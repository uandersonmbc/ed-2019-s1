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

bool check_move(char move_game, char * mat, bool player){
    for(int i = 0; i < 9; i++){
        if(mat[i] == move_game){
            if(player)
                mat[i] = 'X';
            else
                mat[i] = 'O';
            return true;
        }
    }
    return false;
}

int winner(char value){
    if(value == 'X')
        return 1;
    return 2;
}

int check_out_winner(char mat[3][3]){
    char *p = &mat[0][0];
    if(p[0] == p[4] && p[4] == p[8]){
        return winner(p[0]);
    }

    if(p[2] == p[4] && p[4] == p[6]){
        return winner(p[0]);
    }

    for(int i = 0; i < 3; i++){
        if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]){
            return winner(mat[i][0]);
        }
    }
    for(int i = 0; i < 3; i++){
        if(mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]){
            return winner(mat[0][i]);
        }
    }
    return 0;
}

int main(){
    char mat[3][3];
    char *p = &mat[0][0];
    string play1, play2;
    char move_game;
    bool player = true;
    for(int i = 0; i < 9; i++){
        p[i] = i+'0';
    }
    show(mat);
    cout << "player 1: ";
    getline(cin, play1);
    cout << "player 2: ";
    getline(cin, play2);
    cout << "Començando o jogo" << endl;
    while(true){
        if(player)
            cout << play1 << ": ";
        else
            cout << play2 << ": ";
        cin >> move_game;
        int move = check_move(move_game, &mat[0][0], player);
        if(move){
            if(player)
                player = false;
            else
                player = true;
        }
        show(mat);
        int winner = check_out_winner(mat);
        if(winner){
            if(winner)
                cout << "Vencedor: " << play1 << endl;
            else
                cout << "Vencedor: " << play2 << endl;
           break; 
        }
    }
}