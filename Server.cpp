#include "Server.h"
#include <iostream>
#include <cstring>

std::vector<std::string> Server::received_commands;

Server::Server() {
    mosquitto_lib_init();
    mosq = mosquitto_new("robot_client", true, nullptr);
    if (!mosq) {
        throw std::runtime_error("Failed to create Mosquitto instance");
    }
    mosquitto_message_callback_set(mosq, message_callback);
}

Server::~Server() {
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
}

void Server::message_callback(struct mosquitto*, void*, const struct mosquitto_message* msg) {
    if (msg->payloadlen > 0) {
        std::string command(static_cast<char*>(msg->payload), msg->payloadlen);
        received_commands.push_back(command);
        std::cout << "Received command: " << command << std::endl;
    }
}

void Server::connect_to_broker() {
    if (mosquitto_connect(mosq, "localhost", 1883, 60) != MOSQ_ERR_SUCCESS) {
        throw std::runtime_error("Failed to connect to broker");
    }
    mosquitto_subscribe(mosq, nullptr, "robot/commands", 0);
}

std::vector<std::string> Server::get_commands() {
    mosquitto_loop_start(mosq);
    return received_commands;
}
