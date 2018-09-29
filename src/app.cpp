#include "nlpo/app.h"
#include <iostream>

namespace nlpo
{
    App::App(int argc, char* argv[]) {
        for(int i = 1; i < argc; ++i)  
            args_.emplace_back(std::string{argv[i]}); 
    }

    App::App(App& app) { args_ = std::move(app.args_); }

    Command& App::add_command(const std::string& name) {
        auto command = std::make_shared<Command>(name);
        command->regist(this);
        commands_[name] = command;
        return *command;
    }
    
    Option& App::add_option(const std::string& name) {
        auto opt = "--" + name;
        auto option = std::make_shared<Option>(opt);
        option->regist(this);
        options_[opt] = option;
        return *option;
    }
    
    void App::run() {
        while(!args_.empty()) {
            auto arg = args_.front();
            if(auto opt = options_.find(arg); !(opt == options_.end())) {
                args_.pop_front();
                opt->second->run();
            }
            else if(auto cmd = commands_.find(arg); !(cmd == commands_.end())) {
                args_.pop_front();
                cmd->second->run();
            }
            else {
                std::cerr << "can't find option and subcommand" << std::endl;
                exit(1);
            }
        }
    }

}
