#include "Http.hpp"



webapp::Http::Http() {
	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	/* no progress meter please */
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
	/* example.com is redirected, so we tell libcurl to follow redirection */
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
}

webapp::Http::~Http() {
	 curl_easy_cleanup(curl);


}

size_t webapp::Http::write_data(void *ptr, size_t size, size_t nmemb, void *ourpointer){
	//http://curl.haxx.se/libcurl/c/getinmemory.html
	int realsize = size*nmemb;
	std::string* returnstr = (std::string*)ourpointer;
	//returnstr->resize(realsize);
	*returnstr = std::string((char*)ptr);
	return realsize;
}

std::string webapp::Http::send(const char* url) {
	std::string returnstring;

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, webapp::Http::write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &returnstring);

	CURLcode res = curl_easy_perform(curl);

	/* Check for errors */
	if(res != CURLE_OK){
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	}

	return returnstring;
}

//http://curl.haxx.se/libcurl/c/simple.html
std::string webapp::Http::get(const char* url){
	return send(url);
}

std::string webapp::Http::post(const char* url, const char* data) {

	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

	return send(url);
}

std::string webapp::Http::postMime(const char* url, const char* data, const char* mime_type) {
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


