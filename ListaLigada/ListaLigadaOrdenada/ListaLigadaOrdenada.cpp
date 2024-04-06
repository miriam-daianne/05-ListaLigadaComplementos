#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		return;
	}

	NO* atual = primeiro;
	while (atual != NULL) {
		if (atual->valor == novo->valor) {
			cout << "O Elemento ja existe na lista, insira outro valor." << endl;
			return;
		}
		atual = atual->prox;
	}

	atual = primeiro;
	NO* anterior = NULL;
	while (atual != NULL){

		if (atual->valor < novo->valor){
			anterior = atual;
		}
		atual = atual->prox;
	}

	if (anterior == NULL) {
		novo->prox = primeiro;
		primeiro = novo;
	}
	else {
		novo->prox = anterior->prox;
		anterior->prox = novo;
	}

}


void excluirElemento()
{
	int excluindo;
	NO* atual = primeiro;
	cout << "Digite o elemento que deseja excluir: " << endl;
	cin >> excluindo;

	NO* anterior = NULL;
	while (atual != NULL && atual->valor <= excluindo) {
		if (atual->valor == excluindo) {
			if (anterior == NULL) { 
				primeiro = atual->prox;
			}
			else {
				anterior->prox = atual->prox;
			}
			free(atual);
			cout << "Elemento excluido com sucesso" << endl;
			return;
		}
		anterior = atual;
		atual = atual->prox;
	}
	cout << "Nenhum elemento encontrado para excluir!" << endl;
}



void buscarElemento()
{
	int buscado = 0;
	NO* atual = primeiro;

	cout << "Digite o elemento que deseja buscar: " << endl;
	cin >> buscado;

	while (atual->valor <= buscado &&  atual != NULL) {
		if (atual->valor == buscado) {
			cout << "ELemento Encontrado!" << endl;
			return; 
		}
		atual = atual->prox;
	}

	cout << "ELemento NAO Encontrado!" << endl;
	
}





