int main()
{
	int  n1 = 3.4; // ok. ���� �߻�. ���� �ڵ�
	char c1 = 500; // ���� �÷ο�. 

	// prevent narrow - 56 page �߰��κ�
	// {} �ʱ�ȭ�� ���� �մϴ�.
	int n2{ 3.4 };  // error
	char c2{ 500 }; // error. 

	int n3 = { 3.4 }; // error

}