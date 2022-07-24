#include "readAndWrite.h"
#include "fileStructs.h"
#include "projectMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include "mainFileEdit.h"
#include "spravFunctions.h"
#include "aboutTheDeveloper.h"


void menu()
{
    while(1){
        system("clear");
        printf("1. File\n");
        printf("2. Edit file\n");
        printf("3. Display file\n");
        printf("4. Export file to TXT\n");
        printf("5. Directory\n");
        printf("6. About programm\n");
        printf("7. Exit\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
        case '1': file();break;
        case '2': edit(); break;
        case '3': vivod(); break;
        case '4': EXPORT(); break;
        case '5': spravochnik(); break;
        case '6': aboutDev(); break;
        case '7': exit(0);
        }
    }
}

void file()
{
    while(1) {
        system("clear");
        printf("1. Open\n");
        printf("2. Save\n");
        printf("3. Close\n");
        printf("4. Back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
        case '1': read(); break;
        case '2': savefile(); break;
        case '3': closefile(); break;
        case '4': return;
        }
    }
}

void edit()
{
    while(1){
        system("clear");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Edit\n");
        printf("4. Back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
        case '1': mainAdd(); break;
        case '2': mainDel(); break;
        case '3': mainEdit(); break;
        case '4': return;
        }
    }
}

void spravochnik(){
    while(1){
        system("clear");
        printf("1. Choose\n");
        printf("2. Display\n");
        printf("3. Edit\n");
        printf("4. Add\n");
        printf("5. Delete\n");
        printf("6. Back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
        case '1': choose(); break;
        case '2': displaySprav(); break;
        case '3': spravEdit(); break;
        case '4': spravAdd(); break;
        case '5': spravDelete(); break;
        case '6': remove("/home/abdurakhman/Usmanov_ICTMS-1-5/spravFile.db"); return;
        }
    }
}

void choose(){
    while(1){
        system("clear");
        printf("1. names\n");
        printf("2. ports\n");
        printf("3. back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
        case '1': nameOpen(); break;
        case '2': portOpen(); break;
        case '3': return;
        }
    }
}









