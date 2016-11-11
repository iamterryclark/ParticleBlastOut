
//
//  ParticleSystem.cpp
//  particleBlastOut
//
//  Created by Terry Clark on 01/11/2016.
//
//

#include "ParticleSystem.hpp"


ParticleSys::ParticleSys(ofVec3f pos){
    origin = pos;
}
    
void ParticleSys::addParticles() {
    //I created a variety of sizes, velocity and accelerations in order to produce a realistic burner.
    
    
    //7725 Particles rednered
    
    //Main Burner2
    particles.push_back(Particle(origin, ofGetWidth()/13, ofVec3f( 1.3 , 1.3, 1.3 ), ofVec3f( 0 , 0.001, 0 ), 150));
    particles.push_back(Particle(origin, ofGetWidth()/24, ofVec3f( 1.7 , 1.7, 1.7 ), ofVec3f( 0 , 0.001, 0 ), 230));
    particles.push_back(Particle(origin, ofGetWidth()/35, ofVec3f( 1.9 , 1.9, 1.9 ), ofVec3f( 0 , 0.001, 0 ), 240));
        
    //Mid Burner
    particles.push_back(Particle(origin, ofGetWidth()/50, ofVec3f( 2   , 2   , 2   ), ofVec3f( 0 , 0.005, 0 ), 255));
    particles.push_back(Particle(origin, ofGetWidth()/50, ofVec3f( 1.6 , 1.6 , 1.6 ), ofVec3f( 0 , 0.005, 0 ), 255));
    
    //Spray
    for (int i =1; i < 15; i ++) {
        particles.push_back(Particle(origin, ofGetWidth()/(16 * i), ofVec3f( 2.6-(i/60) , 2.6-(i/60), 2.6-(i/60)), ofVec3f(0 , 0.004, 0), 100 + (i*20)));
    }
}

void ParticleSys::setup(){
    for (auto &p : particles) p.setup();
}

void ParticleSys::run() {
    //I then look through all of the arraylist which increases in size and display this whilst always
    //check if the particle should be removed based on the opacity.
    deleteParticles();
    display();
    cout << particles.size() << endl;
    cout << ofGetFrameRate() << endl;
    
}

void ParticleSys::display(){
    for (auto it = particles.end(); it != particles.begin(); it--){
        Particle &p = *it;
        it->display();
    }

}

void ParticleSys::deleteParticles(){
    auto it = remove_if(particles.begin(), particles.end(), [this](Particle particles){ return particles.kill(); });
    particles.erase(it, particles.end());
}


