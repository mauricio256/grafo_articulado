#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	char nomeArquivo[60];
	char ext[4] = {".txt"};
    int matriz[5][5];
    int encontrados[6];
    int i, j;
    int continua; 
    int tot, vert, indice;
    
    bool verifica_encont(int x){
    	bool aux;
    	aux = false;
 		for (i=1; i<tot; i++){
 			if (x == encontrados[i]){  ///// percorre o vetor de encontrados, se encontrar o valor
			  							/// na posição i do vetor do encontrados[], aux recebe true. 
 				aux = true;
			 }
		 }
		 return aux;   		
	}
    
    
    
  	do{
  		system("cls");
		printf(" Digite o nome do arquivo: ");
		scanf("%s", nomeArquivo);
		
		strcat(nomeArquivo, ext); 	/// a funcao strcat cocaltena o valor da primeira variavel a segunda.
		
	    FILE *file;   ///cria ponteiro para um tipo de dados, padrÃ£o do C, do tipo file.
	    file = fopen( nomeArquivo,"r" ); /* A funcao fopen(), que estÃ¡ sendo atribuida ao ponteiro do tipo file,
										    abre o arquivo com o segundo atributo com letra "r" de read. O primeiro 
											atributo o caminho+nome+entensao do arquivo. */ 
											
	    if( file == NULL ){  //// verifica se o arquivo file pode ser lido
	    	system("cls");
	    	printf("\n Erro na leitura ou arquivo inexistente \n");
		}else{ 
	        for(i=1;i<6;i++){ //// percorre todo o arquivo lendo e atribuido a cada valor de i e j a matriz[][] em linhas e colunas   
	            for(j=1;j<6;j++){
	                fscanf(file,"%d",&matriz[i][j]);
	            }
	        }  
	        
	        
	        for(i=1;i<6;i++){
	        	encontrados[i] = 0;
			}

	        
	        
	        tot = 1;
	        indice = 0;
	        encontrados[tot] = 1;
	        
	        
	        
	        do { 
	        	indice = indice + 1;
	        	vert = encontrados[indice];
	        	for(j = 1; j<6; j++){
	        		if (matriz [vert,j] == 1  && verifica_encont(j) == false) { //// Percorre a matriz verificando se o vertice 
																		//// na posição [vert] e [J] (J que vai de 1 à 5) é igual a 1.
																		//// Se for e se a função "verifica_encont(j)" na posição J retornar falso,
																		///  ele adicionar o valor no array[] de encontrados. se retornar true é pq ja tem no vertor de encont     
						tot = tot + 1;
						encontrados[tot] = j;		
					}
				}	        
	        	
	        
			} while (indice != tot);		
				
		}/// fim do else
		
		for(i=1;i<6;i++){
					printf("[%d] ", encontrados[i]);
		}
		
		
			
	    printf("\n tecle 'Enter' para digitar um novo arquivo ou tecle 's' se para sair \n");
	    continua = getch();
	    
	}while (continua != 's'); 

	return 0;

}






