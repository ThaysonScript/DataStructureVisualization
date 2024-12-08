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
        if (*valor_inserir > arvore_passada->valor)
            arvore_passada->subarvore_direita = inserirBST(arvore_passada->subarvore_direita, valor_inserir);
        
        else
            arvore_passada->subarvore_esquerda = inserirBST(arvore_passada->subarvore_esquerda, valor_inserir);

        // ver se precisa retornar valor
        return arvore_passada;
    }
}


/** DEFINICAO PARA MANIPULACAO DA ARVORE 2
 *      - BUSCAR NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 *                  -1 VERIFICAR SE A CHAVE/VALOR É MAIOR OU MENOR QUE OS NÓ A SEREM PERCORRIDOS
 *                  -2 RETORNAR O NÓ ENCONTRADO?
 * 
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == UMA NOVA ESTRUTURA/ARVORE ATUALIZADA
 *          -2 PASSAR A ARVORE A QUAL DESEJA BUSCAR O NÓ DESEJADO
 *          -3 PASSAR VALOR/CHAVE DE BUSCA PARA ENCONTRAR O NÓ DA ARVORE PASSADA NO PARAMETRO 2
 */
struct BST *buscarBST(struct BST *arvore_passada, int *valor_buscar) {
    // 1 - caso base; encontrou o nó de busca ou o no nao foi encontrado
    if (arvore_passada == NULL || *valor_buscar == arvore_passada->valor)
        return arvore_passada;

    // 2 - nao encontrou, entao navegue pelo no direito caso valor de busca maior que no
    else if (*valor_buscar > arvore_passada->valor)
        return buscarBST(arvore_passada->subarvore_direita, valor_buscar);
    
    // 3 - nao encontrou, entao navegue pelo no a esquerda caso valor de busca menor que no
    else 
        return buscarBST(arvore_passada->subarvore_esquerda, valor_buscar);

}


/** DEFINICAO PARA MANIPULACAO DA ARVORE 3
 *      - REMOVER NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 *                  1 - buscar no com o valor desejado para remover
 *                  2 - verificar casos base de remoção:
 *                      2.1 - caso nao tenha filhos == remover o no
 *                      2.2 - caso tenha 1 filho == passar o no filho para o pai do no a ser removido e remover o no desejado
 *                      2.3 - caso tenha 2 filhos == navegar para a subarvore a esquerda obtendo o maior no a direita da subarvore
 *                          2.3.1 - copiar o valor do maior no para o no que foi desejado remover
 *                          2.3.2 - remover o maior no verificando os casos 2.1 e 2.2
 * 
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == UMA NOVA ESTRUTURA/ARVORE ATUALIZADA
 *          -2 PASSAR A ARVORE A QUAL DESEJA REMOVER O NÓ DESEJADO
 *          -3 PASSAR VALOR/CHAVE DE BUSCA PARA ENCONTRAR O NÓ DA ARVORE PASSADA NO PARAMETRO 2
 */
struct BST *removerBST(struct BST *arvore_remover, int *valor_remover) {
    // pronto para remover
    if (*valor_remover == arvore_remover->valor) {
        // 2.1 - caso nao tenha filhos == remover o no
        if (arvore_remover->subarvore_direita == NULL && arvore_remover->subarvore_esquerda == NULL){
            free(arvore_remover);
            return NULL;

        // 2.2 - caso tenha 1 filho == passar o no filho para o pai do no a ser removido e remover o no desejado
        } else if (arvore_remover->subarvore_direita != NULL && arvore_remover->subarvore_esquerda == NULL) {
            struct BST *recuperar_no_direito = arvore_remover->subarvore_direita;
            free(arvore_remover);
            return recuperar_no_direito;

        // 2.2 - caso tenha 1 filho == passar o no filho para o pai do no a ser removido e remover o no desejado
        } else if (arvore_remover->subarvore_direita == NULL && arvore_remover->subarvore_esquerda != NULL) {
            struct BST *recuperar_no_esquerdo = arvore_remover->subarvore_esquerda;
            free(arvore_remover);
            return recuperar_no_esquerdo;

        // 2.3 - caso tenha 2 filhos == navegar para a subarvore a esquerda obtendo o maior no a direita da subarvore
        } else if (arvore_remover->subarvore_direita != NULL && arvore_remover->subarvore_esquerda != NULL) {


        // 1 - buscar no com o valor desejado para remover
        } else {
            if (*valor_remover > arvore_remover->valor)
                arvore_remover->subarvore_direita = removerBST(arvore_remover->subarvore_direita, valor_remover);
            
            else
                arvore_remover->subarvore_esquerda = removerBST(arvore_remover->subarvore_esquerda, valor_remover);
        }
        
    }

}


struct BST *bucarMaiorNoDireitoSubarvoreEsquerda(struct BST *arvore) {
    // 
}


void imprimirPreOrderBST(struct BST *arvore_passada) {
    if (arvore_passada != NULL) {
        printf("[%d] ", arvore_passada->valor);

        imprimirPreOrderBST(arvore_passada->subarvore_esquerda);
        imprimirPreOrderBST(arvore_passada->subarvore_direita);
    }
}

void imprimirInOrderBST(struct BST *arvore_passada) {
    if (arvore_passada != NULL) {
        imprimirInOrderBST(arvore_passada->subarvore_esquerda);

        printf("[%d] ", arvore_passada->valor);

        imprimirInOrderBST(arvore_passada->subarvore_direita);
    }
}

void imprimirPosOrderBST(struct BST *arvore_passada) {
    if (arvore_passada != NULL) {
        imprimirPosOrderBST(arvore_passada->subarvore_esquerda);
        imprimirPosOrderBST(arvore_passada->subarvore_direita);

        printf("[%d] ", arvore_passada->valor);
    }
}


int main(int argc, char const *argv[])
{
    // nova arvore
    struct BST *nova_arvore = NULL;
    int valor;

    while (valor != -1) {
        scanf("%i", &valor);

        if (valor != -1)
            nova_arvore = inserirBST(nova_arvore, &valor);
    }


    imprimirPreOrderBST(nova_arvore);
    puts("");
    imprimirInOrderBST(nova_arvore);
    puts("");
    imprimirPosOrderBST(nova_arvore);
    puts("");

    struct BST *no_buscado = NULL;
    int val = 5;

    no_buscado = buscarBST(nova_arvore, &val);
    printf("no com valor: %p\n", no_buscado);
    printf("no com valor: %i\n", no_buscado->valor);

    puts("REMOVENDO");
    nova_arvore = removerBST(nova_arvore, &val);

    imprimirPreOrderBST(nova_arvore);
    puts("");
    imprimirInOrderBST(nova_arvore);
    puts("");
    imprimirPosOrderBST(nova_arvore);
    puts("");

    return 0;
}
