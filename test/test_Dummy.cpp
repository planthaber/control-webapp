#include <boost/test/unit_test.hpp>
#include <webapp/Http.hpp>

using namespace webapp;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    webapp::Http dummy;
    dummy.get("");
}
