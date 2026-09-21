#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

enum class TipoNo {
    PALAVRA_FICTICIA,
    SIGNIFICADO
};

struct Coordenada {
    int x;
    int y;
    int z;

    Coordenada();
    Coordenada(int x, int y, int z);
};

struct No {
    std::string id;
    std::string termo;
    TipoNo tipo;
    int x;
    int y;
    int z;

    No();
    No(const std::string& id, const std::string& termo, TipoNo tipo, int x = -1, int y = -1, int z = -1);
};

std::string idPalavra(const std::string& termo);
std::string idSignificado(const std::string& termo);
std::string trim(const std::string& texto);

#endif
