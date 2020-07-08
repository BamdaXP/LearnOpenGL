#version 330 core
out vec4 FragColor;

in vec3 ourNormal;
in vec3 ourColor;
in vec2 ourTexCoord;

uniform sampler2D MainTex;

void main()
{
    FragColor = texture(MainTex,ourTexCoord);
} 