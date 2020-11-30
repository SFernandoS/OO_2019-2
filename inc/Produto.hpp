#include <iostream>
#include <string>

#ifndef PRODUTO_HPP
#define PRODUTO_HPP

using namespace std;

class Produto
{ 
private: 
	string nome;
	string tipo;
	string categoria;
	float preco;

public:
	
	Produto();
	Produto(string nome, string tipo, string categoria, float preco);
	~Produto();

	string getNome();
	void setNome(string nome);

	string getTipo();
	void setTipo(string tipo);

	string getCategoria();
	void setCategoria(string categoria);

	float getPreco();
	void setPreco(float preco);

};

#endif PRODUTO_HPP