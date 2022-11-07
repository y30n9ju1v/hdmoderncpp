// enum2.cpp �� �Ʒ� �ڵ�� �����ϼ���

//enum     DAYOFWEEK { sum = 0, mon = 1 };	// C++98 unscoped enum
enum class DAYOFWEEK { sum = 0, mon = 1 };	// C++11 scoped enum

//void foo(int dayofaweek) {}	// ���ϻ� �ƴ϶� 100,200��
								// �߸��� ���� �ɼ� �ִ�.

void foo(DAYOFWEEK dayofweek) {}// ���ϸ� ������ �ִ�.

int main()
{
//	int n1 = mon;			// error.  
							// "DAYOFWEEK::mon" �� ����ؾ� �մϴ�.
//	int n2 = DAYOFWEEK::mon;// error. 
							// int Ÿ���� �ƴ϶� "DAYOFWEEK" Ÿ��

	DAYOFWEEK n3 = DAYOFWEEK::mon; // ok. 

	foo(DAYOFWEEK::mon);
}





