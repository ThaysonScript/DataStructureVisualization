#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

/** DEFINICOES DA BST == ARVORE BINARIA DE BUSCA
 *      - AO CONTRARIO DA BT, A BST POSSUI RESTRICAO DE COMO PODE INSERIR, REMOVER, PESQUISA ....
 *      
 *      - RESTRICOES GERAIS IMPORTANTES:
 *          OS FILHOS PRECISAM SE COMPARAVEIS
 *          POR PADRAO FILHOS A ESQUERDA DEVEM SER MENORES QUE FILHOS A DIREITA
 *          E FILHOS A DIREITA DEVEM SER MAIORES QUE FILHOS A ESQUERDA
 * 
 *      - O PORQUE DE RESTRIÇÕES:
 *          MELHORA A EFICIENCIA DO ALGORITMO
 *          EM MEDIA O(logN) PARA ARVORES BALANCEADAS == PARA OPERACOES DE MANIPULACAO DA ARVORE: INSERIR, REMOVER ...
 *      
 *      - CONCEITO GERAL:
 *          MESMO CONCEITO DE BT OU ARVORE BINARIA
 *          BUSCA SEMELHANTE A BT NAVEGANDO ENTRE OS NÓ DA ARVORE
 *          INSERIR É MUITO MAIS BARATO DO QUE EM VETORES ORDENADOS, POIS NAO PRECISA MOVIMENTAR OS VALORES OU NÓ
 */


// IMPLEMENTANDO UMA BST


// definir estrutura basica para a arvore
struct BST
{
    int valor;
    struct BST *subarvore_esquerda, *subarvore_direita;
};


/** DEFINICAO PARA MANIPULACAO DA ARVORE 1
 *      - INSERIR NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 *                  -1 CASO A ARVORE ESTIVER VAZIA INSERIR UM NOVO NÓ QUE SERÁ A RAIZ DA ARVORE
 *                  -2 CASO A ARVORE NAO ESTIVER VAZIA INSERIR UM NOVO NÓ QUE SERÁ A SUBARVORE/FILHO DA ARVORE/RAIZ
 *                  -3 VERIFICAR SE A NOVA CHAVE/VALOR A SER INSERIDO É MAIOR DO QUE O NÓ ATUAL DA ARVORE:
 *                      -3.1 EXEMPLO:
 *                          - CASO NOVO NÓ A SER INSERIDO SEJA MAIOR QUE A RAIZ, 
 *                          NAVEGAR PARA O PROXIMO NÓ A DIREITA ATÉ ENCONTRAR UM NÓ FOLHA 
 *                          ONDE SEU LINK SEJA NULL E INSERIR O NOVO NÓ COM CHAVE/VALOR EM QUESTÃO
 *                          
 *                          - CASO NA NAVEGAÇÃO NÃO ENCONTRAR O CAMINHO ESPERADO CONTINUAR NAVEGANDO
 *                          OU SEJA ACESSAR SEMPRE O PROXIMO NÓ A DIREITA
 * 
 *                  -4 VERIFICAR SE A NOVA CHAVE/VALOR A SER INSERIDO É MENOR DO QUE O NÓ ATUAL DA ARVORE:
 *                      -4.1 EXEMPLO:
 *                          - CASO NOVO NÓ A SER INSERIDO SEJA MENOR QUE A RAIZ, 
 *                          NAVEGAR PARA O PROXIMO NÓ A ESQUERDA ATÉ ENCONTRAR UM NÓ FOLHA 
 *                          ONDE SEU LINK SEJA NULL E INSERIR O NOVO NÓ COM CHAVE/VALOR EM QUESTÃO
 *                          
 *                          - CASO NA NAVEGAÇÃO NÃO ENCONTRAR O CAMINHO ESPERADO CONTINUAR NAVEGANDO
 *                          OU SEJA ACESSAR SEMPRE O PROXIMO NÓ A ESQUERDA
 * 
 *                  -5 INSERIU O NOVO NÓ COM VALOR/CHAVE? FAÇA O RETORNO DA NOVA ESTRUTURA, 
 *                  POIS IRÁ ATUALIZAR/SUBSTITUIR A ESTRUTURA ANTIGA NÃO MODIFICADA
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == UMA NOVA ESTRUTURA/ARVORE ATUALIZADA
 *          -2 PASSAR A ARVORE A QUAL DESEJA INSERIR NOVO NÓ
 *          -3 PASSAR VALOR A SER INSERIDO NO NOVO NÓ DA ARVORE PASSADA NO PARAMETRO 2
 */
BST *inserirBST(BST *arvore_passada, int valor_inserir);


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
BST *buscarBST(BST *arvore_passada, int valor_inserir);


/** DEFINICAO PARA MANIPULACAO DA ARVORE 3
 *      - REMOVER NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 * 
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == UMA NOVA ESTRUTURA/ARVORE ATUALIZADA
 *          -2 PASSAR A ARVORE A QUAL DESEJA REMOVER O NÓ DESEJADO
 *          -3 PASSAR VALOR/CHAVE DE BUSCA PARA ENCONTRAR O NÓ DA ARVORE PASSADA NO PARAMETRO 2
 */
BST *removerBST(BST *arvore_passada, int valor_remover);


/** DEFINICAO PARA IMPRESSAO DE ARVORE 1
 *      - IMPRIMIR NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 * 
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == NENHUM RETORNO
 *          -2 PASSAR A ARVORE A QUAL DESEJA A IMPRESSAO DOS VALORES
 */
BST *imprimirBST(BST *arvore_passada);



/** DEFINICAO PARA IMPRESSAO DE ARVORE 1.1
 *      - IMPRIMIR NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 * 
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == NENHUM RETORNO
 *          -2 PASSAR A ARVORE A QUAL DESEJA A IMPRESSAO DOS VALORES
 */
BST *imprimirPreOrderBST(BST *arvore_passada);

/** DEFINICAO PARA IMPRESSAO DE ARVORE 1.2
 *      - IMPRIMIR NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 * 
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == NENHUM RETORNO
 *          -2 PASSAR A ARVORE A QUAL DESEJA A IMPRESSAO DOS VALORES
 */
BST *imprimirInOrderBST(BST *arvore_passada);

/** DEFINICAO PARA IMPRESSAO DE ARVORE 1.3
 *      - IMPRIMIR NA ARVORE
 *          O QUE É PRECISO?
 *              CASOS DE USO:
 * 
 * 
 *      - PARAMETROS ESPERADOS
 *          -1 RETORNO == NENHUM RETORNO
 *          -2 PASSAR A ARVORE A QUAL DESEJA A IMPRESSAO DOS VALORES
 */
BST *imprimirPosOrderBST(BST *arvore_passada);

#endif