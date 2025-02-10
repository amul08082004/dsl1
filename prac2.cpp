#include <bits/stdc++.h>
using namespace std;

void insertion(int v, int arr[]) {
    int val = v % 10;  
    int l = 0;

    while (l < 10) {
        int index = (val + l) % 10;
        
        if (arr[index] == -1 || arr[index] == -2) {
            
            arr[index] = v;
            break;
        } else if (arr[index] == v) {
    
            arr[index] = v;
            break;
        } else {
            
            int old_value = arr[index];
            arr[index] = v;
            
            
            int nextIndex = (index + 1) % 10;
            while (arr[nextIndex] != -1 && arr[nextIndex] != -2) {
                nextIndex = (nextIndex + 1) % 10;
            }
            if (arr[nextIndex] == -1 || arr[nextIndex] == -2) {
                arr[nextIndex] = old_value;
                break;
            }
        }
        l++;
    }

    if (l == 10) {
        cout << "Table is full" << endl;
    }
}

void display(int arr[]) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == -1) {
            cout << "Slot " << i << " is empty." << endl;
        } else if (arr[i] == -2) {
            cout << "Slot " << i << " is deleted." << endl;
        } else {
            cout << "Slot " << i << ": " << arr[i] << endl;
        }
    }
}

void deletion(int n, int arr[]) {
    int val = n % 10;
    int l = 0;

    while (l < 10) {
        int index = (val + l) % 10;
        if (arr[index] == n) {
            arr[index] = -2;  // Mark as deleted
            cout << "Successfully deleted the value " << n << endl;
            return;
        }
        if (arr[index] == -1) {
            cout << "Value not found" << endl;
            return;
        }
        l++;
    }

    cout << "Value not found" << endl;
}

void search(int n, int arr[]) {
    int val = n % 10;
    int l = 0;

    while (l < 10) {
        int index = (val + l) % 10;
        if (arr[index] == n) {
            cout << "Value found at location: " << index << endl;
            return;
        } else if (arr[index] == -1) {
            cout << "Value is not present in the table" << endl;
            return;
        }
        l++;
    }

    cout << "Value is not present in the table" << endl;
}

int main() {
    int arr[10]={-1};
    
    int menu;
    while (true) {
        cout << "Enter your choice" << endl;
        cout << "1->Insert" << endl;
        cout << "2->Display" << endl;
        cout << "3->Deletion" << endl;
        cout << "4->Search" << endl;
        cout << "5->Exit" << endl;
        cin >> menu;

        if (menu == 1) {
            int n;
            cout << "Enter value you want to enter: ";
            cin >> n;
            insertion(n, arr);
        }
        else if (menu == 2) {
            cout << "Displaying the Hash table" << endl;
            display(arr);
        }
        else if (menu == 3) {
            int v;
            cout << "Enter value you want to delete: ";
            cin >> v;
            deletion(v, arr);
        }
        else if (menu == 4) {
            int v;
            cout << "Enter value you want to search: ";
            cin >> v;
            search(v, arr);
        }
        else if (menu == 5) {
            cout << "Successfully exited from program!!" << endl;
            break;
        }
        else {
            cout << "Enter valid option: " << endl;
        }
    }
}
