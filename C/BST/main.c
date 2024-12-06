#include <stdio.h>
#include <stdlib.h>
#include "./bst.h"

/** IMPLEMENTANDO PARA MANIPULACAO DA ARVORE 1 */
struct BST *inserirBST(struct BST *arvore_passada, int *valor_inserir) {
    // -1 CASO A ARVORE ESTIVER VAZIA INSERIR UM NOVO NÓ QUE SERÁ A RAIZ DA ARVORE
    if (arvore_passada == NULL) {
        struct BST *novo_no = (struct BST*) malloc(sizeof(struct BST));     // 1.1 alocar novo nó para a raiz

        novo_no->valor = *valor_inserir;                                    // 1.2 inserir o valor/chave ao novo nó
        novo_no->subarvore_direita = NULL;                                  // 1.3 definir nó direita como nulo
        novo_no->subarvore_esquerda = NULL;                                 // 1.4 definir nó esquerdo como nulo

        printf("valor inserido2: %p\n", &novo_no->valor);

        return novo_no;                                                     // 1.5 retornar raiz como qualquer outro nó que seria um nó folha

    } else {
        /* -2 CASO A ARVORE NAO ESTIVER VAZIA INSERIR UM NOVO NÓ QUE SERÁ A SUBARVORE/FILHO DA ARVORE/RAIZ
           -3 VERIFICAR SE A NOVA CHAVE/VALOR A SER INSERIDO É MAIOR DO QUE O NÓ ATUAL DA ARVORE:
              -3.1 EXEMPLO:
                  - CASO NOVO NÓ A SER INSERIDO SEJA MAIOR QUE A RAIZ, 
                  NAVEGAR PARA O PROXIMO NÓ A DIREITA ATÉ ENCONTRAR UM NÓ FOLHA 
                  ONDE SEU LINK SEJA NULL E INSERIR O NOVO NÓ COM CHAVE/VALOR EM QUESTÃO
                  
                  - CASO NA NAVEGAÇÃO NÃO ENCONTRAR O CAMINHO ESPERADO CONTINUAR NAVEGANDO
                  OU SEJA ACESSAR SEMPRE O PROXIMO NÓ A DIREITA
         
           -4 VERIFICAR SE A NOVA CHAVE/VALOR A SER INSERIDO É MENOR DO QUE O NÓ ATUAL DA ARVORE:
            -4.1 EXEMPLO:
                - CASO NOVO NÓ A SER INSERIDO SEJA MENOR QUE A RAIZ, 
                NAVEGAR PARA O PROXIMO NÓ A ESQUERDA ATÉ ENCONTRAR UM NÓ FOLHA 
                ONDE SEU LINK SEJA NULL E INSERIR O NOVO NÓ COM CHAVE/VALOR EM QUESTÃO
                
                - CASO NA NAVEGAÇÃO NÃO ENCONTRAR O CAMINHO ESPERADO CONTINUAR NAVEGANDO
                OU SEJA ACESSAR SEMPRE O PROXIMO NÓ A ESQUERDA
    
           -5 INSERIU O NOVO NÓ COM VALOR/CHAVE? FAÇA O RETORNO DA NOVA ESTRUTURA, 
           POIS IRÁ ATUALIZAR/SUBSTITUIR A ESTRUTURA ANTIGA NÃO MODIFICADA
        */

        // caso valor seja maior que o nó atual == inserir na esquerda
        if (*valor_inserir >= arvore_passada->valor)
            arvore_passada->subarvore_direita = inserirBST(arvore_passada->subarvore_direita, valor_inserir);
        
        else
            arvore_passada->subarvore_esquerda = inserirBST(arvore_passada->subarvore_esquerda, valor_inserir);

        // ver se precisa retornar valor
        return arvore_passada;
    }
}

void imprimirTeste(struct BST *arvore) {
    if (arvore != NULL) {
        printf("[%d] ", arvore->valor);

        imprimirTeste(arvore->subarvore_esquerda);
        imprimirTeste(arvore->subarvore_direita);
    }
}

int main(int argc, char const *argv[])
{
    // nova arvore
    struct BST *nova_arvore = NULL;
    int valor1 = 1, valor2 = 2, valor3 = 3;

    nova_arvore = inserirBST(nova_arvore, &valor1);
    nova_arvore = inserirBST(nova_arvore, &valor2);
    nova_arvore = inserirBST(nova_arvore, &valor3);

    imprimirTeste(nova_arvore);
    puts("");

    return 0;
}
