#ifndef LISTA_DUPENCAD_H_INCLUDED
#define LISTA_DUPENCAD_H_INCLUDED

// Bibliotecas ---------------------

#include <iostream>
using namespace std;
#include <ctype.h>
#include <conio2.h>
#include <stdlib.h>
#include <stdio.h>
// ---------------------------------

// Definições e structs ------------

typedef struct nodoLista *apontador;

typedef struct
{
    int chave;
    /*outros componentes*/
} TInfo;

struct nodoLista
{
    TInfo item;
    struct nodoLista *anterior;
    struct nodoLista *proximo;
};

typedef struct
{
    struct nodoLista *primeiro;
    struct nodoLista *ultimo;
} TLista;
// --------------------------------
enum opcoes
{
    INSEREINICIO, INSEREPOSICAO, INSEREFINAL, REMOVEINICIO,
    REMOVEFINAL, PESQUISAREMOVE, IMPRIME, FINALIZAR
};
// Protótipos ---------------------

void cria (TLista& lista);
void insereInicio (TLista& lista, TInfo item);
void inserePosicao (TLista& lista, int p, TInfo item);
void insereFinal (TLista& lista, TInfo item);
void removeInicio (TLista& lista);
void removeFinal (TLista& lista);
void pesquisaRemove (TLista& lista, TInfo item);
void imprime (TLista& lista);
opcoes menu (TLista& lista);
void setDados (TInfo& item);
bool vazia (TLista& lista);
void imprimeContrario(TLista& lista);
// --------------------------------

// Funções ------------------------

opcoes menu (TLista& lista)
{
    int o;
    clrscr();
    imprime(lista);
    imprimeContrario(lista);
    cout << "\n Menu: " << endl
         << " 1 - Insere no Início\n"
         << " 2 - Insere na Posição\n"
         << " 3 - Insere no Final\n"
         << " 4 - Remove do Início\n"
         << " 5 - Remove do Final\n"
         << " 6 - Pesquisa e Remove\n"
         << " 7 - Imprime\n"
         << " 8 - Fim do Programa\n"
         << " Opção: ";
    scanf("%d", &o);
    fflush(stdin);
    o-=1;

    return (opcoes) o;
}

void cria(TLista& lista)
{
    lista.primeiro = (apontador) malloc(sizeof(struct nodoLista));
    lista.ultimo = lista.primeiro;
    lista.primeiro->proximo = NULL;
    lista.primeiro->anterior = NULL;
}

void setDados(TInfo& item)
{
    cout << "\n Informe o código: ";
    cin >> item.chave;
}

void insereInicio(TLista& lista, TInfo item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoLista));
    apontador aux;
    p->item = item;
    p->anterior = NULL;
    p->proximo = lista.primeiro->proximo; // Primeiro nodoLista
    aux->proximo = lista.primeiro->proximo;
    lista.primeiro->proximo = p;

    if (p->proximo == NULL)
        lista.ultimo = p;
    else
        aux->proximo->anterior = p;

    free(aux);
}

void removeInicio(TLista& lista)
{
    if(vazia(lista))
    {
        cout << "\n ERRO: A lista está vazia.\n";
        getch();
    }
    else
    {
        apontador p = lista.primeiro->proximo;
        cout << "\n Elemento removido = " << p->item.chave << endl;
        Sleep(800);
        lista.primeiro->proximo = p->proximo;
        if(lista.primeiro->proximo == NULL)
            lista.ultimo = lista.primeiro;
        else
            p->proximo->anterior = NULL;

        free(p);
    }
}

void insereFinal(TLista& lista, TInfo item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoLista));
    p->item = item;
    p->proximo = NULL;

    if(vazia(lista))
        p->anterior = lista.ultimo->proximo;
    else
        p->anterior = lista.ultimo;

    lista.ultimo->proximo = p;
    lista.ultimo = p;
}

void removeFinal(TLista& lista)
{
    if(vazia(lista))
    {
        cout << "\n ERRO: A lista está vazia! " << endl;
        getch();
    }
    else
    {
        apontador p = lista.primeiro->proximo; // Pega o endereço do 1º nó
        if(p->proximo == NULL) // Aqui já testa se há mais de 1 nodoLista
        {
            //lista.primeiro->proximo = NULL;
            //lista.ultimo = lista.primeiro;
            removeInicio(lista);
        }
        else
        {
            cout << "\n Elemento removido = " << lista.ultimo->item.chave << endl;
            Sleep(800);
            lista.ultimo = lista.ultimo->anterior;
            lista.ultimo->proximo = NULL;
        }
        free(p);
    }
}

bool vazia(TLista& lista)
{
    if(lista.primeiro->proximo == NULL)
        return true;
    else
        return false;
}

void imprime(TLista& lista)
{
    cout << " Itens na LISTA:\n";
    if(vazia(lista))
        cout << " A lista está vazia!\n";
    else
    {
        apontador aux = lista.primeiro->proximo;
        while(aux != NULL)
        {
            cout << " " << aux->item.chave;
            aux = aux->proximo;
        }
        cout << endl;
    }
}

void imprimeContrario(TLista& lista)
{
    cout << "\n Itens na LISTA INVERTIDA:\n";
    if(vazia(lista))
        cout << " A lista está vazia!\n";
    else
    {
        apontador aux = lista.ultimo;
        while(aux != NULL)
        {
            cout << " " << aux->item.chave;
            aux = aux->anterior;
        }
        cout << endl;
    }
}

#endif // LISTA_DUPENCAD_H_INCLUDED
