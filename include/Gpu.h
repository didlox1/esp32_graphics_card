#pragma once
#include "ITickable.h"
#include "IResetable.h"
#include "Module.h"

class Gpu : public Module {
public:
    Gpu() = default;
    ~Gpu() = default;
    void evaluate() override;
    void commit() override;
    void reset() override;
    void print() override;
};