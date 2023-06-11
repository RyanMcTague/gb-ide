#ifndef ACORN_SHADER_H
#define ACORN_SHADER_H
#include <map>
#include "opengl.h"

namespace Acorn{
    class Shader{
    private:
        std::map<uint32_t, const char *> sources;
        bool m_isValid;
    public:
        Shader(const char* vertexSource, const char* fragmentSource);

    private:
        bool compileShader(uint32_t shaderType, const char *sourceCode);
    };

}

#endif
