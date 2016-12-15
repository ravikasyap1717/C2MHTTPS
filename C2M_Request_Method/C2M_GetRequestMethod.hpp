/*
 * C2M_GetRequestMethod.hpp
 *
 *  Created on: 04-Oct-2016
 *      Author: ravi
 */

#ifndef C2M_GETREQUESTMETHOD_HPP_
#define C2M_GETREQUESTMETHOD_HPP_

#include <iostream>

#ifndef Curl_
#define Curl_
	#include "../Curl_Request/Curl_request.hpp"
	#include "../Curl_Request/Curl_request.cpp"
#endif

extern std::string server_url;


std::string CheckUserCredentials(std::string emailid,std::string password);
std::string GetCompanies(std::string apikey);
std::string GetPublishChannels(std::string apikey , int companyid);
std::string GetPublishChannelSchema(std::string apikey, int publishchannelid);
std::string OnboardChannel(std::string apikey, std::string name, int channelidefid);
std::string GetAllSubscribeChannel(std::string apikey, std::string pagenumber);
std::string GetSubscribeChannelCommands(std::string apikey, int subscribechannelid);
std::string GetSubscribeChannelStatus(std::string apikey, int subscribechannelid);
std::string GetSubscribeChannel(std::string apikey, int publishedchannelid, int pagenumber);
std::string GetSubscribeChannelFeeds(std::string apikey, int subscribechannelid);
std::string GetChannelFeedStatus(std::string apikey, std::string feedid);
std::string PushFeed(std::string apikey, std::string feedid, std::string feed);
std::string GetData(std::string apikey, std::string feedid, std::string parameterType, std::string parameters, std::string filtertype, int startrecord, std::string whereCondition);
std::string ExecuteFeed(std::string apikey, std::string feedid, std::string parameters);

#endif /* C2M_GETREQUESTMETHOD_HPP_ */
