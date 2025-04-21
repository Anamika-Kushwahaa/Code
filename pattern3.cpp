#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=0 ; i<5 ; i++){
        for(int j=i ; j<n ; j++){
            cout<<"* ";

        }
        cout<< endl;
    }
    return 0;
}
/*
* * * * * 
* * * * 
* * * 
* * 
* 
*/