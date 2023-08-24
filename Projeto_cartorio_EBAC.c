#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espasos de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cudar das string

int registro() // Função responsavel por cadastrar os usuarios no systema.
{
	//Inicio criação de vareaveis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de vareaveis/string.
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuario.
	scanf("%s", cpf);//%s refere-se a string
		
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string

	FILE * file;
	file = fopen(arquivo, "w"); // criando o arquivo e o "w" significa escrever.
	fprintf(file,cpf);// salvo o valor da vareavel
	fclose(file);// fecho o arquivo
	
	file = fopen(arquivo, "a"); //atualizar o arquivo o "a" significa atualizar.
	fprintf(file,"," );
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuario.
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"," );
	fclose(file);
	
	printf("Sobrenome: ");//coletando informação do usuario.
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"," );
	fclose(file);
		
	printf("Digite o cargo a ser preenchido: ");//coletando informação do usuario.
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}
int consulta() // Função responsavel por consultar usuarios cadastrados.
{
	
	setlocale(LC_ALL, "portuguese");
	// inicio da criação de vareaveis/string.
	char cpf[40];
	char conteudo[200];
	// Fim da criação de vareaveis/string.
	printf("Digite o cpf a ser consultado:");//coletando informação do usuario.
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abrindo um arquivo e o "r" significa ler.
	
	if(file == NULL)
	{
		printf("Usuario não localisado.\n\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são a informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause"); // pausa o sistema para o usuario poder ler.
		
}
int deletar() // Função responsavel por deletar usuarios cadastrados. 
{
	char cpf[40];// definindo a vareavel

	printf("Digite o cpf a ser deletado: "); //pedindo a informação necesaria para o procedimento.
	scanf("%s",cpf);
	
	remove(cpf);//comando responsavel por deletar o usuario a ser removido
	
	printf("Usuario deletado com sucesso!\n");
	system("pause");
	FILE *file;
	file = fopen(cpf, "r");
	 
	if( file == NULL);// comando caso o usuario não se encontra no sistema.
	{
		printf("Usuário não se encontra no sistema!!");
		system("pause");
		
	}

}
int erro()  // Inicio da definição das funções.
{
	printf("opcao invalida!!\n");
	system("pause");
}
int erro2()
{
	printf("opcao invalida!!\n");
	system("pause");	
}
int main()  // Fim da definição das funções. 
{
	int opcao=0; //definindo variaveis
	int repita=0;
	
	for(repita=1;repita=1;)
	{
		system("cls");
		setlocale(LC_ALL,"Portuguese");// definindo a linguagem
	
		printf("\t##CARTÓRIO DA EBAC##\n\n");// inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes.\n");
		printf("\t2 - consultar nomes.\n");
		printf("\t3 - Deletar nomes.\n\n");
		printf("Opção:"); // fim do menu
	
		scanf("%d", &opcao); // armasenando a escolha do usuario
	
		system("cls");// responsavel por limpar a tela.
	
		switch(opcao) // definindo as opções
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
			erro2(); // fim das opções
			break;
		}
	}
}

