#include <iostream>
#include <string>
#include <filesystem>
#include <direct.h>

using namespace std;
namespace fs = std::filesystem;


void mainMenu() {
    cout << "\nDirectory Management System\n";
    cout << "[1] List Files\n";
    cout << "[2] Create Directory\n";
    cout << "[3] Change Directory\n";
    cout << "[4] Exit\n";
    cout << "Enter your choice: ";
}


int getValidInput() {
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore();
    return input;
}





