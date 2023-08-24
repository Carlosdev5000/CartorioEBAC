#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espasos de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cudar das string

int registro() // Fun��o responsavel por cadastrar os usuarios no systema.
{
	//Inicio cria��o de vareaveis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vareaveis/string.
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario.
	scanf("%s", cpf);//%s refere-se a string
		
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string

	FILE * file;
	file = fopen(arquivo, "w"); // criando o arquivo e o "w" significa escrever.
	fprintf(file,cpf);// salvo o valor da vareavel
	fclose(file);// fecho o arquivo
	
	file = fopen(arquivo, "a"); //atualizar o arquivo o "a" significa atualizar.
	fprintf(file,"," );
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usuario.
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"," );
	fclose(file);
	
	printf("Sobrenome: ");//coletando informa��o do usuario.
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"," );
	fclose(file);
		
	printf("Digite o cargo a ser preenchido: ");//coletando informa��o do usuario.
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}
int consulta() // Fun��o responsavel por consultar usuarios cadastrados.
{
	
	setlocale(LC_ALL, "portuguese");
	// inicio da cria��o de vareaveis/string.
	char cpf[40];
	char conteudo[200];
	// Fim da cria��o de vareaveis/string.
	printf("Digite o cpf a ser consultado:");//coletando informa��o do usuario.
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abrindo um arquivo e o "r" significa ler.
	
	if(file == NULL)
	{
		printf("Usuario n�o localisado.\n\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o a informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause"); // pausa o sistema para o usuario poder ler.
		
}
int deletar() // Fun��o responsavel por deletar usuarios cadastrados. 
{
	char cpf[40];// definindo a vareavel

	printf("Digite o cpf a ser deletado: "); //pedindo a informa��o necesaria para o procedimento.
	scanf("%s",cpf);
	
	remove(cpf);//comando responsavel por deletar o usuario a ser removido
	
	printf("Usuario deletado com sucesso!\n");
	system("pause");
	FILE *file;
	file = fopen(cpf, "r");
	 
	if( file == NULL);// comando caso o usuario n�o se encontra no sistema.
	{
		printf("Usu�rio n�o se encontra no sistema!!");
		system("pause");
		
	}

}
int erro()  // Inicio da defini��o das fun��es.
{
	printf("opcao invalida!!\n");
	system("pause");
}
int erro2()
{
	printf("opcao invalida!!\n");
	system("pause");	
}
int main()  // Fim da defini��o das fun��es. 
{
	int opcao=0; //definindo variaveis
	int repita=0;
	
	for(repita=1;repita=1;)
	{
		system("cls");
		setlocale(LC_ALL,"Portuguese");// definindo a linguagem
	
		printf("\t##CART�RIO DA EBAC##\n\n");// inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes.\n");
		printf("\t2 - consultar nomes.\n");
		printf("\t3 - Deletar nomes.\n\n");
		printf("Op��o:"); // fim do menu
	
		scanf("%d", &opcao); // armasenando a escolha do usuario
	
		system("cls");// responsavel por limpar a tela.
	
		switch(opcao) // definindo as op��es
		{
			case 1:
			registro();
			break;
		
		
			case 2:
			consulta();
			break;
		
		
			case 3:
			deletar();
			break;
		
			case 4:
			erro();
			break;
			
			default:
			erro2(); // fim das op��es
			break;
		}
	}
}

