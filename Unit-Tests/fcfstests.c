#include <stdlib.h>
#include "ctest.h"
#include "fcfs.h"

// Note: the name in the first parameter slot must match all tests in that group
CTEST_DATA(firstcomefirstserved) {
    struct task_t task[3];
    int size;
};

CTEST_SETUP(firstcomefirstserved) {
    int execution[] = {1, 2, 3};
    data->size = sizeof(execution) / sizeof(execution[0]);
    init(data->task, execution, data->size);
    first_come_first_served(data->task, data->size);
}

CTEST2(firstcomefirstserved, test_process) {
    for (int i = 0; i < data->size; i++) {
        ASSERT_EQUAL(i, (int)data->task[i].process_id);
    }
}

// TODO add additional tests to help debug

CTEST2(firstcomefirstserved, test_excution_time)
{
    for (int i = 1; i < (data->size + 1); i++)
    ASSERT_EQUAL(i, (int)data->task[i - 1].execution_time);
}

CTEST_DATA(FCFS_2) {
    struct task_t task[3];
    int size; int waiting_time[3]; int execution[3]; 
};

CTEST_SETUP(FCFS_2) {

    data->waiting_time[0] = 0;
    data->waiting_time[1] = 1;
    data->waiting_time[2] = 3;
    

    data->execution[0] = 1;
    data->execution[1] = 2;
    data->execution[2] = 3; 
   
 
    data->size = sizeof(data->execution) / sizeof(data->execution[0]);
    init(data->task, data->execution, data->size);
    first_come_first_served(data->task, data->size);
}

CTEST2(FCFS_2, TP2) {
    ASSERT_EQUAL(1, (int)data->task[0].turnaround_time);
    ASSERT_EQUAL(3, (int)data->task[1].turnaround_time);
    ASSERT_EQUAL(6, (int)data->task[2].turnaround_time);
    
   
}


CTEST_DATA(firstcomefirstserved1) {
    struct task_t task[50];
    int size;
};
CTEST_SETUP(firstcomefirstserved1) {
    int execution[50];
    for(int i = 0; i < 50; i++)
    {
        execution[i] = i;
    }

    data->size = sizeof(execution) / sizeof(execution[0]);
    init(data->task, execution, data->size);

    first_come_first_served(data->task, data->size);
}

CTEST2(firstcomefirstserved1, test_process2) {
    for (int i = 0; i < data->size; i++) {
    ASSERT_EQUAL(i, (int)data->task[i].process_id);
    }
}

CTEST_DATA(platform_test) {
    struct object_t platform_test;
    struct object_t platform_not_moving;
    struct object_t platform_move_right;
    struct object_t platform_move_left;
    struct object_t platform_move_left_slow;
    struct object_t platform_move_right_slow;
    struct object_t platform_high_left_fast;
    struct object_t platform_high_right_fast;
    struct object_t platform_destroyed; 
    struct object_t platform_stop_leftwall;
    struct object_t platform_stop_rightwall;

};

CTEST_SETUP(platform_test) {
    data->platform.x_position = 40;
    data->platform.y_position = 40;
    data->platform.x_velocity = 3;
    data->platform.y_velocity = 0;
  //  data->platform.walls = 1;
    
    data->platform_not_moving = data->platform_test;
    data->platform_not_moving.x_velocity = 0;   
    platform_physics(&(data->platform_not_moving), 0 ); 
    
    data->platform_move_right = data->platform_test;
    platform_physics(&(data->platform_move_right), 0); 

    data->platform_move_left = data->platform_test;
    data->platform_move_left.x_velocity = -3;   
    platform_physics(&(data->platform_move_left), 0); 
  
    platform_physics_2(&(data->platform_test), 0 ); 
    data->platform_move_left_slow = data->platform_test;

    platform_physics_1(&(data->platform_test), 0); 
    data->platform_high_left_fast = data->platform_test;

    platform_physics_4(&(data->platform_test), 8, 0, 0, 1); 
    data->platform_move_right_slow = data->platform_test;
    
    platform_physics_4(&(data->platform_test), 8, 0, 0, 1); 
    data->platform_high_right_fast = data->platform_test;
    
    data->platform_destroyed = data->platform_test;
    data->platform_destroyed.x_velocity = 0;   
    data->platform_destroyed.y_velocity = 0;
    platform_physics_3(&(data->platform_destroyed), 0); 

    data->platform_destroyed = data->platform_test;
    data->platform_destroyed.x_velocity = 0;   
    data->platform_destroyed.y_velocity = 0;
    platform_physics(&(data->platform_destroyed), 0); 

    data->platform_stop_leftwall = data->platform_test;
    data->platform_stop_leftwall.x_velocity = 0;   
    data->platform_stop_leftwall.y_velocity = 0;
    platform_physics_5(&(data->platform_stop_leftwall), 0, 1); 

    data->platform_stop_rightwall = data->platform_test;
    data->platform_stop_rightwall.x_velocity = 0;   
    data->platform_stop_rightwall.y_velocity = 0;
    platform_physics_5(&(data->platform_stop_rightwall), 0, 1); 


}

//to test when the platform is at a standstill and not moving 
CTEST2 (platform_test, platform_not_moving) {
    ASSERT_EQUAL(40, (int) data->platform_not_moving.x_position);
    ASSERT_EQUAL(0, (int)data->platform_not_moving.x_velocity);
    ASSERT_EQUAL(40, (int)data->platform_not_moving.y_position);
    ASSERT_EQUAL(0, (int)data->platform_not_moving.y_velocity);  
}

//platform to test for moving right when no accelaration is there
CTEST2 (platform_test, platform_move_right) {
    ASSERT_EQUAL(43, (int) data->platform_move_right.x_position);
    ASSERT_EQUAL(3, (int)data->platform_move_right.x_velocity);
    ASSERT_EQUAL(40, (int)data->platform_move_right.y_position);
    ASSERT_EQUAL(0, (int)data->platform_move_right.y_velocity);  
}

//platform to test for moving left when no accelaration is there 
CTEST2 (platform_test, platform_move_left) {
    ASSERT_EQUAL(37, (int) data->platform_move_left.x_position);
    ASSERT_EQUAL(-3, (int)data->platform_move_left.x_velocity);
    ASSERT_EQUAL(40, (int)data->platform_move_left.y_position);
    ASSERT_EQUAL(0, (int)data->platform_move_left.y_velocity);  
}

//platform move left when slow accelaration is provided
CTEST2 (platform_test, platform_move_left_slow) {
    ASSERT_EQUAL(34, (int) data->platform_move_left_slow.x_position);
    ASSERT_EQUAL(-6, (int)data->platform_move_left_slow.x_velocity);
    ASSERT_EQUAL(40, (int)data->platform_move_left_slow.y_position);
    ASSERT_EQUAL(0, (int)data->platform_move_left_slow.y_velocity);  
}

//platform to move right when slow accelaration is being provided 
CTEST2 (platform_test, platform_move_right_slow) {
    ASSERT_EQUAL(46, (int) data->platform_move_right_slow.x_position);
    ASSERT_EQUAL(6, (int)data->platform_move_right_slow.x_velocity);
    ASSERT_EQUAL(40, (int)data->platform_move_right_slow.y_position);
    ASSERT_EQUAL(0, (int)data->platform_move_right_slow.y_velocity);  
}

//Platform to move left with high accelaration
CTEST2 (platform_test, platform_high_left_fast) {
    ASSERT_EQUAL(24, (int) data->platform_high_left_fast.x_position);
    ASSERT_EQUAL(10, (int)data->platform_high_left_fast.x_velocity);
    ASSERT_EQUAL(40, (int)data->platform_high_left_fast.y_position);
    ASSERT_EQUAL(0, (int)data->platform_high_left_fast.y_velocity);  
}

//Platform to move right with high accelaration 
CTEST2 (platform_test, platform_high_right_fast) {
    ASSERT_EQUAL(56, (int) data-> platform_high_right_fast.x_position);
    ASSERT_EQUAL(-10, (int)data-> platform_high_right_fast.x_velocity);
    ASSERT_EQUAL(40, (int)data-> platform_high_right_fast.y_position);
    ASSERT_EQUAL(0, (int)data-> platform_high_right_fast.y_velocity);  

}


//platform destroyed 
CTEST2 (platform_test, platform_destroyed) {
    ASSERT_EQUAL(0, (int) data-> platform_destroyed.x_position);
    ASSERT_EQUAL(0, (int)data-> platform_destroyed.x_velocity);
    ASSERT_EQUAL(0, (int)data-> platform_destroyed.y_position);
    ASSERT_EQUAL(0, (int)data-> platform_destroyed.y_velocity);  

}

//platform stopping at the left-wall/bounds
CTEST2 (platform_test, platform_stop_leftwall) {
    ASSERT_EQUAL(-10, (int) data-> platform_stop_leftwall.x_position);
    ASSERT_EQUAL(0, (int)data-> platform_stop_leftwall.x_velocity);
    ASSERT_EQUAL(40, (int)data-> platform_stop_leftwall.y_position);
    ASSERT_EQUAL(0, (int)data-> platform_stop_leftwall.y_velocity);  

}

//platform stopping at the right wall/bounds
CTEST2 (platform_test, platform_stop_rightwall) {
    ASSERT_EQUAL(10, (int) data-> platform_stop_rightwall.x_position);
    ASSERT_EQUAL(0, (int)data-> platform_stop_rightwall.x_velocity);
    ASSERT_EQUAL(40, (int)data-> platform_stop_rightwall.y_position);
    ASSERT_EQUAL(0, (int)data-> platform_stop_rightwall.y_velocity);  

}









