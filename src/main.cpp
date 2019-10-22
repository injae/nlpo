#include "nlpo/value.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    auto t = nlpo::value::from_str("123");
    std::cout << t.get<int>() << std::endl;

    return 0;
}
