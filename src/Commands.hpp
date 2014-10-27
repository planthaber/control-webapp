/*
 * Commands.h
 *
 *  Created on: 30.09.2014
 *      Author: planthaber
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdio.h>

namespace webapp {

class Commands {
public:


	inline static const char*  motion2d(){
		return "";
	};

	inline static const char* motion3d(float forward, float lateral, float yaw){
		snprintf(charbuf,255,"value={\"forward\":%f,\"lateral\":%f,\"yaw\":%f}",forward,lateral,yaw);
		return (const char*)&charbuf;
	};


	inline static const char* move(float duration, float forward, float lateral, float yaw){
		snprintf(charbuf,255,"value={\"d\":%f,\"v\":%f,\"l\":%f,\"y\":%f}",duration,forward,lateral,yaw);
		return (const char*)&charbuf;
	};

	inline static const char* moveTo(float x, float y){
		snprintf(charbuf,255,"value={\"x\":%f,\"y\":%f}",x,y);
		return (const char*)&charbuf;
	};


	inline static const char* moveArm(float pos[3], float orientation[4]){
		snprintf(charbuf,255,"value={\"position\": {\"data\": [%f,%f,%f]}, \"orientation\": {\"im\": [%f,%f,%f], \"re\": %f}}",pos[0],pos[1],pos[2],orientation[0],orientation[1],orientation[2],orientation[3]);
		return (const char*)&charbuf;
	};

	inline static const char* killJob(int id){
		snprintf(charbuf,255,"value={\"id\": %d}",id);
		return (const char*)&charbuf;
	};


private:
	static char charbuf[1024];


};

} /* namespace webapp */

#endif /* COMMANDS_H_ */
