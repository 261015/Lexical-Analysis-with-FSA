#include "Instruction.h"

Instruction::Instruction(std::string name, std::vector<std::string> args) {
    this->name = name;
    this->args = args;
}

std::string Instruction::getName() {
    return name;
}

std::vector<std::string> Instruction::getArgs() {
    return args;
}
