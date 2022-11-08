// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}
	// C++17 의 새로운 제어문
	// => 초기화 구문을 가지는 if 문
	// => if ( init; condition) 

	if (int ret2 = foo(); ret2 == 0)
	{
	} // <= ret2 파괴. 

	// switch 도 가능합니다.
	switch (int n = foo(); n)
	{
	case 0: break;
	case 1: break;
	}

	// while 도 될까요 ?
	// => 안됩니다.
	// => 필요없습니다. for 문사용하면 됩니다.
	/*
	while (int cnt = 0; cnt < 10) 
	{
		++cnt;
	}
	*/
}




// github.com/codenuri/hdmoderncpp   에서 DAY2.zip 받으시면 됩니다.
// VC 에서 열고 버전 설정해 주세요.

