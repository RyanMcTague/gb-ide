#ifndef ACORN_ELEMENT_BUFFER_OBJECT_H
#define ACORN_ELEMENT_BUFFER_OBJECT_H
#include <cstdint>
#include "opengl.h"

namespace Acorn{
    class ElementBufferObject{
        uint32_t m_ID;
        bool m_created;
    public:
        ElementBufferObject(bool initialize = false);
        ~ElementBufferObject();
        void create();
        void destroy();
        void bind();
        void unbind();
        bool isCreated() const;
        void addIndices(uint32_t* indices, uint32_t count);
    };
}

#endif