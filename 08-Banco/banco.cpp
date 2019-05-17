#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct Client{
    string id;
    int docs;
    int pac;
    Client(string id, int docs, int pac){
        this->id = id;
        this->docs = docs;
        this->pac = pac;
    }
};

struct Bank{
    vector<Client*> caixas;
    list<Client*> fila_entrada;
    queue<Client*> fila_saida;
};

void show(Bank bank){
    for (int i = 0; i < (int) bank.caixas.size(); i++){
        cout << "[";
        if(bank.caixas[i] != nullptr){
            cout << bank.caixas[i]->id << ":" << bank.caixas[i]->docs << ":" << bank.caixas[i]->pac << " ";
        }
        cout << "]";
    }
    if(!bank.caixas.size()){
        cout << "Caixas Fechados";
    }
    cout << endl;

    cout << "in  : { ";
    list<Client*>::iterator it;
    for (it = bank.fila_entrada.begin(); it != bank.fila_entrada.end(); ++it){
        cout << (*it)->id << ":" << (*it)->docs << ":" << (*it)->pac << " ";
    }
    cout << "}" << endl;

    cout << "out : { ";
    while (!bank.fila_saida.empty()){
        cout << bank.fila_saida.front()->id << ":" << bank.fila_saida.front()->docs << ":" << bank.fila_saida.front()->pac << " ";
        bank.fila_saida.pop();
    }

    cout << "}" << endl;
}

void open_cashier(Bank * bank, int size, Client * empty){
    int difference = (*bank).caixas.size() - size;
    if(difference > 0){
        while(difference > 0){
            (*bank).caixas.pop_back();
            difference--;
        }
    }else{
        while(difference < 0){
            (*bank).caixas.push_back(empty);
            difference++;
        }
    }
}

void tic(Bank * bank, Client * empty, int *received, int *lost){
    while (!(*bank).fila_saida.empty()){
        (*bank).fila_saida.pop();
    }
    for (int i = 0; i < (int) (*bank).caixas.size(); i++){
        if((*bank).caixas[i] != nullptr){
            if((*bank).caixas[i]->docs > 0){
                (*bank).caixas[i]->docs--;
                *received += 1;
            }else{
                (*bank).fila_saida.push((*bank).caixas[i]);
                (*bank).caixas[i] = empty;
            }
        }else{
            if((*bank).fila_entrada.size()){
                (*bank).caixas[i] = (*bank).fila_entrada.front();
                (*bank).fila_entrada.pop_front();
            }
        }
    }

    for(auto it = (*bank).fila_entrada.begin(); it != (*bank).fila_entrada.end();){
        if((*it)->pac > 0){
            (*it)->pac--;
            ++it;
        }else{
            (*bank).fila_saida.push((*it));
            *lost += (*it)->docs;
            it = (*bank).fila_entrada.erase(it);
        }
    }
}

int main(){
    int cashier = 0;
    Bank bank;
    Client * client;
    Client * empty = nullptr;
    int received = 0;
    int lost = 0;
    int tic_total = 0;
    int value_cashier = 100;
    while(true){
        string line, cmd;
        getline(cin, line);
        stringstream ui(line);
        ui >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "finalizar"){
            cout << "Total de turnos: " << tic_total << endl;
            cout << "Docs recebidos: " << received << endl;
            cout << "Docs perdidos: " << lost << endl;
            cout << "Melhor quantidade de caixa: " << (received - (cashier * value_cashier)) << endl;
        }else if(cmd == "init"){
            ui >> cashier;
            open_cashier(&bank, cashier, empty);
        }else if(cmd == "show"){
            show(bank);
            cout << endl;
        }else if(cmd == "tic"){
            tic(&bank, empty, &received, &lost);
            tic_total++;
        }else if(cmd == "in"){
            string nome;
            int docs, pac;
            ui >> nome;
            ui >> docs;
            ui >> pac;
            client = new Client(nome, docs, pac);
            bank.fila_entrada.push_back(client);
        }else if(cmd == "clear"){
            system("reset");
        }else{
            cout << "EX: show, in, end, init, tic, clear e finalizar" << endl;
        }
    }
}