
//�� ������ ������ �Ϳ� ���� ������� �ʹ� ��������� ��������, �ܺ��� ����� �����ϴ� ����, ���ø� �����Ͽ� ��������ϴ�.
//����ڸ� �����ϰ� ���ھ �ű�� �κ��� �������� ���Ͽ����ϴ�.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dict.h" // english-korean dictionary file include

#define TRY_GAME 5
#define TRY_TRY  5
#define TRY_MAX  10

// FUNCTION: usage
//   1. ���� ���
void usage()
{
    printf( "\n[���� ����]\n"
            "1. ���õ� �ܾ ���ߴ� Hangman Game �Դϴ�.\n"
            "2. �⺻���� ����� Ư���� �ܾ��� ��Ʈ�� ���������� ����ϰ�, �� ��Ʈ�� ���� �ܾ ���߸� ����, ������ ���� ��쿣 �й踦 ����մϴ�.\n"
            "3. �پ��� �ܾ ����ϱ� ���� �ܾ ���� �����ͺ��̽��� �����մϴ�. ���� �ܾ ���� ����� �з��ϸ�(�ܾ�� 5~7���� ����), �� �ܾ ���� ����, �ܾ� �ǹ̿� ���� �����͸� �����մϴ�.\n"
            "4. ������ �����ϸ� �����ͺ��̽� �� �ܾ�(ex. Seagull)�� �����ϰ� �ϳ� ����մϴ�. �̶� ����ڰ� ������ �������� ������ ���� ����ϴ� ��Ʈ�� 5�ܰ�� �����µ�, 1�ܰ�: �ܾ��� ���ڼ��� ù ���ڸ� �˷��ش�(ex.7����, S). 2�ܰ�: �ܾ��� 3��° ���ڸ� �˷��ش�(ex. a). 3�ܰ�: �ܾ��� 5��° ���ڸ� �˷��ش�(u). 4�ܰ���ʹ� ������� �й�� ó���ϸ�, �ܾ��� �ǹ̸� �˷��ش�(ex. �ⷯ��). 5�ܰ�: �ܾ �����Ѵ�.\n"
            "5. ����ڰ� 3�ܰ� �ȿ� �ܾ ���߸� ���������� ����ϰ�, ������ �� �����С��� ����մϴ�.\n"
            "6. ����ڰ� �������� �� ��� H-A-N-G-M-A-N ������� ���ڸ� ����� �ܾ �����ϸ�, �ܾ �ϼ� �� ������ �¸��� ����� �Բ� ���� ������ �Ϸ��մϴ�. 5ȸ �̻� ���� �� ������ �й衯 ����� �Բ� ���� ������ �Ϸ��մϴ�.\n"
            "7. ������ ���� �� ����� ���θ� ���� Y/N�� ���� ����� ���θ� ������ �� �ֽ��ϴ�. ������ �ϴ� �߰��� ����� �ؾ���� �� �ֱ� ������ m�� �Է��ϸ�, ���� ����� �ٽ� �˷��ְ�, x�� ������ ������ ������ �����մϴ�.\n"
            "8. ���� ����� �� ������ ������ ������(���� �� ���� ȸ��)�� �ʱ�ȭ�� �� ������ �����մϴ�.\n\n");
}

// FUNCTION: check_word
//   1. input�� 'm'�� ��� ���� ��� ȣ��
//   2. input�� 'x'�� ��� ���� (try = -1: ���� game ���� message)
//   3. �׿� ��� input�� word�� ��ġ ���� �˻�, try ȸ�� ����
// INPUT:
//   word: input�� ���� �ܾ�
//   try: ������� �õ� ȸ��
// RETURN:
//   1: word�� ��ġ
//   0: word�� ����ġ
//   -1: ���� game ����
int check_word(char *word, int *try)
{
    char input[16];
    while (1) {
        printf("  �Է� #%d> ", *try+1);
        scanf("%s", input);

        if (!strcmp(input, "m")) { // ����
            usage();
        } else if (!strcmp(input, "x")) { // ���� game ����
            *try = -1; // special case: program terminate if try = -1
            return -1;
        } else {
            *try += 1; // increase try
            return !strcmp(input, word); // 0: mismatch, 1: match
        }
    }
}

// FUNCTION: guess_word
//   1. ����(Words)���� word�� ���� ����
//   2. stage-1: �ܾ� ���ڼ��� �˷��ְ� �Է°� ��, ���߸� ����
//   3. stage-2: �ܾ��� 1��° ���ڸ� �˷��ְ� �Է°� ��, ���߸� ����
//   4. stage-3: �ܾ��� 3��° ���ڸ� �˷��ְ� �Է°� ��, ���߸� ����
//   5. stage-4: �ܾ��� 5��° ���ڸ� �˷��ְ� �Է°� ��, ���߸� ����
//   6. stage-4���� �� 10���� �õ��ϰ� 5��°�� '�й�' 10��°�� '����'�� ���
//   7. stage-5: �ܾ��� �ǹ̸� �˷��ְ� �Է°� ��, ���߸� ����
//   8. stage-6: ���õ� �ܾ ���
// RETURN:
//   try: �ܾ ���⶧���� �õ� ȸ��
int guess_word()
{
    int try = 0;
    int widx = rand() % nWord;
    char *word = Words[widx][0];

    // stage-1
    printf("�� �ܾ�� %d�� �Դϴ�.\n", (int)strlen(Words[widx][0]));
    if (check_word(word, &try)) return try;

    //stage-2
    printf("�� �ܾ��� 1��° ���ڴ� '%c' �Դϴ�.\n", Words[widx][0][0]);
    if (check_word(word, &try)) return try;

    // stage-3
    printf("�� �ܾ��� 3��° ���ڴ� '%c' �Դϴ�.\n", Words[widx][0][2]);
    if (check_word(word, &try)) return try;

    // stage-4
    printf("�� �ܾ��� 5��° ���ڴ� '%c' �Դϴ�.\n", Words[widx][0][4]);

    while (try < TRY_MAX) {
        if (check_word(word, &try)) return try;

        if (try == TRY_TRY)
            printf("�й��ϼ���.\n");
        else if (try == TRY_MAX)
            printf("���ӿ� �����ϼ���.\n");
    }

    // stage-5
    printf("�� �ܾ��� �ǹ̴� '%s' �Դϴ�.\n", Words[widx][1]);
    if (check_word(word, &try)) return try;

    // stage-6
    printf("�� �ܾ�� '%s' �Դϴ�.\n", Words[widx][0]);

    return try;
}

// FUNCTION: hangman_game
//   1. ���߱�(guess_word)�� ���� ���߱���� �õ� ȸ��(try) ȹ��
//   2. try = -1 �̸� ��� ���� (input = 'x')
//   3. try > 10 (stage-3 �ʰ�)�̸� ����(fail) ȸ�� ����
//   4. try <= 10 (stage-3 �̳�)�̸� ����(success) ȸ�� ����
//   5. ���ݱ��� ����(success) ȸ���� ���߾� H-A-N-G-M-A-N ���� ���
//   6. ����(fail)�� 5ȸ �̻��̸� '���� �й�'�� ����
//   7. ����(success)�� H-A-N-G-M-A-N�� �Ϸ��ϸ�(6ȸ) '���� ����'���� ����
// RETURN:
//   score: ���� ���� = (11 - �õ�ȸ��) * n��
int hangman_game()
{
    char *hangman = "HANGMAN";
    int fail = 0, success = 0;
    int score = 0, try;
    int n = 0, i;

    printf("\nHANGMAN ������ �����մϴ�.\n\n");
    while (1) {
        printf("%d��° �ܾ��Դϴ�.\n", ++n);
        try = guess_word();
        if (try < 0) return 0; // ��� ���� if try = -1
        else if (try > TRY_MAX) { // fail if too many try
            fail++;
            printf("\n[���� %d]\n\n", fail);
        } else {
            score += TRY_MAX+1 - try;

            success++;
            printf("\n[����]  ");
            for (i = 0; i < success-1; i++)
                printf("%c-", hangman[i]);
            printf("%c\n\n", hangman[i]);
        }

        if (fail >= TRY_GAME) {
            printf("[���� �й�]\n\n");
            break;
        } else if (success >= strlen(hangman)) { // complete HANGMAN
            printf("[���� ����]\n\n");
            break;
        }
    }

    return score;
}

// FUNCTION: retry
//   1. ����� ���θ� ����
//   2. input�� 'y' �Ǵ� 'n'�� ��츸 ����
//   3. �׿� ��� �ٽ� ����� ���θ� ����
// RETURN:
//   1: yes
//   0: no
int retry()
{
    while (1) { // wait Y/N input
        char yn;
        printf("������ ����� �ϰڽ��ϱ� (Y/N)? ");
        scanf("%c", &yn);
        if (yn == 'N' || yn == 'n') return 0;
        else if (yn == 'Y' || yn == 'y') return 1;
    }
}

int main()
{
    srand(time(0)); // ���� �ʱ�ȭ

    do {
        int score = hangman_game();
        // TOTO: player score
    } while (retry());

    printf("\n[���� ����]\n");

    return 0;
}
