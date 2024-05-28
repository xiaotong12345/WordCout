#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>

// 函数：统计字符数
int count_characters(FILE *file) {
    int count = 0;
    char ch;

    // 逐个读取字符，直到文件结束
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }

    return count;
}

// 函数：统计单词数
int count_words(FILE *file) {
    int count = 0;
    char ch;
    int in_word = 0; // 标志是否在单词中

    // 逐个读取字符，直到文件结束
    while ((ch = fgetc(file)) != EOF) {
        // 如果是空格或逗号，表示单词结束
        if (ch == ' ' || ch == ',') {
            in_word = 0;
        }
        // 如果是字母，则进入单词中
        else if (isalpha(ch)) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    // 检查参数数量是否正确
    if (argc != 3) {
        printf("输入格式错误，请输入 [parameter] [input_file_name]\n");
        return 1;
    }

    char *parameter = argv[1];
    char *input_file_name = argv[2];

    // 打开文件
    FILE *file = fopen(input_file_name, "r");
    if (file == NULL) {
        printf("文件不存在！\n");
        return 1;
    }

    // 根据参数执行相应操作
    if (strcmp(parameter, "-c") == 0) {
        int result = count_characters(file);
        printf("字符数：%d\n", result);
    } else if (strcmp(parameter, "-w") == 0) {
        int result = count_words(file);
        printf("单词数：%d\n", result);
    } else {
        printf("参数错误，请输入 '-c' 或 '-w'\n");
    }

    // 关闭文件
    fclose(file);

    return 0;
}

