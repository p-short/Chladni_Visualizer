/*
  ==============================================================================

    Particle.h
    Created: 18 Aug 2022 11:09:16am
    Author:  Phillip Short

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Particle  : public juce::Component
{
public:
    Particle();
    ~Particle() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void move(float mSliderVal, float nSliderVal, float vSliderVal);
    void updateOffsets();

private:
    
    float x, y, xOff, yOff;
    float randAmp { 0 };
    float minWalk { 0.002 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Particle)
};
