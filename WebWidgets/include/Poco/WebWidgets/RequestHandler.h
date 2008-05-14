//
// RequestHandler.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/RequestHandler.h#2 $
//
// Library: WebWidgets
// Package: Core
// Module:  RequestHandler
//
// Definition of the RequestHandler class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
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


#ifndef WebWidgets_RequestHandler_INCLUDED
#define WebWidgets_RequestHandler_INCLUDED


#include "Poco/WebWidgets/WebWidgets.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/NameValueCollection.h"
#include "Poco/Net/HTMLForm.h"


namespace Poco {
namespace WebWidgets {


class WebApplication;


class WebWidgets_API RequestHandler: public Poco::Net::HTTPRequestHandler
	/// The HTTP request handler for WebWidgets.
{
public:
	static const std::string KEY_ID; /// key for form param contains id
	static const std::string KEY_EVID; /// form param containing the event name

	RequestHandler(WebApplication& app);
		/// Creates the RequestHandler, using the given WebApplication.

	virtual ~RequestHandler();
		/// Destroys the RequestHandler.

	// HTTPRequestHandler
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

protected:
	void handlePageRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
	void handleAjaxRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response, const Poco::Net::NameValueCollection& args);
	void handleForm(const Poco::Net::HTMLForm& form);
	static void parseRequest(const Poco::Net::HTTPServerRequest& request, Poco::Net::NameValueCollection& nvc);
	static void parseRequest(const std::string& path, Poco::Net::NameValueCollection& nvc);
	
private:
	WebApplication& _app;
};


} } // namespace Poco::WebWidgets


#endif // WebWidgets_RequestHandler_INCLUDED
