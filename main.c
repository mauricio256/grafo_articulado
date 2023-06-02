#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	char nomeArquivo[60];
	char ext[4] = {".txt"};
    int matriz[5][5];
    int matriz_sec[5][5];
    int encontrados[6];
    int i, j;
    int continua; 
    int tot, vert, indice;
    
    
    
    
    bool verifica_encont(int j){
    	bool aux;
    	aux = false;
 		for (i=1; i<6; i++){
 			if (j == encontrados[i]){  ///// percorre o vetor de encontrados, se encontrar o valor
			  							/// na posiÁ„o i do vetor do encontrados[], aux recebe true. 
 				aux = true;
			 }
		 }
		 return aux;   		
	}
	
	
	
	
	
	
	
	
	int verifica_caminhos(int matriz[5][5]){
		int cont;
		tot = 1;
	    indice = 0;
	    encontrados[tot] = 1;
	        
	    do { 
	        indice++;
	        for(j = 1; j<6; j++){
	        	if (matriz[indice][j] == 1 && !verifica_encont(j) ) { //// Percorre a matriz verificando se o vertice 
																				//// na posiÁ„o [vert] e [J] (J que vai de 1 ‡ 5) È igual a 1.
																				//// Se for e se a funÁ„o "verifica_encont(j)" na posiÁ„o J retornar falso,
																				///  ele adicionar o valor no array[] de encontrados. se retornar true È pq ja tem no vertor de encont     
					tot++;
					encontrados[tot] = j;		
				}	
			}	 
				
		} while (indice != tot);	
			
		return	encontrados[indice]; /// retorna o valor do array de encontrado na ultima possiÁ„o em que 
									///	 encontrou um vertice (identificado por indice).
	}
    
    
    
    
    
    
    
    bool verifica_articulacao(int zera_vert, int matriz_sec[5][5]){
				
		for(i=1;i<6;i++){
		    for(j=1;j<6;j++){
		        if(i != zera_vert && j != zera_vert){
		            matriz_sec[i][zera_vert] = 0;
		            matriz_sec[zera_vert][j] = 0;					
				} 	
		    }
		}
	
		if (verifica_caminhos(matriz_sec) < 4){
			printf(" [%d] -> E articulacao \n", zera_vert);
		}	
				
	}
	
	
	
	
	
	
	
	
    

    
    
  	do{
  		system("cls");
		printf(" Digite o nome do arquivo: ");
		scanf("%s", nomeArquivo);
		
		strcat(nomeArquivo, ext); 	/// a funcao strcat cocaltena o valor da primeira variavel a segunda.
		
	    FILE *file;   ///cria ponteiro para um tipo de dados, padr√£o do C, do tipo file.
	    file = fopen( nomeArquivo,"r" ); /* A funcao fopen(), que est√° sendo atribuida ao ponteiro do tipo file,
										    abre o arquivo com o segundo atributo com letra "r" de read. O primeiro 
											atributo o caminho+nome+entensao do arquivo. */ 
											
	    if( file == NULL ){  //// verifica se o arquivo file pode ser lido
	    	system("cls");
	    	printf("\n Erro na leitura ou arquivo inexistente \n");
		}else{ 
	        for(i=1;i<6;i++){ //// percorre todo o arquivo lendo e atribuido a cada valor de i e j a matriz[][] em linhas e colunas   
	            for(j=1;j<6;j++){
	                fscanf(file,"%d",&matriz[i][j]);
	            	matriz_sec[i][j] = matriz[i][j];
				}
	        } 
	        
	        
	        //int cont = 2;
	       // while(cont<6){
	        	 verifica_articulacao(5, matriz_sec);
			//	 cont++;	
			//}
	       
	        
     		
		}/// fim do else		
	    printf("\n tecle 'Enter' para digitar um novo arquivo ou tecle 's' se para sair \n");
	    continua = getch();
	    
	}while (continua != 's'); 

	return 0;

}






