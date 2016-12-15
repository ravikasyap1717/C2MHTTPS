/*
 * Curl_request.hpp
 *
 *  Created on: 03-Oct-2016
 *      Author: ravi
 */

#ifndef CURL_REQUEST_CURL_REQUEST_HPP_
#define CURL_REQUEST_CURL_REQUEST_HPP_

#include <iostream>
#include <sstream>
#include <curl/curl.h>

#include "../Curl_Request/Base64_Encode.hpp"
#include "../Curl_Request/Base64_Encode.cpp"


size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
  ((std::string*)stream)->append((char*)ptr, 0, size*count);
  return size*count;
}

std::string Get(std::string url);
std::string Get(std::string url , std::string Header);

std::string Post(std::string url);
std::string Post(std::string url, std::string Header);

std::string Delete(std::string url);

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);



#endif /* CURL_REQUEST_CURL_REQUEST_HPP_ */
