#include <iostream>
#include "nlpo/app.h"

int main(int argc, char* argv[]) 
{
    nlpo::App root;
    nlpo::App test_cmd;
    test_cmd.name("test");
    test_cmd.add_option("test")
            .abbr("t")
            .call_back([](nlpo::arg::One arg){std::cout << arg << std::endl;});
    test_cmd.add_command("test")
            .call_back([](nlpo::arg::One arg){std::cout << arg << std::endl;});
    test_cmd.add_command("mtest")
        .call_back([](nlpo::arg::Multi args){std::cout << args.front() << std::endl;});
    test_cmd.add_command("make")
            .call_back([&](){
                auto arg = test_cmd.get_arg();
                std::cout << arg << std::endl;
                });
    root.add_command("test", test_cmd);
    root.parse(argc, argv);

    return 0;
}
