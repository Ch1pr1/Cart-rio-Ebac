#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar dos string

int registro()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//cria��o das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPG a ser cadastrado (apenas n�meros): "); 
	scanf("%s", cpf); //%s para salvar strings
	
	strcpy(arquivo, cpf); //copia os valores do cpf para o arquivo
	
	FILE *file; //acessar um arquivo
	file = fopen(arquivo, "w"); //define o arquivo acessado como um novo arquivo nomeado pela variavel
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" para atualizar o arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o primeiro nome a ser cadastrado: ");
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado, apenas n�meros: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
		
	if(file == NULL)
	{
		printf("Arquivo n�o localizado \n");
			system("pause");
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O us�ario n�o se encontra no sistema! \n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op��o: "); //Fim do menu

		scanf("%d", &opcao); //Armazenamento e escolha do usuario
		
		system("cls");
		
		
		switch(opcao) //chamada de fun��es
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
			printf("Obrigado por usar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Op��o Indispon�vel\n"); 
			system ("pause");
			break;
			
		}	
	}
}
	
