#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 TexData;

out vec2 TexCoord;
out vec2 Debug;

uniform vec2 screenSize;

void main()
{
	//gl_Position = vec4(aPos.x*2/screenSize.x - 1, aPos.y*2/screenSize.y - 1, aPos.z, 1.0);
	gl_Position = vec4(aPos.x/600.0, aPos.y/400.0, 1.0, 1.0);
	TexCoord = TexData;
	Debug = screenSize;
}