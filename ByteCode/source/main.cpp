#include "VirtualMachine.h"

int main(int, const char*[])
{
    std::vector<byte> byteCode = {
        ToByteCode(Instruction::InsertLiteral), 0x00, 0x00, 0x00, 0x00, // wizard
        ToByteCode(Instruction::InsertLiteral), 0x64, 0x00, 0x00, 0x00, // amount
        ToByteCode(Instruction::SetHealth),

        ToByteCode(Instruction::InsertLiteral), 0x00, 0x00, 0x00, 0x00, // wizard
        ToByteCode(Instruction::InsertLiteral), 0xFF, 0x00, 0x00, 0x00, // amount
        ToByteCode(Instruction::SetWisdom),

        ToByteCode(Instruction::InsertLiteral), 0x00, 0x00, 0x00, 0x00, // wizard
        ToByteCode(Instruction::InsertLiteral), 0xFF, 0xFF, 0x00, 0x00, // amount
        ToByteCode(Instruction::SetAgility),
    };

    VirtualMachine vm;
    vm.Interpret(byteCode);

    //int x = 0x12345678;
    //byte* p = reinterpret_cast<byte*>(&x);
    //printf_s("0x%x, 0x%x, 0x%x, 0x%x\n", p[0], p[1], p[2], p[3]);

    return 0;
}
