#include "Robot_server_interaction.h"
#include <iostream>
#include <chrono>
#include <thread>

void Robot_server_interaction::run() {
    server.connect_to_broker();
    
    while (true) {
        auto commands = server.get_commands();
        for (const auto& command : commands) {
            std::cout << "Processing command: " << command << std::endl;
            
            size_t space_pos = command.find(' ');
            std::string direction = command.substr(0, space_pos);
            int time = (space_pos != std::string::npos) ? std::stoi(command.substr(space_pos)) : 0;

            if (direction == "forward") {
                robot.set_command(std::make_unique<MoveForward>());
            } else if (direction == "backward") {
                robot.set_command(std::make_unique<MoveBackward>());
            } else if (direction == "right") {
                robot.set_command(std::make_unique<TurnRight>());
            } else if (direction == "left") {
                robot.set_command(std::make_unique<TurnLeft>());
            } else if (direction == "stop") {
                robot.set_command(std::make_unique<StopCommand>());
                robot.execute_command(0);
                return;
            }
            
            if (direction != "stop") {
                robot.execute_command(time);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
