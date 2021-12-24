#include <iostream>
#include <stdlib.h>

	using namespace std;

	int topoP, topoC,topoF, compras;
	string nomesCliente[20] = {"","","","","","","","","","","","","","","","","","","",""};
	string nomesFuncionario[20] = {"","","","","","","","","","","","","","","","","","","",""};
	double valorPagar = 0, totalPago[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},  
	totalVendido[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
	
//================================================================================//

		void menuPrincipal(){
		cout<<"	Menu Principal         					     "<<endl;
		cout<<" �rea para Funcionarios:"<<endl;
		cout<<"	1 - Cadastrar produtos   					 "<<endl; 
		cout<<"	2 - Cadastrar cliente para cart�o fidelidade "<<endl;
		cout<<"	3 - Cadastrar funcionario					 "<<endl;
		cout<<"	4 - Editar produtos/clientes/funcionarios    "<<endl;
		cout<<"	5 - Relatorios          					 "<<endl; 
		cout<<"	6 - Exibir produtos/clientes/funcionarios	 "<<endl;
		cout<<" �rea para clientes:							 "<<endl;
		cout<<"	7 - Comprar produtos     					 "<<endl;
		cout<<"	8 - sair								     "<<endl;
	}
	
//================================================================================//
	struct mercadoria{
		int id;
		string nome;
		string categoria;
		double valor;
		int quantidade;
	};
	
	mercadoria superMercado[20];
	
	struct cliente{
		int idCliente;
		string nome;
		int idade;
	};
	
	cliente clienteMercado[20];
	
	struct funcionario{
		int idFuncionario;
		string nome;
		int idade;
		int anoDeContratacao;
		float vendasRealizadas;
	};
	
	funcionario funcionarioMercado[20];
	
//=========================================================================================================//

	bool validaIdProduto(int idProduto){
	bool valida = false;
	for(int i = 0; i < topoP; i++){
		if(superMercado[i].id == idProduto ){
			valida = true;			
			break;
		}
	}
	return valida;
}

	bool validaIdCliente(int idCliente){
	bool valida = false;
	for(int i = 0; i < topoC; i++){
		if(clienteMercado[i].idCliente == idCliente ){
			valida = true;			
			break;
		}
	}
	return valida;
}

	bool validaIdFuncionario(int idFuncionario){
	bool valida = false;
	for(int i = 0; i < topoF; i++){
		if(funcionarioMercado[i].idFuncionario == idFuncionario ){
			valida = true;			
			break;
		}
	}
	return valida;
}

	bool produtoExiste(string nomeProd){
	bool valida = false;
	for(int i = 0; i < topoP; i++){
		if(superMercado[i].nome == nomeProd ){
			valida = true;			
			break;
		}
	}
	return valida;
}

	bool funcionarioExiste(string nomeFunc){
	bool valida = false;
	for(int i = 0; i < topoF; i++){
		if(funcionarioMercado[i].nome == nomeFunc ){
			valida = true;			
			break;
		}
	}
	return valida;
}

bool clienteExiste(string nomeCliente){
	bool valida = false;
	for(int i = 0; i < topoC; i++){
		if(clienteMercado[i].nome == nomeCliente ){
			valida = true;			
			break;
		}
	}
	return valida;
}
//=========================================================================================================//
	void cadastrarProduto(){
		int res;
		float senha;
		
		cout<< " 	 � funcionario? digite a senha para ter acesso!!"<<endl;
		cin>>senha;
		
		do{
			if(senha == 123456){
			do{
			cout<<"		CADASTRAR PRODUTO: "<<endl;
		int idProduto = 0, quantidade;
		string nome;
			
		for(int i = 0; i < 10; i++){
			if(superMercado[i].id == 0){
				cout<<" 	Informe o id do produto, favor inserir somente NUMEROS"<<endl;
				cin>>idProduto;
				
			if(validaIdProduto(idProduto)){
				cout<<" 	Por favor, informe um ID que ainda n�o tenha sido cadastrado!"<<endl;
				break;
				
			}else{
				cout<<"		Informe o nome do produto "<<endl;
				cin>>nome;
				
				if(produtoExiste(nome)){
					cout<<" 	Este produto j� existe em estoque, favor ir em menu -> adicionar produto"<<endl;
					break;
				}
				superMercado[i].id = idProduto;	
				superMercado[i].nome = nome;	
				cout<<"		Informe a categoria do produto "<<endl;
				cin>>superMercado[i].categoria;
				cout<<"		Informe o valor do produto "<<endl;
				cin>>superMercado[i].valor;
				cout<<"		Informe a quantidade do produto "<<endl;
				cin>>superMercado[i].quantidade;
				topoP++;
				break;
				
			}	
		}
	}
			cout<<"		Cadastrar outro produto? [1 - sim | 2 - n�o]"<<endl;
			cin>>res;
		}while(res != 2);
		}
		if(res == 2){
			senha = 123;
		}
			
		}while(senha == 123456);
		
}
//=========================================================================================================//
	void cadastrarCliente(){
		int res, respCliente;
		float senha;
		
		cout<< " 	� funcionario? digite a senha para ter acesso!!"<<endl;
		cin>>senha;
		
		do{
			if(senha == 123456){	
			 do{
			cout<<"		CADASTRAR CLIENTE: "<<endl;
		int idCliente = 0, idade;
		string nome;
			
		for(int i = 0; i < 10; i++){
			if(clienteMercado[i].idCliente == 0){
				cout<<" 	Informe um id para o Cliente:"<<endl;
				cin>>idCliente;
				
				if(validaIdCliente (idCliente)){
					cout<<"		Por favor, informe um ID que ainda n�o tenha sido cadastrado!"<<endl;
					break;
				
				}else{
					cout<<"		Informe o nome do cliente "<<endl;
					cin>>nome;
					cout<<"		Informe a idade do cliente "<<endl;
					cin>>idade;
			
					clienteMercado[i].idCliente = idCliente;	
					clienteMercado[i].nome = nome;	
					clienteMercado[i].idade = idade;
					topoC++;
					break;
			}	
		}
	}
			cout<<"		Cadastrar outro Cliente? [1 - sim | 2 - n�o]"<<endl;
			cin>>res;
		}while(res != 2);
		}else{
			cout<<" 	Senha incorreta, digite a senha novamente! | 1- sair"<<endl;
			cin>>senha;
		}
			cout<<"		Deseja voltar ao menu? [1 - sim | 2 - Cadastrar novo cliente]"<<endl;
			cin>>respCliente;
		}while(respCliente != 1);
}

//================================================================================//
	void cadastrarFuncionario(){
		int res, respFuncionario;
		float senha;
		
		cout<< " 	� funcionario? digite a senha para ter acesso!!"<<endl;
		cin>>senha;
		
			if(senha == 123456){
			 do{
			cout<<"		CADASTRAR FUNCIONARIO: "<<endl;
		int idFuncionario = 0, idade, anoDeContratacao;
		string nome;
			
		for(int i = 0; i < 10; i++){
			if(funcionarioMercado[i].idFuncionario == 0){
				cout<<" 	Informe um id para o funcionario:"<<endl;
				cin>>idFuncionario;
				
			if(validaIdFuncionario(idFuncionario)){
				cout<<" 	Por favor, informe um ID que ainda n�o tenha sido cadastrado!"<<endl;
				break;
				
			}else{
				cout<<"		Informe o nome do funcionario "<<endl;
				cin>>nome;
				cout<<"		Informe a idade do funcionario "<<endl;
				cin>>idade;
				cout<<"		Informe a ano de contrata��o do funcionario "<<endl;
				cin>>anoDeContratacao;
				
				funcionarioMercado[i].idFuncionario = idFuncionario;	
				funcionarioMercado[i].nome = nome;	
				funcionarioMercado[i].idade = idade;
				funcionarioMercado[i].anoDeContratacao = anoDeContratacao;
				topoF++;
				break;
				
			}	
		}
	}
			cout<<"		Cadastrar outro funcionario? [1 - sim | 2 - n�o]"<<endl;
			cin>>res;
		}while(res != 2);
		}else{
			cout<<" 	Senha incorreta, digite a senha novamente! | 1- sair"<<endl;
			cin>>senha;
		}
		
}
//================================================================================//

	void exibirProdutos(){
		cout<<"		PRODUTOS  "<<endl;
		for(int i = 0; i < topoP; i++){
			cout<<" 	ID: "<<superMercado[i].id<<endl;
			cout<<" 	Nome: "<<superMercado[i].nome<<endl;
			cout<<" 	Categoria: "<<superMercado[i].categoria<<endl;
			cout<<" 	Valor: R$ "<<superMercado[i].valor<<" reais a unidade"<<endl;
			cout<<" 	Quantidade: "<<superMercado[i].quantidade<<" kg de "<<superMercado[i].nome<<" em estoque"<<endl;
			cout<<"========================================================="<<endl;
	}
}
	void exibirNomeProdutos(){
		cout<<"		PRODUTOS  "<<endl;
		for(int i = 0; i < topoP; i++){
			cout<<" 	Nome: "<<superMercado[i].nome<<endl;
			cout<<" 	Valor: R$ "<<superMercado[i].valor<<" reais a unidade"<<endl;
			cout<<"========================================================="<<endl;
	}
}
//================================================================================//
	void exibirClientes(){
		cout<<"		CLIENTES "<<endl;
		for(int i = 0; i < topoC; i++){
			cout<<" 	ID: "<<clienteMercado[i].idCliente<<endl;
			cout<<" 	Nome: "<<clienteMercado[i].nome<<endl;
			cout<<" 	Idade: "<<clienteMercado[i].idade<<endl;
			cout<<"========================================================="<<endl;
	}
}
//================================================================================//
	void exibirFuncionarios(){
		
		cout<<"		FUNCIONARIOS  "<<endl;
		for(int i = 0; i < topoF; i++){
			cout<<" 	ID: "<<funcionarioMercado[i].idFuncionario<<endl;
			cout<<" 	Nome: "<<funcionarioMercado[i].nome<<endl;
			cout<<" 	Idade: "<<funcionarioMercado[i].idade<<endl;
			cout<<" 	Ano de contrata��o: "<<funcionarioMercado[i].anoDeContratacao<<endl;
			cout<<"========================================================="<<endl;
	}
}
	void exibirNomeFuncionarios(){
		
		cout<<"		NOMES FUNCIONARIOS  "<<endl;
		for(int i = 0; i < topoF; i++){
			cout<<" 	Nome: "<<funcionarioMercado[i].nome<<endl;
			cout<<" 	Vendas: "<<funcionarioMercado[i].vendasRealizadas<<" esta semana"<<endl;
			cout<<"========================================================="<<endl;
	}
}

//================================================================================//
	void editarProduto(){
		int quantAdd, senha;
		string nome, propriedade;
		
		cout<< " 	� funcionario? digite a senha para ter acesso!!"<<endl;
		cin>>senha;
		
		if(senha == 123456){
		cout<<"		Informe o nome item que desejas editar do estoque"<<endl;
		exibirProdutos();
		cin>>nome;
		if(produtoExiste(nome)){
			cout<<"		O que gostaria de editar no item "<<nome<<": nome, categoria, quantidade, valor ou id "<<endl;
			cin>>propriedade;
		
		if(propriedade == "quantidade"){
			for(int i = 0; i < topoP; i++){
			if(superMercado[i].nome == nome){
				cout<<" 	Informe a quantidade que ir� adicionar ao estoque"<<endl;
				cin>>quantAdd;
				double novaQuant = superMercado[i].quantidade + quantAdd;
				cout<<" 	Antes tinha "<<superMercado[i].quantidade<<" itens, agora tem: "<<novaQuant<<" itens de "<<superMercado[i].nome<<endl;
				superMercado[i].quantidade = novaQuant;				
			}
		}
	}
		if(propriedade == "nome"){
			for(int i = 0; i < topoP; i++){
			if(superMercado[i].nome == nome){
				cout<<" 	Informe o novo nome do item"<<endl;
				cin>>superMercado[i].nome;
				cout<<" 	Novo nome do produto: "<<superMercado[i].nome<<endl;
			}
		}
	}
		if(propriedade == "categoria"){
			for(int i = 0; i < topoP; i++){
			if(superMercado[i].nome == nome){
				cout<<" 	Informe a nova categoria do item"<<endl;
				cin>>superMercado[i].categoria;
				cout<<" 	Nova categoria do produto: "<<superMercado[i].categoria<<endl;
			}
		}
	}
		if(propriedade == "valor"){
			for(int i = 0; i < topoP; i++){
			if(superMercado[i].nome == nome){
				cout<<" 	Informe o novo valor do item"<<endl;
				cin>>superMercado[i].valor;
				cout<<" 	Novo valor do produto: "<<superMercado[i].valor<<endl;
			}
		}
	}	
		if(propriedade == "id"){
			for(int i = 0; i < topoP; i++){
			if(superMercado[i].nome == nome){
				cout<<" 	Informe o novo id do item"<<endl;
				cin>>superMercado[i].id;
				cout<<" 	Novo id do produto: "<<superMercado[i].id<<endl;
			}
		}
	}	
		}else{
				cout<<" 	N�o escontramos esse produto em nosso sistema"<<endl;
		}
}else{
			cout<<" 	SENHA INCORRETA!!"<<endl;
		}
};

//============================================================================================================//
void editarCliente(){
		int senha;
		string nome, propriedade;
		
		cout<< " 	� funcionario? digite a senha para ter acesso!!"<<endl;
		cin>>senha;
		
		if(senha == 123456){
		cout<<"		Informe o nome do cliente  que desejas editar"<<endl;
		exibirClientes();
		cin>>nome;
		if(clienteExiste(nome)){
			cout<<"		O que gostaria de editar do cliente "<<nome<<": nome, idade ou id "<<endl;
			cin>>propriedade;
		
		
		if(propriedade == "nome"){
			for(int i = 0; i < topoC; i++){
			if(clienteMercado[i].nome == nome){
				cout<<" 	Informe o novo nome do cliente"<<endl;
				cin>>clienteMercado[i].nome;
				cout<<" 	Novo nome do cliente: "<<clienteMercado[i].nome<<endl;
			}
		}
	}
	
		if(propriedade == "idade"){
			for(int i = 0; i < topoC; i++){
			if(clienteMercado[i].nome == nome){
				cout<<" 	Informe a nova idade do cliente"<<endl;
				cin>>clienteMercado[i].idade;
				cout<<" 	Nova idade do cliente: "<<clienteMercado[i].idade<<endl;
			}
		}
	}
		if(propriedade == "id"){
			for(int i = 0; i < topoC; i++){
			if(clienteMercado[i].nome == nome){
				cout<<" 	Informe o novo id do cliente"<<endl;
				cin>>clienteMercado[i].idCliente;
				cout<<" 	Novo id do cliente: "<<clienteMercado[i].idCliente<<endl;
			}
		}
	}
		
	
		}else{
				cout<<" 	N�o escontramos esse produto em nosso sistema"<<endl;
		}
}else{
			cout<<" 	SENHA INCORRETA!!"<<endl;
		}
};

//============================================================================================================//
void editarFuncionario(){
		int senha;
		string nome, propriedade;
		
		cout<< " 	� funcionario? digite a senha para ter acesso!!"<<endl;
		cin>>senha;
		
		if(senha == 123456){
		cout<<"		Informe o nome do funcionario  que desejas editar"<<endl;
		exibirFuncionarios();
		cin>>nome;
		if(funcionarioExiste(nome)){
			cout<<"		O que gostaria de editar do funcionario "<<nome<<": id, nome, idade, ou anoContrata��o: "<<endl;
			cin>>propriedade;
		
		if(propriedade == "anoContrata��o"){
				for(int i = 0; i < topoF; i++){
				if(funcionarioMercado[i].nome == nome){
					cout<<" 	Informe o ano de contrata��o correto do funcionario"<<endl;
					cin>>funcionarioMercado[i].anoDeContratacao;
					cout<<" 	Correto ano de contrata��o do funcionario: "<<funcionarioMercado[i].idade<<endl;
			}
		}
	}
		if(propriedade == "idade"){
					for(int i = 0; i < topoF; i++){
					if(funcionarioMercado[i].nome == nome){
						cout<<" 	Informe a nova idade do funcionario"<<endl;
						cin>>funcionarioMercado[i].idade;
						cout<<" 	Nova idade do funcionario: "<<funcionarioMercado[i].idade<<endl;
				}
			}
		}
		
		if(propriedade == "nome"){
			for(int i = 0; i < topoF; i++){
			if(funcionarioMercado[i].nome == nome){
				cout<<" 	Informe o novo nome do funcionario"<<endl;
				cin>>funcionarioMercado[i].nome;
				cout<<" 	Novo nome do funcionario: "<<funcionarioMercado[i].nome<<endl;
			}
		}
	}
		if(propriedade == "id"){
				for(int i = 0; i < topoF; i++){
				if(funcionarioMercado[i].nome == nome){
					cout<<" 	Informe o novo id do funcionario"<<endl;
					cin>>funcionarioMercado[i].idFuncionario;
					cout<<" 	Novo id do funcionario: "<<funcionarioMercado[i].idFuncionario<<endl;
			}
		}
	}
	
		
		
	
		}else{
				cout<<" 	N�o escontramos esse produto em nosso sistema"<<endl;
		}
}else{
			cout<<" 	SENHA INCORRETA!!"<<endl;
		}
};

//============================================================================================================//

	void comprarProdutos(){
		string nome, nomeCliente, nomeFuncionario;
		
		double  quantidade, res, valorTotal, clientes, novaQuantidade, respostaCliente;
		
			exibirFuncionarios();
			cout<<" 	Seja bem vindo � sess�o de compras, qual o nome do atendente?"<<endl;
			cin>>nomeFuncionario;
			
			if(!funcionarioExiste(nomeFuncionario)){
				cout<<" 	N�o existe esse funcionario cadastrado no nosso banco de dados"<<endl;
			}else{
			
			cout<<"		Qual o nome do cliente?"<<endl;
			cin>>nomeCliente;
			if(!clienteExiste(nomeCliente)){
				cout<<" 	Gostaria de realizar o cadastro para cart�o fideliza��o? 1- Sim | 2- N�o"<<endl;
				cin>>respostaCliente;
				if(respostaCliente == 1){
					cadastrarCliente();
				}
				
			}else{
				compras++;
		
		do{
			
			exibirNomeProdutos();
			
			cout<<" 	Ol� "<<nomeCliente<<" informe o nome do produto que gostaria de comprar?"<<endl;
			cin>>nome;
			
			
			if(!produtoExiste(nome)){
				cout<<" 	Favor escreva corretamente o nome do produto"<<endl;
			}else{
				
			cout<<" 	Qual a quantidade de itens que gostaria de adicionar ao carrinho?"<<endl;	
			cin>>quantidade;
					
					for(int i=0; i<topoP; i++){
						if(superMercado[i].nome == nome){
							if(superMercado[i].quantidade >= quantidade){
						 valorPagar = superMercado[i].valor * quantidade;
						 novaQuantidade =  superMercado[i].quantidade - quantidade;
						 superMercado[i].quantidade = novaQuantidade;						 
							}else{
						 cout<<" 	Nao temos quantidade suficiente deste produto em nosso estoque"<<endl;
						 return;
					}
				}
			}
						valorTotal = valorPagar + valorTotal;
					cout<<" 	Valor a pagar: R$"<<valorTotal<<endl;
					cout<<" 	Gostaria de realizar mais alguma compra?[1 - sim | 2 - n�o]"<<endl;
					cin>>res;
					
					if(res == 2){
						cout<<" 	Pagamento realizado com sucesso, volte sempre"<<endl;
						for(int i=0; i < compras; i++){
							if(nomesCliente[i]== ""){
								nomesCliente[i] = nomeCliente;
								break;
							}
						}
						for(int i=0; i < compras; i++){
							if(nomesFuncionario[i]== ""){
								nomesFuncionario[i] = nomeFuncionario;
								break;
							}
						}
							for(int i=0; i < compras; i++){
							if(totalPago[i] == 0){
								totalPago[i] = valorTotal;
								break;
							}
						}
					}
							for(int i= 0; i < compras; i++){
							if(funcionarioMercado[i].nome == nomeFuncionario){
								funcionarioMercado[i].vendasRealizadas += 1;
							}
						}
			}
				
		}while(res != 2);	
			}
			
			}
			
	}
//==========================================================================================================//
	
	void relatorios(){
		int res, senha;
		float soma=0, total=0;
		
		cout<< " 	� funcionario? digite a senha para ter acesso!!"<<endl;
		cin>>senha;
		
		if(senha == 123456){
		
		cout<<" 	BEM VINDO(A) AO RELATORIO		"<<endl;
		cout<<" 	1- Clientes e Pagamentos		"<<endl;
		cout<<" 	2- Rendimento total do mercado  "<<endl;
		cout<<" 	3- Vendas por funcionario       "<<endl;
		cout<<" 	4- Voltar ao menu				"<<endl;
		cin>>res;
		
		if(res == 1){
			cout<<" 	Abaixo poder� verificar os clientes e suas compras"<<endl;
			for(int i=0; i<compras; i++){
				cout<<" 	Cliente: "<<nomesCliente[i]<<"  || Pagamento: R$"<<totalPago[i]<<" || Atendente: "<<nomesFuncionario[i]<<endl;
			}
		}
		if(res == 2){
			cout<<" 				Rendimento do mercado"<<endl;
			for(int i=0; i<compras; i++){
				soma += totalPago[i];
			}
			cout<<" 				No caixa tem: R$"<<soma<<" reais"<<endl;
		}
		if(res == 3){
			cout<<"                 Vendas por funcionario"<<endl;
			exibirNomeFuncionarios();
		}
		
		}else{
			cout<<" 	SENHA INCORRETA!!"<<endl;
		}
	}
	
int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int op;
	int resp;
	
	do{
		system("cls");	
		menuPrincipal();
		cout<<"	Informe a op��o desejada "<<endl;
		cin>>op;
		
		if(op == 1){
			cadastrarProduto();
			system("cls");		
		}
		
		if(op == 2){
			cadastrarCliente();
			system("cls");		
		}
	
		if(op == 3){
			cadastrarFuncionario();
			system("cls");
		}
			
		if(op == 4){
			int resCl, resExi;
			do{
				cout<<" 	1- Editar Produtos"<<endl;
				cout<<" 	2- Editar Clientes"<<endl;
				cout<<" 	3- Editar Funcionarios"<<endl;
				cout<<" 	4- Voltar ao menu"<<endl;
				cin>>resExi;
				
				if(resExi == 1){
					editarProduto();
				}
				if(resExi == 2){
					editarCliente();
				}
				if(resExi == 3){
					editarFuncionario();
				}
				if(resExi == 4){
					break;				
				}
				if(resExi < 4){
				cout<<" 	Gostaria de editar mais alguma coisa? 1- sim | 0 - n�o"<<endl;
				cin>>resCl;	
				}
				
				
			}while(resCl == 1);
	}
				
		if(op == 6){
			int resCl, resExi;
			do{
				cout<<" 	1- Exibir Lista de Produtos"<<endl;
				cout<<" 	2- Exibir Lista de Clientes"<<endl;
				cout<<" 	3- Exibir Lista de Funcionarios"<<endl;
				cout<<" 	4- Voltar ao menu"<<endl;
				cin>>resExi;
				
				if(resExi == 1){
					exibirProdutos();
				}
				if(resExi == 2){
					exibirClientes();
				}
				if(resExi == 3){
					exibirFuncionarios();
				}
				if(resExi == 4){
					break;				
				}
				if(resExi < 4){
				cout<<" 	Gostaria de exibir mais alguma coisa? 1- sim | 0 - n�o"<<endl;
				cin>>resCl;	
				}
				
				
			}while(resCl == 1);
			
		}
		if(op == 7){
			//Comprar produtos
			comprarProdutos();
		}
		if(op == 5){
			relatorios();
		}	
		if(op == 8 ){
			cout<<"		SISTEMA ENCERRADO";
			resp = 2;
		}	
		
		if(op >= 3  && op != 8){
			cout<<"		Deseja voltar ao menu principal? [1 = SIM || 2 = N�O]"<<endl;
			cin>>resp;	
		}
	
		
	}while(resp == 1);
}
