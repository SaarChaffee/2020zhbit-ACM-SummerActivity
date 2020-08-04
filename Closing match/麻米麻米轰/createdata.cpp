#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int N=62;
const int maxlen=10000;
const char dest[N]={
'0','1','2','3','4','5','6','7','8','9',
'a','A','b','B','c','C','d','D','e','E',
'f','F','g','G','h','H','i','I','j','J',
'k','K','l','L','m','M','n','N','o','O',
'p','P','q','Q','r','R','s','S','t','T',
'u','U','v','V','w','W','x','X','y','Y',
'z','Z'
};

int main(){
	int n=60,index;
	char tmp;
	freopen("in.txt","w",stdout);
	while(n--){
		int len=(rnd()%maxlen)+1;
		cout<<len<<" "<<len<<endl;
		stringstream ss;
		for(int i=0;i<len;++i){
			ss.put(dest[rnd()%N]);
		}
		string s=ss.str();
		cout<<s<<endl;
		for(int i=0;i<len;++i){
			index=rnd()%len;
			tmp=s[i];
			s[i]=s[index];
			s[index]=tmp;
		}
		cout<<s<<endl;
	}
	n=60;
	while(n--){
		int len=(rnd()%maxlen)+1;
		cout<<len<<" "<<len<<endl;
		stringstream ss;
		for(int i=0;i<len;++i){
			ss.put(dest[rnd()%N]);
		}
		string s=ss.str();
		cout<<s<<endl;
		for(int i=0;i<len;++i){
			int change=(rnd()%len)/10-3;
			for(int j=0;j<change;++j){
				s[i]=dest[rnd()%N];
			}
			index=rnd()%len;
			tmp=s[i];
			s[i]=s[index];
			s[index]=tmp;
		}
		cout<<s<<endl;
	}
	cout<<"0 0"<<endl;
	return 0;
}

