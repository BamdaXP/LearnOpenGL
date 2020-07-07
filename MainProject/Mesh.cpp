#include "Mesh.h"
#include "Shader.h"


Mesh::Mesh()
{
    b_IsSetup = false;
}
void Mesh::Setup()
{
    //Generate buffers and arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    //Bind VAO
    glBindVertexArray(VAO);

    //Bind and pass vertices data to VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), 
        &vertices[0], GL_STATIC_DRAW);

    //Bind and pass indices data to EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        &indices[0], GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // Vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    //Vetex colors
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
    // Vertex UVs
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV));

    //Unbind VAO
    glBindVertexArray(0);

    b_IsSetup = true;
}


void Mesh::Draw(Shader& shader,GLenum drawType)
{
    if (!b_IsSetup)
        Setup();
    
    for (unsigned int i = 0; i < textures.size(); i++)
    {
        textures[i].UseTexture(GL_TEXTURE0+i);
    }
    glActiveTexture(GL_TEXTURE0);
    
    //Use shader
    shader.UseShader();
    shader.SetInt("MainTex", 0);

    //Draw mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    if (drawType == GL_STATIC_DRAW)
        b_IsSetup = false;
}
