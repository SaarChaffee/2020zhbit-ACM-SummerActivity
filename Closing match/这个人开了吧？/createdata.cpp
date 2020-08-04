#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int main(){
	int n=20,a,b,ex,ey,sx,sy;
	freopen("in.txt","w",stdout);
	while(n--){
		a=(rnd()%500)+1;
		b=(rnd()%500)+1;
		if(a==1)a++;
		if(b==1)b++;
		cout<<a<<" "<<b<<endl;
		ex=rnd()%a;
		ey=rnd()%b;
		for(int i=0;i<a;++i){
			if(i==ex){
				for(int j=0;j<b;++j){
					if(j==ey){
						cout<<"100 ";	
					}
					else{
						cout<<rnd()%100<<" ";
					}
				}
				puts("");
			}
			else{
				for(int j=0;j<b;++j)
					cout<<rnd()%100<<" ";
				puts("");
			}
			
		}
		sx=rnd()%a;
		sy=rnd()%b;
		cout<<sx<<" "<<sy<<endl;
	}
	return 0;
}

