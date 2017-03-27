#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 colorPosition;
uniform  float offset ;

void main()
{
    gl_Position = vec4(position.x+offset,-position.y+offset,position.z+offset, 1.0f);
    colorPosition=vec4(position,1.0f);
}