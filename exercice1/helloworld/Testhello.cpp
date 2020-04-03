#include "hello.hpp"

#include "gtest/gtest.h"

TEST( TestHelloWorld, TestEnglishHelloWorld )
{
    HelloWorld hw;
    EXPECT_EQ( "Hello world!", hw.hello_world( false ) );
}
 
TEST( TestHelloWorld, TestFrenchHelloWorld )
{
    HelloWorld hw;
    EXPECT_EQ( "Bonjour le monde !", hw.hello_world( true ) );
}

