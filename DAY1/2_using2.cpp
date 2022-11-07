#include <unordered_set>

// std::unordered_set<int> �� ������ ����� �ʹ�.
typedef std::unordered_set<int>    SETI;
typedef std::unordered_set<double> SETD;

// �Ʒ�ó�� ������ ����� ������ ?
// "Ÿ��"�� �ƴ� "���ø�"�� ����
//typedef std::unordered_set   SET;	// error.
									// typedef ��
									// "Ÿ��"�� ���� �����ϴ�

template<typename T>
using SET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;

	SETI s1;
	SETD s2;

	SET<int> s3; // std::unordered_set<int>
}
// �ٽ�
// typedef : Ÿ�Կ� ���� ���� ����� �ִ�.
// using   : Ÿ�Կ� ���� ���� + ���ø��� ���� ����