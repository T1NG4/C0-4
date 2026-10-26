#include "menu.h"

#include "grafo.h"
#include "palavra.h"

#include <iostream>
#include <limits>
#include <list>
#include <string>

namespace {
std::string lerLinha(const std::string& mensagem) {
    std::string entrada;
    std::cout << mensagem;
    std::getline(std::cin, entrada);
    return trim(entrada);
}

}  // namespace

void funcionalidadeEmConstrucao() {
    std::cout << "Funcionalidade em construção\n";
}

void exibirMenu() {
    std::cout << "\n=== Dicionário de Língua Fictícia ===\n";
    std::cout << "a) Cadastrar palavra\n";
    std::cout << "b) Listar significados de uma palavra\n";
    std::cout << "c) Listar sinônimos de uma palavra\n";
    std::cout << "d) Listar palavras em ordem alfabética\n";
    std::cout << "e) Listar palavras por ordem de tamanho\n";
    std::cout << "f) Remover palavra\n";
    std::cout << "g) Calcular similaridade entre duas palavras\n";
    std::cout << "0) Sair\n";
    std::cout << "Escolha uma opção: ";
}

void cadastrarPalavra(Grafo& grafo) {
    const std::string palavra = lerLinha("Digite a palavra fictícia: ");
    if (palavra.empty()) {
        std::cout << "Palavra inválida.\n";
        return;
    }

    if (grafo.palavraExiste(palavra)) {
        std::cout << "Palavra já cadastrada.\n";
        return;
    }

    const std::string significado = lerLinha("Digite o significado em português: ");
    if (significado.empty()) {
        std::cout << "Significado inválido.\n";
        return;
    }

    const Coordenada coordenada = grafo.gerarCoordenadas(palavra, significado);
    std::cout << "Coordenadas geradas automaticamente: ("
              << coordenada.x << ", " << coordenada.y << ", " << coordenada.z << ")\n";

    if (grafo.cadastrarPalavra(palavra, significado, coordenada.x, coordenada.y, coordenada.z)) {
        std::cout << "Palavra cadastrada com sucesso.\n";
    } else {
        std::cout << "Não foi possível cadastrar a palavra.\n";
    }
}

void listarSignificados(Grafo& grafo) {
    const std::string palavra = lerLinha("Digite a palavra fictícia: ");
    if (palavra.empty()) {
        std::cout << "Palavra inválida.\n";
        return;
    }

    const std::list<std::string> significados = grafo.buscarSignificados(palavra);
    if (significados.empty()) {
        if (!grafo.palavraExiste(palavra)) {
            std::cout << "Palavra não encontrada.\n";
        } else {
            std::cout << "Nenhum significado encontrado.\n";
        }
        return;
    }

    std::cout << "Significados de \"" << palavra << "\":\n";
    std::list<std::string>::const_iterator it;
    for (it = significados.begin(); it != significados.end(); ++it) {
        std::cout << "- " << *it << '\n';
    }
}

void listarSinonimos(Grafo& grafo) {
    const std::string palavra = lerLinha("Digite a palavra fictícia: ");
    if (palavra.empty()) {
        std::cout << "Palavra inválida.\n";
        return;
    }

    if (!grafo.palavraExiste(palavra)) {
        std::cout << "Palavra não encontrada.\n";
        return;
    }

    const std::list<std::string> sinonimos = grafo.buscarSinonimos(palavra);
    if (sinonimos.empty()) {
        std::cout << "Nenhum sinônimo encontrado.\n";
        return;
    }

    std::cout << "Sinônimos de \"" << palavra << "\":\n";
    std::list<std::string>::const_iterator it;
    for (it = sinonimos.begin(); it != sinonimos.end(); ++it) {
        std::cout << "- " << *it << '\n';
    }
}

void listarOrdemAlfabetica(Grafo& grafo) {
    const std::list<std::string> palavras = grafo.listarPalavrasOrdenadas();
    if (palavras.empty()) {
        std::cout << "Nenhuma palavra cadastrada.\n";
        return;
    }

    std::cout << "Palavras em ordem alfabética:\n";
    std::list<std::string>::const_iterator it;
    for (it = palavras.begin(); it != palavras.end(); ++it) {
        std::cout << "- " << *it << '\n';
    }
}

void listarOrdemTamanho(Grafo& grafo) {
    (void)grafo;
    funcionalidadeEmConstrucao();
}

void removerPalavra(Grafo& grafo) {
    (void)grafo;
    funcionalidadeEmConstrucao();
}

void calcularSimilaridade(Grafo& grafo) {
    (void)grafo;
    funcionalidadeEmConstrucao();
}

void executarMenu(Grafo& grafo) {
    bool executando = true;

    while (executando) {
        exibirMenu();

        std::string opcao;
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcao == "a") {
            cadastrarPalavra(grafo);
        } else if (opcao == "b") {
            listarSignificados(grafo);
        } else if (opcao == "c") {
            listarSinonimos(grafo);
        } else if (opcao == "d") {
            listarOrdemAlfabetica(grafo);
        } else if (opcao == "e") {
            listarOrdemTamanho(grafo);
        } else if (opcao == "f") {
            removerPalavra(grafo);
        } else if (opcao == "g") {
            calcularSimilaridade(grafo);
        } else if (opcao == "0") {
            executando = false;
            std::cout << "Encerrando o programa.\n";
        } else {
            std::cout << "Opção inválida.\n";
        }
    }
}
