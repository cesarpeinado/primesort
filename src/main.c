#include <stdio.h>
#include <unistd.h> // Permite a criacao de pipes

/* Funcao que reconhece se um inteiro eh primo */
int ehprimo(int numero){
	int i, primo=1;
	int flag=1; // Flag inicia em 1 (o divisor considerado se refere ao proprio numero n) para otimizar o codigo sem precisar percorrer todos os numeros de 1 a n, mas sim ate a metade

	if(numero == 0 || numero == 1){
		primo=0;
		return primo;
	}
	if (numero == 2 || numero == 3){
		primo=1;
		return primo;
	}

	for(i=1; i<=(numero/2); i++){
    		if(numero%i == 0){
        		flag++;
	
			if(flag>2){
				primo=0;
				return primo;
			}
        	}
	}

return primo;
}

int main (){

	int entrada, continua=1;
	FILE *respostas;    
    
	respostas = popen("sort -n -r", "w"); // Abre um arquivo para escrita

	while(continua){
        
        	scanf("%d\n", &entrada);
        
        	if(entrada == -1) // Indica o fim das entradas
        		continua=0;

        	else{
        		if(ehprimo(entrada) == 0){ // Confere se a entrada eh um numero nao primo
        			fprintf(respostas, "%d\n", entrada); // Escreve no arquivo
			}
		}
	}

pclose(respostas); // Fecha o arquivo

return 0;
}
