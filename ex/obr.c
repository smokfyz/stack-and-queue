#include <stdio.h>

unsigned reverse(int n, int i) {
	return (n==0) ? i : reverse( n/10, i*10 + n%10 );
}

int main() {
	unsigned num = 0;
	scanf("%d", &num);
	
	printf("%d\n", reverse(num, 0));
	return 0;
}
