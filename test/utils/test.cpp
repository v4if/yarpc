#include <boost/asio.hpp>
#include <iostream>
int main() {
    char const* host = "127.0.0.1";
    int port = 80;
    auto endpoint = boost::asio::ip::tcp::endpoint(
        boost::asio::ip::address::from_string(host), port);

    std::cout  << endpoint.address().to_string() << ":" << endpoint.port() << std::endl;
    std::cout << (endpoint.address().to_string() == std::string(host)) << std::endl;

    std::shared_ptr<int> sp;
    if (!sp) {
        std::cout << "nullptr" << std::endl;
    }
    // sp.reset(new int(1));
    std::shared_ptr<int> sp1(new int(1));
    sp = sp1;
    std::cout << sp1.use_count() << std::endl;
    std::cout << sp.use_count() << std::endl;

    std::weak_ptr<int> wp(sp);
    auto func = [&sp]() mutable{
        // auto sp_lambda = wp.lock();
        // std::cout << sp_lambda.use_count() << std::endl;
        sp.reset();
        std::cout << sp.use_count() << std::endl;
    };
    func();
    std::cout << sp1.use_count() << std::endl;
    std::cout << sp.use_count() << std::endl;
}