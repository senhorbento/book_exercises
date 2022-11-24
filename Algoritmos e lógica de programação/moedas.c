#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSA 1
#define VERDADEIRA 2

#define MAX_MOEDAS 10

void definirMoedas(int v[]){
    int falsa;
    
    for(int i = 0; i < MAX_MOEDAS; i++)
        v[i]=VERDADEIRA;
    
    srand(time(NULL));   
    falsa = rand() % MAX_MOEDAS;
    
    v[falsa]=FALSA;
}

void mostrarMoedas(int v[]){
    for(int i = 0; i < MAX_MOEDAS; i++)
        printf("%c ", v[i] == VERDADEIRA ? 'V' : 'F');
    printf("\n");
}

int checarPeso(int m1, int m2){
    if(m1 + m2 == VERDADEIRA * 2)
        return -1;

    return m1 < m2 ? 1 : 2;
}

int localizarFalsa(int v[], int *p){
    int pos;
    *p = 0;
    for(int i=0; i<MAX_MOEDAS;i++){
        pos = checarPeso(v[i],v[i+1]);
        *p += 1;
        if(pos < 0) i++;
        else return pos == 1 ? i : i+1;
    }
    return -1;
}

int main(){
    int moedas[MAX_MOEDAS], pos, quantidadePesagem;
    
    definirMoedas(moedas);
    mostrarMoedas(moedas);
    
    pos = localizarFalsa(moedas, &quantidadePesagem);
    
    printf("A %dª moeda eh falsa\n", pos+1);
    printf("Foram feitas %d pesagens\n", quantidadePesagem);

    return 0;
}
