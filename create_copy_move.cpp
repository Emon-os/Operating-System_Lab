#include <bits/stdc++.h>
using namespace std;

void createFile(const char* filename){
    FILE *fp = fopen(filename,"w");
    if(fp == NULL){
        cout << "Error creating file\n";
        return;
    }
    cout << "File '" << filename << "' created successfully!\n";
    fclose(fp);
}

void deleteFile(const char* filename){
    if(remove(filename) == 0){
        cout << "File '" << filename << "' deleted successfully!\n";
    }
    else{
        cout << "File does not exist!\n";
    }
}

void copyFile(const char* src,const char* dst){
    FILE *f1 = fopen(src,"rb");
    if(!f1){
        cout << "Source file not found!\n";
        return;
    }
    FILE *f2 = fopen(dst,"wb");
    if(!f2){
        cout << "Unable to create destination file!\n";
        fclose(f1);
        return;
    }

    char ch;
    while(fread(&ch,1,1,f1))
        fwrite(&ch,1,1,f2);

    cout << "File copied from '" << src << "' to '" << dst << "' successfully!\n";

    fclose(f1);
    fclose(f2);
}

void movefile(const char* src,const char* dst){
    if(rename(src,dst) == 0){
        cout << "File moved from '" << src << "' to '" << dst << "' successfully!\n";
    }
    else{
        cout << "Source file not found!\n";
    }
}

int main(){
    int choice = 0;
    char file1[100], file2[100];

    while(choice != 5){   // <-- FIXED HERE
        cout << "\n--- File Operation Simulator ---\n";
        cout << "1. Create File\n";
        cout << "2. Delete File\n";
        cout << "3. Copy File\n";
        cout << "4. Move File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

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
                cout << "Enter source file name: ";
                cin >> file1;
                cout << "Enter destination file name: ";
                cin >> file2;
                copyFile(file1, file2);
                break;

            case 4:
                cout << "Enter source file name: ";
                cin >> file1;
                cout << "Enter destination file name: ";
                cin >> file2;
                movefile(file1, file2);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
