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
                break;
            case PESQUISAREMOVE:
                break;
            case IMPRIME:
                break;
            default:
                cout << " Opção inválida!\n";
                Sleep(1000);
        }
    }

    return 0;
}
