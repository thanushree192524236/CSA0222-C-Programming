#include <stdio.h>
#include <ctype.h>

/* Count words without using string.h. Multiple spaces are treated as one gap. */
int word_count(const char text[]) {
    int count = 0, inside_word = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace((unsigned char)text[i])) inside_word = 0;
        else if (!inside_word) {
            count++;
            inside_word = 1;
        }
    }
    return count;
}

/* Check letters from both ends, ignoring case and punctuation. */
int is_palindrome(const char text[]) {
    int left = 0, right = 0;
    while (text[right] != '\0') right++;
    right--;

    while (left < right) {
        while (left < right && !isalpha((unsigned char)text[left])) left++;
        while (left < right && !isalpha((unsigned char)text[right])) right--;
        if (tolower((unsigned char)text[left]) != tolower((unsigned char)text[right]))
            return 0;
        left++;
        right--;
    }
    return 1;
}

void make_uppercase(char text[]) {
    for (int i = 0; text[i] != '\0'; i++)
        text[i] = (char)toupper((unsigned char)text[i]);
}

void reverse_text(char text[]) {
    int left = 0, right = 0;
    char temp;
    while (text[right] != '\0') right++;
    right--;
    while (left < right) {
        temp = text[left]; text[left] = text[right]; text[right] = temp;
        left++; right--;
    }
}

int main(void) {
    char message[] = "Meet at the library at 5 PM";
    char copy[] = "Hello C";
    puts("SMS FEEDBACK CHECK");
    printf("Words: %d\n", word_count(" Meet at the library at 5 PM "));
    printf("Palindrome results: %d %d\n", is_palindrome("Madam, I'm Adam"), is_palindrome("Hello"));
    make_uppercase(copy);
    printf("Upper case: %s\n", copy);
    reverse_text(message);
    printf("Reversed: %s\n", message);
    printf("Tab-separated words: %d\n", word_count("one\ttwo three"));
    return 0;
}
