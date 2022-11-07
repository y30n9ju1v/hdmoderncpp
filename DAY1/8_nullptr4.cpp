#include <iostream>

// nullptr �� ����

void f1(int* p) {}
void f2(char* p) {}

// nullptr�� ����
// 1. boost ���̺귯������ �Ʒ� ó�� ���� ����߽��ϴ�.
//    => �̴�� nullptr �� nullptr_t Ÿ���� ��ü �����ϴ�.

// 2. C++11 ���鶧 ǥ�ؿ� ����
//   => ���� "nullptr" �� Ű���� �Դϴ�.
//   => Ÿ���� "std::nullptr_t" Ÿ��


struct mynullptr_t
{
	// ��ȯ ������ �Լ� : ��ü�� �ٸ� Ÿ������ ��ȯ�Ƿ��� �Ҷ� ȣ��.
//	operator int* () const { return 0; }
//	operator char* () const { return 0; }

	// �Ʒ� ��� �Լ� ���п� mynullptr_t �� ��� Ÿ���� �����ͷ� 
	// �Ͻ��� ����ȯ �����մϴ�.
	template<typename T>
	operator T* () const { return 0; }
};
mynullptr_t mynullptr;


int main()
{
	f1(mynullptr);	// nullptr_t => int*���� �Ͻ��� ����ȯ �ʿ�
					// "mynullptr.operator int*()" ��� �Լ� ȣ��
	f2(mynullptr);
}
