#include <iostream>

using namespace std;

int prog1(int n){
    if(n<=1){
        return 2;
    }else{
        int cont=0;
        for(int i = 0; i < (n + 2); i++){
            cont++;
        }
        return cont + prog1(n-1);
    }
}

int prog2(int n){
    if(n<=1){
        return 5;
    }else{
        int cont=0;
        for(int i = 0; i < (n + 2); i++){
            cont++;
        }
        return cont + prog2(n-1);
    }
}

int main(){
    int n = 0;
    cin >> n;
    cout << prog1(n) << endl;
    cout << prog2(n) << endl;
    return 0;
}