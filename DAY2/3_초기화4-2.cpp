
// std::cin �� istream Ŭ������ ��ü �Դϴ�.
// (��Ȯ���� basic_istream)
class istream
{
public:
	bool fail() { return false; } // �Է½��п� ���� �����ȯ
};
istream cin;

int main()
{
	int n = 0;

	if (cin) {}
}
