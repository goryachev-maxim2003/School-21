#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"
// void output(struct node* doors){
//     struct node* p = doors;
//     while (p!=NULL){
//         printf("address:%p ", p);
//         printf("id:%d ", p->info->id);
//         printf("status:%d ", p->info->status);
//         printf("next:%p\n", p->next);
//         p = p->next;
//     }
//     printf("\n");
// }

struct node* init(struct door* door) {
    struct node* element = malloc(sizeof(struct node));
    element->info = door;
    element->next = NULL;
    return element;
}  //Инициализация

struct node* add_door(struct node* elem, struct door* door) {
    struct node* new = malloc(sizeof(struct node));
    new->info = door;
    new->next = elem->next;
    elem->next = new;
    return new;
}  //вставка нового struct door лемента в односвязный список после переданного elem узла

struct node* find_door(int door_id, struct node* root) {
    struct node* p = NULL;
    while (root != NULL) {
        if (root->info->id == door_id) {
            p = root;
            break;
        }
        root = root->next;
    }
    return p;

}  //поиск по id

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* p = root;
    //Условие для первого
    if (root == elem) {
        root = root->next;  //Новый корень списка
        free(p);
    } else {
        while (p->next != NULL) {
            //Условие сработает правильно даже если элемент - последний
            if (p->next == elem) {
                p->next = elem->next;  //В указатель перед el записываем адрес элемента после el
                free(elem);
                break;
            }
            p = root->next;
        }
    }
    return root;  //Корень списка
}  //Удаление

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* p = root;
        root = root->next;
        free(p);
    }
}  //освобождение памяти, занятой структурой списка
