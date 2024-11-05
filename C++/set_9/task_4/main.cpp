//
// Created by Mikołaj on 31/05/2022.
// https://onedrive.live.com/view.aspx?resid=2301EB34D0EAFE6B!4330&ithint=file%2cdocx&authkey=!ANH5g5HCbTKz88k
//

#include <iostream>

class Test {
private:
    int num;
public:
    explicit Test(int num) : num(num) {}
    static void hello() { std::cout << "hello" << std::endl; }
};

int main4() {

    // to initialize object
    // template< class T, class... Args > unique_ptr<T> make_unique( Args&&... args );
    auto obj = std::make_unique<Test>(10);

    // to initialize table
    // template< class T > unique_ptr<T> make_unique( std::size_t size );
    auto p = std::make_unique<int[]>(5);

    return 0;
}
