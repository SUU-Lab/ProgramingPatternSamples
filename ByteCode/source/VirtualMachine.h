#pragma once

#include "InstructionSet.h"
#include <vector>
#include <stack>


class VirtualMachine
{
public:
    void Interpret(const std::vector<byte>& byteCode);

private:
    void Push(int value);
    int Pop();

private:
    std::stack<int> m_stack;
};
