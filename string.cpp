#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	string a,b;
	int vowel=0,cons=0;
	int len;
	char p;
	cout<<"Enter the string :";
	getline(cin,a);
	len=a.length();
    do
    {
        cout<<"Enter your option :"<<endl;
        cout<<"1.Reverse"<<endl;
        cout<<"2.Counting vowel and consonant"<<endl;
        cout<<"3.Toggle the character "<<endl;
	    int o;
	    cin>>o;
	    switch(o)
	    {
        case 1:
        cout<<"The reversed string is :"<<endl;
        for(int i=a.length()-1;i>=0;i--)
        {
            cout<<a[i];
        }
        break;
        case 2:
        for(int i=0;i<len;i++)
        {
            if(isalpha(a[i]))
                {
                    if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
                    vowel++;
                    else
                    cons++;
                }
        }
        cout<<"The number of vowel is :";
        cout<<vowel<<endl;
        cout<<"The number of consonant :";
        cout<<cons<<endl;
        break;

        case 3:
        for(int i=0;i<a.length();i++)
        {
            if(isalpha(a[i]))
            {
                if(islower(a[i]))
                cout<<(char)toupper(a[i]);
                else
                cout<<(char)tolower(a[i]);
            }
            else
            cout<<a[i];
        }
        break;
        default:
        cout<<"Invalid Choice !";
	}
cout<<endl<<"Want some other operation ? Enter y/Y:"<<endl;
cin>>p;
}while(p=='y'||p=='Y');
cout<<"Thank you for visiting!!";
return 0;
}

