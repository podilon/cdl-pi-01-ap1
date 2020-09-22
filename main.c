#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

//CONSTANTES

/* Valor definindo quantidade de registros */
#define MAXCADASTRO 10

//VARIAVEIS GLOBAL

/* Inicializando ID */
int vg_ID = 0;

//STRUCT CADASTRO MÁQUINA

typedef struct
{
    char nomeMaquina[25];
    char ipMaquina[15];
    char soMaquina[15];
    char versaoSoMaquina[15];
    char usuarioMaquina[15];
    char setorMaquina[15];

} Tmaquina;

/* Tabela Cadastro - Tipo | Tabela[MAXCADASTRO] */
Tmaquina cadastro[MAXCADASTRO];

// PROCEDIMENTO INICIALIZA

/* Inicializa com valores a Tabela Cadastro - registro: Tabela[0] */
void inicializaCadastro()
{

    strcpy(cadastro[0].nomeMaquina, "NULL");
    strcpy(cadastro[0].ipMaquina, "NULL");
    strcpy(cadastro[0].soMaquina, "NULL");
    strcpy(cadastro[0].versaoSoMaquina, "NULL");
    strcpy(cadastro[0].usuarioMaquina, "NULL");
    strcpy(cadastro[0].setorMaquina, "NULL");
    return;
}

// 00 - PROCEDIMENTO MENU //

void menu(void)
{

    printf("\n-------------------------------------------------------------\n");
    printf("\n----- Bem Vindos ao Sistema de Cadastro de Equipamentos -----\n");
    printf("\n---------------------- Menu do Sistema ----------------------\n");
    printf("\n*** DIGITE 01 - CADASTRAR COMPUTADOR ************************\n");
    printf("*** DIGITE 02 - CONSULTAR COMPUTADORES POR ID ***************\n");
    printf("*** DIGITE 03 - VISUALIZAR LISTA DE COMPUTADORES ************\n");
    printf("*** DIGITE 04 - ALTERAR CADASTRO DE COMPUTADOR **************\n");
    printf("*** DIGITE 05 - PARA SAIR ***********************************\n");
    printf("\n-------------------------------------------------------------\n");

    return;
}

//funçao que limpa o buffer
void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

// 01 - PROCEDIMENTO CADASTRAR MÁQUINA//

void cadastrar(void)
{
    /* Declara a variável local vl_id  */
    int vl_id;

    /* Inicializa a variável local vl_id com a variável Global vg_ID  */
    vl_id = vg_ID;

    /* Exibe o ID do Novo Cadastro a ser Inserido no Registro da Tabela Cadastro */
    printf("\n-------------------------------------------------------------\n");

    printf("\nCADASTRO ID: %d", vg_ID);

    printf("\n-------------------------------------------------------------\n");

    /* Inclusão de Dados do Novo Cadastro a ser Inserido no Registro da Tabela Cadastro */
    printf("\nDigite o Nome da Máquina:  ");
    scanf(" %[^\n]s%*c", &cadastro[vg_ID].nomeMaquina);

    printf("\nDigite o IP da Máquina: ");
    scanf(" %[^\n]s%*c", &cadastro[vg_ID].ipMaquina);

    printf("\nDigite o SO da Máquina: ");
    scanf(" %[^\n]s%*c", &cadastro[vg_ID].soMaquina);

    printf("\nDigite o versão do SO: ");
    scanf(" %[^\n]s%*c", &cadastro[vg_ID].versaoSoMaquina);

    printf("\nDigite o usuário responsável: ");
    scanf(" %[^\n]s%*c", &cadastro[vg_ID].usuarioMaquina);

    printf("\nDigite o setor/departamento da Máquina:  ");
    scanf(" %[^\n]s%*c", &cadastro[vg_ID].setorMaquina);

    

    /* Atualizando a váriavel Global disponibilizando um novo ID para um próximo cadastro */
    vg_ID++;
}

// 02 - PROCEDIMENTO CONSULTAR MÁQUINAS POR ID

void listarCadastroID(void)
{
    /* Declara a variável local vl_id  */
    int vl_id = 0;

    /* Inserção do ID do Cadastro a ser Consultado */
    printf("\n-------------------------------------------------------------\n");
    printf("\nDigite o ID da Máquina:  ");
    scanf("%d", &vl_id);

    /* Tratamento de Erro para o ID do Cadastro Inválido */
    if ((vl_id < 0) || (vl_id >= vg_ID))
    {
        printf("\n-------------------------------------------------------------\n");
        printf("\n*********************** ID INVÁLIDO *************************\n");
        
    }
    else
    {
        /* Visualizar Cadastro de Acordo com ID selecionado */
        printf("\n-------------------------------------------------------------\n");
        printf("\n ID da Máquina: %d \n", vl_id);
        printf("\n-------------------------------------------------------------\n");

        printf("\nNome da Máquina: %s \n", cadastro[vl_id].nomeMaquina);
        printf("\nSO da Máquina: %s \n", cadastro[vl_id].soMaquina);
        printf("\nIP da Máquina: %s \n", cadastro[vl_id].ipMaquina);
        printf("\nVersão do SO: %s \n", cadastro[vl_id].versaoSoMaquina);
        printf("\nUsuário responsável: %s \n", cadastro[vl_id].usuarioMaquina);
        printf("\nSetor/Departamento da Máquina: %s \n", cadastro[vl_id].setorMaquina);
        
    }

    return;
}

// 03 - PROCEDIMENTO LISTAR CADASTRO DE MÁQUINAS

void listarCadastro(void)
{
    int vl_id;

    for (vl_id = 0; vl_id < vg_ID; vl_id++)
    {
        printf("\n-------------------------------------------------------------\n");
        printf("\n ID da Máquina: %d \n", vl_id);
        printf("\n-------------------------------------------------------------\n");
        printf("\nNome da Máquina: %s \n", cadastro[vl_id].nomeMaquina);
        printf("\nSO da Máquina: %s \n", cadastro[vl_id].soMaquina);
        printf("\nIP da Máquina: %s \n", cadastro[vl_id].ipMaquina);
        printf("\nVersão do SO: %s \n", cadastro[vl_id].versaoSoMaquina);
        printf("\nUsuário responsável: %s \n", cadastro[vl_id].usuarioMaquina);
        printf("\nSetor/Departamento da Máquina: %s \n", cadastro[vl_id].setorMaquina);
        
    }
}

// 04 - PROCEDIMENTO ALTERAR CADASTRO DE MÁQUINA

void alterarCadastro(void)
{
    /* Declara e Inicializa a variável local vl_id  */
    int vl_id = 0;

    /* Inserção do ID do cadastro a ser alterado */
    printf("\n-------------------------------------------------------------\n");
    printf("\nDigite o ID da Máquina:  ");
    scanf("%d", &vl_id);

    /* Tratamento de Erro para o ID do Cadastro Inválido */
    if ((vl_id < 0) || (vl_id >= vg_ID))
    {
        printf("\n-------------------------------------------------------------\n");
        printf("\n*********************** ID INVÁLIDO *************************\n");
        
    }
    else
    {
        /* Visualizar Cadastro de Acordo com ID selecionado */
        printf("\n-------------------------------------------------------------\n");
        printf("\n ID da Máquina: %d \n", vl_id);
        printf("\n-------------------------------------------------------------\n");

        printf("\nNome da Máquina: %s \n", cadastro[vl_id].nomeMaquina);
        printf("\nSO da Máquina: %s \n", cadastro[vl_id].soMaquina);
        printf("\nIP da Máquina: %s \n", cadastro[vl_id].ipMaquina);
        printf("\nVersão do SO: %s \n", cadastro[vl_id].versaoSoMaquina);
        printf("\nUsuário responsável: %s \n", cadastro[vl_id].usuarioMaquina);
        printf("\nSetor/Departamento da Máquina: %s \n", cadastro[vl_id].setorMaquina);
        

        /* Alterar Cadastro */

        printf("\n-------------------------------------------------------------\n");
        printf("\nCADASTRO ID: %d", vl_id);
        printf("\n-------------------------------------------------------------\n");

        printf("\nDigite o Nome da Máquina:  ");
        scanf(" %[^\n]s%*c", &cadastro[vl_id].nomeMaquina);

        printf("\nDigite o IP da Máquina: ");
        scanf(" %[^\n]s%*c", &cadastro[vl_id].ipMaquina);

        printf("\nDigite o SO da Máquina: ");
        scanf(" %[^\n]s%*c", &cadastro[vl_id].soMaquina);

        printf("\nDigite o versão do SO: ");
        scanf(" %[^\n]s%*c", &cadastro[vl_id].versaoSoMaquina);

        printf("\nDigite o usuário responsável: ");
        scanf(" %[^\n]s%*c", &cadastro[vl_id].usuarioMaquina);

        printf("\nDigite o setor/departamento da Máquina:  ");
        scanf(" %[^\n]s%*c", &cadastro[vl_id].setorMaquina);

        
    }


    return;
}

// FUNÇÃO PRINCIPAL //

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Portuguese");

    /* Inicialização da chave: On = 0 | Off = 5 */
    int vl_start = 0;

    /* Função para Inicializar valores a Tabela Cadastro - registro: Tabela[0] */
    inicializaCadastro();

    /* Laço While para aplicar o Menu e suas Respectivas Operações: */
    while (vl_start == 0)
    {

        // 00 - MENU

        /* Função para Visualizar o Menu na Tela e Inserção da Opção Desejada */
        menu();
        printf("\nOpção: ");
        scanf("%d", &vl_start);
        

        /* Tratamento de Erro na Opção Menu */
        if ((vl_start < 1) || (vl_start > 5))
        {
            /* Reset da Chave(ON) */
            vl_start = 0;
        }

        // 01 - CADASTRAR MÁQUINA

        if (vl_start == 1)
        {
            /* Função para Inserção de Novo Cadastro */
            cadastrar();

            /* Reset da Chave(ON) */
            vl_start = 0;
        }

        // 02 - CONSULTA POR ID DA MÁQUINA

        if (vl_start == 2)
        {
            /* Função para Listar Cadastro por ID */
            listarCadastroID();

            /* Reset da Chave(ON) */
            vl_start = 0;
        }

        // 03 - LISTAR CADASTRO DAS MÁQUINAS

        if (vl_start == 3)
        {
            /* Função para Mostrar Cadastro selecionado por ID a ser Alterado */
            listarCadastro();

            /* Reset da Chave(ON) */
            vl_start = 0;
        }

        // 04 - ALTERAR CADASTRO DAS MÁQUINAS

        if (vl_start == 4)
        {
            /* Função para Alterar Cadastro selecionado por ID */
            alterarCadastro();

            /* Reset da Chave(ON) */
            vl_start = 0;
        }

        // 05 - ENCERRAR

        /* Fecha a Chave(OFF) */
        if (vl_start == 5)
        {
            break;
        }
    }

    getchar();

    return 0;
}
