// 7_가변인자템플릿1 - 225 page


// 핵심 : 가변인자 클래스 템플릿 모양 알아 두세요
//       "T" 가 아닌 복수형 으로 표기하는 것이 관례 입니다.

// 가변인자 클래스 템플릿
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<int> t1; // ok		// Types : int
	tuple<int, int> t2;			// Types : int, int
	tuple<int, int, double> t3;	// Types : int, int, double
}