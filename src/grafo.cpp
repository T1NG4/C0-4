#include "grafo.h"

Grafo::Grafo() : quantidadeNos(0) {}

int Grafo::buscarIndicePorId(const std::string& id) const {
    for (int i = 0; i < quantidadeNos; ++i) {
        if (nos[i].id == id) {
            return i;
        }
    }
    return -1;
}

int Grafo::buscarIndicePalavra(const std::string& palavra) const {
    return buscarIndicePorId(idPalavra(palavra));
}

int Grafo::adicionarNo(const No& no) {
    const int indice = buscarIndicePorId(no.id);
    if (indice != -1) {
        return indice;
    }

    if (quantidadeNos >= MAX_NOS) {
        return -1;
    }

    nos[quantidadeNos] = no;
    return quantidadeNos++;
}

bool Grafo::arestaExiste(int origem, int destino) const {
    std::list<Aresta>::const_iterator it;
    for (it = adj[origem].begin(); it != adj[origem].end(); ++it) {
        if (it->destino == destino) {
            return true;
        }
    }
    return false;
}

void Grafo::adicionarAresta(int origem, int destino) {
    if (!arestaExiste(origem, destino)) {
        adj[origem].push_back({origem, destino});
    }
    if (!arestaExiste(destino, origem)) {
        adj[destino].push_back({destino, origem});
    }
}

bool Grafo::palavraExiste(const std::string& palavra) const {
    return buscarIndicePalavra(palavra) != -1;
}

int Grafo::limitarCoordenada(int valor) const {
    if (valor < 0) {
        return 0;
    }
    if (valor > 99) {
        return 99;
    }
    return valor;
}

unsigned int Grafo::hashTexto(const std::string& texto) const {
    unsigned int hash = 0;
    for (size_t i = 0; i < texto.size(); ++i) {
        hash = hash * 31u + static_cast<unsigned char>(texto[i]);
    }
    return hash;
}

Coordenada Grafo::gerarCoordenadas(const std::string& palavra, const std::string& significado) const {
    const int indiceSignificado = buscarIndicePorId(idSignificado(significado));

    if (indiceSignificado != -1) {
        std::list<Aresta>::const_iterator it;
        for (it = adj[indiceSignificado].begin(); it != adj[indiceSignificado].end(); ++it) {
            const int destino = it->destino;
            if (nos[destino].tipo == TipoNo::PALAVRA_FICTICIA) {
                const unsigned int variacao = hashTexto(palavra) % 5u + 1u;
                return Coordenada(
                    limitarCoordenada(nos[destino].x + static_cast<int>(variacao)),
                    limitarCoordenada(nos[destino].y + static_cast<int>(variacao)),
                    limitarCoordenada(nos[destino].z + static_cast<int>(variacao))
                );
            }
        }
    }

    const std::string chave = palavra + significado;
    const unsigned int hash = hashTexto(chave);

    return Coordenada(
        static_cast<int>(hash % 100u),
        static_cast<int>((hash / 100u) % 100u),
        static_cast<int>((hash / 10000u) % 100u)
    );
}

bool Grafo::cadastrarPalavra(const std::string& palavra, const std::string& significado, int x, int y, int z) {
    if (palavraExiste(palavra)) {
        return false;
    }

    const int indicePalavra = adicionarNo(No(idPalavra(palavra), palavra, TipoNo::PALAVRA_FICTICIA, x, y, z));
    const int indiceSignificado = adicionarNo(No(idSignificado(significado), significado, TipoNo::SIGNIFICADO));

    if (indicePalavra == -1 || indiceSignificado == -1) {
        return false;
    }

    adicionarAresta(indicePalavra, indiceSignificado);
    return true;
}

bool Grafo::contemTermo(const std::list<std::string>& lista, const std::string& termo) const {
    std::list<std::string>::const_iterator it;
    for (it = lista.begin(); it != lista.end(); ++it) {
        if (*it == termo) {
            return true;
        }
    }
    return false;
}

std::list<std::string> Grafo::buscarSignificados(const std::string& palavra) const {
    std::list<std::string> significados;
    const int indicePalavra = buscarIndicePalavra(palavra);

    if (indicePalavra == -1) {
        return significados;
    }

    std::list<Aresta>::const_iterator it;
    for (it = adj[indicePalavra].begin(); it != adj[indicePalavra].end(); ++it) {
        const int destino = it->destino;
        if (nos[destino].tipo == TipoNo::SIGNIFICADO) {
            significados.push_back(nos[destino].termo);
        }
    }

    return significados;
}

std::list<std::string> Grafo::buscarSinonimos(const std::string& palavra) const {
    std::list<std::string> sinonimos;
    const int indicePalavra = buscarIndicePalavra(palavra);

    if (indicePalavra == -1) {
        return sinonimos;
    }

    const std::list<std::string> significados = buscarSignificados(palavra);
    std::list<std::string>::const_iterator sigIt;

    for (sigIt = significados.begin(); sigIt != significados.end(); ++sigIt) {
        const int indiceSignificado = buscarIndicePorId(idSignificado(*sigIt));
        if (indiceSignificado == -1) {
            continue;
        }

        std::list<Aresta>::const_iterator it;
        for (it = adj[indiceSignificado].begin(); it != adj[indiceSignificado].end(); ++it) {
            const int destino = it->destino;
            if (nos[destino].tipo != TipoNo::PALAVRA_FICTICIA || nos[destino].termo == palavra) {
                continue;
            }

            if (!contemTermo(sinonimos, nos[destino].termo)) {
                sinonimos.push_back(nos[destino].termo);
            }
        }
    }

    return sinonimos;
}
