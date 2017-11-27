
/**顺序栈的指针实现**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define Stack_size 100

int contents[Stack_size];
int *top;

void make_empty(void)
{
    *top = 0;
}

bool is_empty(void)
{
    return *top == 0;
}


bool is_full(void)
{
    return *top == Stack_size;
}

void push(int i)
{
    if(is_full())
    {
        printf("stack_overflow()");
    }
    else
        *top++ = i;
}

int pop(void)
{
    if(is_empty())
        printf("stack_underflow()");
    else
        return contents[--(*top)];
}

int main(void)
{
    int *k;

    printf("enter the stack number: \n");

    scanf("%d", k);

    push(*k);

    scanf("%d", k);
    pop();

}

/**
  1、栈
          什么是栈，它是你的电脑内存的一个特别区域，它用来存储被每一个function（包括mian（）方法）创建的临时变量。
          栈是FILO，就是先进后出原则的结构体，它密切的被CPU管理和充分利用。每次function声明一个新的变量，它就会被“推”到栈中。
          然后每次一个function退出时，所有关于这个函数中定义的变量都会被释放（换句话说就是删除）。一旦栈中的变量释放，
          这块区域就会变成可用的，提供给其他栈中的变量。
     用栈存储变量的好处是，内存是被你管理的。你不用手动的创建内存，不用当你不在需要它的时候手动释放内存。
     另外，由于CPU组织栈内存很高效。读出和写入栈变量是很快的。
     理解栈的关键是理解概念，当一个function退出时，所有它的变量都会从栈中弹出,以后都会永远消失。
     因此栈中的变量本质是局部的。这和我们原来理解为变量作用域或者本地或者全局变量是相关的。
     在C中，一个公共的bug 是从你程序中的一个function外尝试访问一个在栈中的这个function的变量（在该function已经退出后）。

关于栈的另一个特点我们应该记住，就是存储再栈中的变量的大小有限制。而堆上创建变量不用考虑。

总结栈：
      a、栈的生长和伸缩就是函数压入或者推出局部变量。
      b、我们不用自己去管理内存，变量创建和释放都是自动的。
      c、栈中的变量只有在函数创建运行时存在。

2、 堆

堆也是我们的计算机内存中的一个区域，但是他不是自动管理的。
而且也不是被CPU密切的管理着。它是一片更加自由的内存区域（很大）。要想在堆上创建内存，我们必须使用malloc() 或者calloc（），
他们都是C语言编译的。一旦你在堆上分配内存，当你不在需要的时候你必须用free()去销毁。如果你不销毁或者销毁失败，你的程序就会有内存泄露。
换句话说就是堆内存会一直在，其他进程无法使用。我们将会再调试部分看到，那里有一个叫做Valgrind的东西，它可以帮助你发现内存泄露。

不像栈，堆没有变量大小的限制（除了你电脑的物理限制条件外）。堆内存读出和写入都比较慢，因为它必须使用指针图访问堆内存。
我们将会下面讲解指针。

3、栈和堆的优缺点

栈：
          a、快速访问。
          b、没有必要明确的创建分类变量，因为它是自动管理的。
          c、空间被CPU高效地管理着，内存不会变成碎片。
          d、只有局部变量
          e、受限于栈大小(取决于操作系统)
          f、变量不能调整大小。
        堆：
          a、变量可以被全局访问
          b、没有内存大小限制
          c、（相对）访问比较慢
          d、没有高效地使用空间，随着块内存的创建和销毁，内存可能会变成碎片。
          e、你必须管理内存（变量的创建和销毁你必须要负责）
          f、变量大小可以用realloc( )调整
例如：
          下面是一个在栈上创建变量的短程序。和我们看到的其他程序类似

#include <stdio.h>
double multiplyByTwo (double input) {
double twice = input * 2.0;
return twice;
}
int main(int argc, const char * argv[]) {
int age = 30;
double salary = 12345.67;
double myList[3] = {1.2,2.3,3.4};
printf("double your salary is %.3f\n",multiplyByTwo(salary));
return 0;
}

/**
运行结果如下： double your salary is 24691.340

在第7，8和9行,我们声明了三个变量：一个int变量、一个double变量和一个包含三个包含double的数组。
这三个变量在main（）函数创建，被压入栈中。当main（）函数退出（程序退出），这些变量就会出栈。
同样地，在multiplyByTwo函数中，第二个double变量，也会在multiplyByTwo（）函数创建的时候压入栈中。
一旦函数退出，第二个变量就会出栈，永远地消失。

备注：有一种方法可以告诉C保持一个栈变量。即使它的创建函数退出。
那就是用static关键字当声明变量的时候。一个变量用static关键之声明，因此就会变成一个类似与全局变量的东西。
但是它仅仅在创建它的函数里面可见。这是一个奇怪的东西，除非你在一个非常特殊的情况下需要。


下面是另一个版本的创建变量在堆上而不是在栈上：

#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo (double *input) {
 double *twice = malloc(sizeof(double));
 *twice = *input *2.0;
 return twice;
}
int main(int argc, const char * argv[]) {
 int *age = malloc(sizeof(int));
 *age = 30;
 double *salary = malloc(sizeof(double));
 *salary = 12345.67;
 double *myList = malloc(3 * sizeof(double));
 myList[0] = 1.2;
 myList[1] = 3.4;
 myList[2] = 4.5;
 double *twiceSalary = multiplyByTwo(salary);

 printf("double your salary is %.3f\n",*twiceSalary);

 free(age);
 free(salary);
 free(myList);
 free(twiceSalary);

 return 0;
}
　　
正如你所看到的，我们用malloc（）去分配堆内存，用free()去释放它。
这样不是很大的处理，但是很笨重。还有一件要注意的事情是：这样会由很多*号。
这些是指针。malloc()（calloc()和free（））函数处理的是指针而不是真正的数值。
指针在C栈是一个特殊的数据类型，它用来存储内存的地址而不是存储实际的values.因此在
1*twice = *input *2.0;

　　
这行，twice变量不是一个double，而是一个指向double的指针，是double被存储再内存中的地址。
4、什么时候使用堆

应该什么时候使用堆和栈呢？如果我们需要分配一大块内存（例如一个很大的数组或者一个很大的结构体），
而且我们需要保持这个变量很长时间（例如全局变量）。我们应该分配堆内存。
如果你处理的很小的变量，而且只要再函数使用的时候存活，那么你应该使用栈，它比较方便而且快捷。
如果你需要类似与数组或者结构体的变量，而且能够动态改变大小（例如一个数组可以根据需要添加数据或者删除数据），
那么你可以用malloc(),realloc（)给他们分配堆内存，用free()手动的管理内存。当我们讨论完指针，我们将会讨论动态分配数据结构体。

在”%m.ns”中，m 表示占用宽度（字符串长度不足时补空
格，超出了则按照实际宽度打印），n 才表示从相应的字符串中最多取用的字符数。
**/
