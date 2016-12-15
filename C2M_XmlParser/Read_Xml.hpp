/*
 * Read_Xml.hpp
 *
 *  Created on: 10-Oct-2016
 *      Author: ravi
 */

#ifndef READ_XML_HPP_
#define READ_XML_HPP_

#include <iostream>
#include <string>

void Read_CheckUserCredentials(std::string message);
void Read_GetCompanies(std::string message);
void Read_GetPublishChannelSchema(std::string message);
void Read_OnboardChannel(std::string message);
void Read_RegisterChannel(std::string message);
void Read_GetAllSubscribeChannel(std::string message);
void Read_GetSubscribeChannelCommands(std::string message);
void Read_GetSubscribeChannelStatus(std::string message);
void Read_SetSubscribeChannelConfiguration(std::string message);
void Read_SetChannelStatus(std::string message);
void Read_GetSubscribeChannel(std::string message);
void Read_DeleteSubscribeChannel(std::string message);
void Read_GetSubscribeChannelFeeds(std::string message);
void Read_GetChannelFeedStatus(std::string message);
void Read_SetFeedConfiguration(std::string message);
void Read_SetChannelFeedStatus(std::string message);
void Read_DeleteChannelFeed(std::string message);
void Read_DeleteChannelFeed(std::string message);
void Read_Postfeeddata(std::string message);
void Read_GetData(std::string message);
void Read_ExecuteFeed(std::string message);

#endif /* READ_XML_HPP_ */

