#include "connect.h"

int main() {
    std::cout << "Choose mode: (1) Server (2) Client: ";
    int mode;
    std::cin >> mode;

    if (mode == 1) {
        server();
    }
    else if (mode == 2) {
        client();
    }
    else {
        std::cerr << "Invalid mode selected.\n";
    }

    return 0;
}