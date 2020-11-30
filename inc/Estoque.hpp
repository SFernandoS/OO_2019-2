#include <iostream>
#include <string>
#include "Produto.hpp"

using namespace std;

class Estoque: public Produto
{
private:
	short quantidade;

public:
	Estoque();
	Estoque(string nome, string tipo, string categoria, float preco,short quantidade);
	~Estoque();
	
	short getQuantidade();
	void setQuantidade(short quantidade);
};
