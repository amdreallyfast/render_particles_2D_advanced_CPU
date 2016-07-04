#include "ParticleEmitterBar.h"

#include "RandomToast.h"

// TODO: header
ParticleEmitterBar::ParticleEmitterBar(const glm::vec2 &p1, const glm::vec2 &p2, const float minVel,
    const float maxVel)
{
    _barStart = p1;
    _barStartToEnd = p2 - p1;

    // rotate a 2D vector (x,y) by +90 degrees => (-y,x)
    glm::vec2 plus90Degrees((-1.0f) * _barStartToEnd.y, _barStartToEnd.x);

    _velocityCalculator.SetMinMaxVelocity(minVel, maxVel);
    _velocityCalculator.SetDir(plus90Degrees);
}

// TODO: header
void ParticleEmitterBar::ResetParticle(Particle *resetThis) const
{
    //??when to turn it on??
    //resetThis->_isActive = true;

    // give it some flavor by making the particles be reset to within a range near the emitter 
    // bar's position instead of exactly on the bar, making it look like a particle hotspot
    // TODO: the random thing
    resetThis->_position = _barStart + (RandomOnRange0to1() * _barStartToEnd);


    resetThis->_velocity = _velocityCalculator.GetNew();
}


