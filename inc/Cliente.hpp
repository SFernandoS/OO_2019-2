#include <string>
#include <iostream>

using namespace std;

class Cliente
{
private:
	string nome;
 	string email;
 	string cpf;
 	short idade;
 	char socio;

public:
	Cliente();
	Cliente(string nome, string cpf, short idade, string email,char socio);
	~Cliente();
	
 	string getNome();
 	void setNome(string nome);

 	string getEmail();
 	void setEmail(string email);

 	string getCpf();
 	void setCpf(string cpf);

 	short int getIdade();
 	void setIdade(short idade);

 	char getSocio();
 	void setSocio(char socio);
	
};

