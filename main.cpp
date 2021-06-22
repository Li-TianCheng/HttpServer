#include <iostream>
#include <fstream>
#include <string>
#include "http/include/HttpServer.h"
#include "modules/Modules.h"

#include "net/include/Ping.h"
#include "log/include/Log.h"
#include <unordered_map>
using namespace std;

Mutex mutex;
static std::unordered_map<string, string> resourceManager;

void handleHello(const shared_ptr<Http>& request, const shared_ptr<Http>& response) {
    std::ifstream file("../resources/bXKvL1.jpg");
    std::stringstream buffer;
    buffer << file.rdbuf();
    response->data = buffer.str();
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
