#include <locale.h>
#include <windows.h>
#include "Lista_DupEncad.h"

int main()
{
    setlocale(LC_ALL, "portuguese");
    opcoes opc;
    TLista lista;
    //TInfo item;

    cria(lista);

    while ((opc = menu()) != FINALIZAR)
    {
        switch (opc)
        {
            case INSEREINICIO:
                //insereInicio(lista, item);
                cout << " Funfa";
                getch();
                break;
            case INSEREPOSICAO:
                break;
            case INSEREFINAL:
                break;
            case REMOVEINICIO:
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
