#include<iostream>
#include<cstring>

using namespace std;

template<typename T>
class myString
{
public:
	myString()
	{
		_str = new T [1];
		_str[0] = '\0';
		_size = 0;
	}

	myString(const T* str)
	{
		_size = strlen(str);
		_str = new T [strlen(str) + 1];
		//strcpy(_str, str);
		strcpy_s(_str, _size + 1, str);
	}

	~myString()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
	myString(const myString& str)
	{
		_str = new char[strlen(str._str) + 1];
		_size = str._size;
		//strcpy(_str, str._str);
		strcpy_s(_str, _size + 1, str._str);
	}
	myString& operator=(const myString& str)
	{
		if (this != &str)
		{
			delete _str;
			_str = new T [strlen(str._str) + 1];
			//strcpy(_str, str._str);
			_size = str._size;
			strcpy_s(_str, _size+1, str._str);
		}
		return *this;
	}

	
public:
	const char* GetStr()
	{
		return (char*)_str;
	}
	void myPushback(const T* str)
	{
		_str[_size] = *str;
		_size++;
		_str[_size] = '\0';
	}
	void myPopback()
	{	
		if (_str)
		{
			_str[_size - 1] = '\0';
			_size--;
		}
		else
		{
			cout << "此节点为空" << endl;
		}
	}
	void myInsert(int pos, const T* str)
	{	
		int len = strlen(str);
		int i = _size;
		int j = _size + len;
		for (; i >= pos;)
		{
			_str[j--] = _str[i--];
		}
		while (*str)
		{
			_str[pos++] = *str++;
		}
		_size += len;
		_str[_size] = '\0';
	}

	bool operator<(const myString& str)
	{
		const T* str1 = _str;
		const T* str2 = str._str;
		while (*str1 && *str2)
		{
			if (*str1 < *str2)
			{
				return true;
			}
			else if (*str1 > *str2)
			{
				return false;
			}
			else
			{
				str1++;
				str2++;
			}
		}
		if (*str1)
		{
			return false;
		}
		if (*str2)
		{
			return true;
		}
	}
	bool operator>(const myString& str)
	{
		return !(this < str._str || this == str._str);
	}
	bool operator<=(const myString& str)
	{
		return !(this > str._str);
	}
	bool operator>=(const myString& str)
	{
		return !(this < str._str);
	}
	bool operator==(const myString& str)
	{
		const char* str1 = _str;
		const char* str2 = str._str;
		while (*str1 && *str2)
		{
			if (*str1++ != *str2++)
			{
				return false;
			}
		}
		if (*str1 == *str2)
		{
			return true;
		}
		else
			return false;
	}
	myString operator+(const myString& str)
	{
		myString tmp(_str);
		tmp.Insert(_size, str._str);
		return tmp;
	}
	myString operator+=(const myString& str)
	{
		myInsert(_size, str._str);
		return *this;
	}
	friend ostream& operator<<(ostream& os, const myString& str)
	{
		os << str._str;
		return os;
	}
	friend istream& operator>>(istream& is, myString& str);

private:
	T * _str;
	size_t _size;
};

void test01()
{
	myString<char> s;
	myString<char> s1("hello");
	cout << "s1=" << s1.GetStr() << endl;
	s1.myPopback();
	s1 += "a";
	myString<char> s2 = s1;
	cout << "s2=" << s2.GetStr() << endl;
	s2.myPopback();
	s2.myPushback("a");
	cout << "s2=" << s2.GetStr() << endl;
	myString<char> s3 = s2;
	s3.myPopback();
	cout << "s3=" << s3.GetStr() << endl;
	s3.myInsert(4,"x");
	cout << "s3=" << s3.GetStr() << endl;
}

int main()
{
	test01();
	return 0;
}