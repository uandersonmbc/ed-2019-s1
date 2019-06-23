#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

struct Pessoa {
    char nome;
    int idade;
};

int main(){
    Pessoa p;

    p.idade = 20;
    p.nome = 'a';

    cout << p.nome << p.idade << endl;
    return 0;
}