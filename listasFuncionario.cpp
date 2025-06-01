#include <iostream>
#include <locale.h>
using namespace std;

struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
	Funcionario* prox;
};

Funcionario* init()
{
	return NULL;
}

bool isEmpty(Funcionario* lista)
{
	return (lista == NULL);
}

bool existeProntuario(Funcionario* lista, int prontuario) {
    Funcionario* aux = lista;
    while (aux != NULL) {
        if (aux->prontuario == prontuario) {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

Funcionario* incluir(Funcionario* lista){
	int prontuario;
	string nome;
	double salario;
	
	cout << "Digite o Prontuário:\n" << endl;
	cin >> prontuario;
	cout << "Digite o Nome:\n" << endl;
	cin >> nome;
	cout << "Digite o Salario:\n" << endl;
	cin >> salario;
	
	Funcionario* novo = new Funcionario();
	novo->prontuario = prontuario;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = lista;
	
	cout << "Funcionario cadastrado com sucesso!\n";
	  
	return novo;
}
Funcionario* excluir(Funcionario* lista){
	if (isEmpty(lista)) {
        cout << "Lista vazia!\n";
        return lista;
    }

    int prontuario;
    cout << "Digite o prontuario do funcionario: ";
    cin >> prontuario;

    Funcionario* aux = lista;
    Funcionario* ant = NULL;

    while (aux != NULL && aux->prontuario != prontuario) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        cout << "Funcionario nao encontrado.\n";
        return lista;
    }

    if (ant == NULL) { 
        lista = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    delete aux;
    cout << "Funcionario excluido com sucesso!\n";

    return lista;
}
void listar(Funcionario* lista){
	if (isEmpty(lista)) {
        cout << "Lista vazia!\n";
        return;
    }

    Funcionario* aux = lista;
    double totalSalarios = 0.0;

    cout << "\n--- Lista de Funcionarios ---\n";
    while (aux != NULL) {
        cout << "Prontuario: " << aux->prontuario << endl;
        cout << "Nome: " << aux->nome << endl;
        cout << "Salario: " << aux->salario << endl;
        cout << "-----------------------------\n";
        totalSalarios += aux->salario;
        aux = aux->prox;
    }

    cout << "Total dos salarios: " << totalSalarios << endl;
} 
void pesquisar(Funcionario* lista){
	if (isEmpty(lista)) {
        cout << "Lista vazia!\n";
        return;
    }

    int prontuario;
    cout << "Digite o prontuario para pesquisar: ";
    cin >> prontuario;

    Funcionario* aux = lista;
    while (aux != NULL) {
        if (aux->prontuario == prontuario) {
            cout << "Funcionario encontrado:\n" << endl;
            cout << "Prontuario: " << aux->prontuario << endl;
            cout << "Nome: " << aux->nome << endl;
            cout << "Salario: " << aux->salario << endl;
            return;
        }
        aux = aux->prox;
    }

    cout << "Funcionario nao encontrado.\n";
}

int main(int argc, char** argv)
{
	Funcionario* lista = init();
	int option;
	do
	{
		cout << "0 - Sair\n" << endl;
		cout << "1 - Incluir\n" << endl;
		cout << "2 - Excluir\n" << endl;
		cout << "3 - Pesquisar\n" << endl;
		cout << "4 - Listar\n" << endl;
		cin >> option;
			switch (option) {
		case 0:
	        cout << "Programa finalizado!" << endl;
	        break;
	    case 1:
	        lista = incluir(lista);
	        break;
	    case 2:
	        lista = excluir(lista);
	        break;
	    case 3:
	        pesquisar(lista);
	        break;
	    case 4:
	         listar(lista);
	        break;
	    default:
	        cout << "Escolha uma das opções!" << endl;
			}
	}while(option != 0);
	
	while (lista != NULL) {
        Funcionario* aux = lista;
        lista = lista->prox;
        delete aux;
    }
    
    return 0;
}
