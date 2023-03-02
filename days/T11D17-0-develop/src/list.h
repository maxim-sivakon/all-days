#ifndef LIST_H
#define LIST_H

typedef struct door {
    int id;
    int status;
} door;

typedef struct node {
    int value;
    struct node* next;
} node;

struct node {
    struct door doors;
    struct node* next;
};

void bubble_sort(struct door* doors, int doorsCount);
void output(struct node* root);
struct node* init(struct door* door);
struct node* add_door(struct node* element, struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* element, struct node* root);
void destroy(struct node* root);
void initialize_doors(struct door* doors, int doorsCount);

#endif
