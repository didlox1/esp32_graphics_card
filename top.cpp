// Top module file
#include "VgaController.h"
#include "Clock.h"
int main() {
    VgaController vgaController;
    Clock clock;
    clock.addVgaController(vgaController);
    clock.tick(1000);
    return 0;
}