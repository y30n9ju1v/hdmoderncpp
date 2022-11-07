// constexpr �� 3���� ���� �Դϴ�.
// 1. constexpr ��� - C++11
// 2. constexpr �Լ� - C++11  !!
// 3. constexpr if  - C++17


// constexpr �Լ�
// => ���� ���� ������ �ð��� �˰�
//    �Լ� ȣ���� ���Ǵ� ǥ������ ������ �ð��� ���� �˾ƾ� �Ѵٸ�
//    �Լ� ������ ������ �ð��� ����

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)]; // ������ �ϸ� "int arr1[120]"			
							// ��, �Լ��� ������ ������ �Ҷ� ����

	int arr2[Factorial(n)];	// error. 
							// ���ڰ��� ������ �Ҷ� �˼� ����.
						
	int s2 = Factorial(n);	// ok. �����Ҷ� �Լ� ȣ��


	int s = Factorial(5);	// �����Ͻð��� �Ҽ��� �ְ� ����ð��� ȣ���Ҽ���
							// �ֽ��ϴ�. 
							// �����Ϸ����� �ٸ�
	const int s3 = Factorial(5); // �����Ϸ����� �ٸ�

	constexpr int s4 = Factorial(5); //�ݵ�� ������ �Ҷ� �ش޶�.

}