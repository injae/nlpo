#include "nlpo/app.h"
#include <iostream>
#include <algorithm>
#include <fmt/format.h>

namespace nlpo
{
    App::App() {
        add_option("help")
        .abbr("h")
        .desc("show cppm commands and options")
        .call_back([&](){ show_help(); });
    }

    void App::parse(int argc, char* argv[]) {
        for(int i = 1; i < argc; ++i)  
            args_.emplace_back(std::string{argv[i]}); 
        run();
    }

    void App::parse(App& app) {
        args_ = std::move(app.args_);
        run();
    }

    Command& App::add_command(const std::string& name) {
        auto command = std::make_shared<Command>(name);
        command->regist(this);
        commands_[name] = command;
        return *command;
    }

    Command& App::add_command(const std::string& name, App& app) {
        return add_command(name).call_back([&](){ app.parse(*this); });
    }

    Command& App::add_command() {
        default_command_ = std::make_optional<Command>("default");         
        return *default_command_;
    }
    
    Option& App::add_option(const std::string& name) {
        auto opt = "--" + name;
        auto option = std::make_shared<Option>(name);
        option->regist(this);
        options_[opt] = option;
        return *option;
    }

    void App::show_help() {
        if(!options_.empty()) {
            std::cout << "Option:" << std::endl;
            std::for_each(options_.begin(), options_.end(), [](auto& opt){
                std::cout << opt.second->make_description();
            });
        }
        if(!commands_.empty()) {
            std::cout << "Command:" << std::endl;
            std::for_each(commands_.begin(), commands_.end(), [](auto& cmd){
                std::cout << cmd.second->make_description();
            });
        }
        exit(1);
    }
    
    void App::run() {
        while(!args_.empty()){
            auto arg = args_.front();
            if(auto opt = options_.find(arg); !(opt == options_.end())) {
                args_.pop_front();
                opt->second->run();
            }
            else if(auto cmd = commands_.find(arg); !(cmd == commands_.end())) {
                args_.pop_front();
                cmd->second->run();
            }
            else if(default_command_) {
                default_command_->run();
                return ;
            }
            else {
                std::cerr << "can't find option and subcommand" << std::endl;
                exit(1);
            }
        }
        if(args_.empty() && default_command_) { default_command_->run(); return; }
    }
}

