#pragma once

class IResetable{
public:
    virtual ~IResetable() = default;
    virtual void reset() = 0;
};