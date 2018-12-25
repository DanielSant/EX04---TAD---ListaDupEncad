#ifndef LISTA_DUPENCAD_H_INCLUDED
#define LISTA_DUPENCAD_H_INCLUDED

typedef struct nodoLista *apontador;

typedef struct {
    int chave;
    /*outros componentes*/
} TInfo;

struct nodoLista
{
    TInfo item;
    struct nodoLista *anterior;
    struct nodoLista *proximo;
};

typedef struct {
    struct nodoLista *primeiro;
    struct nodoLista *ultimo;
} TLista;

#endif // LISTA_DUPENCAD_H_INCLUDED
