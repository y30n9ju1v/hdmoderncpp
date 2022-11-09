#include <iostream>
#include <vector>
#include <string>

template<typename T>
class Object
{
	int id;
	std::string name;
	T data;

public:
	Object() {}


	Object(const Object&)
	{
		std::cout << "copy" << std::endl;
	}
	// move 생성자에서는 모든 멤버를 "std::move()" 로 옮겨라!
	// 아래 코드에서 "noexcept" 를 어떻게 해야 할까요 ?
	Object(Object&& other) noexcept 
		: id(other.id), 
		  name(std::move(other.name)),
		  data(std::move(other.data))
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; 
	Object o3 = std::move(o1); 
	Object o4 = std::move_if_noexcept(o2);

}

