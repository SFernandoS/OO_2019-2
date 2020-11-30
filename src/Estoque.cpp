#include <iostream>
#include <string>
#include "Estoque.hpp"

using namespace std;

Estoque::Estoque()
{	
	quantidade = 0;
}

Estoque::Estoque(string nome, string tipo, string categoria, float preco, short quantidade):Produto(nome,tipo,categoria,preco)
{

	setQuantidade(quantidade);
}

short Estoque::getQuantidade()
{
	return quantidade;
}

void Estoque::setQuantidade(short quantidade)
{
	this->quantidade = quantidade;
}
