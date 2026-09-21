#include "palavra.h"

#include <cctype>

Coordenada::Coordenada() : x(0), y(0), z(0) {}

Coordenada::Coordenada(int x, int y, int z) : x(x), y(y), z(z) {}

No::No() : tipo(TipoNo::SIGNIFICADO), x(-1), y(-1), z(-1) {}

No::No(const std::string& id, const std::string& termo, TipoNo tipo, int x, int y, int z)
    : id(id), termo(termo), tipo(tipo), x(x), y(y), z(z) {}

std::string idPalavra(const std::string& termo) {
    return "P:" + termo;
}

std::string idSignificado(const std::string& termo) {
    return "S:" + termo;
}

std::string trim(const std::string& texto) {
    size_t inicio = 0;
    while (inicio < texto.size() && std::isspace(static_cast<unsigned char>(texto[inicio]))) {
        ++inicio;
    }

    if (inicio == texto.size()) {
        return "";
    }

    size_t fim = texto.size() - 1;
    while (fim > inicio && std::isspace(static_cast<unsigned char>(texto[fim]))) {
        --fim;
    }

    return texto.substr(inicio, fim - inicio + 1);
}
