#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

const char PAREDE = 219;// █
const char CAMINHO = 248;// °
const char INICIO = 79;// O
const char CHEGADA = 88;// X

typedef struct _Pos{
    int l;
    int c;
} Pos;

#define get_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}//

void shuffle(Pos vet[], int size){
    //Sorteia aleatoriamente o vetor
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}

bool equals(int nl, int nc, char mat[nl][nc], int l, int c, char value){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))//Verifica se o elemento está fora da matriz
        return false;
    return mat[l][c] == value;//Retorna true ou false dizendo se é furavel
}

bool eh_furavel(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!equals(nl, nc, mat, l, c, PAREDE))
        return false;
    int cont = 0;
    Pos neibs[] = get_neibs(l, c);
    for(int i = 0; i < 4; i++)
        if(equals(nl, nc, mat, neibs[i].l, neibs[i].c, PAREDE))
            cont++;
    if(cont < 3)
        return false;
    return true;
}

void furar(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!eh_furavel(nl, nc, mat, l, c))
        return;
    mat[l][c] = ' ';
    Pos neibs[] = get_neibs(l, c);
    shuffle(neibs, 4);
    for(int i = 0; i < 4; i++)
        furar(nl, nc, mat, neibs[i].l, neibs[i].c);    
}

void show(int nl, int nc, char mat[nl][nc]){
    //loop encadeado para pegar linha e coluna de uma matriz
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            printf("%c", mat[l][c]);//imprime a posição da matriz
        }
        puts("");//Quebra a linha para imprimir a próxima
    }
}

bool procurar_saida(int nl,int nc,char mat[nl][nc],bool mvis[nl][nc],int l,int c,int lf,int cf){
    if(mat[l][c] == PAREDE)
        return false;//Se não for espaço ele retorna para procurar nas redondezas 

    if(mvis[l][c])
        return false;//Se já estiver sido visitado retorna para procurar nas redondezas 

    mvis[l][c] = true;//Marca como visitado
    mat[l][c] = CAMINHO;//Marca o caminha que esta sendo feito
    
    if(l == lf && c == cf)
        return true;//retorn dizendo que ele é saida
        
    Pos neibs[] = get_neibs(l, c);//preenhe o verto com os valores de l e c soma ou subtraído 1 e -1
    shuffle(neibs, 4);//Bagunça o vetoe
    bool retorno = false;//iniciando a variavel com false
    bool retornoaux = false;
    for(int i = 0; i < 4; i++){//fazendo a bucas dos vizinhos
        retorno = procurar_saida(nl, nc, mat, mvis, neibs[i].l, neibs[i].c, lf, cf);//consulta visinho para saber se ele é caminho
        if(true == retorno){
            retornoaux = retorno;
            break;
        }
    }

    if(retornoaux){
        return true;//retorno true se ele for visinho
    }else{
        mat[l][c] = ' ';//desmarca caminho feito
        return false;//retorno false se ele não for visinho
    }
}

int main(int argc, char * argv[]){
    srand(time(NULL));//fazendo com que rand fique aleatório
    int nl = 10;//total de linhas
    int nc = 30;//total de colunas

    if(argc > 2){
        nl = atoi(argv[1]);//definida pelos argumentos 
        nc = atoi(argv[2]);//definida pelos argumentos
    }

    char mat[nl][nc];//criando a matriz do labirinto
    bool mvis[nl][nc];//crindo a matriz de visitados
    char * m = &mat[0][0];//pegando o primeiro endereço da matriz do labirinto
    bool * v = &mvis[0][0];//pegando o primeiro endereço da matriz de visitados
    for(int i = 0; i < nl * nc; i++){
        //preenchendo as matriz com os valores inicias
        m[i] = PAREDE;
        v[i] = false;
    }
    
    furar(nl, nc, mat, 1, 1);//criando o labirinto
    
    printf("%d %d\n", nl, nc);//printando o total de linhas e colunas
    
    show(nl, nc, mat);//mostrando o labirinto
    
    int li = 0;//linha de inicio
    int lf = 0;//linha final
    int ci = 0;//coluna inicio
    int cf = 0;//coluna final
    scanf("%d %d",&li, &ci);//entra de valores (linha coluna)
    scanf("%d%d",&lf, &cf);//entra de valores (linha coluna)

    procurar_saida(nl, nc, mat, mvis, li, ci, lf, cf);//Procurando a chegada

    mat[li][ci] = INICIO;//marca ponto de inicio
    mat[lf][cf] = CHEGADA;//marca ponto de chegada

    show(nl, nc, mat);//mostrando o labirinto
}