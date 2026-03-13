#include "VirtualMachine.h"
#include <iostream>

VirtualMachine::VirtualMachine() {

    registers["AL"] = 0;
    registers["AH"] = 0;
    registers["BL"] = 0;
    registers["BH"] = 0;

    registers["ACC"] = 0;

    PC = 0;

    memory.resize(256);
}

void VirtualMachine::fetch(std::vector<Instruction> program){

    std::cout << "FETCH\n";

    currentInstruction = program[PC];

    PC++;

}

void VirtualMachine::decode(){

    std::cout << "DECODE: " << currentInstruction.getName() << "\n";

}

void VirtualMachine::execute(){

    std::string name = currentInstruction.getName();
    auto args = currentInstruction.getArgs();

    std::cout << "EXECUTE\n";

    if(name == "MOVE"){

        registers[args[0]] = std::stoi(args[1]);

    }

    else if(name == "ADD"){

        registers[args[0]] += registers[args[1]];

    }

    else if(name == "STORE"){

        int addr = std::stoi(args[0]);
        memory[addr] = registers["ACC"];

    }

    else if(name == "START"){

        std::cout << "Program started\n";

    }

    else if(name == "STOP"){

        std::cout << "Program finished\n";

        exit(0);

    }

    std::cout << "Registers:\n";

    for(auto r : registers){

        std::cout << r.first << " = " << r.second << "\n";

    }

}

void VirtualMachine::run(std::vector<Instruction> program){

    while(true){

        fetch(program);
        decode();
        execute();

    }

}
