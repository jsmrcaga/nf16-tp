#include <stdio.h>
#include <time.h>
#include <math.h>
#define CHAR_MAX 60
#define TAB_MAX 20


int fibo1(int);
int fibo2(int);

typedef char poulet[60];

struct menu{
	poulet tab[TAB_MAX];
	int n;
};

void main(){
	ton.v=volTonn(ton);
}

float volTonn(tonneau ton){
	return (ton.d+ton.D);
}

void setVolTonn(tonneau *ton){
	tonneau->vol= formule.
}
// int fact1(int f){
// 	int i, res=1;
// 	for (i=1; i<=f;i++){
// 		res*=i;
// 	}
// 	return res;
// }

// int fact2(int f){
// 	int res=f;
// 	if (f==1){
// 		return 1;
// 	}else{
// 		res*=fact2(f-1);
// 	}
// 	return res;
// }

// double determinantMat(double mat[][], int n){
// 	double det;
// 	if (n==1){
// 		det = mat[0][0];
// 	}else{
// 		int i, j , j2, j1;
// 		double temp[n-1][n-1];
// 		for (j=0; j<n; j++){
// 				for (i=1; i<n; i++){
// 						j1=0;
// 						for (j2=0; j2<n; j2++){
// 							if (j2==j) continue;
// 							temp[i-1][j1]=mat[i][j];
// 							j1++;
// 						}

// 				}


// 				det+=pow(-1.0, 1+j1+1)*mat[0][j]*determinantMat(temp, n-1);
// 		}
// 	}
// 	return (det);
// }

// int fibo1(int fib){
// 	int res=0;
// 	if(fib==0){
// 		return 0;
// 	}else if(fib==1){
// 		return 1;
// 	}else{
// 		res = fibo1(fib-2) + fibo1(fib-1);
// 		return res;
// 	}
// }

// int fibo2(int fib){
// 	int res=0;
// 	if(fib==0){
// 		return 0;
// 	}else if(fib==1){
// 		return 1;
// 	}else{
// 		if (fib%2==0){
// 			res = pow((double)fibo2(fib/2),2.0) + 2*fibo2(fib/2)*fibo2((fib/2)-1);

// 		}else{
// 			res = pow((double)fibo2((fib-1)/2),2.0) + pow((double)fibo2(((fib-1)/2)+1), 2.0);
// 		}
// 		return res;
// 	}
// }