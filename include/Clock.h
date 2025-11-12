#include <vector>
#include "ITickable.h"

class Clock {
    std::vector<ITickable&> tickables;
public:
    Clock() = default;
    ~Clock() = default;
    void tick();
    void addTickable(ITickable& tickable) {
        tickables.push_back(tickable);
    }
};