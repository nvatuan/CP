#include <stdio.h>

int main(){
	char P1, P2;
	scanf("%c%c%c", &P1, &P2, &P2);

	if(P1 == P2) printf("DRAW");
	else 
		if((P1 == 'B') && (P2 == 'K')) printf("WIN");
		else if((P1 == 'K') && (P2 == 'G')) printf("WIN");
			 else if((P1 == 'G') && (P2 == 'B')) printf("WIN");
				  else printf("LOSE");
}