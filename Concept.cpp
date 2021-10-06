#include <string>
#include <deque>

class Concept {
    public:
        std::string Word;
        int Count;
        std::deque<std::string> Associations;
    Concept(std::string word) {
        this->Word = word;
    }
};