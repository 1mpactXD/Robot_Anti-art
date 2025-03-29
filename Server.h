#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>

class Server {
public:
    std::vector<std::string> get_commands();
};

#endif // SERVER_H