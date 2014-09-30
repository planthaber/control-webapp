#include <boost/test/unit_test.hpp>
#include <webapp/Dummy.hpp>

using namespace webapp;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    webapp::DummyClass dummy;
    dummy.welcome();
}
