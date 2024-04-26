#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

void add_door_test();
void remove_door_test();

int main() {
    struct door door1 = {2, 0};
    struct door door2 = {3, 1};
    struct door door3 = {4, 1};
    struct node *doors = init(&door1);
    add_door(doors, &door2);
    add_door(doors, &door3);
    // 2 4 3
    // Test add_door
    (doors->info->id == 2) ? printf("SUCCESS\n") : printf("FAIL\n");
    (doors->next->info->id == 4) ? printf("SUCCESS\n") : printf("FAIL\n");
    (doors->next->next->info->id == 3) ? printf("SUCCESS\n") : printf("FAIL\n");

    //Для cppcheck
    (find_door(4, doors)->info->id == 4) ? printf("SUCCESS\n") : printf("FAIL\n");

    // Text remove_door
    doors = remove_door(doors->next->next, doors);                         //Удаляем последний
    (doors->next->next == NULL) ? printf("SUCCESS\n") : printf("FAIL\n");  // NEXT последнего элемента
    (doors->next->info->id == 4) ? printf("SUCCESS\n") : printf("FAIL\n");
    doors = remove_door(doors, doors);  //Удаляем первый
    (doors->info->id == 4) ? printf("SUCCESS\n") : printf("FAIL\n");

    destroy(doors);
    return 0;
}
