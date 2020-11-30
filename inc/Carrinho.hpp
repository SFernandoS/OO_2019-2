#include <iostream>
#include <string>
#include "Produto.hpp"

using namespace std;

class Carrinho: public Produto
{
private:
	float total =0;

public:

	Carrinho();
	Carrinho(string nome, string tipo, string categoria, float preco,float total);
	~Carrinho();

	float getTotal();
	void setTotal(float total);
};

