#include <iostream>
#include <string>
#include "Produto.hpp"
#include "Carrinho.hpp"
#include "Estoque.hpp"

using namespace std;

Produto::Produto()
{
	nome;
	tipo;
	categoria;
	preco;
}

Produto::Produto (string nome, string tipo, string categoria, float preco)
{
	setNome(nome);
	setTipo(tipo);
	setCategoria(categoria);
	setPreco(preco);
}

string Produto::getNome()
{
	return nome;
}

void Produto::setNome(string nome)
{
	this->nome = nome;
}

string Produto::getTipo()
{
	return tipo;
}

void Produto::setTipo(string tipo)
{
	this->tipo = tipo;
}

string Produto::getCategoria()
{
	return categoria;
}

void Produto::setCategoria(string categoria)
{
	this->categoria = categoria;
}

float Produto::getPreco()
{
	return preco;
}

void Produto::setPreco(float preco)
{
	this->preco = preco;
}