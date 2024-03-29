#include "Mountains.h"
#include <thread>
#include <map>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#define BOOST_TEST_MODULE mytests

namespace bdata = boost::unit_test::data;

BOOST_AUTO_TEST_SUITE(MountainsTestSuite)

// Test constructor
BOOST_AUTO_TEST_CASE(TestConstructor)
{
    std::vector<std::string> filenames = { "Alps.txt", "Carpathians.txt" };
    Mountains mountains(filenames);
    BOOST_REQUIRE(mountains.getRandomMountain() != "");
}

// Test getRandomMountain method
BOOST_AUTO_TEST_CASE(TestGetRandomMountain)
{
    std::vector<std::string> filenames = { "Alps.txt", "Carpathians.txt" };
    Mountains mountains(filenames);
    std::string mountain1 = mountains.getRandomMountain();
    std::string mountain2 = mountains.getRandomMountain();
    BOOST_REQUIRE(mountain1 != "");
    BOOST_REQUIRE(mountain2 != "");
    BOOST_REQUIRE(mountain1 != mountain2);
}

// Test getRandomMountain method with empty filenames vector
BOOST_AUTO_TEST_CASE(TestGetRandomMountainWithEmptyFilenames)
{
    std::vector<std::string> filenames = {};
    Mountains mountains(filenames);
    std::string mountain = mountains.getRandomMountain();
    BOOST_REQUIRE(mountain == "");
}

BOOST_AUTO_TEST_CASE(TestCheckRange)
{
    std::vector<std::string> filenames = { "Alps.txt", "Carpathians.txt",};
    Mountains mountains(filenames);

    BOOST_CHECK(mountains.checkRange("Piz Bernina", "Alps"));
    BOOST_CHECK(mountains.checkRange("Gerlach", "Carpathians"));
}

BOOST_AUTO_TEST_SUITE_END()



