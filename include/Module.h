#pragma once
#include "ITickable.h"
#include "IResetable.h"

class Module : public ITickable, public IResetable{
public:
    Module() = default;
    virtual ~Module() = default;
    virtual void print() = 0;
};