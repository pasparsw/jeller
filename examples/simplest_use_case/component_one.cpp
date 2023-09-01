#include <jeller/logger.hpp>

#include "component_one.hpp"

// create logger instance for this component
static jeller::Logger logger("ComponentOne");

void ComponentOne::DoSomething()
{
    logger.Fatal("Example fatal error log");
    logger.Error("Example error log");
    logger.Warning("Example warning log");
    logger.Info("Example info log");
    logger.Debug("Example debug log");
    logger.Verbose("Example verbose log");
}