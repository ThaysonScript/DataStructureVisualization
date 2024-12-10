#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

struct ArvoreBst {
    int chave;
    int altura = 0;
    struct ArvoreBst *no_esquerdo;
    struct ArvoreBst *no_direito;
};

typedef struct ArvoreBst *ArvoreBstPonteiro;

/** op = 1
 * Recebe como parâmetros um número inteiro e o ponteiro para raiz de uma 
 * árvore BST, retorna o ponteiro para árvore após a inclusão do valor passado 
 * como primeiro parâmetro
 */
ArvoreBstPonteiro inserir(int numero_inserir, ArvoreBstPonteiro nova_arvore);

/** op = 2
 * Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela 
 * todos seus elementos, seguindo a ordem pré-order. Os valores dos elementos 
 * devem ser impressos entre colchetes, sem espaço entre dois elementos. 
 * Acrescentar um ‘\n’ após imprimir todos os elementos. Ex: [20][10][30]
 */
void preorder(ArvoreBstPonteiro arvore);

/** op =3
 * Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela 
 * todos seus elementos, seguindo a ordem in-order. Os valores dos elementos 
 * devem ser impressos entre colchetes, sem espaço entre dois elementos. 
 * Acrescentar um ‘\n’ após imprimir todos os elementos. Ex: [10][20][30
 */
void inorder(ArvoreBstPonteiro arvore);

/** op = 4
 * Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela 
 * todos seus elementos, seguindo a ordem pós-order. Os valores dos elementos 
 * devem ser impressos entre colchetes, sem espaço entre dois elementos. 
 * Acrescentar um ‘\n’ após imprimir todos os elementos. Ex: [10][30][20]
 */
void posorder(ArvoreBstPonteiro arvore);

/** op = 5
 * Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela 
 * todos seus elementos, ordenados de forma decrescente. Os valores dos 
 * elementos devem ser impressos entre colchetes, sem espaço entre dois 
 * elementos. Acrescentar um ‘\n’ após imprimir todos os elementos. 
 * Ex: [30][20][10]
 */
void reverso(ArvoreBstPonteiro arvore);

/** op = 6
 * Recebe como parâmetro o ponteiro para uma árvore BST e retorna a altura da
 * árvore. Na função main, deve ser impresso apenas o número inteiro seguido 
 * por ‘\n’. Ex: 2
 */
int altura(ArvoreBstPonteiro arvore);

/** op = 7
 * Recebe como parâmetro o ponteiro para uma árvore BST e a quantidade de 
 * folhas existentes na árvore
 */
void qtdFolhas(ArvoreBstPonteiro arvore, int qtd_folhas);

/** op = 8
 * Recebe como parâmetro o ponteiro para uma árvore BST e o valor de uma 
 * chave de procura. A função deve imprimir o caminho do nó raiz até o nó 
 * específico passado como parâmetro, caso a chave não exista, imprima apenas 
 * ‘\n’. Ex: [2][1]
 */
void caminho(ArvoreBstPonteiro arvore, int chave_procura);

/** op = 9
 * Recebe como parâmetros um número inteiro e a ponteiro para raiz de uma 
 * árvore BST, retorna o ponteiro para árvore após a remoção do valor passado 
 * como primeiro parâmetro.
 */
ArvoreBstPonteiro remover(int chave_remover, ArvoreBstPonteiro arvore);

#endif