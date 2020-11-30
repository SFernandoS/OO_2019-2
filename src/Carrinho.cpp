#include <iostream>
#include <string>
#include "Carrinho.hpp"

using namespace std;

Carrinho::Carrinho()
{	
	total = 0;
}

Carrinho::Carrinho(string nome, string tipo, string categoria, float preco,float total): Produto(nome,tipo,categoria,preco)
{

	setTotal(total);
}

float Carrinho::getTotal()
{
	return total;
}

void Carrinho::setTotal(float total)
{
	this->total = total;
}