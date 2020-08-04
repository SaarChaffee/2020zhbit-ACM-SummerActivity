#include<bits/stdc++.h>
using namespace std;
#pragma execution_character_set("utf-8")
int main(){
	freopen("in.txt","w",stdout);
	char a='a';
	char A='A';
	for(int i=0;i<26;++i){
//		cout<<",\'"<<a<<"\'"<<",\'"<<A<<"\'";
//		cout<<",'"<<a<<"'"<<",'"<<A<<"'";
		printf("'%c'",a);
		putchar(',');
		printf("'%c'",A);
		putchar(',');
//		fflush(stdout);
//		cout<<a<<A;
		a++;A++;
	}
	return 0;
}
