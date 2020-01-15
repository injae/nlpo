#ifndef __NLPO_APP_H__
#define __NLPO_APP_H__

#include <map>
#include <list>
#include <vector>
#include <memory>
#include <optional>
#include <string>
#include "nlpo/option.h"
#include "nlpo/command.h"

namespace nlpo
{
    //template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
    //template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;
    //using result = std::variant<std::string, std::vector<std::string>>;
    class AppWrapper;

    class App 
    {
    public:
        App();
        Option&  add_option(const std::string& name);
        Command& add_command(const std::string& name);
        Command& add_command(const std::string& name, App& app);
        Command& add_command(const std::string& name, AppWrapper& app);
        Command& add_command();
        void call_default() { default_command_->run(); }
        std::list<std::string>& args() { return args_; }
        std::string get_arg() { auto arg = args_.front(); args_.pop_front(); return arg; }
        void parse(int argc, char* argv[]);
        void parse(App& app);
        void show_help();
        friend Command;
        friend Option;
    private:
        void run();
    private:
        std::list<std::string> args_;
        std::map<std::string, std::shared_ptr<Option>>  options_;
        std::map<std::string, std::shared_ptr<Command>> commands_;
        std::optional<Command> default_command_;
    };
    

    class AppWrapper {
    public:
        App& app() { return app_; }
        virtual ~AppWrapper() {}
        App app_;
    };
}

#endif
