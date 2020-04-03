#include <iostream>
#include <string>
#include "hello.hpp"
#include "gtest/gtest.h"

int main( int argc, char * argv[] )
{
    std::cout << "Language ? ";
    std::string lang;
    std::cin >> lang;
    HelloWorld hw;
    std::cout << hw.hello_world( lang == "fr" ) << std::endl;
    // Keep command window open on Windows
    char c; std::cin >> c;
//    return 0;
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
