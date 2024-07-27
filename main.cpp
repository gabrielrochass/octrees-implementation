// octrees implementation
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// define estrutura do nó, referenciando os 8 filhos e uma bounding box que delimita o espaço coberto pelo nó
struct BoundingBox { // delimita o espaço 3D coberto pelo nó
    float x_min, x_max, 
    y_min, y_max, 
    z_min, z_max;

    BoundingBox(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max) {
        this->x_min = x_min;
        this->x_max = x_max;
        this->y_min = y_min;
        this->y_max = y_max;
        this->z_min = z_min;
        this->z_max = z_max;
    }
};

struct OctreeNode { // nó da árvore octree
    BoundingBox box;
    vector<shared_ptr<OctreeNode>> filhos;
    vector<int> objetos;

    OctreeNode(BoundingBox bb) : box(bb) {
        filhos.resize(8, nullptr); // cria 8 filhos 
    }

void printOctree(int profundidade = 0) {
    string indent(profundidade*2, ' ');
    cout << indent << "Node na profundidade " << profundidade << " com limites: "
    << "x[" << box.x_min << ", " << box.x_max << "], "
    << "y[" << box.y_min << ", " << box.y_max << "], "
    << "z[" << box.z_min << ", " << box.z_max << "]" << endl;

    for (int i = 0; i < 8; i++) {
        if (filhos[i] != nullptr) {
            filhos[i]->printOctree(profundidade + 1);
        } else {
            cout << indent << "Filho " << i << " nulo" << endl;
        }
    }
}
};

int main() {
    BoundingBox bb(0, 100, 0, 100, 0, 100);
    OctreeNode root(bb);

    // child 1 
    BoundingBox bb1(0, 50, 0, 50, 0, 50);
    root.filhos[0] = make_shared<OctreeNode>(bb1);

    // child 2
    BoundingBox bb2(50, 100, 0, 50, 0, 50);
    root.filhos[1] = make_shared<OctreeNode>(bb2);

    root.printOctree();

    return 0;
}


// método de divisão do espaço em 8 partes iguais, a partir do centro da bounding box

// método de inserção de um ponto no octree em um nó (sub-volume) específico -> se ligar no momento em que um novo nó é criado (critério de subdivisão: quantidade de pontos no nó > 1)

// método de busca de um ponto no octree

// método de remoção de um ponto no octree

// método de visualização do octree

// método de visualização do octree em formato de árvore
