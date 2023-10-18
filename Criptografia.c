#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Esta função preenche os alfabetos maiúsculos e minúsculos
void preencher(char alfabetoMaiusculo[], char alfabetoMinusculo[])
{
    char letraMaiuscula = 'A';
    char letraMinuscula = 'a';

    for (int i = 0; i < 26; i++)
    {
        alfabetoMaiusculo[i] = letraMaiuscula;
        alfabetoMinusculo[i] = letraMinuscula;
        letraMaiuscula++;
        letraMinuscula++;
    }
}

// Esta função criptografa o texto
void criptografar(char texto[], char texto_codificado[])
{

    char alfabetoMaiusculo[26];
    char alfabetoMinusculo[26];

    preencher(alfabetoMaiusculo, alfabetoMinusculo);

    //int comp = strlen(texto);

    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == ' ')
        {
            texto_codificado[i] = ' ';
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (texto[i] == alfabetoMaiusculo[j])
                {
                    texto_codificado[i] = alfabetoMaiusculo[(j + 3) % 26];
                }

                else if (texto[i] == alfabetoMinusculo[j])
                {
                    texto_codificado[i] = alfabetoMinusculo[(j + 3) % 26];
                }
            }
        }
    }
}

// Esta função descriptografa o texto
void descriptografar(char texto[], char texto_decodificado[])
{

    char alfabetoMaiusculo[26];
    char alfabetoMinusculo[26];

    preencher(alfabetoMaiusculo, alfabetoMinusculo);

    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == ' ')
        {
            texto_decodificado[i] = ' ';
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (texto[i] == alfabetoMaiusculo[j])
                {
                    texto_decodificado[i] = alfabetoMaiusculo[(j - 3 + 26) % 26];
                }

                else if (texto[i] == alfabetoMinusculo[j])
                {
                    texto_decodificado[i] = alfabetoMinusculo[(j - 3 + 26) % 26];
                }
            }
        }
    }
}

int main()
{
    char alfabetoMaiusculo[26];
    char alfabetoMinusculo[26];
    char texto[1000];
    char texto_codificado[1000];
    char texto_decodificado[1000];
    int opcao;

    while (1)
    {

        printf("\n[1] Criptografar texto na Cifra de César.\n[2] Decodificar texto que está na Cifra de César.\n[0] Encerrar programa.\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o texto que você deseja criptografar: ");
            getchar(); // Consumir a quebra de linha pendente
            fgets(texto, 1000, stdin);

            // Remova a quebra de linha do final do texto
            texto[strlen(texto) - 1] = '\0';

            memset(texto_codificado, 0, sizeof(texto_codificado));

            criptografar(texto, texto_codificado);

            printf("\nTexto criptografado: %s\n", texto_codificado);

            break;

        case 2:

            printf("Digite o texto que você deseja descriotografar: ");
            getchar();
            fgets(texto_codificado, 1000, stdin);

            // Remova a quebra de linha do final do texto
            texto_codificado[strlen(texto_codificado) - 1] = '\0';

            memset(texto_decodificado, 0, sizeof(texto_decodificado));

            descriptografar(texto_codificado, texto_decodificado);

            printf("\nTexto descriptografado: %s\n", texto_decodificado);

            break;

        case 0:

            printf("\nPrograma Encerrado!\nObrigado!");
            return 0;

        default:
            printf("Opção inválida\n");
            break;
        }
    }

    return 0;
}
