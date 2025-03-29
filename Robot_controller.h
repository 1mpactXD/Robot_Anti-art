#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <iostream>
#include <string>
#include <thread>

class Robot_controller {
public:
    void move_forward(int time);
    void move_backward(int time);
    void turn_right(int time);
    void turn_left(int time);
    void stop();
};

#endif // ROBOT_CONTROLLER_H