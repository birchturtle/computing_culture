#include <iostream>
#include <fstream>
#include <filesystem>
#include <deque>

class FileController {
    private:

        std::string path;

    public:

        FileController(std::string path) {
            this->path = path;
        }

        std::deque<std::string> getDirContents();

        std::string readWholeTextFile(std::string filename);
};

std::deque<std::string> FileController::getDirContents() {
    const std::__fs::filesystem::path DATADIR{this->path};
    std::deque<std::string> q;
    
    for(auto const& dir_entry: std::__fs::filesystem::directory_iterator{DATADIR}) {
        q.push_back(dir_entry.path().filename());
    }

    return q;
}

std::string FileController::readWholeTextFile(std::string filename) {
    
}