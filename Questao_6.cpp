#include <iostream>
#include <iomanip>

using namespace std ;

class Tempo
{
private :
	int hh, mm, ss;
public :

	int converteEmSegundos(void);

	friend istream& operator>>(istream& in, Tempo& T);
	friend ostream& operator<<(ostream& out, Tempo& T);
};

int
Tempo::converteEmSegundos(){
	int sec = (ss + (mm*60) + ((hh*60)*60));

	return sec;
}

istream& operator>>(istream& in, Tempo& T){
	struct tm time;

	cout << "Digite o tempo no formato \"HH:MM:SS\" : ";

	cin >> get_time(&time,"%T");;

	T.hh = time.tm_hour;
	T.mm = time.tm_min;
	T.ss = time.tm_sec;
	return in;
}

ostream& operator<<(ostream& out, Tempo& T){
	cout << T.hh << ":" << T.mm << ":" << T.ss << " tem o total de " << T.converteEmSegundos() << " segundos." << endl;
	return out;
}

int main()
{
	Tempo T ;
	cin >> T;
	cout << T;

	return 0;
}