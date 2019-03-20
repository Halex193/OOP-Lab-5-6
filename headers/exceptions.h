#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <exception>

class IndexInvalidException : std::exception
{
};

class TutorialDoesNotExistException : std::exception
{
};

class DuplicateTutorial : std::exception
{
};

class InvalidInput : std::exception
{
};

#endif