/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Particle.h"

//==============================================================================
Chladni_VisualizerAudioProcessorEditor::Chladni_VisualizerAudioProcessorEditor (Chladni_VisualizerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    Timer::startTimerHz(60);
    setSize (400, 400);
}

Chladni_VisualizerAudioProcessorEditor::~Chladni_VisualizerAudioProcessorEditor()
{
    Timer::stopTimer();
}

//==============================================================================
void Chladni_VisualizerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Chladni_VisualizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void Chladni_VisualizerAudioProcessorEditor::timerCallback()
{
    //auto randomIntA = juce::Random::getSystemRandom().nextFloat();
//    auto randomIntB = juce::Random::getSystemRandom().nextInt (101) * 0.01;
    
    auto randomInt = juce::Random::getSystemRandom().nextInt (juce::Range<int> (-6.f, 7.f));
    std::cout << randomInt << "\n";
}
