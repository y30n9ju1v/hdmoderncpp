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
	int s = Factorial(5);

	int arr1[Factorial(5)]; 

	int arr2[Factorial(n)]; 
						
	int s2 = Factorial(n); 
}