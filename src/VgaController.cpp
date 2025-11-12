#include "VgaController.h"

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

    //Calculate memory address
    int pixelX = x - (H_SYNC_PULSE + H_FRONT_PORCH);
    int pixelY = y - (V_SYNC_PULSE + V_FRONT_PORCH);
    address.first = pixelY;
    address.second = pixelX;
}
void print(){
    //TODO: Implement print function
}