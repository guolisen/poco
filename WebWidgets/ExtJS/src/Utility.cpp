//
// Utility.cpp
//
// $Id: //poco/Main/WebWidgets/ExtJS/src/Utility.cpp#17 $
//
// Library: ExtJS
// Package: Core
// Module:  Utility
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
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


#include "Poco/WebWidgets/ExtJS/Utility.h"
#include "Poco/WebWidgets/ExtJS/LabelRenderer.h"
#include "Poco/WebWidgets/ExtJS/PageRenderer.h"
#include "Poco/WebWidgets/ExtJS/ButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/SubmitButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/CollapsibleRenderer.h"
#include "Poco/WebWidgets/ExtJS/FormRenderer.h"
#include "Poco/WebWidgets/ExtJS/FrameRenderer.h"
#include "Poco/WebWidgets/ExtJS/TextFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/TimeFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/DateFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/PasswordFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/NumberFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/ComboBoxCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/ImageButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/TextEditCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/CheckButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/RadioButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/GridLayoutRenderer.h"
#include "Poco/WebWidgets/ExtJS/PanelRenderer.h"
#include "Poco/WebWidgets/ExtJS/HorizontalLayoutRenderer.h"
#include "Poco/WebWidgets/ExtJS/VerticalLayoutRenderer.h"
#include "Poco/WebWidgets/ExtJS/ImageRenderer.h"
#include "Poco/WebWidgets/ExtJS/TabViewRenderer.h"
#include "Poco/WebWidgets/ExtJS/ListBoxCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/TableRenderer.h"

#include "Poco/WebWidgets/Label.h"
#include "Poco/WebWidgets/Page.h"
#include "Poco/WebWidgets/ButtonCell.h"
#include "Poco/WebWidgets/SubmitButtonCell.h"
#include "Poco/WebWidgets/Collapsible.h"
#include "Poco/WebWidgets/Form.h"
#include "Poco/WebWidgets/Frame.h"
#include "Poco/WebWidgets/Panel.h"
#include "Poco/WebWidgets/Cell.h"
#include "Poco/WebWidgets/View.h"
#include "Poco/WebWidgets/GridLayout.h"
#include "Poco/WebWidgets/TextFieldCell.h"
#include "Poco/WebWidgets/TimeFieldCell.h"
#include "Poco/WebWidgets/DateFieldCell.h"
#include "Poco/WebWidgets/PasswordFieldCell.h"
#include "Poco/WebWidgets/NumberFieldCell.h"
#include "Poco/WebWidgets/ComboBoxCell.h"
#include "Poco/WebWidgets/ImageButtonCell.h"
#include "Poco/WebWidgets/TextEditCell.h"
#include "Poco/WebWidgets/CheckButtonCell.h"
#include "Poco/WebWidgets/RadioButtonCell.h"
#include "Poco/WebWidgets/HorizontalLayout.h"
#include "Poco/WebWidgets/VerticalLayout.h"
#include "Poco/WebWidgets/Image.h"
#include "Poco/WebWidgets/TabView.h"
#include "Poco/WebWidgets/ListBoxCell.h"
#include "Poco/WebWidgets/Table.h"
#include "Poco/WebWidgets/WebApplication.h"
#include "Poco/WebWidgets/RequestHandler.h"

#include "Poco/String.h"
#include "Poco/DateTimeFormat.h"
#include <sstream>


namespace Poco {
namespace WebWidgets {
namespace ExtJS {


void Utility::initialize(LookAndFeel::Ptr ptr)
{
	ptr->registerRenderer(typeid(Label), new LabelRenderer());
	ptr->registerRenderer(typeid(Page), new PageRenderer());
	ptr->registerRenderer(typeid(ButtonCell), new ButtonCellRenderer());
	ptr->registerRenderer(typeid(SubmitButtonCell), new SubmitButtonCellRenderer());
	ptr->registerRenderer(typeid(Form), new FormRenderer());
	ptr->registerRenderer(typeid(Frame), new FrameRenderer());
	ptr->registerRenderer(typeid(Collapsible), new CollapsibleRenderer());
	ptr->registerRenderer(typeid(TextFieldCell), new TextFieldCellRenderer());
	ptr->registerRenderer(typeid(TimeFieldCell), new TimeFieldCellRenderer());
	ptr->registerRenderer(typeid(DateFieldCell), new DateFieldCellRenderer());
	ptr->registerRenderer(typeid(PasswordFieldCell), new PasswordFieldCellRenderer());
	ptr->registerRenderer(typeid(NumberFieldCell), new NumberFieldCellRenderer());
	ptr->registerRenderer(typeid(ComboBoxCell), new ComboBoxCellRenderer());
	ptr->registerRenderer(typeid(ImageButtonCell), new ImageButtonCellRenderer());
	ptr->registerRenderer(typeid(TextEditCell), new TextEditCellRenderer());
	ptr->registerRenderer(typeid(CheckButtonCell), new CheckButtonCellRenderer());
	ptr->registerRenderer(typeid(RadioButtonCell), new RadioButtonCellRenderer());
	ptr->registerRenderer(typeid(ListBoxCell), new ListBoxCellRenderer());
	ptr->registerRenderer(typeid(GridLayout), new GridLayoutRenderer());
	ptr->registerRenderer(typeid(Panel), new PanelRenderer());
	ptr->registerRenderer(typeid(HorizontalLayout), new HorizontalLayoutRenderer());
	ptr->registerRenderer(typeid(VerticalLayout), new VerticalLayoutRenderer());
	ptr->registerRenderer(typeid(Image), new ImageRenderer());
	ptr->registerRenderer(typeid(TabView), new TabViewRenderer());
	ptr->registerRenderer(typeid(Table), new TableRenderer());
}


const std::string& Utility::getTmpID()
{
	static const std::string tmp("tmp");
	return tmp;
}


void Utility::writeRenderableProperties(const Renderable* pRend, std::ostream& ostr)
{
	ostr << "id:'" << pRend->id() << "'";
}


void Utility::writeRenderableProperties(const std::string& id, std::ostream& ostr)
{
	if (!id.empty())
		ostr << "id:'" << id << "'";
}


void Utility::writeCellProperties(const Cell* pCell, std::ostream& ostr, bool writeId)
{
	if (writeId)
		writeRenderableProperties(pCell, ostr);
	//don't support label for cell, keep this separate
	ostr << ",hideLabel:true";
	if (!pCell->isEnabled())
	ostr << ",disabled:true";
	View* pOwner = pCell->getOwner();
	if (pOwner)
	{
		if (!pOwner->getName().empty())
			ostr << ",name:'" << pOwner->getName() << "'";
		if (pOwner->getWidth() != 0)
			ostr << ",width:" << pOwner->getWidth();
		if (pOwner->getHeight() != 0)
			ostr << ",height:" << pOwner->getHeight();
	}
}



void Utility::writeCellProperties(const std::string& id, 
								const std::string& disabled, 
								const std::string& name, 
								const std::string& width,
								const std::string& height,
								std::ostream& ostr)
{
	
	writeRenderableProperties(id, ostr);
	//don't support label for cell, keep this separate
	if (!id.empty())
		ostr << ",";
	ostr << "hideLabel:true,";
	if (!disabled.empty())
		ostr << ",disabled:" << disabled;

	if (!name.empty())
		ostr << ",name:" << name;
	
	if (!width.empty())
		ostr << ",width:" << width;
	if (!height.empty())
		ostr << ",height:" << height;
}


std::string Utility::safe(const std::string& str)
{
	std::string safe(Poco::replace(str, "\\", "\\\\"));
	Poco::replaceInPlace(safe, "'", "\\'");
	return safe;
}


std::string Utility::convertPocoDateToPHPDate(const std::string& dateTimeFmt)
{
	if (dateTimeFmt == Poco::DateTimeFormat::ISO8601_FORMAT)
		return "c";

	std::string result;
	bool inPercent = false;
	for (int i = 0; i < dateTimeFmt.length(); ++i)
	{
		if (inPercent)
		{
			convertPocoDateToPHPDate(dateTimeFmt[i], result);
			inPercent = false;
		}
		else
		{
			if (dateTimeFmt[i] == '%')
			{
				poco_assert_dbg(!inPercent);
				inPercent = true;
			}
			else
				escapeCharForPHP(dateTimeFmt[i], result);
		}
	}
	return result;
}


void Utility::convertPocoDateToPHPDate(char in, std::string& result)
{
	//Not supported in POCO:
	//   *??->w - Numeric representation of the day of the week (1-7)
	//   *??->z - Day of the year starting with zero for jan the 1st (0 - 364/365)
	//   *??->W - ISO-8601 week number of year, weeks starting on Monday (01-53)
	//   *??->t - Number of days in the given month (28-31)
	//   *??->L - 1 for a yeap lear, 0 otherwise
	//   *??->o - ISO-8601 year number but if the ISO week number (W) belongs to the previous or next year, that year is used instead
	//   *??->g - 12-hour format of an hour without leading zeros
	//   *??->G - 24-hour format of an hour without leading zeros
	//   *??->T - Timezone abbreviation of the machine running the code, examples: EST, MDT, PDT
	//   *??->Z - Timezone offset in seconds (negative if west of UTC, positive if east)    -43200 to 50400
	//   *??->c - ISO 8601 date, should be handled in the caller must not occur here
	//   *??->U - Seconds since the Unix Epoch (January 1 1970 00:00:00 GMT) 1193432466 or -2138434463

	//   * %w->D - abbreviated weekday (Mon, Tue, ...)
	//   * %W->l - full weekday (Monday, Tuesday, ...)
	//   * %b->M - abbreviated month (Jan, Feb, ...)
	//   * %B->F - full month (January, February, ...)
	//   * %d->d - zero-padded day of month (01 .. 31)
	//   * %e->j - day of month (1 .. 31)
	//   * %m->m - zero-padded month (01 .. 12)
	//   * %n->n - month (1 .. 12)
	//   * %y->y - year without century (70)
	//   * %Y->Y - year with century (1970)
	//   * %H->H - hour (00 .. 23)
	//   * %h->h - hour (00 .. 12)
	//   * %a->a - am/pm
	//   * %A->A - AM/PM
	//   * %M->i - minute (00 .. 59)
	//   * %S->s - second (00 .. 59)
	//   * %i->u - millisecond (000 .. 999)
	//   * %z->P - time zone differential in ISO 8601 format (Z or +NN.NN).
	//   * %Z->O - time zone differential in RFC format (GMT or +NNNN)
	//   * %%->% - percent sign

	//Not supported in PHP/extjs
	//   * %f - space-padded day of month ( 1 .. 31), solution: map this to zeropadded: d
	//   * %o - space-padded month ( 1 .. 12), solution: map this to zeropadded: m
	//   * %c - centisecond (0 .. 9), solution use millisecond: u
	static const char table[]={
		'\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08', '\x09', '\x0A', '\x0B', '\x0C', '\x0D', '\x0E', '\x0F',
		'\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F',
		' ',	'!',	'"',	'#',	'$',	'%',	'&',	'\'',	'(',	')',	'*',	'+',	',',	'-',	'.',	'/',
		'0',	'1',	'2',	'3',	'4',	'5',	'6',	'7',	'8',	'9',	':',	';',	'<',	'=',	'>',	'?',
		'@',	'A',	'F',	'C',	'D',	'E',	'F',	'G',	'H',	'I',	'J',	'K',	'L',	'i',	'N',	'O',
		'P',	'Q',	'R',	's',	'T',	'U',	'V',	'l',	'X',	'Y',	'O',	'[',	'\\',	']',	'^',	'_',
		'`',	'a',	'M',	'u',	'd',	'j',	'f',	'g',	'h',	'u',	'j',	'k',	'l',	'm',	'n',	'm',
		'p',	'q',	'r',	's',	't',	'u',	'v',	'D',	'x',	'y',	'P',	'{',	'|',	'}',	'~',	'\x7F'};

	
	if (in < 0 || in > 127)
	{
		result.append(1, in);
		return;
	}

	result.append(1, table[in]);
}


void Utility::escapeCharForPHP(char in, std::string& result)
{
	// lowest ascii value is 32 ' '
	static const char table[]={
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '1', '0', '0', '1', '0', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1',
		'1', '0', '0', '1', '1', '1', '0', '1', '0', '1', '1', '0', '0', '0', '0', '0',
		'0', '1', '0', '1', '1', '0', '0', '1', '1', '1', '1', '0', '1', '1', '1', '1',
		'0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '1', '0', '0', '0', '0', '0'};

	if (in < 0 || in > 127)
	{
		result.append(1, in);
		return;
	}
	if (table[in] == '1')
	{
		result.append(1, '\\');
	}

	result.append(1, in);
}


void Utility::convertPHPDateToPocoDate(char in, std::string& result)
{
	static const char table[]={
		'\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08', '\x09', '\x0A', '\x0B', '\x0C', '\x0D', '\x0E', '\x0F',
		'\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F',
		' ',	'!',	'"',	'#',	'$',	'%',	'&',	'\'',	'(',	')',	'*',	'+',	',',	'-',	'.',	'/',
		'0',	'1',	'2',	'3',	'4',	'5',	'6',	'7',	'8',	'9',	':',	';',	'<',	'=',	'>',	'?',
		'@',	'A',	'B',	'C',	'D',	'E',	'F',	'G',	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
		'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',	'X',	'Y',	'Z',	'[',	'\\',	']',	'^',	'_',
		'`',	'a',	'b',	'c',	'd',	'e',	'f',	'g',	'h',	'i',	'j',	'k',	'l',	'm',	'n',	'o',
		'p',	'q',	'r',	's',	't',	'u',	'v',	'w',	'x',	'y',	'z',	'{',	'|',	'}',	'~',	'\x7F'};

	if (in < 0 || in > 127)
	{
		result.append(1, in);
		return;
	}
}


LookAndFeel::Ptr Utility::createDefault()
{
	LookAndFeel::Ptr ptr = new LookAndFeel();
	Utility::initialize(ptr);
	return ptr;
}


LookAndFeel& Utility::getDefaultRenderers()
{
	static LookAndFeel::Ptr ptr = createDefault();
	return *ptr;
}


Form::Ptr Utility::insideForm(const View* pChild)
{
	Form::Ptr ptr;

	while (pChild && !ptr)
	{
		View::Ptr ptrView = pChild->parent();
		ptr = ptrView.cast<Form>();
		pChild = ptrView;
	}

	return ptr;
}


Form::Ptr Utility::insideForm(const Cell* pChild)
{
	return Utility::insideForm(pChild->getOwner());
}


bool Utility::writeJSEvent(std::ostream& out, const std::string& eventName, const std::set<JSDelegate>& delegates)
{
	//'click' : {
	//	fn: this.onClick,
	//	scope: this,
	//	delay: 100
	//}
	if (delegates.empty())
		return false;
		
	out << "'" << eventName << "':";
		
	if (delegates.size() == 1)
		out << "{fn:" << delegates.begin()->jsCode() << "}";
	else
	{
		// rather simple way to support more than one delegate
		// TODO: there sure is a more efficient way to do this
		std::ostringstream invoke;
		invoke << "invoke:function(" << JS_EVENTARGNAME << "){";
		out << "{fn:function(" << JS_EVENTARGNAME << "){var all={";
		writeCodeForDelegate(invoke, out, delegates);
		invoke << "}";
		out << invoke.str() << "};"; //closes all
		
		out << "all.invoke(" << JS_EVENTARGNAME << ");";
		out << "}"; //closes fn
		out << "}"; //closes function
	}	

	return true;
}


void Utility::writeCodeForDelegate(std::ostream& invoke, std::ostream& out, const std::set<JSDelegate>& jsDels)
{
	int cnt(0);
	std::set<JSDelegate>::const_iterator it = jsDels.begin();
	for (; it != jsDels.end(); ++it)
	{
		writeCodeForDelegate(invoke, out, *it, cnt);
		++cnt;
	}
}


void Utility::writeCodeForDelegate(std::ostream& invoke, std::ostream& out, const JSDelegate& jsDel, int cnt)
{
	std::string code(Poco::trim(jsDel.jsCode()));
	if (code.find("function") == 0)
	{
		// inline function definition
		out << "d" << cnt << ":" << code << ",";
		invoke << "this.d" << cnt << "(" << JS_EVENTARGNAME << ");";
	}
	else
	{
		out << "d" << cnt << ":function(" << JS_EVENTARGNAME << "){" << code;
		if (!code.empty() && code[code.size()-1] != ';')
			out << ";";
		 out << "},";
		invoke << "this.d" << cnt << "(" << JS_EVENTARGNAME << ");";
	}
}


bool Utility::writeJSEventPlusServerCallback(std::ostream& out, const std::string& eventName, const std::set<JSDelegate>& delegates, const std::map<std::string, std::string>& addServerParams)
{
	// rather simple way to support more than one delegate
	// TODO: there sure is a more efficient way to do this
	std::ostringstream invoke;
	invoke << "invoke:function(" << JS_EVENTARGNAME << "){";
	out << "{fn:function(" << JS_EVENTARGNAME << "){var all={";
	writeCodeForDelegate(invoke, out, delegates);
	//write server callback
	writeCodeForDelegate(invoke, out, jsDelegate(createFunctionCode(eventName, addServerParams)), static_cast<int>(delegates.size()));
	invoke << "}";
	out << invoke.str() << "};"; //closes all
	
	out << "all.invoke(" << JS_EVENTARGNAME << ");";
	out << "}"; //closes fn
	out << "}"; //closes function
	return true;
}


std::string Utility::createFunctionCode(const std::string& eventName, const std::map<std::string, std::string>& addParams)
{
	WebApplication& app = WebApplication::instance();
	Renderable::ID id = app.getCurrentPage()->id();
	std::ostringstream uri;
	uri << "'" << app.getURI().toString();
	uri << ";"; //mark as AJAX request
	uri << RequestHandler::KEY_ID << "=" << id << "&";
	uri << RequestHandler::KEY_EVID << "=" << eventName;
	// add optional params
	std::map<std::string, std::string>::const_iterator it = addParams.begin();
	for (; it != addParams.end(); ++it)
	{
		uri << "&" << it->first;
		if (it->second.empty())
		{
		}
		else
		{
			if (it->second[0] == '+')
			{
				// a variable was added
				uri << "='" << 	it->second << "+'";
			}
			else
				uri << "=" << it->second;
					
		}
		 
	}
	// now add the callback code
	std::ostringstream function;
	function << "function(" << JS_EVENTARGNAME << "){var uri=" << uri.str() << ";";
	function << "Ext.Ajax.request({url:uri,";
	function << "failure:function(){Ext.MessageBox.alert('Status','Failed to write changes back to server.');}});}";
	return function.str();
}


} } } // namespace Poco::WebWidgets::ExtJS
