#ifndef __NLPO_COMMAND_H__
#define __NLPO_COMMAND_H__

#include <string>
#include <memory>
#include <functional>

namespace nlpo
{
    class App;
    class Command : public std::enable_shared_from_this<Command>
    {
    public:
        using ptr = std::shared_ptr<Command>;
        Command(std::string name) : name_(name) {}
        void regist(App* app) { owner_ = app;}
        ptr get_ptr() { return shared_from_this(); }
        Command& desc(const char* description);
        Command& call_back(std::function<void()>&& func);
        void run();
    private:
        std::string name_;
        std::string desc_;
        App* owner_;
        std::vector<std::function<void()>> call_backs_;
    };
}

#endif
