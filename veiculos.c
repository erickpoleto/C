#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>


typedef struct{
    char brand[100];
    char model[100];
    int plateNumbers;
    char plateLetters[4];
    int fabricationYear;
} Veicle;


static int MAX=4;

void sortByYear(Veicle veicl[]);
void insertVeicle();
void printVeicles(Veicle veicl[]);
void costructVeicle();
void insertFabYear();
void printVeiclesByFabYear(Veicle veicl[]);
void printVeiclesBiggerThanFabYear(Veicle veicl[]);
void insertBrand();
void insertModel();
void insertPlateNumber();
void insertPlateLetters();
void printVeiclesByModel(Veicle veicl[]);

static Veicle veicles[4];
static Veicle veicleConstruction;

int main(void){
    veicles[0].fabricationYear = 1972;
    veicles[1].fabricationYear = 1971;
    int option = 0;
    while(option != 6){

        printf("1 - insert veicle\n");
        printf("2 - list veicles\n");
        printf("3 - list veicles by year\n");
        printf("4 - list veicles bigger than choosed year\n");
        printf("5 - list veicles by model\n");
        printf("6 - exit\n");
        printf("choose an option: ");
        scanf("%d", &option);

        if(option < 1 || option > 6){
            printf("opção inválida");
            break;
        }

        switch(option){
            case 1:
                insertVeicle();
                break;
            case 2:
                printVeicles(veicles);
                break;
            case 3:
                printVeiclesByFabYear(veicles);
                break;
            case 4:
                printVeiclesBiggerThanFabYear(veicles);
                break;
            case 5:
                printVeiclesByModel(veicles);
                break;
        }

    }
}

void costructVeicle() {
    printf("veicle informations");
    printf("\n");
    insertFabYear();
    insertBrand();
    insertModel();
    insertPlateNumber();
    insertPlateLetters();
}

void insertFabYear() {
    printf("fabrication year: ");
    scanf("%d", &veicleConstruction.fabricationYear);
    if(veicleConstruction.fabricationYear > 2020 || veicleConstruction.fabricationYear < 1900) {
        printf("fabrication year is invalid!");
        printf("\n");
        insertFabYear();
    }
}

void insertBrand() {
    printf("Brand: ");
    scanf("%s", veicleConstruction.brand);
}

void insertModel() {
    printf("Model: ");
    scanf("%s", veicleConstruction.model);
}

void insertPlateNumber() {
    do{
    printf("Plate Numbers(XXX):");
    scanf("%d", &veicleConstruction.plateNumbers);
    }while(veicleConstruction.plateNumbers < 100 || veicleConstruction.plateNumbers >= 1000);

}

void insertPlateLetters() {
  char word[4];
    printf("Plate letters(YYYY):");
    scanf("%s", word);
    if(word[3] != '\0'){
        for(int i = 0; i < 4; i++){
            veicleConstruction.plateLetters[i] = word[i];
        }
    }else {
        printf("\n");
        printf("invalid value!");
        insertPlateLetters();
    }
}


void insertVeicle() {
    costructVeicle();
    for(int i = 0; i < MAX; i++) {
        if(veicles[i].fabricationYear < 1) {
            veicles[i] = veicleConstruction;
            break;
        }
    }
    sortByYear(veicles);
}


void swap(Veicle *veicleMin, Veicle *veiclePos)
{
    Veicle temp = *veicleMin;
    *veicleMin = *veiclePos;
    *veiclePos = temp;
}


void sortByYear(Veicle veicl[])
{
    int min_idx;

    for (int i = 0; i < MAX-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < MAX; j++)
        if (veicl[j].fabricationYear < veicl[min_idx].fabricationYear)
            min_idx = j;
        swap(&veicl[min_idx], &veicl[i]);
    }
}

void printVeicles(Veicle veicl[])
{
    int i;
    for (i=0; i < MAX; i++){
        if(veicles[i].fabricationYear != 0){
            printf("%d ", veicl[i].fabricationYear);
            printf(" | ");
            printf("%s", veicl[i].brand);
            printf(" | ");
            printf("%s", veicl[i].model);
            printf(" | ");
            printf("%d-%s", veicl[i].plateNumbers, veicl[i].plateLetters);
            printf("\n");
        }
    }
}

void printVeiclesByFabYear(Veicle veicl[])
{
    int fabYear = 0;
    printf("fabrication year: ");
    scanf("%d", &fabYear);

    if(fabYear > 2020 || fabYear < 1900) {
        printf("\n");
        printf("fabrication year is invalid!");
        printf("\n");
        printVeiclesByFabYear(veicl);
    }

    for (int i=0; i < MAX; i++){
        if(veicles[i].fabricationYear == fabYear){
            printf("%d ", veicl[i].fabricationYear);
            printf(" | ");
            printf("%s", veicl[i].brand);
            printf(" | ");
            printf("%s", veicl[i].model);
            printf(" | ");
            printf("%d-%s", veicl[i].plateNumbers, veicl[i].plateLetters);
            printf("\n");
        }
    }
}

void printVeiclesBiggerThanFabYear(Veicle veicl[])
{
    int fabYear = 0;
    printf("fabrication year: ");
    scanf("%d", &fabYear);

    if(fabYear > 2020 || fabYear < 1900) {
        printf("\n");
        printf("fabrication year is invalid!");
        printf("\n");
        printVeiclesBiggerThanFabYear(veicl);
    }

    for (int i=0; i < MAX; i++){
        if(veicles[i].fabricationYear > fabYear){
            printf("%d ", veicl[i].fabricationYear);
            printf(" | ");
            printf("%s", veicl[i].brand);
            printf(" | ");
            printf("%s", veicl[i].model);
            printf(" | ");
            printf("%d-%s", veicl[i].plateNumbers, veicl[i].plateLetters);
            printf("\n");
        }
    }
}

void printVeiclesByModel(Veicle veicl[])
{
    char veicleModel[100];
    printf("model: ");
    scanf("%s", veicleModel);
    for (int i=0; i < MAX; i++){

        if(strcmp(veicl[i].model, veicleModel) == 0){
            printf("%d ", veicl[i].fabricationYear);
            printf(" | ");
            printf("%s", veicl[i].brand);
            printf(" | ");
            printf("%s", veicl[i].model);
            printf(" | ");
            printf("%d-%s", veicl[i].plateNumbers, veicl[i].plateLetters);
            printf("\n");
        }
    }
}



