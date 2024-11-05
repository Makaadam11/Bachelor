//
// Created by Mikołaj on 31/05/2022.
// https://onedrive.live.com/view.aspx?resid=2301EB34D0EAFE6B!4330&ithint=file%2cdocx&authkey=!ANH5g5HCbTKz88k
//

#include <iostream>

class Test {
public:
    static void hello() { std::cout << "hello" << std::endl; }
    ~Test() {
        std::cout << "destruction" << std::endl;
    }
};

std::shared_ptr<Test> test1() {
    std::cout << "test1()" << std::endl;
    auto ptr = std::make_shared<Test>();
    ptr->hello();
    return ptr;
}

void test2(std::shared_ptr<Test> ptr) {
    std::cout << "test2()" << std::endl;
    ptr->hello();
}

int main5() {

    test2(test1());
    std::cout << "after call" << std::endl;

    return 0;
}
