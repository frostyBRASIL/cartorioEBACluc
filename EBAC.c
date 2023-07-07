#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função com a finalidade de cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("digite o CPF a ser cadastrado: "); //coleta de informações do usuário
	scanf ("%s",&cpf); //%s se refere a string
	
	strcpy (arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados na pasta onde está salvo o sistema
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa "escrever"
	fprintf(file,cpf); //salvar o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir um arquivo já existente
	fprintf(file,","); //separar a informação recebida das demais
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta de informações do usuário
	scanf("%s",nome);//%s se refere a string
	
	file = fopen(arquivo, "a");//abrir um arquivo já existente
	fprintf(file,nome); //salvar o valor da variável
	fclose(file);//fechar o arquivo

	file = fopen(arquivo, "a"); //abrir um arquivo já existente
	fprintf(file,","); //separar a informação recebida das demais
	fclose(file); //fechar o arquivo
	
	printf("Digite o seu sobrenome a ser cadastrado: "); //coleta de informações do usuário
	scanf("%s",sobrenome); //%s se refere a string
	
	file = fopen (arquivo, "a"); //abrir um arquivo já existente
	fprintf(file,sobrenome); //salvar o valor da variável
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abrir um arquivo já existente
	fprintf(file,","); //separar a informação recebida das demais
	fclose(file); //fechar o arquivo
	
	
	printf("Digite o cargo a ser cadastrado: "); //coleta de informações do usuário
	scanf("%s", cargo); //%s se refere a string

	
	file = fopen (arquivo, "a"); //citar um arquivo já existente
	fprintf(file,cargo); //salvar o valor da variável
	fclose(file); //fechar o arquivo
	system("pause"); //espera de uma tecla ser apertada pelo usuário
	
}

int consulta() //função com a finalidade de consultar os dados alocados no banco de dados
{	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio criação de variáveis/string
	char cpf [40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coleta de informações do usuário
	scanf("%s",cpf); //%s se refere a string
	
	FILE*file; //cria o arquivo no banco de dados na pasta onde está salvo o sistema
	file = fopen(cpf,"r"); //abrir um arquivo já gravado no banco de dados, a função "r" significa abrir um arquivo texto para a leitura
	
	if(file == NULL) //se o arquivo não for localizado, classifique como nulo/inexistente
	{
		printf("Não localizado. \n"); //mensagem de não localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //procurar o arquivo "conteúdo" 200 vezes. Caso não ache, classifique como nulo/inexistente
	{
		printf("\nEssas são as informações do usuário: "); //resposta do sistema para o usuário
		printf("%s",conteudo); //%s se refere a string
		printf("\n\n"); //espaçamento 
	}
	
	system("pause"); //espera de uma tecla ser apertada pelo usuário
}

int deletar() //função com a finalidade de deletar arquivos registrados nos bancos de dados
{
	//inicio criação de variáveis/string
	char cpf [40];
	//final da criação de variáveis/string
	printf("Digite o CPF do usuário a ser deletado: "); //coleta de informações do usuário
	scanf("%s",cpf); //%s se refere a string
	
	remove(cpf); //deleta o arquivo
	
	FILE *file; //cria o arquivo no banco de dados na pasta onde está salvo o sistema
	file = fopen (cpf, "r"); //abrir um arquivo já gravado no banco de dados, a função "r" significa abrir um arquivo texto para a leitura
	
	if(file == NULL) //se o arquivo não for localizado, classifique como nulo/inexistente
	{
		printf("O usuário não foi encontrado no sistema! \n"); //resposta do sistema para o usuário
		system("pause"); //espera de uma tecla ser apertada pelo usuário
	}
	
}

int main()//função principal que se encontra o menu de opções 
	{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //voltar ao menu
	{
		
		system("cls");//responsável por limpar a tela 
	
 		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
 	
 		//início do menu
 		printf("### Cartório da EBAC ### \n\n"); //apresentação do cartório da EBAC
 		printf("Escolha a opção desejada do menu:\n\n"); //coleta de informações do usuário
 		
 		//Início das seleções apresentadas no menu
 		printf("\t(1) - Registrar nomes\n");
 		printf("\t(2) - Consultar os nomes\n");
 		printf("\t(3) - Deletar os nomes\n\n");
 		printf("\t(4) - Sair do sistema \n\n");
 		//Final das seleções apresentadas no menu
 		
		printf("Opção: "); //Resposta do usuário
		
		//final do menu
 	
 		scanf("%d", &opcao); //armazenando informações selecionadas
 		
 		system ("cls");
 		
 		//início da seleção do menu
 		switch(opcao) 
 		{
 			
 			//início da chamada das funções
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
 			printf("Obrigado por utilizar o software!\n\n");
 			return 0;
 			break;
 			//fim da chamada das funções

 			default:
 			printf("Você escolheu uma opção inválida\n"); //resposta do sistema para o usuário
 			system("pause");
 			break;
 		//final da seleção do menu
		 }
 	
 	
	 }
}
