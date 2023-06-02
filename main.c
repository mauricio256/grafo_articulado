#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	char nomeArquivo[20];
	char ext[4] = {".txt"};
    int matriz[7][7];
    int matriz_sec[7][7];
    int encontrados[7];
    int i, j;
    int continua; 
    int tot, vert, indice;
    
    
    
    bool verifica_encont(int j){
    	bool aux;
    	aux = false;
 		for (i=1; i<8; i++){
 			if (j == encontrados[i]){  ///// percorre o vetor de encontrados, se encontrar o valor
			  							/// na posição i do vetor do encontrados[], aux recebe true. 
 				aux = true;
			 }
		 }
		 return aux;   		
	}
	
	

	
	int verifica_caminhos(int matriz[7][7]){
		tot = 1; 	//// define onde está a possição do vetor de encontrados
	    indice = 0;		 /// a linha que ele vai verificar se tem ligaçoes
	    encontrados[tot] = 1; 
	        
	    do { 
	        indice++;
	        for(j = 1; j<8; j++){
	        	if (matriz[indice][j] == 1 && !verifica_encont(j) ) { //// Percorre a matriz verificando se o vertice 
																	//// na posição [vert] e [J] (J que vai de 1 à 5) é igual a 1.
																	//// Se for e se a função "verifica_encont(j)" na posição J retornar falso,
																	// é porque ele ainda nao ta no vetor[] de encontrados então
																	///  ele adicionar o valor no vetor[] de encontrados. se retornar true é pq ja tem no vertor     
					tot++;
					encontrados[tot] = j;		
				}	
			}	 
				
		} while (indice != tot);	
			
		return	encontrados[indice]; /// retorna o valor do array de encontrado na ultima possição em que 
									///	 encontrou um vertice (identificado por indice).
	}
    
    
 
    
    /// essa função abaixo recebe a matriz principal e a secundaria 0 a linha definida na variavel zera_vert
    //  e verifica com a função verifica_caminhos(matriz_sec) se esse vertice tirado era articulação
 
    bool verifica_articulacao(int zera_vert, int matriz_sec[7][7], int matriz[7][7]){
				
		for(i=1;i<8;i++){
		    for(j=1;j<8;j++){
		        if(i != zera_vert && j != zera_vert){
		            matriz_sec[i][zera_vert] = 0;
		            matriz_sec[zera_vert][j] = 0;					
				} 	
		    }
		}
	
		if (verifica_caminhos(matriz_sec) < 4){
			printf(" [%d] -> E articulacao \n \n", zera_vert);
		}
		
		
		for(i=1;i<8;i++){ //// Devolve os valores originais a matriz secundaria com os valores da matriz principal
		    for(j=1;j<8;j++){
		    	matriz_sec[i][j] = matriz[i][j];
		        ///printf("[%d]", matriz_sec[i][j] );
		    }
			printf("\n");	
		}		
			
	}
	

    
  	do{
  		system("cls");
		printf(" Digite o nome do arquivo: ");
		scanf("%s", nomeArquivo);
		
		strcat(nomeArquivo, ext); 	/// a funcao strcat cocaltena o valor da primeira variavel a segunda.
		
	   /// FILE *file;   ///cria ponteiro para um tipo de dados, padrÃ£o do C, do tipo file.
	    FILE *file = fopen( nomeArquivo,"r" ); /* A funcao fopen(), que estÃ¡ sendo atribuida ao ponteiro do tipo file,
										    abre o arquivo com o segundo atributo com letra "r" de read. O primeiro 
											atributo o caminho+nome+entensao do arquivo. */ 
											
	    if (file == NULL) {  //// verifica se o arquivo file pode ser lido
	    	system("cls");
	    	printf("\n Erro na leitura ou arquivo inexistente \n");
	    	
		}else{
		
	        for(i=1;i<8;i++){ //// percorre todo o arquivo lendo e atribuido a cada valor de i e j a matriz[][] em linhas e colunas   
	            for(j=1;j<8;j++){
	                fscanf(file,"%d",&matriz[i][j]);
	            	matriz_sec[i][j] = matriz[i][j];
				}
	        } 
	     	    
	        

		   	verifica_articulacao(5, matriz_sec, matriz);

		fclose(file);
		}/// fim do else		
	    printf("\n tecle 'Enter' para digitar um novo arquivo ou tecle 's' se para sair \n");
	    continua = getch();
	    
	    
	}while (continua != 's'); 

	return 0;

}






