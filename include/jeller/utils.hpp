#pragma once

#include <string>
#include <string_view>

#include "jeller/logging_level.hpp"

namespace jeller {

class Utils
{
public:
    static std::string LoggingLevelToString(const LoggingLevel level);
    static void DefaultLoggingCallback(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message);

private:
    static std::string GetDefaultLogLine(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message);
};

} // jeller