#include <list>

// STL list 에서 상속 받아서 간단한 함수 1~2개만 추가하고 싶다.
class MyList : public std::list<int>
{
public:
	void dump() {}

	// C++98 시절
//	MyList(int sz)            : std::list<int>(sz) {}
//	MyList(int sz, int value) : std::list<int>(sz, value) {}

	// C++11 이후
	using std::list<int>::list; // list 의 모든 생성자를 물려 받겠다
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




