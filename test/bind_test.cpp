#include <functional>
#include <iostream>

class widget{
public:
    void self_print() {
        std::cout << "widget" << std::endl;
    }
};

int main(int argc, char *argv[]) {
    //auto a = std::make_shared<widget>();
    widget w;
    auto func = std::bind(&widget::self_print, std::placeholders::_1);
    func(&w);
}
