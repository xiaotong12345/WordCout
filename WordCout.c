#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char s[1000];
    int wordCount = 0;
    int inWord = 0;
    int i;

    printf("����: ");
    scanf("%[^\n]s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        } else {
            inWord = 0;
        }
    }

    printf("һ���� %d ������\n", wordCount);

    return 0;
}

