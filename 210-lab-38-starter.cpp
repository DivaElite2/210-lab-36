#include <iostream>
#include <fstream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

// Function prototypes
void displayMenu();
void readCodesFromFile(StringBinaryTree& tree, const string& filename);

int main() {
    StringBinaryTree codeTree;
    string filename = "codes.txt";
    
    // Step 1: Read codes from file and populate BST
    cout << "Reading codes from " << filename << "...\n";
    readCodesFromFile(codeTree, filename);
    cout << "BST populated successfully!\n";
    
    // Step 2: Interactive menu
    int choice;
    string inputCode, newCode;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        
        switch (choice) {
            case 1: // Add a new code
                cout << "Enter code to add: ";
                getline(cin, inputCode);
                if (codeTree.searchNode(inputCode)) {
                    cout << "Code '" << inputCode << "' already exists!\n";
                } else {
                    codeTree.insertNode(inputCode);
                    cout << "Code '" << inputCode << "' added successfully!\n";
                }
                break;
                
            case 2: // Delete a code
                cout << "Enter code to delete: ";
                getline(cin, inputCode);
                if (codeTree.searchNode(inputCode)) {
                    codeTree.remove(inputCode);
                    cout << "Code '" << inputCode << "' deleted successfully!\n";
                } else {
                    cout << "Code '" << inputCode << "' not found!\n";
                }
                break;
                
            case 3: // Search for a code
                cout << "Enter code to search: ";
                getline(cin, inputCode);
                if (codeTree.searchNode(inputCode)) {
                    cout << "Code '" << inputCode << "' found in BST!\n";
                } else {
                    cout << "Code '" << inputCode << "' not found!\n";
                }
                break;
                
            case 4: // Modify a code
                cout << "Enter code to modify: ";
                getline(cin, inputCode);
                cout << "Enter new code: ";
                getline(cin, newCode);
                codeTree.modify(inputCode, newCode);
                break;
                
            case 5: // Display all codes (in-order)
                cout << "\nAll codes (in-order):\n";
                cout << "---------------------\n";
                codeTree.displayInOrder();
                break;
                
            case 6: // Display pre-order
                cout << "\nAll codes (pre-order):\n";
                cout << "---------------------\n";
                codeTree.displayPreOrder();
                break;
                
            case 7: // Display post-order
                cout << "\nAll codes (post-order):\n";
                cout << "---------------------\n";
                codeTree.displayPostOrder();
                break;
                
            case 8: // Exit
                cout << "Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        cout << endl;
        
    } while (choice != 8);
    
    return 0;
}

void displayMenu() {
    cout << "=== String BST Code Manager ===\n";
    cout << "1. Add a new code\n";
    cout << "2. Delete a code\n";
    cout << "3. Search for a code\n";
    cout << "4. Modify a code\n";
    cout << "5. Display all codes (in-order)\n";
    cout << "6. Display codes (pre-order)\n";
    cout << "7. Display codes (post-order)\n";
    cout << "8. Exit\n";
    cout << "Enter your choice (1-8): ";
}

void readCodesFromFile(StringBinaryTree& tree, const string& filename) {
    ifstream inputFile(filename);
    string code;
    
    if (!inputFile) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    
    while (getline(inputFile, code)) {
        // Only insert non-empty lines
        if (!code.empty()) {
            tree.insertNode(code);
        }
    }
    
    inputFile.close();
}