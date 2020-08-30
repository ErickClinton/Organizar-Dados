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

//junta os 2 sub arrays criados ao dividir o vetor principal
void merge(int vetor[TAM], int indiceEsquerdo,int meio, int indiceDireito)
{
    int i,j,k;
    int n1 = meio -indiceEsquerdo +1;
    int n2 = indiceDireito - meio;
    //cria dois arrays temporarios
    int vetorEsquerdo[n1], vetorDireito[n2];

    //passa os elementos do vetor principal para o primeiro vetor auxiliar
    for(i=0;i<n1;i++)
    {
        vetorEsquerdo[i] = vetor[indiceEsquerdo+i];
    }

    for(j=0;j<n2;j++)
    {
        vetorDireito[j] = vetor[meio+1+j];
    }

    //reseta as variaveis
    i=0;
    j=0;
    k = indiceEsquerdo;
    while(i<n1 && j<n2)
    {
        //caso o valor da esquerda seja menor
        if(vetorEsquerdo[i]<=vetorDireito[j])
        {
            //passo para o meu vetor principal
            vetor[k] = vetorEsquerdo[i];
            i++;
        }
        else
        {
            vetor[k] = vetorDireito[j];

            j++;
                
            
        }
        k++;
        
    }
    //se faltarem alguns elementos do array esquerdo, passa eles para o array principal
    while (i<n1)
    {
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        vetor[k]=vetorDireito[j];
        j++;
        k++;
    }
    
}
void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito)
{
    if(indiceEsquerdo<indiceDireito)
    {
        //encontra o meio
        int meio = indiceEsquerdo + (indiceDireito-indiceEsquerdo)/2;
        merge_sort(vetor, indiceEsquerdo,meio);
        merge_sort(vetor,meio+1,indiceDireito);

        //une os 2 subs arrays que foram criados
        merge(vetor, indiceEsquerdo,meio,indiceDireito);
    }
}

int main()
{   
    int x,y,aux;
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    //'X' valor da esquerda sendo analisado

    merge_sort(vetor,0,TAM-1);

    imprime_vetor(vetor);
    return 0;
}