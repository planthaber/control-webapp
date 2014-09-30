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


			std::string get(const char* url);

			std::string post(const char* url,const char* data);

			std::string postMime(const char* url, const char* data, const char* mime_type);


		private:

			std::string send(const char* url);

			static size_t write_data(void *ptr, size_t size, size_t nmemb, void *ourpointer);

			CURL* curl;

	};

} // end namespace webapp

#endif // _DUMMYPROJECT_DUMMY_HPP_
