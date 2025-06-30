#include "logger.h"
#include <fstream>
#include <string>

namespace banking
{
namespace core
{

Logger::Logger(std::string logpath) : logpath_(std::move(logpath)), finilized_(false)
{
}

Logger::Logger(Logger &&other) noexcept
{
    logpath_ = other.logpath_;
    ss_.clear();
    if (!other.finilized_)
    {
        ss_ << other.ss_.str();
    }
    finilized_ = other.finilized_;

    other.finilized_ = true;
    other.ss_.clear();
    other.logpath_ = "";
}

Logger &Logger::operator=(Logger &&other)
{
    logpath_ = other.logpath_;
    ss_.clear();
    if (!other.finilized_)
    {
        ss_ << other.ss_.str();
    }
    finilized_ = other.finilized_;

    other.finilize();

    return *this;
}

void Logger::operator<<(const std::string &str)
{
    write(str);
}

void Logger::flush()
{
    if (finilized_ || logpath_.empty())
    {
        return;
    }
    std::ofstream logfile(logpath_);

    if (logfile.is_open())
    {
        logfile << ss_.str() << std::endl;
        logfile.close();
    }
    finilize();
}

void Logger::write(const std::string &log)
{
    if (!finilized_)
    {
        ss_ << log;
    }
}

void Logger::finilize()
{
    finilized_ = true;
    ss_.clear();
    logpath_ = "";
}
} // namespace core
} // namespace banking
