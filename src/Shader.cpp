//
// Created by Slope on 6/10/23.
//

#include "../include/Shader.h"

Shader::Shader(const char *vertexSource, const char *fragmentSource) : RendererObject(){
    m_fragmentSource = vertexSource;
    m_vertexSource = fragmentSource;
}

bool Shader::compileShader(uint32_t shaderType, const char *sourceCode) {
    return false;
}
