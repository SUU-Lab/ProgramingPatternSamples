#include "VirtualMachine.h"
#include "InstructionSet.h"
#include <cassert>

void VirtualMachine::Interpret(const std::vector<byte>& byteCode)
{
    
    for (std::size_t index = 0; index < byteCode.size(); ++index)
    {
        const byte code = byteCode[index];

        switch (ToInstruction(code))
        {
        case Instruction::InsertLiteral: // 8bit little endian
        {
            assert((index + 4) <= byteCode.size());
            const int value = (*reinterpret_cast<const int*>(&byteCode[index + 1]));
            Push(value);
            index += 4;
            break;
        }

        case Instruction::SetHealth:
        {
            const int amount = Pop();
            const int wizard = Pop();
            SetHealth(wizard, amount);
            break;
        }

        case Instruction::SetWisdom:
        {
            const int amount = Pop();
            const int wizard = Pop();
            SetWisdom(wizard, amount);
            break;
        }

        case Instruction::SetAgility:
        {
            const int amount = Pop();
            const int wizard = Pop();
            SetAgility(wizard, amount);
            break;
        }

        default:
            break;
        }
    }
}

void VirtualMachine::Push(int value)
{
    m_stack.push(value);
}

int VirtualMachine::Pop()
{
    int value = m_stack.top();
    m_stack.pop();
    return value;
}
