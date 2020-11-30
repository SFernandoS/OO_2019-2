#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

#include "Menu.hpp"
#include "Produto.hpp"
#include "Carrinho.hpp"
#include "Cliente.hpp"
#include "Estoque.hpp"

using namespace std;

Cliente *novoCliente(Cliente *);
Estoque *novoProduto(Estoque *);
Estoque *novaCategoria(Estoque *);

void lerArquivos();
void venda();
void attCategoria();
void attProduto();
void Recomendacao();

vector<Cliente *> novo;
vector<Estoque *> novo_produto;
vector<Estoque *> nova_categoria;
vector<Carrinho *> compras;

template <typename in>

in getInput()
{
    while(true)
    {
    	in valor;
   		cin >> valor;
    	if(cin.fail())
    	{
        	cin.clear();
        	cin.ignore(32767,'\n');
       		cout << "Entrada inválida! Insira novamente: " << endl;
    	}
    	else
    	{
       		cin.ignore(32767,'\n');
       	 	return valor;
    	}
    }
}


int menu();

int main()
{

	lerArquivos();

	while(true)
	{
		 switch(menu())
		 {
		 	case '1':
		 		venda();
		 	break;

		 	case '2':
		 		Recomendacao();
		 	break;

		 	case '3':
		 		{
		 			char escolha;
		 			system("clear");

		 			cout <<"1 - Cadastrar produto;"<< endl;
		 			cout <<"2 - Cadastrar categoria;" << endl;
		 			cout <<"3 - Atualizar produto;" << endl;
		 			cout <<"4 - Atualizar categoria;"<< endl;
		 			cout <<"5 - Para listar produtos cadastrados;"<<endl;
		 			cout <<"6 - Para listar categorias cadastradas;"<<endl;
		 			cout <<"0 - Para sair."<<endl;

		 			cin >> escolha;

		 			switch(escolha)
		 			{
		 				case '1':
		 				{
		 					Estoque *cria = novoProduto(cria);
		 					novo_produto.push_back(cria);
		 				}
		 				break;

		 				case '2':
		 				{
		 					Estoque *cria = novaCategoria(cria);
		 					nova_categoria.push_back(cria);
		 				}
		 				break;

		 				case '3':	
		 					attProduto();
		 				break;

		 				case '4':
		 					attCategoria();
		 				break;
		 				case'5':
		 				{
		 					system("clear");
		 					for (unsigned i = 0; i < novo_produto.size(); ++i)
							 {	
	 						 	cout <<"\nCategoria: ........... "<< novo_produto[i]->getCategoria()<<endl;
	 						 	cout <<"Nome:................. "<< novo_produto[i]->getNome()<<endl;
	 						 	cout <<"Tipo:................. "<< novo_produto[i]->getTipo()<<endl;
	 						 	cout <<"Preco:................ "<< novo_produto[i]->getPreco()<<endl;
	 						 	cout <<"Quantidade:........... "<< novo_produto[i]->getQuantidade()<<endl;
	 						 	cout <<"------------------------------------------------------------------";
	 						 		
		 					}
		 					cout << "\n\nPressione qualquer tecla para continuar..." << endl;
							getchar();	
   							getchar();
		 				}
		 				break;
		 				case'6':
		 				system("clear");
		 				{
		 					for (unsigned i = 0; i < novo_produto.size(); ++i)
							{	
	 						 	cout <<"\nCategoria: ........... "<< novo_produto[i]->getCategoria()<<endl;
	 						 	cout <<"------------------------------------------------------------------"<< endl;
		 					}
		 					cout << "\n\nPressione qualquer tecla para continuar..." << endl;
   							getchar();
    						getchar();
		 				}
		 				break;

		 				case '0':
		 				break;
		 			}
		 		}
		 	break;

		 	case '0':
		 	return 0;
		 	break;

		 	default:
		 	system("clear");
		 	cout <<"Erro: tente novamente!\n"<< endl;
		 	break;
		 } 
	}

	return 0;
}

Cliente *novoCliente(Cliente *cria)
{
	string nome;
	string email;
	string cpf;
	short idade;
	char socio;

	system("clear");

	cout << "Digite o nome: ";
	cin.ignore();
	getline(cin, nome);

	for (unsigned i = 0; i < nome.size(); ++i)
		nome[i] = toupper(nome[i]);

	cout << "\nDigite o cpf: ";
	cin.ignore();
	getline(cin,cpf);

	cout << "\nDigite a idade: ";
	idade = getInput<int>();

	cout << "\nDigite o email: ";
	cin.ignore();
	getline(cin,email);

	for (unsigned i = 0; i < email.size(); ++i)
		email[i] = toupper(email[i]);

	do
	{
		cout << "\nDigite '1' se o Cliente deseja se tornar sócio, caso contrário '2': ";
		cin >> socio;
	}while(socio != '1' && socio != '2');

	cria = new Cliente(nome,cpf,idade,email,socio);

	ofstream ACliente;

	ACliente.open("doc/Clientes.txt",ofstream::app);

	ACliente << endl <<nome << endl;
	ACliente << cpf << endl;
	ACliente << idade << endl;
	ACliente << email << endl;
	ACliente << socio << endl;

	ACliente.close();

	return cria;
}

Estoque *novoProduto(Estoque *cria)
{
	string nome;
	string tipo;
	string categoria;
	string verifica;
	bool confirma = false;
	float quantidade;
	float preco;

	system("clear");

	cout <<"Digite o nome do produto: ";
	cin.ignore();
	getline(cin,nome);

	for (unsigned i = 0; i < nome.size(); ++i)
		nome[i] = toupper(nome[i]);

	cout <<"\nDigite o tipo do produto: ";
	getline(cin,tipo);

	for (unsigned i = 0; i < tipo.size(); ++i)
		tipo[i] = toupper(tipo[i]);

	cout <<"\nDigite a categoria do produto: ";
	getline(cin,categoria);

	for (unsigned i = 0; i < categoria.size(); ++i)
		categoria[i] = toupper(categoria[i]);

	cout <<"\nDigite o preco do produto: ";
	preco = getInput<float>();

	cout <<"\nDigite a quantidade: ";
	quantidade = getInput<int>();

	cria = new Estoque(nome,tipo,categoria,preco,quantidade);


	ofstream AProdutos;

	AProdutos.open("doc/Produtos.txt",ofstream::app);

	AProdutos << nome << endl;
	AProdutos << tipo << endl;
	AProdutos << categoria << endl;
	AProdutos << preco << endl;
	AProdutos << quantidade << endl;

	AProdutos.close();


		ifstream ACategoria;

		ACategoria.open("doc/Categoria.txt");

		while(ACategoria >> verifica)
		{
			if (verifica == categoria)
				confirma = true;
		}
		ACategoria.close();

		if (confirma == false)
		{
			ofstream ACategoria;

			ACategoria.open("doc/Categoria.txt",ofstream::app);

			ACategoria << endl <<categoria << endl;

			ACategoria.close();	

		}


	cout <<"Produto cadastrado com sucesso!"<< endl << endl;
	cout << "\n\nPressione qualquer tecla para continuar..." << endl;
    getchar();
    getchar();

	return cria;
}

Estoque *novaCategoria(Estoque *cria)
{
	string nome = "NULL";
	string tipo = "NULL";
	float quantidade = 0;
	float preco = 0;
	string categoria;

	system ("clear");

	cout <<"Digite o nome da categoria: ";
	cin.ignore();
	getline(cin, categoria);

	for (unsigned i = 0; i < categoria.size(); ++i)
		categoria[i] = toupper(categoria[i]);

	cria = new Estoque(nome,tipo,categoria,preco,quantidade);

	ofstream ACategoria;

	ACategoria.open("doc/Categoria.txt",ofstream::app);

	ACategoria << endl <<categoria << endl;

	ACategoria.close();

	cout << "Categoria cadastrada com sucesso" << endl << endl;
	cout << "\n\nPressione qualquer tecla para continuar..." << endl;
    getchar();
    getchar();

	return cria;
}


void lerArquivos()
{
	Cliente *lerC;
	Estoque *lerP;
	string nome, cpf, email, tipo, categoria;
	char socio;
	short idade, quantidade;
	float preco;

	ifstream RCliente;

	RCliente.open("doc/Clientes.txt");


	while(RCliente >> nome >> cpf >> idade >> email >> socio)
	{
		lerC = new Cliente(nome,cpf,idade,email,socio);	
		novo.push_back(lerC);
	}

	RCliente.close();

	ifstream RProdutos;

	RProdutos.open("doc/Produtos.txt");

	while(RProdutos >> nome >> tipo >> categoria >> preco >> quantidade)
	{
		lerP = new Estoque(nome,tipo,categoria,preco,quantidade);
		novo_produto.push_back(lerP);
	} 
	RProdutos.close();
}

void venda()
{
	char continuar, escolha;
	string procura;
	string compra, lista[100];
	Carrinho *venda;
	unsigned short quantidade,encontrado = 0, o = 0, QtdComprada[100],k = 0, socio = 0;

	system("clear");

	 do
	{
	 	cout <<"\nO cliente já tem cadastro? (s/n)"<< endl;
		cin >> escolha;
		if (escolha != 's' && escolha != 'n')
			cout <<"\nEntrada inválida. Tente novamente"<< endl;
		system("clear");
	}
	while(escolha != 's' && escolha !='n');

	if(escolha == 'n')
	{
		Cliente *cria;
		cria = novoCliente(cria);
		novo.push_back(cria);
	}
	else
	{
		do
		{
			cout << "Digite o nome do cliente: ";
			cin >> procura;

			for (unsigned i = 0; i < procura.size(); ++i)
				procura[i] = toupper(procura[i]);

			for (unsigned i = 0; i < novo.size(); ++i)
			{
				if(procura == novo[i]->getNome())
				{
					if(novo[i]->getSocio() == 1)
						socio = 1;
					encontrado = 1;
				}
			}

			if (encontrado == 0)
				cout << "\n\nCliente não encontrado, Tente novamente \n\n";

		}
		while(encontrado == 0);
	}

	encontrado = 0;

	system("clear");

	cout << "\n\n.................LISTA DE PRODUTOS....................."<< endl << endl;


	for (unsigned i = 0; i < novo_produto.size(); ++i)
	{
		cout <<novo_produto[i]->getNome() << "......................."<< novo_produto[i]->getPreco()<< endl;
		cout <<"-------------------------------------------------------"<< endl;
	}	

	do
	{
		do
		{
			cout <<"\n\nDigite o nome do produto a ser comprado: ";
			cin >> compra;

			for (unsigned i = 0; i < compra.size(); ++i)
				compra[i] = toupper(compra[i]);

			for (unsigned i = 0; i < novo_produto.size(); ++i)
			{
				if(compra == novo_produto[i]->getNome())
				{
					venda = new Carrinho(procura,novo_produto[i]->getTipo(),novo_produto[i]->getCategoria(),novo_produto[i]->getPreco(),0);
					compras.push_back(venda);
					encontrado = 1;
				}
			}

			if (encontrado == 0)
			{
				system ("clear");
				cout << "\n\nProduto não encontrado. Tente novamente \n\n";
			}
		}
		while(encontrado == 0);

		cout <<"\nDigite a quantidade: ";
		quantidade = getInput<int>();;

		for (unsigned i = 0; i < novo_produto.size(); ++i)
		{
			if(compra == novo_produto[i]->getNome())
			{
				if(quantidade > novo_produto[i]->getQuantidade())
				{
					cout << "Error: Quantidade maior que o estoque" << endl;
					cout << "Venda Cancelada";
					break;
				}
				else
				{
					lista[k] = compra;
					QtdComprada[k] = quantidade;
					++k;
					++o;
					compras[0]->setTotal(compras[0]->getTotal()+ compras[0]->getPreco()*quantidade);
				}
			}		
		}

		cout <<"\n\nDeseja continuar comprando? (s/n): ";
		cin >> continuar;

	}
	while(continuar == 's');

	system("clear");

	cout << "Lista de produtos comprados:"<< endl << endl;

	for (unsigned i = 0; i < o; ++i)
		cout << QtdComprada[i] << " x " << lista[i] << endl;
	cout << "-----------------------------------------------------"<< endl << endl;

	if (socio == 0)
	{
		cout << "Desconto oferecido 0%"<< endl;
		cout <<"Total a pegar: " << compras[0]->getTotal() << endl;					
	}
	else
	{
		cout << "Desconto oferecido 15 %"<< endl;
		cout <<"Total a pegar: " << compras[0]->getTotal()*0.85 << endl;
	}

	ofstream ARecomenda;

	ARecomenda.open("doc/Carrinho.txt",ofstream::app);

	if (escolha == 's')
		ARecomenda <<procura<<endl;
	else
		ARecomenda << novo[novo.size()-1]->getNome() << endl;
	
	ARecomenda <<compras[0]->getCategoria()<<endl;

	ARecomenda.close();

	cout << "\n\nPressione qualquer tecla para continuar..." << endl;
    getchar();
    getchar();

}

void attCategoria()
{
	char escolha;
	system("clear");
	cout << "1 - Para atualizar o nome da categoria;"<< endl;
	cout << "2 - Para excluir categoria"<< endl;

	do
	{
		cin >> escolha;
		if (escolha != '1' && escolha != '2')
			cout << "\n Entrada inválida tente novamente: ";
	}
	while(escolha != '1' && escolha != '2');

	if(escolha == '1')
	{
		string nome;
		string novo;

		system ("clear");
		cout <<"\nDigite o nome da categoria: ";
		cin >> nome;

		for (unsigned i = 0; i < nome.size(); ++i)
			nome[i] = toupper(nome[i]);

		cout <<"\nDigite a novo nome da categoria: ";
		cin >> novo;

		for (unsigned i = 0; i < novo.size(); ++i)
			novo[i] = toupper(novo[i]);	 			

		for (unsigned i = 0; i < novo_produto.size(); ++i)
		{
		 	if(nome == novo_produto[i]->getNome())
		 		novo_produto[i]->setNome(novo);

		}
	}
	else
	{
		system ("clear");

		string nome;

		cout <<"Digite o nome da categoria a ser excluída: ";

		cin >> nome;

		for (unsigned i = 0; i < nome.size(); ++i)
			nome[i] = toupper(nome[i]);

		for (unsigned i = 0; i < novo_produto.size(); ++i)
		{
		 	if(nome == novo_produto[i]->getCategoria())
		 		novo_produto.erase(novo_produto.begin()+i);
		 }

		cout << "\n\n A categoria, se existir, foi excluida com sucesso!"<< endl << endl;
		cout << "\n\nPressione qualquer tecla para continuar..." << endl;
    	getchar();
    	getchar();
	}
}

void attProduto()
{
	char escolha;
	system("clear");
	cout << "1 - Para atualizar a quantidade do produto;"<< endl;
	cout << "2 - Para excluir o produto"<< endl;

	do
	{
		cin >> escolha;
		if (escolha != '1' && escolha != '2')
			cout << "\nEntrada inválida. Tente novamente: ";
	}
	while(escolha != '1' && escolha != '2');

	if(escolha == '1')
	{
		string nome;
		int quantidade;

		system ("clear");
		cout <<"Digite o nome do produto: ";
		cin >> nome;

		for (unsigned i = 0; i < nome.size(); ++i)
			nome[i] = toupper(nome[i]);

		cout <<"\nDigite a nova quantidade: ";
		quantidade = getInput<int>();		 			

		for (unsigned i = 0; i < novo_produto.size(); ++i)
		{
			if(nome == novo_produto[i]->getNome())
				novo_produto[i]->setQuantidade(quantidade);

		}
	}
	else
	{
		system ("clear");

		string nome;
		cout <<"Digite o nome do produto a ser excluido: ";
	 	cin >> nome;

	 	for (unsigned i = 0; i < nome.size(); ++i)
			nome[i] = toupper(nome[i]);

		for (unsigned i = 0; i < novo_produto.size(); ++i)
		{
		 	if(nome == novo_produto[i]->getNome())
		 		novo_produto.erase(novo_produto.begin()+i);
		}
	}
}

void Recomendacao()
{	
	string procura, nome, categoria;
	string recomenda, lista[9], alfabetico[9], prod, prodsuc; 
	short encontrado = 0, Conta10 = 1;
	short unsigned contaLista = 0;

	system("clear");

	while(encontrado == 0)
	{
		cout << "Digite o nome do cliente: ";
		cin >> procura;

		for (unsigned i = 0; i < procura.size(); ++i)
			procura[i] = toupper(procura[i]);

		for (unsigned i = 0; i < novo.size(); ++i)
		{
			if (novo[i]->getNome() == procura)
			{
				encontrado = 1;
				break;
			}
			if(encontrado == 0 && i == novo.size() - 1)
			{
				cout << "\n\nCliente não encontrado. Tente novamente.\n\n";
			}
		}
	}

	system("clear");

	cout <<"Lista de Recomendacao"<< endl << endl << endl;

	ifstream RCarrinho;

	RCarrinho.open("doc/Carrinho.txt");

	while(RCarrinho >> nome >> categoria)
	{
		if (nome == procura)
		{
			recomenda = categoria;

			for (unsigned i = 0; i < novo_produto.size(); ++i)
			{

				if (recomenda == novo_produto[i]->getCategoria())
				{

					lista[contaLista] = novo_produto[i]->getNome();
					++contaLista;
					++Conta10;

					if (Conta10 == 9)
					{
						break;
					}
				}
			}
		}
		if (Conta10 == 9)
		{
			break;
		}
	}

	for (unsigned i = 0; i < contaLista; ++i)
		cout << lista [i] << endl;

	RCarrinho.close();


	if(contaLista < 10)
	{
		for (unsigned i = 1; i < novo_produto.size() && i < 10 ; ++i)
		{
			prod = novo_produto[i - 1]->getNome();
			prodsuc = novo_produto[i]->getNome();

			if (prod[i] > prodsuc[i])
			{
				alfabetico[i - 1] = prod;
				alfabetico[i] = prodsuc;
			}
			else if(prod[i] < prodsuc[i])
				alfabetico[i] = prod;
		}
	}

	cout << "\n\nCompletando alfabéticamente" << endl << endl;

	for (unsigned i = contaLista; i < 10; ++i)
		cout << alfabetico[i - contaLista] << endl;
		
    cout << "\n\nPressione qualquer tecla para continuar..." << endl;
    getchar();
    getchar();
}