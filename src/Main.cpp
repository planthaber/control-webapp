#include <iostream>
#include "Http.hpp"
#include "Commands.hpp"

int main(int argc, char** argv)
{
	rest_api_cppclient::Http http;

	//std::cout << http.get("sim01-u:9292/api/tasks/tasks") << std::endl;

	//const char* url = "http://localhost:9292/api/tasks/tasks/localhost/motion_planner/ports/goal_pose_samples/write";
	const char* url = "http://localhost:9292/api/tasks/tasks/localhost/simple_controller/ports/motion_command/write";
	//std::cout << http.post(url,webapp::Commands::motion3d(0,0,1)) << std::endl;

	//url = "http://sim01-u:9292/api/syskit/actions/move!/start";
	//std::cout << http.post(url,webapp::Commands::move(5,0,0,1)) << std::endl;


//	float pos[3] = {0,0.5,0.2};
//	float orientation[4] = {1,0,0,0};
//	url = "http://192.168.151.171:9292/api/tasks/tasks/localhost/arm_motion_planner/ports/target_pose/write";
//	std::cout << http.post(url,webapp::Commands::rbsPos(pos,orientation)) << std::endl;
//
//
//	url = "http://192.168.151.171:9292/api/syskit/actions/move_to_def!/start";
//	std::cout << http.post(url,webapp::Commands::moveTo(1,1)) << std::endl;
//
//	std::cout << http.post(url,webapp::Commands::moveTo(1,1)) << std::endl;


//	float pos[3] = {1,0,0};
//	float orientation[4] = {1,0,0,0};
//	std::cout << http.post(url,rest_api_cppclient::Commands::rbsPos(pos,orientation)) << std::endl;

	float translation = 1;
	float rotation = 1;
	std::cout << http.post(url,rest_api_cppclient::Commands::motion2d(translation,rotation)) << std::endl;

	return 0;
}
