#include "Labirinto.h"

int Initiation()
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
			srand(time(NULL));
		for(k=0;k<QuantMatriz;k++){
			GenerateMatrix(n,k);
			PrintMatrix(n,k);
		}
		Jornada(n,QuantMatriz);
	
		}		
		else if(opcao == 2){			
		ReadMatriz();		
		}
		else if(opcao == 0){
			return 0;
		}
		else{
		printf("\nOpção inválida\n");
		}

}

int GenerateMatrix(int n,int k){
	int i,j,data=0,data2=0;
	FILE *f = fopen("dataset/input.data", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(EXIT_FAILURE);
    }
 
    if(k==0)
    {
       fprintf(f, "%d %d %d\n",n, n,k);
   }
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			Matrizes[k].caminho[i][j]='0';
			data = rand()%20;
        	if(data <= 10){     	
			Matrizes[k].matrix[i][j] = (1 + rand()%5) + '0';
			 fprintf(f, "%c ", Matrizes[k].matrix[i][j]);
		}else if ((data > 10) && (data < 16)){
			Matrizes[k].matrix[i][j] = '*';
			 fprintf(f, "%c ", Matrizes[k].matrix[i][j]);
		} else
		{
				if(i==0&&j==0&&k==0)
			{
			data2 = rand()%20;
			if(data2 <= 15){     	
			Matrizes[k].matrix[i][j] = (1 + rand()%5) + '0';
			 fprintf(f, "%c ", Matrizes[k].matrix[i][j]);
		}else if ((data2 > 15) && (data2 < 20)){
			Matrizes[k].matrix[i][j] = '*';
			 fprintf(f, "%c ", Matrizes[k].matrix[i][j]);

		}
			}else{
			Matrizes[k].matrix[i][j] = '#';
			 fprintf(f, "%c ", Matrizes[k].matrix[i][j]);
		}
		}
       
		}
		 fprintf(f, "\n");
		
	}
	fprintf(f, "\n");

    fclose(f);
 

	return 0;
}

void PrintMatrix(int n,int k){
	int i,j;
		printf("\nMatriz %d\n\n",k+1);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c ", Matrizes[k].matrix[i][j]);
		}
		printf("\n");
	}

}


void ReadMatriz() {
    FILE *f = fopen("dataset/input.data", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        exit(EXIT_FAILURE);
    }

    int linhas = 0, colunas = 0, numeroMatrizes = 0, i, j, k;
    char c;

    fscanf(f, "%d %d %d", &linhas, &colunas, &numeroMatrizes);

    for (k = 0; k < numeroMatrizes; k++) {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
            	Matrizes[k].caminho[i][j]='0';
                c = fgetc(f);
                while (isspace(c)) {
                    c = fgetc(f);
                }
                if (c == '#') {
                    if (i == 0 && j == 0 && k == 0) {
                        int data = rand() % 20;
                        if (data <= 10) {     
                            Matrizes[k].matrix[i][j] = (1 + rand() % 5) + '0';
                        } else if (data > 10 && data < 16) {
                            Matrizes[k].matrix[i][j] = '*';
                        }
                    } else {
                        Matrizes[k].matrix[i][j] = c;
                    }
                } else {
                    Matrizes[k].matrix[i][j] = c;
                }
            }
        }
    }

    for (k = 0; k < QuantMatriz; k++) {
        PrintMatrix(linhas, k);
    }

    fclose(f);
    Jornada(linhas,numeroMatrizes);
}

int Jornada(int n,int tam)
{
    
	Personagem Garoto;
	int i=0,j=0,r=0,x=0,y=0,z=0,k=0,data=0,a,b,c,ok=0,opcao;
	int Direita=0,Esquerda=0,Baixo=0,Cima=0,DiagonalEsquerdaSuperior=0,DiagonalDireitaSuperior=0,DiagonalEsquerdaInferior=0,DiagonalDireitaInferior=0;
	Garoto.hp=10;
	Garoto.Inexplorado=0;
	Garoto.itens=0;
	Garoto.passos=0;
	Garoto.perigos=0;
	Garoto.sacola=0;
	Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
	
	for(;;)
	{
		
	//Verificador de casa
	
		if(Matrizes[k].matrix[i][j]=='*'){	
    		Garoto.hp=Garoto.hp-1;
    		Garoto.perigos=Garoto.perigos+1;
  
    		
    		if(Garoto.hp==0)	
	{
		 printf("\n\nO garoto não conseguiu sobreviver dentro do Labirinto\n");
		 printf("\nDados da Jornada:\n");
		 printf("\nQuantidade de passos:%d ",Garoto.passos);
		 printf("\nQuantidade de itens consumidos:%d ",Garoto.itens);
		 printf("\nQuantidade de perigos enfrentados:%d ",Garoto.perigos);
		 	for(k = 0; k < QuantMatriz; k++){
		 		for(i = 0; i < n; i++){
		 		for(j = 0; j < n; j++){		 			
		 			if(Matrizes[k].matrix[i][j]!='0'&&Matrizes[k].matrix[i][j]!='#'&&Matrizes[k].matrix[i][j]!='*')
		 			{
		 				Garoto.Inexplorado=Garoto.Inexplorado+1;					 }
				 
			}		 			
		 		}
		 		
		 	}
		 printf("\nQuantidade de casa Inexploradas :%d ",Garoto.Inexplorado);
		 		
		return 0;
     	
	}
	
    	}else if(Matrizes[k].matrix[i][j]=='#'){
    		printf("\nO garoto entrou na backroom");
	}else if(Matrizes[k].matrix[i][j]>'0'){
    	Matrizes[k].matrix[i][j]=Matrizes[k].matrix[i][j]-1;	
    	Matrizes[k].caminho[i][j]=Matrizes[k].caminho[i][j]-1;
    	Garoto.itens=Garoto.itens+1;
    	Garoto.sacola=Garoto.sacola+1;
	   }else{
	   	Garoto.sacola=Garoto.sacola+1;
	   }
	//Verificador de Sacola
	if(Garoto.sacola==4)
	{
		if(Garoto.hp<10)
		{
		  Garoto.hp=Garoto.hp+1;
	      Garoto.sacola=0;	
       }
	}
	
	//Demarcar Paredes
	//cima
	if(Matrizes[k].matrix[i-1][j]=='#')
	{
		Cima=-1;
	}
	//baixo
	if(Matrizes[k].matrix[i+1][j]=='#')
	{
		Baixo=-1;
	}
	//esquerda
	if(Matrizes[k].matrix[i][j-1]=='#')
	{
		Esquerda=-1;
	}
	//direita
	if(Matrizes[k].matrix[i][j+1]=='#')
	{
		Direita=-1;
	}
	//diagonal superior esquerda
	if(Matrizes[k].matrix[i-1][j-1]=='#')
	{
		DiagonalEsquerdaSuperior=-1;
	}
	//diagonal superior direita
	if(Matrizes[k].matrix[i-1][j+1]=='#')
	{
		DiagonalDireitaSuperior=-1;
	}
	//diagonal inferior esquerda
	if(Matrizes[k].matrix[i+1][j-1]=='#')
	{
		DiagonalEsquerdaInferior=-1;
	}
	//diagonal inferior direita
	if(Matrizes[k].matrix[i+1][j+1]=='#')
	{
		DiagonalDireitaInferior=-1;
	}
//Escolher caminho possivel de caminhar
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
   //Caminhar
	
	if(data==1)
	{
		i=i-1;
		Garoto.passos=Garoto.passos+1;
		Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
			printf("\n |Cima [%c]| ", Matrizes[k].matrix[i][j]);


	}else if(data==2){
	
		i=i+1;
		Garoto.passos=Garoto.passos+1;
		Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
		printf("\n |Baixo [%c]| ", Matrizes[k].matrix[i][j]);

	}else if(data==3){
		
		j=j-1;
		Garoto.passos=Garoto.passos+1;
		Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
		printf("\n |Esquerda [%c]| ", Matrizes[k].matrix[i][j]);

	}else if(data==4){
		j=j+1;
		Garoto.passos=Garoto.passos+1;
		Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
		printf("\n |Direita [%c]| ", Matrizes[k].matrix[i][j]);

	}else if(data==5)
	{
		i=i-1;
		j=j+1;
		Garoto.passos=Garoto.passos+1;
		Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
		printf("\n |Diagonal Direita Superior [%c]| ", Matrizes[k].matrix[i][j]);

	}else if(data==6){
		i=i-1;
		j=j-1;
		Garoto.passos=Garoto.passos+1;
		Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
		printf("\n |Diagonal Esquerda Superior [%c]| ", Matrizes[k].matrix[i][j]);
	
	}else if(data==7){
	    i=i+1;
	    j=j+1;
	    Garoto.passos=Garoto.passos+1;
	    Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
	   	printf("\n |Diagonal Direita Inferior [%c]| ", Matrizes[k].matrix[i][j]);
	
		
	}else if(data==8){
		i=i+1;
		j=j-1;
		Garoto.passos=Garoto.passos+1;
		Matrizes[k].caminho[i][j]=Matrizes[k].matrix[i][j];
		printf("\n |Diagonal Esquerda Inferior [%c]| ", Matrizes[k].matrix[i][j]);
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
	

	//Verificador de Portal
	if(i==0){
	
	data = rand()%tam;	
	x=k;
	k=data;

	if(Matrizes[k].matrix[i][j]=='#')
	{
	k=x;
			
	}
	printf("\n-------------------------------------------");	
		printf("\n\n |Teletransportou para a sala %d| \n", data);				
	}else if(j==0){

	data = rand()%tam;	
	x=k;
	k=data;

	
	if(Matrizes[k].matrix[i][j]=='#')
	{
	k=x;
			
	}
		printf("\n-------------------------------------------");	
			printf("\n\n |Teletransportou para a sala %d| \n", data);
	}else if(i==n){

	data = rand()%tam;	
	x=k;
	k=data;

	
	if(Matrizes[k].matrix[i][j]=='#')
	{
	k=x;
			
	}
		printf("\n-------------------------------------------");	
			printf("\n\n |Teletransportou para a sala %d| \n", data);
	}else if(j==n){
		
	data = rand()%tam;	
	x=k;
	k=data;

	
	if(Matrizes[k].matrix[i][j]=='#')
	{
	k=x;
			
	}
		printf("\n-------------------------------------------");	
		printf("\n\n |Teletransportou para o Mundo %d| \n", data);	
	}

	//Verificar se está no inicio
	if(i==0&&j==0)
	{
		ok=1;
		for(a = 0; a < tam; a++){
		for(b = 0; b < n; b++){
		for(c = 0; c < n; c++){
		if(Matrizes[a].caminho[b][c]!='0')
		{
			ok=0;
		}	
			
		}}}
		
		if(ok==1)
		{
		 printf("\n\nO garoto terminou a jornada com segurança\n");
		 printf("\nDados da Jornada:\n");
		 printf("\nQuantidade de passos:%d ",Garoto.passos);
		 printf("\nQuantidade de itens consumidos:%d ",Garoto.itens);
		 printf("\nQuantidade de perigos enfrentados:%d ",Garoto.perigos);
		 	for(k = 0; k < tam; k++){
		 		for(i = 0; i < n; i++){
		 		for(j = 0; j < n; j++){		 			
		 			if(Matrizes[k].matrix[i][j]!='0'&&Matrizes[k].matrix[i][j]!='#'&&Matrizes[k].matrix[i][j]!='*')
		 			{
		 				Garoto.Inexplorado=Garoto.Inexplorado+1;					 
						 }
				 
			}		 			
		 		}
		 		
		 	}
		 printf("\nQuantidade de casas Inexploradas :%d ",Garoto.Inexplorado);
		 		 
		 return 0;
		}
	}
	
	
		}
	
	
}


	





