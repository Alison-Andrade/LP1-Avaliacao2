/*
Questão 7

		-A herança de empregado havia sido definida como 'private Pessoa', assim todas as classes que herdassem 
	da classe Empregado não teria acesso aos atributos da classe Pessoa. A solução foi alterar a herança para
	public ou protected.
		-Ordem dos construtores e destrutores do objeto Aluno
			Pessoa() -> Aluno() -> ~Aluno() -> ~Pessoa()
		-Ordem dos construtores e destrutores do objeto Gerente
			Pessoa() -> Empregado() -> Gerente() -> ~Gerente() -> ~Empregado() -> Pessoa()

		-Seguem essa ordem pois em uma herança a ordem dos construtores segue da primeira classe base e em seguida todas 
	as derivadas até que chame o construtor da classe do objeto. Já os destrutores segue a ordem inversa, onde primeiro
	é chamado o destrutor da classe a qual o objeto pertence e em seguida os níveis acima.

*/

#include <iostream>

using namespace std;

class Pessoa {
public:
	string m_nome;
	int m_idade;
public:
	Pessoa(string nome_, int idade_): m_nome(nome_){};
	~Pessoa(){};
	string getNome(){ return m_nome; };
	int getIdade(){ return m_idade; };
};

class Empregado : public Pessoa {
private:
	string m_matricula;
	double m_salario;
public:
	Empregado(string nome_, int idade_, string matricula_, double
		salario_):
	Pessoa(nome_, idade_), m_matricula(matricula_), m_salario(salario_){};
	~Empregado(){};
	string getMatricula(){ return m_matricula; };
	double getSalario(){ return m_salario; };
};

class Aluno : public Pessoa {
private:
	string m_matricula;
public:
	Aluno(string nome_, int idade_, string matricula_):
	Pessoa(nome_ , idade_) , m_matricula(matricula_) {};
	~Aluno(){};
	string getMatricula(){ return m_matricula; };
};

class Vendedor : private Empregado {
private:
	double m_meta_mensal;
	double m_desconto_nivel1;
public :
	Vendedor(string nome_, int idade_, string matricula_, double
		salario_, double meta_, double desconto_) :
		Empregado(nome_, idade_, matricula_, salario_),
		m_meta_mensal(meta_), m_desconto_nivel1(desconto_){};
	~Vendedor(){};
	double getMetaMensal() { return m_meta_mensal; };
	double getDescontoN1() { return m_desconto_nivel1; };
};

class Gerente : private Empregado {
private:
	string m_setor;
	double m_desconto_nivel2 ;
public :
	Gerente(string nome_, int idade_, string matricula_, double salario_
		, string setor_, double desconto_) :
		Empregado(nome_, idade_, matricula_, salario_),
		m_setor(setor_), m_desconto_nivel2(desconto_){};
	~Gerente(){};
	string getSetor(){ return m_setor; };
	double getDescontoN2(){ return m_desconto_nivel2; };
	void imprimeDados(){ cout << "Nome: " << m_nome << " \t "
				<< "Idade " << m_idade << " \t "
				<< "Matricula: " << getMatricula() << endl
				<< "Salario: " << getSalario() << " \t "
				<< "Setor: " << m_setor << endl
				<< "Desconto N2: " << m_desconto_nivel2
				<< endl ; };
};

int main (int argc, char const* argv[])
{
	Aluno a("Maria de Lourdes", 22, "98765432-1");
	Gerente g("Emiliano Emilio", 45, "666000666-1", 5780.00, 
		"Departamento Financeiro", 7.5);
	g.imprimeDados();
	return 0;
}