#include <iostream>
#include <webapp/Http.hpp>
#include <webapp/Commands.hpp>

int main(int argc, char** argv)
{
	webapp::Http http;

	//std::cout << http.get("localhost:9292/api/tasks/tasks") << std::endl;

	const char* url = "http://localhost:9292/api/tasks/tasks/localhost/sherpa_tt_mcs/ports/motion_command_3d/write";

	//std::cout << http.post(url,webapp::Commands::motion3d(0,0,1)) << std::endl;

	url = "http://localhost:9292/api/syskit/actions/move!/start";
	std::cout << http.post(url,webapp::Commands::move(5,0,0,1)) << std::endl;


	return 0;
}
