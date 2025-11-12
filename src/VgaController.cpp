#include "VgaController.h"

VgaController::VgaController() {
    reset();
}

void VgaController::evaluate() {
    //Evaluate all the booleans and calculate outputs
    hSync = !(x < H_SYNC_PULSE);
    vSync = !(y < V_SYNC_PULSE);
    doneLine = (x >= (H_WHOLE_LINE -1));
    doneFrame = (y >= (V_WHOLE_FRAME - 1));
    videoEnable = (
    x >= (H_SYNC_PULSE + H_FRONT_PORCH) &&
    x < (H_SYNC_PULSE + H_FRONT_PORCH + H_VISIBLE_AREA)
    &&
    y >= (V_SYNC_PULSE + V_FRONT_PORCH) &&
    y < (V_SYNC_PULSE + V_FRONT_PORCH + V_VISIBLE_AREA)
    );
}
void VgaController::commit() {
    //Set outputs and increment counters
    //Horizontal counter
    if (doneLine) x = 0;
    else x = x + 1;
    //Vertical counter
    if (doneFrame) y = 0;
    else if (doneLine) y = y + 1;
    //RGB data outputs
    if (videoEnable) {
        redOut = (dataIn >> 5) & 0x07;        //Top 3 bits for red
        greenOut = (dataIn >> 2) & 0x07;      //Middle 3 bits for green
        blueOut = dataIn & 0x07;              //Bottom 2 bits for blue
    } else {
        redOut = 0;
        greenOut = 0;
        blueOut = 0;
    }

    //Calculate memory address - think about negative coordinates
    pixelX = x - (H_SYNC_PULSE + H_FRONT_PORCH);
    pixelY = y - (V_SYNC_PULSE + V_FRONT_PORCH);
    address.first = pixelY;
    address.second = pixelX;
}
void VgaController::print(){
    //TODO: Implement print function
    std::cout << std::format("VGA Controller State: X: {}, Y: {}    HSync: {}, VSync: {}    Red: {}, Green: {}, Blue: {}    Address: ({}, {})\n",
        x, y, hSync, vSync, redOut.to_ulong(), greenOut.to_ulong(), blueOut.to_ulong(), address.first, address.second);
}

void VgaController::reset() {
    //Reset all counters and outputs
    x = 0;
    y = 0;
    pixelX = 0;
    pixelY = 0;
    videoEnable = false;
    doneLine = false;
    doneFrame = false;
    dataIn = 0;
    redOut = 0;
    greenOut = 0;
    blueOut = 0;
    hSync = true; //Active low
    vSync = true; //Active low
    address = {0, 0};
}

std::ostream& operator<<(std::ostream& os, const VgaController& vga) {
    os << std::format("VGA Controller State: X: {}, Y: {}    HSync: {}, VSync: {}    Red: {}, Green: {}, Blue: {}    Address: ({}, {})",
        vga.x, vga.y, vga.hSync, vga.vSync, vga.redOut.to_ulong(), vga.greenOut.to_ulong(), vga.blueOut.to_ulong(), vga.address.first, vga.address.second);
    return os;
}