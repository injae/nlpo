#include "nlpo/program.h"
#include "nlpo/option_group.h"

#include <nieel/algorithm.hpp>
#include <iomanip>

class TT
{
public:
    TT(nlpo::Args&& args) : prg_(std::move(args)) {
        prg_["Options:"]["--tt"]
            .abbreviation("-t")
            .description("test option")
            .call_back([](){ std::cout << "test" << std::endl; });
        prg_["Options:"]["--help"]
            .abbreviation("-h")
            .description("help")
            .call_back([&](){ prg_.help(); });
        prg_["Command:"]["tt"]
            .description("test option")
            .call_back([&](){ prg_.args().clear(); });
        prg_["Command:"][" "]
            .description("default option")
            .call_back([](){std::cout << "default option" << std::endl;});
    }
    void operator() () { prg_.run(); }
private:
   nlpo::Program prg_; 
};

class Test
{
public:
    Test(nlpo::Args&& args) : prg_(std::move(args)) {
        prg_["Options:"]["--test"]
            .abbreviation("-t")
            .description("test option")
            .call_back([](){ std::cout << "test" << std::endl; });
        prg_["Options:"]["--help"]
            .abbreviation("-h")
            .description("help")
            .call_back([&](){ prg_.help(); });
        prg_["Command:"]["xx"]
            .description("test option")
            .call_back([&](){ TT(std::move(prg_.args()))(); });
        prg_["Command:"][" "]
            .description("default option")
            .call_back([](){std::cout << "default option" << std::endl;});
    }
    void operator() () { prg_.run(); }
private:
   nlpo::Program prg_; 
};


int main(int argc, char* argv[]) 
{
    Test program(nlpo::Args(argc, argv));
    program();
    
    return 0;
}