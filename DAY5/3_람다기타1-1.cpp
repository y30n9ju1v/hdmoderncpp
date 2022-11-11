class CompilerGeneratedName
{
	int v1;
public:
	CompilerGeneratedName(int a) : v1(a) {}

	inline int operator()(int a, int b) const
	{
		return a + b + v1; // ok~~~~
	}

	// ���������� ĸ���� ���� ǥ������
	// �Լ� �����ͷ��� ��ȯ�� ���� �Ʒ� �Լ��� ����� �����ϴ�!!
	// => �׷��� �Լ� �����ͷ� ��ȯ �ɼ� �����ϴ�.
	/*
	static inline int helper(int a, int b)
	{
		return a + b + v1; // error.
						// static ��� �Լ��� �������Ÿ ���� �ȵ�.
	}

	using FP = int(*)(int, int);
	operator FP() { return &CompilerGeneratedName::helper; }
	*/
};


int main()
{
	int v1 = 0;
	// ���������� ĸ���� ���� ǥ���İ� �Լ� ������!
	int(*f1)(int, int) = [v1](int a, int b) {return a + b + v1; };
//	int(*f2)(int, int) = CompilerGeneratedName(v1);

}












