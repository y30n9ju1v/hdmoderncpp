// 7_�����������ø�1 - 225 page


// �ٽ� : �������� Ŭ���� ���ø� ��� �˾� �μ���
//       "T" �� �ƴ� ������ ���� ǥ���ϴ� ���� ���� �Դϴ�.

// �������� Ŭ���� ���ø�
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<int> t1; // ok		// Types : int
	tuple<int, int> t2;			// Types : int, int
	tuple<int, int, double> t3;	// Types : int, int, double
}