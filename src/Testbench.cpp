#include "Testbench.h"

Testbench::Testbench() = default;
Testbench::~Testbench() = default;

Testbench& Testbench::getInstance() {
    static Testbench instance;
    return instance;
}

// Testbench body
void Testbench::run() {
    VgaController vgaController;
    Clock clock;
    clock.addVgaController(vgaController);
    clock.tick(1000);
}