
#ifndef TCP_CONNECT_H
#define TCP_CONNECT_H

#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void handle_client(std::shared_ptr<tcp::socket> socket);
void server();
void read_messages(tcp::socket& socket);
void client();

// Declaration of global variables
extern std::vector<std::shared_ptr<tcp::socket>> clients;

#endif // TCP_CONNECT_H
