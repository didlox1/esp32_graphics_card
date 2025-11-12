#pragma once
#include <vector>
#include <memory>
#include "ITickable.h"
#include "Module.h"

class Clock {
    std::vector<std::shared_ptr<Module>> modules;
public:
    Clock() = default;
    ~Clock() = default;
    void tick(int cycles = 1) {
        for (int i = 0; i < cycles; ++i) {
            // First evaluate all modules
            for (auto& module : modules) {
                module->evaluate();
            }
            // Then commit all modules
            for (auto& module : modules) {
                module->commit();
            }
            // Only debug option - for now
            for (auto& module : modules) {
                module->print();
            }
        }
    }
    void addVgaController(VgaController& module) {
        modules.emplace_back(std::make_shared<VgaController>(module));
    }
    void addVram(Vram& module) {
        modules.emplace_back(std::make_shared<Vram>(module));
    }
};