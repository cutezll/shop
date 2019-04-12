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
	int m_flag; //不同的flag表示不同的错误
	int m_len;  //当前数组的长度
	int m_index;  //当前使用的数组下标
};