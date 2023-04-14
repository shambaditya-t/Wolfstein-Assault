#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node_t* create_queue(struct task_t* task, int size) {
    // return null so it compiles

    struct node_t* head = create_new_node(task);

    for(int i = 1; i < size; i++)
    {
        push(&head, &task[i]);
    }
    return head;
}

struct node_t* create_new_node(struct task_t* task) {
    
    struct node_t* new_node = (struct node_t*) malloc(sizeof(struct node_t));

    new_node->task = task;
    new_node->next = NULL;
    return new_node;
}
struct task_t* peek(struct node_t** head) {
    return (*head)->task;
}

void pop(struct node_t** head) {
    struct node_t* temp = *head;
    *head = temp->next;
    free(temp);
    return;
}

void push(struct node_t** head, struct task_t* task) {
    struct node_t* prev = *head;
    struct node_t* temp = create_new_node(task);

    while(prev->next != NULL)
    {
        prev = prev->next;
    }
    prev->next = temp;
    return;
}

int is_empty(struct node_t** head) {
    if(*head == NULL){
        return 1;
    }
    else return NULL;
}

void empty_queue(struct node_t** head) {
    while (!is_empty(head))
    {
        pop(head);
    }
}
