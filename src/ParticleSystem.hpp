//
//  ParticleSystem.hpp
//  particleBlastOut
//
//  Created by Terry Clark on 01/11/2016.
//
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>
#include <Particle.hpp>

class ParticleSys {
    
public:
    ParticleSys(ofVec3f pos);
    void setup();
    void addParticles();
    void run();
    void display();
    void deleteParticles();
    vector <Particle> particles;
    ofVec3f origin;
};

#endif /* ParticleSystem_hpp */
