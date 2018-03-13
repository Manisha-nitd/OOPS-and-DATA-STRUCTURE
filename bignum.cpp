#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
string multip(string s,char n)
{
	string sr="";int sum=0,carry=0;
	for(int i=s.length()-1;i>=0;i--){
		sum=((s[i]-'0')*(n-'0'))+carry;
		sr=char(sum%10+'0')+sr;
		carry=sum/10;
	}
	while(carry){
		sr=char(carry%10+'0')+sr;
		carry/=10;
	}
	return sr;
}
//to put 0 at the end of any multiplication.
string multiplyby(string s,int n){
	int t=s.length();
	for(int i=0;i<n;i++)
	s+="0";
	return s;
}
//to add to string
string addon(string s1,string s2){
	string s="";int sum=0,carry=0;
	for(int i=s1.length()-1;i>=0;i--){
		int sum=carry+s1[i]+s2[i]-'0'-'0';
		int x=sum%10;char t=x+'0';
		s=t+s;
		carry=sum/10;
	}
	while(carry){
		char v=carry%10+'0';
		s=v+s;
		carry/=10;
	}
	return s;
}
//main function to multiply two string
string mul(string s1,string s2){
	int l=s1.length();
	if(l<s2.length())
	l=s2.length();
	for(int i=s1.length();i<l;i++)
	s1='0'+s1;
	for(int i=s2.length();i<l;i++)
	s2='0'+s2;
	string s[l],sf;
	for(int i=0;i<l;i++){
		s[i]=multip(s1,s2[i]);
		s[i]=multiplyby(s[i],l-i-1);
		if(i>0){
			for(int j=s[i-1].length();j<s[i].length();j++)
			s[i-1]='0'+s[i-1];
			for(int j=s[i].length();j<s[i-1].length();j++)
			s[i]='0'+s[i];
		}
	}
	for(int i=sf.length();i<s[0].length();i++)
	sf='0'+sf;
	for(int i=0;i<l;i++){
		sf=addon(sf,s[i]);
	}
	bool flag=false;string srf="";
	for(int i=0;i<sf.length();i++){
		//to emit per zero of string
		if(sf[i]=='0'&&flag==false&&i!=sf.length()-1)continue;
		srf+=sf[i];
		flag=true;
	}
	return srf;
}
void add(string num1,string num2)
{
    int i,carry=0,k=0,l1,l2,j;
    int sum[1000];
    for(i=0;i<num1.length();i++)
    {
        num1[i]=num1[i]-'0';
    }
    for(i=0;i<num2.length();i++)
    {
        num2[i]=num2[i]-'0';
    }
    l1=num1.length();
    l2=num2.length();
    i=l1-1;
    j=l2-1;
for (; i >= 0 && j >= 0; i--, j--, k++) {
sum[k] = (num1[i] + num2[j] + carry) % 10;
carry = (num1[i] + num2[j] + carry) / 10;
}
if (l1 > l2) {

while (i >= 0) {
sum[k++] = (num1[i] + carry) % 10;
carry = (num1[i--] + carry) / 10;
}

} else if (l1 < l2) {
while (j >= 0) {
sum[k++] = (num2[j] + carry) % 10;
carry = (num2[j--] + carry) / 10;
}
} else {
if (carry > 0)
sum[k++] = carry;
}


cout<<"Result :"<<endl;
for (k--; k >= 0; k--)
cout<<sum[k];

}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }

    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
void factorial(long int n)
{
    int res[100000];
    res[0] = 1;
    int res_size = 1;

    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}

int main()
{
    long int num;
    string a,b;
    char ch;
    int o;
    do
    {
        cout<<"Enter the option for the following operation :"<<endl;
        cout<<"1.Addition"<<endl<<"2.Multiplication"<<endl<<"3.Factorial"<<endl;
        cin>>o;
        switch(o)
        {
        case 1:
            cout<<"Enter the first number :"<<endl;
            cin>>a;
            cout<<"Enter the second number :"<<endl;
            cin>>b;
            add(a,b);
            break;
        case 2:
            cout<<"Enter the first number :"<<endl;
            cin>>a;
            cout<<"Enter the second number :"<<endl;
            cin>>b;
            cout<<mul(a,b);
            break;
        case 3:
             cout<<"Enter the number :(less than 25000)"<<endl;
             cin>>num;
             factorial(num);
            break;
        default:
            cout<<"Wrong Choice !!"<<endl;
        }
        cout<<endl<<"Want some other operations?? Enter (y/Y)"<<endl;
        cin>>ch;
   } while(ch=='y'||ch=='Y');
return 0;
}
