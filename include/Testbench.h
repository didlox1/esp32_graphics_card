#pragma once
#include "VgaController.h"
#include "Vram.h"
#include "Clock.h"
#include <fstream>
#include <string>

class Testbench {
public:
    ~Testbench();
    static Testbench& getInstance();
    void run();
    // Helpers
    void setCaptureFilename(const std::string& filename);
    // Threads needed for capturing and waiting
    void captureFrame();
    // TODO: Implement methods shown below
    void waitFrames(int frameCount);
    // CPU interaction methods
    void writeChar(int row, int col, uint8_t ascii_code);
    void setFontColor(uint8_t color);
    void setBackgroundColor(uint8_t color);
    void clearScreen();
    void clearLine(int row);

private:
    std::fstream m_file;
    Testbench();
    Testbench(const Testbench&) = delete;
    Testbench& operator=(const Testbench&) = delete;
    Testbench(Testbench&&) = delete;
    Testbench& operator=(Testbench&&) = delete;
};