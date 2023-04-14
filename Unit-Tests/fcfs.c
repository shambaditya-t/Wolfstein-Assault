#include "fcfs.h"
#include "queue.h"
#include <stdio.h>

void init(struct task_t *task, int *execution, int size) {

    for (int i = 0; i<size; i++){
        task[i].process_id = i;
        task[i].execution_time = execution[i];
        task[i].turnaround_time = 0;
        task[i].waiting_time = 0;
    }

}

void first_come_first_served(struct task_t *task, int size) {
    // Hints:
    // 1. Create Queue based on the task array
    // 2. Pop off the front item until there are no more tasks
    
    struct task_t * curr_node;
    
    int time = 0;
    int exec_time ;

    struct node_t *fcfs = create_queue(task, size); //new queue 

    while (!is_empty(&fcfs))
    {
        
        curr_node = peek(&fcfs);
        curr_node->waiting_time = time;
        exec_time = curr_node->execution_time;
        curr_node->turnaround_time = time + exec_time;

        time = time + exec_time;
        pop(&fcfs);
    }
}

float calculate_average_wait_time(struct task_t *task, int size) {
    // return 0.0 so it compiles
    
   
    float x = 0;

    for (int i = 0; i < size; i++){
      x += task[i].waiting_time;

    }

    return 0.0;
}

float calculate_average_turn_around_time(struct task_t *task, int size) {
    // return 0.0 so it compiles

   
    float x = 0;

    for (int i = 0; i < size; i++){
    x += task[i].turnaround_time;
    }

    return 0.0;
}

void platform_physics(struct object_t *object, int y_val) {

      object->x_position += object->x_velocity; 

}

void platform_physics_1(struct object_t *object, int y_val) {

    object->x_velocity = object->x_velocity + 3 ; 

}

void platform_physics_2(struct object_t *object, int y_val) {

    object->x_velocity = object->x_velocity + 1 ; 
    object->x_position += object->x_velocity;

}

void platform_physics_3(struct object_t *object, int y_val) {

    object->x_velocity = object->x_velocity - 1 ; 
    object->x_position += object->x_velocity;

}

void platform_physics_4(struct object_t *object, int y_val) {

    object->x_velocity = object->x_velocity - 3 ; 
    object->x_position += object->x_velocity;

}

void platform_physics_5(struct object_t *object, int y_val,int walls) {

    if(walls == 1){  // detected left or right walls 
            // It will come to a halt at position 
    } 

}



