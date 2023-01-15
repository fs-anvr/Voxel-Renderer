#version 460 core

uniform vec3 lightPos;

in vec3 fragmentColor;
in vec3 fragmentPos;
in vec3 normal;

out vec3 color;

//TODO: unhardcode light strength
//TODO: unhardcode light color

void main() {
  /* Ambient light */
  float ambientStrength = 0.1;
  vec3 lightColor = vec3(1.0, 1.0, 1.0);
  vec3 ambient = ambientStrength * lightColor;

  /* Diffuse light */
  vec3 normNormal = normalize(normal);
  vec3 lightDir = normalize(lightPos - fragmentPos);
  float diff = max(dot(normNormal, lightDir), 0.0);
  vec3 diffuse = diff * lightColor;
  vec3 result = (ambient + diffuse) * fragmentColor;

  color = result;
}