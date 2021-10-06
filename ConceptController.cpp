#include <iostream>
#include <string>
#include <deque>
#include "Concept.cpp"

class ConceptController {
    public:
        static std::deque<Concept> Concepts;
        static void AddConcept(Concept c);
        static void PrintByWord(std::string word);
        ConceptController() {}
};

std::deque<Concept> ConceptController::Concepts;

void ConceptController::AddConcept(Concept c) {
    ConceptController::Concepts.push_back(c);
}
void ConceptController::PrintByWord(std::string word)  {
    std::cout << word << std::endl;
    for (Concept c : ConceptController::Concepts) {
        std::cout << "Her er det igen: " << c.Word << std::endl;
    }
    std::cout << std::endl << std::flush;
}