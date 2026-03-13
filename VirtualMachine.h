#ifndef VM_H
#define VM_H

#include <map>
#include <vector>
#include <string>
#include "Instruction.h"

class VirtualMachine {

private:

    std::map<std::string,int> registers;

    std::vector<int> memory;

    int PC;
    Instruction currentInstruction;

public:

    VirtualMachine();

    void loadProgram(std::vector<Instruction> program);

    void fetch(std::vector<Instruction> program);

    void decode();

    void execute();

    void run(std::vector<Instruction> program);

};

#endif
