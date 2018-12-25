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
opcoes menu();
// --------------------------------

// Funções ------------------------

opcoes menu ()
{
    int o;
    clrscr();
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
    lista.ultimo->anterior = NULL;
}



#endif // LISTA_DUPENCAD_H_INCLUDED
