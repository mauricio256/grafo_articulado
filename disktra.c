void dijkstra(int vertices,int origem,int destino,int *custos)
{ int i,v,    /* vari�veis auxiliares */
      ant[MAXVERTICES],   /* vetor dos antecessores */
      z[MAXVERTICES];     /* v�rtices para os quais se conhece o caminho m�nimo */
  double min, /* vari�vel auxiliar */
       dist[MAXVERTICES]; /* vetor com os custos dos caminhos */

/* OBS: O usu�rio enxerga os v�rtices como rotulados de 1 a "v�rtices",  */
/* mas o programa armazena as informa��es usando os elementos 0 dos */
/* dos vetores. Dessa formar � preciso subtrair 1 de "origem" e "destino" */
/* ao mape�-los nos vetores. */

  /* Inicializa��o */

  for (i=0;i<vertices;i++) {
    if (custos[(origem-1)*vertices+i]!=-1) {
      ant[i]=origem-1; 
      dist[i]=custos[(origem-1)*vertices+i];
    }
    else {
      ant[i]=-1;
      dist[i]=HUGE_VAL;
    }
    z[i]=0;
  }
  z[origem-1]=1;
  dist[origem-1]=0;

  /* La�o principal */

  do {

    /* Encontrando o v�rtice que deve entrar em z */

    min=HUGE_VAL;
    for (i=0;i<vertices;i++)
      if (!z[i])
        if (dist[i]>=0 && dist[i]<min) {min=dist[i];v=i;}

    /* Calculando as dist�ncias dos novos vizinhos de z */

    if (min!=HUGE_VAL && v!=destino-1) {
      z[v]=1;
      for (i=0;i<vertices;i++)
        if (!z[i]) {
          if (custos[v*vertices+i]!=-1 && dist[v]+custos[v*vertices+i]<dist[i])
            { dist[i]=dist[v]+custos[v*vertices+i];ant[i]=v; }
        }
    }
  } while (v!=destino-1 && min!=HUGE_VAL);

  /* Imprimindo o resultado  */

  if (min==HUGE_VAL)
    printf("\nNo digrafo dado n�o existe caminho entre os v�rtices %d e %d !!\n",origem,destino);
  else {
    printf("\nO caminho de custo m�nimo entre os v�rtices %d e %d  � (na ordem reversa):\n",
           origem,destino);
    i=destino;
    printf("%d",i);
    i=ant[i-1];
    while (i!=-1) {
      printf("<-%d",i+1);
      i=ant[i];
    }
    printf("\nO custo deste caminho �: %d\n",(int) dist[destino-1]);
  }
  
} /* dijsktra */

