#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <boost/asio.hpp>
#include "connect.h"

using boost::asio::ip::tcp;

// To keep track of the clients
std::vector<std::shared_ptr<tcp::socket>> clients;

// To handle communication with a client
void handle_client(std::shared_ptr<tcp::socket> socket) {
    try {
        for (;;) {
            char data[512];
            boost::system::error_code error;
            size_t length = socket->read_some(boost::asio::buffer(data), error);

            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer
            else if (error)
                throw boost::system::system_error(error); // Other error

            // Broadcast message to other clients
            for (auto& client : clients) {
                if (client != socket) {
                    boost::asio::write(*client, boost::asio::buffer(data, length));
                }
            }
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void server() {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        for (;;) {
            auto socket = std::make_shared<tcp::socket>(io_context);
            acceptor.accept(*socket);
            clients.push_back(socket);

            std::thread(handle_client, socket).detach();
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

// To read messages from the server
void read_messages(tcp::socket& socket) {
    try {
        for (;;) {
            char reply[512];
            boost::system::error_code error;
            size_t reply_length = socket.read_some(boost::asio::buffer(reply), error);

            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer
            else if (error)
                throw boost::system::system_error(error); // Other error

            std::cout.write(reply, reply_length);
            std::cout << "\n";
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void client() {
    try {
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "12345");

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        std::thread(read_messages, std::ref(socket)).detach();

        for (;;) {
            std::string msg;
            std::getline(std::cin, msg);
            boost::asio::write(socket, boost::asio::buffer(msg));
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
