#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{

	int i,n,k,;
	vector<int> m;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		m.push_back(k);
	}
	cout<<"m.size="<<m.size()<<endl;
	for (i=0;i<m.size();i++)
	{
		cout<<m[i]<<endl;
	}
	return 0;
}