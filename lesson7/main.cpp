#include<iostream>
using	namespace std;

template<typename T>
class my_shared_ptr {
public:
	my_shared_ptr(T* p):count(new int(1)),ptr(p) {}
	//拷贝构造
	my_shared_ptr(my_shared_ptr<T>& p):count(&(++*p.count)),ptr(p.ptr){}
	~my_shared_ptr()
	{
		if (--*count == 0) {
			delete count;
			delete ptr;
		}
		cout << "~my_shared_ptr";
	}

	my_shared_ptr<T>& operator=(my_shared_ptr<T>& p) {
		if (this == &p) {
			return *this;
		}
		++*p.count;
		if (-- * p.count == 0) {
			delete count;
			delete ptr;
		}
		ptr = p.ptr;
		count = p.count;
		return *this;
	}
	T* operator->() {
		return ptr;
	}
	T& operator*() {
		return *ptr;
	}
	int use_count() {
		return *count;
	}
	bool empty() {
		if (ptr == nullptr) {
			return false;
		}
		else return true;
	}
	//获取地址
	T* get() {
		return ptr;
	}

private:
	int* count;
	T* ptr;
};


int main()
{
	my_shared_ptr<string> s1(new string("aaa")); cout << s1.use_count() << endl;
	my_shared_ptr<string> s2(s1); cout << s1.use_count() <<" "; cout << s2.use_count() << endl;
	my_shared_ptr<string> s3(new string("bbb")); cout << s3.use_count() << endl;
	s3 = s2; cout << s1.use_count() << " "; cout << s2.use_count() << " "; cout << s3.use_count() << endl;
	cout << s1.empty() << endl;
	cout << s1.get() << endl;
	return 0;
}