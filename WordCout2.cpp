#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>

// ������ͳ���ַ���
int count_characters(FILE *file) {
    int count = 0;
    char ch;

    // �����ȡ�ַ���ֱ���ļ�����
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }

    return count;
}

// ������ͳ�Ƶ�����
int count_words(FILE *file) {
    int count = 0;
    char ch;
    int in_word = 0; // ��־�Ƿ��ڵ�����

    // �����ȡ�ַ���ֱ���ļ�����
    while ((ch = fgetc(file)) != EOF) {
        // ����ǿո�򶺺ţ���ʾ���ʽ���
        if (ch == ' ' || ch == ',') {
            in_word = 0;
        }
        // �������ĸ������뵥����
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
    // �����������Ƿ���ȷ
    if (argc != 3) {
        printf("�����ʽ���������� [parameter] [input_file_name]\n");
        return 1;
    }

    char *parameter = argv[1];
    char *input_file_name = argv[2];

    // ���ļ�
    FILE *file = fopen(input_file_name, "r");
    if (file == NULL) {
        printf("�ļ������ڣ�\n");
        return 1;
    }

    // ���ݲ���ִ����Ӧ����
    if (strcmp(parameter, "-c") == 0) {
        int result = count_characters(file);
        printf("�ַ�����%d\n", result);
    } else if (strcmp(parameter, "-w") == 0) {
        int result = count_words(file);
        printf("��������%d\n", result);
    } else {
        printf("�������������� '-c' �� '-w'\n");
    }

    // �ر��ļ�
    fclose(file);

    return 0;
}

