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
    
    nSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    nSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    nSlider.setRange(1, 50, 0.01);
    nSlider.setValue(1);
    nSlider.addListener(this);
    addAndMakeVisible(nSlider);
    
    vSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    vSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    vSlider.setRange(0.01, 0.1, 0.01);
    vSlider.setValue(0.05);
    vSlider.addListener(this);
    addAndMakeVisible(vSlider);
    
    
    Timer::startTimerHz(60);
    setSize (400, 450);
}

Chladni_VisualizerAudioProcessorEditor::~Chladni_VisualizerAudioProcessorEditor()
{
    Timer::stopTimer();
}

//==============================================================================
void Chladni_VisualizerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black.withLightness(0.15f));
    g.setColour(juce::Colours::black);
    g.fillRect(0, 0, 400, 400);
    g.setColour(juce::Colour::fromFloatRGBA (0.996f, 0.509f, 0.549f, 1.0f));
    
    for (auto i = 0; i < particles.size(); i++)
    {
        g.fillEllipse(particles[i]->getX(), particles[i]->getY(), 2, 2);
    }
}

void Chladni_VisualizerAudioProcessorEditor::resized()
{
    nSlider.setBounds(5, 412.5, 190, 12);
    vSlider.setBounds(205, 412.5, 190, 12);
}

void Chladni_VisualizerAudioProcessorEditor::timerCallback()
{
    repaint();
    
    for (auto i = 0; i < particles.size(); i++)
    {
        particles[i]->move(5.f, nSliderVal, vSliderVal);
        particles[i]->updateOffsets();
    }
}

void Chladni_VisualizerAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &nSlider)
    {
        nSliderVal = nSlider.getValue();
    }
    
    if (slider == &vSlider)
    {
        vSliderVal = vSlider.getValue();
    }
}
