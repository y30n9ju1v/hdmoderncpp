// chronometry1.cpp
#include <functional>

class Dialog
{
public:
	void init(int a, double d) {}
};

void foo(int a, double d) {}

// 가변인자템플릿7 에서 chronometry 복사 하세요
template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
	// StopWatch sw(true);
	return std::invoke(std::forward<F>(f), std::forward<Types>(args)...);
}

int main()
{
	Dialog dlg;

	chronometry(foo, 1, 3.4);
	chronometry(&Dialog::init, dlg, 1, 3.4);
}