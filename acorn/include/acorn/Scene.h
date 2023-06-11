#ifndef ACORN_SCENE_H
#define ACORN_SCENE_H
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Shader.h"

namespace Acorn{

    class Scene{
    public:
        virtual ~Scene() = 0;
        VertexArrayObject* VAO;
        VertexBufferObject* VBO;
        ElementBufferObject* EBO;
        Shader* shader;
    protected:
        virtual void setup() = 0;
        virtual void teardown() = 0;
    };
}

#endif