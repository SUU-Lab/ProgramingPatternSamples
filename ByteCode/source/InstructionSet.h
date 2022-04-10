#pragma once

#include <cstdint>

typedef std::uint8_t byte;

enum class Instruction : byte
{
    InsertLiteral = 0x00,
    SetHealth     = 0x01,
    SetWisdom     = 0x02,
    SetAgility    = 0x03,
};

byte ToByteCode(Instruction instruction);
Instruction ToInstruction(byte code);

void SetHealth(int wizard, int amount);
void SetWisdom(int wizard, int amount);
void SetAgility(int wizard, int amount);
