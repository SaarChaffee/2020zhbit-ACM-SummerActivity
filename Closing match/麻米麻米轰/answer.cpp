#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
//ascii 128
//1-128
//abc c[0]='a' c[1]='b'
//sort  o(nlogn+n)==o(nlogn)
//o(n+n)==o(n)  1E8 
int dest[129];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);
	int a,b,flag;
	string c,d;
	while(cin>>a>>b,a+b){
		cin>>c>>d;
		if(a!=b){
			cout<<"JiuZhe?"<<endl;
			continue;
		}
		flag=0;
		memset(dest,0,sizeof dest);
		for(int i=0;i<a;++i){
			dest[c[i]]++;
		}
		for(int i=0;i<b;++i){
			dest[d[i]]--;
		} 
		
		//o(129) == o(1)
		for(int i=0;i<129;++i){
			if(dest[i]!=0){	
				flag=1;
//				cout<<i<<" dest[i]:"<<dest[i]<<endl;
				break;
			}
		}
		if(flag){
			cout<<"JiuZhe?"<<endl;
		}
		else{
			cout<<"LinBen!"<<endl;
		}
	}
	return 0;
}
