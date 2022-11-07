#include <unordered_set>

// std::unordered_set<int> 의 별명을 만들고 싶다.
typedef std::unordered_set<int>    SETI;
typedef std::unordered_set<double> SETD;

// 아래처럼 별명을 만들수 없을까 ?
// "타입"이 아닌 "템플릿"의 별명
//typedef std::unordered_set   SET;	// error.
									// typedef 는
									// "타입"의 별명만 가능하다

template<typename T>
using SET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;

	SETI s1;
	SETD s2;

	SET<int> s3; // std::unordered_set<int>
}
// 핵심
// typedef : 타입에 대한 별명만 만들수 있다.
// using   : 타입에 대한 별명 + 템플릿에 대한 별명