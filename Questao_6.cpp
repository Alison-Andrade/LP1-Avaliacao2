#include <iostream>
#include <iomanip>

using namespace std ;

class Tempo
{
private :
	int hh, mm, ss;
public :
	// Le os dados do tempo a partir da entrada padrao
	void lerTempo(void);
	// Retorna o tempo em segundos
	int converteEmSegundos(void);
	// Imprime o tempo no formato HH:MM:SS e o seu total
	// em segundos
	void mostraTempo(void);

	friend istream& operator>>(istream& in, Tempo& T);
	friend ostream& operator<<(ostream& out, Tempo& T);
};

// Implementar os metodos ...

void
Tempo::lerTempo(){
	struct tm time;

	cout << "Digite o tempo no formato \"HH:MM:SS\" : ";

	cin >> get_time(&time,"%T");;

	hh = time.tm_hour;
	mm = time.tm_min;
	ss = time.tm_sec;

}

int
Tempo::converteEmSegundos(){
	int sec = (ss + (mm*60) + ((hh*60)*60));

	return sec;
}

void
Tempo::mostraTempo(){
	cout << hh << ":" << mm << ":" << ss << " tem o total de " << converteEmSegundos() << " segundos." << endl;
}

istream& operator>>(istream& in, Tempo& T){
	T.lerTempo();
	return in;
}

ostream& operator<<(ostream& out, Tempo& T){
	T.mostraTempo();
	return out;
}

int main()
{
	Tempo T ;
	cin >> T;
	cout << T;

	return 0;
}