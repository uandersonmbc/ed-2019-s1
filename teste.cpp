#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

void show(char mat[3][3]){
    for(int l = 0; l < 3; l++){
        cout << " " << mat[l][0] << " | " << mat[l][1] << " | " << mat[l][2] << endl;
        if(l != 2)
            cout << string(11, '-') << endl;
    }
}

bool check_move(char jogada, char * mat){
    for(int i = 0; i < 9; i++){
        if(mat[i] == jogada){
            mat[i] = 'X';
            return true;
        }
    }
    return false;
}

int main(){
    char mat[3][3];
    char *p = &mat[0][0];
    string jog1, jog2;
    char jogada;
    for(int i = 0; i < 9; i++){
        p[i] = i+'0';
    }
    show(mat);
    getline(cin, jog1);
    getline(cin, jog2);
    while(true){
        cin >> jogada;
        check_move(jogada, &mat[0][0]);
        show(mat);
    }
}