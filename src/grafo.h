#ifndef GRAFO_H
#define GRAFO_H

#include "palavra.h"
#include "abb.h"

#include <list>
#include <string>

#define MAX_NOS 200

struct Aresta {
    int origem;
    int destino;
};

class Grafo {
public:
    Grafo();

    bool cadastrarPalavra(const std::string& palavra, const std::string& significado, int x, int y, int z);
    Coordenada gerarCoordenadas(const std::string& palavra, const std::string& significado) const;
    bool palavraExiste(const std::string& palavra) const;
    std::list<std::string> buscarSignificados(const std::string& palavra) const;
    std::list<std::string> buscarSinonimos(const std::string& palavra) const;
    std::list<std::string> listarPalavrasOrdenadas() const;

private:
    No nos[MAX_NOS];
    int quantidadeNos;
    std::list<Aresta> adj[MAX_NOS];
    ABB abb;

    int buscarIndicePorId(const std::string& id) const;
    int buscarIndicePalavra(const std::string& palavra) const;
    int adicionarNo(const No& no);
    void adicionarAresta(int origem, int destino);
    bool arestaExiste(int origem, int destino) const;
    bool contemTermo(const std::list<std::string>& lista, const std::string& termo) const;
    int limitarCoordenada(int valor) const;
    unsigned int hashTexto(const std::string& texto) const;
};

#endif
