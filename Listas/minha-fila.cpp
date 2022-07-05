// Autor: Iann-Zorkot
// Licença: CC0 1.0 Universal
// Descrição: Implementação de fila utilizando encadeamento de nós, desenvolvido para o curso de Estruturas de Dados -- DAC/UFLA

#include <iostream>
using namespace std;

typedef int dado; // Usado para trocar o tipo da fila

class Noh {
	friend class Fila;
	private:
		dado valor;
		Noh* proximo;
	public:
		Noh(dado umDado);
};

// Constrói o Noh
Noh::Noh(dado umDado) {
	proximo = NULL;
	valor = umDado;
}

class Fila {
	private:
		Noh* primeiro;
		Noh* ultimo;
		unsigned tamanho;
	public:
		Fila();
		~Fila();
		void insere(dado umDado);
		dado remove();
		inline void esvazia();
		inline bool vazia();

		// Métodos auxiliares
		inline dado getPrimeiro();
		inline unsigned getTamanho();
		void imprime();
};

// Constrói a fila
Fila::Fila() {
	primeiro = NULL;
	ultimo = NULL;
	tamanho = 0;
}

// Deleta a fila
Fila::~Fila() {
	this->esvazia();
}

// Verifica se o primeiro é nulo, ou seja, se a fila está vazia.
bool Fila::vazia() {
	return (this->primeiro == NULL);
}

// Insere um dado na fila
void Fila::insere(dado umDado) {
	Noh* novo = new Noh(umDado);
	if(this->vazia())
		primeiro = novo;
	else
		ultimo->proximo = novo;
	ultimo = novo;
	tamanho++;
}

// Remove e retorna o primeiro dado da fila
dado Fila::remove() {
	if(this->vazia()) {
		cerr << "Fila vazia!\n";
		exit(EXIT_FAILURE);
	}

	Noh* aux = primeiro;
	dado removido = aux->valor;
	primeiro = primeiro->proximo;
	delete aux;
	tamanho--;
	if(this->vazia())
		ultimo = NULL;
	return removido;
}

// Remove todos os elementos da fila
void Fila::esvazia() {
	while(not this->vazia())
		remove();
}

// Retorna o tamanho da fila
unsigned Fila::getTamanho() {
	return this->tamanho;
}

// Retorna o valor do primeiro (getValor)
dado Fila::getPrimeiro() {
	if(this->vazia()) {
		cerr << "fila vazia!\n";
		exit(EXIT_FAILURE);
	}

	return this->primeiro->valor;
}

// Imprime os dados da fila no terminal
void Fila::imprime() {
	if(this->vazia()) {
		cerr << "fila vazia!\n";
		exit(EXIT_FAILURE);
	}

	Fila aux;
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
	Fila umaFila;

	cout << "Digite uma opção:\n"
		 << "i - Inserir dado\n"
		 << "r - Remover dado\n"
		 << "l - Limpar todos os dados da fila\n"
		 << "e - Imprimir os dados da fila no terminal\n"
		 << "t - Imprimir o tamanho da fila\n"
		 << "h - Imprimir o primeiro da fila\n"
		 << "s - Sair do programa\n";

	cin >> opcao;

	while(opcao != 's') {
		switch(opcao) {
			case 'i':
				cout << "digite o dado para inserir: ";
				dado umDado;
				cin >> umDado;
				umaFila.insere(umDado);
				break;

			case 'r':
				dado removido;
				removido = umaFila.remove();
				cout << "dado removido: "
					 << removido << "\n";
				break;

			case 'l':
				umaFila.esvazia();
				break;

			case 'e':
				umaFila.imprime();
				break;

			case 't':
				cout << "tamanho: " << umaFila.getTamanho() << "\n";
				break;

			case 'h':
				cout << "primeiro: " << umaFila.getPrimeiro() << "\n";
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
		 	 << "l - Limpar todos os dados da fila\n"
		 	 << "e - Imprimir os dados da fila no terminal\n"
		 	 << "t - Imprimir o tamanho da fila\n"
		 	 << "h - Imprimir o primeiro da fila\n"
		 	 << "s - Sair do programa\n";

		cin >> opcao;
	}

	return 0;
}
