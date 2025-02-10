#include <bits/stdc++.h>
using namespace std;
 
void insertion(int v,int arr[]){
    int val=v%10;
    if(arr[val]==-1){
        arr[val]=v;
    }else{
        int l=1;
        while(l<10){
 
            if(arr[(val+l)%10]==-1){
                arr[(val+l)%10]=v;
                break;
            }
            l++;
        }
        if(l==10){
            cout<<"Table is full";
        }
 
    }
 
}
 
void display(int arr[]){
    for(int i=0;i<10;i++){
        cout<<"Slot "<<i<<" is : ";
        if(arr[i]==-1 || arr[i]==-2) cout<<"Empty"<<endl;
        else{
            cout<<arr[i];
        }

    }
}
 
void deletion(int n, int arr[]){
    int comp=0;
    int val=n%10;
 
    int l=0;
    while(l<10){
        if(arr[(val+l)%10]==n){
            arr[(val+l)%10]=-2;
            cout<<"Sucessfully deleted the value"<<endl;
            break;
        }if(arr[(val+l)%10]==-1){
            cout<<"value not found"<<endl;
            break;
        }
        if(l==10){
        cout<<"value not found"<<endl;
        }
        l++;
    }
}
 
void search(int n, int arr[]){
    int val=n%10;
 
    int l=0;
    while(l<10){
        if(arr[(val+l)%10]==n){
            cout<<"value found at location: "<<(val+l)%10<<endl;
            break;
        }else if(arr[(val+l)%10]== -1){
            cout<<"value is not present in table"<<endl;
            break;
        }
        l++;
        if(l==10){
            cout<<"value is not present in table"<<endl;
            break;
        }
    }
 
 
 
}
 
 
int main(){
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = -1;
    }
 
    double num=0;
    int menu;
 
    while(menu!=6){
        cout<<"Enter your choice"<<endl;
        cout<<"1->Insert"<<endl;
        cout<<"2->Display"<<endl;
        cout<<"3->Deletion"<<endl;
        cout<<"4->Search"<<endl;
        cout<<"5->Exit"<<endl;
        cin>>menu;
        if(menu==1){
            int n;
            cout<<"Enter value you want to enter: ";
            cin>>n;
            insertion(n,arr);
        }
        else if(menu==2){
            cout<<"Displaying the Hash table"<<endl;
            display(arr);
        }
        else if(menu==3){
            int v;
            cout<<"Enter value you want to delete: ";
            cin>>v;
            deletion(v,arr);
        }
        else if(menu==4){
            int v;
            cout<<"Enter value you want to search: ";
            cin>>v;
            search(v,arr);
        }
        else if(menu==5){cout<<"Sucessfully exitied from program!!";
        break;}
        else{cout<<"Enter valid option: ";}
    }
}
