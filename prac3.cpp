#include <bits/stdc++.h>
using namespace std;

// Hash table class using separate chaining
class HashTable {
private:
    vector<list<string>> buckets;  // Vector of lists (buckets)

    // Hash function to map a string to an index
    int hashFunc(const string& str) {
        int hashVal = 0;
        int i = 0;
        int len = str.size();
        for (char c : str) {
            hashVal = hashVal + int(c) * (pow(10, len - i - 1));
            i++;
        }
        return hashVal % 10;
    }

public:
    HashTable(int size) {
        buckets.resize(size);
    }

    // Insert a string into the hash table
    void insert(const string& str) {
        int idx = hashFunc(str);
        buckets[idx].push_back(str);  
    }

    // Search for a string in the hash table
    bool search(const string& str) {
        int idx = hashFunc(str);
        for (const string& s : buckets[idx]) {
            if (s == str) {
                return true;  
            }
        }
        return false;  
    }

    
    void display() {
        for (int i = 0; i < buckets.size(); ++i) {
            cout << "Bucket " << i << ": ";
            for (const string& s : buckets[i]) {
                cout << s << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable table(10);  

    string menu = "Enter your choice: \n1. Add\n2. Display\n3. Search\n4. Exit";
    int ch;
    string value;

    while (true) {
        cout << menu << endl;
        cout << "Your choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "\nEnter the element: ";
            cin >> value;
            table.insert(value);
        }
        else if (ch == 2) {
            table.display();
        }
        else if (ch == 3) {
            cout << "\nEnter the element to search: ";
            cin >> value;
            if (table.search(value)) {
                cout << value << " found in the hash table!" << endl;
            } else {
                cout << value << " not found in the hash table." << endl;
            }
        }
        else if (ch == 4) {
            break;  
        }
        else {
            cout << "\nPlease enter a valid option" << endl;
        }
    }

    return 0;
}
