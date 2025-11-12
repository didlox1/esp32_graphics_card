#include "ITickable.h"
#include "IResetable.h"

class Gpu : public ITickable, public IResetable {
public:
    Gpu() = default;
    ~Gpu() = default;
    void evaluate() override;
    void commit() override;
    void reset() override;
};