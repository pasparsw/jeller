#include <iostream>
#include <fstream>

#include <jeller/logger.hpp>

// create logger instance for this component
static jeller::Logger logger("Main");

// additional logging callback function which will log all errors and fatal errors to file "logs.txt"
void LogToFile(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)
{
    if (logging_level == jeller::kErrorStr || logging_level == jeller::kFatalStr) {
        std::ofstream log_file;
        
        log_file.open("logs.txt", std::ios::app);
        log_file << logger_name << " | " << logging_level << " | " << message << std::endl;

        log_file.close();
    }
}

int main(int argc, char** argv)
{
    try {
        // set logging level
        jeller::Logger::SetLevel(jeller::LoggingLevel::kVerbose);
        // append additional logging callback
        jeller::Logger::AppendLoggingCallback(LogToFile);

        // these messages will be logged only to the console using the default logging callback
        logger.Verbose("Some verbose message");
        logger.Debug("Some debug message");
        logger.Info("Some info message");
        // these messages will be logged both to the console (using the default logging callback)
        // and to logs.txt file (using logging callback defined above)
        logger.Error("Some error message");
        logger.Fatal("Some fatal message");
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}