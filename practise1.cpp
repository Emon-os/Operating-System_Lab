#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void createFile(const string &filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error creating file.\n";
        return;
    }
    cout << "File '" << filename << "' created successfully!\n";
}

void deleteFile(const string &filename) {
    if (fs::exists(filename)) {
        fs::remove(filename);
        cout << "File '" << filename << "' deleted successfully!\n";
    } else {
        cout << "File does not exist!\n";
    }
}

void copyFile(const string &source, const string &dest) {
    if (!fs::exists(source)) {
        cout << "Source file not found!\n";
        return;
    }
    fs::copy(source, dest, fs::copy_options::overwrite_existing);
    cout << "File copied from '" << source << "' to '" << dest << "' successfully!\n";
}

void moveFile(const string &source, const string &dest) {
    if (!fs::exists(source)) {
        cout << "Source file not found!\n";
        return;
    }
    fs::rename(source, dest);
    cout << "File moved from '" << source << "' to '" << dest << "' successfully!\n";
}

int main() {
    int choice;
    string file1, file2;

    while (true) {
        cout << "\n--- File Operation Simulator ---\n";
        cout << "1. Create File\n";
        cout << "2. Delete File\n";
        cout << "3. Copy File\n";
        cout << "4. Move File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter file name to create: ";
                cin >> file1;
                createFile(file1);
                break;

            case 2:
                cout << "Enter file name to delete: ";
                cin >> file1;
                deleteFile(file1);
                break;

            case 3:
                cout << "Enter source file: ";
                cin >> file1;
                cout << "Enter destination file: ";
                cin >> file2;
                copyFile(file1, file2);
                break;

            case 4:
                cout << "Enter source file: ";
                cin >> file1;
                cout << "Enter destination file: ";
                cin >> file2;
                moveFile(file1, file2);
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
