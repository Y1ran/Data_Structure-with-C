//test

#include<stdio.h>
#include<stdbool.h>

int main(void)
{int hack, price, all, quio;
int i, j;
bool flag;

switch (flag){
  case 1: printf("Nice!");
  break;
  case 0: printf("Not bad!");
  break;
  default: printf("Quit it \a");
  break;
  }
printf("Please enter: \n");
scanf("%d", &hack);
printf("Please enter: \n");
scanf("   %d   /   %d", &price, &quio);

all = hack * price / quio;
printf("%d%%\n", all);


scanf("%d,%d", &i, &j);
printf("%d,%d", i, j);

return 0;
}
