#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义字符串类型
typedef struct {
    char* str;  // 字符串存储数组
    int length; // 字符串长度
} StringType;

// 初始化一个空字符串
void StrInit(StringType* t) {
    t->str = NULL;
    t->length = 0;
}

// 将s的值赋给t
void StrAssign(StringType* t, const char* s) {
    t->length = strlen(s);
    t->str = (char*)malloc(t->length + 1); // +1 用于存储字符串结束符 '\0'
    strcpy(t->str, s);
}

// 比较s和t
int StrCompare(StringType s, StringType t) {
    return strcmp(s.str, t.str);
}

// 返回字符串长度
int StrLength(StringType s) {
    return s.length;
}

// 返回由s和t联接而成的新串
StringType Concat(StringType s, StringType t) {
    StringType result;
    result.length = s.length + t.length;
    result.str = (char*)malloc(result.length + 1);
    strcpy(result.str, s.str);
    strcat(result.str, t.str);
    return result;
}

// 返回s中第start个字符起长度为len的子串
StringType SubString(StringType s, int start, int len) {
    if (start < 1 || start > s.length || len < 0 || start + len - 1 > s.length) {
        StringType empty;
        StrInit(&empty);
        return empty;
    }

    StringType result;
    result.length = len;
    result.str = (char*)malloc(len + 1);
    strncpy(result.str, s.str + start - 1, len);
    result.str[len] = '\0';

    return result;
}

// 释放字符串的内存
void StrDestroy(StringType* s) {
    if (s->str != NULL) {
        free(s->str);
        s->str = NULL;
    }
    s->length = 0;
}

int main() {
    char inputA[100];
    char inputB[100];
    StringType s, t;
    StrInit(&s);
    StrInit(&t);

    gets(inputA);
    gets(inputB);

    StrAssign(&s, inputA);
    StrAssign(&t, inputB);
    //测试
    // StrAssign(&s, "Hello");
    // StrAssign(&t, "World");

    printf("s: %s\n", s.str);
    printf("t: %s\n", t.str);
    printf("Comparison result: %d\n", StrCompare(s, t));
    printf("Length of s: %d\n", StrLength(s));

    StringType concatenated = Concat(s, t);
    printf("Concatenated: %s\n", concatenated.str);

    StringType substring = SubString(concatenated, 6, 5);
    printf("Substring: %s\n", substring.str);

    StrDestroy(&s);
    StrDestroy(&t);
    StrDestroy(&concatenated);
    StrDestroy(&substring);

    return 0;
}
