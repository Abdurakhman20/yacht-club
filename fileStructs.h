#ifndef FILESTRUCTS_H
#define FILESTRUCTS_H

struct list{
      int id;
      char gosId[20];
      char idName[20];
      char yachtClass[20];
      char yachtType[20];
      char yachtBody[20];
      char idPort[20];
};

struct name
{
    int id;
    char name[20];
} ;

struct port
{
    int id;
    char city[20];
} ;


void closefile();
void savefile();
//void menu();
void vivod();
//void spravochnik();
//void choose();
void nameopen();
void portopen();
void dispSpr();
//void file();
//void edit();
void mainAdd();
void mainDel();
void mainEdit();
void about();
void sprAdd();
void sprDel();
void sprEdit();
void EXPORT();
void SPpr();




#endif // FILESTRUCTS_H
