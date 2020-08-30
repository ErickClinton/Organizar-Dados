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

void selection_sort(int vetor[TAM])
{
    int posicaoDoMenorValor,aux,i,j;

    for(i=0;i<TAM;i++)
    {
        //recebe a posicao inicial para o menor valor
        posicaoDoMenorValor = i;

        for(j = i+1;j<TAM;j++)
        {
            if(vetor[j]<vetor[posicaoDoMenorValor])
            {
                posicaoDoMenorValor = j;
            }
        }
        //verifica se ouve mudanca e troca os valores
        if(posicaoDoMenorValor != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;
        }
    }
}

int main()
{
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    selection_sort(vetor);

    imprime_vetor(vetor);
}