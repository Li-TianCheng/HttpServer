#include <iostream>
#include <fstream>
#include <string>
#include "http/include/HttpServer.h"
#include "modules/Modules.h"

using namespace std;

void handleHello(shared_ptr<Http> request, shared_ptr<Http> response) {
    std::ifstream file("../resources/bXKvL1.jpg");
    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);
    response->data.resize(length);
    file.read(response->data.data(), length);
    file.close();
}

int main() {
    modules::init();
    HttpServer server(8080, IPV4);
    server.registerHandler("/hello", handleHello);
    server.serve();
    std::cout << "Hello, World!" << std::endl;
    modules::close();
    return 0;
}
