/*
  ==============================================================================

    Particle.cpp
    Created: 18 Aug 2022 11:09:16am
    Author:  Phillip Short
 
 This code has been adapted from addiebarron JavaScript implementation of Chladni plates, which can be found at this link https://github.com/addiebarron/chladni

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Particle.h"
#include "chladni.h"

//==============================================================================
Particle::Particle()
{
    //init x & y coordiantes with a random float value between 0 - 1
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
    //chladni function found in chladni.h
    float eq = chladni(x, y, 1, 1, mSliderVal, nSliderVal);
    //multiply the value from the energy slider by the absolute value returned by chladni function
    randAmp = vSliderValue * abs(eq);
    //if energy slider is at its lowest set it to the value of minWalk so particles dont vibrate
    if (randAmp <= minWalk)
    {
        randAmp = minWalk;
    }
    //randFloatInRange function found in chladni.h
    //add random offset to x & y coordiantes, this is what causes the particles to vibrate
    x += randFloatInRange(-randAmp, randAmp);
    y += randFloatInRange(-randAmp, randAmp);
    
    updateOffsets();
}

void Particle::updateOffsets()
{
   //handle edges
   if (x <= 0) x = 0;
   if (x >= 1) x = 1;
   if (y <= 0) y = 0;
   if (y >= 1) y = 1;

   //convert normalised x & y coodinates to fit the size of the plugin
   xOff = 400 * x;
   yOff = 400 * y;
}

//getters to return the value of x & y
float Particle::getX()
{
    return xOff;
}

float Particle::getY()
{
    return yOff;
}

