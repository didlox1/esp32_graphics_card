#pragma once

#include "ITickable.h"
#include "IResetable.h"
#include "Module.h"
#include <cstdint>
#include <bitset>
#include <utility>
#include <iostream>
#include <format>
// Source: http://tinyvga.com/vga-timing/640x480@60Hz
// Configuration for the 640x480 resolution 60Hz refresh rate and 25.175MHz clock
// Period of 39.72 nanoseconds (ns)
// Horizontal timings [pixels]
#define H_VISIBLE_AREA 640
#define H_FRONT_PORCH 16
#define H_SYNC_PULSE 96
#define H_BACK_PORCH 48
#define H_WHOLE_LINE (H_SYNC_PULSE + H_BACK_PORCH + H_VISIBLE_AREA + H_FRONT_PORCH)
// Vertical timings [lines]
#define V_VISIBLE_AREA 480
#define V_FRONT_PORCH 10
#define V_SYNC_PULSE 2
#define V_BACK_PORCH 33
#define V_WHOLE_FRAME (V_SYNC_PULSE + V_BACK_PORCH + V_VISIBLE_AREA + V_FRONT_PORCH)

class VgaController : public Module {
private:
    //Counters
    int x;
    int y;
    int pixelX;
    int pixelY;
    //Helper booleans
    bool videoEnable;
    bool doneLine;
    bool doneFrame;
    //IO signals
    //Inputs
    uint8_t dataIn; 
    //Outputs
    std::bitset<3> redOut;
    std::bitset<3> greenOut;
    std::bitset<2> blueOut;
    bool hSync;
    bool vSync;
    std::pair<int, int> address;

public:
    VgaController();
    ~VgaController() = default;
    void evaluate() override;
    void commit() override;
    void reset() override;
    void print() override;
    friend std::ostream& operator<<(std::ostream& os, const VgaController& vga);
};