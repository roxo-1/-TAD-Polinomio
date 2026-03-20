/*
Carolina Lee - 10440304
Pedro Gabriel Guimarães Fernandes - 10437465 
*/

//gcc -g poli.c teste_poli.c -o teste_poli -lm
//valgrind --leak-check=yes ./teste_poli
#include <stdlib.h>
#include <stdio.h>

#include "poli.h"

polinomio * poli_create(int grau){
    // TODO: Implemente aqui a solucao para operacao create
    polinomio *p = malloc(sizeof(polinomio));
    p->grau = grau;
    p->termos = 0;

    p->coeficientes = malloc((grau + 1) * sizeof(int)); // botar grau + 1 aqui, não entendi pq, imagino que seja porque o menor que pode ter é grau 1, faz sentido
    
    for (int i = 0; i <= grau; i++){
        p->coeficientes[i] = 0;
    }
        return p; 
}

void poli_destroy(polinomio **p){
    // TODO: Implemente aqui a solucao para operacao destroy
    if (p == NULL || *p == NULL) {
        return;
    }
    free((*p)->coeficientes);
    //então aqui o destroy tá errado tbm né? tipo já que agnt inicializou todo o coeficiente lá no create
    free(*p);
    //acho que tá certo sim,tipo ai vc tá liberando a memoria dele, pra mim isso tá certo
    //:-:
    //Vamos ver o codigo lá denovo, ok
    *p=NULL;
    // return;
}

int poli_ins_termo(polinomio *p, int exp, int coef) {
    // TODO: Implemente aqui a solucao para operacao insere coeficiente
    //Então pelo que eu li no poli.h essa função tem que retornar 1 se a operação deu certo e 0 se deu errado
    if((exp <= p->grau) && (exp >= 0)){
        p->coeficientes[exp] = coef;
        p->termos += 1;
        return 1;
    }else{
        return 0;
        printf("não");
    }
    // Precisamos inserir o coeficiente e o exp
    //p->grau diferente de 0, se sim termos aumenta. se ele for igual  1
    
    // return 0;//?Assim? Acho que sim mas agora precisamos ver como prencher a parte do meio
    //to tentando entender o codigo do polinomio
}

int poli_get_termo(polinomio *p, int exp, int *coef){
    // TODO: Implemente aqui a solucao para operacao get coeficiente
    if((exp >= 0) && (exp <= p->grau) && (p->coeficientes[exp] != 0) ){
        *coef = p->coeficientes[exp];
        return 1;
    }
    return 0;

}

int calcula_px(polinomio *p, int x){
    // TODO: Implemente aqui a solucao para operacao calcula o valor de P(x)    
    int soma = 0;
    for (int i = 0; i <= p->grau; i++)
    {
        int valor = 1;
        for (int j = 0; j < i; j++)
        {
            valor *= x;
        }
        
        soma += p->coeficientes[i] * valor;
    }
    
    return soma;
}

polinomio * poli_soma(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que soma dois polinomios e gera um terceiro
    int novoGrau = 0;
    if(p->grau > q->grau){
        novoGrau = p->grau;
    }else{
        novoGrau = q->grau;
    }
    polinomio *r = poli_create(novoGrau);
    
    for (int i = 0; i <= novoGrau; i++)
    {
        int pCoef, qCoef = 0;
        if(p->grau >= i){
            pCoef = p->coeficientes[i];
        }
        if(q->grau >= i){
            qCoef = q->coeficientes[i];
        }

        r->coeficientes[i] = pCoef + qCoef;
    }
    

    return r;
}

polinomio * poli_mult(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que multiplica dois polinomios e gera um terceiro
    if(p == NULL || q == NULL) return NULL;
    if(p->termos == 0 || q ->termos == 0) return NULL;
    int novoGrau = p->grau + q->grau;
    polinomio *r = poli_create(novoGrau);

     for (int i = 0; i <= p->grau; i++) {
        for (int j = 0; j <= q->grau; j++) {
            r->coeficientes[i + j] += p->coeficientes[i] * q->coeficientes[j];
        }
    }

    return r;
}

polinomio * poli_div(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que divide dois polinomios e gera um terceiro
    if(p == NULL || q == NULL) return NULL;
    if(p->termos == 0 || q ->termos == 0) return NULL;
    if (p->grau < q->grau) {
        return poli_create(0);
    }

    polinomio *resto = poli_create(p->grau);
    polinomio *quociente = poli_create(p->grau - q->grau);

    for (int i = 0; i <= p->grau; i++) {
        resto->coeficientes[i] = p->coeficientes[i];
    }

    for (int i = p->grau; i >= q->grau; i--) {
        float coef = resto->coeficientes[i] / q->coeficientes[q->grau];
        int grau = i - q->grau;

        quociente->coeficientes[grau] = coef;

        for (int j = 0; j <= q->grau; j++) {
            resto->coeficientes[j + grau] -= coef * q->coeficientes[j];
        }
    }

    poli_destroy(&resto);

    return quociente;
}


