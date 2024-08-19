#include <stdio.h>
#include <string.h>


char grid[5][5];

void createGrid(char key[]) {
    int used[26] = {0}, k = 0;
    used['J' - 'A'] = 1;
    for (int i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
        if (key[i] == 'J') key[i] = 'I';
        if (!used[key[i] - 'A']) {
            grid[k / 5][k % 5] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!used[i]) {
            grid[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }
}

void preprocess(char text[], char result[]) {
    int len = strlen(text), j = 0;
    for (int i = 0; i < len; i++) {
        text[i] = toupper(text[i]);
        if (text[i] == 'J') text[i] = 'I';
        if (isalpha(text[i])) {
            if (j > 0 && result[j - 1] == text[i]) result[j++] = 'X';
            result[j++] = text[i];
        }
    }
    if (j % 2 != 0) result[j++] = 'X';
    result[j] = '\0';
}

void findPos(char c, int *row, int *col) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (grid[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
}

void playfairCipher(char text[], char result[]) {
    int row1, col1, row2, col2, len = strlen(text);

    for (int i = 0; i < len; i += 2) {
        findPos(text[i], &row1, &col1);
        findPos(text[i + 1], &row2, &col2);
        if (row1 == row2) {
            result[i] = grid[row1][(col1 + 1) % 5];
            result[i + 1] = grid[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            result[i] = grid[(row1 + 1) % 5][col1];
            result[i + 1] = grid[(row2 + 1) % 5][col2];
        } else {
            result[i] = grid[row1][col2];
            result[i + 1] = grid[row2][col1];
        }
    }
    result[len] = '\0';
}
int main() {
    char key[100], pt[100], ppt[100], ct[100];

    printf("\nPlayfair Cipher\n");
    printf("Enter plain text: ");
    scanf("%s", pt);
    printf("Enter key: ");
    scanf("%s", key);

    preprocess(pt, ppt);
    createGrid(key);
    playfairCipher(ppt, ct);
    printf("Encrypted text: %s\n\n\n ", ct);
    return 0;
}
