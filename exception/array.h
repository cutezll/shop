#include <iostream>
#include <cstdlib>
using namespace std;

class OutOfRange
{
public:
	OutOfRange();
	OutOfRange(int len,int index);
public:
	void what();
private:
	int m_flag; //��ͬ��flag��ʾ��ͬ�Ĵ���
	int m_len;  //��ǰ����ĳ���
	int m_index;  //��ǰʹ�õ������±�
};