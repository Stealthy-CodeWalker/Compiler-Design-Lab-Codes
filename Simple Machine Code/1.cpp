#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

// Define an enum for different instruction types
enum class InstructionType {
    LOAD,
    ADD,
    STORE,
    HALT
};

// Define a map to associate instruction strings with their types
const unordered_map<string, InstructionType> instructionMap = {
    {"LOAD", InstructionType::LOAD},
    {"ADD", InstructionType::ADD},
    {"STORE", InstructionType::STORE},
    {"HALT", InstructionType::HALT}
};

// Function to translate an instruction string into its enum type
InstructionType getInstructionType(const string& instruction) {
    auto it = instructionMap.find(instruction);
    if (it != instructionMap.end()) {
        return it->second;
    } else {
        throw invalid_argument("Unknown instruction: " + instruction);
    }
}

// Function to generate machine code for an instruction
string generateMachineCode(InstructionType type, const vector<string>& operands) {
    switch (type) {
        case InstructionType::LOAD:
            if (operands.size() != 2) {
                throw invalid_argument("LOAD instruction requires two operands");
            }
            return "LOAD " + operands[0] + ", " + operands[1];
        case InstructionType::ADD:
            if (operands.size() != 2) {
                throw invalid_argument("ADD instruction requires two operands");
            }
            return "ADD " + operands[0] + ", " + operands[1];
        case InstructionType::STORE:
            if (operands.size() != 2) {
                throw invalid_argument("STORE instruction requires two operands");
            }
            return "STORE " + operands[0] + ", " + operands[1];
        case InstructionType::HALT:
            return "HALT";
        default:
            throw invalid_argument("Invalid instruction type");
    }
}

int main() {
    // Expression: x = a + b
    vector<pair<string, vector<string>>> program = {
        {"LOAD", {"R1", "a"}},     // LOAD R1, a
        {"LOAD", {"R2", "b"}},     // LOAD R2, b
        {"ADD", {"R1", "R1"}},     // ADD R1, R1
        {"STORE", {"x", "R1"}},    // STORE x, R1
        {"HALT", {}}                // HALT
    };

    try {
        cout << "Generated machine code:" << endl;
        for (const auto& instructionPair : program) {
            const string& instruction = instructionPair.first;
            const vector<string>& operands = instructionPair.second;

            InstructionType type = getInstructionType(instruction);
            string machineCode = generateMachineCode(type, operands);
            cout << machineCode << endl;
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}