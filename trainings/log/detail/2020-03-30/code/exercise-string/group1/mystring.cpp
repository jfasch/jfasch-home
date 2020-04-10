#include "mystring.h"

MyString::MyString(const char * var)
{
	unsigned int temp_laenge = 0;
	while(*(var + temp_laenge) != '\0')
	{
		temp_laenge++;
	} 

	laenge = temp_laenge;

	_ncvar = new char[laenge+1];
	
	for(unsigned int i=0; i <= laenge; i++)
	{
		_ncvar[i] = var[i];
	}
}

MyString::MyString()
{
	_ncvar = new char[1];
	_ncvar[0] = '\0';
	laenge = 0;
}

MyString::MyString(const MyString& init)
{
	laenge = init.laenge;
	_ncvar = new char[laenge + 1];
	
	for(unsigned int i=0; i <= laenge; i++)
	{
		_ncvar[i] = init._ncvar[i];
	}
}

const MyString& MyString::operator=(const MyString& rhs)
{
	if (this == &rhs)
		return *this;

	delete[] this->_ncvar;
	laenge = rhs.laenge;
	_ncvar = new char[laenge + 1];

	for(unsigned int i=0; i <= rhs.laenge; i++)
	{
		this->_ncvar[i] = rhs._ncvar[i];
	}
	return *this;
}

MyString::~MyString()
{
	delete[] _ncvar;
}

const char* MyString::str() const
{
	return _ncvar;
}

size_t MyString::size() const
{
	return laenge;  
}
