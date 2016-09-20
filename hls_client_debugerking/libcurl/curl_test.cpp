#include <stdio.h>
#include <string>
#include <iostream>
//#define CURL_STATICLIB
#include <curl/curl.h>


//#pragma commnet( lib, "wldap32.lib")
//#pragma comment( lib, "ws2_32.lib")

//#ifdef _DEBUG
//#pragma comment( lib, "libcurld.lib")
//#else
//#pragma comment( lib, "libcurl.lib")
//#endif

int main(void)
{
	CURL* ctx;
	CURLcode res;

	const char* url = "http://192.168.219.200/test.m3u8";

	ctx = curl_easy_init();
	if (ctx)
	{
		curl_easy_setopt(ctx, CURLOPT_URL, url);
		curl_easy_setopt(ctx, CURLOPT_FOLLOWLOCATION, 1L);

		res = curl_easy_perform(ctx);

		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		curl_easy_cleanup(ctx);

	}
	return 0;
}