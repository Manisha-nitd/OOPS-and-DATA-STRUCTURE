#include<iostream>
#include<fstream>
using namespace std;
//using namespace ios;

//give command arguements in the format::   <executable_file> <.txt_file_directory>
int main(int argc, char *argv[])
{
	if(argc!=2)
	{
	 cout<<"\nformat: <executable file> <.txt file directory>\n";
	 return -1;
	}
	ifstream f1;
	ofstream f2;
	char *filedir=argv[1];
	f1.open(filedir, ios::in);
	f2.open("indented_file.txt",ios::out);
	string s;
	int t=0;
	while(!f1.eof())
	{
		getline(f1,s);
		if(s[0]!='{' && s[0]!='}')
		{
			for(int i=0;i<t;i++)
				f2<<"\t";
			f2<<s<<"\n";
		}
		else if(s[0]=='{')
		{
			for(int i=0;i<t;i++)
				f2<<"\t";
			f2<<"{\n";
			t++;
		}
		else if(s[0]=='}')
		{
			if(t>0)
				t--;
			for(int i=0;i<t;i++)
				f2<<"\t";
			f2<<"}\n";
		}
	}

	f1.close();
	f2.close();
	return 0;
}
