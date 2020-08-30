#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#define TAM 10

using namespace std;

void imprime_vetor(int vetor[])
{
    int i;

    cout << "\n";

    for(i = 0;i<TAM;i++)
    {
        cout << vetor[i]<< "-";
    }
}

int main()
{   
    int x,y,aux;
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    //'X' valor da esquerda sendo analisado
    for(x=0;x<TAM;x++)
        for(y=x+1;y<TAM;y++)
        {
            //confere se precisa fazer a troca
            if (vetor[x]>vetor[y])
            {
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
    imprime_vetor(vetor);
    return 0;
}