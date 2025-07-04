#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro () //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	printf("Voc� escolheu o registro de nomes!\n");
	system("pause");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:"); //respons�vel por copiar os valores das string
	scanf("%s", cpf); //%s se refere a salvar a string
	
	strcpy(arquivo, cpf);	//Respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w");
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastras: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //"a" significa atualiza��o
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastras: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //"a" significa atualiza��o
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta ()
{
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem
		
	printf("Voc� escolheu consultar os nomes!\n");
	system("pause");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)	
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar ()
{
	printf("Voc� escolheu deletar os nomes!\n");	
	system("pause");
	
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
		
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");	
	}	
}

int main ()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
{
	
	system ("cls"); // respons�vel por limpar a tela
	
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o:" ); //fim do menu
	
	scanf ("%d", &opcao); //armazenando a escolha do usu�rio
	
	system ("cls");
	
	switch(opcao) //inicio da sele��o do menu
		{
		case 1:
		registro(); //chamada de fun��es
		break;
	
		case 2:
		consulta();
		break;
	
		case 3:
		deletar();
		break;
		
		case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
	
		default:
		printf("Essa op��o n�o est� dispon�vel!\n");
		system("pause");
		break;
		}//fim da sele��o de op��es
}
	
	
}

