#include "list.h"

#include <stdio.h>

#define MAX_ID_SEED 10000

int main() {
    struct door doors[0];

    initialize_doors(doors, 15);
    bubble_sort(doors, 15);
    destroy(root);

    struct node* root = init(&doors[0]);
    struct node* current_ptr = root;

    return 0;
}

void bubble_sort(struct door* doors, int doorsCount) {
    for (int i = doorsCount; i > 1; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (doors[j + 1].id < doors[j].id) {
                int tmp_id = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = tmp_id;
            }
        }
    }
}

void output(struct door* doors) {}

struct node* init(struct door* door) {
    struct node* element = (struct node*)malloc(sizeof(struct node));
    element->doors.id = door->id;
    element->doors.status = door->status;
    element->next = NULL;

    return element;
}

struct node* add_door(struct node* element, struct door* door) {
    if (element != NULL) {
        struct node* addition = init(door);
        struct node* ptr = element->next;
        element->next = addition;
        addition->next = ptr;
        ptr = NULL;
    }
    return element;
}

struct node* find_door(int door_id, struct node* root) {}

struct node* remove_door(struct node* element, struct node* root) {

}

void destroy(struct node* root) {
    struct node* ptr = root;
    struct node* del = NULL;
    while (ptr != NULL && ptr->next != NULL) {
        del = ptr;
        ptr = ptr->next;
        free(del);
        del = NULL;
    }
    free(ptr);
}

void initialize_doors(struct door* doors, int doorsCount) {
    struct door doors[doorsCount];
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < doorsCount; i++) {
        doors[i].id = (i + seed) % doorsCount;
        doors[i].status = rand() % 2;
    }
}