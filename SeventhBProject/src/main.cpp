#include <iostream>
#include <memory>
#include "../include/Test.h"

std::weak_ptr<Test> wp;

int main() {
    {
        auto sp = std::make_shared<Test>();
        std::cout << sp.use_count() << std::endl;
        wp = sp;
        std::cout << sp.use_count() << std::endl;

        auto p = wp.lock();
        if (p) std::cout << "Object is alive " << p.use_count() << std::endl;
        else std::cout << "No owned object" << std::endl;
    }

    auto p = wp.lock();
    if (p) std::cout << "Object is alive " << p.use_count() << std::endl;
    else std::cout << "No owned object" << std::endl;

    return 0;
}
