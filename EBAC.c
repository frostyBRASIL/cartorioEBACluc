#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o com a finalidade de cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("digite o CPF a ser cadastrado: "); //mostrar a mensagem na tela
	scanf ("%s",&cpf); //%s se refere a string
	
	strcpy (arquivo, cpf); //respons�vel por pegar o valor da vari�vel cpf e transferir para a vari�vel arquivo
	
	FILE*file; //referencia��o aos m�todos utilizados para manipular o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa "escrever"
	fprintf(file,cpf); //salvar o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir um arquivo j� existente
	fprintf(file,","); //separar a informa��o recebida das demais
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //mostrar a mensagem na tela
	scanf("%s",nome);//%s se refere a string
	
	file = fopen(arquivo, "a");//abrir um arquivo j� existente
	fprintf(file,nome); //salvar o valor da vari�vel
	fclose(file);//fechar o arquivo

	file = fopen(arquivo, "a"); //abrir um arquivo j� existente
	fprintf(file,","); //separar a informa��o recebida das demais
	fclose(file); //fechar o arquivo
	
	printf("Digite o seu sobrenome a ser cadastrado: "); //mostrar a mensagem na tela
	scanf("%s",sobrenome); //%s se refere a string
	
	file = fopen (arquivo, "a"); //abrir um arquivo j� existente
	fprintf(file,sobrenome); //salvar o valor da vari�vel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abrir um arquivo j� existente
	fprintf(file,","); //separar a informa��o recebida das demais
	fclose(file); //fechar o arquivo
	
	
	printf("Digite o cargo a ser cadastrado: "); //mostrar a mensagem na tela
	scanf("%s", cargo); //%s se refere a string

	
	file = fopen (arquivo, "a"); //citar um arquivo j� existente
	fprintf(file,cargo); //salvar o valor da vari�vel
	fclose(file); //fechar o arquivo
	system("pause"); //espera de uma tecla ser apertada pelo usu�rio
	
}

int consulta() //fun��o com a finalidade de consultar os dados alocados no banco de dados
{	
	setlocale(LC_ALL, "Portuguese"); //definindo o tipos de caracteres aceitos, entre as "" est� definindo a linguagem
	
	//inicio cria��o de vari�veis/string
	char cpf [40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //mostrar a mensagem na tela
	scanf("%s",cpf); //%s se refere a string
	
	FILE*file; //referencia��o aos m�todos utilizados para manipular o arquivo
	file = fopen(cpf,"r"); //abrir um arquivo j� gravado no banco de dados, a fun��o "r" significa abrir um arquivo texto para a leitura
	
	if(file == NULL) //se o programa buscar um arquivo e ele n�o existir, esta busca retorna null
	{
		printf("N�o localizado. \n");  //mostrar a mensagem na tela
	}
	
	while(fgets(conteudo, 200, file) != NULL) //procura de arquivo, colocando o seu valor na vari�vel conte�do e declara que o limite de caracteres � at� 200. Verifica tamb�m se existe este conte�do checado se � diferente de null.
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //resposta do sistema para o usu�rio
		printf("%s",conteudo); //%s se refere a string
		printf("\n\n"); //quebra de linhas
	}
	
	system("pause"); //espera de uma tecla ser apertada pelo usu�rio
}

int deletar() //fun��o com a finalidade de deletar arquivos registrados nos bancos de dados
{
	//inicio cria��o de vari�veis/string
	char cpf [40];
	//final da cria��o de vari�veis/string
	printf("Digite o CPF do usu�rio a ser deletado: "); //mostrar a mensagem na tela
	scanf("%s",cpf); //%s se refere a string
	
	remove(cpf); //deleta o arquivo
	
	FILE*file; //referencia��o aos m�todos utilizados para manipular o arquivo
	file = fopen (cpf, "r"); //abrir um arquivo j� gravado no banco de dados, a fun��o "r" significa abrir um arquivo texto para a leitura
	
	if(file == NULL) //se o programa buscar um arquivo e ele n�o existir, esta busca retorna null 
	{
		printf("O usu�rio n�o foi encontrado no sistema! \n"); //resposta do sistema para o usu�rio
		system("pause"); //espera de uma tecla ser apertada pelo usu�rio
	}
	
}

int main()//fun��o principal que se encontra o menu de op��es 
	{
	//inicio cria��o de vari�veis/string
	int opcao=0; 
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	//final da cria��o de vari�veis/string
	
	printf("### Cart�rio da EBAC ### \n\n"); //mostrar a mensagem na tela
	printf("Login de Administrador - Digite a sua senha:"); //mostrar a mensagem na tela
	scanf("%s", senhadigitada); //%s se refere a string
	
	comparacao = strcmp(senhadigitada, "admin"); //comparar a senha digitada com a senha de acesso
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;) //voltar ao menu
		{
		
			system("cls"); //respons�vel por limpar a tela 
	
 			setlocale(LC_ALL, "Portuguese"); //definindo o tipos de caracteres aceitos, entre as "" est� definindo a linguagem
 	
 			//in�cio do menu
 			printf("### Cart�rio da EBAC ### \n\n"); //apresenta��o do cart�rio da EBAC
 			printf("Escolha a op��o desejada do menu:\n\n"); //mostrar a mensagem na tela
 		
 			//In�cio das sele��es apresentadas no menu
 			printf("\t(1) - Registrar nomes\n");
 			printf("\t(2) - Consultar os nomes\n");
 			printf("\t(3) - Deletar os nomes\n\n");
 			printf("\t(4) - Sair do sistema \n\n");
 			//Final das sele��es apresentadas no menu
 		
			printf("Op��o: "); //Resposta do usu�rio
		
			//final do menu
 	
 			scanf("%d", &opcao); //armazenando informa��es selecionadas
 		
 			system ("cls"); //respons�vel por limpar a tela 
 		
 			//in�cio da sele��o do menu
 			switch(opcao) 
 			{
 			
 			//in�cio da chamada das fun��es
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
 				printf("Obrigado por utilizar o software!\n\n"); //resposta do sistema para o usu�rio
 				return 0;
 				break;
 				//fim da chamada das fun��es

 				default:
 				printf("Voc� escolheu uma op��o inv�lida\n"); //resposta do sistema para o usu�rio
 				system("pause"); //espera de uma tecla ser apertada pelo usu�rio
 				break;
 			//final da sele��o do menu
			 }
 		}
 	
	 }
	 
	else //c�digo caso o resultado escolhido seja FALSE
	printf("Senha incorreta!"); //mostrar a mensagem na tela
	
}


	
