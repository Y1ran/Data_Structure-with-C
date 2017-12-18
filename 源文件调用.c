/****此程序用来检验文本格式化，以及头文件，源文件的分离合并**
justify <quote称为输入重定向，UNIX中直接从Justify后面的文件调用而不是通过命令行输入***/

/*********************
****格式化字符程序***/

/*justify.c  Format the text*/
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, int *argv[])
{
    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();

    for(;;)
    {
        read_word(word, MAX_WORD_LEN + 1);
        word_len = strlen(word);
        if(word_len == 0){
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1> space_remaining()){
            write_line();
            clear_line(;)
        }
        add_word(word);
    }
}
