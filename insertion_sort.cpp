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

void insertion_sort(int vetor[TAM])
{   
    int i,j,atual;
    for(i=1;i<TAM;i++)
    {
        //Elemento atual em analise
        atual = vetor[i];
    //Elemento anterior analisado
        j = i -1;

        while(j>=0 && atual< vetor[j])
        {
            //reporsiciona os elementos para frente
            vetor[j+1] = vetor[j];
            //faz o j andar para tras
            j= j-1;
        }

        //agr que o espaco foi aberto colocamos o atual numero menor
        vetor[j+1] = atual;
        imprime_vetor(vetor); //mostra a lista atualizada
        
    }    

}
int main ()
{

    int vetor [TAM] = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(vetor);
    imprime_vetor(vetor);
}
