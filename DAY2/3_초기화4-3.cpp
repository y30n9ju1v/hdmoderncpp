class istream
{
public:
	bool fail() { return false; } // �Է½��п� ���� �����ȯ

	// C++98 : �����ڿ��� explicit �� ���ϼ� �ֽ��ϴ�.
	// C++11 : ��ȯ�����ڿ��� explicit �� ���ϼ� �ֽ��ϴ�.
	//         => �Ͻ��� ��ȯ�� �ȵǰ� ����� ��ȯ�� �ȴ�.
	explicit operator bool() { return fail() ? false : true; }
};
istream cin;

int main()
{
	int n = 0;

//	bool b1 = cin; // error �Ͻ��� ��ȯ
	bool b2 = static_cast<bool>(cin); // ok. ����� ��ȯ

//	cin << n;	// error. cin �� ����(bool)�� �Ͻ��� ��ȯ�� �Ǹ� �Ǵµ�
				//		  ������ ����� ��ȯ�� �ȴ�.

	if (cin) {}	// if �� �ȿ����� �ڵ����� ����� ��ȯ���� ��ȯ �ɼ�
				// �ִٴ� C++ ������ �߰� �Ǿ����ϴ�.

	// ��� : cin �� ��ȯ �̾߱�
	// C++98 : cin.operator void*() ����
	// C++11 : cin.operator bool() ����. ��, explicit

	// ����. nullptr(std::nullptr_t) ��
	//       bool ���� ����� ��ȯ�� �����մϴ�.
//	bool b3 = nullptr; // error
	bool b4 = static_cast<bool>(nullptr); // ok

	if (nullptr) {} // 
}
