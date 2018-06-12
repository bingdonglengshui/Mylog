 ///
 /// @file    Mylog.cc
 /// @author  lishen
 /// @date    2018-06-11 20:06:52
 ///
#include "Mylog.h"
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <iostream>
using std::cout;
using namespace wd;
Mylog* Mylog::_pinstance=NULL; 
Mylog* Mylog::getInstance()
{
	if(_pinstance==NULL)
	{
		_pinstance=new Mylog();
	}
	return _pinstance;
}
void Mylog::destory()
{
	if(_pinstance!=NULL)
	{
		delete _pinstance;
		_pinstance=NULL;
	}
}
void Mylog::error(const char* msg)
{
	root.error(msg);
}
void Mylog::info(const char* msg)
{
	root.info(msg);
}
void Mylog::warn(const char* msg)
{
	root.warn(msg);
}
void Mylog::debug(const char* msg)
{
	root.debug(msg);
}
Mylog::Mylog()
     :root(log4cpp::Category::getRoot())
{
	log4cpp::OstreamAppender *osappend=new log4cpp::OstreamAppender("osappend",&cout);
	log4cpp::FileAppender * fileappend=new log4cpp::FileAppender("fileappend","log4cpp.txt");
	log4cpp::PatternLayout* layout1=new log4cpp::PatternLayout();
	layout1->setConversionPattern("%d:[%p] %x :%m%n");
	log4cpp::PatternLayout* layout2=new log4cpp::PatternLayout();
	layout2->setConversionPattern("%d:[%p] %x :%m%n");
    osappend->setLayout(layout1);
	fileappend->setLayout(layout2);
	root.setAppender(osappend);
	root.setAppender(fileappend);
	root.setPriority(log4cpp::Priority::DEBUG);
}
Mylog::~Mylog()
{
	log4cpp::Category::shutdown();
}


