//Ñ¡ÔñÓëÅĞ¶Ï

#include <stdio.h>

int main(void){

int i, grade, rank;

printf("Enter numerical grade:\n");
scanf("%d", &grade);

i = (grade - grade % 10) / 10;
switch(i){
case 5: case 4: case 3: case 2: case 1: case 0:

    printf("Letter grade: F");
    break;
case 6:
    rank = "D";
    printf("Letter grade: D");  /*×¢Òâ×Ö·û´®¸³Öµ*/
    break;
case 7:
    rank = "C";
    printf("Letter grade: C");
    break;
case 8:
    rank = "B";
    printf("Letter grade: B");
    break;
case 9:
case 10:
    rank = "D";
    printf("Letter grade: A");
    break;
default: printf("Please enter number between [0,100]");
    break;
}

return 0;
}
