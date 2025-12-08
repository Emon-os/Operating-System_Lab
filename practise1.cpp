#include <iostream>
#include <cstdio>     // for remove(), rename()
#include <fstream>    // for file read/write

using namespace std;

void createFile(const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        cout << "Error creating file.\n";
        return;
    }
    cout << "File created successfully!\n";
    fclose(fp);
}

void deleteFile(const char* filename) {
    if (remove(filename) == 0)
        cout << "File deleted successfully!\n";
    else
        cout << "File not found!\n";
}

void copyFile(const char* source, const char* dest) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        cout << "Source file not found!\n";
        return;
    }

    FILE *dst = fopen(dest, "wb");
    char ch;

    while (!feof(src)) {
        ch = fgetc(src);
        if (!feof(src))
            fputc(ch, dst);
    }

    fclose(src);
    fclose(dst);
    cout << "File copied successfully!\n";
}

void moveFile(const char* source, const char* dest) {
    if (rename(source, dest) == 0)
        cout << "File moved successfully!\n";
    else
        cout << "Error moving file!\n";
}

int main() {
    int choice;
    char file1[100], file2[100];

    while (true) {
        cout << "\n--- File Operations ---\n";
        cout << "1. Create File\n";
        cout << "2. Delete File\n";
        cout << "3. Copy File\n";
        cout << "4. Move File\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter filename to create: ";
                cin >> file1;
                createFile(file1);
                break;

            case 2:
                cout << "Enter filename to delete: ";
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
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
