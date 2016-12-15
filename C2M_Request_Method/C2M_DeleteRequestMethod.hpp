/*
 * C2M_DeleteRequestMethod.hpp
 *
 *  Created on: 04-Oct-2016
 *      Author: ravi
 */

#ifndef C2M_DELETEREQUESTMETHOD_HPP_
#define C2M_DELETEREQUESTMETHOD_HPP_

#include <iostream>

#ifndef Curl_
#define Curl_
	#include "../Curl_Request/Curl_request.hpp"
	#include "../Curl_Request/Curl_request.cpp"
#endif

extern std::string server_url;

std::string DeleteChannelFeed(std::string apikey, std::string feedid);
std::string DeleteSubscribeChannel(std::string apikey, int subscribechannelid);

#endif /* C2M_DELETEREQUESTMETHOD_HPP_ */
