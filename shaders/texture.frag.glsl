#version 460 core

layout (location = 0) out vec4 o_Color;

layout(location = 0) in vec2 v_TexCoord;

layout(location = 1) uniform sampler2D u_Texture;
layout(location = 2) uniform bool u_IsHovered;

void main()
{
	o_Color = texture(u_Texture, v_TexCoord);
	if (u_IsHovered)
		o_Color.rgb += 0.2;
}
