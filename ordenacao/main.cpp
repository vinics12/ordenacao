//
//  main.cpp
//  ordenacao
//
//  Created by Vinícius Cerqueira Silva on 07/06/15.
//  Copyright (c) 2015 BEPiD FUCAPI. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 10000
int vetorQuick[tam],vetorSelDir[tam],vetorOrdDir[tam],vetorBubble[tam];
void quickSort( int p, int r,int *trocas);
int separa(int p, int r);
int selecaoDireta();
int insercaoDireta();
int bubbleSort();
void showVetor(int *vet){
    printf("\n");
    for (int i=0; i<tam; i++) {
        printf("%d, ",vet[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    for(int i=0;i<tam;i++){
        int v =rand()%1000;
        vetorQuick[i]=v;
        vetorSelDir[i]=v;
        vetorOrdDir[i]=v;
        vetorBubble[i]=v;
    }
    showVetor(vetorQuick);
    int trocas[4]={0,0,0,0};
    clock_t tempoInicial, tempoFinal;
    double tempoGasto[4];
    
    //quick
    tempoInicial = clock();
    quickSort(0, tam-1,&trocas[0]);
    tempoFinal = clock();
    
    tempoGasto[0] = (tempoFinal-tempoInicial)*1000/CLOCKS_PER_SEC;
    
    showVetor(vetorQuick);
    
    //selecao direta
    tempoInicial = clock();
    trocas[1]=selecaoDireta();
    tempoFinal = clock();
    
    tempoGasto[1] = (tempoFinal-tempoInicial)*1000/CLOCKS_PER_SEC;
    
    showVetor(vetorSelDir);
    
    //insercao direta
    tempoInicial = clock();
    trocas[2]=insercaoDireta();
    tempoFinal = clock();
    
    tempoGasto[2] = (tempoFinal-tempoInicial)*1000/CLOCKS_PER_SEC;
    
    showVetor(vetorOrdDir);
    
    //bubble
    tempoInicial = clock();
    trocas[3]=bubbleSort();
    tempoFinal = clock();
    
    tempoGasto[3] = (tempoFinal-tempoInicial)*1000/CLOCKS_PER_SEC;
    
    showVetor(vetorBubble);
    
    printf("Ordenação tempos e trocas:\nTempo em milisegundos para quick: %f e trocas: %d", tempoGasto[0],trocas[0]);
    printf("\nTempo em milisegundos para selecao direta: %f e trocas: %d", tempoGasto[1],trocas[1]);
    printf("\nTempo em milisegundos para ordenacao direta: %f e trocas: %d", tempoGasto[2],trocas[2]);
    printf("\nTempo em milisegundos para bubble: %f e trocas: %d", tempoGasto[3],trocas[3]);
    
    return 0;
}


//quicksort
int separa(int p, int r,int *trocas){
    int c = vetorQuick[p], i = p+1, j = r, t;
    while (i <= j) {
        if (vetorQuick[i] <= c)
            i++;
        else if (c < vetorQuick[j])
            j--;
        else {
            t = vetorQuick[i];
            vetorQuick[i] = vetorQuick[j];
            vetorQuick[j] = t;
            i++;
            j--;
        }
    }
    if (c!=vetorQuick[j]) {
        vetorQuick[p] = vetorQuick[j];
        vetorQuick[j] = c;
        *trocas=*trocas+1;
    }
    
    return j;
}
void
quickSort( int p, int r,int *trocas)
{
    int j;
    if (p < r) {
        j = separa(p, r,trocas);
        quickSort(p, j-1,trocas);
        quickSort(j+1, r,trocas);
    }
}

//selecao direta
int selecaoDireta(){
    int i,j,aux,menor, trocas;
    for (i=0; i<tam; i++) {
        menor = i;
        for (j=i+1; j<tam; j++) {
            if (vetorSelDir[j]<vetorSelDir[menor]) {
                menor = j;
                
            }
        }
        aux = vetorSelDir[i];
        vetorSelDir[i] = vetorSelDir[menor];
        vetorSelDir[menor] = aux;
        trocas++;
        
    }
    return trocas;
}

//insercao direta
int insercaoDireta(){
    int i, j,chave, trocas;
    for (j=1;j<tam;j++)
    {
        chave = vetorOrdDir[j];
        i = j - 1;
        while((i>=0) && (vetorOrdDir[i]>chave))
        {
            vetorOrdDir[i+1] = vetorOrdDir[i];
            i = i - 1;
            
        }
        vetorOrdDir[i+1] = chave;
        trocas++;
        
        
    }
    return trocas;
}

//bubble
int bubbleSort(){
    int i,j,aux,trocas;
    for (i=1; i<tam;i++ ) {
        for (j=tam-1; j>=i; j--) {
            if (vetorBubble[j-1]>vetorBubble[j]) {
                aux = vetorBubble[j-1];
                vetorBubble[j-1] = vetorBubble[j];
                vetorBubble[j] = aux;
                trocas++;
                
            }
        }
    }
    return trocas;
}