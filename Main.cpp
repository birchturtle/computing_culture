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

    cout << "Checking files at path.." << endl;
    
    FileController fc {argv[1]};
    deque<string> q = fc.getDirContents();
    for (string &dir_entry : q) {
      string test;
      if ((test = dir_entry) == "ars_notoria") {
        fc.readWholeTextFile(test);
        break;
      }
        cout << dir_entry << endl;
    }
    return 0;
}
