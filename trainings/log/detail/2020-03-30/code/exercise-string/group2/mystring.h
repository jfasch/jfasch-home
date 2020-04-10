#ifndef __HAVE_THING_H__
#define __HAVE_THING_H__

#include "string.h"

class MyString
{
private:
    char * strContainer;
public:
    MyString()
    {
        strContainer = new char[20];
        strContainer[0] = 0;
    }

    MyString(const char * init)
    {
        strContainer = new char[strlen(init)+1];
        strcpy(strContainer, init);
    }

    MyString(const MyString& init)
    {
        strContainer = new char[strlen(init.strContainer)+1];
        strcpy(strContainer, init.strContainer);
    }

    MyString& operator = (const MyString& init)
    {
        if (this == &init)
            return *this;
        delete[] strContainer;
        strContainer = new char[strlen(init.strContainer)+1];
        strcpy( strContainer, init.str() );
        return *this;
    }

    MyString& operator = (const char * init)
    {
        delete[] strContainer;

        strContainer = new char[strlen(init)+1];
        strcpy(strContainer, init);
        return *this;
    }

    ~MyString()
    {
        delete[] strContainer;
    }

    const char * str() const { return strContainer; }
    int size() const {return strlen(strContainer); }

    bool operator == (const char * str)
    {
        if (strcmp(strContainer, str) == 0)
            return true;
        
        return false;
    }
};




#endif
