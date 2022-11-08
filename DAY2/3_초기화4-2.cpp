
// std::cin 은 istream 클래스의 객체 입니다.
// (정확히는 basic_istream)
class istream
{
public:
	bool fail() { return false; } // 입력실패에 따라 결과반환
};
istream cin;

int main()
{
	int n = 0;

	if (cin) {}
}
