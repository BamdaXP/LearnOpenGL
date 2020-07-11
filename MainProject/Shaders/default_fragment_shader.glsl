#version 420 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 ourNormal;
in vec3 ourColor;
in vec2 ourTexCoord;

uniform sampler2D MainTex;

uniform vec3 viewPos;
uniform vec3 lightPos;
uniform vec3 lightIntensity;
uniform vec3 lightColor;

void main()
{
    vec3 norm = normalize(ourNormal);
    vec3 lightDir = normalize(lightPos - FragPos);  
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    //Ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
    //Diffuse
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    //Specular
    float specularStrength = 0.5;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor; 

    FragColor = texture(MainTex, ourTexCoord) * vec4((ambient+diffuse+specular)*ourColor,1.0);
} 