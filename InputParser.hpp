#include <string>
#include <vector>
class InputParser{
public:
    InputParser();
    InputParser(InputParser &&) = default;
    InputParser(const InputParser &) = default;
    InputParser &operator=(InputParser &&) = default;
    InputParser &operator=(const InputParser &) = default;
    ~InputParser();

    void toStringVector(int argc, char* argv[]); 
    void printCommandFlags();

private:
    std::vector<std::string> commandFlags;    
};

