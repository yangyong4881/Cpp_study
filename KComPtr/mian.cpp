#include<iostream>
#include<unordered_map>

using namespace std;

class ReferenceCount
{
public:
	void incRef(void* ptr) {
		refMap[ptr]++;
	}
	int decRef(void* ptr) {
		unordered_map <void*, int>::iterator it = refMap.find(ptr);
		if (it == refMap.end()) {
			return 0;
		}
		else {
			int ret = --(it->second);
			if (it->second == 0) {
				refMap.erase(it);
			}
			return ret;
		}
	}
private:
	unordered_map <void*, int> refMap;
};



template<typename T>
class KcomPtr
{
public:
	KcomPtr(T* ptr = NULL) :kptr(ptr)
	{
		if (kptr != NULL)
		{
			refCnt.add(kptr);
		}
	}
	~KcomPtr()
	{
		refCnt.del(kptr);
	}

	bool operator==(const T* ptr)const 
	{ 
		return kptr == ptr; 
	}
	bool operator!=(const T * ptr)const
	{ 
		return kptr != ptr;
	}
private:
	T* kptr;
	static ReferenceCount refCnt;
	void incRef() { refCnt.incRef(kptr); }
	int decRef() { return refCnt.decRef(kptr); }
};
template<typename T>
ReferenceCount KcomPtr<T>::refCnt;


int main()
{
	return 0;
}