/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Particle.h"

//==============================================================================
/**
*/
class Chladni_VisualizerAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                                public juce::Timer
{
public:
    Chladni_VisualizerAudioProcessorEditor (Chladni_VisualizerAudioProcessor&);
    ~Chladni_VisualizerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;

private:
    
    const int numParticles {100};
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Chladni_VisualizerAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Chladni_VisualizerAudioProcessorEditor)
};
