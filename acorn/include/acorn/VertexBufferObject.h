#ifndef ACORN_VERTEX_BUFFER_OBJECT_H
#define ACORN_VERTEX_BUFFER_OBJECT_H
#include <cstdint>
#include "opengl.h"

namespace Acorn{
    class VertexBufferObject{
        uint32_t m_ID;
        bool m_created;
    public:
        VertexBufferObject(bool initialize = false);
        ~VertexBufferObject();
        void create();
        void destroy();
        void bind();
        void unbind();
        bool isCreated() const;

        template<typename T>
        void addVertices(T* vertices, uint32_t count);
    };

    template<typename T>
    void VertexBufferObject::addVertices(T* vertices, uint32_t count){
        bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(T) * count, vertices, GL_STATIC_DRAW);
    }
}

#endif