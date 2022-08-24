/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Particle.h"


struct GetFunFreq
{
    GetFunFreq(std::atomic <float>& valueToUse) : value(valueToUse) {}
    //this is getting called 60 times a second in timer callback
    float getValue()
    {
        return value.load();
    }
    std::atomic <float>& value;
};

//==============================================================================
/**
*/
class Chladni_VisualizerAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                                public juce::Timer,
                                                public juce::Slider::Listener
{
public:
    Chladni_VisualizerAudioProcessorEditor (Chladni_VisualizerAudioProcessor&);
    ~Chladni_VisualizerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;
    void sliderValueChanged(juce::Slider* slider) override;
    
    GetFunFreq getFunFreq;

private:
    
    const int numParticles {3000};
    const int x {100};
    std::vector <std::unique_ptr <Particle>> particles;
    
    juce::Slider nSlider;
    juce::Slider vSlider;
    
    float nSliderVal { 1 };
    float vSliderVal { 0.05 };
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Chladni_VisualizerAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Chladni_VisualizerAudioProcessorEditor)
};
