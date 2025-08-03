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
void listFiles(){
    cout << "\nList Files Menu:\n";
    cout << "[1] List All Files\n";
    cout << "[2] List Files by Extension\n";
    cout << "[3] List Files by Pattern\n";

int choice = getValidInput();

try {
        switch (choice) {
        case 1: {
            cout << "\nFiles in " << fs::current_path().string() << ":\n";
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                cout << "- " << entry.path().filename().string() << endl;
            }
            break;
        }
        case 2: {
            string ext;
            cout << "Enter file extension (e.g., .txt): ";
            getline(cin, ext);
            cout << "\nFiles with extension " << ext << ":\n";
            bool found = false;
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                if (entry.path().extension() == ext) {
                    cout << "- " << entry.path().filename().string() << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No files found with extension " << ext << ".\n";
            }
            break;
        }
        case 3: {
            string pattern;
            cout << "Enter pattern (e.g., moha*.*): ";
            getline(cin, pattern);
            cout << "\nFiles matching pattern " << pattern << ":\n";
            bool found = false;
            string prefix = pattern.substr(0, pattern.find('*'));
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                string name = entry.path().filename().string();
                if (name.find(prefix) == 0) {
                    cout << "- " << name << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No files found matching pattern " << pattern << ".\n";
            }
            break;
        }
        default:
            cout << "Invalid option!\n";
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error accessing filesystem: " << e.what() << endl;
    }
}




