#include "nlpo/app.h"
#include <iostream>



int main(int argv, char* argc[])
{

    nlpo::App app(argv, argc);
    app.add_option("help")
        .abbr("h")
        .call_back([](){ std::cout << "hello" << std::endl; }); 
    


    app.add_command("make")
        .call_back([&app]()
        { nlpo::App(app).add_option("help")
                        .call_back([](){ std::cout << "no" << std::endl;})});
   
                          
    app.run();


    return 0;
}
