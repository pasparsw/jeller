#include <iostream>

#include "component_one.hpp"
#include "component_two.hpp"

int main(int argc, char** argv)
{
    try {
        ComponentOne component_one;
        ComponentTwo component_two;

        component_one.DoSomething();
        component_two.DoSomething();
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}