#include <iostream>
using namespace std;

void refution(int a);

int main()
{
	cout<<"开始"<<endl;
	refution(2);
	return 0;
}

void refution(int a)
{
	cout<<"我是"<<endl;
	if (!a)
	{
		cout<<"你是"<<endl;
	}else{
		refution(--a);
	}
	cout<<"结束"<<endl;
}

// int main()
// {
// 
// 	int i=0,m=5;
// 	for (i=0;i<m;i++)
// 	{
// 		cout<<i<<endl;
// 		m -= 1;
// 	}
// 	return 0;
// }