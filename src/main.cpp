#include "dicionario.h"
#include "grafo.h"
#include "menu.h"

#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    Grafo grafo;
    inicializarDicionario(grafo);

    std::cout << "Dicionário carregado com vocabulário High Valyrian.\n";
    executarMenu(grafo);

    return 0;
}
