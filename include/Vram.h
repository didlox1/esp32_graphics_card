#pragma once
#include <array>
#include <cstdint>
#include <format>
#include <iostream>
#include "Module.h"

#define WRITE_ADDRESS_SIZE 16
#define VRAM_SIZE (1 << WRITE_ADDRESS_SIZE) // 2^WRITE_ADDRESS_SIZE bytes

//For now let's go with resetable VRAM (need to change it later)
//And also with vram that can read and write at the same tick (clock pulse)
class Vram : public Module {
    private:
    std::array<uint8_t, VRAM_SIZE> m_memory;
    uint16_t m_writeAddress;
    uint16_t m_readAddress;
    uint8_t m_readData;
    uint8_t m_writeData;
    bool _wEnable;
public:
    Vram();
    ~Vram();
    // VRAM access methods
    void write();
    uint8_t read();
    //  Setters
    void setReadAddress(uint16_t readAddress) {m_readAddress = readAddress;}
    void setWriteAddress(uint16_t writeAddress) {m_writeAddress = writeAddress;}
    void setWriteData(uint8_t writeData) { m_writeData = writeData;}
    // Getter
    uint8_t getReadData() const { return m_readData;}
    // 
    void evaluate() override;
    void commit() override;
    void reset() override;
    void print() override;
};