#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

struct Node {
    int data;
    int x, y;  // Coordenadas a desenhar
    Node* left;
    Node* right;

    Node(int value, int x_pos, int y_pos) : data(value), x(x_pos), y(y_pos), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int value, int x, int y) {
        root = insertRec(root, value, x, y);
    }

    Node* insertRec(Node* node, int value, int x, int y) {
        if (node == nullptr) {
            return new Node(value, x, y);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value, x - 50, y + 50);  // Ajusta a posição para a esquerda
        } else {
            node->right = insertRec(node->right, value, x + 50, y + 50);  // Ajusta a posição para a direita
        }

        return node;
    }

    void draw(SDL_Renderer* renderer, Node* node) {
        if (node != nullptr) {
            // Desenhar o nó
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Azul
            SDL_RenderDrawPoint(renderer, node->x, node->y);

            // Desenhar as linhas para os filhos
            if (node->left != nullptr) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Verde
                SDL_RenderDrawLine(renderer, node->x, node->y, node->left->x, node->left->y);
                draw(renderer, node->left);
            }

            if (node->right != nullptr) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Vermelho
                SDL_RenderDrawLine(renderer, node->x, node->y, node->right->x, node->right->y);
                draw(renderer, node->right);
            }
        }
    }
};

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Binary Search Tree Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    BST tree;
    tree.insert(50, 400, 50);  // Raiz
    tree.insert(30, 350, 150);
    tree.insert(70, 450, 150);
    tree.insert(20, 300, 250);
    tree.insert(40, 400, 250);
    tree.insert(60, 420, 250);
    tree.insert(80, 480, 250);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Branco para fundo
    SDL_RenderClear(renderer);

    tree.draw(renderer, tree.root);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);  // Espera 5 segundos antes de fechar

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
