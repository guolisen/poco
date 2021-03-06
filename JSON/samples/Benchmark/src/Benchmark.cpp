//
// Benchmark.cpp
//
// $Id$
//
// This sample shows a benchmark of the JSON parser.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/Timestamp.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/DefaultHandler.h"
#include "Poco/JSON/JSONException.h"
#include "Poco/Environment.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"
#include <iostream>
#include <iomanip>


void printTimeDiff(const Poco::Timestamp& start, const Poco::Timestamp& end)
{
	Poco::Timestamp::TimeDiff diff = end - start;
	std::cout << std::setw(25) << std::left << diff;
}


int main(int argc, char** argv)
{
	Poco::JSON::Object::Ptr obj;

	std::string dir = Poco::Environment::get("POCO_BASE") + "/JSON/samples/Benchmark/";
	Poco::Path filePath(dir, "input");

	std::ostringstream ostr;

	if ( filePath.isFile() )
	{
		Poco::File inputFile(filePath);
		if ( inputFile.exists() )
		{
			Poco::FileInputStream fis(filePath.toString());
			Poco::StreamCopier::copyStream(fis, ostr);
		}
		else
		{
			std::cout << filePath.toString() << " doesn't exist!" << std::endl;
			return 1; 
		}
	}

	std::cout << std::setw(25) << "POCO JSON";

	std::string jsonStr = ostr.str();
	
	try
	{
		Poco::JSON::DefaultHandler handler;
		Poco::JSON::Parser parser;
		parser.setHandler(&handler);
		Poco::Timestamp time1;
		parser.parse(jsonStr);
		Poco::DynamicAny result = handler.result();
		Poco::Timestamp time2;
		printTimeDiff(time1, time2);

		if ( result.type() == typeid(Poco::JSON::Object::Ptr) )
		{
			obj = result.extract<Poco::JSON::Object::Ptr>();
		}

		//Serialize to string
		std::ostringstream out;
		Poco::Timestamp time3;
		obj->stringify(out);
		Poco::Timestamp time4;
		printTimeDiff(time3, time4);
		std::cout << std::endl;
	}
	catch(Poco::JSON::JSONException jsone)
	{
		std::cout << jsone.message() << std::endl;
	}

	return 0;
}
