#ifndef ABB_H
#define ABB_H

#include <list>
#include <string>

struct NodeABB {
    std::string palavra;
    int indiceNo;
    NodeABB* left;
    NodeABB* right;
};

class ABB {
public:
    ABB();
    ~ABB();

    void insert(const std::string& palavra, int indice);
    std::list<std::string> inOrder() const;

private:
    NodeABB* root;

    void insert(NodeABB*& current, const std::string& palavra, int indice);
    void inOrder(NodeABB* current, std::list<std::string>& resultado) const;
    void destruct(NodeABB*& current);
    std::string normalizarString(const std::string& str) const;
};

#endif
