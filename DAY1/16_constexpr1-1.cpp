// 16_constexpr1-1
int main()
{
	int n = 10;

	// C++98 const
	const int c1 = 10; // ok. ������ �ð� ����� �ǰ�
	const int c2 = n;  // ok. ����ð� ���(������ �ʱ�ȭ)�� ����

	// C++11 constexpr 
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error
}