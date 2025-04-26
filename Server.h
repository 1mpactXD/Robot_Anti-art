#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <string>
#include <mosquitto.h>

class Server {
private:
    struct mosquitto* mosq;
    static std::vector<std::string> received_commands;
    static void message_callback(struct mosquitto*, void*, const struct mosquitto_message*);

public:
    Server();
    ~Server();
    std::vector<std::string> get_commands();
    void connect_to_broker();
};

#endif
