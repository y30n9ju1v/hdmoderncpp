class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const 
	{ 
		return a + b; 
	}

	// �Լ������ͷ��� ��ȯ�� ���� ��ȯ ������
	using FP = int(*)(int, int);

	operator FP() { return �Լ� �ּ�; }
};


int main()
{
	int(*f2)(int, int) = CompilerGeneratedName();
						// �ӽð�ü.operator �Լ�������();


	// ���� ǥ������ "�Լ� ������"�� ��ȯ �����մϴ�.
	int(*f1)(int, int) = [](int a, int b) {return a + b; };
						// class xxx{}; xxx();
			
}












