#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
#include <map>

void analyzeTextFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    int letterCount = 0;
    int punctuationCount = 0;
    int spaceCount = 0;

    std::string line;
    while (std::getline(file, line)) {
        ++lineCount;

        bool inWord = false;
        for (char ch : line) {
            ++charCount;
            if (std::isspace(static_cast<unsigned char>(ch))) {
                ++spaceCount;
                if (inWord) {
                    inWord = false;
                    ++wordCount;
                }
            } else {
                inWord = true;
                if (std::isalpha(static_cast<unsigned char>(ch))) {
                    ++letterCount;
                } else if (std::ispunct(static_cast<unsigned char>(ch))) {
                    ++punctuationCount;
                }
            }
        }
        if (inWord) {
            ++wordCount;
        }
    }

    file.close();

    std::cout << "Analysis of file: " << filePath << std::endl;
    std::cout << "Lines: " << lineCount << std::endl;
    std::cout << "Words: " << wordCount << std::endl;
    std::cout << "Characters: " << charCount << std::endl;
    std::cout << "Letters: " << letterCount << std::endl;
    std::cout << "Punctuation: " << punctuationCount << std::endl;
    std::cout << "Spaces: " << spaceCount << std::endl;

    
    std::ofstream resultFile("analysis_result.txt");
    if (resultFile.is_open()) {
        resultFile << "Analysis of file: " << filePath << std::endl;
        resultFile << "Lines: " << lineCount << std::endl;
        resultFile << "Words: " << wordCount << std::endl;
        resultFile << "Characters: " << charCount << std::endl;
        resultFile << "Letters: " << letterCount << std::endl;
        resultFile << "Punctuation: " << punctuationCount << std::endl;
        resultFile << "Spaces: " << spaceCount << std::endl;
        resultFile.close();
    } else {
        std::cerr << "Error creating result file" << std::endl;
    }
}

int main() {
    std::string folderPath;
    std::string fileName;

    std::cout << "Enter the path to the folder: ";
    std::getline(std::cin, folderPath);

    std::cout << "Enter the text file name: ";
    std::getline(std::cin, fileName);

    
    std::string filePath = folderPath + "\\" + fileName;

    analyzeTextFile(filePath);

    return 0;
}
