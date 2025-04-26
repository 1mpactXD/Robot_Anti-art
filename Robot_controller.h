#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <iostream>
#include <string>
#include <thread>
#include <memory>


class MoveCommand {
public:
    virtual ~MoveCommand() = default;
    virtual void execute(int time) = 0;
};


class MoveForward : public MoveCommand {
public:
    void execute(int time) override;
};

class MoveBackward : public MoveCommand {
public:
    void execute(int time) override;
};

class TurnRight : public MoveCommand {
public:
    void execute(int time) override;
};

class TurnLeft : public MoveCommand {
public:
    void execute(int time) override;
};

class StopCommand : public MoveCommand {
public:
    void execute(int time) override;
};


class Robot_controller {
private:
    std::unique_ptr<MoveCommand> current_command;
    
public:
    void set_command(std::unique_ptr<MoveCommand> command);
    void execute_command(int time);
};

#endif