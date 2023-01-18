#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca responsavel por aloca��o de espa�os de mem�ria(vari�veis)
#include <locale.h> //biblioteca de aloca��es de texto por regiao
#include <string.h> // biblioteca para armazenar as strings


int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// inicio da cria��o de vari�veis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis
	setlocale(LC_ALL, "portuguese");
	
	printf("Digite o seu cpf: "); //coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);              // respons�vel por copiar os arquivos das strings 
	
	FILE *file;                       //cria o arquivo
	file = fopen(arquivo, "w");      // "w" de write
	fprintf(file, cpf);             //salva o valor da vari�vel
	fclose(file);                  // fecha o arquivo
	
	fopen(arquivo, "a");         // "a" atualiza o arquivo
	fprintf(file, "; \n");
	fclose(file);
	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	fopen(arquivo, "a");
	fprintf(file, "; \n");
	fclose(file);
	
	printf("Digite seu Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "; \n");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".\n");
	fclose(file);
	
	system("pause");
} 
int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL) //NULL = NULO - caso o usu�rio digite um CPF que n�o esteja no banco de dados.
	{
		printf ("N�o foi poss�vel encontrar o arquivo solicita. \n");
		
	}
	
		printf("\n Essas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) != NULL)  // while significa "enquanto";
	{
		printf("%s", conteudo);
		printf("\n");
	} 
	
	system("pause");
	file = fclose(cpf);
}
int deletar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("Qual o CPF do usu�rio que deseja deletar?: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF n�o se encontra no sistema. \n");
		system("pause");
	}
	
	
}


int main() // inicio do programa
{
	int opcao=0; // armazenamento de vari�vel
	int x=1; // armazenamento de vari�vel
	
	for(x=1;x=1;)
	{
		
	system("cls");
	
	setlocale(LC_ALL, "portuguese");

	printf("###Cart�ria da EBAC###\n\n"); // in�cio do menu 
	printf("Escolha a op��o desejada no menu: \n\n");
	printf("\t1 - Resgistrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o: "); // fim do menu
	
	scanf("%d", &opcao); // armazana a escolha do usu�rio
	
	system("cls"); // respons�vel por limpar a tela.
	
	switch(opcao) // sele��o de op��o
	{
			case 1: // chamada de fun��es
			registro();
			break;
		
			case 2:
			consulta();
			break;
		
			case 3: 
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
		
			default:
			printf("Voc� escolheu uma op��o inesistente\n");
			system("pause");
			break;
	}
	
	}
} // fim do programa
