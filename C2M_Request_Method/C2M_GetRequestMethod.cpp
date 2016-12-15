/*
 * Get_Call.cpp
 *
 *  Created on: 28-Sep-2016
 *      Author: ravi
 */
#include "C2M_GetRequestMethod.hpp"


std::string CheckUserCredentials(std::string emailid,std::string password)
{
	std::string query_param = "CheckUserCredentials";
	std::string request = server_url+ query_param;

	return request;std::string responce = Get(request);
	return responce;

}

std::string GetCompanies(std::string apikey)
{
	std::string query_param = "GetCompanies?";
	std::string request = server_url+ query_param + "apikey=" + apikey;

	std::string responce = Get(request);
	return responce;
	//return request;


}
std::string GetPublishChannels(std::string apikey , int companyid)
{
	std::string query_param = "GetPublishChannels?";

	std::stringstream compid; // stringstream used for the conversion
	compid << companyid;
	std::string companyid_str = compid.str();

	std::string request = server_url+ query_param + "companyid=" + companyid_str + "&" + "apikey=" + apikey;

	std::string responce = Get(request);
	return responce;
}

std::string GetPublishChannelSchema(std::string apikey, int publishchannelid)
{
	std::string query_param = "GetPublishChannelSchema?";

	std::stringstream channelid; // stringstream used for the conversion
	channelid << publishchannelid;
	std::string publishchannelid_str = channelid.str();
	std::string request = server_url+ query_param + "publishchannelid=" + publishchannelid_str +"&" + "apikey=" + apikey;

	std::string responce = Get(request);
	return responce;

}

std::string OnboardChannel(std::string apikey, std::string name, int channelidefid)
{
		std::string query_param = "OnboardChannel?";

		std::stringstream convert; // stringstream used for the conversion
		convert << channelidefid;
		std::string channelidefid_str = convert.str();

		std::string request = server_url+ query_param + "apikey=" + apikey + "&" + "name" + name \
					+ "&"+ "channelidefid" + channelidefid_str;

		std::string responce = Get(request);
		return responce;

}

std::string GetAllSubscribeChannel(std::string apikey, std::string pagenumber)
{
	std::string query_param = "GetAllSubscribeChannel?";
	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "pagenumber=" + pagenumber;

	std::string responce = Get(request);
	return responce;
}


std::string GetSubscribeChannelCommands(std::string apikey, int subscribechannelid)
{
	std::string query_param = "GetSubscribeChannelcommands?";


	std::stringstream convert;
	convert << subscribechannelid ; // stringstream used for the conversion
	std::string subscribechannelid_str = convert.str();
	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "subscribechannelid=" + subscribechannelid_str;

	std::string responce = Get(request);
	return responce;
}

std::string GetSubscribeChannelStatus(std::string apikey, int subscribechannelid)
{
	std::string query_param = "GetSubscribeChannelStatus?";

	std::stringstream channelid; // stringstream used for the conversion
	channelid << subscribechannelid;
	std::string subscribechannelid_str = channelid.str();

	std::string request = server_url + query_param + "apikey=" + apikey +"&" + "subscribechannelid=" + subscribechannelid_str;

	std::string responce = Get(request);
	return responce;
}

std::string GetSubscribeChannel(std::string apikey, int publishedchannelid, int pagenumber)
{
	std::string query_param = "GetSubscribeChannel?";

	std::stringstream channelid,page; // stringstream used for the conversion
	channelid << publishedchannelid; page << pagenumber;
	std::string publishedchannelid_str = channelid.str();
	std::string pagenumber_str = page.str();

	std::string request = server_url + query_param + "apikey=" + apikey +"&" + "publishedchannelid=" + publishedchannelid_str +"&" + "pagenumber=" + pagenumber_str;
	std::string responce = Get(request);
	return responce;
}

std::string GetSubscribeChannelFeeds(std::string apikey, int subscribechannelid)
{
	std::string query_param = "GetSubscribeChannelFeeds?";

	std::stringstream channelid; // stringstream used for the conversion
	channelid << subscribechannelid;
	std::string subscribechannelid_str = channelid.str();

	std::string request = server_url+ query_param + "subscribechannelid=" + subscribechannelid_str +"&" + "apikey=" + apikey;

	std::string responce = Get(request);
	return responce;
}

std::string GetChannelFeedStatus(std::string apikey, std::string feedid)
{
	std::string query_param = "GetChannelFeedStatus?";

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid;

	std::string responce = Get(request);
	return responce;
}

std::string PushFeed(std::string apikey, std::string feedid, std::string feed)
{
	std::string query_param = "pushfeed?";


	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid;

	std::string responce = Get(request,feed);
	return responce;
}

std::string GetData(std::string apikey, std::string feedid, std::string parameterType, std::string parameters, std::string filtertype, int startrecord, std::string whereCondition)
{
	std::string query_param = "GetData?";


	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid +"&" + "parameterType=" + parameterType +"&" + "parameters=" + parameters +"&" + "filtertype=" + filtertype +"&" + "feedid=" + feedid +"&" + "feedid=" + feedid;
	return request;
}

std::string ExecuteFeed(std::string apikey, std::string feedid, std::string parameters)
{
	std::string query_param = "ExecuteFeed?";

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid +"&" + "parameters=" + parameters;

	std::string responce = Get(request);
	return responce;
}
