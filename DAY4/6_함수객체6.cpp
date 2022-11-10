#include <iostream>
#include <algorithm>
#include <string>

// �Լ� ��ü ���� 3. ADL ��Ģ�� ������� �ʴ´�.
//				=> ���� ���ٴ� Ư¡!

// ADL : Argument Dependent Lookup
// => �Լ��� ã���� ���ڰ� ���� namespace �� �ڵ��˻� �ȴ�.

int main()
{
//	int ret1 = max(1, 2);		// error. max �� 
								// "std::" �ȿ� �ֽ��ϴ�.
	int ret2 = std::max(1, 2);	// ok. 

	std::string s1 = "a";
	std::string s2 = "n";

	auto ret3 = max(s1, s2); // ��.. ������ ������� ?
}