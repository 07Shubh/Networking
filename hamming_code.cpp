#include <iostream>
#include<conio.h>
using namespace std;

int main(){

	int a[10], b[10], c1, c2, c3;

	cout<<"\nEnter the data code:-\n";
	cin>>a[3];
	cin>>a[5];
	cin>>a[6];
	cin>>a[7];

	//for Parity bit
	a[1] = a[3]^a[5]^a[7];
	a[2] = a[3]^a[6]^a[7];
	a[4] = a[5]^a[6]^a[7];

	cout<<"\nHamming Code:-\n\n";
	for(int i=1;i<8;i++){
		cout<<"\t"<<a[i];
	}

	//Error Detection
	cout<<"\nEnter the received data code:-\n";
	for(int i=1;i<8;i++){
		cin>>b[i];
	}

	c1 = b[1]^b[3]^b[5]^b[7];
	c2 = b[2]^b[3]^b[6]^b[7];
	c3 = b[4]^b[5]^b[6]^b[7];

	int p = c1*1 + c2*2 + c3*4;

	if(p==0){
		cout<<"\nNo Error\n";
	}
	else{
		cout<<"\nError is at "<<p;

		//Correction
		if(b[p]==0)
			b[p]=1;
		else
			b[p]=0;
		cout<<"\nCorrected Data Code:-\n\n";
		for(int i=1;i<8;i++){
			cout<<"\t"<<b[i];
		}
	}

	getch();
	return 0;
}