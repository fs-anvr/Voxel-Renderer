#version 460 core

layout(location = 0) in vec3 vertexPositionModelspace;
layout (location = 1) in vec3 vertexColor;

uniform mat4 MVP;

out vec3 fragmentColor;

void main() {
  gl_Position = MVP * vec4(vertexPositionModelspace, 1.0);
  fragmentColor = vertexColor;
}