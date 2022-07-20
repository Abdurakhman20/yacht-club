#ifndef FILESTRUCTS_H
#define FILESTRUCTS_H

struct list{
      int id;
      char gosId[20];
      char idName[50];
      char yachtClass[50];
      char yachtType[50];
      char yachtBody[50];
      char idPort[50];
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
void vivod();
void nameopen();
void portopen();
void about();
void EXPORT();
void SPpr();




#endif // FILESTRUCTS_H
