#include "InstructionSet.h"
#include <iostream>

byte ToByteCode(Instruction instruction)
{
    return static_cast<byte>(instruction);
}

Instruction ToInstruction(byte code)
{
    return static_cast<Instruction>(code);
}

void SetHealth(int wizard, int amount)
{
    std::cout << "SetHealth(wizard: " << wizard << ", amount: " << amount << ");\n";
}

void SetWisdom(int wizard, int amount)
{
    std::cout << "SetWisdom(wizard: " << wizard << ", amount: " << amount << ");\n";
}

void SetAgility(int wizard, int amount)
{
    std::cout << "SetAgility(wizard: " << wizard << ", amount: " << amount << ");\n";
}
