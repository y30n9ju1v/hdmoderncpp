// chronometry1.cpp

class Dialog 
{
public:
	void init(int a, double d) {}
};

void foo(int a, double d) {}

int main()
{
	void(*f1)(int, double) = &foo;
	void(*f2)(int, double) = &Dialog::init;
}