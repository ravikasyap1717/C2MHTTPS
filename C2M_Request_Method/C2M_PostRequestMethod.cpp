/*
 * Post_Call.cpp
 *
 *  Created on: 29-Sep-2016
 *      Author: ravi
 */
#include "C2M_PostRequestMethod.hpp"

#define xml_node_name "beacon_tracking"
#define xml_subnode_name "parameter"
#define xml_file_name "C2M.xml"

std::string RegisterChannel(std::string apikey, std::string name, std::string channelid,std::string Identifier, std::string conninfo, std::string schema,std::string legallyagree)
{
	std::string query_param = "RegisterChannel?";

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "name=" + name + "&" \
				+ "channelid=" + channelid + "&" + "Identifier=" + Identifier + "&" \
				+ "conninfo=" + conninfo + "&" + "schema=" + schema  + "&" + "legallyagree=" + legallyagree;

	std::string responce = Post(request);
	return responce;


}

std::string RegisterChannel(std::string apikey, std::string name, std::string channelid,std::string Identifier, std::string legallyagree)
{
	std::string query_param = "RegisterChannel?";

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "name=" + name + "&" \
				+ "channelid=" + channelid + "&" + "Identifier=" + Identifier + "&" + "legallyagree=" + legallyagree;

	std::string responce = Post(request);
	return responce;

}

std::string SetSubscribeChannelConfiguration(std::string apikey, int subscribechannelid,int refreshrate, int refreshperiod)
{
	std::string query_param = "SetSubscribeChannelConfiguration?";

	std::stringstream channelid,rate,period; // stringstream used for the conversion
	channelid << subscribechannelid; rate << refreshrate; period << refreshperiod;

	std::string subscribechannelid_str = channelid.str();
	std::string refreshrate_str = rate.str();
	std::string refreshperiod_str = period.str();

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "subscribechannelid=" + subscribechannelid_str +"&" + "refreshrate=" + refreshrate_str +"&" + "refreshperiod=" + refreshperiod_str;

	std::string responce = Post(request);
	return responce;
}

std::string SetChannelStatus(std::string apikey, int subscribechannelid,int status)
{
	std::string query_param = "SetChannelStatus?";

	std::stringstream channelid,Status; // stringstream used for the conversion
	channelid << subscribechannelid; Status << status;

	std::string subscribechannelid_str = channelid.str();
	std::string status_str = Status.str();

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "subscribechannelid=" + subscribechannelid_str +"&" + "status=" + status_str;

	std::string responce = Post(request);
	return responce;
}

std::string SetFeedConfiguration(std::string apikey,std::string feedid,int refreshrate, int refreshperiod, int isappend)
{
	std::string query_param = "SetFeedConfiguration?";

	std::stringstream append,rate,period; // stringstream used for the conversion
	append << isappend; rate << refreshrate; period << refreshperiod;

	std::string isappend_str = append.str();
	std::string refreshrate_str = rate.str();
	std::string refreshperiod_str = period.str();

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid + "&" + "refreshrate=" + refreshrate_str +"&" + "refreshperiod=" + refreshperiod_str +"&"+ "isappend=" + isappend_str ;
	std::string responce = Post(request);
	return responce;
}

std::string SetChannelFeedStatus(std::string apikey, std::string feedid, int status)
{
	std::string query_param = "SetChannelFeedStatus?";


	std::stringstream STATUS; // stringstream used for the conversion
	STATUS << status;
	std::string status_str = STATUS.str();

	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid +"&" + "status=" + status_str;

	std::string responce = Post(request);
	return responce;
}

std::string Postfeeddata(std::string apikey, std::string feedid, std::string feed)
{
	std::string query_param = "Postfeeddata?";
	std::string request = server_url+ query_param + "apikey=" + apikey +"&" + "feedid=" + feedid;

	std::string Mess = create_xml(xml_node_name,xml_subnode_name,feed,xml_file_name);

	check_xml(Mess.c_str());

	//std::string responce = Post(request,feed);
	std::string responce = Post(request,Mess);
	return responce;
}
