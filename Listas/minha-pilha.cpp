// Autor: Iann-Zorkot
// Licença: CC0 1.0 Universal
// Descrição: Implementação de pilha utilizando encadeamento de nós, desenvolvido para o curso de Estruturas de Dados -- DAC/UFLA

#include <iostream>
using namespace std;

typedef int dado; // Usado para trocar o tipo da pilha

class Noh {
	friend class Pilha;
	private:
		dado valor;
		Noh* proximo;
	public:
		Noh(dado umDado);
};

// Constroi o Noh
Noh::Noh(dado umDado) {
	proximo = NULL;
	valor = umDado;
}

class Pilha {
	private:
		Noh* topo;
		unsigned tamanho;
	public:
		Pilha();
		~Pilha();
		void insere(dado umDado);
		dado remove();
		inline void esvazia();
		inline bool vazia();

		// Métodos auxiliares
		dado espia();
		inline unsigned getTamanho();
		void imprime();
};

// Constroi a pilha
Pilha::Pilha() {
	topo = NULL;
	tamanho = 0;
}

// Deleta a pilha
Pilha::~Pilha() {
	this->esvazia();
}

// Verifica se o topo é nulo, ou seja, se a pilha está vazia.
bool Pilha::vazia() {
	return (this->topo == NULL);
}

// Insere um dado na pilha
void Pilha::insere(dado umDado) {
	Noh* novo = new Noh(umDado);
	novo->proximo = topo;
	topo = novo;
	tamanho++;
}

// Remove e retorna o dado do topo da pilha
dado Pilha::remove() {
	if(this->vazia()) {
		cerr << "pilha vazia!\n";
		exit(EXIT_FAILURE);
	}

	Noh* aux = topo;
	dado removido = aux->valor;
	topo = topo->proximo;
	delete aux;
	tamanho--;
	return removido;
}

// Remove todos os elementos da pilha
void Pilha::esvazia() {
	while(not this->vazia())
		remove();
}

// Retorna o tamanho da pilha
unsigned Pilha::getTamanho() {
	return this->tamanho;
}

// Retorna o valor do topo (getValor)
dado Pilha::espia() {
	if(this->vazia()) {
		cerr << "pilha vazia!\n";
		exit(EXIT_FAILURE);
	}

	return this->topo->valor;
}

// Imprime os dados da pilha no terminal
void Pilha::imprime() {
	if(this->vazia()) {
		cerr << "pilha vazia!\n";
		exit(EXIT_FAILURE);
	}

	Pilha aux;
	dado umDado;

	while(not this->vazia()) {
		umDado = this->remove();
		cout << "Dado: " << umDado << "\n";
		aux.insere(umDado);
	}

	while(not aux.vazia()) {
		this->insere(aux.remove());
	}
}

// Função principal para testes
int main() {
	char opcao;
	Pilha umaPilha;

	cout << "Digite uma opção:\n"
		 << "i - Inserir dado\n"
		 << "r - Remover dado\n"
		 << "l - Limpar todos os dados da pilha\n"
		 << "e - Imprimir os dados da pilha no terminal\n"
		 << "t - Imprimir o tamanho da pilha\n"
		 << "h - Imprimir o topo da pilha\n"
		 << "s - Sair do programa\n";

	cin >> opcao;

	while(opcao != 's') {
		switch(opcao) {
			case 'i':
				cout << "digite o dado para inserir: ";
				dado umDado;
				cin >> umDado;
				umaPilha.insere(umDado);
				break;

			case 'r':
				dado removido;
				removido = umaPilha.remove();
				cout << "dado removido: "
					 << removido << "\n";
				break;

			case 'l':
				umaPilha.esvazia();
				break;

			case 'e':
				umaPilha.imprime();
				break;

			case 't':
				cout << "tamanho: " << umaPilha.getTamanho() << "\n";
				break;

			case 'h':
				cout << "topo: " << umaPilha.espia() << "\n";
				break;

			case 's':
				cout << "saindo do programa...\n";
				break;

			default:
				cout << "Opção inválida!\n";
				break;
		}

		cout << "Digite uma opção:\n"
			 << "i - Inserir dado\n"
		 	 << "r - Remover dado\n"
		 	 << "l - Limpar todos os dados da pilha\n"
		 	 << "e - Imprimir os dados da pilha no terminal\n"
		 	 << "t - Imprimir o tamanho da pilha\n"
		 	 << "h - Imprimir o topo da pilha\n"
		 	 << "s - Sair do programa\n";

		cin >> opcao;
	}

	return 0;
}
