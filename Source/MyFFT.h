/*
  ==============================================================================

    MyFFT.h
    Created: 20 Aug 2022 10:43:25am
    Author:  Phillip Short

  ==============================================================================
*/

#pragma once

class MyFFT
    : forwardFFT(fftOrder)
{
public:
    
    static constexpr auto fftOrder = 10;                // [1]
    static constexpr auto fftSize  = 1 << fftOrder;     // [2]
    
private:
    
    juce::dsp::FFT forwardFFT;                          // [3]
 
    std::array<float, fftSize> fifo;                    // [4]
    std::array<float, fftSize * 2> fftData;             // [5]
    int fifoIndex = 0;                                  // [6]
    bool nextFFTBlockReady = false;                     // [7]
}
