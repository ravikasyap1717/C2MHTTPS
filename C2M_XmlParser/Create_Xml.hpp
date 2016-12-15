/*
 * Create_Xml.hpp
 *
 *  Created on: 10-Oct-2016
 *      Author: ravi
 */

#ifndef CREATE_XML_HPP_
#define CREATE_XML_HPP_

#include "pugixml.hpp"
#include "pugixml.cpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::string create_xml(std::string xml_node_name, std::string xml_subnode_name, std::string parameter,std::string xml_file_name);
std::vector<std::string> split_str(const std::string &s, const char* delim);
void check_xml(const char* source);


#endif /* CREATE_XML_HPP_ */
