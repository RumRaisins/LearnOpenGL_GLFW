#version 330 core
in vec4 positionColor;

out vec4 color;

void main()
{
	color = positionColor;
}