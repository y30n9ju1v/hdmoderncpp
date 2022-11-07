#include <list>

// STL list ���� ��� �޾Ƽ� ������ �Լ� 1~2���� �߰��ϰ� �ʹ�.
class MyList : public std::list<int>
{
public:
	void dump() {}

	// C++98 ����
//	MyList(int sz)            : std::list<int>(sz) {}
//	MyList(int sz, int value) : std::list<int>(sz, value) {}

	// C++11 ����
	using std::list<int>::list; // list �� ��� �����ڸ� ���� �ްڴ�
};

int main()
{
	MyList st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList st2(10);
}




