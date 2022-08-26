#include<iostream>
#include<cmath>
using namespace std;

string primeCheck(long long int num){
	if(num<1000 && num >1){
		for( int i = floor(sqrt(num)); i>1; --i){
			if(num%i ==0){
				return "False, is not a prime number";
				break;
			
			}
			else{
				return "True, is a prime number";
			}
		}
	}
	else{
		return "False, Number is greater than or less than 1";
	}
}
int main(){
	int x;
	cin>>x;
	cout<<primeCheck(x);
	return 0;
}