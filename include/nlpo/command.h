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
        ptr get_ptr() { return shared_from_this(); }
        Command(std::string name) : name_(name) {}
        void regist(App* app) { owner_ = app;}
        Command& desc(const std::string& description);
        Command& args(const std::string& description);
        Command& call_back(std::function<void()>&& func);
        std::string make_description();
        void is_show(bool show) { is_show_ = show; }
        void run();
    private:
        bool is_show_ = false;
        std::string name_;
        std::string desc_;
        std::string args_;
        App* owner_;
        std::vector<std::function<void()>> call_backs_;
    };
}

#endif
