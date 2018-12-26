#include <locale.h>
#include <windows.h>
#include "Lista_DupEncad.h"

int main()
{
    setlocale(LC_ALL, "portuguese");

    opcoes opc;
    TLista lista;
    TInfo item;

    cria(lista);

    while ((opc = menu(lista)) != FINALIZAR)
    {
        switch (opc)
        {
        case INSEREINICIO:
            setDados(item);
            fflush(stdin);
            insereInicio(lista, item);
            break;

        case INSEREPOSICAO:
            int pos;
            setDados(item);
            setPosicao(pos);
            inserePosicao(lista, pos, item);
            break;

        case INSEREFINAL:
            setDados(item);
            insereFinal(lista, item);
            break;

        case REMOVEINICIO:
            removeInicio(lista);
            break;

        case REMOVEFINAL:
            removeFinal(lista);
            break;

        case PESQUISAREMOVE:
            setDados(item);
            pesquisaRemove(lista, item);
            break;

        case IMPRIME:
            cout << endl;
            imprime(lista);
            Sleep(800);
            imprimeContrario(lista);
            Sleep(5000);
            break;

        default:
            cout << " Opção inválida!\n";
            Sleep(1000);
        }
    }

    return 0;
}
