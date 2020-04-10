#ifndef __HAVE_THING_H__
#define __HAVE_THING_H__

#include <cstddef>

class MyString
{
public:
	MyString(const char * var);
	MyString();
	MyString(const MyString& init);
	const MyString& operator=(const MyString& rhs);
	~MyString();

	const char* str() const;
	size_t size() const;
private:
	char * _ncvar;
	size_t laenge;
};

#endif
