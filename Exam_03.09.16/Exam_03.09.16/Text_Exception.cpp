#include "stdafx.h"
#include "Text_Exception.h"


Text_Exception::Text_Exception(const char* text)
{
	err = new char[strlen(text) + 1];
	strcpy(err, text);
}

Text_Exception::Text_Exception(const Text_Exception& e)
{
	err = new char[strlen(e.err) + 1];
	strcpy(err, e.err);
}

Text_Exception::~Text_Exception() throw()
{
	delete[] err;
}

Text_Exception& Text_Exception::operator=(const Text_Exception& e)
{
	err = new char[strlen(e.err) + 1];
	strcpy(err, e.err);
	return *this;
}

const char* Text_Exception::what() const
{
	return err;
}

