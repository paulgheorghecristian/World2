#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>

struct Vertex{
    glm::vec3 positionCoords;
    glm::vec3 normalCoords;
    glm::vec2 textureCoords;

    Vertex() : positionCoords(0.0f), normalCoords(0.0f), textureCoords(0.0f){}

    Vertex(glm::vec3 positionCoords, glm::vec3 normalCoords, glm::vec2 tc){
        this->positionCoords = positionCoords;
        this->normalCoords = normalCoords;
        this->textureCoords = tc;
    }
    Vertex(glm::vec3 positionCoords) : Vertex(positionCoords, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)){}
    Vertex(glm::vec3 positionCoords, glm::vec3 normalCoords) : Vertex(positionCoords, normalCoords, glm::vec2(0.0f, 0.0f)){}
    Vertex(glm::vec3 positionCoords, glm::vec2 textureCoords) : Vertex(positionCoords, glm::vec3(0.0f, 1.0f, 0.0f), textureCoords){}
};

class Mesh
{
    public:
        Mesh(std::vector<Vertex>&, std::vector<unsigned int>&, const glm::vec3& maxCoordinates, const glm::vec3& minCoordinates);
        Mesh(std::vector<Vertex>&, std::vector<unsigned int>&);
        GLuint getVao();
        void draw();
        GLsizei getNumberOfTriangles();
        static Mesh* getRectangle();
        static Mesh* loadObject(std::string);
        static Mesh* getSurface(int, int);
        static Mesh* getDome(int, int);
        static Mesh* getCircle(float, float, float, int);
        std::vector<Vertex>& getVertices(){return vertices;}
        std::vector<unsigned int>& getIndices(){return indices;}
        glm::vec3& getMinCoordinates(){
            return minCoordinates;
        }
        glm::vec3& getMaxCoordinates(){
            return maxCoordinates;
        }
        virtual ~Mesh();
    protected:
    private:
            enum VBOs{
                VERTEX, INDEX, NUM_VBOS
            };
            GLuint vaoHandle;
            GLuint vboHandles[NUM_VBOS];
            GLsizei numberOfTriangles;
            std::vector<Vertex> vertices;
            std::vector<unsigned int> indices;
            glm::vec3 minCoordinates, maxCoordinates;
            static float _stringToFloat(const std::string &source);
            static unsigned int _stringToUint(const std::string &source);
            static int _stringToInt(const std::string &source);
            static void _stringTokenize(const std::string &source, std::vector<std::string> &tokens);
            static void _faceTokenize(const std::string &source, std::vector<std::string> &tokens);
};

#endif // MESH_H
