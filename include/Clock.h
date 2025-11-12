#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "ITickable.h"
#include "Module.h"

class Clock {
    std::vector<std::shared_ptr<Module>> tickables;
public:
    Clock() = default;
    ~Clock() = default;
    void tick(int cycles = 1) {
        for (int i = 0; i < cycles; ++i) {
            // First evaluate all tickables
            for (auto& tickable : tickables) {
                tickable->evaluate();
            }
            // Then commit all tickables
            for (auto& tickable : tickables) {
                tickable->commit();
            }
            
            // Only debug option
            for (auto& tickable : tickables) {
                tickable->print();
            }
            
        }
    }
    void addVgaController(VgaController& tickable) {
        tickables.emplace_back(std::make_shared<VgaController>(tickable));
    }
};