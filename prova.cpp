/** 

1. Explique como funciona a inserção, busca e remoção numa tabela hash com marcação. (texto)

2. Clone uma lista ligada simples. (pseudocódigo)

3. Dados dois nós de uma ávore, encontre o primeiro ancestral comum. (pseudocódigo)

4. Dado uma matriz de elementos, encontre a maior partição. (interativo com fila)


1) ------------------------------------------------------------------------------

Tamanho da tabela 6
regra -> (valor do número % tambanho da tabela)

[0] - 96
[1] - 79
[2] - 38
[3] - 39
[4] - 40
[5] - 41

- Inserção
Tendo o tamanho de sua tabela o valor a ser inserido vai ser no campo onde
(regra) é igual.

(96 % 6) = 0
(79 % 6) = 1
(38 % 6) = 2
(39 % 6) = 3
(40 % 6) = 4
(41 % 6) = 5

Caso a posição que você for inserir já estiver ocupada,
você add o próximo a frente que estiver vazio.

- Busca
Tem o valor a ser buscado, você faz a (regra) e verifica 
se o valor que estar na posição é o mesmo que eu quero busca, caso contrário
vai para o próximo à frente e verifica até voltar ao ponto de partida onde iniciei
minha busca.

- Remoção
Tem o valor a ser removido, você faz a (regra), encontrando 
a posição do número na minha tabela tenho que verificar se o número que estar lá
é o mesmo que quero remover, caso o contrário vou para o próximo para verifica se é
o mesmo valor até voltar ao ponto de partida onde iniciei minha busca.


2) ------------------------------------------------------------------------------


3) ------------------------------------------------------------------------------
            1
           / \
          2   3
         /     \
        4       7
       / \     / \
      5   6   8   9

de 5 e 6 é o 4
de 8 e 9 é o 7
de 9 e 5 é o 1

Node * find_ancester(int value_a, int value_b){

}

*/

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

struct LC{
    int l, c;
};

vector<LC> find_greater_partition(vector<string> & mat){
    queue<LC> fila;
    return vector<LC>();
}

/*

>>>>>>>>
2 8
aaaaaaaa
aaaaaabb
========
********
******bb
<<<<<<<<

*/
int main(){
    int nl, nc;
    string line;
    getline(cin, line);
    stringstream(line) >> nl >> nc;
    vector<string> mat(nl, "");
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);
    auto partition = find_greater_partition(mat);
    for(auto lc : partition)
        mat[lc.l][lc.c] = '*';
    for(int l = 0; l < mat.size(); l++)
        cout << mat[l] << "\n";
}