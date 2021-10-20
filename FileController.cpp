#include <iostream>
#include <fstream>
#include <filesystem>
#include <deque>
#include <string>

class FileController {
    private:

        std::string path;

    public:

        FileController(std::string path) {
            this->path = path;
        }

        std::deque<std::string> getDirContents();

        void readWholeTextFile(std::string filename);
};

std::deque<std::string> FileController::getDirContents() {
    const std::filesystem::path DATADIR = this->path;
    std::deque<std::string> q;

    for(auto const& dir_entry: std::filesystem::directory_iterator{DATADIR}) {
        q.push_back(dir_entry.path().filename());
    }

    return q;
}

void FileController::readWholeTextFile(std::string filename) {
  std::string filepath;
  filepath = this->path;
  if (filepath.substr((filepath.length() -1), 1) != "/") {
    filepath.append("/");
  }
    filepath.append(filename);
    std::cout << filepath << std::endl;
    if (std::ifstream is{filepath}) {
      std::string line;
      while (std::getline(is, line)) {
        std::cout << line << std::endl;
      }
      is.close();
    }
}
