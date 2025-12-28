#version 460 core

layout(location = 0) in vec2 a_Position;
layout(location = 1) in vec2 a_TexCoord;

out vec2 v_TexCoord;

layout(location = 0) uniform mat4 u_Transform;

void main()
{
	v_TexCoord = a_TexCoord;
	gl_Position = u_Transform * vec4(a_Position, 0.0, 1.0);
}