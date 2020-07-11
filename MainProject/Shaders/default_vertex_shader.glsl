#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aNormal; // the color variable has attribute position 1
layout (location = 2) in vec3 aColor; 
layout (location = 3) in vec2 aUV; 

out vec3 ourPos;
out vec3 ourNormal;
out vec3 ourColor; // output a color to the fragment shader
out vec2 ourTexCoord;

out vec3 FragPos;


uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;
void main()
{
    gl_Position =  projection * view * transform * vec4(aPos, 1.0) ;

    FragPos = vec3(transform * vec4(aPos, 1.0));
    ourNormal = mat3(transpose(inverse(transform))) * aNormal;
    ourColor = aColor;
    ourTexCoord = aUV;
}
 