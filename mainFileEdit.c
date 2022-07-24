#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include "readAndWrite.h"
#include "fileStructs.h"
#include "projectMenu.h"
#include "mainFileEdit.h"
#include "spravFunctions.h"

void mainAdd(){
    FILE *in = 0;
    int id, idName, idPort, mN = 0;
    char gosId[10], yachtClass[15], yachtType[15], yachtBody[15];
    char nc[100]= {0};
    char s[10];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","r");
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("Enter any character to escape: ");
        scanf("%s",s);
        return;
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","a+");
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write state number of yacht: ");
    scanf("%s", gosId);
    printf("Write id of owner: ");
    scanf("%d", &idName);
    printf("Write yacht class: ");
    scanf("%s", yachtClass);
    printf("Write type of yacht: ");
    scanf("%s", yachtType);
    printf("Write type of corpus: ");
    scanf("%s", yachtBody);
    printf("Write id of home port: ");
    scanf("%d", &idPort);
    fseek(in,0,SEEK_END);
    fprintf(in, "%d;%s;%d;%s;%s;%s;%d;\n", id, gosId, idName, yachtClass, yachtType, yachtBody, idPort);
    fclose(in);
    printf("\n\nSuccessful\n");
    //printf("write SHOW to show file: ");
    //char z[5];
    //scanf("%s",z);
    savefile();
    vivod();
    return;
}



void mainDel(){
    FILE *in = 0;
    int i, id, mN = 0;
    char str[100] = {0}, nc[100]= {0};
    char s[10];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","r");
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("Enter any character to escape: ");
        scanf("%s",s);
        return edit();
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","r");
    struct list *yacht;
    yacht = (struct list*)malloc(mN * sizeof(struct list));
    for (i = 0; i < mN; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            yacht[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].gosId, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].idName, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].yachtClass, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].yachtType, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].yachtBody, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].idPort, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","w");
    printf("\n\nWrite id to delete: ");
    scanf("%d", &id);
    for(i=0;i<mN;i++)
        if(id==yacht[i].id)
            continue;
        else
            fprintf(in, "%d;%s;%s;%s;%s;%s;%s;\n", yacht[i].id, yacht[i].gosId,
                    yacht[i].idName, yacht[i].yachtClass, yacht[i].yachtType, yacht[i].yachtBody, yacht[i].idPort);
    fclose(in);
    printf("\n\nSuccessful\n");
    //printf("write SHOW to show file: ");
    //char z[5];
    //scanf("%s",z);
    savefile();
    vivod();
    return;
}




void mainEdit(){
    FILE *in = 0;
    int i, id, idPort, mN = 0;
    char gosId[10], yachtClass[15], yachtType[15], yachtBody[15];
    char str[100] = {0}, nc[100]= {0};
    char s[10];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","r");
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("Enter any character to escape: ");
        scanf("%s",s);
        return edit();
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","r");
    struct list *yacht;
    yacht = (struct list*)malloc(mN * sizeof(struct list));
    for (i = 0; i < mN; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            yacht[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].gosId, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].idName, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].yachtClass, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].yachtType, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].yachtBody, tok);
            tok = strtok(NULL, ";");
            strcpy(yacht[i].idPort, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    printf("\n\nWrite id to edit: ");
    scanf("%d", &id);
    printf("Write new state number of yacht: ");
    scanf("%s", gosId);
    printf("Write new yacht class: ");
    scanf("%s", yachtClass);
    printf("Write new type of yacht: ");
    scanf("%s", yachtType);
    printf("Write type of corpus: ");
    scanf("%s", yachtBody);
    printf("Write id of home port: ");
    scanf("%d", &idPort);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainFileYacht.db","w");
    for(i=0;i<mN;i++)
        if(id==yacht[i].id)
            fprintf(in, "%d;%s;%s;%s;%s;%s;%d;\n", id, gosId, yacht[i].idName, yachtClass, yachtType, yachtBody, idPort);
        else
            fprintf(in, "%d;%s;%s;%s;%s;%s;%s;\n", yacht[i].id, yacht[i].gosId, yacht[i].idName,
                    yacht[i].yachtClass, yacht[i].yachtType, yacht[i].yachtBody, yacht[i].idPort);
    fclose(in);
    printf("\n\nSuccessful\n");
    //printf("write SHOW to show file: ");
    //char z[5];
    //scanf("%s",z);
    savefile();
    vivod();
    return;
}

