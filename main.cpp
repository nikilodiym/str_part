#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int counting_the_number_of_occurrences_of_a_word(const char* text, const char* word) {
    int count = 0;
    int text_len = strlen(text);
    int word_len = strlen(word);

    for (int i = 0; i <= text_len - word_len; ++i) {
        int j;
        for (j = 0; j < word_len; ++j) {
            if (text[i + j] != word[j]) {
                break;
            }
        }
        if (j == word_len) {
            count++;
            i += word_len - 1;
        }
    }
    return count;
}

int count_number_of_sentences_in_text(const char* text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}

void counting_number_of_dots_and_commas(const char* text, int& dots, int& commas) {
    dots = 0;
    commas = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '.') {
            dots++;
        }
        else if (text[i] == ',') {
            commas++;
        }
    }
}

void turn_entire_text_over(char* text) {
    int len = strlen(text);
    for (int i = 0; i < len / 2; ++i) {
        char temp = text[i];
        text[i] = text[len - i - 1];
        text[len - i - 1] = temp;
    }
}

void turn_every_sentence_in_the_text_over(char* text) {
    int start = 0;
    int end = 0;
    int len = strlen(text);

    while (end <= len) {
        if (text[end] == '.' || text[end] == '!' || text[end] == '?' || text[end] == '\0') {
            int sentence_end = end - 1;
            while (start < sentence_end) {
                char temp = text[start];
                text[start] = text[sentence_end];
                text[sentence_end] = temp;
                start++;
                sentence_end--;
            }
            start = end + 1;
        }
        end++;
    }
}

int main() {
    const char* text = "C++ is a powerful programming language, widely used in software development. It was created by Bjarne Stroustrup in 1985! The language supports both procedural and object-oriented programming, making it very versatile. Do you know why C++ is so popular? One reason is its performance; C++ programs are often very fast and efficient. Moreover, C++ has a rich set of libraries and frameworks. Learning C++ can be challenging, but it's definitely rewarding!";
    char buffer[256];
    strcpy(buffer, text);
    char word[50];

    cout << "Enter the word to count: ";
    cin >> word;

    int word_count = counting_the_number_of_occurrences_of_a_word(buffer, word);
    int sentence_count = count_number_of_sentences_in_text(buffer);

    int dots, commas;
    counting_number_of_dots_and_commas(buffer, dots, commas);

    char reversed_text[256];
    strcpy(reversed_text, buffer);
    turn_entire_text_over(reversed_text);

    char reversed_sentences[256];
    strcpy(reversed_sentences, buffer);
    turn_every_sentence_in_the_text_over(reversed_sentences);

    cout << "Occurrences of " << word << ": " << word_count << endl;
    cout << "Number of sentences: " << sentence_count << endl;
    cout << "Number of dots: " << dots << endl;
    cout << "Number of commas: " << commas << endl;
    cout << "Reversed text: " << reversed_text << endl;
    cout << "Reversed each sentence: " << reversed_sentences << endl;

	return 0;
}