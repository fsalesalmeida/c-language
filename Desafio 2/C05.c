#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct Contact{
    char name[64];
    char address[64];
    int birthDay;
    int birthMonth;
    int birthYear;
    float salary;
};

FILE *p;
main(){
    struct Contact contact;
    int menuOption = 0;
    while(1){
        printf("\n============= DESAFIO 02 - C05 - BEATRIZ, FABIO E JOAO =============\n\n");
        printf("\n1 - Entra dados");
        printf("\n2 - Lista dados na tela");
        printf("\n3 - Pesquisar pelo nome completo");
        printf("\n4 - Pesquisar por endereco completo");
        printf("\n5 - Pesquisar aniversariantes de um determinado mes");
        printf("\n6 - Pesquisar por faixa salarial");
        printf("\n7 - Pesquisar por nome e alterar salario");
        printf("\n8 - Pesquisar por nome e alterar dados");
        printf("\n9 - Pesquisar por nome e excluir");
        printf("\n10 - Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertContact(&contact);
                break;
            case 2:
                getContacts(&contact);
                break;
            case 3:
                getContactByName(&contact);
                break;
            case 4:
                getContactByAddress(&contact);
                break;
            case 5:
                getBirthdayPeopleOfTheMonth(&contact);
                break;
            case 6:
                getSalaryByRange(&contact);
                break;
            case 7:
                updateSalary(&contact);
                break;
            case 8:
                updateContact(&contact);
                break;
            case 9:
                deleteContact(&contact);
                break;
            case 10:
                break;
            default:
                printf("Opcao invalida.\n\n");
        }
        if(menuOption == 10){
            break;
        }
    }
}
void insertContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o nome do contato: ");
    gets(contact->name);
    printf("Digite o endereco do contato: ");
    gets(contact->address);
    printf("Digite o dia do nascimento do contato: ");
    scanf("%d", &contact->birthDay);
    printf("Digite o mes do nascimento do contato: ");
    scanf("%d", &contact->birthMonth);
    printf("Digite o ano do nascimento do contato: ");
    scanf("%d", &contact->birthYear);
    printf("Digite o salario do contato: ");
    scanf("%f", &contact->salary);

    fwrite(contact, sizeof(struct Contact), 1, p);
    fclose(p);
}

void deleteContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do contato: ");
    scanf("%s", &name);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            *contact->name = '\0';
            fseek(p, sizeof(struct Contact) * i, 0);
            fwrite(contact, sizeof(struct Contact), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Registro nao encontrado\n");
    }
    fclose(p);
}

void getContactByName(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    printf("Digite o nome do contato: ");
    scanf("%s", &name);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            printf("Nome: %s\n",contact->name);
            printf("Endereco: %s\n",contact->address);
            printf("Data de Nascimento: %d/%d/%d\n", contact->birthDay, contact->birthMonth, contact->birthYear);
            printf("Salario: %.2f\n", contact->salary);

            break;
        }
    }
    if(result != 1){
        printf("Registro nao encontrado\n");
    }
    fclose(p);
}

void getContactByAddress(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char address[64];
    int result;
    printf("Digite o endereco do contato: ");
    scanf("%s", &address);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&address, contact->address);
        if(result == 1){
            printf("Nome: %s\n",contact->name);
            printf("Endereco: %s\n",contact->address);
            printf("Data de Nascimento: %d/%d/%d\n", contact->birthDay, contact->birthMonth, contact->birthYear);
            printf("Salario: %.2f\n", contact->salary);
            break;
        }
    }
    if(result != 1){
        printf("Registro nao encontrado\n");
    }
    fclose(p);
}

void getContacts(struct Contact *contact){
    if((p = fopen("contacts.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(contact, sizeof(struct Contact), 1, p)){
        if(*contact->name != '\0'){
            printf("Nome: %s\n",contact->name);
            printf("Endereco: %s\n",contact->address);
            printf("Data de Nascimento: %d/%d/%d\n", contact->birthDay, contact->birthMonth, contact->birthYear);
            printf("Salario: %.2f\n\n", contact->salary);
        }
    }
    fclose(p);
}

void getBirthdayPeopleOfTheMonth(struct Contact *contact){
    int result;
    int flag = 0;
    if((p = fopen("contacts.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    printf("Digite o mes para buscar aniversariante: ");
    scanf("%d", &result);

    while(fread(contact, sizeof(struct Contact), 1, p)){
        if(result == contact->birthMonth){
            printf("Nome: %s\n",contact->name);
            printf("Endereco: %s\n",contact->address);
            printf("Data de Nascimento: %d/%d/%d\n", contact->birthDay, contact->birthMonth, contact->birthYear);
            printf("Salario: %.2f\n", contact->salary);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("Registro nao encontrado\n");
    }
    fclose(p);
}

void updateContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome a ser alterado: ");
    scanf("%s", &name);

    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            printf("Alterando contato...\n");
            getchar();
            printf("Digite o nome do contato: ");
            gets(contact->name);
            printf("Digite o endereco do contato: ");
            gets(contact->address);
            printf("Digite o dia do nascimento do contato: ");
            scanf("%d", &contact->birthDay);
            printf("Digite o mes do nascimento do contato: ");
            scanf("%d", &contact->birthMonth);
            printf("Digite o ano do nascimento do contato: ");
            scanf("%d", &contact->birthYear);
            printf("Digite o salario do contato: ");
            scanf("%f", &contact->salary);
            fseek(p, sizeof(struct Contact) * i, 0);
            fwrite(contact, sizeof(struct Contact), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Registro nao encontrado\n");
    }
    fclose(p);
}

void getSalaryByRange(struct Contact *contact) {
    float begin_range;
    float end_range;
    int flag = 0;
    if((p = fopen("contacts.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    printf("Digite Salario Inicial da Faixa: ");
    scanf("%f", &begin_range);

    do{
        printf("Digite Salario final da Faixa: ");
        scanf("%f", &end_range);
        if (end_range < begin_range){
            printf("\nValor final precisa ser maior que valor inicial!\n\n");
        }
    }while (end_range < begin_range);

   while(fread(contact, sizeof(struct Contact), 1, p)){
        if(contact->salary >= begin_range && contact->salary <= end_range){
            printf("Nome: %s\n",contact->name);
            printf("Endereco: %s\n",contact->address);
            printf("Data de Nascimento: %d/%d/%d\n", contact->birthDay, contact->birthMonth, contact->birthYear);
            printf("Salario: %.2f\n\n", contact->salary);
            flag = 1;
        }
    }

    if(flag != 1){
        printf("Registro nao encontrado\n");
    }
    fclose(p);

}

void updateSalary(struct Contact *contact) {
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome para o salario ser alterado: ");
    scanf("%s", &name);

    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            printf("Alterando salario...\n");
            getchar();
            printf("Digite o salario do contato: ");
            scanf("%f", &contact->salary);
            fseek(p, sizeof(struct Contact) * i, 0);
            fwrite(contact, sizeof(struct Contact), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Registro nao encontrado\n");
    }
    fclose(p);
}

int areEqual(char *firstString, char *secondString){
    int result = 0;
    int i = 0;
    for(i; firstString[i] != '\0' ||secondString[i] != '\0'; i++){
        if(firstString[i] != secondString[i]){
            result = 4;
            if(firstString[i] == '\0' && secondString[i] != '\0'){
                result = 3;
                break;
            }
            else{
                if(firstString[i] != '\0' && secondString[i] == '\0'){
                    result = 2;
                    break;
                }
            }
        }
        else{
            result = 1;
        }
    }
    return result;
}
