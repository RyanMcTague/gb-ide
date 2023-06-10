//
// Created by Slope on 6/10/23.
//

#include "../include/ShaderSource.h"


const char* ShaderSource::vertex = R""""(
    #version 330 core
    layout (location = 0) in vec3 aPos;

    void main()
    {
        gl_Position = vec4(aPos, 1.0);
    }
)"""";

const char* ShaderSource::fragment = R""""(
    #version 330 core
    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    }
)"""";
