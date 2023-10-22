#ifndef MODULO_IMPLEMENTACAO_H_INCLUDED
#define MODULO_IMPLEMENTACAO_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct PilhaEstatica{
    int cardinalidade = 0;
    T elementos[MAX];
};

//criar uma pilha
template<typename T, int MAX>
void criar(PilhaEstatica<T,MAX> &pilha){
    pilha.cardinalidade = 0;
}

//verificar se uma pilha esta vazia
template<typename T, int MAX>
bool ehVazia(PilhaEstatica<T,MAX> pilha){
    return pilha.cardinalidade == 0;
}

//verificar se h� espa�o na pilha
template<typename T, int MAX>
bool temEspaco(PilhaEstatica<T,MAX> pilha){
    return pilha.cardinalidade != MAX;
}

//recuperar o numero de elementos da pilha
template<typename T, int MAX>
int numeroElementos(PilhaEstatica<T,MAX> pilha){
    return pilha.cardinalidade;
}

//verificar se um determinado elemento esta na pilha
template<typename T, int MAX>
bool existeElemento(PilhaEstatica<T,MAX> pilha, T elemento){
    for(int i = 0; i < pilha.cardinalidade; i++){
        if(pilha.elementos[i] == elemento){
            return true;
        }
    }
    return false;
}

//verificar se uma posicao qualquer e valida
template<typename T, int MAX>
bool existePosicao(PilhaEstatica<T,MAX> pilha, int posicao){
    return posicao > 0 && posicao <= pilha.cardinalidade;
}

//recuperar um elemento da pilha
template<typename T, int MAX>
T umElemento(PilhaEstatica<T,MAX> pilha, int posicao){
    if(!existePosicao(pilha, posicao)){
        throw "POSICAO INVALIDA!";
    }
    return pilha.elementos[posicao-1];
}

//recuperar a posi��o de um elemento da pilha
template<typename T, int MAX>
int posicao(PilhaEstatica<T,MAX> pilha, T elemento){
    if(!existeElemento(pilha, elemento)){
        throw "ELEMENTO NAO ESTA NA LISTA!";
    }
    for(int i = 0; i < pilha.cardinalidade; i++){
        if(pilha.elementos[i] == elemento){
            return (i + 1);
        }
    }
}

//recuperar o topo da pilha
template<typename T, int MAX>
T topo(PilhaEstatica<T,MAX> pilha){
    if(ehVazia(pilha)){
        throw "PILHA VAZIA!";
    }
    return pilha.elementos[0];
}

//inserir (empilhar) um elemento
template<typename T, int MAX>
void empilhar(PilhaEstatica<T,MAX> &pilha, T elemento){
    if(pilha.cardinalidade == MAX){
        throw "PILHA CHEIA!";
    }
    for(int i = pilha.cardinalidade; i > 0; i--){
        pilha.elementos[i] = pilha.elementos[i - 1];
    }
    pilha.elementos[0] = elemento;
    pilha.cardinalidade++;
}

//retirar (desempilhar) um elemento
template<typename T, int MAX>
void retirar(PilhaEstatica<T,MAX> &pilha){
    if(ehVazia(pilha)){
        throw "UNDERFLOW";
    }
    for(int i = 0; i < pilha.cardinalidade - 1; i++){
        pilha.elementos[i] = pilha.elementos[i+1];
    }
    pilha.cardinalidade--;
}

//exibir os elementos da pilha
template<typename T, int MAX>
void mostrar(PilhaEstatica<T,MAX> pilha){
    for(int i = 0; i < pilha.cardinalidade; i++){
        cout << pilha.elementos[i] << " ";
    }
}

#endif // MODULO_IMPLEMENTACAO_H_INCLUDED
