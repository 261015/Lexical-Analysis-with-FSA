#include <iostream>
#include "VirtualMachine.h"

int main(){

    std::vector<Instruction> program;

    program.push_back(Instruction("START",{}));
    program.push_back(Instruction("MOVE",{"AL","10"}));
    program.push_back(Instruction("MOVE",{"BL","20"}));
    program.push_back(Instruction("ADD",{"AL","BL"}));
    program.push_back(Instruction("STOP",{}));

    VirtualMachine vm;

    vm.run(program);

}
