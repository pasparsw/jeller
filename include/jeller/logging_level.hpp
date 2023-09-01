#pragma once

namespace jeller {

enum class LoggingLevel
{
    kVerbose,
    kDebug,
    kInfo,
    kWarning,
    kError,
    kFatal
};

static const std::string kVerboseStr {"VERBOSE"};
static const std::string kDebugStr {"DEBUG"};
static const std::string kInfoStr {"INFO"};
static const std::string kWarningStr {"WARNING"};
static const std::string kErrorStr {"ERROR"};
static const std::string kFatalStr {"FATAL"};

}