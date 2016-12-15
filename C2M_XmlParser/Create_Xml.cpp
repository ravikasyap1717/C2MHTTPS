/*
 * create_xml.cpp
 *
 *  Created on: 05-Sep-2016
 *      Author: ravi
 */

#include "Create_Xml.hpp"

struct xml_string_writer : pugi::xml_writer
{
    std::string result;
    virtual void write(const void* data, size_t size)
    {
        result += std::string(static_cast<const char*>(data), size);
    }
};

/*
 * p1,v1
 * p1,v1|p2,v2|p3,v3|p4,v4
 * p1,v1|p2,v2|p3,v3|p4,v4 <> p5,v5|p6,v6|p6,v7

 * apikey1, feedid1, para1,v1|p2,v2<>apikey1, feedid1, para1,v5|p2,v6
 *	apikey2, feedid2, para1,v1|p2,v2<>apikey1, feedid1, para1,v5|p2,v6
*/



std::vector<std::string> split_str(const std::string &s, const char* delim){

	std::vector<std::string> tokens;

    // to avoid modifying original string
    // first duplicate the original string and return a char pointer then free the memory

    char * dup = strdup(s.c_str());
    char * token = strtok(dup, delim);
    while(token != NULL)
    {
        tokens.push_back(std::string(token));
        // the call is treated as a subsequent calls to strtok:
        // the function continues from where it left in previous invocation
        token = strtok(NULL, delim);
    }
    free(dup);
    return tokens;
}

void check_xml(const char* source)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(source);

	std::cout << "checking XML RESULT " << std::endl << std::endl;
	if (result)
	{
		std::cout << "XML [" << source << "] "<< "\n" << "parsed XML,No errors" << std::endl;
	}
	else
	{
		std::cout << "XML [" << source << "]" << "\n" <<  "parsed with errors" <<  std::endl;
		std::cout << "Error description: " << result.description() << "\n";
		std::cout << "Error offset: " << result.offset << " (error at [..." << (source+ result.offset) << "]\n\n";
	}

}

std::string create_xml(std::string xml_node_name, std::string xml_subnode_name, std::string parameter,std::string xml_file_name )
{

		pugi::xml_document doc;

		pugi::xml_node declarationNode = doc.append_child(pugi::node_declaration);
		declarationNode.append_attribute("version")    = "1.0";
	    declarationNode.append_attribute("encoding")   = "ISO-8859-1";
	    declarationNode.append_attribute("standalone") = "yes";

	    // create a XML Node which Name is Defined
	    pugi::xml_node node = doc.append_child(xml_node_name.c_str());
	    node.append_attribute("version")    = "0.1";

	    std::vector<std::string> split_multiple_record  = split_str(parameter, "<>");
	    std::vector<std::string>::iterator mutiple_record;
	    for(mutiple_record=split_multiple_record.begin();mutiple_record!=split_multiple_record.end();++mutiple_record)
	    {
	    	// create a XML Sub Node which Name is Defined
	    	pugi::xml_node subnode = node.append_child(xml_subnode_name.c_str());

	    	std::vector<std::string> split_pipe  = split_str(*mutiple_record, "|");
	    	std::vector<std::string>::iterator pipe;
	    	for(pipe=split_pipe.begin();pipe!=split_pipe.end();++pipe)
	    	{
	    		std::vector<std::string> split_commas  = split_str(*pipe, ",");
	    		std::vector<std::string>::iterator comma;
	    		for(comma=split_commas.begin();comma!=split_commas.end();)
	    		{
	    			//std::cout << "param =" << (*comma) <<  std::endl;
	    			//create a sub node child with parameter name as passed
	    		    pugi::xml_node descr0 = subnode.append_child((*comma).c_str());
	    		    ++comma;
	    		    //std::cout << "value =" <<  (*comma)  <<  std::endl;
	    		    //create a sub node child value with value as passed
	    	 	    descr0.append_child(pugi::node_pcdata).set_value((*comma).c_str());
	    	 	    ++comma;
	    		}
	    	}
	    }

	    // doc.print(std::cout) ;
	    doc.save_file(xml_file_name.c_str());
	   // save xml in a string
	   xml_string_writer writer;
	   doc.save(writer);
	   std::string xmlstring = writer.result;

	   return xmlstring;
}


