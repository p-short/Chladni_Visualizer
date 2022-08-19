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
    for (auto i = 0; i < 1000; i++)
    {
        particles.push_back(std::make_unique<Particle>());
    }
    
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

    for (auto i = 0; i < particles.size(); i++)
    {
        g.setColour(juce::Colour::fromFloatRGBA (0.996f, 0.509f, 0.549f, 1.0f));
        g.fillEllipse(particles[i]->getX(), particles[i]->getY(), 2, 2);
        //std::cout << particles[i]->getX() << "\n";
    }
    
}

void Chladni_VisualizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void Chladni_VisualizerAudioProcessorEditor::timerCallback()
{
    repaint();
    
    for (auto i = 0; i < particles.size(); i++)
    {
        particles[i]->move(5.f, 2.f, 0.05f);
        particles[i]->updateOffsets();
        //std::cout << particles[i]->getX() << " " << particles[i]->getY() << "\n";
    }
    //auto randomIntA = juce::Random::getSystemRandom().nextFloat();
    //auto randomIntB = juce::Random::getSystemRandom().nextInt (101) * 0.01;
    
    //auto randomInt = juce::Random::getSystemRandom().nextInt (juce::Range<int> (-6.f, 7.f));
    //std::cout << randomInt << "\n";
}
