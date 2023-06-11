#include "VertexBufferObject.h"
using namespace Acorn;

VertexBufferObject::VertexBufferObject(bool initialize){
    m_created = false;
    m_ID = 0;
    if(initialize)
        create();
}

VertexBufferObject::~VertexBufferObject(){
    if(m_created)
        destroy();
}

void VertexBufferObject::bind(){
   glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBufferObject::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::create(){
    glGenBuffers(1, &m_ID);
    m_created = true;
}

void VertexBufferObject::destroy(){
    glDeleteBuffers(1, &m_ID);
    m_created = false;
}

bool VertexBufferObject::isCreated() const{
    return m_created;
}