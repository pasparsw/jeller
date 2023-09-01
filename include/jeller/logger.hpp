#pragma once

#include <mutex>
#include <vector>
#include <functional>
#include <string_view>

#include "logging_level.hpp"
#include "utils.hpp"
#include "export_jeller_api.hpp"

namespace jeller {

using JellerLoggingCallback = std::function<void(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)>;

class Logger
{
public:
    /**
     * @brief Constructor.
     * @param name Name of the component in which particular logger instance is used.
     */
    PUBLIC_JELLER_API Logger(const std::string_view name) noexcept;
    /**
     * @brief Allows to set global logging level across all the logger instances used.
     * @param level Logging level to be set.
     */
    PUBLIC_JELLER_API static void SetLevel(const LoggingLevel level) noexcept;
    /**
     * @brief Allows to set a custom default logging callback.
     * @param callback Function pointer to the custom logging callback.
     */
    PUBLIC_JELLER_API static void SetDefaultLoggingCallback(JellerLoggingCallback callback);
    /**
     * @brief Allows to append a custom logging callback. All appended callbacks are called when a message is logged.
     * @param callback Function poitner to the custom logging callback.
     */
    PUBLIC_JELLER_API static void AppendLoggingCallback(JellerLoggingCallback callback);
    /**
     * @brief Log a fatal error message. Use this function for logging in case of unrecoverable component error.
     * @param message Message content.
     */
    PUBLIC_JELLER_API void Fatal(const std::string_view message) const noexcept;
    /**
     * @brief Log an error message. Use this function for logging in case of recoverable component error.
     * @param message Message content.
     */
    PUBLIC_JELLER_API void Error(const std::string_view message) const noexcept;
    /**
     * @brief Log a warning message. Use this function for logging in case of potentially problematic situation which
     *        however does not necessarly lead to a higher level error.
     * @param message Message content.
     */
    PUBLIC_JELLER_API void Warning(const std::string_view message) const noexcept;
    /**
     * @brief Log an information message. Use this function for logging information valueable for the user during normal usage.
     * @param message Message content.
     */
    PUBLIC_JELLER_API void Info(const std::string_view message) const noexcept;
    /**
     * @brief Log a debug message. Use this function for logging information helpful for the user during debugging.
     * @param message Message content.
     */
    PUBLIC_JELLER_API void Debug(const std::string_view message) const noexcept;
    /**
     * @brief Log a verbose message. Use this function for logging information helpful for the software developer during software development.
     * @param message Message content.
     */
    PUBLIC_JELLER_API void Verbose(const std::string_view message) const noexcept;

private:
    void Log(const std::string_view message, const LoggingLevel logging_level) const;

    std::string_view name_;

    static inline LoggingLevel level_ = LoggingLevel::kInfo;
    static inline std::vector<JellerLoggingCallback> logging_callbacks_ = {Utils::DefaultLoggingCallback};
    static inline std::mutex mutex_;
};

} // jeller