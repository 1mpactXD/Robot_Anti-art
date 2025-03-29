#include "Robot_server_interaction.h"
#include <iostream>

void Robot_server_interaction::run() {
    for (const std::string& command : server.get_commands()) {
        std::cout << "Получена команда: " << command << std::endl;

        size_t space_pos = command.find(" ");
        std::string direction = command.substr(0, space_pos);
        int time = (space_pos != std::string::npos) ? std::stoi(command.substr(space_pos + 1)) : 0;

        if (direction == "forward") {
            robot.move_forward(time);
        } else if (direction == "backward") {
            robot.move_backward(time);
        } else if (direction == "right") {
            robot.turn_right(time);
        } else if (direction == "left") {
            robot.turn_left(time);
        } else if (direction == "stop") {
            robot.stop();
            break;
        }
    }
}