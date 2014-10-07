#include <stdio.h>

void main(){

}

int fact1(int f){
	int i, res=1;
	for (i=1; i<=f;i++){
		res*=i;
	}
	return res;
}

int fact2(int f){
	int res=1;
	if (f==1){
		return 1;
	}else{
		res*=fact(f-1);
	}
}