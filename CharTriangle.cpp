#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for (int i=0 ; i<n ; i++){
        char ch = 'A';
        for(int j=0 ; j<i+1 ; j++){
            cout<< ch << " ";
            ++ch;
        }
        cout<< endl;
    }
}
/*
A 
A B 
A B C 
A B C D 
A B C D E */