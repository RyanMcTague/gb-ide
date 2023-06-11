#ifndef ACORN_SHADER_H
#define ACORN_SHADER_H
#include <map>
#include "opengl.h"

namespace Acorn{
    class Shader{
    private:
        uint32_t m_program;
        std::map<uint32_t, const char*> m_sources;
        bool m_created;
    public:
        Shader();
        ~Shader();
        void addShaderSource(uint32_t shaderType, const char* source);
        bool compile();
        void use() const;
        void destroy(); 
        bool isCreated() const;
    };
}

#endif
