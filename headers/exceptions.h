#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <exception>

class IndexInvalidException : std::exception
{
};

class TutorialDoesNotExistException : std::exception
{
};

#endif