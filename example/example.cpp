#include <iostream>
#include "nlpo/app.h"

int main(int argc, char* argv[]) 
{
    nlpo::App root;
    root.add_option("help")
        .abbr("h")
        .call_back([](){std::cout << "hello" << std::endl;});
    
    nlpo::App test_cmd;
    test_cmd.add_option("help")
            .abbr("h")
            .call_back([](){std::cout << "test cmd" << std::endl;});
    test_cmd.add_command("make")
            .call_back([&](){
                auto args = test_cmd.args();
                auto arg = args.front(); args.pop_front();
                std::cout << arg << std::endl;
                });

    root.add_command("test")
        .call_back([&](){ test_cmd.parse(root);});

    return 0;
}
