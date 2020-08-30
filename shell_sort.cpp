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
void shell_sort(int vetor[TAM])
{
    int i,j,atual;
    int h=1;

    //de quantos em quantos sera o pulo entre analises
    while(h<TAM)
    {
        h=3*h+1;
    }

    while(h>1)
    {
        //reduz a distancia entre as analises
        h=h/3;
        int i,j,atual;
        for(i=h;i<TAM;i++)
        {
            //Elemento atual em analise
            atual = vetor[i];
            //Elemento anterior analisado
            j= i -h;

            while(j>=0 && atual< vetor[j])
            {
                //reporsiciona os elementos para frente
                vetor[j+h] = vetor[j];
                //faz o j andar para tras
                j= j-h;
            }

            //agr que o espaco foi aberto colocamos o atual numero menor
            vetor[j+h] = atual;
            imprime_vetor(vetor); //mostra a lista atualizada
        }
    }
        
}

int main()
{
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    shell_sort(vetor);

    imprime_vetor(vetor);
}