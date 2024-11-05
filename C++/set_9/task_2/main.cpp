//
// Created by Mikołaj on 31/05/2022.
// https://onedrive.live.com/view.aspx?resid=2301EB34D0EAFE6B!4330&ithint=file%2cdocx&authkey=!ANH5g5HCbTKz88k
//

#include <iostream>

class Test {
public:
    static void hello() { std::cout << "hello" << std::endl; }
};

int main2() {

    auto unique_smart = std::make_unique<Test>();
    auto shared_smart = std::make_shared<Test>();
    auto standard = new Test();

    std::cout << "size of unique smart: " << sizeof(unique_smart) << std::endl;
    std::cout << "size of shared smart: " << sizeof(shared_smart) << std::endl;
    std::cout << "size of standard: " << sizeof(standard) << std::endl;

    return 0;
}
