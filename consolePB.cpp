#include <iostream>
#include <conio.h>
#include <vector>
#include<string>

using namespace std;


const int TABLE_SIZE = 100; 

struct Node {
    string name;  
    string phone; 
    Node* next;   

    Node(string n, string p) : name(n), phone(p), next(nullptr) {}
};

// Hashtable class
class HashTable {
private:
    vector<Node*> table;

  
    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch; 
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE, nullptr); 
    }

    // Add a contact
    void addContact(const string& name, const string& phone) {
        int index = hashFunction(name);
        Node* newNode = new Node(name, phone);

        if (table[index] == nullptr) {
            table[index] = newNode; 
        }
        else {
            Node* current = table[index];
            while (current->next != nullptr) {
                if (current->name == name) {
                    current->phone = phone; 
                    delete newNode;         
                    return;
                }
                current = current->next;
            }
            if (current->name == name) {
                current->phone = phone; 
                delete newNode;
            }
            else {
                current->next = newNode;
            }
        }
        cout << "Contact added successfully!" << endl;
    }

    // Remove a contact
    void removeContact(const string& name) {
        int index = hashFunction(name);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Contact not found!" << endl;
            return;
        }

        if (prev == nullptr) {
            table[index] = current->next;
        }
        else {
            prev->next = current->next;
        }

        delete current;
        cout << "Contact removed successfully!" << endl;
    }


    //view a particular contact at a given instance
    void viewContact(const string& name) {
        int index = hashFunction(name);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->name == name) {
                cout << "Name: " << current->name << ", Phone: " << current->phone << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found!" << endl;
    }

    // view all contacts at once
    void viewAllContacts() {
        bool empty = true;
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << "Name: " << current->name << ", Phone: " << current->phone << endl;
                current = current->next;
                empty = false;
            }
        }
        if (empty) {
            cout << "No contacts found!" << endl;
        }
    }
};



int main()
{
    HashTable phonebook;
    int size = 40;
    int middle = size / 2;

    cout << "______________________________________\n";
  
    for (int i = 0; i < size; i++) {
        cout << "*";
    }
    cout << endl;

    for (int i = 0; i < size / 2; i++) {
        cout << "*";
        if (i == middle / 2 - 1) {
            cout << " Welcome to PhoneBook application ";
        }
        else {
            for (int j = 0; j < size - 2; j++) {
                cout << " ";
            }
        }
        cout << "*";
        cout << endl;
    }
  
    for (int i = 0; i < size; i++) {
        cout << "*";
    }
    cout << endl;
    cout << "______________________________________\n\n";

    cout << "Press any key to Continue....." << endl;
    _getch();
    int choice = 0;
    do {
        cout << "1. Add Contact" << endl;
        cout << "2. Remove Contact" << endl;
        cout << "3. View Contact" << endl;
        cout << "4. View All Contacts" << endl;
        cout << "5. Exit" << endl;

        cout << "______________________________________\n\n";
        cout << "Enter your Choices: " << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            string name, number;
            cout << "Add Contact" << endl;
            cout << "Enter Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, name); 
            cout << "Enter Phone Number: ";
            getline(cin, number); 
            phonebook.addContact(name, number);
            cout << "______________________________________\n";
            break;
        }
        case 2: {
            cout << "Remove Contact" << endl;
            string name;
            cout << "Enter Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            phonebook.removeContact(name);
            cout << "______________________________________\n";
            break;
        }
        case 3: {
            cout << "View Contact" << endl;
            string name;
            cout << "Enter Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, name);
            phonebook.viewContact(name);
            cout << "______________________________________\n";
            break;
        }
        case 4: {
            cout << "View All Contacts" << endl;
            phonebook.viewAllContacts();
            cout << "______________________________________\n";
            break;
        }
        case 5: {
            cout << "______________________________________\n";
            cout << "Thank you for using our application!" << endl;
            cout << "Exiting the Application" << endl;
            break;
        }
        default: {
            cout << "Invalid Choice" << endl;
        }
        }
    }
    while (choice != 5);
    return 0;
};