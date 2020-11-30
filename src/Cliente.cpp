#include <iostream>
#include <string>
#include "Cliente.hpp"

using namespace std;

Cliente::Cliente()
{
	nome;
	email;
	cpf;
	idade;
	socio;
}

Cliente::Cliente (string nome, string cpf, short int idade, string email, char socio)
{
	setNome(nome);
	setCpf(cpf);
	setIdade(idade);
	setEmail(email);
	setSocio(socio);
}

string Cliente::getNome()
{
	return nome;
}

void Cliente::setNome(string nome)
{
	this->nome = nome;
}

string Cliente::getCpf()
{
	return cpf;
}

void Cliente::setCpf(string cpf)
{
 	this->cpf = cpf;
}

short int Cliente::getIdade()
{
	return idade;
}

void Cliente::setIdade(short idade)
{
 	this->idade = idade;
}

string Cliente::getEmail()
{
	return email;
}

void Cliente::setEmail(string email)
{
 	this->email = email;
}

char Cliente::getSocio()
{
	return socio;
}

void Cliente::setSocio(char socio)
{
	this->socio = socio;
}
