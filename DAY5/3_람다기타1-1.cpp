class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const
	{
		return a + b;
	}

	static inline int helper(int a, int b)
	{
		return a + b;
	}

	using FP = int(*)(int, int);
	operator FP() { return &CompilerGeneratedName::helper; }
};


int main()
{
	int v1 = 0;

	int(*f1)(int, int) = [v1](int a, int b) {return a + b + v1; };


	int(*f2)(int, int) = CompilerGeneratedName();




}












