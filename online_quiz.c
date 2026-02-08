#include <stdio.h>
#include <ctype.h>
int main() {
    char ans;
    int score = 0;

    // Question bank
    char *questions[] = {
        "Q1: Capital of India?",
        "Q2: 2 + 2 = ?",
        "Q3: Largest planet in the Solar System?"
    };

    char *options[] = {
        "a. Delhi   b. Mumbai",
        "a. 3       b. 4",
        "a. Jupiter b. Mars"
    };

    char correct[] = { 'a', 'b', 'a' };
    int total = sizeof(correct) / sizeof(correct[0]);

    printf("===== Simple Quiz =====\n\n");

    for (int i = 0; i < total; i++) {
        printf("%s\n", questions[i]);
        printf("%s\n", options[i]);

        printf("Your answer: ");
        scanf(" %c", &ans);
        ans = tolower(ans);   // make it case-insensitive

        if (ans == correct[i]) {
            printf("✅ Correct!\n\n");
            score++;
        } else {
            printf("❌ Wrong!\n\n");
        }
    }

    printf("===== Quiz Finished =====\n");
    printf("Your Score: %d / %d\n", score, total);

    return 0;
}
