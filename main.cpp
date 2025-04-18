#include <iostream>

#include "calculator.cpp"

int main(int argc, char *argv[]) {
    FILE* in_file;
    char file_name[100];
    std::cout << "file name: ";
    std::cin >> file_name;
    in_file = fopen(file_name, "r"); // read only
    if (in_file == NULL){
        printf("File not found");
        exit(0);
    }
    char data_string[100];
    while (fgets(data_string, sizeof(data_string), in_file)) {
        // Reads the file until there's nothing left
        std::string number;
        strcpy(number.data(), strtok(data_string, " "));
        if (not is_valid_conversion(number)) {
            std::cout << "Not valid float\n";
        }else {
            std::cout<<parse_number(number);
        }
    }
}
// test commit