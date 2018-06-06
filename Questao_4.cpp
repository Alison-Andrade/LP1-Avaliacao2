#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	double* d = new double[3];

	for(unsigned int i = 0; i < 3; i++) {
		d[i] = 1.5 + i;
	}

	for(int i = 2; i >= 0; i--) {
		cout << d[i] << endl;
	}

	delete [] d;
 
}

/*
		O primeiro erro encontrado foi no segundo 'for', pois 'i' era do tipo 'unsigned' e a medida que 
	ia executando o comando 'i--' acabava que i virava um numero negativo, como tipos unsigned só podem ser positivos 
	isso causava falha de segmentação.
		No valgrid apresentava também erros de alocação, pois ao instanciar 'd' como 'new double' era alocada apenas uma
	posição na memória para um valor double, mas eram inseridos 3 valores em 'd', fazendo dele um vetor, logo, a solução
	foi mudar a instanciação para 'new double[3]', e adicionar 'delete [] d' para liberar a memória alocada.
*/