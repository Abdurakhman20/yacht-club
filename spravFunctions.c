#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include "readAndWrite.h"
#include "fileStructs.h"
#include "projectMenu.h"
#include "mainFileEdit.h"
#include "spravFunctions.h"



void displaySprav(){
    system("clear");
    FILE *in =0;
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","r");
    if (!in){
        printf("\n\nFile is not opened");
        return;
    }
    int NC=0;
    char str[100] = { 0 };
    while(fscanf(in,"%[^\n]%*c",str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","r");
    struct name *sprav;
    sprav = (struct name*)malloc(NC * sizeof(struct name));
    int i;
    for (i = 0; i < NC; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].name, tok);
            tok = strtok(NULL, ";");
        }
    }
    for(i=0;i<NC;i++)
        printf("%-3d %-20s\n", sprav[i].id, sprav[i].name);
    printf("\n\nEnter any character to escape: ");
    char su[10];
    scanf("%s",su);
    return;
}


void spravAdd(){
    while(1){
            system("clear");
            printf("1. add to name.db\n");
            printf("2. add to home_port.db\n");
            printf("3. back\n");
            printf("\nChoose: ");
            int ch = 0;
            ch = getchar();
            printf("\n");
            switch (ch) {
            case '1': spravAdd1(); break;
            case '2': spravAdd2(); break;
            case '3': return;
            }
        }
}

void spravAdd1(){
    FILE *in = 0;
    int nN=0;
    char nc[50] = {0}, z[5];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in);
    int id;
    char zap[20], s1[10];
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write info: ");
    scanf("%s%s", zap, s1);
    strcat(zap, " ");
    strcat(zap, s1);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","a+");
    fseek(in,0,SEEK_END);
    fprintf(in, "%d;%s;\n", id, zap);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    scanf("%s",z);
    return;
}

void spravAdd2(){
    FILE *in = 0;
    int nN=0;
    char nc[50] = {0}, z[5];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in);
    int id;
    char zap[20];
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write info: ");
    scanf("%s", zap);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","a+");
    fseek(in,0,SEEK_END);
    fprintf(in, "%d;%s;\n", id, zap);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    scanf("%s",z);
    return;
}

void spravDelete(){
    while(1){
            system("clear");
            printf("1. Delete from name.db\n");
            printf("2. Delete from home_port.db\n");
            printf("3. back\n");
            printf("\nChoose: ");
            int ch = 0;
            ch = getchar();
            printf("\n");
            switch (ch) {
            case '1': spravDelete1(); break;
            case '2': spravDelete2(); break;
            case '3': return;
            }
        }
}

void spravDelete1(Edit){
    FILE *in = 0;
    int i, k = 0;
    struct name *sprav;
    int nN = 0;
    char nc[50] = { 0 };
    char str[100] = { 0 };
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in);
    sprav = (struct name*)malloc(nN * sizeof(struct name));
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    for (i = 0; i < nN; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].name, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    char zap[20], s1[10];
    if(Edit == 1){
        printf("\n\nWrite id to Edit: ");
        scanf("%d", &k);
        printf("Write info: ");
        scanf("%s%s", zap, s1);
        strcat(zap, " ");
        strcat(zap, s1);
    }
    else{
        printf("\n\nWrite id to delete: ");
        scanf("%d", &k);
    }
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","w");
    for(i=0;i<nN;i++)
        if(k==sprav[i].id){
            if (Edit == 1){
                fprintf(in, "%d;%s;\n", k, zap);
            }
            else
                continue;
        }
        else
            fprintf(in, "%d;%s;\n", sprav[i].id, sprav[i].name);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    char z[5];
    scanf("%s",z);
    return;
}


void spravDelete2(Edit){
    FILE *in = 0;
    int i, k = 0;
    struct name *sprav;
    int nN = 0;
    char nc[50] = { 0 };
    char str[100] = { 0 };
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in);
    sprav = (struct name*)malloc(nN * sizeof(struct name));
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    for (i = 0; i < nN; i++) {
        fscanf(in, "%s", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].name, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    char zap[20];
    if(Edit == 1){
        printf("\n\nWrite id to Edit: ");
        scanf("%d", &k);
        printf("Write info: ");
        scanf("%s", zap);
    }
    else{
        printf("\n\nWrite id to delete: ");
        scanf("%d", &k);
    }
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","w");
    for(i=0;i<nN;i++)
        if(k==sprav[i].id){
            if (Edit == 1){
                fprintf(in, "%d;%s;\n", k, zap);
            }
            else
                continue;
        }
        else
            fprintf(in, "%d;%s;\n", sprav[i].id, sprav[i].name);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    char z[5];
    scanf("%s",z);
    return;
}



void spravEdit(){
    while(1){
           system("clear");
           printf("1. Edit name.db\n");
           printf("2. Edit home_port.db\n");
           printf("3. back\n");
           printf("\nChoose: ");
           int ch = 0;
           ch = getchar();
           printf("\n");
           switch (ch) {
           case '1': spravDelete1(1); break;
           case '2': spravDelete2(1); break;
           case '3': return;
           }
       }
}

void nameOpen(){
    FILE *in = 0, *in2 = 0;
    int i = 0;
    char buf[500];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    int NC=0;
    char str[50] = { 0 };
    while(fscanf(in,"%[^\n]%*c",str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","w");
    for(i=0;i<NC;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    displaySprav();
    return;
}

void portOpen(){
    FILE *in = 0, *in2 = 0;
    int i = 0;
    char buf[500];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    int NC=0;
    char str[50] = { 0 };
    while(fscanf(in,"%[^\n]%*c",str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","w");
    for(i=0;i<NC;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    displaySprav();
    return;
}
















