/*
 * Delete_Call.cpp
 *
 *  Created on: 29-Sep-2016
 *      Author: ravi
 */

#include "C2M_DeleteRequestMethod.hpp"

std::string DeleteChannelFeed(std::string apikey, std::string feedid)
{
	std::string query_param = "DeleteChannelFeed?";

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid;

	std::string responce = Delete(request);
	return responce;
}


std::string DeleteSubscribeChannel(std::string apikey, int subscribechannelid)
{
	std::string query_param = "DeleteSubscribeChannel?";

	std::stringstream channelid; // stringstream used for the conversion
	channelid << subscribechannelid;
	std::string subscribechannelid_str = channelid.str();

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "subscribechannelid=" + subscribechannelid_str;

	std::string responce = Delete(request);
	return responce;
}

