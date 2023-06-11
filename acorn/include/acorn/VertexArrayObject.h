#ifndef ACORN_VERTEX_ARRAY_OBJECT_H
#define ACORN_VERTEX_ARRAY_OBJECT_H
#include <cstdint>
#include <cstring>
#include <typeinfo>
#include <spdlog/spdlog.h>
#include "opengl.h"

namespace Acorn{
    class VertexArrayObject{
        uint32_t m_ID;
        bool m_created;
        uint32_t m_nextLocation;
    public:
        VertexArrayObject(bool initialize = false);
        ~VertexArrayObject();
        void create();
        void destroy();
        void bind();
        void unbind();
        bool isCreated() const;

        template<typename T>
        void push(uint32_t count);
    };
    
    template<typename T>
    void VertexArrayObject::push(uint32_t count){
        spdlog::debug("Found float in VAO");
        uint32_t location = m_nextLocation++;
        glVertexAttribPointer(location, count, GL_FLOAT, GL_FALSE, count * sizeof(float), nullptr);
        glEnableVertexAttribArray(location);
    }
}


#endif