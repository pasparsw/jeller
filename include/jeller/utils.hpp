#pragma once

#include <string>
#include <string_view>

#include "jeller/logging_level.hpp"
#include "jeller/export_jeller_api.hpp"

namespace jeller {

class Utils
{
public:
    PUBLIC_JELLER_API static void DefaultLoggingCallback(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message);
    static std::string LoggingLevelToString(const LoggingLevel level);

private:
    static std::string GetDefaultLogLine(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message);
};

} // jeller