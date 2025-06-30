#pragma once

#include <sstream>
#include <string>

namespace banking
{
namespace core
{

class Logger
{
    std::string logpath_;
    std::stringstream ss_;
    bool finilized_;

    void finilize();

  public:
    explicit Logger(std::string);
    Logger(Logger &&) noexcept;
    ~Logger() = default;
    void operator<<(const std::string &);
    Logger &operator=(Logger &&other);
    void write(const std::string &);
    void flush();
};
} // namespace core
} // namespace banking
