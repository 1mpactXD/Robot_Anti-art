#include "Server.h"

std::vector<std::string> Server::get_commands() {
    return {"forward 2", "right 1", "backward 3", "left 1", "stop"};
}