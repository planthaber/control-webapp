#ifndef _WEBAPP_HTTP_HPP_
#define _WEBAPP_HTTP_HPP_

#include <iostream>
#include <string>
#include <curl/curl.h>

namespace webapp
{
	class Http
	{
		public: 

			Http();

			~Http();


			std::string get(const char* url, int timeout = 0);

			std::string post(const char* url,const char* data, int timeout = 0);

			std::string postMime(const char* url, const char* data, const char* mime_type);


		private:

			/**
			 * timeout 0 never times out
			 */
			std::string send(const char* url, int timeout);

			static size_t write_data(void *ptr, size_t size, size_t nmemb, void *ourpointer);

			CURL* curl;

	};

} // end namespace webapp

#endif // _DUMMYPROJECT_DUMMY_HPP_
