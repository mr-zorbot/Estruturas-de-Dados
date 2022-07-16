// Autor: Iann-Zorkot
// Licença: CC0 1.0 Universal
// Descrição: Implementação de Max Heap utilizando arranjos, desenvolvido para o curso de Estruturas de Dados -- DAC/UFLA

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef int dado; // Usado para mudar o tipo do Heap

class Heap {
	private:
		unsigned tamanho;
		unsigned capacidade;
		dado* vetorDados;

		// Métodos usados na correção da estrutura (não precisam ficar visíveis para o usuário)
		void corrigeDescendo(unsigned posicao);
		void corrigeSubindo(unsigned posicao);
		inline unsigned pai(unsigned posicao);
		inline unsigned esquerdo(unsigned posicao);
		inline unsigned direito(unsigned posicao);
	public:
		Heap(unsigned umaCapacidade);
		Heap(dado* umVetor, unsigned umTamanho);
		~Heap();
		void insere(dado umDado);
		dado remove();
		dado getRaiz();
};

// Constrói o Heap
Heap::Heap(unsigned umaCapacidade) {
	capacidade = umaCapacidade;
	tamanho = 0;
	vetorDados = new dado[capacidade];
}

// Constrói o Heap a partir de um vetor (Heapify)
Heap::Heap(dado* umVetor, unsigned umTamanho) {
	vetorDados = new dado[umTamanho];
	copy(umVetor, umVetor + umTamanho, vetorDados);
	tamanho = umTamanho;
	capacidade = umTamanho;

	for (int i=(tamanho/2); i>=0; i--)
		corrigeDescendo(i);
}

// Deleta o Heap
Heap::~Heap() {
	delete[] vetorDados;
}

// Retorna a posição do pai
unsigned Heap::pai(unsigned posicao) {
	return (posicao - 1)/2;
}

// Retorna a posição do filho esquerdo
unsigned Heap::esquerdo(unsigned posicao) {
	return (2 * posicao) + 1;
}

// Retorna a posição do filho direito
unsigned Heap::direito(unsigned posicao) {
	return (2 * posicao) + 2;
}

// Corrige o Heap comparando a posição com seus filhos
void Heap::corrigeDescendo(unsigned posicao) {
	unsigned filhoEsquerdo = esquerdo(posicao);
	unsigned filhoDireito = direito(posicao);
	unsigned maior = posicao;

	if ((filhoEsquerdo < tamanho) and (vetorDados[filhoEsquerdo] > vetorDados[maior]))
		maior = filhoEsquerdo;

	if ((filhoDireito < tamanho) and (vetorDados[filhoDireito] > vetorDados[maior]))
		maior = filhoDireito;

	if (maior != posicao) {
		swap(vetorDados[posicao], vetorDados[maior]);
		corrigeDescendo(maior);
	}
}

// Corrige o Heap comparando a posição com seu pai
void Heap::corrigeSubindo(unsigned posicao) {
	unsigned p = pai(posicao);
	if (vetorDados[posicao] > vetorDados[p]) {
		swap(vetorDados[posicao], vetorDados[p]);
		corrigeSubindo(p);
	}
}

// insere um dado no Heap
void Heap::insere(dado umDado) {
	if (tamanho == capacidade) {
		cerr << "Heap cheio!\n";
		exit(EXIT_FAILURE);
	}

	vetorDados[tamanho] = umDado;
	corrigeSubindo(tamanho);
	tamanho++;
}

// Remove e retorna o valor da raiz
dado Heap::remove() {
	if (tamanho == 0) {
		cerr << "Heap vazio!\n";
		exit(EXIT_FAILURE);
	}

	dado aux = vetorDados[0];
	swap(vetorDados[0], vetorDados[tamanho-1]);
	tamanho--;
	corrigeDescendo(0);
	return aux;
}

// Retorna a raiz do Heap sem remover
dado Heap::getRaiz() {
	if (tamanho == 0) {
		cerr << "Heap vazio!\n";
		exit(EXIT_FAILURE);
	}

	return vetorDados[0];
}

// Função principal para testes
int main () {
	unsigned tam = 10;
	dado vet[] = {50, 2, 90, 20, 230, 43, 8, 34, 66, 100};
	Heap h1(vet, tam);

	for (unsigned i=0; i<tam; i++) // Testa se o Heap está ordenando o vetor ao retirar os elementos (Heap Sort)
		cout << h1.remove() << " ";

	cout << "\n";

	return 0;
}
