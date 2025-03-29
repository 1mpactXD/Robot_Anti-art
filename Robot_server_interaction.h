#ifndef ROBOT_SERVER_INTERACTION_H
#define ROBOT_SERVER_INTERACTION_H

#include "Robot_controller.h"
#include "Server.h"

class Robot_server_interaction {
private:
    Robot_controller robot;
    Server server;

public:
    void run();
};

#endif // ROBOT_SERVER_INTERACTION_H