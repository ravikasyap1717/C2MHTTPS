/*
 * C2M_PostRequestMethod.hpp
 *
 *  Created on: 04-Oct-2016
 *      Author: ravi
 */

#ifndef C2M_POSTREQUESTMETHOD_HPP_
#define C2M_POSTREQUESTMETHOD_HPP_
#include <iostream>

#include "../C2M_XmlParser/Create_Xml.hpp"
#include "../C2M_XmlParser/Create_Xml.cpp"
//#include "../C2M_XmlParser/Read_Xml.hpp"
//#include "../C2M_XmlParser/Read_Xml.cpp"
#ifndef Curl_
#define Curl_
	#include "../Curl_Request/Curl_request.hpp"
	#include "../Curl_Request/Curl_request.cpp"
#endif


extern std::string server_url;

std::string RegisterChannel(std::string apikey, std::string name, std::string channelid,std::string Identifier, std::string conninfo, std::string schema,std::string legallyagree);
std::string RegisterChannel(std::string apikey, std::string name, std::string channelid,std::string Identifier, std::string legallyagree);
std::string SetSubscribeChannelConfiguration(std::string apikey, int subscribechannelid,int refreshrate, int refreshperiod);
std::string SetChannelStatus(std::string apikey, int subscribechannelid,int status);
std::string SetFeedConfiguration(std::string apikey,std::string feedid,int refreshrate, int refreshperiod, int isappend);
std::string SetChannelFeedStatus(std::string apikey, std::string feedid, int status);
std::string Postfeeddata(std::string apikey, std::string feedid, std::string feed);
#endif /* C2M_POSTREQUESTMETHOD_HPP_ */
