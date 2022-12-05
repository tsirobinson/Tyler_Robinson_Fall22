#version 330 core

out vec4 FragColor;

in vec2 TexCoord;
in vec2 Debug;

uniform sampler2D texture1;

void main()
{
	//FragColor = texture(texture1, TexCoord);
	//FragColor = vec4(0.2+Debug.x/1200, 0.0, 0.0, 1.0);
	FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}