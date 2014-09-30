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



private:
	static char charbuf[256];


};

} /* namespace webapp */

#endif /* COMMANDS_H_ */
