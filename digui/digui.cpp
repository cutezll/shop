#include <iostream>
using namespace std;

void refution(int a);

int main()
{
	cout<<"��ʼ"<<endl;
	refution(2);
	return 0;
}

void refution(int a)
{
	cout<<"����"<<endl;
	if (!a)
	{
		cout<<"����"<<endl;
	}else{
		refution(--a);
	}
	cout<<"����"<<endl;
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