#include <iostream>
#include "modulo_implementacao.h"

using namespace std;

int main()
{

    PilhaEstatica<int, 10> pilha;

    criar(pilha);
    cout << "Pilha criada!" << endl;

    if (ehVazia(pilha)) {
        cout << "A pilha esta vazia." << endl;
    } else {
        cout << "A pilha nao esta vazia." << endl;
    }

    if (temEspaco(pilha)) {
        cout << "A pilha tem espaco disponivel." << endl;
    } else {
        cout << "A pilha esta cheia." << endl;
    }

    cout << "Inserindo dados..." << endl;
    empilhar(pilha, 100);
    empilhar(pilha, 300);
    empilhar(pilha, 200);
    empilhar(pilha, 800);
    empilhar(pilha, 700);
    empilhar(pilha, 900);

    if (ehVazia(pilha)) {
        cout << "A pilha esta vazia." << endl;
    } else {
        cout << "A pilha nao esta vazia." << endl;
    }

    cout << "Elementos na pilha: ";
    mostrar(pilha);
    cout << endl;

    int elementoProcurado = 2;
    if (existeElemento(pilha, elementoProcurado)) {
        cout << elementoProcurado << " esta na pilha." << endl;
    } else {
        cout << elementoProcurado << " nao esta na pilha." << endl;
    }

    int pos = 2;
    if (existePosicao(pilha, pos)) {
        int elemento = umElemento(pilha, pos);
        cout << "Elemento na posicao " << pos << ": " << elemento << endl;
    }

    int elementoParaEncontrar = 3;
    if (existeElemento(pilha, elementoParaEncontrar)) {
        int posicaoElemento = posicao(pilha, elementoParaEncontrar);
        cout << "Posicao de " << elementoParaEncontrar << " na pilha: " << posicaoElemento << endl;
    }

    int elementoTopo = topo(pilha);
    cout << "Topo da pilha: " << elementoTopo << endl;

    cout << "Desempilhando um elemento... " << endl;
    retirar(pilha);

    cout << "Elementos na pilha: ";
    mostrar(pilha);
    cout << endl;

    return 0;
}
