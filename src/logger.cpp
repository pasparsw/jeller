#include <iostream>

#include "jeller/logger.hpp"

namespace jeller {

Logger::Logger(const std::string_view name) noexcept
: name_{name}
{}

void Logger::SetLevel(const LoggingLevel level) noexcept
{
    level_ = level;
}

void Logger::SetDefaultLoggingCallback(JellerLoggingCallback callback)
{
    if (!callback) {
        throw std::invalid_argument("Failed to set default logging callback - given callback is a nullptr or is empty!");
    }

    if (logging_callbacks_.empty()) {
        logging_callbacks_.push_back(callback);
    }
    else {
        logging_callbacks_.at(0U) = callback;
    }
}

void Logger::AppendLoggingCallback(JellerLoggingCallback callback)
{
    if (!callback) {
        throw std::invalid_argument("Failed to append logging callback - given callback is a nullptr or is empty!");
    }

    logging_callbacks_.push_back(callback);
}

void Logger::Fatal(const std::string_view message) const noexcept
{
    Log(message, LoggingLevel::kFatal);
}

void Logger::Error(const std::string_view message) const noexcept
{
    Log(message, LoggingLevel::kError);
}

void Logger::Warning(const std::string_view message) const noexcept
{
    Log(message, LoggingLevel::kWarning);
}

void Logger::Info(const std::string_view message) const noexcept
{
    Log(message, LoggingLevel::kInfo);
}

void Logger::Debug(const std::string_view message) const noexcept
{
    Log(message, LoggingLevel::kDebug);
}

void Logger::Verbose(const std::string_view message) const noexcept
{
    Log(message, LoggingLevel::kVerbose);
}

void Logger::Log(const std::string_view message, const LoggingLevel logging_level) const
{
    try {
        if (level_ <= logging_level) {
            std::lock_guard<std::mutex> lock(mutex_);

            for (const auto log_message_cb : logging_callbacks_) {
                try {
                    log_message_cb(name_, Utils::LoggingLevelToString(logging_level), message);
                }
                catch (const std::exception &e) {
                    std::cerr << "[Jeller] Error during calling logging callback: " << e.what() << std::endl; 
                }
                catch (...) {
                    std::cerr << "[Jeller] Unknown error occurred during calling logging callback!" << std::endl;
                }
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "[Jeller] Error during logging data: " << e.what() << std::endl; 
    }
    catch (...) {
        std::cerr << "[Jeller] Unknown error occurred during logging data!" << std::endl;
    }
}

} // jeller