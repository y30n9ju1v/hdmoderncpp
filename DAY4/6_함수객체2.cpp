#include <iostream>

// �Լ���ü�� const member function

struct Plus
{
	// �ٽ� : �Լ� ��ü�� ���鶧, �ǵ��� �̸� operator() ����Լ���
	//       ��� ��� �Լ� �� �ϼ���
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

//template<typename T> void foo(T f)
template<typename T> void foo(const T& f)
{
	int ret = f(1, 2);	// f.operator()(1, 2) �� �Ǿ�� �ϴµ�
						// f�� ��� ��ü �Դϴ�.
						// ȣ�� �����ϰ� �Ϸ���
						// "operator()" �Լ��� ��� ��� �Լ����ؾ��մϴ�.
}

int main()
{
	Plus p;

	foo(p);
}
