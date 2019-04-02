#include <iostream>

using namespace std;

struct No
{
    int value;
    No * next;
    No * prev;
    No(int value = 0, No * next = nullptr, No * prev = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};


struct Cabeca
{
    No * head;
    No * tail;
    Cabeca(){
        head = new No();
        tail = new No();
        head->next = tail;
        tail->prev = head;
    }

    void show(){
        cout << "[ ";
        No * no = head->next;
        while(no != tail){
            cout << no->value << " ";
            no = no->next;
        }
        cout << "]\n";
    }

    void insert(No * ref, int value){
        No * no = new No(value, ref, ref->prev);
        ref->prev = no;
        no->prev->next = no;
    }

    void remove(No * ref){
        ref->prev->next = ref->next;
        ref->next->prev = ref->prev;
        delete ref;
    }

    void push_back(int value){
        insert(tail, value);
    }

    No * search(int ini){
        No * no = head->next;
        int i = 1;
        while(no != tail){
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