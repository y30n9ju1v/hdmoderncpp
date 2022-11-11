// 3_���ٱ�Ÿ3-3
#include <memory>
#include <set>

int main()
{
	// STL �� ���� Ŭ������ ���ø� ���ڷ� �Լ� ��ü�� �䱸 �մϴ�.
	// �̶� �Լ� ��ü�� ���� ������ ����,
	// ���ٸ� ����ϰ� ������

	// �Ʒ� �ڵ尡 "effective modern C++" ���� �����ϴ� �ڵ��Դϴ�.
	auto deleter = [](void* p) { free(p); };

	std::unique_ptr<int, decltype(deleter)> up((int*)malloc(100),
													deleter);

	// �׷���, C++20 ���ʹ�
	// 1. ����ǥ������ �򰡵��� ���� ǥ���Ŀ� ��� ���� �ְ�
	// 2. ����ǥ������ ����� Ÿ�Կ� ����Ʈ �����ڰ� �ֽ��ϴ�.(ĸ������ ������)


	std::unique_ptr<int, decltype([](void* p) { free(p); })> 
								up2((int*)malloc(100));
}