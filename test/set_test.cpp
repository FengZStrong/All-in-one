#include <iostream>
#include <set>
#include <memory>

class test {
public:
    test():mem(0) {}
private:
    int mem;
};

int main() {
    std::shared_ptr<test> sp1 = std::make_shared<test>();
    std::shared_ptr<test> sp2 = sp1;
    std::set<std::shared_ptr<test>> s{sp1, sp2};

    test* p1 = new test();
    test* p2 = p1;
    std::set<test*> s1{p1, p2};

    std::cout << s.size() << std::endl;
    std::cout << s1.size() << std::endl;

    delete p1;
}
