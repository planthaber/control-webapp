#include "Http.hpp"



rest_api_cppclient::Http::Http() {
	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	/* no progress meter please */
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
	/* example.com is redirected, so we tell libcurl to follow redirection */
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	/* Force reconnect for GET Requests */
	//curl_easy_setopt(curl, CURLOPT_FRESH_CONNECT, 1L);
	/* Disable Nagle Algorithm */
	curl_easy_setopt(curl, CURLOPT_TCP_NODELAY, 1L);

	//curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
}

rest_api_cppclient::Http::~Http() {
	 curl_easy_cleanup(curl);


}

size_t rest_api_cppclient::Http::write_data(void *ptr, size_t size, size_t nmemb, void *ourpointer){
	//http://curl.haxx.se/libcurl/c/getinmemory.html
	int realsize = size*nmemb;
	std::string* returnstr = (std::string*)ourpointer;
	//returnstr->resize(realsize);
	*returnstr = std::string((char*)ptr);
	return realsize;
}

std::string rest_api_cppclient::Http::send(const char* url, int timeout) {
	std::string returnstring;

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, rest_api_cppclient::Http::write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &returnstring);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);


	CURLcode res = curl_easy_perform(curl);

	/* Check for errors */
	if(res != CURLE_OK){
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	}

	return returnstring;
}

//http://curl.haxx.se/libcurl/c/simple.html
std::string rest_api_cppclient::Http::get(const char* url, int timeout){
	return send(url, timeout);
}

std::string rest_api_cppclient::Http::post(const char* url, const char* data, int timeout) {

	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

	return send(url, timeout);
}

std::string rest_api_cppclient::Http::postMime(const char* url, const char* data, const char* mime_type) {
	std::string returnstring;

	struct curl_slist *headers = NULL;
	std::string content = "Content-Type: ";
	content += mime_type;
	headers = curl_slist_append(headers, content.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

	returnstring = post(url,data);

	curl_slist_free_all(headers); /* free the header list */

	return returnstring;
}


