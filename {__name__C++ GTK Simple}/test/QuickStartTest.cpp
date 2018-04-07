#define BOOST_TEST_MODULE QuickStartTest

//TODO relpace with class being tested header 
#include "../include/QuickStart.hpp"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

//TODO replace name
BOOST_AUTO_TEST_SUITE(QuickStartSuite)

BOOST_AUTO_TEST_CASE(AdditionTest1)
{
    QuickStart quickStart;

    BOOST_CHECK_EQUAL(quickStart.add(1, 1), 2);
}


BOOST_AUTO_TEST_CASE(AdditionTest2)
{
    QuickStart quickStart;

    BOOST_CHECK_EQUAL(quickStart.add(5, 1), 65);
}
BOOST_AUTO_TEST_SUITE_END()