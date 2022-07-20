#include "readAndWrite.h"
#include "fileStructs.h"
#include "projectMenu.h"
#include "spravFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>


void read()
{
    FILE *in = 0, *in2 = 0;
    char buf[500];
    int i;
    char s[10];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/yachtclub.db","r");
    if (!in) {
        printf("\n\nERROR\n");
        printf("\n\nwrite EXIT to escape: ");
        scanf("%s",s);
        return file();
    }
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/yachtclub.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainf.db","w");
    for(i=0;i<10;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nSuccessful\n");
    printf("write SHOW to show file: ");
    char z[5];
    scanf("%s",z);
    vivod();
    return;
}

void savefile(){
    FILE *in = 0, *in2 = 0;
    int i, mN = 0;
    char buf[100], nc[100] = {0};
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainf.db","r");
    char s[10];
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("write EXIT to escape: ");
        scanf("%s",s);
        return file();
    }
    while(fscanf(in,"%s",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainf.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/yachtclub.db","w");
    for(i=0;i<mN;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    return;
}

void closefile(){
    FILE *in = 0;
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/mainf.db","r");
    char s[10];
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("write EXIT to escape: ");
        scanf("%s",s);
    }
    else {
        printf("\n\nFile closed\n");
        printf("write EXIT to escape: ");
        scanf("%s",s);
        remove("/home/abdurakhman/Usmanov_ICTMS-1-5/mainf.db");
    }
    return;
}


void vivod(protect)
{
    system("clear");
    FILE *in = 0, *in2 = 0, *in3 = 0;
    int lN = 0, nN = 0, pN = 0;
    char nc[50] = { 0 };
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/yachtclub.db","r");
    while(fscanf(in,"%s",nc)!=EOF)
        lN++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/yachtclub.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    while(fscanf(in2,"%s",nc)!=EOF)
        nN++;
    fclose(in2);
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    in3 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    while(fscanf(in3,"%s",nc)!=EOF)
        pN++;
    fclose(in3);
    in3 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    struct list *yacht;
    yacht = (struct list*)malloc(lN * sizeof(struct list));
    int i, j, k;
    char str[100] = { 0 };
    for (i = 0; i < lN; i++) {
        fscanf(in, "%s", str);
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
    struct name *sprav;
    sprav = (struct name*)malloc(nN * sizeof(struct name));
    for (i = 0; i < nN; i++) {
        fscanf(in2, "%s", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].name, tok);
            tok = strtok(NULL, ";");
        }
    }
    struct port *hp;
    hp = (struct port*)malloc(pN * sizeof(struct name));
    for (i = 0; i < pN; i++) {
        fscanf(in3, "%s", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            hp[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(hp[i].city, tok);
            tok = strtok(NULL, ";");
        }
    }

    if(protect == 1){
        FILE *EXPORTTXT = 0;
        EXPORTTXT = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/EXPORT.txt","w");

        for (i=0;i<lN;i++){
            for (j=0;j<nN;j++)
                if (sprav[j].id==yacht[i].id)
                    strcpy(yacht[i].idName,sprav[j].name);
            for (k=0;k<pN;k++)
                if (atoi(yacht[i].idPort)==hp[k].id)
                    strcpy(yacht[i].idPort,hp[k].city);
            fprintf(EXPORTTXT, "|%-2d|%-6s|%-18s|%-20s|%-20s|%-20s|%-20s|\n", yacht[i].id, yacht[i].gosId, yacht[i].idName,
                    yacht[i].yachtClass, yacht[i].yachtType, yacht[i].yachtBody, yacht[i].idPort);
        }

        fclose(EXPORTTXT);
        printf("Export was succsessful");
        printf("\nwrite EXIT to escape: ");
        char s[10];
        scanf("%s",s);
        protect = 0;
        return;
    }
    system("clear");
    for(i=0;i<100;i++)
        str[i]=' ';
    for(i=0;i<100;i++)
        nc[i]=' ';

    for (i=0;i<lN;i++){
        for (j=0;j<nN;j++)
            if (sprav[j].id==atoi(yacht[i].idName))
                strcpy(yacht[i].idName,sprav[j].name);
        for (k=0;k<pN;k++)
            if (atoi(yacht[i].idPort)==hp[k].id)
                strcpy(yacht[i].idPort,hp[k].city);
        printf("|%-2d|%-6s|%-18s|%-10s|%-10s|%-14s|%-12s|\n", yacht[i].id, yacht[i].gosId, yacht[i].idName, yacht[i].yachtClass,
               yacht[i].yachtType, yacht[i].yachtBody, yacht[i].idPort);
    }

    printf("\n\nwrite EXIT to escape: ");
    char s[10];
    scanf("%s",s);
    return;
}

void EXPORT(){
    int protect = 1;
    vivod(protect);
}

void nameopen(){
    FILE *in = 0, *in2 = 0;
    int i = 0;
    char buf[500];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    int NC=0;
    char str[50] = { 0 };
    while(fscanf(in,"%s",str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/sprav.db","w");
    for(i=0;i<NC;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nFile opened\n");
    printf("write SHOW to show file: ");
    char z[5];
    scanf("%s",z);
    dispSpr();
    return;
}

void portopen(){
    FILE *in = 0, *in2 = 0;
    int i = 0;
    char buf[500];
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    int NC=0;
    char str[50] = { 0 };
    while(fscanf(in,"%s",str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/home_port.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/sprav.db","w");
    for(i=0;i<NC;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nFile opened\n");
    printf("write SHOW to show file: ");
    char z[5];
    scanf("%s",z);
    dispSpr();
    return;
}


void about()
{
    printf("\n\n\nDeveloping of programm for working with list of yacht attributed to club");
    printf("\nDeveloped by student of ICTMS 1-5");
    printf("\nUsmanov Abdurakhman Khasmagamedovich, 2022 year");
    printf("\n\nwrite EXIT to escape: ");
    char s[10];
    scanf("%s",s);
    return;
}

