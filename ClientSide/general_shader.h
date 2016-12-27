#ifndef GENERALSHADER_H
#define GENERALSHADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <GL/glew.h>
#include <string.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class GeneralShader
{
    public:
        GeneralShader(const std::string&, const std::string&, const std::string&);
        GeneralShader(const std::string&, const std::string&);
        std::string loadShader(const std::string&);
        void reloadShader();
        virtual void getAllUniformLocations();
        void bind();
        void loadViewMatrix(const glm::mat4& matrix);
        void loadColor(glm::vec4 color);
        void loadProjectionMatrix(const glm::mat4& matrix);
        void loadModelMatrix(const glm::mat4& matrix);
        void loadMatrix(GLuint location, const glm::mat4& matrix);
        void loadVector4(GLuint location, glm::vec4 vect);
        void loadVector2(GLuint, glm::vec2);
        void loadInt(GLuint, int);
        void loadFloat(GLuint, float);
        GLuint getProgram();
        virtual ~GeneralShader();
    protected:
        std::string vertexShaderPath, fragmentShaderPath, geometryShaderPath;
        GLuint vertexHandle, fragmentHandle, geometryHandle;
        GLuint program;
        GLuint projMatLocation, modelMatLocation, colorVectorLocation, viewMatLocation;
    private:
};

#endif // GENERALSHADER_H