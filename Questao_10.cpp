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
	// C1: Cria ponteiro inteligente compartilhado 'ptr' do tipo Pessoa ("Sergio")
	auto ptr = make_shared<Pessoa>("Sergio");

	// C2: Utiliza a notacao de ponteiro, para invocar o metodo getNome().
	//		Imprime "Sergio" como resultado de getNome()
	cout << ptr->getNome() << endl;

	// C3: Utiliza o metodo get() do ponteiro inteligente que retorna um ponteiro comum
	// 		para a posição apontada pelo ponteiro inteligente. Esse ponteiro é passado
	// 		como parametro para a função quemEhEstaPessoa() que imprime na saída padrão
	// 		"Esta pessoa eh: Sergio"
	quemEhEstaPessoa(ptr.get());

	// C4: Cria um novo ponteiro inteligente compartilhado 'aquelaPessoa' a partir do ponteiro ptr
	//		já existente. Isso é permitido pois os ponteiros inteligentes são compartilhados (shared)
	shared_ptr<Pessoa> aquelaPessoa = ptr;

	// C5: Faz ptr1 apontar para outro objeto do tipo Pessoa ("Thiago").
	//		É chamado o destrutor do objeto apontado anteriormente que 
	//		imprime "Destruindo Ser..."
	ptr.reset(new Pessoa("Thiago"));

	// C6: Libera 'aquelaPessoa'
	aquelaPessoa.reset();

	return 0;
}