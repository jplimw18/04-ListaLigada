
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

	// se a lista já possuir elementos
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
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{
	int valorDelete = 0;

	cout << "Insira um elemento para excluir: " << endl;
	cin >> valorDelete;

	if (primeiro == NULL)
	{
		cout << "Lista vazia" << endl;
		return;
	}

	NO* pos = posicaoElemento(valorDelete);

	if (pos == NULL)
	{
		cout << "O numero nao existe na lista" << endl;
		return;
	}

	NO* aux = primeiro;
	bool _delete = false;

	if (aux->valor == valorDelete)
	{
		primeiro = aux->prox;
		free(aux);

		_delete = true;
	}
	else
	{
		while (!_delete && aux != NULL)
		{
			NO* toDelete = NULL;

			if (aux->prox->valor == valorDelete)
			{
				toDelete = aux->prox;
				aux->prox = aux->prox->prox;

				free(toDelete);
				_delete = true;

				cout << "Exclusao realizada" << endl << endl << "nova lista: " << endl << endl;
				exibirElementos();
			}

			aux = aux->prox;
		}
	}
}

void buscarElemento()
{
	int valorBusca = 0;
	cout << "Insira o valor que deseja encontrar: ";
	cin >> valorBusca;

	if (primeiro == NULL)
	{
		cout << "A lista esta vazia" << endl;
		return;
	}

	NO* aux = primeiro;
	bool find = false;

	while (!find && aux != NULL)
	{
		if (aux->valor == valorBusca)
		{
			cout << "Elemento encontrado!" << endl;
			find = true;
		}

		aux = aux->prox;
	}

	if (!find)
	{
		cout << "Elemento nao encontrado!" << endl;
	}
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
