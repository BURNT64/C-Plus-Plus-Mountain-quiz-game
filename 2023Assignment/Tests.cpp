#include "Mountains.h"
#include <thread>
#include <map>

#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
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

BOOST_AUTO_TEST_CASE(TestCheckRange)
{
    std::vector<std::string> filenames = { "alps.txt", "carpathians.txt", "pyrenees.txt", "icelandic_highlands.txt" };
    Mountains mountains(filenames);

    BOOST_CHECK(mountains.checkRange("Piz Bernina", "alps"));
    BOOST_CHECK(mountains.checkRange("Gerlach", "carpathians"));
    BOOST_CHECK(mountains.checkRange("Aneto", "pyrenees"));
    BOOST_CHECK(mountains.checkRange("Kirkjufell", "icelandic highlands"));
}

BOOST_AUTO_TEST_SUITE_END()



