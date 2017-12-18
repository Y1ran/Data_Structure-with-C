/****************************
LINE.H��������ѭ����������ԭ��
1. ����л����������ݣ������е���
2. ����л�������ʣ���ַ���
3. ����л����������ݣ����е���
4. ����л�����
5. ���л�����������µĵ���
*****************************/

#ifndef LINE_H
#define LINE_H

void clear_line(void);

void add_word(const char *word);

int space_remaining(void);

void write_line(void);

void flush_line(void);

#endif
/***word.h �������ı��ж�ȡ���ݲ�װ��
***/

#ifndef WORD_H
#define WORD_H  //�����ж��Ƿ��ظ�������ͷ�ļ����´���

void read_word (char *word, int len);

#endif


/***word.c***/

#include <stdio.h>
#include "word.h"

int read_char(void)
{
    int ch =getchar();

    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;

}

void read_word(char *word, int len)
{
    int ch, pos = 0;

    while((ch = read_char())== ' ')
        ;
    while (ch != ' ' && ch != EOF){
        if (pos < len)
            word[pos++] = ch;
        ch = read_char();
    }
    word[pos] = '\0';
}


/***line.c***/

#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_WORD_LEN 60

char line[MAX_WORD_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0)
    {
        line[line_len] = ' ';
        line[line_len+1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_WORD_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insrt, i , j;

    extra_spaces = MAX_WORD_LEN - line_len;

    for (i = 0;i < line_len; i++){
        if (line[i] != ' ')
            putchar(line[i]);
        else{
            spaces_to_insrt = extra_spaces / (num_words - 1);
            for(j = 1; j <= spaces_to_insrt + 1;j++)
                putchar(' ');
            extra_spaces -= spaces_to_insrt;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void)
{
    if (line_len > 0)
        puts(line);
}


/****�˳������������ı���ʽ�����Լ�ͷ�ļ���Դ�ļ��ķ���ϲ�**
justify <quote��Ϊ�����ض���UNIX��ֱ�Ӵ�Justify������ļ����ö�����ͨ������������***/

/*********************
****��ʽ���ַ�����***/

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
            clear_line();
        }
        add_word(word);
    }
}
