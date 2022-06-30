
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>

#define MAX_PILOTOS 2
#define MAX_CIRCUITOS 2
#define MAX_VOLTAS 2

struct Piloto{				//estrutura dos pilotos
	int id, idade;
	char nome[50], sexo, pais[30];
};

struct Circuito{			//estrutura dos pilotos
	int id, id_menorTempo, menorTempo_minutos=9999, menorTempo_segundos=9999, menorTempo_milissegundos=9999;
	char nome[50], pais[20];
	float tamanho;
};

struct Volta{				//estrutura das voltas
	int id_piloto, id_circuito, data_dia, data_mes, data_ano, tempo_minutos, tempo_segundos, tempo_milissegundos;
	char nomeEquipe[50];
};

void cadastroPiloto(struct Piloto *piloto, int contadorPilotos, char **paises){		//Procedimento de cadastramento de pilotos
    int validaPais=0, i=0;
    
	do{
		printf("Digite a identificacao do piloto:\n");
		scanf("%d", &piloto[contadorPilotos].id);
        fflush(stdin);

        if (piloto[contadorPilotos].id < 100 || piloto[contadorPilotos].id > 500)
            printf("Numero de identificacao invalido!\n");

        for(i=0;i<MAX_PILOTOS;i++){
        		if((i != contadorPilotos) && (piloto[contadorPilotos].id == piloto[i].id)){		//verificacao caso o ID ja tenho sido utilizado
        		piloto[contadorPilotos].id = 0;												//caso ele já estiver sendo utilizado o valor sera modificado para 0, assim nao passando na validacao
        		printf("Numero de identificacao ja utilizado!\n");
        	}
        }
    }while(piloto[contadorPilotos].id < 100 || piloto[contadorPilotos].id > 500);

    do{
        printf("Digite a idade do piloto:\n");
        scanf("%d", &piloto[contadorPilotos].idade);
        fflush(stdin);
        if (piloto[contadorPilotos].idade < 18)
            printf("Idade do piloto invalida\n");
    }while(piloto[contadorPilotos].idade < 18);

    do{
        printf("Digite o nome do Piloto:\n");
        scanf("%[^\n]s", &piloto[contadorPilotos].nome);
        fflush(stdin);
        if (strlen(piloto[contadorPilotos].nome) < 1 || strlen(piloto[contadorPilotos].nome) > 50)
            printf("Nome do piloto invalido!\n");
    }while(strlen(piloto[contadorPilotos].nome) < 1 || strlen(piloto[contadorPilotos].nome) > 50);

    do{
        printf("Digite o sexo do Piloto: (m-masculino ou f-feminino)\n");
        scanf("%c", &piloto[contadorPilotos].sexo);
        piloto[contadorPilotos].sexo = toupper(piloto[contadorPilotos].sexo);
        fflush(stdin);
        if (piloto[contadorPilotos].sexo != 'M' && piloto[contadorPilotos].sexo != 'F')
            printf("Sexo do piloto invalido!\n");
    }while(piloto[contadorPilotos].sexo != 'M' && piloto[contadorPilotos].sexo != 'F');

    do{
        printf("Digite o pais de origem do piloto:\n");
        scanf("%[^\n]s", &piloto[contadorPilotos].pais);
        fflush(stdin);
        for (i=0; i < 11; i++){
            if (strcasecmp(piloto[contadorPilotos].pais, paises[i]) == 0){
                validaPais = 1;
            }
        }
        
        if(validaPais == 0)
        	printf("Pais do piloto invalido!\n");
    
    }while(validaPais != 1);
    
    printf("Piloto cadastrado com sucesso!\n");
    system("pause");

}

void cadastroCircuito(struct Circuito *circuito, int contadorCircuitos, char **paises){		//Procedimento de cadastramento de circuitos
	int validaPais=0, i=0;
    
	circuito[contadorCircuitos].id = contadorCircuitos +1;
	
	printf("ID do circuito: %d\n", circuito[contadorCircuitos].id);
	
    do{
        printf("Digite o nome do Circuito:\n");
        scanf("%[^\n]s", &circuito[contadorCircuitos].nome);
        fflush(stdin);
        if (strlen(circuito[contadorCircuitos].nome) < 1 || strlen(circuito[contadorCircuitos].nome) > 50)
            printf("Nome do piloto invalido!\n");
    }while(strlen(circuito[contadorCircuitos].nome) < 1 || strlen(circuito[contadorCircuitos].nome) > 50);

    do{
        printf("Digite o pais onde esta o circuito:\n");
        scanf("%[^\n]s", &circuito[contadorCircuitos].pais);
        fflush(stdin);
        for (i=0; i < 11; i++){					//validacao para que o nome do circuito seja um dos contidos no vetor de strings "paises"
            if (strcasecmp(circuito[contadorCircuitos].pais, paises[i]) == 0){
                validaPais = 1;
            }
        }
        
        if(validaPais == 0)
        	printf("Pais do circuito invalido!\n");
    
    }while(validaPais != 1);
    
    do{
    	printf("Digite o tamanho do circuito em KM:\n");
    	scanf("%f", &circuito[contadorCircuitos].tamanho);
    	fflush(stdin);
    		if(circuito[contadorCircuitos].tamanho<0)
    			printf("Tamanho do circuito invalido!\n");
	}while(circuito[contadorCircuitos].tamanho<0);
    
    printf("Circuito cadastrado com sucesso!\n");
	system("pause");
	
}

void cadastroVolta(struct Volta *volta, struct Piloto *piloto, struct Circuito *circuito, int contadorVoltas, int contadorPilotos, int contadorCircuitos){	//Procedimento de cadastramento de voltas
	int i, valida_id_piloto=0, valida_id_circuito=0;
	
	if((contadorPilotos = 0) || (contadorCircuitos = 0)){		//Caso o usuario nao tenha cadastrado ao menos um piloto ou circuito o procedimento acaba aqui
		printf("Sem registro de cadastro de pilotos e/ou circuitos!\n");
		system("pause");
		
	}else{
			do{
				printf("Digite o ID do piloto que fez essa volta:\n");
				scanf("%d", &volta[contadorVoltas].id_piloto);
				fflush(stdin);
				
				for(i=0; i<MAX_PILOTOS; i++){			//comparacao do id digitado com todos os ids de pilotos
					if(volta[contadorVoltas].id_piloto == piloto[i].id){
						valida_id_piloto = 1;
					}
				}
				
				if(valida_id_piloto == 0)
					printf("Esse piloto nao existe!\n");
			}while(valida_id_piloto == 0 );
			
			do{
				printf("Digite o ID do circuito onde foi feita a volta:\n");
				scanf("%d", &volta[contadorVoltas].id_circuito);
				fflush(stdin);
				
				for(i=0; i<MAX_CIRCUITOS; i++){			//comparacao do id digitado com todos os ids de circuitos
					if(volta[contadorVoltas].id_circuito == circuito[i].id){
						valida_id_circuito = 1;
					}
				}
				
				if(valida_id_circuito == 0)
					printf("Esse circuito nao existe!\n");
			}while(valida_id_circuito == 0 );
			
			do{
				printf("Digite o nome da equipe do piloto de realizou essa volta:\n");
				scanf("%[^\n]s", &volta[contadorVoltas].nomeEquipe);
				fflush(stdin);
				if(strlen(volta[contadorVoltas].nomeEquipe) < 1 || strlen(volta[contadorVoltas].nomeEquipe) > 50)
					printf("Nome da equipe invalido!\n");
			}while(strlen(volta[contadorVoltas].nomeEquipe) < 1 || strlen(volta[contadorVoltas].nomeEquipe) > 50);
			
			do{
				printf("Digite a data que foi realizada a volta: (dia/mes/ano)\n");
				scanf("%d %d %d", &volta[contadorVoltas].data_dia, &volta[contadorVoltas].data_mes, &volta[contadorVoltas].data_ano);
				fflush(stdin);
				if((volta[contadorVoltas].data_dia < 1 || volta[contadorVoltas].data_dia > 31) || (volta[contadorVoltas].data_mes < 1 || volta[contadorVoltas].data_mes > 12) || (volta[contadorVoltas].data_ano < 1950 || volta[contadorVoltas].data_ano > 2023))
					printf("Data invalida!\n");
			}while((volta[contadorVoltas].data_dia < 1 || volta[contadorVoltas].data_dia > 31) || (volta[contadorVoltas].data_mes < 1 || volta[contadorVoltas].data_mes > 12) || (volta[contadorVoltas].data_ano < 1950 || volta[contadorVoltas].data_ano > 2023));
			
			do{
				printf("Digite o tempo da volta (minutos / segundos / milissegundos):\n");
				scanf("%d %d %d", &volta[contadorVoltas].tempo_minutos, &volta[contadorVoltas].tempo_segundos, &volta[contadorVoltas].tempo_milissegundos);
				fflush(stdin);
				if(volta[contadorVoltas].tempo_minutos < 0 || volta[contadorVoltas].tempo_segundos < 0 || volta[contadorVoltas].tempo_milissegundos < 0)
					printf("Tempo da volta invalido!\n");
			}while(volta[contadorVoltas].tempo_minutos < 0 || volta[contadorVoltas].tempo_segundos < 0 || volta[contadorVoltas].tempo_milissegundos < 0);
			
			for(i=0; i<MAX_CIRCUITOS; i++){				//estrutura de repeticao para a substituicao do tempo digitado fique como menor tempo, caso o tempo seja menor
				if((volta[contadorVoltas].tempo_milissegundos <= circuito[i].menorTempo_milissegundos) && (volta[contadorVoltas].tempo_segundos >= circuito[i].menorTempo_segundos) && (volta[contadorVoltas].tempo_minutos >= circuito[i].menorTempo_minutos)){
					circuito[i].menorTempo_milissegundos = volta[contadorVoltas].tempo_milissegundos;
					circuito[i].menorTempo_segundos = volta[contadorVoltas].tempo_segundos;
					circuito[i].menorTempo_minutos = volta[contadorVoltas].tempo_segundos;
				}else
				if((volta[contadorVoltas].tempo_segundos <= circuito[i].menorTempo_segundos) && (volta[contadorVoltas].tempo_minutos >= circuito[i].menorTempo_minutos)){
					circuito[i].menorTempo_milissegundos = volta[contadorVoltas].tempo_milissegundos;
					circuito[i].menorTempo_segundos = volta[contadorVoltas].tempo_segundos;
					circuito[i].menorTempo_minutos = volta[contadorVoltas].tempo_segundos;
				}else
				if(volta[contadorVoltas].tempo_minutos <= circuito[i].menorTempo_minutos){
					circuito[i].menorTempo_milissegundos = volta[contadorVoltas].tempo_milissegundos;
					circuito[i].menorTempo_segundos = volta[contadorVoltas].tempo_segundos;
					circuito[i].menorTempo_minutos = volta[contadorVoltas].tempo_segundos;
				}
			}	
			
			printf("Volta cadastrada com sucesso!\n");
			system("pause");
		
	}
}

void consultaPilotos(struct Piloto *piloto, int contadorPilotos){		//Procedimento de consulta de pilotos cadastrados
	int i;
	
	if(contadorPilotos == 0){
		printf("Nao houve cadastro de pilotos!\n");
	}else{
		for(i=0; i<contadorPilotos; i++){
			printf("ID: %d\n", piloto[i].id);
			printf("Nome: %s\n", piloto[i].nome);
			printf("Idade: %d\n", piloto[i].idade);
			printf("Sexo: %c\n", piloto[i].sexo);
			printf("Pais: %s\n", piloto[i].pais);
			printf("__________________________\n");
		}
	}
	
	system("pause");
}

void consultaCircuitos(struct Circuito *circuito, int contadorCircuitos){		//Procedimento de consulta de circuitos cadastrados
	int i;
	
	if(contadorCircuitos == 0){
		printf("Nao houve cadastro de circuitos!\n");
	}else{
		for(i=0; i<contadorCircuitos; i++){
			printf("ID: %d\n", circuito[i].id);
			printf("Nome: %s\n", circuito[i].nome);
			printf("Pais: %s\n", circuito[i].pais);
			printf("Tamanho: %.2fkm", circuito[i].tamanho);
			printf("__________________________\n");
		}
	}
	
	system("pause");
}

void consultaVoltas(struct Volta *volta, int contadorVoltas){		//Procedimento de consulta de voltas cadastradas
	int i;
	
	if(contadorVoltas == 0){
		printf("Nao houve cadastro de voltas!\n");
	}else{
		for(i=0; i<contadorVoltas; i++){
			printf("ID do piloto:: %d\n", volta[i].id_piloto);
			printf("ID do circuito: %d\n", volta[i].id_circuito);
			printf("Nome da equipe: %s\n", volta[i].nomeEquipe);
			printf("Data: %d/%d/%d\n", volta[i].data_dia, volta[i].data_mes, volta[i].data_ano);
			printf("Tempo: %dm %ds %dms \n", volta[i].tempo_minutos, volta[i].tempo_segundos, volta[i].tempo_milissegundos);
			printf("__________________________\n");
		}
	}
	
	system("pause");
}

void consultaPeloNome(struct Piloto *piloto, int contadorPilotos){		//Procedimento para consultar os dados de um piloto pelo nome dele
	int i, validaPesquisaNome=0;
	char pesquisaNome[50];
	
	if(contadorPilotos == 0){
		printf("Nao houve cadastro de pilotos!\n");
		
	}else{
		do{
			printf("Digite o nome do piloto que deseja pesquisar:\n");
			scanf("%[^\n]s", &pesquisaNome);
			fflush(stdin);
			for(i=0; i<MAX_PILOTOS; i++){		//validacao para checar se o nome consta em algum cadastro
				if(strcasecmp(pesquisaNome, piloto[i].nome) == 0){
					validaPesquisaNome = 1;
				}
			}
			
			if(validaPesquisaNome == 0)
				printf("Nome nao consta em nenhum cadastro!\n");
			
		}while(validaPesquisaNome!=1);
		
		
		for(i=0; i<MAX_PILOTOS; i++){			//caso o nome passe na validacao ele sera buscado e printado
			if (strcasecmp(pesquisaNome, piloto[i].nome) == 0){
				printf("__________________________\n");
				printf("ID: %d\n", piloto[i].id);
				printf("Nome: %s\n", piloto[i].nome);
				printf("Idade: %d\n", piloto[i].idade);
				printf("Sexo: %c\n", piloto[i].sexo);
				printf("Pais: %s\n", piloto[i].pais);
				printf("__________________________\n");
			}
	
		}
	}
	system("pause");
}

void consultaVoltaPeloCircuito(struct Piloto *Piloto, struct Circuito *circuito, struct Volta *volta,int contadorPilotos, int contadorCircuitos, int contadorVoltas){		//Procedimento para consultar as voltas em um circuito pelo nome do circuito
	int i, j, pesquisaCircuito, validaPesquisaCircuito=0, ausenciaVoltas;


	if((contadorPilotos == 0) || (contadorCircuitos == 0)){		//Caso o usuario nao tenha cadastrado ao menos um piloto ou circuito o procedimento acaba aqui
		printf("Nao houve cadastro de voltas!\n");
		system("pause");
		
	}else{
		do{
			printf("Digite o ID do circuito que deseja pesquisar:\n");
			scanf("%d", &pesquisaCircuito);
			for(i=0; i<MAX_CIRCUITOS; i++){
				if(pesquisaCircuito = circuito[i].id)
					validaPesquisaCircuito = 1;
			}
		
			if(validaPesquisaCircuito == 0)
				printf("Esse ID de circuito nao existe!\n");
				
		}while(validaPesquisaCircuito == 0);
		
		for(i=0; i<MAX_CIRCUITOS; i++){
			if(pesquisaCircuito = circuito[i].id){
				for(i=0; i<MAX_CIRCUITOS; i++){
					if(circuito[i].id == volta[j].id_circuito){
						printf("_____________________________\n");
						printf("ID do piloto: %d\n", volta[j].id_piloto);
						printf("Nome da equipe: %s\n", volta[i].nomeEquipe);
						printf("Data da volta: %d/%d/%d\n", volta[i].data_dia, volta[i].data_mes, volta[i].data_ano);
						printf("Tempo da volta: %dm %ds %dms\n", volta[i].tempo_minutos, volta[i].tempo_segundos, volta[i].tempo_milissegundos);
						printf("_____________________________\n");
					}
				}
			}
		}
		
		system("pause");
	}
}

void consultaVoltaTempoMenor(struct Volta *volta, int contadorVoltas){		//Procedimento para pesquisar um tempo, e mostrar as voltas com tempo menor
	int i, pesquisaTempo_minutos, pesquisaTempo_segundos, pesquisaTempo_milissegundos;
	
	if(contadorVoltas == 0){
		printf("Nao houve cadastro de voltas!");
	}else{
		printf("Digite o tempo que deseja pesquisar (Minutos / Segundos / Milissegundos):\n");
		scanf("%d %d %d", &pesquisaTempo_minutos, &pesquisaTempo_segundos, &pesquisaTempo_milissegundos);

		for(i=0; i<MAX_VOLTAS; i++){
			if(pesquisaTempo_minutos >= volta[i].tempo_minutos){
				printf("______________________________\n");
				printf("ID do piloto: %d\n", volta[i].id_piloto);
				printf("ID do circuito: %d\n,", volta[i].id_circuito);
				printf("Nome da equipe: %s\n", volta[i].nomeEquipe);
				printf("Data da volta: %d/%d/%d\n", volta[i].data_dia, volta[i].data_mes, volta[i].data_ano);
				printf("Tempo da volta: %dm %ds %dms\n", volta[i].tempo_minutos, volta[i].tempo_segundos, volta[i].tempo_milissegundos);
				printf("______________________________\n");
			}
		}
	}
	
}

int main(){

	int menu1, menuCadastro, menuRelatorio, menuConsulta;
	int contadorPilotos=0, contadorCircuitos=0, contadorVoltas=0;
	char *paises[] = {"Brasil", "Austria", "Franca", "Finlandia", "Australia", "Alemanha", "Inglaterra", "Argentina", "Espanha", "Canada", "Holanda"};		//declaracao do vetor de strings para validacao de paises

	struct Piloto piloto[MAX_PILOTOS];
	struct Circuito circuito[MAX_CIRCUITOS];
	struct Volta volta[MAX_VOLTAS];

	do{
		do{
			system("cls");
			printf(" Programa de Acompanhamento da Formula 1\n");
			printf("________________________________________\n");				//menu principal
			printf("1 - Menu de Cadastro\n");
			printf("2 - Menu de Relatorios\n");
			printf("3 - Finalizar Programa\n");
			printf("________________________\n");
			printf("Digite a opcao desejada:\n");
			scanf("%d", &menu1);
			fflush(stdin);
		}while(menu1 < 1 || menu1 > 3);

		switch(menu1){
			case 1:
				do{
					do{
						system("cls");
						printf("Menu de Cadastro\n");
						printf("____________________\n");		//menu de cadastro (piloto, circuitos e voltas)
						printf("1 - Cadastrar Piloto\n");
						printf("2 - Cadastrar Circuito\n");
						printf("3 - Cadastrar Volta\n");
						printf("4 - Voltar ao Menu Principal\n");
						printf("____________________________\n");
						printf("Digite a opcao desejada:\n");
						scanf("%d", &menuCadastro);
						fflush(stdin);
					}while(menuCadastro < 1 || menuCadastro > 4);
					
					switch(menuCadastro){
					
						case 1:
							system("cls");
							cadastroPiloto(piloto, contadorPilotos, paises);
							contadorPilotos = contadorPilotos + 1;
						break;
						
						case 2:
							system("cls");
							cadastroCircuito(circuito, contadorCircuitos, paises);
							contadorCircuitos = contadorCircuitos + 1;
						break;
						
						case 3:
							system("cls");
							cadastroVolta(volta, piloto, circuito, contadorVoltas, contadorPilotos, contadorCircuitos);
							contadorVoltas = contadorVoltas + 1;
						break;
						
						case 4:
							system("cls");
							printf("Retornando ao menu principal...\n");
							system("pause");
						break;
					}
				}while(menuCadastro!=4);
			break;
			
			case 2:
				do{
					do{
						system("cls");
						printf("Menu de Geracao de Relatorios\n");
						printf("___________________________________________\n");		//menu de relatorios
						printf("1 - Consulta de Pilotos, Circuitos e Voltas\n");
						printf("2 - Pesquisar Piloto pelo nome\n");
						printf("3 - Pesquisar voltas pelo circuito\n");
						printf("4 - Pesquisar voltas menores ao tempo digitado\n");
						printf("5 - Voltar ao Menu Principal\n");
						printf("______________________________________________\n");
						printf("Digite a opcao desejada:\n");
						scanf("%d", &menuRelatorio);
						fflush(stdin);
					}while(menuRelatorio < 1 || menuRelatorio > 5);
					
					switch(menuRelatorio){
						case 1:
							do{
								do{
									system("cls");						//menu de consulta
									printf("_________________________________\n");
									printf("1 - Consultar Pilotos cadastrados\n");
									printf("2 - Consultar Circuitos cadastrados\n");
									printf("3 - Consultar Voltas cadastradas\n");
									printf("4 - Retornar ao menu de Relatorios\n");
									printf("__________________________________\n");
									printf("Digite a opcao desejada:\n");
									scanf("%d", &menuConsulta);
									fflush(stdin);
								}while(menuRelatorio < 1 || menuRelatorio > 4);
								
									switch(menuConsulta){
										case 1:
											system("cls");
											consultaPilotos(piloto, contadorPilotos);
											break;
										case 2:
											system("cls");
											consultaCircuitos(circuito, contadorCircuitos);
											break;
										case 3:
											system("cls");
											consultaVoltas(volta, contadorVoltas);
											break;
										case 4:
											system("cls");
											printf("Retornando ao menu de relatorios...\n");
											system("pause");
											break;
									}
							}while(menuConsulta!=4);
						break;
						
						case 2:
							system("cls");
							consultaPeloNome(piloto, contadorPilotos);
						break;
						
						case 3:
							system("cls");
							consultaVoltaPeloCircuito(piloto, circuito, volta, contadorPilotos, contadorCircuitos, contadorVoltas);
						break;
						
						case 4:
							system("cls");
							consultaVoltaTempoMenor(volta, contadorVoltas);
						case 5:
							system("cls");
							printf("Retornando ao menu principal...\n");
							system("pause");
						break;
					}
				}while(menuRelatorio!=5);

			case 3:
				system("cls");
				printf("Fim do Programa!\n");
		}
	}while(menu1!=3);
		
	return 0;
}
