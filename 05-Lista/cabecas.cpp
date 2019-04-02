#include <iostream>

using namespace std;

struct No
{
    int value;
    No * next;
    No * prev;
};


struct Cabeca
{
    No * _initial;
    No * _final;

    void show(){
        cout << "[ ";
        No * no = _initial->next;
        while(no != _final){
            cout << no->value << " ";
            no = no->next;
        }
        cout << "]\n";
    }

    void insert(int value){
        if(this->_initial == nullptr){
            No * node = new No();
            node->value = value;
            node->prev = node;
            node->next = node;
            this->_initial = node;
            this->_final = node;
        }
        else{
            No * node = new No();
            node->value = value;
            node->prev = this->_final;
            node->next = this->_initial;
            this->_final->next = node;
            this->_final = node;
            this->_initial->prev = this->_final;
        }
    }

    void remove(No * ref){
        ref->prev->next = ref->next;
        ref->next->prev = ref->prev;
        delete ref;
    }

    void push_back(int value){
        insert(_final, value);
    }

    No * search(int ini){
        No * no = _initial->next;
        int i = 1;
        while(no != _final){
            if(i == ini)
                return no;
            no = no->next;
            i++;
        }
        return no;
    }
};


int main(){
    int tam = 0;
    int ini = 0;
    int fase = 1;
    
    Cabeca cabeca;
    
    cin >> tam;
    cin >> ini;
    cin >> fase;

    for(int i = 0; i < tam; i++){
        cabeca.push_back((i + 1) * fase);
        fase *= -1;
    }

    No * found = cabeca.search(ini);
    for(int i = 0; i < tam-1; i++){
        int direcao = found->value > 0 ? 1 : -1;
        int andar = found->value > 0 ? found->value : -found->value;
        cabeca.remove(found->next);
        for(int j = 0; j < andar; j++){
            if(direcao == 1)
                found = found->next;
            else
                found = found->prev;
        }

        cabeca.show();
    }
    return 0;
}
// g++ .\cabecas.cpp -o cabecas