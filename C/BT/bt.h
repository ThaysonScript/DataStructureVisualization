#ifndef BT_H_INCLUDED
#define BT_H_INCLUDED

/** DEFINICAO DE UM NÓ DE UMA ARVORE BINARIA
 *      - GERAL:
 *          AO CONTRARIO DA BST, A BT NAO POSSUI NENHUMA RESTRICAO DE COMO PODE INSERIR, REMOVER, PESQUISA ....
 *          SAO ESTRUTURAS RECURSIVAS
 *          O(n) no pior caso.
 * 
 *      - ESQUEMA DE HIERARQUIA:
 *          POSSUEM SOMENTE 2 FILHOS COMPARAVEIS
 * 
 *      - BUSCA:
 *          PODE SER FEITA NAVEGANDO ENTRE OS LINKS DOS FILHOS OU CHAMADOS SUBARVORE/NÓ DA ARVORE
 * 
 *      - RAIZ:
 *          A RAIZ OU PRIMEIRO NÓ DA ARVORE É O UNICO NÓ QUE NAO É FILHO DE OUTRO NÓ
 * 
 *      - ARVORE VAZIA:
 *          ARVORE DITA VAZIA QUANDO RAIZ == NULL
 * 
 *      - SUBARVORE:
 *          CADA NÓ INSERIDO NA ARVORE SE TORNARÁ UMA RAIZ DESTA SUBARVORE
 * 
 *      - PROFUNDIDADE DE UM NÓ:
 *          A PROFUNDIDADE DO NÓ SE DÁ PELA QUANTIDADE DE LINKS/ARESTAS DE CAMINHOS QUE VAI DA RAIZ ATÉ O NÓ 
 * 
 *      - ALTURA DA ARVORE:
 *          A ALTURA DA ARVORE SE DÁ PELA QUANTIDADE MAXIMA DE LINKS/ARESTAS DE CAMINHOS QUE VAI DA RAIZ
 *          ATÉ O ULTIMO NÓ DA ARVORE
 * 
 *      - MAXIMOS:
 *          A ALTURA MAXIMA DE UM ARVORE É DADA POR ( N - 1 ) SENDO N A QUANTIDADE DE NÓ DA ARVORE 
 * 
 *      - MINIMOS:
 *          A ALTURA MINIMA DA ARVORE E DADA POR ( LOG N ) SENDO N A QUANTIDADE DE NÓ DA ARVORE
 *          CASO ALTURA ESTIVER PROXIMO DE LOG DE N, ENTAO A ALTURA DA ARVORE ESTA BALANCEADA
 * 
 *      - COMPRIMENTO INTERNO DE UM NÓ:
 *          SE DA PELA PROFUNDIDADE DE UM NÓ QUE TEM PELO MENOS 1 FILHO, OU SEJA, SEM CONSIDERAR NÓ FOLHA
 * 
 *      - SOMA DOS COMPRIMENTOS INTERNOS DE UM NÓ:
 *          SE DA PELA SOMA DA QUANTIDADE DA PROFUNDIDADE DOS COMPRIMENTOS INTERNOS DE UM NÓ
 *      
 */
struct BT
{
    // int valor;  valor ou chave do novo no, opcional
    struct BT *noDireito, *noEsquerdo;
};


/** EXEMPLO DE UMA ARVORE
 * 
 *                  A
                   / \
                  B   C
                 / \
                D   E

    - PROFUNDIDADE DE NÓ ( ENTENDE-SE MELHOR SE CONTAR QUANTOS LINKS TEM DO NÓ ATUAL ATÉ SUA RAIZ ACIMA ):
        A = 0, POIS É A QUANTIDADE DE LINKS QUE ( A ) FAZ DA RAIZ ATÉ O NÓ ( A )
        B = 1, POIS É A QUANTIDADE DE LINKS QUE ( B ) FAZ DA RAIZ ATÉ O NÓ ( B )
        C = 1, POIS É A QUANTIDADE DE LINKS QUE ( C ) FAZ DA RAIZ ATÉ O NÓ ( C )
        D = 2, POIS É A QUANTIDADE DE LINKS QUE ( D ) FAZ DA RAIZ ATÉ O NÓ ( D )
        E = 2, POIS É A QUANTIDADE DE LINKS QUE ( E ) FAZ DA RAIZ ATÉ O NÓ ( E )


    - COMPRIMENTO INTERNO DO NÓ:
        A = POSSUI LINKS COM ( B ) E ( C ), MAS SUA PROFUNDIDADE É == 0 {
            POIS É A QUANTIDADE DE LINKS QUE ( A ) FAZ DA RAIZ ATÉ O NÓ ( A )
        }

        B = POSSUI LINKS COM ( D ) E ( E ), MAS SUA PROFUNDIDADE É == 1 {
            POIS É A QUANTIDADE DE LINKS QUE ( B ) FAZ DA RAIZ ATÉ O NÓ ( B )
        }

    - SOMA DOS COMPRIMENTOS INTERNOS DO NÓ:
        É A SOMA DAS QUANTIDADES DA ( PROFUNDIDADE ) DOS COMPRIMENTOS INTERNOS DO NÓ ( A + B ) = ( 0 + 1 ) == 1
 */

#endif