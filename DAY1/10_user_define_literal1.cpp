
class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

// 34 page ����
// operator"" �Լ��� ����Ÿ���� ��ӵǾ� �ֽ��ϴ�.
Meter operator""m(unsigned long long n)
{
	Meter m( static_cast<int>(n) );
	return m;
}

int main()
{
	double d = 3.4; // "3.4" �� double Ÿ�� �Դϴ�.
	float f = 3.4f; // "3.4f" �� float Ÿ�� �Դϴ�.

	Meter me = 3m;	// operator""m(3) �� ã�� �˴ϴ�.

//	Gram  g = 3g;
}




