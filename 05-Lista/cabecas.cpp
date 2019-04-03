#include <iostream>

using namespace std;

struct No
{
    int value;
    No * next;
    No * prev;
    No(int value){
        this->value = value;
        this->next = this;
        this->prev = this;
    }
};

void insert(No * ref, int value){
    No * no = new No(value);
    no->next = ref->next;
    no->prev = ref;
    ref->next = no;
    no->next->prev = no;
}

void remove(No * ref){
    ref->prev->next = ref->next;
    ref->next->prev = ref->prev;
}

void show(No * ref, No * espada = nullptr){
    cout << "[";
    if(ref != nullptr){
        No * aux = ref;
        do{
            if((espada != nullptr) && (aux == espada)){
                if(aux->value > 0){
                    cout << " " << aux->value;
                    printf(">");
                }else{
                    printf(" <");
                    cout << aux->value;
                }
            }else{
                cout << " " << aux->value;
            }
            aux = aux->next;
        } while (aux != ref);
        
    }
    cout << " ]\n";
}

No * search(No * ref,int ini){
    No * aux = ref;
    int i = 1;
    do{
        if(i == ini)
            return aux;
        aux = aux->next;
        i++;
    } while (aux != ref);
    return aux;
}

void show_ord(No * ref){
    No * menor = ref;
    No * aux = ref;
    do{
        int om = menor->value > 0 ? menor->value : -menor->value;
        int am = aux->value > 0 ? aux->value : -aux->value;
        if(om < am)
            menor = aux;
        aux = aux->next;
    }while(aux != ref);
    show(menor->next, ref);
}


int main(){
    int tam = 0;
    int ini = 0;
    int fase = 1;
    No * lista = nullptr;
    cin >> tam >> ini >> fase;

    for(int i = 2; i <= tam; i++){
        if (lista == nullptr) {
            lista = new No((1 * fase));
            fase *= -1;
        }
        
        insert(lista->prev,(i * fase));
        fase *= -1;
    }

    No * found = search(lista,ini);
    show(lista, found);
    
    for(int i = 0; i < tam-1; i++){
        int direcao = found->value > 0 ? 1 : -1;
        int andar = found->value > 0 ? found->value : -found->value;

        if(direcao == 1)
            remove(found->next);
        else
            remove(found->prev);
        
        for(int j = 0; j < andar; j++){
            if(direcao == 1)
                found = found->next;
            else
                found = found->prev;
        }

        show_ord(found);
    }
    return 0;
}