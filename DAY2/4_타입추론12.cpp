template<typename T> void f1(T a, T b)
{
}
template<typename T> void f2(T& a, T& b)
{
}

int main()
{
	// "orange" Ÿ�� : const char[7]
	// "apple"  Ÿ�� : const char[6]
	// ��, "orange", "apple"�� �ٸ� Ÿ���Դϴ�

	f1("orange", "apple"); // ok
			// => �迭�� "�� Ÿ��(T a)�� �ް� �����Ƿ� �����ͷ� ����"
			//	  �Ǿ ���� �˴ϴ�.
			// "orange" Ÿ�� : const char[7] => const char*
			// "apple"  Ÿ�� : const char[6] => const char*

	f2("orange", "apple"); // error. �� �����ϱ�� ?
			// => �迭�� �״�� ����
			// => ���� Ÿ���� �䱸�ϴµ� �ٸ� Ÿ�� �Դϴ�.
	f2("orange", "banana"); // ok
}

// decay ���� : �迭�� ������ "������"�� ����Ǿ� �ް� �Ǵ�����