// 58 page
class Vector
{
	int sz;
public:
	// explicit ������ : ���� �ʱ�ȭ�� ����Ҽ� ����
	//					���� �ʱ�ȭ�� �����ϴ�.!
	//					����, ��ȯ�� �뵵�ε� ����Ҽ� ����.
	//					C++98 ����
	explicit Vector(int s) : sz(s) {}
};

// �Լ��� ���� ������ ���� �ʱ�ȭ �Դϴ�.
void foo(Vector v) {}	// Vector v = 10	
						// Vector v = {10}	
						// Vector v = v1  �̹Ƿ� ���� ������
						//		����Ʈ ���� �����ڴ� explicit �ƴ�.
int main()
{
	// �ٽ� 1. ���ڰ� �Ѱ��� �����ڰ� ������ �Ʒ��� ǥ����� �����մϴ�.
	Vector v1(10);		// C++98. direct initialization
	Vector v2 = 10;		// C++98. copy   initialization

	Vector v3{ 10 };	// C++11. direct initialization
	Vector v4 = { 10 };	// C++11. copy   initialization

	//----------------
	foo(10);		// explicit �� ��� ����
	foo( { 10 } );	// C++11 ���� ���ڵ嵵 ����, explicit �� ��� ����
	foo(v1);  // ok
}







