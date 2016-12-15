/*
 * Read_Xml.cpp
 *
 *  Created on: 06-Oct-2016
 *      Author: ravi
 */

#include "Read_Xml.hpp"

void Read_CheckUserCredentials(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());

	pugi::xml_node response = doc.child("response");

	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

void Read_GetCompanies(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());

	pugi::xml_node response = doc.child("response");
	pugi::xml_node response_child;

	if(response_child =response.child("code"))
		std::cout << "code : " << response_child.child_value() << std::endl;

	if(response_child =response.child("status"))
		std::cout << "status : " << response_child.child_value() << std::endl;

	if(response_child =response.child("message"))
		std::cout << "message : " << response_child.child_value() << std::endl;

	if(response_child =response.child("icedata").child("companies").child("company"))
	{
		std::cout << response_child.name() << ":" << std::endl;
		for (pugi::xml_node_iterator it = response_child.begin(); it != response_child.end(); ++it)
		{
			std::cout << "\t" << it->name() << "=" << it->child_value();
			std::cout << std::endl;
		}
	}

}
void Read_GetPublishChannels(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());

	pugi::xml_node response = doc.child("response");
	pugi::xml_node response_child;

	if(response_child =response.child("code"))
		std::cout << "code : " << response_child.child_value() << std::endl;

	if(response_child =response.child("status"))
		std::cout << "status : " << response_child.child_value() << std::endl;

	if(response_child =response.child("message"))
		std::cout << "message : " << response_child.child_value() << std::endl;

	if(response_child =response.child("icedata").child("company").child("channel"))
	{
		//std::cout << "status : " << respon.child_value() << std::endl;
		//std::cout << respon.child("ID").text().get() << std::endl;
		std::cout << response_child.name() << ":" << std::endl;
		for (pugi::xml_node_iterator it = response_child.begin(); it != response_child.end(); ++it)
		{
			std::cout << "\t" << it->name() << "=" << it->child_value();
			std::cout << std::endl;
		}
	}

}
/*==========GetPublishChannelSchema ======  */
/*std::string mess ="<?xml version=\"1.0\" encoding=\"utf-8\"?>"
		"<response xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
		"<code>200</code><status>SUCCESS</status>"
		"<icedata>"
			"<channel>"
				"<name>Arduino Uno</name>"
				"<schemaxsd>"
					"<xs:element name=\"dm\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\">"
						"<xs:complexType>"
							"<xs:sequence>"
								"<xs:element name=\"temp1\" type=\"xs:int\"/>"
								"<xs:element name=\"temp2\" type=\"xs:int\"/>"
							"</xs:sequence>"
						"</xs:complexType>"
					"</xs:element>"
				"</schemaxsd>"
	"<identification><root>"
		"<Column selected=\"true\" type=\"string\" name=\"mac\"/>"
	"</root></identification>"
		"</channel></icedata>"
		"</response>";*/
void Read_GetPublishChannelSchema(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());

	pugi::xml_node response = doc.child("response");
	for (pugi::xml_attribute attr = response.first_attribute(); attr; attr = attr.next_attribute())
	{
		std::cout << "\t" << attr.name() << "=" << attr.value()  <<  std::endl ;
	}

	pugi::xml_node response_child;

	if(response_child =response.child("code") )
		std::cout << "code : " << response_child.child_value() << std::endl;

	if(response_child =response.child("status") )
		std::cout << "status : " << response_child.child_value() << std::endl;


	if(response_child =response.child("icedata").child("channel"))
	{
		pugi::xml_node channel;
		if(channel =response_child.child("name") )
			std::cout << "name : " << channel.child_value() << std::endl;

		if(channel =response_child.child("schemaxsd") )
		{
			std::cout << "schemaxsd:"<< std::endl;
			pugi::xml_node xs_element = channel.child("xs:element") ;
			std::cout << "xs:element : "<< std::endl;
			for (pugi::xml_attribute attr = xs_element.first_attribute(); attr; attr = attr.next_attribute())
			{
				std::cout << "\t" << attr.name() << "=" << attr.value()  <<  std::endl ;
			}
			std::cout <<  std::endl;

			pugi::xml_node xs_sequence = xs_element.child("xs:complexType").child("xs:sequence") ;
			std::cout << "xs:element : "<< std::endl;

			for (pugi::xml_node tool = xs_sequence.first_child(); tool; tool = tool.next_sibling())
			{
				std::cout << "Tool:";
				for (pugi::xml_attribute attr = tool.first_attribute(); attr; attr = attr.next_attribute())
				{
					std::cout << "\t" << attr.name() << "=" << attr.value() <<  std::endl;
				}
				std::cout <<  std::endl;
			}
		}

		if(channel = response_child.child("identification").child("root"))
		{
			std::cout <<  "Column : " << std::endl;
			pugi::xml_node Column = channel.child("Column");
			for (pugi::xml_attribute attr = Column.first_attribute(); attr; attr = attr.next_attribute())
			{
				std::cout << "\t" << attr.name() << "=" << attr.value()  <<  std::endl ;
			}

		}
	}
}
 /* ==================   OnboardChannel =========================*/
void Read_OnboardChannel(std::string message)
{
	/*std::string message = "<response><code> 200</code><status> SUCCESS</status>"
		"<message> https://www.connect2.me/Apiprovider.aspx?accessToken=https://graph.faceboo"
		"k.com/oauth/access_token?grant_type=authorization_code@accessTokenparam=access_to"
		"ken@requestToken=@authorizeToken=https://graph.facebook.com/oauth/authorize?auth_"
		"type=reauthenticate@consumerKey=649822138478766@consumerKeyparam=client_id@co"
		"nsumerSecret=84c5707598407ec61880e6ead5600ee4@consumerSecretparam=client_secre"
		"t@ApiCallUrl=@BaseUrl=https://graph.facebook.com/v2.2@Version=OAuth"
		"2.0@methodType=GET@fromPg=Ice@Scope=user_about_me,user_actions.books,user_acti"
		"ons.music,user_actions.news,user_actions.video,user_activities,user_birthday,"
		"user_education_history,user_events,user_friends,user_games_activity,user_groups,user_ho"
		"metown,user_interests,user_likes,"
		"user_location,user_photos,user_relationship_details,user_relationships,user_religion_politic"
		"s,user_status,"
		"user_tagged_places,user_videos,user_website,user_work_history,email,manage_notificatio"
		"ns,manage_pages,publish_actions,"
		"read_friendlists,read_insights,read_mailbox,read_page_mailboxes,read_stream,rsvp_event,"
		"publish_likes@channeldefId=315@name=ApiTest2@type=API@apikey=dvH5tcKnrQu5CcXz<"
		"/message></response>";*/

	pugi::xml_document doc;
	doc.load_string(message.c_str());

	pugi::xml_node response = doc.child("response");
	pugi::xml_node response_child;

	if(response_child =response.child("code") )
		std::cout << "code : " << response_child.child_value() << std::endl;

	if(response_child =response.child("status") )
		std::cout << "status : " << response_child.child_value() << std::endl;

	if(response_child =response.child("message") )
		std::cout << "message : " << response_child.child_value() << std::endl;

}

void Read_RegisterChannel(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());

	pugi::xml_node response = doc.child("response");

	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*================= GetAllSubscribeChannel =========================*/
void Read_GetAllSubscribeChannel(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());

	pugi::xml_node response = doc.child("response");
	pugi::xml_node respon;

	if(respon =response.child("code"))
		std::cout << "code : " << respon.child_value() << std::endl;

	if(respon =response.child("status"))
		std::cout << "status : " << respon.child_value() << std::endl;

	if(respon =response.child("message"))
		std::cout << "message : " << respon.child_value() << std::endl;

	if(respon =response.child("icedata").child("subscribechannel").child("channels").child("channel"))
	{
		std::cout << respon.name() << ":" << std::endl;
		for (pugi::xml_node_iterator it = respon.begin(); it != respon.end(); ++it)
		{
			std::cout << "\t" << it->name() << "=" << it->child_value();
			std::cout << std::endl;
		}
	}
}

void Read_GetSubscribeChannelCommands(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

void Read_GetSubscribeChannelStatus(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*=================== SetSubscribeChannelConfiguration =============================*/
void Read_SetSubscribeChannelConfiguration(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*=======================  SetChannelStatus ===================================*/
void Read_SetChannelStatus(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}
/*========================= GetSubscribeChannel  ==============================================*/
void Read_GetSubscribeChannel(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	pugi::xml_node respon;

	if(respon =response.child("code"))
		std::cout << "code : " << respon.child_value() << std::endl;
	if(respon =response.child("status"))
		std::cout << "status : " << respon.child_value() << std::endl;
	if(respon =response.child("message"))
		std::cout << "message : " << respon.child_value() << std::endl;

	if(respon =response.child("icedata").child("company").child("channel"))
	{
		std::cout << respon.name() << ":" << std::endl;
		for (pugi::xml_node_iterator it = respon.begin(); it != respon.end(); ++it)
		{
			std::cout << "\t" << it->name() << "=" << it->child_value();
			std::cout << std::endl;
		}
	}
}

/*================  DeleteSubscribeChannel  ==========================*/
void Read_DeleteSubscribeChannel(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*================  GetSubscribeChannelFeeds ==========================*/
void Read_GetSubscribeChannelFeeds(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	pugi::xml_node respon;

	if(respon =response.child("code"))
		std::cout << "code : " << respon.child_value() << std::endl;
	if(respon =response.child("status"))
		std::cout << "status : " << respon.child_value() << std::endl;
	if(respon =response.child("message"))
		std::cout << "message : " << respon.child_value() << std::endl;

	if(respon =response.child("icedata").child("feeds").child("feed"))
	{
		std::cout << respon.name() << ":" << std::endl;
		for (pugi::xml_node_iterator it = respon.begin(); it != respon.end(); ++it)
		{
			std::cout << "\t" << it->name() << "=" << it->child_value();
			std::cout << std::endl;
		}
	}
}

/*================ GetChannelFeedStatus ==========================*/
void Read_GetChannelFeedStatus(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*================ SetFeedConfiguration ==========================*/
void Read_SetFeedConfiguration(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*================ SetChannelFeedStatus ==========================*/
void Read_SetChannelFeedStatus(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*================ DeleteChannelFeed ==========================*/
void Read_DeleteChannelFeed(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}
/*================ PushFeed ==========================*/
void Read_PushFeed(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}


/*================ Postfeeddata ==========================*/
void Read_Postfeeddata(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("response");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}

/*================ GetData ==========================*/
/*<root>
	<response status=\"SUCCESS\" startrecord=\"0\" fetchedrecords=\"10\" totalrecords=\"36011\">
	<NewDataSet>
		<Table1>
			<c2mdatetime>2015-01-20T22:03:00.436+00:00</c2mdatetime>
			<v5>8</v5>
			<v4>0</v4>
			<v3>1240</v3>
			<v2>1240</v2>
			<c2mseqno>1</c2mseqno>
			<c2mfeedid>897</c2mfeedid>
			<c2muserid>526</c2muserid>
			<battery>2529</battery>
			<potentiometer>25</potentiometer>
		</Table1>
		<Table1>
			<c2mdatetime>2015-01-20T22:01:25.681+00:00</c2mdatetime>
			<v5>0</v5>
			<v4>0</v4>
			<v3>1054</v3>
			<v2>1015</v2>
			<c2mseqno>1</c2mseqno>
			<c2mfeedid>897</c2mfeedid>
			<c2muserid>526</c2muserid>
			<battery>2109</battery>
			<potentiometer>21</potentiometer>
			</Table1>
		</NewDataSet>
	</ response>
</root>
*/
void Read_GetData(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("root").child("response");
	std::cout << " Attribute : " << std::endl;
	for (pugi::xml_attribute attr = response.first_attribute(); attr; attr = attr.next_attribute())
	{
		std::cout << "\t" << attr.name() << "=" << attr.value()  <<  std::endl ;
	}

	pugi::xml_node NewDataSet = response.child("NewDataSet");

	std::cout << " NewDataSet : " << std::endl;
	for (pugi::xml_node Table1 = NewDataSet.first_child(); Table1; Table1 = Table1.next_sibling())
	{
		std::cout << "\t" << " Table1 : "<< std::endl;
		for (pugi::xml_node_iterator it1 = Table1.begin(); it1 != Table1.end(); ++it1)
		{
			std::cout << "\t"<< "\t" <<it1->name() << " : " << it1->child_value();
			std::cout << std::endl;
		}
	}
}


/*================ ExecuteFeed ==========================*/

void Read_ExecuteFeed(std::string message)
{
	pugi::xml_document doc;
	doc.load_string(message.c_str());
	pugi::xml_node response = doc.child("root");
	for (pugi::xml_node_iterator it1 = response.begin(); it1 != response.end(); ++it1)
	{
		std::cout << it1->name() << " : " << it1->child_value();
		std::cout << std::endl;
	}
}
