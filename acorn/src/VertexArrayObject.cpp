#include "VertexArrayObject.h"
#include "opengl.h"

using namespace Acorn;

VertexArrayObject::VertexArrayObject(bool initialize){
    m_created = false;
    m_ID = 0;
    m_nextLocation = 0;
    if(initialize)
        create();
}

VertexArrayObject::~VertexArrayObject(){
    if(m_created)
        destroy();
}

void VertexArrayObject::bind(){
    glBindVertexArray(m_ID);
}

void VertexArrayObject::unbind(){
    glBindVertexArray(0);
}

void VertexArrayObject::create(){
    glGenVertexArrays(1, &m_ID);
    m_created = true;
}

void VertexArrayObject::destroy(){
    glDeleteVertexArrays(1, &m_ID);
    m_created = false;
    m_nextLocation = 0;
}

bool VertexArrayObject::isCreated() const{
    return m_created;
}