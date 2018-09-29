#ifndef __NLPO_APP_H__
#define __NLPO_APP_H__

#include <map>
#include <list>
#include <memory>
#include "nlpo/option.h"
#include "nlpo/command.h"

namespace nlpo
{
    class App 
    {
    public:
        App(int argc, char* argv[]);
        App(App& app);
        Option&  add_option(const std::string& name);
        Command& add_command(const std::string& name);
        void run();
        void operator()() { run(); }
        friend Command;
        friend Option;
    private:
        std::list<std::string> args_;
        std::map<std::string, std::shared_ptr<Option>>  options_;
        std::map<std::string, std::shared_ptr<Command>> commands_;
    };
    

}

#endif
