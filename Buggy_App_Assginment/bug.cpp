#include <iostream>

#include <fstream>

#include <string>

 // Code was not working as sample.txt was not existing 
 // steps done to trace it
 // call strace -c ./app 
 // openat was failing as no file exists 
 // using command line write " touch sample.txt"
 // run the app again it will work
 // app usage is to get each line inside the txt file and print it out 

int main() {

    std::ifstream file("sample.txt");

    if (!file.is_open()) {

        std::cerr << "Error: File not found!\n";

        return 1;

    }

 

    std::string line;

    while (std::getline(file, line)) {

        std::cout << line << "\n";

    }

 

    file.close();

    return 0;

}