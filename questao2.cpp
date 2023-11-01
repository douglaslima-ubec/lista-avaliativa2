#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	
	char nome[30];
	double forca;
	
	typedef struct{
		char posicao[6];
		int limite[6];
	} pos;
	
	const pos posicoes = {{'G','L','Z','V','M','A'},{1,2,2,2,2,2}};
	
	typedef struct{
		char nome[30];
		char posicao;
		int forca;
	} jogador;
	
	jogador jogadores[11];
	
} time;

double calculaForca(time time){
	
	int soma[6] = {0,0,0,0,0,0};
	
	for(int i=0;i<11;i++){
		for(int j=0;j<6;j++){
			if(time.jogadores[i].posicao == time.posicoes.posicao[j]){
				soma[j] += time.jogadores[i].forca;
			}
		}
	}
	
	int peso[6] = {8,10,5,8,11,12};
	int temp = 0;
	
	for(int i=0;i<6;i++){
		temp += peso[i]*soma[i];
	}
	
	double forca = (double) temp/100;
		
	return forca;
}

time leEntrada(){
	
	time time;
	scanf(" %[a-zA-Z ]",&time.nome);
	
	int posicaoQtd[6] = {0,0,0,0,0,0};
	
	for(int i=0;i<11;i++){
		scanf("%*[\n]%[^;]%*;%c%*;%d",&time.jogadores[i].nome,&time.jogadores[i].posicao,&time.jogadores[i].forca);
		
		for(int j=0;j<6;j++){
			if(time.jogadores[i].posicao == time.posicoes.posicao[j]){
				posicaoQtd[j]++;
				if(posicaoQtd[j]>time.posicoes.limite[j]){
					printf("\n\nERROR => You inserted more players than what's allowed for position '%c'!",time.jogadores[i].posicao);
					printf("\nPositions:\n\t'G': 1 player\n\t'L': 2 players\n\t'Z': 2 players\n\t'V': 2 players\n\t'M': 2 players\n\t'A': 2 players\n");
					exit(0);
				}
			}
		}
		
	}
	
	time.forca = calculaForca(time);
	
	return time;
}

int main(){
	
	time time1 = leEntrada();
	time time2 = leEntrada();
	
	printf("%s: %.2f de forca\n",time1.nome,time1.forca);
	printf("%s: %.2f de forca\n",time2.nome,time2.forca);
	
	if(time1.forca>time2.forca){
		printf("%s eh mais forte\n",time1.nome);
	}else{
		printf("%s eh mais forte\n",time2.nome);
	}
	
	return 0;
}
