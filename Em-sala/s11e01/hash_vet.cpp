#include <vector>
#include <iostream>
using namespace std;
enum State {Empty = 0, Filled = 1, Removed = 2};

struct Item{
    int key;
    State state;
    Item(int key = -1, State state = Empty){
        this->key = key;
        this->state = state;
    }
    string toString(){
        string text = "EFR";
        return to_string(key) + ":" + 
            string(1, text[static_cast<int>(this->state)]);
    }
};

struct Hash{
    vector<Item> vet;
    Hash(int size):
        vet(size, Item()){
    }

    int find(int value){
        int hash = value % vet.size();
        while (vet[hash].state != Empty || 
            (vet[hash].state == Filled && vet[hash].key != value)){
                hash = (hash + 1) % vet.size();
        }
        if(vet[hash].state == Empty){
            vet[hash] = Item(value, Filled);
            return true;
        }
        return false;
    }

    bool insert(int value){
        
    }

    void show(){
        for(int i = 0; i < (int) vet.size(); i++){
            cout << "[" << i << ":" << vet[i].toString() << "]";
        }
        cout << "\n";
    }
};

#include <sstream>
int main(){
    Hash ht(10);
    string cmd;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "add"){
            int value;
            while(ss >> value)
                ht.insert(value);
        }else if(cmd == "show"){
            ht.show();
        }else{
            cout << "fail: comando invalido\n";
        }
        
    }
}