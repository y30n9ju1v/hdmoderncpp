// "3_���ٱ�Ÿ3" => 3-1 �� �����ϰ�
// "3_���ٱ�Ÿ3" �ٽ� ���弼��

int main()
{
	auto f1 = [](int a, int b) { return a + b; };


	decltype(f1) f2;
	decltype(f1) f3 = f1;
}