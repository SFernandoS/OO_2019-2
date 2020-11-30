#include <iostream>

using namespace std;

int menu()
{
	char escolha;

	system("clear");
	cout << "Menu\n\n";
	cout << "1 - Venda;"<< endl;
	cout << "2 - Recomendação;"<< endl;
	cout << "3 - Estoque;"<< endl;
	cout << "0 - Sair.\n"<< endl;
	cout << "Digite alguma das opções acima: ";
	cin  >> escolha;

	return escolha;
}
