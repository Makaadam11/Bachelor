//
// Created by Mikołaj on 31/05/2022.
// https://onedrive.live.com/view.aspx?resid=2301EB34D0EAFE6B!4330&ithint=file%2cdocx&authkey=!ANH5g5HCbTKz88k
//

#include <iostream>
#include <memory>

class PointerContainer{
private:
    std::weak_ptr<int> weak;
public:
    explicit PointerContainer(std::weak_ptr<int> weak) : weak(weak) {}

    void checkPtr() {
        if (weak.expired())
            std::cout << "expired" << std::endl;
        else
            std::cout << "value is " << *weak.lock() << std::endl;
    }
};

int main() {

    // empty definition
    auto sptr = std::make_shared<int>(1);

    // get pointer to data without taking ownership
    std::weak_ptr<int> weak1 = sptr;

    auto pc = new PointerContainer(weak1);
    pc->checkPtr();

    // deletes managed object, acquires new pointer
    sptr = std::make_shared<int>(2);
    pc->checkPtr();
}
