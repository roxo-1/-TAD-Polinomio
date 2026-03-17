/*
Carolina Lee - 10440304
Pedro Gabriel Guimarães Fernandes - 10437465 
*/
#include <stdlib.h>
#include <stdio.h>

#include "poli.h"

polinomio * poli_create(int grau){
    // TODO: Implemente aqui a solucao para operacao create
    polinomio *p;
    p=malloc(sizeof(polinomio));
    p->grau = grau;
    p->coeficientes = malloc(grau * sizeof(int));
    p->termos = 0;
    return p;
    // return NULL;
}

void poli_destroy(polinomio **p){
    // TODO: Implemente aqui a solucao para operacao destroy
    if (p == NULL || *p == NULL) {
        return; // Safety check: don't try to free nothing
    }
    free((*p)->coeficientes);
    free(*p);
    *p=NULL;
    // return;
}

int poli_ins_termo(polinomio *p, int exp, int coef) {
    // TODO: Implemente aqui a solucao para operacao insere coeficiente
    for(int i = 0; i<sizeof(p);i++){
        if(i==exp){
            p->coeficientes[i] = coef;
        }
    }
    return 0;
}

int poli_get_termo(polinomio *p, int exp, int *coef){
    // TODO: Implemente aqui a solucao para operacao get coeficiente
    for(int i = 0; i<sizeof(p);i++){
        if(i==exp){
            return p->coeficientes[i];
        }
    }
    return 0;
}

int calcula_px(polinomio *p, int x){
    // TODO: Implemente aqui a solucao para operacao calcula o valor de P(x)     
    
    return 0;
}

polinomio * poli_soma(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que soma dois polinomios e gera um terceiro

    return NULL;
}

polinomio * poli_mult(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que multiplica dois polinomios e gera um terceiro

    return NULL;
}

polinomio * poli_div(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que divide dois polinomios e gera um terceiro

    return NULL;
}


