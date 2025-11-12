#pragma once
#include "VgaController.h"
#include "Clock.h"

class Testbench {
public:
    static Testbench& getInstance();
    void run();
    ~Testbench();
private:
    Testbench();
    Testbench(const Testbench&) = delete;
    Testbench& operator=(const Testbench&) = delete;
    Testbench(Testbench&&) = delete;
    Testbench& operator=(Testbench&&) = delete;
};