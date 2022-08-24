/*
  ==============================================================================

    MyFFT.h
    Created: 20 Aug 2022 10:43:25am
    Author:  Phillip Short
 
 this FFT code was put together while watching Beats basteln :3s video walkthrough, which can be found here https://www.youtube.com/watch?v=7ldQWYjWinU

  ==============================================================================
*/

#pragma once

class MyFFT
{
public:
    MyFFT() :
    forwardFFT (fftOrder),
    fifoIndex(0),
    sizeHalf(fftSize / 2),
    m_sampleRate(1.f),
    sizeMaxInv(1.f / float(fftSize - 1)),
    sampRateSizeMaxInv(1.f)
    {
    }

    ~MyFFT()
    {
    }

    //==============================================================================
   
    void getSampleRate(double sr)
    {
        m_sampleRate = float(sr);
        sampRateSizeMaxInv = m_sampleRate * sizeMaxInv;
    }

    //==============================================================================

    void pushNextSampleIntoFifo (float sample) noexcept
    {
        if (fifoIndex == fftSize)
        {
            std::fill (fftData.begin(), fftData.end(), 0.0f);
            std::copy (fifo.begin(), fifo.end(), fftData.begin());
            forwardFFT.performFrequencyOnlyForwardTransform (fftData.data());
            fifoIndex = 0;
        }
        fifo[(size_t) fifoIndex++] = sample; // [9]
    }

    float processFundamentalFreq()
    {
        float index = 0.f;
        float max = 0.f;
        float abSamp;
        
        for (auto i = 0; i < sizeHalf; ++i)
        {
            abSamp = std::abs(fftData[i]);
            
            if (max < abSamp)
            {
                max = abSamp;
                index = i;
            }
        }
        return sampRateSizeMaxInv * index;
    }
    
    static constexpr auto fftOrder = 10;                // [1]
    static constexpr auto fftSize  = 1 << fftOrder;     // [2]
    
private:
    
    juce::dsp::FFT forwardFFT;                          // [3]
    std::array<float, fftSize> fifo;                    // [4]
    std::array<float, fftSize * 2> fftData;             // [5]
    int fifoIndex, sizeHalf;
    float m_sampleRate, sizeMaxInv, sampRateSizeMaxInv;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyFFT)
};
