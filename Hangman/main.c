
//이 게임은 구상한 것에 비해 결과물이 너무 비대해지고 복잡해져, 외부의 도움과 현존하는 서적, 예시를 참고하여 만들었습니다.
//사용자를 구분하고 스코어를 매기는 부분은 구현하지 못하였습니다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dict.h" // english-korean dictionary file include

#define TRY_GAME 5
#define TRY_TRY  5
#define TRY_MAX  10

// FUNCTION: usage
//   1. 사용법 출력
void usage()
{
    printf( "\n[게임 사용법]\n"
            "1. 제시된 단어를 맞추는 Hangman Game 입니다.\n"
            "2. 기본적인 기능은 특정한 단어의 힌트를 순차적으로 출력하고, 그 힌트에 따라 단어를 맞추면 성공, 맞추지 못할 경우엔 패배를 출력합니다.\n"
            "3. 다양한 단어를 출력하기 위해 단어에 대한 데이터베이스를 구축합니다. 먼저 단어를 문자 수대로 분류하며(단어는 5~7문자 사이), 각 단어에 구성 문자, 단어 의미에 대한 데이터를 저장합니다.\n"
            "4. 게임을 시작하면 데이터베이스 내 단어(ex. Seagull)를 랜덤하게 하나 출력합니다. 이때 사용자가 문제를 맞히는지 유무에 따라서 출력하는 힌트를 5단계로 나누는데, 1단계: 단어의 문자수와 첫 문자를 알려준다(ex.7글자, S). 2단계: 단어의 3번째 문자를 알려준다(ex. a). 3단계: 단어의 5번째 문자를 알려준다(u). 4단계부터는 사용자의 패배로 처리하며, 단어의 의미를 알려준다(ex. 기러기). 5단계: 단어를 공개한다.\n"
            "5. 사용자가 3단계 안에 단어를 맞추면 ‘성공’을 출력하고, 실패할 시 ‘실패’를 출력합니다.\n"
            "6. 사용자가 ‘성공’ 할 경우 H-A-N-G-M-A-N 순서대로 문자를 출력해 단어를 구성하며, 단어를 완성 시 ‘게임 승리’ 문장과 함께 현재 게임을 완료합니다. 5회 이상 실패 시 ‘게임 패배’ 문장과 함께 현재 게임을 완료합니다.\n"
            "7. 게임이 끝난 후 재시작 여부를 물어 Y/N로 게임 재시작 여부를 선택할 수 있습니다. 게임을 하다 중간에 방법을 잊어버릴 수 있기 때문에 m을 입력하면, 게임 방법을 다시 알려주고, x를 누르면 게임을 완전히 종료합니다.\n"
            "8. 게임 재시작 시 이전에 누적된 데이터(성공 및 실패 회수)를 초기화한 후 게임을 시작합니다.\n\n");
}

// FUNCTION: check_word
//   1. input이 'm'일 경우 사용법 출력 호출
//   2. input이 'x'일 경우 종료 (try = -1: 현재 game 종료 message)
//   3. 그외 경우 input과 word의 일치 여부 검사, try 회수 증가
// INPUT:
//   word: input과 비교할 단어
//   try: 현재까지 시도 회수
// RETURN:
//   1: word와 일치
//   0: word와 불일치
//   -1: 현재 game 종료
int check_word(char *word, int *try)
{
    char input[16];
    while (1) {
        printf("  입력 #%d> ", *try+1);
        scanf("%s", input);

        if (!strcmp(input, "m")) { // 사용법
            usage();
        } else if (!strcmp(input, "x")) { // 현재 game 종료
            *try = -1; // special case: program terminate if try = -1
            return -1;
        } else {
            *try += 1; // increase try
            return !strcmp(input, word); // 0: mismatch, 1: match
        }
    }
}

// FUNCTION: guess_word
//   1. 사전(Words)에서 word를 랜덤 선택
//   2. stage-1: 단어 글자수를 알려주고 입력과 비교, 맞추면 종료
//   3. stage-2: 단어의 1번째 글자를 알려주고 입력과 비교, 맞추면 종료
//   4. stage-3: 단어의 3번째 글자를 알려주고 입력과 비교, 맞추면 종료
//   5. stage-4: 단어의 5번째 글자를 알려주고 입력과 비교, 맞추면 종료
//   6. stage-4까지 총 10번을 시도하고 5번째면 '분발' 10번째면 '집중'을 출력
//   7. stage-5: 단어의 의미를 알려주고 입력과 비교, 맞추면 종료
//   8. stage-6: 선택된 단어를 출력
// RETURN:
//   try: 단어를 맞출때까지 시도 회수
int guess_word()
{
    int try = 0;
    int widx = rand() % nWord;
    char *word = Words[widx][0];

    // stage-1
    printf("이 단어는 %d자 입니다.\n", (int)strlen(Words[widx][0]));
    if (check_word(word, &try)) return try;

    //stage-2
    printf("이 단어의 1번째 글자는 '%c' 입니다.\n", Words[widx][0][0]);
    if (check_word(word, &try)) return try;

    // stage-3
    printf("이 단어의 3번째 글자는 '%c' 입니다.\n", Words[widx][0][2]);
    if (check_word(word, &try)) return try;

    // stage-4
    printf("이 단어의 5번째 글자는 '%c' 입니다.\n", Words[widx][0][4]);

    while (try < TRY_MAX) {
        if (check_word(word, &try)) return try;

        if (try == TRY_TRY)
            printf("분발하세요.\n");
        else if (try == TRY_MAX)
            printf("게임에 집중하세요.\n");
    }

    // stage-5
    printf("이 단어의 의미는 '%s' 입니다.\n", Words[widx][1]);
    if (check_word(word, &try)) return try;

    // stage-6
    printf("이 단어는 '%s' 입니다.\n", Words[widx][0]);

    return try;
}

// FUNCTION: hangman_game
//   1. 맞추기(guess_word)를 실행 맞추기까지 시도 회수(try) 획득
//   2. try = -1 이면 즉시 종료 (input = 'x')
//   3. try > 10 (stage-3 초과)이면 실패(fail) 회수 증가
//   4. try <= 10 (stage-3 이내)이면 성공(success) 회수 증가
//   5. 지금까지 성공(success) 회수에 맞추어 H-A-N-G-M-A-N 문자 출력
//   6. 실패(fail)가 5회 이상이면 '게임 패배'로 종료
//   7. 실패(success)가 H-A-N-G-M-A-N을 완료하면(6회) '게임 성공'으로 종료
// RETURN:
//   score: 게임 점수 = (11 - 시도회수) * n차
int hangman_game()
{
    char *hangman = "HANGMAN";
    int fail = 0, success = 0;
    int score = 0, try;
    int n = 0, i;

    printf("\nHANGMAN 게임을 시작합니다.\n\n");
    while (1) {
        printf("%d번째 단어입니다.\n", ++n);
        try = guess_word();
        if (try < 0) return 0; // 즉시 종료 if try = -1
        else if (try > TRY_MAX) { // fail if too many try
            fail++;
            printf("\n[실패 %d]\n\n", fail);
        } else {
            score += TRY_MAX+1 - try;

            success++;
            printf("\n[성공]  ");
            for (i = 0; i < success-1; i++)
                printf("%c-", hangman[i]);
            printf("%c\n\n", hangman[i]);
        }

        if (fail >= TRY_GAME) {
            printf("[게임 패배]\n\n");
            break;
        } else if (success >= strlen(hangman)) { // complete HANGMAN
            printf("[게임 성공]\n\n");
            break;
        }
    }

    return score;
}

// FUNCTION: retry
//   1. 재시작 여부를 물음
//   2. input이 'y' 또는 'n'일 경우만 종료
//   3. 그외 경우 다시 재시작 여부를 물음
// RETURN:
//   1: yes
//   0: no
int retry()
{
    while (1) { // wait Y/N input
        char yn;
        printf("게임을 재시작 하겠습니까 (Y/N)? ");
        scanf("%c", &yn);
        if (yn == 'N' || yn == 'n') return 0;
        else if (yn == 'Y' || yn == 'y') return 1;
    }
}

int main()
{
    srand(time(0)); // 랜덤 초기화

    do {
        int score = hangman_game();
        // TOTO: player score
    } while (retry());

    printf("\n[게임 종료]\n");

    return 0;
}
