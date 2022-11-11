int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										    a   = std::move(b); 
										    b   = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	// �Ʒ� �ڵ�� �Ǵ°� ������� ? �ȵǴ°� ������� ?
	swap(n, d); // error �� �߻��ϴ� ���� �����ϴ�.
				// �׷���, ������ �ƴմϴ�.

	// swap ���� ���� ���鶧�� 2���� ���ڰ� "���� Ÿ��" �̾�� �Ѵٴ�
	// ������ ������ �����ϴ�.

	// �׷��� "C++20" ���� template lambda �� ��������ϴ�
	// C++14 : generic  lambda. ���ڷ� auto
	// C++20 : template lambda. ���ڷ� template

	auto swap2 = []<typename T>(T& a, T& b) { auto tmp = std::move(a);
												a = std::move(b);
												b = std::move(tmp); };

}