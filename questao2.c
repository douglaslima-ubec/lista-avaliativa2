#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct posicoes{
	char posicao[6];
	int limite[6];
};

struct jogador{
	char nome[30];
	char posicao;
	int forca;
};
	
typedef struct time{
	char nome[30];
	double forca;
	struct posicoes posicoes;	
	struct jogador jogadores[11];
} time;

double calculaForca(time time){
	
	int i;
	int j;
	int soma[6] = {0,0,0,0,0,0};
	int peso[6] = {8,10,5,8,11,12};
	int temp = 0;
	double forca;
	
	for(i=0;i<11;i++){
		for(j=0;j<6;j++){
			if(time.jogadores[i].posicao == time.posicoes.posicao[j]){
				soma[j] += time.jogadores[i].forca;
			}
		}
	}
	
	for(i=0;i<6;i++){
		temp += peso[i]*soma[i];
	}
	
	forca = (double) temp/100;
	
	return forca;
}

time leEntrada(){
	
	int i;
	int j;
	
	time time;
	scanf("\n%[^\n]",time.nome);
	
	char posicoes[6] = {'G','L','Z','V','M','A'};
	int limite[6] = {1,2,2,2,2,2};
	
	for(i=0;i<6;i++){
		time.posicoes.posicao[i] = posicoes[i];
		time.posicoes.limite[i] = limite[i];
	}
	
	int posicaoQtd[6] = {0,0,0,0,0,0};
	
	for(i=0;i<11;i++){
		
		scanf("\n%[^;];%c;%d",time.jogadores[i].nome,&time.jogadores[i].posicao,&time.jogadores[i].forca);
		
		for(j=0;j<6;j++){
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

void exibeTime(time time){
	printf("\n-----%s\n",time.nome);
	int i;
	for(i=0;i<11;i++){
        printf("\n-----%s %c %d\n",time.jogadores[i].nome,time.jogadores[i].posicao,time.jogadores[i].forca);
    }
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
