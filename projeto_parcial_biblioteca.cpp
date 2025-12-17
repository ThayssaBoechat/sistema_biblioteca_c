
#include <stdio.h>
#include <string.h> // manipulacao de string (remove o \n, evitando erros) 

// struct 
struct Infos_livro {
	char titulo[40];
    char autor[30];
	int codigo;
	char genero[20];
};

// função para remover o \n
void removeNovaLinha(char *string) {
    string[strcspn(string, "\n")] = '\0';
}

// adcionei poiserro inesperado na leitura do menu
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// função //biblioteca:array que armazena os livros cadastrados;
void cadastrar_livros( struct Infos_livro biblioteca[], int * num_livros ) {
	
	printf("Digite o titulo do livro: ");
	fgets (biblioteca[*num_livros].titulo, sizeof (biblioteca[*num_livros].titulo), stdin);
	removeNovaLinha(biblioteca[* num_livros].titulo);
	
	printf("Digite o autor do livro: ");
	fgets(biblioteca[*num_livros].autor, sizeof (biblioteca[* num_livros].autor), stdin);
	removeNovaLinha(biblioteca[* num_livros].autor);
	
	printf("Digite o codigo do livro: ");
	scanf("%d", &biblioteca[*num_livros].codigo);
	getchar(); //limpa o buffer
	
	printf("Digite o genero do livro: ");
	fgets(biblioteca[*num_livros].genero, sizeof (biblioteca[*num_livros].genero), stdin);
	removeNovaLinha(biblioteca[*num_livros].genero);
	
	//contador de livros
	(*num_livros) ++;
	
	printf("Livro cadastrado \n");	
}


//funcao de pesquisa ou listagem
void pesquisa_livros (struct Infos_livro biblioteca[], int num_livros){
	int opcao, result_pesquisa = 0, i;
	int pesquisa_codigo; // caso o usuario queira buscar por codigo
	char pesquisa[45];
	
	printf("--Como deseja realizar a busca?-- \n");
	printf("Escolha uma opcao: \n ");
	printf("1. Pelo nome do livro \n");
	printf("2. Pelo autor do livro \n");
	printf("3. Pelo genero do livro \n");
	printf("4. Pelo codigo do livro \n"); //vou primeiro testar com os outros
	scanf("%d", &opcao);
	limparBuffer(); //limpar o buffer

	//busca 
	if (opcao != 4){ //busca por string
		printf("Digite o termo de busca: ");
		fgets (pesquisa, sizeof (pesquisa), stdin);
		removeNovaLinha(pesquisa);
	}else { // busca por int (codigo apenas)
		printf("Digite o código do livro: ");
        scanf("%d", &pesquisa_codigo);
        limparBuffer();
	}
	
	printf("Resultado da busca: \n ");
	
	for(i = 0; i < num_livros; i++){
		switch (opcao) {
			case 1:  //titulo
				if (strcasecmp (biblioteca[i].titulo, pesquisa) == 0){
					printf("Titulo: %s, Autor: %s, Codigo: %d, Genero: %s\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].codigo, biblioteca[i].genero);	
					result_pesquisa = 1;
				}
			break;
			case 2: //autor
				if ( strcasecmp (biblioteca[i].autor, pesquisa) == 0){
					printf("Titulo: %s, Autor: %s, Codigo: %d, Genero: %s\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].codigo, biblioteca[i].genero);
					result_pesquisa = 1;
				}
			break;
			case 3: // genero
				if ( strcasecmp (biblioteca[i].genero, pesquisa) == 0){
					printf("Titulo: %s, Autor: %s, Codigo: %d, Genero: %s\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].codigo, biblioteca[i].genero);
					result_pesquisa = 1;
				}
			break;
			case 4: //codigo
				if (biblioteca[i].codigo == pesquisa_codigo){
					printf("Titulo: %s, Autor: %s, Codigo: %d, Genero: %s\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].codigo, biblioteca[i].genero);
					result_pesquisa = 1;
				}
			break;
			default: 
				printf("Opcao invalida! \n");
			break;
		}
	} 
	
	if (result_pesquisa == 0){
		printf("Nenhum resultado foi encontrado \n");
		result_pesquisa = 1;
	}

}

int main(){
	
	struct Infos_livro biblioteca[100]; // array amzena ate 100 livros
	int cont_livros = 0; // contador de livros cadastrados
	int opcao;
	
	do {
		printf(" --Sistema de Biblioteca -- \n");
		printf("Escolha uma opcao: \n");
		printf("1. Cadastrar Livro \n");
		printf("2. Procurar Livros \n");
		printf("3. Sair \n");
		scanf("%d", &opcao);
		limparBuffer();
		
		switch (opcao){
			case 1:
				cadastrar_livros (biblioteca, &cont_livros); //funcao de cadastro
				break;
			case 2:
				pesquisa_livros (biblioteca, cont_livros); // funcao de pesquisa
				break;
			case 3: 
				printf("O programa foi encerrado... \n");
				break;
			default:
				printf("Opcao invalida! \n");	
		}
	} while (opcao != 3);
	return 0;
}




