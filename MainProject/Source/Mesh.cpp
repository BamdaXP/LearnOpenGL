#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
Mesh::Mesh()
{
    b_IsSetup = false;
}
void Mesh::Setup()
{

    //Generate buffers and arrays
    glGenVertexArrays(1, &b_VAO);
    glGenBuffers(1, &b_VBO);
    glGenBuffers(1, &b_EBO);
      
    //Bind VAO
    glBindVertexArray(b_VAO);

    //Bind and pass vertices data to VBO
    glBindBuffer(GL_ARRAY_BUFFER, b_VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), 
        &Vertices[0], GL_STATIC_DRAW);

    //Bind and pass indices data to EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int),
        &Indices[0], GL_STATIC_DRAW);

    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    // Vertex normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    glEnableVertexAttribArray(1);
    //Vetex colors
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
    glEnableVertexAttribArray(2);
    // Vertex UVs
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV));
    glEnableVertexAttribArray(3);
    //Unbind VAO
    glBindVertexArray(0);

    b_IsSetup = true;
}


void Mesh::Draw(Shader& shader,GLenum drawType)
{
    if (!b_IsSetup)
        Setup();

    //Set transform to shader
    shader.SetMat4("transform", Transform.GetTransformMatrix());
    shader.SetMat4("view", Camera::MainCamera->GetViewMatrix());
    shader.SetMat4("projection", Camera::MainCamera->GetProjectionMatrix());
    shader.SetVec3("viewPos", Camera::MainCamera->Transform.Position);

    for (unsigned int i = 0; i < Textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0+i);
        shader.SetInt("MainTex", i);
        glBindTexture(GL_TEXTURE0 + i, Textures[i].GetTextureHandle());
    }
    
    //Use shader
    shader.UseShader();

    //Draw mesh
    glBindVertexArray(b_VAO);

    GLenum topo;
    switch (Topology)
    {
    case Mesh::Triangles:
        topo = GL_TRIANGLES;
        break;
    case Mesh::Quads:
        topo = GL_QUADS;
        break;
    default:
        topo = GL_TRIANGLES;
        break;
    }
    //Depth testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    //Back face culling
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    //glFrontFace(GL_CCW);

    glDrawElements(topo, Indices.size(), GL_UNSIGNED_INT, 0);
    
    //Reset
    glBindVertexArray(0);
    glActiveTexture(GL_TEXTURE0);

}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &b_VAO);
    glDeleteBuffers(1, &b_VBO);
    glDeleteBuffers(1, &b_EBO);
}
