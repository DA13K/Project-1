#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    short day;
    short month;
    short year;
} Date;

typedef struct{
    //Geral
    int id;
    Date creationDate;
    char* description;

    //toDo list
    short priority;

    //doing list
    char* person;
    Date deadline;

    //done list
    Date concluDate;
} Card;

typedef struct lnode* List; 

typedef struct lnode {
    Card* info;
    List next;
    short flag;
} ListNode;

#endif // DATA_H_INCLUDED

//Função para criar uma data
Date createDate(short year, short month, short day);

// Função para criar um cartão
Card* createCard(char* description, short priority);

// Função para criar uma lista
List createList(short f);

// Função para eliminar uma lista
void deleteList(List trash);

// Funcão para inserir item ordenado
void insertNode(List list, Card* card);

//Função que procura um cartão na lista
void listSearch(List list, Card* card, List* prev, List* atual);

// Função para mover os cartões entre listas
void moveToList(List listO, List listD, Card* card);

// Função para alterar a pessoa responsável pela tarefa
void changePerson(List list, Card* card, char* newPerson);

// Função para eliminar elemento de uma lista
void deleteFromList(List list, Card* Card);

// Função para visualizar o quadro
void printBoard(List toDo, List doing, List done);

// Função para visualizar tarefas por data de criação
void printByCreation(List toDo, List doing, List done);

//Função para visualizar tarefas de uma pessoa
void printByPerson(List toDo, List doing, List done, char* person);

//Função para visualizar todas as tarefas por ordem de criação
void printByDate(List toDo, List doing, List done);

//Função de teste para imprimir uma lista
void printTeste(List list);
 
//Função para guardar no ficheiro as alterações
void saveFile(List toDo, List doing, List done);

void readFile(List toDo, List doing, List done);