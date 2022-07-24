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
    FILE *in = 0, *in2 = 0;
    int nN=0;
    char nc[50] = {0};
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    if (!in){
        printf("\n\nFile is not opened");
        return;
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in);
    int i, id;
    char zap[15];
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write info: ");
    scanf("%s", zap);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","a+");
    fseek(in,0,SEEK_END);
    fprintf(in, "%d;%s;\n", id, zap);
    fclose(in);
    nN++;
    char buf[100] = {0};
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","r");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","w");
    for(i=0;i<nN;i++)
        fputs(fgets(buf,100,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nSuccessful\n");
    printf("Enter any character to escape: ");
    char z[5];
    scanf("%s",z);
    return;
}

void spravDelete(){
    FILE *in = 0, *in2 = 0;
    int i, k = 0;
    struct name *sprav;
    int nN = 0;
    char nc[50] = { 0 };
    char str[100] = { 0 };
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    if (!in2){
        printf("\n\nFile is not opened");
        return;
    }
    while(fscanf(in2,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in2);
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    sprav = (struct name*)malloc(nN * sizeof(struct name));
    for (i = 0; i < nN; i++) {
        fscanf(in2, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].name, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in2);
    printf("\n\nWrite id to delete: ");
    scanf("%d", &k);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","w");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    for(i=0;i<nN;i++)
        if(k==sprav[i].id)
            continue;
        else
            fprintf(in, "%d;%s;\n", sprav[i].id, sprav[i].name);
    fclose(in);
    fclose(in2);
    nN--;
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","r");
    char buf[100] = {0};
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","w");
    for(i=0;i<nN;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nSuccessful\n");
    printf("Enter any character to escape: ");
    char z[5];
    scanf("%s",z);
    return;
}

void spravEdit(){
    FILE *in = 0, *in2 = 0;
    int i, k = 0;
    struct name *sprav;
    int nN = 0;
    char nc[50] = { 0 };
    char str[100] = { 0 };
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    if (!in){
        printf("\n\nFile is not opened");
        return;
    }
    while(fscanf(in2,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in2);
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    sprav = (struct name*)malloc(nN * sizeof(struct name));
    for (i = 0; i < nN; i++) {
        fscanf(in2, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].name, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in2);
    printf("\n\nWrite id to edit: ");
    scanf("%d", &k);
    char rep[15];
    printf("Write name: ");
    scanf("%s", rep);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","w");
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","r");
    for(i=0;i<nN;i++)
        if(k==sprav[i].id)
            fprintf(in, "%d;%s;\n", k, rep);
        else
            fprintf(in, "%d;%s;\n", sprav[i].id, sprav[i].name);
    fclose(in);
    fclose(in2);
    in = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db","r");
    char buf[100] = {0};
    in2 = fopen("/home/abdurakhman/Usmanov_ICTMS-1-5/name.db","w");
    for(i=0;i<nN;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nSuccessful\n");
    printf("Enter any character to escape: ");
    char z[5];
    scanf("%s",z);
    return;
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
    //printf("\n\nFile opened\n");
    //printf("write SHOW to show file: ");
    //char z[5];
    //scanf("%s",z);
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
    //printf("\n\nFile opened\n");
    //printf("write SHOW to show file: ");
    //char z[5];
    //scanf("%s",z);
    displaySprav();
    return;
}
















