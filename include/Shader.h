//
// Created by Slope on 6/10/23.
//

#ifndef GBIDE_SHADER_H
#define GBIDE_SHADER_H
#include "gl_context.h"
#include "map"

class Shader{
private:
    std::map<uint32_t, const char *> sources;
    bool m_isValid;
public:
    Shader(const char* vertexSource, const char* fragmentSource);

private:
    bool compileShader(uint32_t shaderType, const char *sourceCode);
};


#endif //GBIDE_SHADER_H
