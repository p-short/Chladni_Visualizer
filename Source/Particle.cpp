/*
  ==============================================================================

    Particle.cpp
    Created: 18 Aug 2022 11:09:16am
    Author:  Phillip Short

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Particle.h"
#include "chladni.h"

//==============================================================================
Particle::Particle()
{
    x = juce::Random::getSystemRandom().nextFloat();
    y = juce::Random::getSystemRandom().nextFloat();
}

Particle::~Particle()
{
}

void Particle::paint (juce::Graphics& g)
{
}

void Particle::resized()
{
}

void Particle::move(float mSliderVal, float nSliderVal, float vSliderValue)
{
    float eq = chladni(x, y, 1, 1, mSliderVal, nSliderVal);
    
    randAmp = vSliderValue * abs(eq);
    
    if (randAmp <= minWalk)
    {
        randAmp = minWalk;
    }
    
    x += randFloatInRange(-randAmp, randAmp);
    y += randFloatInRange(-randAmp, randAmp);
    
    updateOffsets();
}

void Particle::updateOffsets()
{
   if (x <= 0) x = 0;
   if (x >= 1) x = 1;
   if (y <= 0) y = 0;
   if (y >= 1) y = 1;

   // convert to screen space
   xOff = 400 * x; // (this.x + 1) / 2 * width;
   yOff = 400 * y; // (this.y + 1) / 2 * height;
}

float Particle::getX()
{
    return xOff;
}

float Particle::getY()
{
    return yOff;
}

