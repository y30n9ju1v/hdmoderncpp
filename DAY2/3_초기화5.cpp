#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	// �Ʒ� �ڵ��� ������ ã�� ������.
//	goo(10);	// �ȵǴ� �� �����ϴ�.
				// ������ ����� error �Դϴ�.

	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error
								// "explicit vector(int)" ��� �ǹ�

	hoo("hello");	// �Ǵ°� �����ϴ�.
					// ������ ����� ok �Դϴ�.

	std::string s1("hello");	// ok
	std::string s2 = "hello";	// ok
		// "string(const char*)" �� explicit �� �ƴ϶�� �ǹ��Դϴ�.




}





