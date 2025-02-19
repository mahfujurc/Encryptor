#include <iostream>
#include <fstream>
using namespace std;

// Function to encrypt or decrypt a file using XOR cipher
void encryptDecryptFile(const string& filename, char key) {
    fstream file(filename, fstream::in | fstream::out);
    if (!file) {
        cerr << "Error: Cannot open file!" << endl;
        return;
    }
    
    char ch;
    while (file.get(ch)) {
        file.seekp(-1, ios::cur); // Move back to modify
        file.put(ch ^ key); // XOR encryption/decryption
        file.flush();
    }
    
    cout << "Operation completed on: " << filename << endl;
    file.close();
}

int main() {
    string filename;
    char key;
    int choice;
    
    cout << "Enter filename: ";
    cin >> filename;
    cout << "Enter a single character encryption key: ";
    cin >> key;
    
    cout << "Choose operation:\n1. Encrypt\n2. Decrypt\nEnter choice: ";
    cin >> choice;
    
    if (choice == 1 || choice == 2) {
        encryptDecryptFile(filename, key);
    } else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
