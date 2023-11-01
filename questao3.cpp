#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **leEntrada(){
	
	//cria uma matriz com alocação dinâmica de memória
	int lin = 4;
	int col = 4;
	int **matriz;
	matriz = (int **) malloc(lin * sizeof(int *)); //32 bytes
	for(int i=0;i<lin;i++){
		matriz[i] = (int *) malloc(col * sizeof(int)); //16bytes
	}
	
	//lê os elementos da matriz
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&matriz[i][j]);
		}
	}
	
	return matriz;
}

void exibeMatriz(int **matriz){
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%4d",matriz[i][j]);
		}
		printf("\n");
	}
}

int **soma(int **A,int **B){
	
	//cria a matriz C
	int **C;
	C = (int **) malloc(4 * sizeof(int*)); // 32 bytes
	for(int i=0;i<4;i++){
		C[i] = (int *) malloc(4 * sizeof(int));
	}
	
	//soma as matrizes e guarda o resultado em C
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	
	return C;
}


int **sub(int **A,int **B){
	
	//cria a matriz C
	int **C;
	C = (int **) malloc(4 * sizeof(int*)); // 32 bytes
	for(int i=0;i<4;i++){
		C[i] = (int *) malloc(4 * sizeof(int));
	}
	
	//subtrai as matrizes e guarda o resultado em C
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	
	return C;
}

int **mult(int **A,int **B){
	
	//cria a matriz C
	int **C;
	C = (int **) malloc(4 * sizeof(int *));
	for(int i=0;i<4;i++){
		C[i] = (int *) malloc(4 * sizeof(int));
	}
	
	//multiplica as matrizes e guarda o resultado em C
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){

			int aux = 0;
			int count=0;
			while(count<4){
				aux += A[i][count] * B[count][j];
				count++;
			}
			C[i][j] = aux;
		}
	}

	return C;
}

int main(){

	int **matriz1 = leEntrada();
	int **matriz2 = leEntrada();
	
	char operacao[4];
	scanf("%4s",&operacao);
	
	if(strcmp(operacao,"soma") == 0){
			exibeMatriz(soma(matriz1,matriz2));
	}
	if(strcmp(operacao,"sub") == 0){
			exibeMatriz(sub(matriz1,matriz2));
	}
	if(strcmp(operacao,"mult") == 0){
			exibeMatriz(mult(matriz1,matriz2));
	}

	return 0;
}
