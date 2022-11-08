// ������ȯ - 73 page �Ʒ� �κ�
#include <iostream>

/*
// �Ʒ� �ڵ忡�� ��ȯ Ÿ���� ��� ǥ���ؾ� �ұ� ?
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// ��� 1. auto ���
// => return "ǥ����" �� ���� Ÿ���� ������ �޶�� �ǹ�. 
// Ư¡ 1 : return ������ ������ �ִٸ� �߷� �Ҽ� ����.
// Ư¡ 2 : return "ǥ����" �� ����� ���� Ÿ���� ��쿡��
//         auto �� ������ ������ �����ϹǷ� "��" Ÿ������ ��ȯ
/*
template<typename T1, typename T2>
auto Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// ��� 2. decltype(auto) ��ȯ
// Ư¡ 1. return ���� ������ ������ �߷еɼ� ����.
// Ư¡ 2. return "ǥ����" �� ����� �״�� ��ȯ Ÿ������ ���
//        ǥ������ ����� ���� ��� ���� ��ȯ
/*
template<typename T1, typename T2>
decltype(auto) Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// ��� 3. ��ȯ Ÿ���� ���� ǥ��
// => return ���� ������ �� �������� ����� �ǵ�
// => �׷���, �Ʒ� �ڵ�� a, b�� �������� ����ϰ� �����Ƿ� ������ ����
/*
template<typename T1, typename T2>
decltype(a * b) Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// ��� 4. C++11���� �߰��� "���� ��ȯ Ÿ�� ǥ���" ���
// => auto add(int a, int b) -> int {return a + b;}

// Ư¡ : return ���� ������ �־ �����Ϸ��� "decltype(a* b)" �� 
//       Ÿ�� �߷�
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}



int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

