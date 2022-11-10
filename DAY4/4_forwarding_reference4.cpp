int main()
{
	int n = 10;

	auto a1 = n;	// ok. int a1 = n;  
	auto a2 = 10;	// ok. int a2 = 10;

	auto& a3 = n;	// ok.		int& a3 = n;
	auto& a4 = 10;	// error.	int& a4 = 10; �� ����

	const auto& a5 = n;	// ok	const int& a5 = n;
	const auto& a6 = 10;// ok	const int& a6 = 10;

	// �ٽ� : �Ʒ� �ڵ�� 
	// 1. "rvalue reference" �ϱ�� ?
	// 2. "forwording reference" �ϱ�� ?	 => ����
	auto&& a7 = n;	// ok. int& a7 = n
	auto&& a8 = 10;	// ok. int&& a8 = 10;
}