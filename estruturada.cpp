// Gustavo Henrique Dantas UC20100755
// Caio Lucas Lima Carneiro UC21104476

#include <stdio.h>	// Biblioteca padrao do C
#include <ctype.h>	//Biblioteca para funcoes para manupulacoes de caracteres
#include <string.h> // Biblioteca para manipulacoes e concatenacoes de strings
#include <stdlib.h> // Biblioteca com as funcoes basicas de c
#include <locale.h> // Biblioteca para utilizar acentos e caracteres diferentes dependendo do idioma
#include <math.h>	// Biblioteca para importar funcoes matematicas

// Definindo constantes para armazenar valores os quais nao podem ser modificados

#define MAX_PILOTOS 50
#define MAX_CIRCUITOS 50
#define MAX_VOLTAS 50
// Todos estes valores podem ser alterados no futuro caso haja necessidade

// Criando uma funcao void para mostrar os menus quando a chamar dentro do main, para poupar codigo
void menu_inicial()
{
	system("cls");
	printf("\n===== Bem vindo ao F1 =====\n\n");
	printf("===== ===== ===== =====\n");
	printf("I) Cadastro\n");
	printf("II) Relatorios \n");
	printf("III) Encerrar \n");
	printf("===== ===== ===== =====\n");
	printf(" ");
}
// Criando uma funcao void para mostrar os menus quando a chamar dentro do main, para poupar codigo
void menu_cadastro()
{
	system("cls");
	printf("\n===== Cadastramento =====\n\n");
	printf("===== ===== ===== =====\n");
	printf("I) Piloto\n");
	printf("II) Circuito \n");
	printf("III) Volta \n");
	printf("IV) Sair\n");
	printf("===== ===== ===== =====\n");
	printf(" ");
}
// Criando uma funcao void para mostrar os menus quando a chamar dentro do main, para poupar codigo
void menu_relatorio()
{
	system("cls");
	printf("\n===== Relatorios =====\n\n");
	printf("===== ===== ===== =====\n");
	printf("I) Pilotos/Circuitos/Voltas\n");
	printf("II) Pesquisar Piloto \n");
	printf("III) Pesquisar Circuto \n");
	printf("IV) Pesquisar menor tempo\n");
	printf("V) Sair \n");
	printf("===== ===== ===== =====\n");
	printf(" ");
}
// Criando uma funcao void para mostrar os menus quando a chamar dentro do main, para poupar codigo
void menu_consulta()
{
	system("cls");

	printf("\n===== Consultas =====\n\n");
	printf("===== ===== ===== =====\n");
	printf("I) Piloto\n");
	printf("II) Circuito \n");
	printf("III) Volta \n");
	printf("IV) Sair\n");
	printf("===== ===== ===== =====\n");
	printf(" ");
}
// Criando um struct de Circuitos para armazenar informacoes que serao utilizadas futuramente no codigo
struct Circuito
{
	int idnt, idnt_MnT, MnT_m = 100000000, MnT_s = 100000000, MnT_mls = 100000000;
	char nome[50], pais[50];
	float tam;
};
// Criando um struct de Voltas para armazenar informacoes que serao utilizadas futuramente no codigo
struct Volta
{
	int idnt_piloto, dia, ano, idnt_circuito, mes, Tmp_m, Tmp_s, Tmp_mls;
	char equipe[50];
};
// Criando um struct de Pilotos para armazenar informacoes que serao utilizadas futuramente no codigo
struct Piloto
{
	int idnt, idade;
	char nome[50], sexo, pais[50];
};

// Criando uma funcao void para poder cadastrar os circuitos quando for chamada dentro do main
void cadastro_circuito(struct Circuito *circuito, int cont_circuito, char **paises)
{
	int valPais = 0, i = 0;

	circuito[cont_circuito].idnt = cont_circuito + 1;

	printf("ID do circuito: %d\n", circuito[cont_circuito].idnt);

	do
	{
		printf("Pais do circuito:\n");
		scanf("%[^\n]s", &circuito[cont_circuito].pais);
		fflush(stdin);
		// for utilizado para repeticoes
		for (i = 0; i < 11; i++)
		{
			// stricmp funcao utilizada para comprar duas strings
			if (stricmp(circuito[cont_circuito].pais, paises[i]) == 0)
			{
				valPais = 1;
			}
		}

		if (valPais == 0)
			printf("Pais do circuito invalido!\n");

	} while (valPais != 1);

	do
	{
		printf("Tamanho do circuito em KM:\n");
		scanf("%f", &circuito[cont_circuito].tam);
		fflush(stdin);
		if (circuito[cont_circuito].tam < 0)
			printf("tamanho do circuito invalido!\n");
	} while (circuito[cont_circuito].tam < 0);

	do
	{
		printf("Nome do Circuito:\n");
		scanf("%[^\n]s", &circuito[cont_circuito].nome);
		fflush(stdin);
		// strlen utilizado para chegar quantos caracteres ha na string
		if (strlen(circuito[cont_circuito].nome) < 1 || strlen(circuito[cont_circuito].nome) > 50)
			printf("Circuito invalido!\n");
	} while (strlen(circuito[cont_circuito].nome) < 1 || strlen(circuito[cont_circuito].nome) > 50);

	printf("Cadastro concluido\n");
	system("pause");
}

// Criando uma funcao void para poder cadastrar as voltas do circuito quando for chamada dentro do main
void cadastro_voltas(struct Volta *volta, struct Piloto *piloto, struct Circuito *circuito, int cont_voltas, int cont_piloto, int cont_circuito)
{
	int i, valida_idnt_piloto = 0, valida_idnt_circuito = 0;

	if ((cont_piloto = 0) || (cont_circuito = 0))
	{
		printf("Nao ha registros de pilotos ou circuitos!\n");
		system("pause");
	}
	else
	{

		do
		{
			printf("Nome da equipe:\n");
			scanf("%[^\n]s", &volta[cont_voltas].equipe);
			fflush(stdin);
			// strlen utilizado para chegar quantos caracteres ha na string
			if (strlen(volta[cont_voltas].equipe) < 1 || strlen(volta[cont_voltas].equipe) > 50)
				printf("equipe invalida!\n");
		} while (strlen(volta[cont_voltas].equipe) < 1 || strlen(volta[cont_voltas].equipe) > 50);

		do
		{
			printf("ID do piloto:\n");
			scanf("%d", &volta[cont_voltas].idnt_piloto);
			fflush(stdin);
			// for utilizado para repeticoes
			for (i = 0; i < MAX_PILOTOS; i++)
			{
				if (volta[cont_voltas].idnt_piloto == piloto[i].idnt)
				{
					valida_idnt_piloto = 1;
				}
			}

			if (valida_idnt_piloto == 0)
				printf("Piloto Inexistente!\n");
		} while (valida_idnt_piloto == 0);

		do
		{
			printf("ID do circuito:\n");
			scanf("%d", &volta[cont_voltas].idnt_circuito);
			fflush(stdin);
			// for utilizado para repeticoes
			for (i = 0; i < MAX_CIRCUITOS; i++)
			{
				if (volta[cont_voltas].idnt_circuito == circuito[i].idnt)
				{
					valida_idnt_circuito = 1;
				}
			}

			if (valida_idnt_circuito == 0)
				printf("Circuito inexistente!\n");
		} while (valida_idnt_circuito == 0);

		do
		{
			printf("Data: (dia/mes/ano)\n");
			scanf("%d %d %d", &volta[cont_voltas].dia, &volta[cont_voltas].mes, &volta[cont_voltas].ano);
			fflush(stdin);
			if ((volta[cont_voltas].dia < 1 || volta[cont_voltas].dia > 31) || (volta[cont_voltas].mes < 1 || volta[cont_voltas].mes > 12) || (volta[cont_voltas].ano < 1950 || volta[cont_voltas].ano > 2023))
				printf("Data invalida!\n");
		} while ((volta[cont_voltas].dia < 1 || volta[cont_voltas].dia > 31) || (volta[cont_voltas].mes < 1 || volta[cont_voltas].mes > 12) || (volta[cont_voltas].ano < 1950 || volta[cont_voltas].ano > 2023));

		do
		{
			printf("Tempo da volta (minuto / segundos / milisegundos):\n");
			scanf("%d %d %d", &volta[cont_voltas].Tmp_m, &volta[cont_voltas].Tmp_s, &volta[cont_voltas].Tmp_mls);
			fflush(stdin);
			if (volta[cont_voltas].Tmp_m < 0 || volta[cont_voltas].Tmp_s < 0 || volta[cont_voltas].Tmp_mls < 0)
				printf("Tempo invalido!\n");
		} while (volta[cont_voltas].Tmp_m < 0 || volta[cont_voltas].Tmp_s < 0 || volta[cont_voltas].Tmp_mls < 0);
		// for utilizado para repeticoes
		for (i = 0; i < MAX_CIRCUITOS; i++)
		{
			if ((volta[cont_voltas].Tmp_mls <= circuito[i].MnT_mls) && (volta[cont_voltas].Tmp_s >= circuito[i].MnT_s) && (volta[cont_voltas].Tmp_m >= circuito[i].MnT_m))
			{
				circuito[i].MnT_mls = volta[cont_voltas].Tmp_mls;
				circuito[i].MnT_s = volta[cont_voltas].Tmp_s;
				circuito[i].MnT_m = volta[cont_voltas].Tmp_s;
			}
			else if ((volta[cont_voltas].Tmp_s <= circuito[i].MnT_s) && (volta[cont_voltas].Tmp_m >= circuito[i].MnT_m))
			{
				circuito[i].MnT_mls = volta[cont_voltas].Tmp_mls;
				circuito[i].MnT_s = volta[cont_voltas].Tmp_s;
				circuito[i].MnT_m = volta[cont_voltas].Tmp_s;
			}
			else if (volta[cont_voltas].Tmp_m <= circuito[i].MnT_m)
			{
				circuito[i].MnT_mls = volta[cont_voltas].Tmp_mls;
				circuito[i].MnT_s = volta[cont_voltas].Tmp_s;
				circuito[i].MnT_m = volta[cont_voltas].Tmp_s;
			}
		}

		printf("Cadastro concluido!\n");
		system("pause");
	}
}
// Criando uma funcao void para poder cadastrar os pilotos quando forem chamadas dentro do main
void registro_piloto(struct Piloto *piloto, int cont_piloto, char **paises)
{
	int valPais = 0, i = 0;

	do
	{
		printf("Digite o Id do piloto:\n");
		scanf("%d", &piloto[cont_piloto].idnt);
		fflush(stdin);

		if (piloto[cont_piloto].idnt < 100 || piloto[cont_piloto].idnt > 500)
			printf("ID invalido\n");
		// for utilizado para repeticoes
		for (i = 0; i < MAX_PILOTOS; i++)
		{
			if ((i != cont_piloto) && (piloto[cont_piloto].idnt == piloto[i].idnt))
			{
				piloto[cont_piloto].idnt = 0;
				printf("ID ja esta sendo utilizado\n");
			}
		}
	} while (piloto[cont_piloto].idnt < 100 || piloto[cont_piloto].idnt > 500);

	do
	{
		printf("Idade:\n");
		scanf("%d", &piloto[cont_piloto].idade);
		fflush(stdin);
		if (piloto[cont_piloto].idade < 18)
			printf("Idade invalida\n");
	} while (piloto[cont_piloto].idade < 18);

	do
	{
		printf("Nome:\n");
		scanf("%[^\n]s", &piloto[cont_piloto].nome);
		fflush(stdin);
		// strlen utilizado para chegar quantos caracteres ha na string
		if (strlen(piloto[cont_piloto].nome) < 1 || strlen(piloto[cont_piloto].nome) > 50)
			printf("Nome invalido!\n");
	} while (strlen(piloto[cont_piloto].nome) < 1 || strlen(piloto[cont_piloto].nome) > 50);

	do
	{
		printf("Sexo: (masculino/feminino)\n");
		scanf("%c", &piloto[cont_piloto].sexo);
		piloto[cont_piloto].sexo = toupper(piloto[cont_piloto].sexo);
		fflush(stdin);
		if (piloto[cont_piloto].sexo != 'M' && piloto[cont_piloto].sexo != 'F')
			printf("Sexo invalido!\n");
	} while (piloto[cont_piloto].sexo != 'M' && piloto[cont_piloto].sexo != 'F');

	do
	{
		printf("Pais de Origem:\n");
		printf("Russia, Eslovaquia, Dhabi, Finlandia, Quenia, Chade, Angola, Madagascar, Japao, Canada, Iraque\n");
		scanf("%[^\n]s", &piloto[cont_piloto].pais);
		fflush(stdin);
		// for utilizado para repeticoes
		for (i = 0; i < 11; i++)
		{
			// stricmp funcao utilizada para comprar duas strings
			if (stricmp(piloto[cont_piloto].pais, paises[i]) == 0)
			{
				valPais = 1;
			}
		}

		if (valPais == 0)
			printf("Pais invalido!\n");

	} while (valPais != 1);

	printf("Cadastro concluido\n");
	system("pause");
}
// Criando uma funcao void para poder consultar os dados dos pilotos quando forem chamadas dentro do main
void consulta_pilotos(struct Piloto *piloto, int cont_piloto)
{
	int i;

	if (cont_piloto == 0)
	{
		printf("Nao houve cadastro!\n");
	}
	else
	{
		// for utilizado para repeticoes
		for (i = 0; i < cont_piloto; i++)
		{

			printf("===== ===== ===== =====\n");
			printf("ID: %d\n", piloto[i].idnt);
			printf("Nome: %s\n", piloto[i].nome);
			printf("Idade: %d\n", piloto[i].idade);
			printf("Sexo: %c\n", piloto[i].sexo);
			printf("Pais: %s\n", piloto[i].pais);
			printf("===== ===== ===== =====\n");
		}
	}

	system("pause");
}
// Criando uma funcao void para poder consultar os dados dos circuitos quando forem chamadas dentro do main
void consulta_circuitos(struct Circuito *circuito, int cont_circuito)
{
	int i;

	if (cont_circuito == 0)
	{
		printf("Nao houve cadastro!\n");
	}
	else
	{
		// for utilizado para repeticoes
		for (i = 0; i < cont_circuito; i++)
		{
			printf("===== ===== ===== =====\n");
			printf("ID: %d\n", circuito[i].idnt);
			printf("Nome: %s\n", circuito[i].nome);
			printf("tam: %.2fkm", circuito[i].tam);
			printf("Pais: %s\n", circuito[i].pais);
			printf("===== ===== ===== =====\n");
		}
	}

	system("pause");
}
// Criando uma funcao void para poder consultar as voltas  dos pilotos quando forem chamadas dentro do main
void consulta_voltas(struct Volta *volta, int cont_voltas)
{
	int i;

	if (cont_voltas == 0)
	{
		printf("Nao houve cadastro!\n");
	}
	else
	{
		// for utilizado para repeticoes
		for (i = 0; i < cont_voltas; i++)
		{
			printf("===== ===== ===== =====\n");
			printf("ID do piloto:: %d\n", volta[i].idnt_piloto);
			printf("ID do circuito: %d\n", volta[i].idnt_circuito);
			printf("Nome da equipe: %s\n", volta[i].equipe);
			printf("Data: %d/%d/%d\n", volta[i].dia, volta[i].mes, volta[i].ano);
			printf("Tmp: %dm %ds %dms \n", volta[i].Tmp_m, volta[i].Tmp_s, volta[i].Tmp_mls);
			printf("===== ===== ===== =====\n");
		}
	}

	system("pause");
}
// Criando uma funcao void para poder consultar os dados com o nome do piloto quando forem chamadas dentro do main
void consulta_nome(struct Piloto *piloto, int cont_piloto)
{
	int i, validaPesquisaNome = 0;
	char pesquisaNome[50];

	if (cont_piloto == 0)
	{
		printf("Nao houve cadastro de pilotos!\n");
	}
	else
	{
		do
		{
			printf("Digite o nome do piloto que deseja pesquisar:\n");
			scanf("%[^\n]s", &pesquisaNome);
			fflush(stdin);
			// for utilizado para repeticoes
			for (i = 0; i < MAX_PILOTOS; i++)
			{
				// stricmp funcao utilizada para comprar duas strings
				if (stricmp(pesquisaNome, piloto[i].nome) == 0)
				{
					validaPesquisaNome = 1;
				}
			}

			if (validaPesquisaNome == 0)
				printf("Nome nao consta em nenhum cadastro!\n");

		} while (validaPesquisaNome != 1);

		// for utilizado para repeticoes
		for (i = 0; i < MAX_PILOTOS; i++)
		{
			// stricmp funcao utilizada para comprar duas strings
			if (stricmp(pesquisaNome, piloto[i].nome) == 0)
			{
				printf("===== ===== ===== =====\n");
				printf("ID: %d\n", piloto[i].idnt);
				printf("Nome: %s\n", piloto[i].nome);
				printf("Idade: %d\n", piloto[i].idade);
				printf("Sexo: %c\n", piloto[i].sexo);
				printf("Pais: %s\n", piloto[i].pais);
				printf("===== ===== ===== =====\n");
			}
		}
	}
	system("pause");
}
// Criando uma funcao void para poder consultar os dados das voltas pelo circuito quando forem chamadas dentro do main
void consulta_volta_circuito(struct Piloto *Piloto, struct Circuito *circuito, struct Volta *volta, int cont_piloto, int cont_circuito, int cont_voltas)
{
	int i, j, pesquisaCircuito, validaPesquisaCircuito = 0, ausenciaVoltas;

	if ((cont_piloto == 0) || (cont_circuito == 0))
	{
		printf("Nao houve cadastro de voltas!\n");
		system("pause");
	}
	else
	{
		do
		{
			printf("Digite o ID do circuito que deseja pesquisar:\n");
			scanf("%d", &pesquisaCircuito);
			// for utilizado para repeticoes
			for (i = 0; i < MAX_CIRCUITOS; i++)
			{
				if (pesquisaCircuito = circuito[i].idnt)
					validaPesquisaCircuito = 1;
			}

			if (validaPesquisaCircuito == 0)
				printf("Esse ID de circuito nao existe!\n");

		} while (validaPesquisaCircuito == 0);
		// for utilizado para repeticoes
		for (i = 0; i < MAX_CIRCUITOS; i++)
		{
			if (pesquisaCircuito = circuito[i].idnt)
			{
				for (i = 0; i < MAX_CIRCUITOS; i++)
				{
					if (circuito[i].idnt == volta[j].idnt_circuito)
					{
						printf("===== ===== ===== =====\n");
						printf("ID do piloto: %d\n", volta[j].idnt_piloto);
						printf("Data da volta: %d/%d/%d\n", volta[i].dia, volta[i].mes, volta[i].ano);
						printf("Tmp da volta: %dm %ds %dms\n", volta[i].Tmp_m, volta[i].Tmp_s, volta[i].Tmp_mls);
						printf("Nome da equipe: %s\n", volta[i].equipe);
						printf("===== ===== ===== =====\n");
					}
				}
			}
		}

		system("pause");
	}
}
// Criando uma funcao void para poder consultar os dados das voltas pelo tempo quando forem chamadas dentro do main
void consulta_volta_tmp(struct Volta *volta, int cont_voltas)
{
	int i, pesquisaTmp_m, pesquisaTmp_s, pesquisaTmp_mls;

	if (cont_voltas == 0)
	{
		printf("Nao houve cadastro de voltas!");
	}
	else
	{
		printf("Digite o Tmp que deseja pesquisar (m / s / mls):\n");
		scanf("%d %d %d", &pesquisaTmp_m, &pesquisaTmp_s, &pesquisaTmp_mls);
		// for utilizado para repeticoes
		for (i = 0; i < MAX_VOLTAS; i++)
		{
			if (pesquisaTmp_m >= volta[i].Tmp_m)
			{
				printf("===== ===== ===== =====\n");
				printf("ID do piloto: %d\n", volta[i].idnt_piloto);
				printf("ID do circuito: %d\n,", volta[i].idnt_circuito);
				printf("Tmp da volta: %dm %ds %dms\n", volta[i].Tmp_m, volta[i].Tmp_s, volta[i].Tmp_mls);
				printf("Data da volta: %d/%d/%d\n", volta[i].dia, volta[i].mes, volta[i].ano);
				printf("Nome da equipe: %s\n", volta[i].equipe);
				printf("===== ===== ===== =====\n");
			}
		}
	}
}

int main()
{

	int menu1, menu__cadastro, menu__relatorio, menu__consulta;
	int cont_piloto = 0, cont_circuito = 0, cont_voltas = 0;
	char *paises[] = {"Russia", "Eslovaquia", "Dhabi", "Finlandia", "Quenia", "Chade", "Angola", "Madagascar", "Japao", "Canada", "Iraque"}; // setlocale funcao utilizada para descrever qual o idioma utilizado no codigo para que assim possa ser utilizado os acentos corretamente
	setlocale(LC_ALL, "Portuguese");

	struct Piloto piloto[MAX_PILOTOS];
	struct Circuito circuito[MAX_CIRCUITOS];
	struct Volta volta[MAX_VOLTAS];

	do
	{
		do
		{
			// puxando a funcao de menu criada anteriormente no codigo
			menu_inicial();

			scanf("%d", &menu1);
			fflush(stdin);
		} while (menu1 < 1 || menu1 > 3);
		// criando um switch para que possa ser feita opcoes pelo usuario a qual irao refletir em respostas pelo codigo
		switch (menu1)
		{
		case 1:
			do
			{
				do
				{
					// puxando a funcao de menu criada anteriormente no codigo
					menu_cadastro();
					scanf("%d", &menu__cadastro);
					fflush(stdin);
				} while (menu__cadastro < 1 || menu__cadastro > 4);
				// criando um switch para que possa ser feita opcoes pelo usuario a qual irao refletir em respostas pelo codigo
				switch (menu__cadastro)
				{

				case 1:
					system("cls");
					registro_piloto(piloto, cont_piloto, paises);
					cont_piloto = cont_piloto + 1;
					break;

				case 2:
					system("cls");
					cadastro_circuito(circuito, cont_circuito, paises);
					cont_circuito = cont_circuito + 1;
					break;

				case 3:
					system("cls");
					cadastro_voltas(volta, piloto, circuito, cont_voltas, cont_piloto, cont_circuito);
					cont_voltas = cont_voltas + 1;
					break;

				case 4:
					system("cls");
					printf("Voltando ao menu...\n");
					system("pause");
					break;
				}
			} while (menu__cadastro != 4);
			break;

		case 2:
			do
			{
				do
				{
					// puxando a funcao de menu criada anteriormente no codigo
					menu_relatorio();
					scanf("%d", &menu__relatorio);
					fflush(stdin);
				} while (menu__relatorio < 1 || menu__relatorio > 5);
				// criando um switch para que possa ser feita opcoes pelo usuario a qual irao refletir em respostas pelo codigo
				switch (menu__relatorio)
				{
				case 1:
					do
					{
						do
						{
							menu_consulta();
							scanf("%d", &menu__consulta);
							fflush(stdin);
						} while (menu__relatorio < 1 || menu__relatorio > 4);

						switch (menu__consulta)
						{
						case 1:
							system("cls");
							consulta_pilotos(piloto, cont_piloto);
							break;
						case 2:
							system("cls");
							consulta_circuitos(circuito, cont_circuito);
							break;
						case 3:
							system("cls");
							consulta_voltas(volta, cont_voltas);
							break;
						case 4:
							system("cls");
							printf("Voltando ao menu...\n");
							system("pause");
							break;
						}
					} while (menu__consulta != 4);
					break;

				case 2:
					system("cls");
					consulta_nome(piloto, cont_piloto);
					system("pause");
					break;

				case 3:
					system("cls");
					consulta_volta_circuito(piloto, circuito, volta, cont_piloto, cont_circuito, cont_voltas);
					system("pause");
					break;

				case 4:
					system("cls");
					consulta_volta_tmp(volta, cont_voltas);
					system("pause");
				case 5:
					system("cls");
					printf("Voltando ao menu...\n");
					system("pause");
					break;
				}
			} while (menu__relatorio != 5);

		case 3:
			system("cls");
			printf("Volte Sempre\n");
		}
	} while (menu1 != 3);

	return 0;
}
