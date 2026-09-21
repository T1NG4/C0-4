#ifndef MENU_H
#define MENU_H

class Grafo;

void exibirMenu();
void executarMenu(Grafo& grafo);

void cadastrarPalavra(Grafo& grafo);
void listarSignificados(Grafo& grafo);
void listarSinonimos(Grafo& grafo);
void listarOrdemAlfabetica(Grafo& grafo);
void listarOrdemTamanho(Grafo& grafo);
void removerPalavra(Grafo& grafo);
void calcularSimilaridade(Grafo& grafo);

void funcionalidadeEmConstrucao();

#endif
