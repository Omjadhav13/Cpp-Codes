//evenoddindigit 
#include <iostream>
using namespace std;
int main(){
	
	for(int i=100;i<=400;i++){
		bool flag=true;
		int copy=i;
		while(copy!=0){
			int digit=copy%10;
			copy/=10;
			if(digit%2!=0){
				flag=false;
				break;
			}
		}
		if(flag==true){
			cout << i << ", ";
		}
		
	}	
}

