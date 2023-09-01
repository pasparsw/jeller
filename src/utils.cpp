#include <iostream>
#include <sstream>

#include "jeller/utils.hpp"

namespace jeller {

std::string Utils::LoggingLevelToString(const LoggingLevel level)
{
    switch (level) {
        case LoggingLevel::kFatal:
            return kFatalStr;
        case LoggingLevel::kError:
            return kErrorStr;
        case LoggingLevel::kWarning:
            return kWarningStr;
        case LoggingLevel::kInfo:
            return kInfoStr;
        case LoggingLevel::kDebug:
            return kDebugStr;
        case LoggingLevel::kVerbose:
            return kVerboseStr;
        default:
            return "INVALID";
    }
}

void Utils::DefaultLoggingCallback(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)
{
    if (logging_level == kErrorStr || logging_level == kFatalStr) {
        std::cerr << GetDefaultLogLine(logger_name, logging_level, message);
    }
    else {
        std::cout << GetDefaultLogLine(logger_name, logging_level, message);
    }
}

std::string Utils::GetDefaultLogLine(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)
{
    std::stringstream ss;

    ss << "[" << logging_level << "][" << logger_name << "] " << message << std::endl;

    return ss.str();
}

} // jeller