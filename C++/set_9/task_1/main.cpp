//
// Created by Mikołaj on 31/05/2022.
// https://onedrive.live.com/view.aspx?resid=2301EB34D0EAFE6B!4330&ithint=file%2cdocx&authkey=!ANH5g5HCbTKz88k
//

#include <iostream>
#include <memory>

class Test {
public:
    static void hello() { std::cout << "hello" << std::endl; }
    ~Test() {
        std::cout << "destruction" << std::endl;
    }
};

void testUnique() {
    auto obj = std::make_unique<Test>();
    obj->hello();
}

void testShared(const std::shared_ptr<Test> ptr) {
    ptr->hello();
}

int main1() {

    /*
     * unique_ptr: allows exactly one owner of the underlying pointer. Use as the default choice for POCO unless you
     * know for certain that you require a shared_ptr. Can be moved to a new owner, but not copied or shared.
     */

    testUnique();
    std::cout << "after testUnique()" << std::endl;

    /*
     * shared_ptr: reference-counted smart pointer. Use when you want to assign one raw pointer to multiple owners, for
     * example, when you return a copy of a pointer from a container but want to keep the original. The raw pointer is
     * not deleted until all shared_ptr owners have gone out of scope or have otherwise given up ownership.
     */

    auto shared = std::make_shared<Test>();
    testShared(shared);
    std::cout << "after testShared()" << std::endl;

    return 0;
}
