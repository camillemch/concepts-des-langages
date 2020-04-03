#include <iostream>
#include <string>
#include "hello.hpp"

std::string HelloWorld::hello_world( bool french )
{
    return french ? "Bonjour le monde !" : "Hello world!";
}