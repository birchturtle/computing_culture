#include <iostream>
#include <deque>
#include "ConceptController.cpp"
#include "FileController.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please specify path to input file directory" << endl;
        return -1;
    }
    Concept c { "Det er et Concept" };
    cout << "Her er det: " << c.Word << endl;
    Concept c2 {" det er det her på sin vis også "};
    ConceptController::AddConcept(c);
    ConceptController::AddConcept(c2);
    ConceptController::PrintByWord("røv");
    FileController fc {argv[1]};
    deque<string> q = fc.getDirContents();
    for (string &dir_entry : q) {
        cout << dir_entry << endl;
    }
    return 0;
}