
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
	if (cin) {}
}
