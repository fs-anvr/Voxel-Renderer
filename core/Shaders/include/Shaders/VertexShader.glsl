#version 460 core

layout(location = 0) in vec3 vertexPositionModelspace;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec3 offset;

uniform mat4 MV;
uniform mat4 modelMatrix;
//mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)
out vec3 fragmentColor;

void main() {
  gl_Position = (MV * modelMatrix) * vec4(vertexPositionModelspace + offset, 1.0);
  fragmentColor = vertexColor;
}