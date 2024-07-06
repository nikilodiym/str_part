#include <iostream>
#include <string>
#include <cstring>

void replace_word(char* text, const char* oldWord, const char* newWord) {
    char buffer[1000];
    char* pos;
    int index = 0;
    int oldWordLen = strlen(oldWord);

    while ((pos = strstr(text, oldWord)) != NULL) {
        strncpy(buffer + index, text, pos - text);
        index += pos - text;

        strcpy(buffer + index, newWord);
        index += strlen(newWord);

        text = pos + oldWordLen;
    }

    strcpy(buffer + index, text);

    strcpy(text, buffer);
}

void capitalize_sentences(char* text) {
    int capitalize = 1;
    for (int i = 0; text[i] != '\0'; i++) {
        if (capitalize && isalpha(text[i])) {
            text[i] = toupper(text[i]);
            capitalize = 0;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            capitalize = 1;
        }
    }
}

void count_letters(const char* text, int counts[26]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            counts[tolower(text[i]) - 'a']++;
        }
    }
}

void count_digits(const char* text, int counts[10]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isdigit(text[i])) {
            counts[text[i] - '0']++;
        }
    }
}

int main() {
    char text[1000] = "C++ is a powerful programming language, widely used in software development. It was created by Bjarne Stroustrup in 1985! The language supports both procedural and object-oriented programming, making it very versatile. Do you know why C++ is so popular? One reason is its performance; C++ programs are often very fast and efficient. Moreover, C++ has a rich set of libraries and frameworks. Learning C++ can be challenging, but it's definitely rewarding!";
    char oldWord[50], newWord[50];
    int letterCounts[26] = { 0 };
    int digitCounts[10] = { 0 };

    printf("Enter the word to replace: ");
    scanf("%s", oldWord);
    printf("Enter the new word: ");
    scanf("%s", newWord);

    replace_word(text, oldWord, newWord);
    printf("Text after word replacement: %s\n", text);

    capitalize_sentences(text);
    printf("Text after capitalizing sentences: %s\n", text);

    count_letters(text, letterCounts);
    printf("Letter counts:\n");
    for (int i = 0; i < 26; i++) {
        if (letterCounts[i] > 0) {
            printf("%c: %d\n", 'a' + i, letterCounts[i]);
        }
    }

    count_digits(text, digitCounts);
    printf("Digit counts:\n");
    for (int i = 0; i < 10; i++) {
        if (digitCounts[i] > 0) {
            printf("%d: %d\n", i, digitCounts[i]);
        }
    }

    system("pause");
    return 0;
}
