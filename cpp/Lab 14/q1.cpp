#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Mapper {
public:
    std::vector<std::pair<std::string, int>> map(const std::string& line) {
        std::vector<std::pair<std::string, int>> result;
        std::string word;
        for (char c : line) {
            if (std::isalnum(c)) {
                word += std::tolower(c);
            } else if (!word.empty()) {
                result.push_back(std::make_pair(word, 1));
                word.clear();
            }
        }
        if (!word.empty()) {
            result.push_back(std::make_pair(word, 1));
        }
        return result;
    }
};

class Reducer {
public:
    std::vector<std::pair<std::string, int>> reduce(std::vector<std::pair<std::string, int>>& pairs) {
        std::sort(pairs.begin(), pairs.end());
        std::vector<std::pair<std::string, int>> result;
        for (size_t i = 0; i < pairs.size(); ++i) {
            int count = 1;
            while (i + 1 < pairs.size() && pairs[i].first == pairs[i + 1].first) {
                count++;
                i++;
            }
            result.push_back(std::make_pair(pairs[i].first, count));
        }
        return result;
    }
};

int main() {
    std::string filename;
    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: File not found." << std::endl;
        return 1;
    }

    std::vector<std::pair<std::string, int>> intermediate_result;
    Mapper mapper;
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::pair<std::string, int>> mapped_pairs = mapper.map(line);
        intermediate_result.insert(intermediate_result.end(), mapped_pairs.begin(), mapped_pairs.end());
    }

    Reducer reducer;
    std::vector<std::pair<std::string, int>> reduced_result = reducer.reduce(intermediate_result);

    std::ofstream output_file(filename + "_mr.txt");
    if (!output_file.is_open()) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return 1;
    }

    for (const auto& pair : reduced_result) {
        std::cout << pair.first << " " << pair.second << std::endl;
        output_file << pair.first << " " << pair.second << std::endl;
    }

    std::cout << "Output written to " << filename << ".txt" << std::endl;
    return 0;
}