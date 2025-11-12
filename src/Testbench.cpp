#include "Testbench.h"

Testbench::Testbench() = default;
Testbench::~Testbench(){
    if (m_file.is_open()) {
        m_file.close();
    }
};

Testbench& Testbench::getInstance() {
    static Testbench instance;
    return instance;
}

// Testbench body
void Testbench::run() {
    VgaController vgaController;
    Vram vram;
    Clock clock;
    clock.addVgaController(vgaController);
    clock.addVram(vram);
    clock.tick(1000);
}

void Testbench::setCaptureFilename(const std::string& filename) {
    m_file.open(filename, std::ios::out |  std::ios::binary);
}

void Testbench::captureFrame() {
    //Need to wait for the vSync to be low to start capturing
    //End of capture is when vSync goes low another time
    //Probably will need to use threads in here to not block the main simulation
    if(m_file.is_open()) {
        m_file << "Frame captured\n"; // TODO: add capturing logic
    }
}