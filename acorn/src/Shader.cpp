#include <spdlog/spdlog.h>
#include <vector>
#include "Shader.h"
using namespace Acorn;

Shader::Shader(){
    m_program = 0;
    m_created = false;
}

Shader::~Shader(){
    if(m_created)
        destroy();
}

void Shader::addShaderSource(uint32_t shaderType, const char* source){
    if(m_sources.find(shaderType) == m_sources.end()){
        m_sources.emplace(shaderType, source);
    }else{
        m_sources[shaderType] = source;
    }
}

bool Shader::compile(){
    int success;
    char infoLog[512];
    std::vector<uint32_t> shaderIDs;
    
    for(auto source: m_sources){
        uint32_t shader = glCreateShader(source.first);
        glShaderSource(shader, 1, &source.second, nullptr);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            spdlog::error(infoLog);
            for(auto& shaderID: shaderIDs)
                glDeleteShader(shaderID);
            return false;
        }
        shaderIDs.push_back(shader);
    }
    
    m_program = glCreateProgram();
    for(auto shaderID: shaderIDs)
        glAttachShader(m_program, shaderID);
    glLinkProgram(m_program);
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(m_program, 512, nullptr, infoLog);
        spdlog::error(infoLog);
        m_created = false;
        m_program = 0;
    }
    else
    {
        m_created = true;
    }

    for(auto shaderID: shaderIDs)
        glDeleteShader(shaderID);
    
    return m_created;
}

void Shader::use() const{
    glUseProgram(m_program);
}

void Shader::destroy() {
    glDeleteProgram(m_program);
    m_program = 0;
    m_created = false;
}


bool Shader::isCreated() const{
    return m_created;
}