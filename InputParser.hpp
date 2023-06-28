#include <string>
#include <vector>
class InputParser{
public:
    InputParser(int argc, char* argv[]);
    InputParser(InputParser &&) = default;
    InputParser(const InputParser &) = default;
    InputParser &operator=(InputParser &&) = default;
    InputParser &operator=(const InputParser &) = default;
    ~InputParser();

    void printAllArgs();
    void printCommandFlags();
    
    int getArgCount();

private:
    int argCount;
    std::vector<std::string> args;
    std::vector<std::string> commandFlags;

    void toStringVector(int argc, char* argv[]);
    void parseArgs();

};

