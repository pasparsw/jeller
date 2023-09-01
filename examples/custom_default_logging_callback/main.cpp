#include <iostream>

#include <jeller/logger.hpp>

// create logger instance for this component
static jeller::Logger logger("Main");

// custom logging callback function
void LogData(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)
{
    std::cout << " | " << logger_name << " | " << logging_level << " | " << message << " | " << std::endl;
}

int main(int argc, char** argv)
{
    try {
        // set default logging callback
        jeller::Logger::SetDefaultLoggingCallback(LogData);

        // this log will be printed out using function defined above
        logger.Info("Info log from custom logging callback");
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}