#include <stdio.h>
#include <stdlib.h>

void somarConjunto(int conjunto[],int conjuntoTamanho){
	
	int i;
	
	for(i=0;i<conjuntoTamanho;i++){
		printf("%d",conjunto[i]);
		if(i < conjuntoTamanho-1){
			printf(" ");
		}
	}
	printf("\n");
	
	int subConjuntoTamanho = conjuntoTamanho-1;
	int subConjunto[subConjuntoTamanho];
	for(i=0;i<subConjuntoTamanho;i++){
		subConjunto[i] = conjunto[i]+conjunto[i+1];
	}
	
	if(subConjuntoTamanho > 0){
		somarConjunto(subConjunto,subConjuntoTamanho);
	}
}

int main(){
	
	int i;
	int conjunto[10] = {0,0,0,0,0,0,0,0,0,0};
	
	for(i=0;i<10;i++){
		scanf("%d",&conjunto[i]);
	}

	somarConjunto(conjunto,10);
	
	return 0;
}
