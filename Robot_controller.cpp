#include "Robot_controller.h"

void Robot_controller::move_forward(int time) {
    std::cout << "Двигаюсь вперед на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}

void Robot_controller::move_backward(int time) {
    std::cout << "Двигаюсь назад на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}

void Robot_controller::turn_right(int time) {
    std::cout << "Поворачиваю вправо на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}

void Robot_controller::turn_left(int time) {
    std::cout << "Поворачиваю влево на " << time << " мин" << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(time));
}

void Robot_controller::stop() {
    std::cout << "Робот остановлен." << std::endl;
}