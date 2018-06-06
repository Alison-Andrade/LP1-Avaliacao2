#include <iostream>
#include <memory>

using namespace std;

class Pessoa
{
private:
	string m_nome ;
public:
	Pessoa(string nome_): m_nome(nome_){};
	~Pessoa(){ cout << "Destruindo " << m_nome << "... " << endl ; };
	string getNome(){ return m_nome ; };
};

void quemEhEstaPessoa(Pessoa * p){
	cout << "Esta pessoa eh: " << p->getNome() << endl;
}

int main(int argc, char const *argv[])
{
	// C1: Cria um ponteiro inteligente ptr1 que aponta unicamente
	//		para a instancia (de Pessoa) "Maria". Nao altera a saida.
	unique_ptr<Pessoa> ptr1(new Pessoa("Maria"));

	// C2: Utiliza a notacao de ponteiro, permitida pelo ponteiro
	//		inteligente, para invocar o metodo getNome(). Imprime
	//		o string "Maria" na saida padrao, como resultado da
	//		execucao do metodo getNome().
	cout << ptr1->getNome() << endl;

	// C3: Utiliza a derreferência de ponteiro, para invocar o metodo getNome().
	//		Imprime o string "Maria" na saida padrao, como resultado da
	//		execucao do metodo getNome().
	cout << (*ptr1).getNome() << endl;

	// C4: Utiliza o metodo get() do ponteiro inteligente que retorna um ponteiro comum
	// 		para a posição apontada pelo ponteiro inteligente. Esse ponteiro é passado
	// 		como parametro para a função quemEhEstaPessoa() que imprime na saída padrão
	// 		"Esta pessoa eh: Maria"

	quemEhEstaPessoa (ptr1.get());

	// C5: Cria um ponteiro inteligente ptr2 unico e passa a posse da região apontada por
	//		por ptr1 para ptr2.	
	unique_ptr<Pessoa> ptr2(std::move(ptr1));

	// C6: Faz ptr1 apontar para outro objeto do tipo pessoa ("Joao").
	ptr1.reset(new Pessoa("Joao"));

	// C7:Faz ptr1 apontar para outro objeto do tipo pessoa.
	//		É chamado o destrutor do objeto apontado anteriormente que 
	//		imprime "Destruindo Maria..."
	ptr2.reset(new Pessoa("Marcos"));

	// C8: Libera ptr1
	//		É chamado o destrutor do objeto apontado anteriormente que 
	//		imprime "Destruindo Joao..."
	ptr1.reset();

	// C9: Libera ptr2 automaticamente
	//		É chamado o destrutor do objeto apontado anteriormente que 
	//		imprime "Destruindo Marcos..."

	return 0;
}