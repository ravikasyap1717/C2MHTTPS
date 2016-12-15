/*
 * main.cpp
 *
 *  Created on: 29-Sep-2016
 *      Author: ravi
 */

#include "C2M_RequestMethod.hpp"
//#include "C2M_XmlParser/create_xml.cpp"

#include <iostream>
std::string server_url = "https://ice.connect2.me/ice.svc/";
int main()
{
/*	std::string str =GetCompanies("ravi");
	std::cout << "str =" << str << std::endl;

	std::string str1 =SetChannelStatus("ravi",0,1);
	std::cout << "str =" << str1 << std::endl;

	std::string str2 =DeleteSubscribeChannel("ravi",0);
	std::cout << "str =" << str2 << std::endl;*/

	std::string str1 =Postfeeddata("ravi","Kumar","soni,1");
	std::cout << std::endl;
	Read_Postfeeddata(str1);
	//std::cout << "str =" << str1 << std::endl;

/*
	//	Check_String_Format(parameter);

	std::string str = create_xml(parameter);
	 std::cout << "Saving Result in string: " << std::endl << str << std::endl;

	 check_xml(str.c_str());*/
}



