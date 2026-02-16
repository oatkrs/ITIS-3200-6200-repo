#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "json.hpp"


using json = nlohmann::json;

std::size_t hash_file(std::string filenpath) {
	std::cout << "Hashing file: " << filenpath << std::endl;

    std::ifstream file(filenpath);
    if (!file.is_open()) { //file does open
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string text; // string to hash
    std::string line;
    while (std::getline(file, line)) {
        for (char c : line) {
            text += std::to_string(static_cast<int>(c));
        }
    }

    std::hash<std::string> hasher; // hash function
    std::size_t hash = hasher(text);
    file.close();

    return hash;

};

std::vector<std::string> traverse_directory() {
    bool done = false; // flag to ensure file is found
    std::vector<std::string> info;
    while (!done) {
        std::string path;
        std::cout << "Enter the file path: " << std::endl;
        std::cin >> path; // get file path from user

		std::string stop = "end";
        if (path == "end") {
            std::cout << "Exiting program." << std::endl;
			done = true;
            exit(1);
		}
        
        std::ifstream file(path);
        if (file.is_open()) {
            std::cout << "traversing file: " << std::endl;
            info.push_back(path);
            std::size_t hash = hash_file(path);
            done = true;
            info.push_back(std::to_string(hash));
            file.close();
        }
        else {
            std::cout << "File not found, please try again." << std::endl;
        }
    }
    return info;


};

void generate_table() {
	std::cout << "Generating hash table" << std::endl;
    std::vector<std::string> info = traverse_directory();

    json fileData = {
        {"hash", info[1]},
        {"path", info[0]}
    };
    if (!fileData.is_object()) {
        std::cerr << "Error creating JSON object!" << std::endl;
        return;
	}

    std::ofstream o("hash_info.json");
    if (!o.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
	}
	o << std::setw(4) << fileData << std::endl;

    std::cout << "Hash table generated" << std::endl;


};

void verify_hash() {
	std::cout << "Verifying hash" << std::endl;

    std::ifstream inputFile("hash_info.json");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    json data = json::parse(inputFile);
	//std::cout << "Data read from file: " << data.dump(4) << std::endl;
    
    std::string path = data["path"].get<std::string>();
    std::string file_hash = data["hash"].get<std::string>();

    inputFile.close();

    std::cout << file_hash << " " << path << std::endl;



    std::size_t hash = hash_file(path);
    if (file_hash == std::to_string(hash)) {
        std::cout << "Hash verified" << std::endl;
    }
    else {
        std::cout << "Hash not verified" << std::endl;
	}
    
};


int main(int argc, char const* argv[])
{
    while (true) {
        std::string text;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "0. exit" << std::endl;
        std::cout << "1. generate a new hash" << std::endl;
        std::cout << "2. verify a hash" << std::endl;

        std::cin >> text;
        if (text == "1") {
            generate_table();
        }
        else if (text == "2") {
            std::cout << "hash verification" << std::endl;
            verify_hash();
        }
        else if (text == "0") {
            std::cout << "Exiting program." << std::endl;
			exit(0);
        }
        else {
            std::cout << "Invalid option" << std::endl;
        }
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
    }
    /* code */
    return 0;
}


