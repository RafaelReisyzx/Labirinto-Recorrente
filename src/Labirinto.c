#include "Labirinto.h"

void Initiation(Mapa *mat)
{

	int k,n=0,opcao;

	printf("\n******************************************************\n");	
	printf("-Menu-\n");
	printf("1-Gerar novas matrizes dentro de um arquivo (input.data)\n");
	printf("2-Ler matrizes de um arquivo (input.data)\n");
	printf("******************************************************\n");
	scanf("%d", &opcao);
	printf("\n");

		if(opcao == 1){
			printf("Digite o tamanho da matriz quadrada: ");
			scanf("%d", &n);
		for(k=0;k<QuantMatriz;k++){
			GenerateMatrix(n,k,mat);
			PrintMatrix(n,k,mat);
		}
		Jornada(n,QuantMatriz,mat);
	
		}		
		else if(opcao == 2){			
		ReadMatriz(mat);		
		}
		else if(opcao == 0){
		
		}
		else{
		printf("\nOpcao invalida\n");
		}

}

int GenerateMatrix(int n,int k,Mapa *mat){
	int i,j,data=0,data2=0;
	FILE *f = fopen("dataset/input.data", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(EXIT_FAILURE);
    }
 
    if(k==0)
    {
       fprintf(f, "%d %d %d\n",n, n,QuantMatriz);
   }
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			mat->Matrizes[k].caminho[i][j]='0';
			data = rand()%20;
        	if(data <= 10){     	
			mat->Matrizes[k].map[i][j] = (1 + rand()%5) + '0';
			 fprintf(f, "%c ", mat->Matrizes[k].map[i][j]);
		}else if ((data > 10) && (data < 16)){
			mat->Matrizes[k].map[i][j] = '*';
			 fprintf(f, "%c ", mat->Matrizes[k].map[i][j]);
		} else
		{
		
				if(i==0&&j==0&&k==0)
			{
			data2 = rand()%20;
			if(data2 <= 15){     	
			mat->Matrizes[k].map[i][j] = (1 + rand()%5) + '0';
			 fprintf(f, "%c ", mat->Matrizes[k].map[i][j]);
		}else if ((data2 > 15) && (data2 < 20)){
			mat->Matrizes[k].map[i][j] = '*';
			 fprintf(f, "%c ", mat->Matrizes[k].map[i][j]);

		}
			}else{
			mat->Matrizes[k].map[i][j] = '#';
			 fprintf(f, "%c ", mat->Matrizes[k].map[i][j]);
		}
		}
       
		}
		 fprintf(f, "\n");
		
	}
	fprintf(f, "\n");

    fclose(f);
 

	return 0;
}

void PrintMatrix(int n,int k,Mapa *mat){
	int i,j;
		printf("\nSala %d\n\n",k);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c ", mat->Matrizes[k].map[i][j]);
		}
		printf("\n");
	}

}


void ReadMatriz(Mapa *mat) {
    FILE *f = fopen("dataset/input.data", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        exit(EXIT_FAILURE);
    }

    int linhas = 0, colunas = 0, numeroMatrizes , i, j, k;
    char c;

    fscanf(f, "%d %d %d", &linhas, &colunas, &numeroMatrizes);

    for (k = 0; k < numeroMatrizes; k++) {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
            	mat->Matrizes[k].caminho[i][j]='0';
                c = fgetc(f);
                while (isspace(c)) {
                    c = fgetc(f);
                }
                if (c == '#') {
                    if (i == 0 && j == 0 && k == 0) {
                        int data = rand() % 20;
                        if (data <= 10) {     
                            mat->Matrizes[k].map[i][j] = (1 + rand() % 5) + '0';
                        } else if (data > 10 && data < 16) {
                            mat->Matrizes[k].map[i][j] = '*';
                        }
                    } else {
                        mat->Matrizes[k].map[i][j] = c;
                    }
                } else {
                    mat->Matrizes[k].map[i][j] = c;
                }
            }
        }
    }

    for (k = 0; k < QuantMatriz; k++) {
        PrintMatrix(linhas, k,mat);
    }

    fclose(f);
    Jornada(linhas,numeroMatrizes,mat);
}

int Jornada(int n,int tam,Mapa *mat)
{
    Personagem Garoto;
	int i=0,j=0,r=0,x=0,k=0,data=0,a,c,b,ok=0,opcao,visualizacao=0;
	int Direita=0,Esquerda=0,Baixo=0,Cima=0,DiagonalEsquerdaSuperior=0,DiagonalDireitaSuperior=0,DiagonalEsquerdaInferior=0,DiagonalDireitaInferior=0;
	Garoto.hp=10;
	Garoto.Inexplorado=0;
	Garoto.itens=0;
	Garoto.passos=0;
	Garoto.perigos=0;
	Garoto.sacola=0;
	mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
		printf("\nVisualizar Movimentos do Garoto?\n1-Sim\n2-Nao\n");
		scanf("%d", &opcao);
		if(opcao==1)
		{
			visualizacao=1;
		}else{
			visualizacao=0;
		}
		
			if(visualizacao==1){
		printf("\nCaminho\n");
		printf("\n-------------------------------------------");
		printf("\n |Sala [0]|\n ");
	}
	for(;;)
	{
	
	//1Â° Etapa Verificador de casa
	
		if(mat->Matrizes[k].map[i][j]=='*'){	
    		Garoto.hp=Garoto.hp-1;
    		Garoto.perigos=Garoto.perigos+1;
  
    		
    		if(Garoto.hp==0)	
	{
			printf("\n-------------------------------------------");
		 printf("\n\nO garoto nao conseguiu sobreviver dentro do Labirinto\n");
		 printf("\nDados da Jornada:\n");
		 printf("\nQuantidade de passos:%d ",Garoto.passos);
		 printf("\nQuantidade de itens consumidos:%d ",Garoto.itens);
		 printf("\nQuantidade de perigos enfrentados:%d ",Garoto.perigos);
		 	for(k = 0; k < QuantMatriz; k++){
		 		for(i = 0; i < n; i++){
		 		for(j = 0; j < n; j++){		 			
		 			if(mat->Matrizes[k].map[i][j]!='0'&&mat->Matrizes[k].map[i][j]!='#'&&mat->Matrizes[k].map[i][j]!='*')
		 			{
		 				Garoto.Inexplorado=Garoto.Inexplorado+1;					 }
				 
			}		 			
		 		}
		 		
		 	}
		 printf("\nQuantidade de casas Inexploradas :%d ",Garoto.Inexplorado);
		 Finalization(n,tam,mat);
		 		
		return 0;
     	
	}
	
    	}else if(mat->Matrizes[k].map[i][j]=='#'){
	}else if(mat->Matrizes[k].map[i][j]>'0'){
    	mat->Matrizes[k].map[i][j]=mat->Matrizes[k].map[i][j]-1;	
    	mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].caminho[i][j]-1;
    	Garoto.itens=Garoto.itens+1;
    	if(Garoto.sacola<4)
    	{
    	Garoto.sacola=Garoto.sacola+1;
    }
	   }else{
	   	if(Garoto.sacola<4)
    	{
    	Garoto.sacola=Garoto.sacola+1;
    }
	   }
	//2Â° EtapaVerificador de Sacola
	if(Garoto.sacola==4)
	{
		if(Garoto.hp<10)
		{
		  Garoto.hp=Garoto.hp+1;
	      Garoto.sacola=0;	
	      	if(visualizacao==1)
	      	printf("\n |Curou 1 de vida| ");
       }
	}
	//3Â° EtapaDemarcar Paredes
	//cima
	if(mat->Matrizes[k].map[i-1][j]=='#')
	{
		Cima=-1;
	}
	//baixo
	if(mat->Matrizes[k].map[i+1][j]=='#')
	{
		Baixo=-1;
	}
	//esquerda
	if(mat->Matrizes[k].map[i][j-1]=='#')
	{
		Esquerda=-1;
	}
	//direita
	if(mat->Matrizes[k].map[i][j+1]=='#')
	{
		Direita=-1;
	}
	//diagonal superior esquerda
	if(mat->Matrizes[k].map[i-1][j-1]=='#')
	{
		DiagonalEsquerdaSuperior=-1;
	}
	//diagonal superior direita
	if(mat->Matrizes[k].map[i-1][j+1]=='#')
	{
		DiagonalDireitaSuperior=-1;
	}
	//diagonal inferior esquerda
	if(mat->Matrizes[k].map[i+1][j-1]=='#')
	{
		DiagonalEsquerdaInferior=-1;
	}
	//diagonal inferior direita
	if(mat->Matrizes[k].map[i+1][j+1]=='#')
	{
		DiagonalDireitaInferior=-1;
	}
//4Â° Etapa Escolher caminho possivel de caminhar
	for(r=0;r<1;)
	{
	data = rand()%8;
	if(data==1&&Cima!=-1&&i>0)
	{
    r=1;
	}else if(data==2&&Baixo!=-1&&i<n-1){
	r=1;
	}else if(data==3&&Esquerda!=-1&&j>0){
	r=1;		
	}else if(data==4&&Direita!=-1&&j<n-1){
	r=1;
	}else if(data==5&&DiagonalDireitaSuperior!=-1&&i>0&&j<n-1){
	r=1;	
	}else if(data==6&&DiagonalEsquerdaSuperior!=-1&&i>0&&j>0){
	r=1;
	}else if(data==7&&DiagonalDireitaInferior!=-1&&i<n-1&&j<n-1){
	r=1;		
	}else if(data==8&&DiagonalEsquerdaInferior!=-1&&i<n-1&&j>0){
	r=1;	
	}	
   }
   //5Â° Etapa Caminhar
	
	if(data==1)
	{
		i=i-1;
		Garoto.passos=Garoto.passos+1;
		mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
			if(visualizacao==1)
			printf("\n |Cima [%c]| ", mat->Matrizes[k].map[i][j]);


	}else if(data==2){
	
		i=i+1;
		Garoto.passos=Garoto.passos+1;
		mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
			if(visualizacao==1)
		printf("\n |Baixo [%c]| ", mat->Matrizes[k].map[i][j]);

	}else if(data==3){
		
		j=j-1;
		Garoto.passos=Garoto.passos+1;
		mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
			if(visualizacao==1)
		printf("\n |Esquerda [%c]| ", mat->Matrizes[k].map[i][j]);

	}else if(data==4){
		j=j+1;
		Garoto.passos=Garoto.passos+1;
		mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
			if(visualizacao==1)
		printf("\n |Direita [%c]| ", mat->Matrizes[k].map[i][j]);

	}else if(data==5)
	{
		i=i-1;
		j=j+1;
		Garoto.passos=Garoto.passos+1;
		mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
			if(visualizacao==1)
		printf("\n |Diagonal Direita Superior [%c]| ", mat->Matrizes[k].map[i][j]);

	}else if(data==6){
		i=i-1;
		j=j-1;
		Garoto.passos=Garoto.passos+1;
		mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
			if(visualizacao==1)
		printf("\n |Diagonal Esquerda Superior [%c]| ", mat->Matrizes[k].map[i][j]);
	
	}else if(data==7){
	    i=i+1;
	    j=j+1;
	    Garoto.passos=Garoto.passos+1;
	    mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
	    	if(visualizacao==1)
	   	printf("\n |Diagonal Direita Inferior [%c]| ", mat->Matrizes[k].map[i][j]);
	
		
	}else if(data==8){
		i=i+1;
		j=j-1;
		Garoto.passos=Garoto.passos+1;
		mat->Matrizes[k].caminho[i][j]=mat->Matrizes[k].map[i][j];
			if(visualizacao==1)
		printf("\n |Diagonal Esquerda Inferior [%c]| ", mat->Matrizes[k].map[i][j]);
	}else
	{
		
	}
		Cima=0;
		Baixo=0;
		Direita=0;
		Esquerda=0;
		DiagonalDireitaSuperior=0;
		DiagonalEsquerdaSuperior=0;
		DiagonalDireitaInferior=0;
		DiagonalEsquerdaInferior=0;
		r=0;
	

	//6Â° Etapa Verificador de Portal
	if(i==0){
	
	data = rand()%tam;	
	x=k;
	k=data;
		if(visualizacao==1)
		printf("\n-------------------------------------------");	
			if(visualizacao==1){
				printf("\n\n |Passou para a sala %d| \n", data);
			}

	if(mat->Matrizes[k].map[i][j]=='#')
	{
	k=x;	
		if(visualizacao==1)
		printf("\n |O caminho estava bloqueado, voltou para a sala %d| \n", k);	
			
	}
				
	}else if(j==0){

	data = rand()%tam;	
	x=k;
	k=data;
		if(visualizacao==1){
		printf("\n-------------------------------------------");
			printf("\n\n |Passou para a sala %d| \n", data);
		}

	
	if(mat->Matrizes[k].map[i][j]=='#')
	{
	k=x;
		if(visualizacao==1)
			printf("\n |O caminho estava bloqueado, voltou para a sala %d| \n", k);		
	}
	}else if(i==n){

	data = rand()%tam;	
	x=k;
	k=data;
		if(visualizacao==1){
			printf("\n-------------------------------------------");	
			printf("\n\n |Passou para a sala %d| \n", data);
		}

	
	if(mat->Matrizes[k].map[i][j]=='#')
	{
	k=x;
		if(visualizacao==1)
		printf("\n |O caminho estava bloqueado, voltou para a sala %d| \n", k);		
	}

	}else if(j==n){
		
	data = rand()%tam;	
	x=k;
	k=data;
		if(visualizacao==1){
			printf("\n-------------------------------------------");	
			printf("\n\n |Passou para a sala %d| \n", data);
		}

	
	if(mat->Matrizes[k].map[i][j]=='#')
	{
	k=x;
		if(visualizacao==1)
		printf("\n |O caminho estava bloqueado, voltou para a sala %d| \n", k);		
	}
	
	}

	//7Â° Etapa Verificar se estÃ¡ no inicio
	if(i==0&&j==0)
	{
		ok=1;
		for(a = 0; a < tam; a++){
		for(b = 0; b < n; b++){
		for(c = 0; c < n; c++){
		if(mat->Matrizes[a].caminho[b][c]!='0')
		{
				if(mat->Matrizes[a].caminho[b][c]!='*')
				{					
					ok=0;	
				}

		}	
			
		}}}
		
		if(ok==1)
		{
		 printf("\n-------------------------------------------");
		 printf("\n\nO garoto terminou a jornada com vida\n");
		 printf("\nDados da Jornada:\n");
		 printf("\nQuantidade de passos:%d ",Garoto.passos);
		 printf("\nQuantidade de itens consumidos:%d ",Garoto.itens);
		 printf("\nQuantidade de perigos enfrentados:%d ",Garoto.perigos);
		 	for(k = 0; k < tam; k++){
		 		for(i = 0; i < n; i++){
		 		for(j = 0; j < n; j++){		 			
		 			if(mat->Matrizes[k].map[i][j]!='0'&&mat->Matrizes[k].map[i][j]!='#'&&mat->Matrizes[k].map[i][j]!='*')
		 			{
		 				Garoto.Inexplorado=Garoto.Inexplorado+1;					 
						 }
				 
			}		 			
		 		}
		 		
		 	}
		 printf("\nQuantidade de casas Inexploradas :%d ",Garoto.Inexplorado);
			Finalization(n,tam,mat);
		 		 
		 return 0;
		}
	}
	
	
		}
	
	
}

void Finalization(int n,int tam,Mapa *mat)
{
	int k,i,j;
	FILE *g = fopen("dataset/output.data", "a");
    if (g == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(EXIT_FAILURE);
    }
	
	printf("\nMapa Atualizado:\n\n");
	for(k = 0;k < tam; k++){
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c ", mat->Matrizes[k].map[i][j]);
			 fprintf(g, "%c ", mat->Matrizes[k].map[i][j]);
		}
		printf("\n");
		 fprintf(g, "\n");
	}
		printf("\n");
		 fprintf(g, "\n");
	}
	
	
}


	




