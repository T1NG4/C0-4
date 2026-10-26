#include "abb.h"

#include <cctype>
#include <algorithm>

ABB::ABB() : root(NULL) {}

ABB::~ABB() {
    destruct(root);
}

std::string ABB::normalizarString(const std::string& str) const {
    std::string resultado;
    for (size_t i = 0; i < str.size(); ++i) {
        unsigned char c = str[i];

        // Converter caracteres acentuados para seus equivalentes
        if (c >= 192 && c <= 214) { // À, Á, Â, Ã, Ä, Å, Ā, Ă, Ą -> A
            resultado += 'A';
        } else if (c >= 216 && c <= 220) { // Ù, Ú, Û, Ü, Ū, Ŭ, Ů, Ű, Ų -> U
            resultado += 'U';
        } else if (c >= 200 && c <= 203) { // È, É, Ê, Ë, Ē, Ĕ, Ė, Ę, Ě -> E
            resultado += 'E';
        } else if (c >= 204 && c <= 207) { // Ì, Í, Î, Ï, Ĩ, Ī, Ĭ, Į, İ -> I
            resultado += 'I';
        } else if (c >= 210 && c <= 214) { // Ò, Ó, Ô, Õ, Ö -> O
            resultado += 'O';
        } else if (c >= 224 && c <= 246) { // à, á, â, ã, ä, å, ā, ă, ą -> a
            resultado += 'a';
        } else if (c >= 232 && c <= 235) { // è, é, ê, ë, ē, ĕ, ė, ę, ě -> e
            resultado += 'e';
        } else if (c >= 236 && c <= 239) { // ì, í, î, ï, ĩ, ī, ĭ, į, ı -> i
            resultado += 'i';
        } else if (c >= 242 && c <= 246) { // ò, ó, ô, õ, ö, ø, ō, ŏ, ő -> o
            resultado += 'o';
        } else if (c >= 249 && c <= 252) { // ù, ú, û, ü, ū, ŭ, ů, ű, ų -> u
            resultado += 'u';
        } else if (c == 231) { // ç -> c
            resultado += 'c';
        } else if (c == 241) { // ñ -> n
            resultado += 'n';
        } else if (c == 255) { // ÿ -> y
            resultado += 'y';
        } else if (c == 223) { // ß -> ss
            resultado += "ss";
        } else if (c >= 65 && c <= 90) { // A-Z -> a-z
            resultado += static_cast<char>(c + 32);
        } else {
            resultado += c;
        }
    }
    return resultado;
}

void ABB::insert(NodeABB*& current, const std::string& palavra, int indice) {
    if (current == NULL) {
        current = new NodeABB;
        current->palavra = palavra;
        current->indiceNo = indice;
        current->left = NULL;
        current->right = NULL;
    } else if (normalizarString(palavra) < normalizarString(current->palavra)) {
        insert(current->left, palavra, indice);
    } else {
        insert(current->right, palavra, indice);
    }
}

void ABB::insert(const std::string& palavra, int indice) {
    insert(root, palavra, indice);
}

void ABB::inOrder(NodeABB* current, std::list<std::string>& resultado) const {
    if (current != NULL) {
        if (current->left != NULL) {
            inOrder(current->left, resultado);
        }
        resultado.push_back(current->palavra);
        if (current->right != NULL) {
            inOrder(current->right, resultado);
        }
    }
}

std::list<std::string> ABB::inOrder() const {
    std::list<std::string> resultado;
    inOrder(root, resultado);
    return resultado;
}

void ABB::destruct(NodeABB*& current) {
    if (current != NULL) {
        if (current->left != NULL) {
            destruct(current->left);
        }
        if (current->right != NULL) {
            destruct(current->right);
        }
        delete current;
    }
}
