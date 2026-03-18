/*
Carolina Lee - 10440304
Pedro Gabriel Guimarães Fernandes - 10437465 
*/

    #ifndef __POLI_H__
    #define __POLI_H__

    typedef struct{
        int *coeficientes; // to com dificuldadde de entender o que isso faz por que não tem um array logo ñ sei como quanda valores distintos
        //tbm não to entendo como caralhos isso funciona
        //termos acho??? aaa ok
        //então pelo que eu entendi isso aqui guarda um grupo de termos acho que pelo grau e termos vc tem um chute de quanto termos temos agora o problema é como tá guardando os coeficientes
        //isso aqui 5x^2 + 0x^1 + 3 e os coeficientes são os numeros na frente se eu entender como quarda isso o res 
        //cara, pra ser bem honesta eu nem sei se ele t´criando direito, pq ele só rodou quando eu setei termos para 0. lá no poli create
        //vamos ver lá no inicio então
        //ok
        int grau; // testar se o termo do grau foi inserido corretamente.
        int termos; // conta quantidade de termos que nao sao igua a zero =>  5x^2 + 0x^1 + 3 => 2 termos.
    }polinomio;

    polinomio *poli_create(int grau);
    void poli_destroy(polinomio **p); 

    /* As funções  poli_ins_termo e poli_get_termo devolvem 
    * 1 se exp (expoente) é válido e a operação foi bem sucedida
    * 0 caso contrário
    * 
    * Se for inserir um termo em expoente com valor este é substituido
    * No caso de poli_get_termo, o valor é retornado na variável apontada por *coef.
    */
    int poli_ins_termo(polinomio *p, int exp, int coef);
    int poli_get_termo(polinomio *p, int exp, int *coef);

    int calcula_px(polinomio *p, int x);

    polinomio * poli_soma(polinomio *p, polinomio *q);

    polinomio * poli_mult(polinomio *p, polinomio *q);

    polinomio * poli_div(polinomio *p, polinomio *q);

    #endif