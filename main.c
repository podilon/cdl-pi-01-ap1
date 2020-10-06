#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


/*VARIAVEIS GLOBAL*/

/* Inicializando ID */
int vg_ID;

/*STRUCT�S*/

/* Struct Cadastro M�quina Head*/

typedef struct
{
    char maquinaId[25];
    char maquinaNome[25];
    char maquinaIp[25];
    char maquinaSo[25];
    char maquinaVersao[25];
    char maquinaUsuario[25];
    char maquinaSetor[25];

} SmaquinaHead;

/* Struct Cadastro M�quina */

typedef struct
{
    int maquinaId;
    char maquinaNome[25];
    char maquinaIp[25];
    char maquinaSo[25];
    char maquinaVersao[25];
    char maquinaUsuario[25];
    char maquinaSetor[25];

} Smaquina;

/*PROCEDIMENTO INICIALIZAR*/

void inicializaCadastro()
{

    /* Inicializa a vari�vel Global vg_ID com os dados Armazenados no BD */
    FILE* arquivoID;

    arquivoID = fopen("bd/bdId.dat", "rb");

    /* Vari�vel do Leitor do ID */
    char leitorId[6];

    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoID == NULL)
    {
        /* Fun��o Head*/
        head();
        system ("mkdir bd");

        printf("\n\n************* Arquivo bdId.dat N�o Encontrado! **************\n\n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n\n*************** Arquivo bdId.dat Criado Ok! *****************\n\n");
        printf("\n---------------------[DIGITE ENTER]--------------------------\n");
        arquivoID = fopen("bd/bdId.dat", "wb");
        /*leitorId[6] = "0";*/
        /*vg_ID = atoi(leitorId);*/
        /*fprintf(arquivoID, "%d", vg_ID);*/
        vg_ID = 0;
        fprintf( arquivoID,"%d", vg_ID);

        fclose(arquivoID);
        getch();
    }
    else
    {

        freopen("bd/bdId.dat", "rb", arquivoID);
        fgets(leitorId, 6, arquivoID);
        vg_ID = atoi(leitorId);
    }

    fclose(arquivoID);

    /* Consultando se o BD est� Dispon�vel em Arquivo dat */
    FILE* arquivoCadastro;
    arquivoCadastro = fopen("bd/bdCadastro.dat", "rb");

    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastro == NULL)
    {
        head();

        printf("\n\n********** Arquivo bdCadastro.dat N�o Encontrado! ***********\n\n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n\n************ Arquivo bdCadastro.dat Criado Ok! **************\n\n");
        printf("\n---------------------[DIGITE ENTER]--------------------------\n");

        /* Criando o BD por meio de um Arquivo de dat */
        arquivoCadastro = fopen("bd/bdCadastro.dat", "wb");
        fclose(arquivoCadastro);
        getch();
    }

    fclose(arquivoCadastro);

    /* Inicializando o Cabe�alho da tabela Cadastro do Arquivo bdCadastro.bkp */
    FILE* arquivoCadastro_bkp;
    arquivoCadastro_bkp = fopen("bd/bdCadastro.bkp", "r+");

    /* Vari�vel Tabela de Cadastro Head*/
    SmaquinaHead TcadastroCsv[1];

    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastro_bkp == NULL)
    {
        head();

        printf("\n********** Arquivo bdCadastro.bkp N�o Encontrado! ***********\n\n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n************** Arquivo bdCadastro.bkp Criado ****************\n\n");
        printf("\n---------------------[DIGITE ENTER]--------------------------\n");


        arquivoCadastro_bkp = fopen("bd/bdCadastro.bkp", "w");

        fclose(arquivoCadastro_bkp);
        getch();

    }
    else
    {
        arquivoCadastro_bkp = fopen("bd/bdCadastro.bkp", "r+");
        /* Retornando Registro para o Indice 0 */
        rewind(arquivoCadastro_bkp);

        /* Inicializando cadastro e Registrando no in�cio do Arquivo como Cabe�alho */
        strcpy(TcadastroCsv[0].maquinaId, "Id");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaId);

        strcpy(TcadastroCsv[0].maquinaNome, "Nome da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaNome);

        strcpy(TcadastroCsv[0].maquinaIp, "IP da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaIp);

        strcpy(TcadastroCsv[0].maquinaSo, "SO da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaSo);

        strcpy(TcadastroCsv[0].maquinaVersao, "Vers�o do SO");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaVersao);

        strcpy(TcadastroCsv[0].maquinaUsuario, "Usu�rio da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaUsuario);

        strcpy(TcadastroCsv[0].maquinaSetor, "Setor/Departamento");
        fprintf(arquivoCadastro_bkp, "%s;\n", TcadastroCsv[0].maquinaSetor);
    }
    fclose(arquivoCadastro_bkp);


    /* Inicializando o Cabe�alho da tabela Cadastro do Arquivo bdCadastro.csv */
    FILE* arquivoCadastroCsv;
    arquivoCadastroCsv = fopen("bd/bdCadastro.csv", "r+");


    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastroCsv == NULL)
    {
        head();

        printf("\n******** Arquivo bdCadastro.csv N�o Encontrado! *********\n\n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n************ Arquivo bdCadastro.csv Criado **************\n\n");
        printf("\n-------------------------------------------------------------\n");

        head();

        printf("\n************** Favor Reinicie a Aplica��o! ******************\n\n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n---------------------[DIGITE ENTER]--------------------------\n");

        arquivoCadastroCsv = fopen("bd/bdCadastro.csv", "w");

        fclose(arquivoCadastroCsv);
        getch();
        exit(1);
    }
    else
    {
        arquivoCadastroCsv = fopen("bd/bdCadastro.csv", "r+");
        /* Retornando Registro para o Indice 0 */
        rewind(arquivoCadastroCsv);

        /* Inicializando cadastro e Registrando no in�cio do Arquivo como Cabe�alho */

        strcpy(TcadastroCsv[0].maquinaId, "Id");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaId);


        strcpy(TcadastroCsv[0].maquinaNome, "Nome da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaNome);

        strcpy(TcadastroCsv[0].maquinaIp, "IP da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaIp);

        strcpy(TcadastroCsv[0].maquinaSo, "SO da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaSo);

        strcpy(TcadastroCsv[0].maquinaVersao, "Vers�o do SO");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaVersao);

        strcpy(TcadastroCsv[0].maquinaUsuario, "Usu�rio da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaUsuario);

        strcpy(TcadastroCsv[0].maquinaSetor, "Setor/Departamento");
        fprintf(arquivoCadastroCsv, "%s;\n", TcadastroCsv[0].maquinaSetor);
    }
    fclose(arquivoCadastroCsv);
}

/*PROCEDIMENTO ATUALIZAR ID*/

/* Atualiza a vari�vel Global vg_ID e Armazena no BD */

void atualizarId()
{
    FILE* arquivoID;
    arquivoID = fopen("bd/bdId.dat", "wb");

    /* Tratamento de Erro caso o Arquivo não seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoID == NULL)
    {
        printf("\n***************** Arquivo n�o Encontrado! *******************\n");
        exit(1);
    }
    else
    {
        fprintf(arquivoID, "%d", vg_ID);
    }

    fclose(arquivoID);
}



/*PROCEDIMENTO HEAD*/
void head()
{
    system("cls");
    printf("\n-------------------------------------------------------------\n");
    printf("\n------------- Sistema de Cadastro de Equipamentos -----------\n");
    printf("\n-------------------------------------------------------------\n");
}

/*PROCEDIMENTO SUBMENU INTERNO FILTRAR CONSULTA DE CADASTRO*/

void submenuFiltroConsulta()
{

    printf("\n--------------- Op��es de Filtro de Pesquisa ----------------\n");
    printf("\n*** DIGITE 01 - CONSULTA POR ID *****************************\n");
    printf("*** DIGITE 02 - CONSULTA POR NOME ***************************\n");
    printf("*** DIGITE 03 - CONSULTA POR IP *****************************\n");
    printf("*** DIGITE 04 - CONSULTA POR SO *****************************\n");
    printf("*** DIGITE 05 - CONSULTA POR VERS�O DO SO *******************\n");
    printf("*** DIGITE 06 - CONSULTA POR USU�RIO ************************\n");
    printf("*** DIGITE 07 - CONSULTA POR SETOR/DEPARTAMENTO *************\n");
    printf("*** DIGITE 08 - RETORNAR AO MENU ****************************\n");
    printf("\n-------------------------------------------------------------\n");
}

/*00 - PROCEDIMENTO MENU*/

void menu()
{
    /* Procedimento Head*/
    head();

    printf("\n---------------------- Menu do Sistema ----------------------\n");
    printf("\n*** DIGITE 01 - CADASTRAR M�QUINA ***************************\n");
    printf("*** DIGITE 02 - FILTRAR CONSULTAS DAS M�QUINAS **************\n");
    printf("*** DIGITE 03 - VISUALIZAR LISTA DE COMPUTADORES ************\n");
    printf("*** DIGITE 04 - ALTERAR CADASTRO DE COMPUTADOR **************\n");
    printf("*** DIGITE 05 - EXCLUIR CADASTRO DE COMPUTADOR **************\n");
    printf("*** DIGITE 06 - CRIAR BACKUP EM ARQUIVOS .BKP E .CSV ********\n");
    printf("*** DIGITE 07 - PARA SAIR ***********************************\n");
    printf("\n-------------------------------------------------------------\n");
}

/*01 - PROCEDIMENTO CADASTRAR M�QUINA*/

void cadastrar()
{
    char leitorip[25];
    /* Vari�vel Tabela de cadastro */
    Smaquina Tcadastro;

    /* Criando o BD por meio de um Arquivo  dat */
    FILE* arquivoCadastro;
    arquivoCadastro = fopen("bd/bdCadastro.dat", "ab");

    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastro == NULL)
    {
        printf("\n***************** Arquivo N�o Encontrado! *******************\n");
        exit(1);
    }
    else
    {
        do
        {
            /* Head */
            head();

            /* Sub Head*/
            printf("\n*************** Op��o 1 - Cadastrar M�quina *****************\n");
            printf("\n-------------------------------------------------------------\n");

            /* Atualizando a Vari�vel Global Disponibilizando um Novo ID para um Pr�ximo Cadastro */
            vg_ID++;

            /* Exibe o ID do Novo Cadastro a ser Inserido no Registro da Tabela Cadastro */

            printf("\n-------------------------------------------------------------\n");

            /* Atribui autom�ticamente o ID */
            Tcadastro.maquinaId = vg_ID;

            printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);

            printf("\n-------------------------------------------------------------\n");

            setbuf(stdin, NULL);
            printf("\nDigite o Nome da M�quina:  ");
            strupr(gets(Tcadastro.maquinaNome));

            setbuf(stdin, NULL);
            printf("\nDigite o IP da M�quina: ");
            strupr(gets(Tcadastro.maquinaIp));

            setbuf(stdin, NULL);
            printf("\nDigite o SO da M�quina: ");
            strupr(gets(Tcadastro.maquinaSo));

            setbuf(stdin, NULL);
            printf("\nDigite o Vers�o do SO:  ");
            strupr(gets(Tcadastro.maquinaVersao));

            setbuf(stdin, NULL);
            printf("\nDigite o Usu�rio Respons�vel: ");
            strupr(gets(Tcadastro.maquinaUsuario));

            setbuf(stdin, NULL);
            printf("\nDigite o Setor/Departamento: ");
            strupr(gets(Tcadastro.maquinaSetor));

            fwrite(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro);

            printf("\n-------------------------------------------------------------\n");
            printf("\nDeseja cadastrar uma nova m�quina? (s/n) ");

        }
        while (tolower(getche()) == 's');

        fclose(arquivoCadastro);
    }
}

/*02 - PROCEDIMENTO CONSULTAR M�QUINAS POR FILTRO*/

void listarCadastroFiltro()
{

    /* Criando o BD por meio de um Arquivo .Dat */
    FILE* arquivoCadastro;

    /* Vari�vel Tabela de Cadastro */
    Smaquina Tcadastro;

    /* Vari�vel de Pesquisa */
    char vl_entrada[30];
    char vl_opcaoChar[10];
    int vl_entrada_id=0;
    int vl_opcao = 0;

    while (vl_opcao != 8)
    {
        arquivoCadastro = fopen("bd/bdCadastro.dat", "rb");

        /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
        if (arquivoCadastro == NULL)
        {
            printf("\n***************** Arquivo N�o Encontrado! *******************\n");
            exit(1);
        }
        else
        {
            /* Head */
            head();

            /* Sub Head*/
            printf("\n*************** Op��o 2 - Pesquisar Cadastro ****************\n");
            printf("\n-------------------------------------------------------------\n");

            /* Lista de Submenu Filtro de Pesquisa */
            submenuFiltroConsulta();

            /* Recebendo os Dados do Usu�rio Referente a Op��o do Menu*/
            printf("\nDigite a Op��o: ");
            fgets(vl_opcaoChar, 2, stdin);
            printf("\n-------------------------------------------------------------\n");

            /* Convertendo a String em Inteiro*/
            vl_opcao = atoi(vl_opcaoChar);

            /* Limpando o Buffer do Teclado */
            setbuf(stdin, NULL);

            switch (vl_opcao)
            {
            /* Consulta por ID */
            case 1:

                /* Head */
                head();

                /* Sub Head*/
                printf("\n**************** Op��o 1 - Pesquisar por ID *****************\n");
                printf("\n-------------------------------------------------------------\n");

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);

                /* Recebendo os Dados do Usu�rio Referente ao ID desejado */
                printf("\nDigite o ID: ");
                scanf(" %d", &vl_entrada_id);
                printf("\n-------------------------------------------------------------\n");

                /* Listando os Dados */
                while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
                {
                    if (vl_entrada_id == Tcadastro.maquinaId)
                    {
                        printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                        printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                        printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                        printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                        printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                        printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                        printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                        printf("\n-------------------------------------------------------------\n");
                        getch();

                    }
                }

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);
                break;

            /* Consulta por Nome da M�quina */
            case 2:

                /* Head */
                head();

                /* Sub Head*/
                printf("\n*************** Op��o 2 - Pesquisar por Nome ****************\n");
                printf("\n-------------------------------------------------------------\n");

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);

                /* Recebendo os Dados do Usu�rio Referente ao Nome da m�quina */
                printf("\nDigite o Nome da m�quina: ");
                strupr(gets(vl_entrada));
                printf("\n-------------------------------------------------------------\n");

                /* Listando os Dados */
                while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
                {
                    if (strcmp(strupr(vl_entrada), Tcadastro.maquinaNome) == 0)
                    {
                        printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                        printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                        printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                        printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                        printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                        printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                        printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                        printf("\n-------------------------------------------------------------\n");
                        getch();
                    }
                }

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);
                break;

            /* Consulta por IP da M�quina */
            case 3:

                /* Head */
                head();

                /* Sub Head*/
                printf("\n**************** Op��o 3 - Pesquisar por IP *****************\n");
                printf("\n-------------------------------------------------------------\n");

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);

                /* Recebendo os Dados do Usu�rio Referente ao IP da m�quina */
                printf("\nDigite o IP da m�quina: ");
                strupr(gets(vl_entrada));
                printf("\n-------------------------------------------------------------\n");

                /* Listando os Dados */
                while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
                {
                    if (strcmp(strupr(vl_entrada), Tcadastro.maquinaIp) == 0)
                    {
                        printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                        printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                        printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                        printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                        printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                        printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                        printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                        printf("\n-------------------------------------------------------------\n");
                        getch();
                    }
                }

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);
                break;

            /* Consulta por SO da M�quina */
            case 4:

                /* Head */
                head();

                /* Sub Head*/
                printf("\n**************** Op��o 4 - Pesquisar por SO *****************\n");
                printf("\n-------------------------------------------------------------\n");

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);

                /* Recebendo os Dados do Usu�rio Referente ao SO da m�quina */
                printf("\nDigite o SO da m�quina: ");
                gets(vl_entrada);
                printf("\n-------------------------------------------------------------\n");

                /* Listando os Dados */
                while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
                {
                    if (strcmp(strupr(vl_entrada), Tcadastro.maquinaSo) == 0)
                    {
                        printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                        printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                        printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                        printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                        printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                        printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                        printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                        printf("\n-------------------------------------------------------------\n");
                        getch();
                    }
                }

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);
                break;

            /* Consulta por Vers�o do SO da M�quina */
            case 5:
                /* Head */
                head();

                /* Sub Head*/
                printf("\n*********** Op��o 5 - Pesquisar por Vers�o do SO ************\n");
                printf("\n-------------------------------------------------------------\n");

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);

                /* Recebendo os Dados do Usu�rio Referente a Vers�o do SO da m�quina */
                printf("\nDigite o Vers�o do SO da m�quina: ");
                gets(vl_entrada);
                printf("\n-------------------------------------------------------------\n");

                /* Listando os Dados */
                while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
                {
                    if (strcmp(strupr(vl_entrada), Tcadastro.maquinaVersao) == 0)
                    {
                        printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                        printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                        printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                        printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                        printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                        printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                        printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                        printf("\n-------------------------------------------------------------\n");
                        getch();
                    }
                }

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);
                break;

            /* Consulta por Usu�rio da M�quina */
            case 6:

                /* Head */
                head();

                /* Sub Head*/
                printf("\n************** Op��o 6 - Pesquisar por Usu�rio **************\n");
                printf("\n-------------------------------------------------------------\n");

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);

                /* Recebendo os Dados do Usu�rio Referente ao Usu�rio da m�quina */
                printf("\nDigite o Usu�rio da m�quina: ");
                gets(vl_entrada);
                printf("\n-------------------------------------------------------------\n");

                /* Listando os Dados */
                while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
                {
                    if (strcmp(strupr(vl_entrada), Tcadastro.maquinaUsuario) == 0)
                    {
                        printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                        printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                        printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                        printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                        printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                        printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                        printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                        printf("\n-------------------------------------------------------------\n");
                        getch();
                    }
                }

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);
                break;

            /* Consulta por Setor/Departamento da M�quina */
            case 7:

                /* Head */
                head();

                /* Sub Head*/
                printf("\n*************** Op��o 7 - Pesquisar por Setor ***************\n");
                printf("\n-------------------------------------------------------------\n");

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);

                /* Recebendo os Dados do Usu�rio Referente ao Setor/Departamento da m�quina */
                printf("\nDigite o Setor/Departamento da m�quina: ");
                gets(vl_entrada);
                printf("\n-------------------------------------------------------------\n");

                /* Listando os Dados */
                while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
                {
                    if (strcmp(strupr(vl_entrada), Tcadastro.maquinaSetor) == 0)
                    {
                        printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                        printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                        printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                        printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                        printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                        printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                        printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                        printf("\n-------------------------------------------------------------\n");
                        getch();
                    }
                }

                /* Limpando o Buffer do Teclado */
                setbuf(stdin, NULL);
                break;

            case 8:
                break;

            default:

                printf("\n-------------------------------------------------------------\n");
                printf("\n********************* Op��o Inv�lida ************************\n");
                printf("\n-------------------------------------------------------------\n");
                getch();
                setbuf(stdin, NULL);
                break;
            }
        }
    }
    fclose(arquivoCadastro);
}

/*03 - PROCEDIMENTO LISTAR CADASTRO*/

void listarCadastro()
{
    /* Head */
    head();

    /* Sub Head*/
    printf("\n*************** Op��o 3 - Listar Cadastro *******************\n");
    printf("\n-------------------------------------------------------------\n");

    /* Vari�vel Tabela de cadastro */
    Smaquina Tcadastro;

    /* Criando o BD por meio de um Arquivo de dat */
    FILE* arquivoCadastro;
    arquivoCadastro = fopen("bd/bdCadastro.dat", "rb");

    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastro == NULL)
    {
        printf("\n***************** Arquivo N�o Encontrado! *******************\n");
        exit(1);
    }
    else
    {
        while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
        {

            printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
            printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
            printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
            printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
            printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
            printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
            printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
            printf("\n-------------------------------------------------------------\n");
        }
    }

    fclose(arquivoCadastro);
}

/*04 - PROCEDIMENTO ALTERAR CADASTRO */
void alterarCadastro()
{
    /* Head */
    head();

    /* Sub Head*/
    printf("\n*************** Op��o 4 - Alterar Cadastro ******************\n");
    printf("\n-------------------------------------------------------------\n");


    /* Vari�vel Tabela de Cadastro */
    Smaquina Tcadastro;

    /* Vari�vel de Pesquisa */
    int vl_entrada_id;

    /* Criando o BD por meio de um Arquivo de dat */
    FILE* arquivoCadastro;
    arquivoCadastro = fopen("bd/bdCadastro.dat", "r+b");


    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastro == NULL)
    {
        printf("\n***************** Arquivo N�o Encontrado! *******************\n");
        exit(1);
    }
    /* Consulta por ID */
    else
    {
        /* Limpando o Buffer do Teclado */
        setbuf(stdin, NULL);

        /* Recebendo os Dados do Usu�rio Referente ao ID desejado */
        printf("\nDigite o ID: ");
        scanf(" %d", &vl_entrada_id);
        printf("\n-------------------------------------------------------------\n");


        while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
        {
            if (vl_entrada_id == Tcadastro.maquinaId)
            {
                printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                printf("\n-------------------------------------------------------------\n");
                getch();



                Tcadastro.maquinaId = vl_entrada_id;

                printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);

                setbuf(stdin, NULL);
                printf("\nDigite o Nome da M�quina:  ");
                strupr(gets(Tcadastro.maquinaNome));


                setbuf(stdin, NULL);
                printf("\nDigite o IP da M�quina: ");
                strupr(gets(Tcadastro.maquinaIp));

                setbuf(stdin, NULL);
                printf("\nDigite o SO da M�quina: ");
                strupr(gets(Tcadastro.maquinaSo));

                setbuf(stdin, NULL);
                printf("\nDigite o Vers�o do SO:  ");
                strupr(gets(Tcadastro.maquinaVersao));

                setbuf(stdin, NULL);
                printf("\nDigite o Usu�rio Respons�vel: ");
                strupr(gets(Tcadastro.maquinaUsuario));

                setbuf(stdin, NULL);
                printf("\nDigite o Setor/Departamento: ");
                strupr(gets(Tcadastro.maquinaSetor));

                fseek (arquivoCadastro, sizeof(Smaquina)*-1, SEEK_CUR);
                fwrite(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro);
                fseek (arquivoCadastro, 0, SEEK_CUR);
                break;

            }
        }
    }

    fclose(arquivoCadastro);
}


/*05 - PROCEDIMENTO REALIZAR BACKUP CADASTRO EM ARQUIVOS .TXT E .CSV*/

void realizarBackupCadastro()
{
    /* Head */
    head();

    /* Sub Head*/
    printf("\n*************** Op��o 5 - Backup Cadastro *******************\n");
    printf("\n-------------------------------------------------------------\n");

    /* Vari�vel Tabela de Cadastro Head*/
    SmaquinaHead TcadastroCsv[1];

    /* Vari�vel Tabela de cadastro */
    Smaquina Tcadastro;


    /* Criando o BD por meio de um Arquivo de dat */
    FILE* arquivoCadastro;
    arquivoCadastro = fopen("bd/bdCadastro.dat", "rb");


    /* Criando o Backup do BD por meio de um Arquivo no Formato Bkp */

    FILE* arquivoCadastro_bkp;
    arquivoCadastro_bkp = fopen("bd/bdCadastro.bkp", "w");

    /* Criando o Backup BD por meio de um Arquivo Csv  */

    FILE* arquivoCadastroCsv;
    arquivoCadastroCsv = fopen("bd/bdCadastro.csv", "w");



    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastro == NULL)
    {
        printf("\n***************** Arquivo N�o Encontrado! *******************\n");
        exit(1);
    }
    else if (arquivoCadastro_bkp == NULL)
    {
        printf("\n*************** Arquivo csv n�o Encontrado! *****************\n");
        exit(1);
    }
    else if (arquivoCadastroCsv == NULL)
    {
        printf("\n*************** Arquivo csv n�o Encontrado! *****************\n");
        exit(1);
    }
    else
    {
        /* Retornando Registro para o Indice 0 */
        rewind(arquivoCadastro_bkp);

        /* Inicializando Cadastro e Registrando no In�cio do Arquivo como Cabe�alho */
        strcpy(TcadastroCsv[0].maquinaId, "Id");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaId);

        strcpy(TcadastroCsv[0].maquinaNome, "Nome da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaNome);

        strcpy(TcadastroCsv[0].maquinaIp, "IP da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaIp);

        strcpy(TcadastroCsv[0].maquinaSo, "SO da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaSo);

        strcpy(TcadastroCsv[0].maquinaVersao, "Vers�o do SO");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaVersao);

        strcpy(TcadastroCsv[0].maquinaUsuario, "Usu�rio da M�quina");
        fprintf(arquivoCadastro_bkp, "%s;", TcadastroCsv[0].maquinaUsuario);

        strcpy(TcadastroCsv[0].maquinaSetor, "Setor/Departamento");
        fprintf(arquivoCadastro_bkp, "%s;\n", TcadastroCsv[0].maquinaSetor);


        /* Inicializando cadastro e Registrando no in�cio do Arquivo como Cabe�alho */
        strcpy(TcadastroCsv[0].maquinaId, "Id");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaId);


        strcpy(TcadastroCsv[0].maquinaNome, "Nome da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaNome);

        strcpy(TcadastroCsv[0].maquinaIp, "IP da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaIp);

        strcpy(TcadastroCsv[0].maquinaSo, "SO da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaSo);

        strcpy(TcadastroCsv[0].maquinaVersao, "Vers�o do SO");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaVersao);

        strcpy(TcadastroCsv[0].maquinaUsuario, "Usu�rio da M�quina");
        fprintf(arquivoCadastroCsv, "%s;", TcadastroCsv[0].maquinaUsuario);

        strcpy(TcadastroCsv[0].maquinaSetor, "Setor/Departamento");
        fprintf(arquivoCadastroCsv, "%s;\n", TcadastroCsv[0].maquinaSetor);


        /* Copiando Registros do Arquivo .dat para os Arquivos .bkp e .Csv */

        while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
        {

            /*printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);*/
            fprintf(arquivoCadastro_bkp, "%d;", Tcadastro.maquinaId);
            fprintf(arquivoCadastroCsv, "%d;", Tcadastro.maquinaId);

            /*printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);*/
            fprintf(arquivoCadastro_bkp, "%s;", strupr(Tcadastro.maquinaNome));
            fprintf(arquivoCadastroCsv, "%s;", strupr(Tcadastro.maquinaNome));


            /*printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);*/
            fprintf(arquivoCadastro_bkp, "%s;", strupr(Tcadastro.maquinaIp));
            fprintf(arquivoCadastroCsv, "%s;", strupr(Tcadastro.maquinaIp));


            /*printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);*/
            fprintf(arquivoCadastro_bkp, "%s;", strupr(Tcadastro.maquinaSo));
            fprintf(arquivoCadastroCsv, "%s;", strupr(Tcadastro.maquinaSo));


            /*printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);*/
            fprintf(arquivoCadastro_bkp, "%s;", strupr(Tcadastro.maquinaVersao));
            fprintf(arquivoCadastroCsv, "%s;", strupr(Tcadastro.maquinaVersao));


            /*printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);*/
            fprintf(arquivoCadastro_bkp, "%s;", strupr(Tcadastro.maquinaUsuario));
            fprintf(arquivoCadastroCsv, "%s;", strupr(Tcadastro.maquinaUsuario));


            /*printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);*/
            fprintf(arquivoCadastro_bkp, "%s;\n", strupr(Tcadastro.maquinaSetor));
            fprintf(arquivoCadastroCsv, "%s;\n", strupr(Tcadastro.maquinaSetor));



        }
    }


    fclose(arquivoCadastro);
    fclose(arquivoCadastro_bkp);
    fclose(arquivoCadastroCsv);

    printf("\n-------------------------------------------------------------\n");
    printf("\n************** Backup Conclu�do com Sucesso *****************\n");
    printf("\n-------------------------------------------------------------\n");
}


/*06 - PROCEDIMENTO EXCLUIR CADASTRO */
void excluirCadastro()
{
    /* Head */
    head();

    /* Sub Head*/
    printf("\n*************** Op��o 6 - Excluir Cadastro ******************\n");
    printf("\n-------------------------------------------------------------\n");


    /* Vari�vel Tabela de Cadastro */
    Smaquina Tcadastro;

    /* Vari�vel de Pesquisa */
    int vl_entrada_id;

    /* Criando o BD por meio de um Arquivo de dat */
    FILE* arquivoCadastro;
    arquivoCadastro = fopen("bd/bdCadastro.dat", "rb");


    /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
    if (arquivoCadastro == NULL)
    {
        printf("\n***************** Arquivo N�o Encontrado! *******************\n");
        exit(1);
    }
    /* Consulta por ID */
    else
    {
        /* Limpando o Buffer do Teclado */
        setbuf(stdin, NULL);

        /* Recebendo os Dados do Usu�rio Referente ao ID desejado */
        printf("\nDigite o ID: ");
        scanf(" %d", &vl_entrada_id);
        printf("\n-------------------------------------------------------------\n");


        while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
        {
            if (vl_entrada_id == Tcadastro.maquinaId)
            {
                printf("\nCADASTRO ID: %d \n", Tcadastro.maquinaId);
                printf("\nNome da M�quina: %s \n", Tcadastro.maquinaNome);
                printf("\nIP da M�quina: %s \n", Tcadastro.maquinaIp);
                printf("\nSO da M�quina: %s \n", Tcadastro.maquinaSo);
                printf("\nVers�o do SO: %s \n", Tcadastro.maquinaVersao);
                printf("\nUsu�rio Respons�vel: %s \n", Tcadastro.maquinaUsuario);
                printf("\nSetor/Departamento da M�quina: %s \n", Tcadastro.maquinaSetor);
                printf("\n-------------------------------------------------------------\n");
                getch();
            }
        }
    }
    fclose(arquivoCadastro);


    /* Limpando o Buffer do Teclado */
    setbuf(stdin, NULL);

    /* Confirma��o de Exclus�o */
    printf("\n\nTem Certeza que Deseja Excluir o Registro[s/n]?");


     /* Exclus�o do Registro por meio de Permuta do Arquivo com os Dados por um Arquivo Tempor�rio */
    if (tolower(getche()) == 's')
    {
        /* Abrindo o BD por meio de um Arquivo de dat */

        arquivoCadastro = fopen("bd/bdCadastro.dat", "rb");

        /* Criando um Arquivo Tempor�rio por meio de um Arquivo de dat */
        FILE* temp;
        temp = fopen("bd/temp.dat", "w");


        /* Tratamento de Erro caso o Arquivo n�o seja: Criado, Encontrado, ou Acesso Permitido*/
        if (arquivoCadastro == NULL)
        {
            printf("\n***************** Arquivo N�o Encontrado! *******************\n");
            exit(1);
        }
        else
        {
            /* Grava��o de Todos os Dados Exceto o que Deseja Excluir no Arquivo Tempor�rio */
            while (fread(&Tcadastro, sizeof(Smaquina), 1, arquivoCadastro) == 1)
            {
                if(vl_entrada_id != Tcadastro.maquinaId)
                {
                    fwrite(&Tcadastro, sizeof(Smaquina), 1, temp);
                }
            }

            /* Tratamento de Erro do Arquivo Tempor�rio */
            if (ferror(temp))
            {
                printf("\n\n-------------------------------------------------------------\n");
                printf("\n********************** Erro ao excluir **********************\n");
                printf("\n-------------------------------------------------------------\n");

            }
            else
            {
                printf("\n\n-------------------------------------------------------------\n");
                printf("\n******************** Exclu�do com Sucesso *******************\n");
                printf("\n-------------------------------------------------------------\n");
            }

        }

        /* Fechando os Arquivos */
        fclose(temp);
        fclose(arquivoCadastro);

        /* Removendo o Arquivo de Dados */
        remove("bd/bdCadastro.dat");

        /* Renomeando o Arquivo Tempor�rio pelo Nome do Arquivo Anteriormente Exclu�do*/
        rename("bd/temp.dat", "bd/bdCadastro.dat");
    }

    /* Limpando o Buffer do Teclado */
    setbuf(stdin, NULL);
}



/*FUN��O PRINCIPAL*/
int main(void)
{



    /* Alterar a Cor do Console */
    system("color F1");/* 1 - azul | F -  branco */

    /* Habilitar o idioma para PTBR - UFT8 */
    setlocale(LC_ALL, "Portuguese");

    /* Titulo da Aplica��o */
    system("title ACM - Aplica��o de Cadastro de M�quinas");

    /* Inicializa os Banco de Dados - bdId | bdCadastro | bdCadastr_bkp*/
    inicializaCadastro();

    /* V�riaveis Locais */
    char vl_opcaoChar[2];
    int vl_opcao = 0;

    /* Seletor de op��es*/

    while (vl_opcao != 7)
    {

        /* Procedimento Menu*/
        menu();

        /* Recebendo os Dados do Usu�rio Referente a Op��o do Menu*/
        printf("\nDigite a Op��o: ");
        fgets(vl_opcaoChar, 2, stdin);

        /* Convertendo a String em Inteiro*/
        vl_opcao = atoi(vl_opcaoChar);

        /* Limpando o Buffer do Teclado */
        setbuf(stdin, NULL);

        switch (vl_opcao)
        {
        case 1:
            /* Procedimento Cadastrar */
            cadastrar();

            /* Limpando o Buffer do Teclado */
            setbuf(stdin, NULL);
            break;

        case 2:
            /* Procedimento Listar Cadastro por ID */
            listarCadastroFiltro();
            getch();
            break;

        case 3:
            /* Procedimento Listar Cadastro */
            listarCadastro();
            getch();
            break;

        case 4:
            /* Procedimento Alterar Cadastro */
            alterarCadastro();
            getch();
            break;


        case 5:
            /* Procedimento Excluir Cadastro */
            excluirCadastro();
            getch();
            break;

        case 6:
            /* Procedimento Realizar Backup do Cadastro */
            realizarBackupCadastro();
            getch();
            break;

        case 7:
            /* Sair da Aplica��o */
            printf("\n-------------------------------------------------------------\n");
            printf("\n********************* Muito Obrigado ************************\n");
            printf("\n-------------------------------------------------------------\n");

            getch();
            break;

        default:
            printf("\n-------------------------------------------------------------\n");
            printf("\n********************* Op��o Inv�lida ************************\n");
            printf("\n-------------------------------------------------------------\n");
            getch();
            setbuf(stdin, NULL);

            break;
        }
    }

    /* Atualiza os Banco de Dados - bdId */
    atualizarId();

    return 0;
}
