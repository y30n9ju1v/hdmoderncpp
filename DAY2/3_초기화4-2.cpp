
void true_function() {} // �ּҸ� ����Ϸ��� ���� �Լ��Դϴ�.

// std::cin �� istream Ŭ������ ��ü �Դϴ�.
// (��Ȯ���� basic_istream)
class istream
{
	struct dummy
	{
		void true_function() {}
	};
public:
	bool fail() { return false; } // �Է½��п� ���� �����ȯ

	// ��� 1. operator bool() ��ȯ �����ڸ� ��������
	// ���� : "cin << n" �� �ڵ尡 ������ ����!!
	// operator bool() { return fail() ? false : true; }

	// ��� 2. void* ���� ��ȯ
	// => this �� ��ȯ�ϴ� ���� Ư���� ���� �����ϴ�. �׳� 0�� �ƴϸ�˴ϴ�.
	// => C++98 ǥ��. cin �� void* ���� ��ȯ �����մϴ�.
	// => ���� : delete cin �� ������ �ƴϴ�. 
	// operator void* () { return fail() ? 0 : this; }

	// ��� 3. �Լ� �����ͷ��� ��ȯ 
	// => "delete �Լ� ������" �� ������ �����̴�.
//	typedef void(*PF)();
//	operator PF() { return fail() ? 0 : &true_function; }

	// ��� 4. ��� �Լ� �����ͷ��� ��ȯ
	// => boost ���̺귯���� ����ϴ� ���
	// => C++ ����������� "safe bool" �̶�� ���� �˷��� ���
	typedef void(dummy::*PF)(); // ��� �Լ� ������ Ÿ��!

	operator PF() { return fail() ? 0 : &dummy::true_function; }
};
istream cin;

int main()
{
	int n = 0;

	if (cin) {}
//	cin << n;   // ?? �� ������.. �߸��� �ڵ��Դϴ�. << �ƴ϶� >> �Դϴ�.
//	delete cin; // boost ���̺귯�� ���� ������ C++98 ǥ���� ������

//	void(*p)() = cin; // �̰͵� �ȵǰ� �ϴ°� ���� ������ ?
}
