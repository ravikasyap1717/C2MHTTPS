/*
 * Curl_request.cpp
 *
 *  Created on: 04-Oct-2016
 *      Author: ravi
 */

#include "../Curl_Request/Curl_request.hpp"

std::string Get(std::string url)
{
	std::string response;

	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

#ifdef SKIP_PEER_VERIFICATION
		/*
		 * If you want to connect to a site who isn't using a certificate that is
		 * signed by one of the certs in the CA bundle you have, you can skip the
		 * verification of the server's certificate. This makes the connection
		 * A LOT LESS SECURE.
		 *
		 * If you have a CA cert for the server stored someplace else than in the
		 * default bundle, then the CURLOPT_CAPATH option might come handy for
		 * you.
		 */
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
		/*
		 * If the site you're connecting to uses a different host name that what
		 * they have mentioned in their server certificate's commonName (or
		 * subjectAltName) fields, libcurl will refuse to connect. You can skip
		 * this check, but this will make the connection less secure.
		 */
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

		   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		   curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);

		/* Check for errors */
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return response;

}

std::string Get(std::string url , std::string Header)
{
	std::string response;
	std::string Header_Name = "feed:";
	std::string Header_Value = base64_encode(reinterpret_cast<const unsigned char*>(Header.c_str()), Header.length());

	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if(curl) {

		struct curl_slist *chunk = NULL;
		chunk = curl_slist_append(chunk, Header_Name.c_str());
		chunk = curl_slist_append(chunk, Header_Value.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

#ifdef SKIP_PEER_VERIFICATION
		/*
		 * If you want to connect to a site who isn't using a certificate that is
		 * signed by one of the certs in the CA bundle you have, you can skip the
		 * verification of the server's certificate. This makes the connection
		 * A LOT LESS SECURE.
		 *
		 * If you have a CA cert for the server stored someplace else than in the
		 * default bundle, then the CURLOPT_CAPATH option might come handy for
		 * you.
		 */
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
		/*
		 * If the site you're connecting to uses a different host name that what
		 * they have mentioned in their server certificate's commonName (or
		 * subjectAltName) fields, libcurl will refuse to connect. You can skip
		 * this check, but this will make the connection less secure.
		 */
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

		   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		   curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);

		/* Check for errors */
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return response;

}



std::string Post(std::string url)
{
	std::string response;

	CURL *curl;
	CURLcode res;

	try {
		curl = curl_easy_init();
		if (curl) {
			struct curl_slist *chunk = NULL;
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");

			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
			curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

		    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
						curl_easy_strerror(res));

			curl_easy_cleanup(curl);
			curl_slist_free_all(chunk);
		}
	} catch (std::exception& e) {
		std::cout << "Standard exception: " << e.what() << std::endl;
	}

	return response;
}

std::string Post(std::string url, std::string Header)
{
	std::string response;
	std::string Header_Name = "feed:";

	std::string Header_Value = base64_encode(reinterpret_cast<const unsigned char*>(Header.c_str()), Header.length());

	CURL *curl;
	CURLcode res;

	try {
		curl = curl_easy_init();
		if (curl) {
			struct curl_slist *chunk = NULL;
			chunk = curl_slist_append(chunk, Header_Name.c_str());
			chunk = curl_slist_append(chunk, Header_Value.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");

			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
			curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

		    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
						curl_easy_strerror(res));

			curl_easy_cleanup(curl);
			curl_slist_free_all(chunk);
		}
	} catch (std::exception& e) {
		std::cout << "Standard exception: " << e.what() << std::endl;
	}

	return response;
}


std::string Delete(std::string url)
{
	std::string response;

	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return response;

}


