 #include <iostream>
#include <vector>
#include <string>
#include <sstream> // Include for std::stringstream

using namespace std;

class IntermediateCodeGenerator {
private:
    static vector<string> intermediateCode;
    static int labelCounter;

public:
    static void generateIntermediateCode(const string& cppCode) {
        string line;
        stringstream ss(cppCode);

        while (getline(ss, line)) {
            line = trim(line);
            if (line.find("if") != string::npos) {
                handleIfStatement(line);
            } else if (line.find("while") != string::npos) {
                handleWhileStatement(line);
            } else if (!line.empty()) {
                intermediateCode.push_back(line);
            }
        }
    }

    static void handleIfStatement(const string& line) {
        intermediateCode.push_back("if " + line.substr(3) + " goto L" + convertToString(labelCounter));
        intermediateCode.push_back("goto L" + convertToString(labelCounter + 1));
        intermediateCode.push_back("L" + convertToString(labelCounter) + ":");
        labelCounter++;
    }

    static void handleWhileStatement(const string& line) {
        intermediateCode.push_back("L" + convertToString(labelCounter) + ":");
        intermediateCode.push_back("if " + line.substr(6) + " goto L" + convertToString(labelCounter + 1));
        intermediateCode.push_back("goto L" + convertToString(labelCounter + 2));
        intermediateCode.push_back("L" + convertToString(labelCounter + 1) + ":");
        labelCounter += 3;
    }

    static void printIntermediateCode() {
        for (const auto& code : intermediateCode) {
            cout << code << endl;
        }
    }

    static string trim(const string& s) {
        size_t start = s.find_first_not_of(" \t");
        size_t end = s.find_last_not_of(" \t");
        return (start != string::npos && end != string::npos) ? s.substr(start, end - start + 1) : "";
    }

    static string convertToString(int value) {
        stringstream ss;
        ss << value;
        return ss.str();
    }
};

vector<string> IntermediateCodeGenerator::intermediateCode;
int IntermediateCodeGenerator::labelCounter = 1;

int main() {
    string cppCode = "int x = 5;\n" +
                     string("if (x > 0) {\n") +
                     "    cout << \"x is positive\" << endl;\n" +
                     "}\n" +
                     string("while (x > 0) {\n") +
                     "    cout << \"x is still positive\" << endl;\n" +
                     "    x--;\n" +
                     "}";

    IntermediateCodeGenerator::generateIntermediateCode(cppCode);
    IntermediateCodeGenerator::printIntermediateCode();

    return 0;
}