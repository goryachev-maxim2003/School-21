#ifndef LIST_H
#define LIST_H

struct node {
    struct door* info;
    struct node* next;
};

// void output(struct node* doors);

struct node* init(struct door* door);  //Инициализация

struct node* add_door(
    struct node* elem,
    struct door* door);  //вставка нового struct door лемента в односвязный список после переданного elemузла

struct node* find_door(int door_id, struct node* root);  //поиск по id

struct node* remove_door(struct node* elem, struct node* root);  //Удаление

void destroy(struct node* root);  //освобождение памяти, занятой структурой списка

#endif