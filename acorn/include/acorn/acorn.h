#ifndef ACORN_H
#define ACORN_H
#include "Application.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Shader.h"

#define ACORN_IMPLEMENT_APP(IApp) \
    int main(){ \
        IApp* app = new IApp(); \
        int status = app->run(); \
        delete app; \
        return status; \
    } 


#endif