#include <stdio.h>
#include <stdlib.h>

void insertAndSaveNumbers() {
    FILE *archiver;
    int number[10];
    int i;

    puts("Informe 10 numeros");
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &number[i]);
    }

    archiver = fopen("numbers.bin", "wb");

    if (archiver == NULL) {
        puts("Nao se pode criar o arquivo");
        exit(1);
    }

    fwrite(number, sizeof(int), 10, archiver);

    fclose(archiver);

    puts("Numeros foram salvos com sucesso");
}

void readNumbers() {
    FILE *archiver;
    int number[10];

    archiver = fopen("numbers.bin", "rb");

    if (archiver == NULL) {
        puts("Nao foi possível abrir o arquivo");
        exit(1);
    }

    fread(number, sizeof(int), 10, archiver);

    puts("Numeros lidos do arquivo:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", number[i]);
    }

    fclose(archiver);
}

void showNumberAtPosition() {
    FILE *archiver;
    int position;
    int number;

    archiver = fopen("numbers.bin", "rb");

    if (archiver == NULL) {
        puts("Nao foi possível abrir o arquivo");
        exit(1);
    }

    printf("Informe a posicao do numero no arquivo (comecando de 0): ");
    scanf("%d", &position);

    fseek(archiver, position * sizeof(int), SEEK_SET);
    fread(&number, sizeof(int), 1, archiver);

    printf("Numero na posicao %d: %d\n", position, number);

    fclose(archiver);
}

int menu() {
    int option;
    puts("1 - Inserir e salvar numeros");
    puts("2 - Ler numeros");
    puts("3 - Mostrar numero em uma posicao");
    puts("5 - Sair");
    printf("Opcao: ");
    scanf("%d", &option);
    return option;
}

void menuOption(int option) {
    switch (option) {
        case 1:
            insertAndSaveNumbers();
            break;
        case 2:
            readNumbers();
            break;
        case 3:
            showNumberAtPosition();
            break;
        case 4:
            exit(0);
            break;
        default:
            puts("Opção inválida");
            break;
    }
}

int main() {
    int option;
    do {
        option = menu();
        menuOption(option);
    } while (option != 5);

    return 0;
}
