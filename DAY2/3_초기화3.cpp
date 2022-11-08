int main()
{
	int  n1 = 3.4; // ok. 경고는 발생. 나쁜 코드
	char c1 = 500; // 오버 플로우. 

	// prevent narrow - 56 page 중간부분
	// {} 초기화는 엄격 합니다.
	int n2{ 3.4 };  // error
	char c2{ 500 }; // error. 

	int n3 = { 3.4 }; // error

}