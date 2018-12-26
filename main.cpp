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
            insereInicio(lista, item);
            break;

        case INSEREPOSICAO:
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
            break;

        case IMPRIME:
            cout << endl;
            imprime(lista);
            Sleep(800);
            imprimeContrario(lista);
            Sleep(5000);
            break;

        default:
            cout << " Op��o inv�lida!\n";
            Sleep(1000);
        }
    }

    return 0;
}
