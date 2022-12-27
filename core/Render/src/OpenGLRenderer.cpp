// clang-format off

#include <Render/OpenGLRenderer.hpp>
#include <Render/Renderables.hpp>
#include <ServiceLocator/ServiceLocator.hpp>

#include <glad/gl.h>
#include <glm/glm.hpp>

#include <cstdint>

// clang-format on

namespace VoxelEngine {

OpenGLRenderer::OpenGLRenderer() { this->Init(); }

OpenGLRenderer::~OpenGLRenderer() {}

void OpenGLRenderer::Init() {
  shaderProgram = ShaderProgram(
      "C:\\Users\\fsanv\\my_projects\\voxel-"
      "engine\\core\\Shaders\\include\\Shaders\\VertexShader.glsl",
      "C:\\Users\\fsanv\\my_projects\\voxel-"
      "engine\\core\\Shaders\\include\\Shaders\\FragmentShader.glsl");

  glUseProgram(shaderProgram.id);

  glGenBuffers(1, &_voxelVertexBuffer);
  glGenBuffers(1, &_voxelIndexBuffer);
  glGenBuffers(1, &_colorBuffer);
  glGenBuffers(1, &_VBO);

  //glGenBuffers(1, &_matrixBuffer);

  glBindBuffer(GL_ARRAY_BUFFER, _voxelVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Renderer::_voxelIndexSize,
               &_voxelVertex, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _voxelIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               sizeof(int) * Renderer::_voxelVertexSize, &_voxelIndex,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
}

void OpenGLRenderer::Rerender() {
  /* clear */
  glClearColor(0.1, 0.1, 0.1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  Camera& camera = ServiceLocator::Camera();

  const glm::mat4 MV = camera.Projection() * camera.View();

  GLuint MatrixID = glGetUniformLocation(shaderProgram.id, "MV");
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MV[0][0]);

  const std::vector<Voxel>& voxels = ServiceLocator::Scene().GetVoxels();

  std::vector<glm::vec3> v_pos(voxels.size());
  std::vector<glm::vec3> v_color(voxels.size());
  std::vector<glm::mat4> v_matrix(voxels.size());

  for (auto& voxel : voxels) {
    std::size_t idx = &voxel - &voxels[0];
    v_pos[idx] = voxel.position;
    v_color[idx] = voxel.color;
    v_matrix[idx] = voxel.transform;
  }

//TODO: группировка вокселей по их moxel matrix?

  const glm::mat4 modelMatrix = voxels.size() == 0 ? glm::mat4(1.0) : voxels[0].transform;

  GLuint modelMatrixId = glGetUniformLocation(shaderProgram.id, "modelMatrix");
  glUniformMatrix4fv(modelMatrixId, 1, GL_FALSE, &modelMatrix[0][0]);

  glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(v_color[0]) * v_color.size(), &v_color[0],
               GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(v_pos[0]) * v_pos.size(), &v_pos[0],
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
  glVertexAttribDivisor(1, 1);

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
  glVertexAttribDivisor(2, 1);

  glDrawElementsInstanced(GL_TRIANGLES, _voxelVertexSize, GL_UNSIGNED_INT,
                 static_cast<void*>(0), voxels.size());
  //}
}

}  // namespace VoxelEngine