// 5_����ǥ����6
// ����ǥ������ ���ڸ� �޴� ��� - 143p �Ʒ� �κ�


// ��� 1. �Լ� ������ ���
// ���� 1. ���������� ĸ���� ���� ǥ������ ������ ����.
//     2. f(1,2) �ڵ尡 �ζ��� ġȯ�ɼ� ����.
//void foo(int(*f)(int, int))
//{
//	int ret = f(1, 2);
//}

// ��� 2. ��� ���� ǥ������ �ᱹ �ٸ� Ÿ���̴�.
//        ���ø� ��� - call by value
// ĸ������ ���� ���� ǥ������ "empty class" �̴�. sizeof(empty)�� 1����Ʈ
// ������, ���� �����ڵ� �ϴ����� ����.
// "call by value" �� ������ �ʴ�
// std::find_if( first, last, T f) �� �Ǿ� �ִ�.
/*
template<typename T> void foo(T f)
{
	auto ret = f(1, 2);
}
*/
// ��� 3. call by reference
// => ����ǥ������ "�ӽð�ü" �Դϴ�.
// => rvalue �̹Ƿ� �Ʒ� �Լ��� ����ǥ������ ������ �����ϴ�.
/*
template<typename T> void foo(T& f)
{
	auto ret = f(1, 2);
}
*/
// ��� 4. call by const reference 
// => "operator()" �� �ݵ�� ��� ��� �Լ� �̾�߸� ��밡���մϴ�
// => mutable ���ٸ� ����Ҽ� �����ϴ�.
/*
template<typename T> void foo(const T& f)
{
	auto ret = f(1, 2);
}
*/
// ��� 5. forwarding reference
// => ���� ���.. ���¼ҽ����� ���� ���� �ֽ��ϴ�.
// => ����ǥ���� �� �ƴ϶�, ũ�Ⱑ ū(�������Ÿ�� ����) �Լ� ��ü�� ���
//    call by value ���� �����ϴ�
template<typename T> void foo(T&& f)
{
	auto ret = f(1, 2);
}


int main()
{
	foo([](int a, int b) { return a + b; });
	foo([](int a, int b) { return a - b; });
}


