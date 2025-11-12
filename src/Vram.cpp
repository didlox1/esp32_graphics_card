#include "Vram.h"

Vram::Vram() {
    reset();
}

Vram::~Vram() = default;

uint8_t Vram::read() {
    return m_memory[m_readAddress];
}

void Vram::write() {
    m_memory[m_writeAddress] = m_writeData;
}

void Vram::evaluate() {
    bool _wEnable = m_writeAddress>>15;
}
void Vram::commit() {
    if (!_wEnable) write();
    m_readData = read();
}

void Vram::reset(){
    m_memory.fill(0);
    m_writeAddress = 0;
    m_readAddress = 0;
    m_readData = 0;
    m_writeData = 0;
    bool _wEnable = 1;
}

void Vram::print(){
    std::cout << std::format("Vram State: ReadData: {}, ReadAddress: {}    WriteData: {}, WriteAddress: {}\n",m_readData, m_readAddress, m_writeData, m_writeAddress);
}
