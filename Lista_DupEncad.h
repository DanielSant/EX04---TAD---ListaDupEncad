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

// Defini��es e structs ------------

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
// Prot�tipos ---------------------

void cria (TLista& lista);
void inserePosicao (TLista& lista, int pos, TInfo item);
void insereInicio (TLista& lista, TInfo item);
void insereFinal (TLista& lista, TInfo item);
void removeInicio (TLista& lista);
void removeFinal (TLista& lista);
void pesquisaRemove (TLista& lista, TInfo item);
void imprime (TLista& lista);
opcoes menu (TLista& lista);
void setDados (TInfo& item);
void setPosicao(int& pos);
bool vazia (TLista& lista);
void imprimeContrario(TLista& lista);
// --------------------------------

// Fun��es ------------------------

opcoes menu (TLista& lista)
{
    int o;
    clrscr();
    imprime(lista);
    imprimeContrario(lista);
    cout << "\n Menu: " << endl
         << " 1 - Insere no In�cio\n"
         << " 2 - Insere na Posi��o\n"
         << " 3 - Insere no Final\n"
         << " 4 - Remove do In�cio\n"
         << " 5 - Remove do Final\n"
         << " 6 - Pesquisa e Remove\n"
         << " 7 - Imprime\n"
         << " 8 - Fim do Programa\n"
         << " Op��o: ";
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
    cout << "\n Informe o c�digo: ";
    cin >> item.chave; // 20
}

void setPosicao(int& pos)
{
    cout << "\n Informe a posi��o: ";
    cin >> pos;
}

bool vazia(TLista& lista)
{
    return lista.primeiro == lista.ultimo ? true : false;
}

void insereInicio(TLista& lista, TInfo item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoLista));
    p->item = item;
    p->anterior = NULL;
    p->proximo = lista.primeiro->proximo; // Primeiro nodoLista

    if (p->proximo == NULL)
        lista.ultimo = p;
    else
        lista.primeiro->proximo->anterior = p;

    lista.primeiro->proximo = p;
}

void removeInicio(TLista& lista)
{
    if(vazia(lista))
    {
        cout << "\n ERRO: A lista est� vazia.\n";
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
            //p->proximo->anterior = NULL;
            lista.primeiro->proximo->anterior = NULL;

        free(p);
    }
}

void insereFinal(TLista& lista, TInfo item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoLista));
    p->item = item;
    p->proximo = NULL;

    if(vazia(lista))
        p->anterior = NULL;//lista.ultimo->proximo;
    else
        p->anterior = lista.ultimo;

    lista.ultimo->proximo = p;
    lista.ultimo = p;
}

void removeFinal(TLista& lista)
{
    if(vazia(lista))
    {
        cout << "\n ERRO: A lista est� vazia! " << endl;
        getch();
    }
    else
    {
        apontador p = lista.primeiro->proximo; // Pega o endere�o do 1� n�
        if(p->proximo == NULL) // Aqui j� testa se h� mais de 1 nodoLista
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
            // add um aux para otimizar;
            lista.ultimo->proximo = NULL;
        }
        free(p);
    }
}

void inserePosicao(TLista& lista, int pos, TInfo item)
{
    if(pos == 1)
    {
        fflush(stdin);
        insereInicio(lista, item);
    }
    else
    {
        apontador aux = lista.primeiro->proximo;
        int i = 1;
        while((i < pos-1) && (aux != NULL))
        {
            i++;
            aux = aux->proximo;
        }

        if((aux == NULL) || (pos  < 1))
        {
            cout << "\n Erro: Posi��o n�o existe!" << endl;
            getch();
        }
        else
        {
            apontador p = (apontador) malloc(sizeof(struct nodoLista));
            p->item = item;
            p->proximo = aux->proximo;
            p->anterior = aux;
            aux->proximo = p;

            if(p->proximo == NULL)
                lista.ultimo = p;
            else
                p->proximo->anterior = p;
        }
    }
}

void imprime(TLista& lista)
{
    cout << " Itens na LISTA:\n";
    if(vazia(lista))
        cout << " A lista est� vazia!\n";
    else
    {
        apontador aux = lista.primeiro->proximo;
        while(aux != NULL)
        {
            cout << " " << aux->item.chave;
            aux = aux->proximo;
        }
        cout << endl;
        free(aux);
    }
}

void imprimeContrario(TLista& lista)
{
    cout << "\n Itens na LISTA INVERTIDA:\n";
    if(vazia(lista))
        cout << " A lista est� vazia!\n";
    else
    {
        apontador aux = lista.ultimo;
        while(aux != NULL)
        {
            cout << " " << aux->item.chave;
            aux = aux->anterior;
        }
        cout << endl;
        free(aux);
    }
}

void pesquisaRemove(TLista& lista, TInfo item)
{
    if(vazia(lista))
    {
        cout << "\n Lista vazia, n�o h� o que pesquisar!";
        getch();
    }
    else
    {
        if(lista.primeiro->proximo->item.chave == item.chave)
            removeInicio(lista);
        else if(lista.ultimo->item.chave == item.chave)
            removeFinal(lista);
        else
        {
            apontador aux = lista.primeiro;
            while((aux->item.chave != item.chave) && (aux->proximo != NULL))
                aux = aux->proximo;

            if(aux->proximo == NULL)
            {
                cout << "\n Elemento n�o encontrado!";
                getch();
            }
            else
            {
                cout << "\n Elemento removido = " << aux->item.chave << endl;
                getch();
                if(aux->proximo == NULL)
                    lista.ultimo = aux;
                else
                {
                    aux->anterior->proximo = aux->proximo;
                    aux->proximo->anterior = aux->anterior;

                }
            }
            free(aux);
        }
    }
}

#endif // LISTA_DUPENCAD_H_INCLUDED
