#include "particle.h"

Particle::Particle(glm::vec3 position,
                   glm::vec3 velocity,
                   glm::vec3 acceleration,
                   float scale,
                   unsigned int liveForInS) : position(position),
                                              velocity(velocity),
                                              acceleration(acceleration),
                                              scale(scale),
                                              liveForInS(liveForInS),
                                              aliveForInMs(0)
{

}

Particle::Particle(glm::vec3 position,
                   glm::vec3 velocity,
                   float scale,
                   unsigned int liveForInS) : Particle(position, velocity, glm::vec3(0, -GRAVITYP, 0), scale, liveForInS)
{

}

void Particle::generateViewModelMatrix(Camera *camera){
    glm::mat4 viewMatrix = camera->getViewMatrix();
    glm::mat4 modelMatrix(1.0);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            modelMatrix[i][j] = viewMatrix[j][i];
        }
    }

    modelMatrix[3][0] = position.x;
    modelMatrix[3][1] = position.y;
    modelMatrix[3][2] = position.z;

    modelMatrix = glm::scale(modelMatrix, glm::vec3(scale));
    viewModelMatrix = viewMatrix * modelMatrix;
}

void Particle::update(long delta, Camera *camera){
    aliveForInMs += delta;

    float deltaF = delta/1000.0f;

    position = position + velocity*deltaF + acceleration*(deltaF*deltaF/2.0f);
    velocity = velocity + acceleration*deltaF;

    generateViewModelMatrix(camera);
}

void Particle::draw(ParticleShader *shader){
    shader->loadViewModelMatrix(viewModelMatrix);
    glDrawArrays(GL_POINTS, 0, 1);
}

bool Particle::isAlive(){
    return aliveForInMs < liveForInS*1000;
}

Particle::~Particle()
{
}