//http://tech.e800.com.cn/articles/2009/1210/1260424896248_1.html
#include <iostream>

using namespace std;

class String{

	friend ostream& operator<< (ostream&,String&);

	public:
		String(const char* str=NULL);                // 赋值构造兼默认构造函数(char)
		String(const String &other);                 // 赋值构造函数(String)
		String& operator=(const String&other);       //operator=
		String operator+(const String &other)const; //operator+
		bool operator==(const String&);              //operator==
		char& operator[](unsigned int);              //operator[]
		size_t size(){return strlen(m_data);};
		~String(void) {delete[] m_data;}
	private:
		char *m_data;
};

String::String(const char* str=NULL)
{
	if (!str)
		m_data = NULL;
	else {
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}

String::String(const String &other)
{
	if (!other.m_data)
		m_data = NULL;
	else {
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	};                 
}

String String::String& operator=(const String&other)
{
	if (*this != other) {
		delete[] m_data;

		m_data = NULL;

		if (other.m_data) {
			m_data = new char[strlen(other.m_data) + 1];
			strcpy(m_data, other.m_data);
		}
	}

	return *this;
}


String String::operator+(const String &other) const
{
	String newString;
	if (!other.m_data)
		newString = *this;
	else
		if (!m_data)
			newString = other;
		else {
			newString.m_data = new char[strlen(m_data) + strlen(other.mdata) + 1];
			strcpy(newString.m_data, m_data);
			strcat(newString.m_data, other.m_data);
		}
	return newString;
}

bool String::operator==(const String&);              //operator==
{
	if (!strcmp(m_data, other.m_data))
		return true;
	else
		return false;
}

