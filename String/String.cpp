#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
	string str="asdfghjkl";
	char ch[] = "123456";
	string a;
	string str_1(str);
	string str_2(str,2,5);
//	string str_3(str,5);
	string str_4(ch,5);
	string str_5(str.begin(),str.end());
	string str_6(5,'C');
	cout<<"sizeof(str)="<<sizeof(str)<<"str.size()="<<str.size()<<"str.length()="<<str.length()<<endl;
	cout<<"sizeof(ch)="<<sizeof(ch)<<endl;
	cout<<a<<endl;
	cout<<str_1<<endl;
	cout<<str_2<<endl;
//	cout<<str_3<<endl;
	cout<<str_4<<endl;
	cout<<str_5<<endl;
	cout<<str_6<<endl;


	char & r=str[2];
	char* p=&str[3];
	cout<<"r="<<r<<"  "<<"*p="<<*p<<"  "<<"p="<<p<<endl;
	cout<<str[str.length()-1]<<endl;
	cout<<str.at(7)<<endl;
	return 0;
}
#endif

#if 0
int main()
{
	string A("123456");
	string B="H";
	B.insert(1,A);
	cout<<B<<endl;   //H123456
	A="0123456";
	B="mem";
	B.insert(0,A,2,2);//23mem
	cout<<B<<endl;
	A="0123456";
	B="mem";
	B.insert (1,"yanchy ",3,2);//mchem
	cout<< B <<endl;
	B="mem";
	B.insert (1,"yanchy ",3);//myanem
	cout<< B <<endl;
	A="123456";
	B="iterator";
	string::iterator it = B.begin () +1;
	const string:: iterator itF = A.begin();
	const string:: iterator itG = A.end();
	B.insert(it,itF,itG);
	cout<<B<<endl;
	return 0;
}
#endif

int main ()
{
    string var ("abcdefghijklmn");
    const string dest ("1234");
    string dest2 ("567891234");
    var.replace (3,3, dest);
    cout << "1: " << var << endl;
    var = "abcdefghijklmn";
    var.replace (3,1, dest.c_str(), 1, 3);
    cout << "2: " << var << endl;
    var ="abcdefghijklmn";
    var.replace (3, 1, 5, 'x');
    cout << "3: " << var << endl;
    string::iterator itA, itB;
    string::iterator itC, itD;
    itA = var.begin();
    itB = var.end();
    var = "abcdefghijklmn";
    var.replace (itA, itB, dest);
    cout << "4: " << var << endl;
    itA = var.begin ();
    itB = var.end();
    itC = dest2.begin () +1;
    itD = dest2.end ();
    var = "abodefghijklmn";
    var.replace (itA, itB, itC, itD);
    cout << "5: " << var << endl;
    var = "abcdefghijklmn";
    var.replace (3, 1, dest.c_str(), 4); //这种方式会限定字符串替换的最大长度
    cout <<"6: " << var << endl;
	cout<<var[3]<<endl;
    return 0;
}