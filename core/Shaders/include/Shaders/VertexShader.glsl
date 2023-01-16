#version 460 core

layout(location = 0) in vec3 vertexPositionModelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec3 vertexColor;
layout(location = 3) in vec3 offset;

uniform mat4 MV;
uniform mat4 modelMatrix;

out vec3 fragmentColor;
out vec3 fragmentPos;
out vec3 normal;

void main() {
  vec4 pos = vec4(vertexPositionModelspace + offset, 1.0);

  gl_Position = (MV * modelMatrix) * pos;

  fragmentColor = vertexColor;
  fragmentPos = vec3(modelMatrix * pos);
  normal = vertexNormal;
}