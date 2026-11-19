/*
	Name: MergeSort.cpp  
	Author: Hyago Santos
	Date: 13/10/26 11:13
	Description: Implementação do metodo de 
				ordenação Merge Sort
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//prototipação
void MergeSort(int *,int, int); //Quebra tudo em uma unica unidade
void Merge(int *, int, int, int); //Mescla todos os sub-vetores

main()
{
	int vet[100000];
	//int vet[] = {23,12,17,-2,20,24,157,50,81,53};
	int tam, i;
	tam = sizeof(vet)/sizeof(int);
	
	srand(time(NULL));
		for(i = 0; i <tam; i++){
			vet[i] = rand()%100000;
	}
		
	MergeSort(vet, 0, tam-1);	
	puts("\n\nVetor ordenado pelo Merge Sort:");
		for(i=0; i<tam; i++){
			printf("%d|", vet[i]);
		}
}
// função recursiva para quebrar todo o conjunto de dados em diversos vetores "Logicos"
void MergeSort(int *V, int inicio, int fim)
{
	if(inicio < fim)
	{
		int meio = (inicio + fim)/2; // Calcula o meio do conjunto
		MergeSort(V, inicio, meio); // Dividi o lado esquerdo
		MergeSort(V, meio+1, fim); // Divide o lado direito
		Merge(V, inicio, meio, fim);
	}	
}

//função para juntar os sub-vetores divididos por Merge Sort
void Merge(int *V, int inicio, int meio, int fim)
{
	int i, j, k;
	int n1, n2; //Tamanhos dos vetroes temporarios
	
	n1 = (meio - inicio)+1;
	n2 = fim - meio;
	
	//cria os vetores auxiliares - temporarios
	int esquerdo[n1];
	int direito[n2];
	
	//copia os dados para os arrays temporarios
	//esquerdo[] e direito[]
	for(i=0; i<n1; i++){
		esquerdo[i] = V[inicio+i];
	}
	
	for(j=0; j<n2; j++){
		direito[j] = V[meio + 1 + j];
	}
	
	//mescla os arrays temporarios de volta para o vetor original - [V]
	i=0; //Indice iniciol do primeiro subarray
	j=0; // indice incial do segundo subarry do lado direito
	k=inicio; //indice do subarray mesclado
	
	while(i < n1 && j < n2)
	{
		if(esquerdo[i] < direito[j])
		{
			V[k] = esquerdo[i];
			i++;
		}
		else
		{
			V[k] = direito[j];
			j++;	
		}
	k++;	
	}
	
	//copia os elementos restantes do vetor esquerdo[] se houver
	while(i < n1)
	{
		V[k] = esquerdo[i];
		i++;
		k++;
	}
	//copia os elementos restantes do vetor direito[] se houver
	while(j < n2)
	{
		V[k] = direito[j];
		k++;
		j++;
	}
}









