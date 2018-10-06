#pragma once

#ifndef TEXT_EXCEPTION_H
#define TEXT_EXCEPTION_H
class Text_Exception : public std::exception
{
	char* err;

public:

	Text_Exception(const char*);
	Text_Exception(const Text_Exception&);
	~Text_Exception();

	Text_Exception& operator= (const Text_Exception& e);
	const char* what() const;

};
#endif /* TEXT_EXCEPTION_H */
