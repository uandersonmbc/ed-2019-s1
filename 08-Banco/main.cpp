#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <sstream>

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

/**
 * [][][]
 * in :{ Ai:4:6 Bo:2:3 Ce:3:8 Di:3:5 Em:3:2 }
 * out:{ }
*/
void show(Bank bank){
    cout << "in : { ";
    for (int i = 0; i < bank.caixas.size(); i++){
        cout << bank.caixas[i]->id << ":" << bank.caixas[i]->docs << ":" << bank.caixas[i]->pac << " ";
    }
    cout << "}" << endl;
}

int main(){
    int cashier = 0;
    Bank bank;
    Client * client;

    while(true){
        string line, cmd;
        getline(cin, line);
        stringstream ui(line);
        ui >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "finalizar"){

        }else if(cmd == "init"){
            ui >> cashier;
        }else if(cmd == "show"){
            show(bank);
        }else if(cmd == "tic"){
            
        }else if(cmd == "in"){
            string nome;
            int docs, pac;
            ui >> nome;
            ui >> docs;
            ui >> pac;
            client = new Client(nome, docs, pac);
            bank.caixas.push_back(client);
        }else{
            cout << "fail: comando invalido\n";
        }
    }
}