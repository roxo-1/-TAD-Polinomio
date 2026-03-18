/*
Carolina Lee - 10440304
Pedro Gabriel Guimarães Fernandes - 10437465 
*/
#include <stdlib.h>
#include <stdio.h>

#include "poli.h"

polinomio * poli_create(int grau){
    // TODO: Implemente aqui a solucao para operacao create
    polinomio *p = malloc(sizeof(polinomio));
    p->grau = grau;
    p->termos = 0;

    p->coeficientes = malloc((grau + 1) * sizeof(int)); // botar grau + 1 aqui, não entendi pq, imagino que seja porque o menor que pode ter é grau 1, faz sentido
    
    for (int i = 0; i < grau; i++){
        p->coeficientes[i] = 0;
    }
        //acho que assim vai funcionar, vc entendeu?
        //sisi, tá inicializando o array todo
        // sim o queagente itnha esquecido foi de inicializar o malloc pra colocar espaço par a struct e zerar todods o coeficientes
        //ahhhhh,e já agnt agnt não tinha inicializado aqui em cima ele não tem onde inserir lá embaixo isso, blz vou testar
        //não sei vc consegue ver o terminal 
        // mas o create continua funcionando, mas o termo continua errado alguma outra coisa ainda não funciona
        // sim eu vejo, é que agente só arrumou o create tem que mexer no termo ainda, aaaa ok
        return p;
    // return NULL;
    //Carol colo quei o outro codigo para ver se ele fazia sentido e pelo que entendi temos que inicializar o array de coeficientestambém
    // mas o que eu não to entendedo é que no struct esse bagulho nõ é um array, é um ponteiro tipo ???? vou mandar um print no whats, ok
    // aaaaaah, o doido mandou agnt criar o array, tendeu kkkkkkkkkkkk
    //então pelo que entend
    //mas ent n o malloc que eu tinha feito deveria funcionar, né? Nao porque o que vc fez é só o coeficuenten tem que fazer outro para o polinomio em si 
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
    if((p->coeficientes[exp] != 0) && (exp <= p->grau) && (exp >= 0)){
        *coef = p->coeficientes[exp];
        return 1;
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


