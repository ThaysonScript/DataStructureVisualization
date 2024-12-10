#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

ArvoreBstPonteiro inserir(int numero_inserir, ArvoreBstPonteiro nova_arvore) {
    if (nova_arvore == NULL) {
        ArvoreBstPonteiro novo_no = (ArvoreBstPonteiro) malloc(sizeof(ArvoreBstPonteiro));

        novo_no->no_esquerdo = NULL;
        novo_no->no_direito = NULL;
        novo_no->chave = numero_inserir;

        return novo_no;

    } else {
        if (numero_inserir > nova_arvore->chave) {
            nova_arvore->no_direito = inserir(numero_inserir, nova_arvore->no_direito);
       
        } else {
            nova_arvore->no_esquerdo = inserir(numero_inserir, nova_arvore->no_esquerdo);
        }        
    }
    nova_arvore->altura += 1;
    return nova_arvore;
}

void preorder(ArvoreBstPonteiro arvore) {
    if (arvore != NULL) {
        printf("[%i]", arvore->chave);
        
        preorder(arvore->no_esquerdo);
        preorder(arvore->no_direito);
    }
    puts("");
}

void inorder(ArvoreBstPonteiro arvore) {
    if (arvore != NULL) {
        inorder(arvore->no_esquerdo);

        printf("[%i]", arvore->chave);
        
        inorder(arvore->no_direito);
    }
    puts("");
}

void posorder(ArvoreBstPonteiro arvore) {
    if (arvore != NULL) {
        posorder(arvore->no_esquerdo);
        posorder(arvore->no_direito);

        printf("[%i]", arvore->chave);
    }
    puts("");
}

void reverso(ArvoreBstPonteiro arvore) {
    posorder(arvore);
}

int altura(ArvoreBstPonteiro arvore) {
    int altura_atual = 0;
    if (arvore != NULL) {
        if (arvore->altura > altura_atual)
            altura_atual = arvore->altura;

        altura(arvore->no_esquerdo);
        altura(arvore->no_direito);
    }
    return altura_atual;
}

void qtdFolhas(ArvoreBstPonteiro arvore, int qtd_folhas) {

}

void caminho(ArvoreBstPonteiro arvore, int chave_procura) {

}

ArvoreBstPonteiro remover(int chave_remover, ArvoreBstPonteiro arvore) {

}

int main(int argc, char const *argv[]) {
    int numero_inserir = 0;
    int qtd_folha = 0;
    int chave_procura = 0;
    int chave_remover = 0;
    int op = 0;
    ArvoreBstPonteiro arvore = NULL;

    while (1) {
        scanf("%i", &op);

        switch(op) {
            case 1:
                scanf("%i", &numero_inserir);

                inserir(numero_inserir, arvore);
                break; 
            
            case 2:
                preorder(arvore);
                break; 
                
            case 3:
                inorder(arvore);
                break; 
                
            case 4:
                posorder(arvore);
                break; 
                
            case 5:
                reverso(arvore);
                break; 

            case 6:
                altura(arvore);
                break; 
            
            case 7:
                scanf("%i", &qtd_folha);

                qtdFolhas(arvore, qtd_folha);
                break; 
                
            case 8:
                scanf("%i", &chave_procura);

                caminho(arvore, chave_procura);
                break; 
                
            case 9:
                scanf("%i", &chave_remover);

                remover(chave_remover, arvore);
                break;             
        }

        /** op = 99
         * Fecha o programa.
         */
        if (op == 99)
            break;
    }
    
    return 0;
}
