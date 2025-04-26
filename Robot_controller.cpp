#include "Robot_controller.h"


void MoveForward::execute(int time) {
    std::cout << "Двигаюсь вперед на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}


void MoveBackward::execute(int time) {
    std::cout << "Двигаюсь назад на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}


void TurnRight::execute(int time) {
    std::cout << "Поворачиваю вправо на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}


void TurnLeft::execute(int time) {
    std::cout << "Поворачиваю влево на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}


void StopCommand::execute(int time) {
    (void)time;
    std::cout << "Робот остановлен." << std::endl;
}


void Robot_controller::set_command(std::unique_ptr<MoveCommand> command) {
    current_command = std::move(command);
}

void Robot_controller::execute_command(int time) {
    if (current_command) {
        current_command->execute(time);
    }
}
