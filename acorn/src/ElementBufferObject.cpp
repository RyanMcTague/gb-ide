#include "ElementBufferObject.h"
using namespace Acorn;

ElementBufferObject::ElementBufferObject(bool initialize){
    m_created = false;
    m_ID = 0;
    if(initialize)
        create();
}

ElementBufferObject::~ElementBufferObject(){
    if(m_created)
        destroy();
}

void ElementBufferObject::bind(){
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void ElementBufferObject::unbind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBufferObject::create(){
    glGenBuffers(1, &m_ID);
    m_created = true;
}

void ElementBufferObject::destroy(){
    glDeleteBuffers(1, &m_ID);
    m_created = false;
}

bool ElementBufferObject::isCreated() const{
    return m_created;
}

void ElementBufferObject::addIndices(uint32_t* indices, uint32_t count){
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
}