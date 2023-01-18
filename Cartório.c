#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca responsavel por alocação de espaços de memória(variáveis)
#include <locale.h> //biblioteca de alocações de texto por regiao
#include <string.h> // biblioteca para armazenar as strings


int registro() // função responsável por cadastrar os usuários no sistema
{
	// inicio da criação de variáveis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis
	setlocale(LC_ALL, "portuguese");
	
	printf("Digite o seu cpf: "); //coletando informações do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);              // responsável por copiar os arquivos das strings 
	
	FILE *file;                       //cria o arquivo
	file = fopen(arquivo, "w");      // "w" de write
	fprintf(file, cpf);             //salva o valor da variável
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

	if(file == NULL) //NULL = NULO - caso o usuário digite um CPF que não esteja no banco de dados.
	{
		printf ("Não foi possível encontrar o arquivo solicita. \n");
		
	}
	
		printf("\n Essas são as informações do usuário: \n");
	
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
	
	printf("Qual o CPF do usuário que deseja deletar?: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF não se encontra no sistema. \n");
		system("pause");
	}
	
	
}


int main() // inicio do programa
{
	int opcao=0; // armazenamento de variável
	int x=1; // armazenamento de variável
	
	for(x=1;x=1;)
	{
		
	system("cls");
	
	setlocale(LC_ALL, "portuguese");

	printf("###Cartória da EBAC###\n\n"); // início do menu 
	printf("Escolha a opção desejada no menu: \n\n");
	printf("\t1 - Resgistrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção: "); // fim do menu
	
	scanf("%d", &opcao); // armazana a escolha do usuário
	
	system("cls"); // responsável por limpar a tela.
	
	switch(opcao) // seleção de opção
	{
			case 1: // chamada de funções
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
			printf("Você escolheu uma opção inesistente\n");
			system("pause");
			break;
	}
	
	}
} // fim do programa
