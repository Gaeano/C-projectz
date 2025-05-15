#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * score;
    int count;
    int length;
}HighScores;


HighScores* createArrayList(int initialCapacity);
void addScore (HighScores* score, int value);
HighScores* getScore (HighScores* scores);
void freeArray(HighScores* score);
void swap(int* a, int* b);

int main (){
    int initialCapacity = 2;

    HighScores * scorez = createArrayList(initialCapacity);
    
    int choice, value;
    while (1){
        printf("--VIDEO GAME HIGH SCORES--\n");
        printf("1. Add new score\n2. View high scores\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
            printf("Enter player score: ");
            scanf("%d", &value);
            getchar();
            addScore(scorez, value);
            printf("\n");
            break;
            
            case 2:
            printf("\n");
            getScore(scorez);
            for (int i = 0 ; i < scorez->count; i++){
                printf("%d: %d\n", i+1, scorez->score[i]);
            }
            printf("\n");
            
            break;
            case 3:
            freeArray(scorez);
            exit(1);
            break;
            default:
            printf("wrong choice try again\n");
            break;
        }
    }

}

HighScores* createArrayList(int initialCapacity){
    HighScores* scores = malloc (sizeof(HighScores));
    if (scores == NULL){
        printf("Memory alloc for array list failed\n");
        exit(1);
    }

    scores->score = malloc (initialCapacity * sizeof(int));
    if (scores->score == NULL){
        printf("memory alloc for array failed\n");
        exit(1);
    }

    scores->count = 0;
    scores->length = initialCapacity;
    return scores;

}

void addScore (HighScores* score, int value){
    if (score->length == score->count){
        score->length *= 2;

        score->score = realloc(score->score, score->length * sizeof(int));
        if (score->score == NULL){
            printf("memory alloc failed\n");
        }
    }

    score->score[score->count] = value;
    score->count++;
}


HighScores* getScore (HighScores* scores){
    for (int i = 0 ; i < scores->count - 1; i++){
        for (int j = 0; j < scores->count - 1 - i; j++){
            if (scores->score[j] < scores->score[j+1]){
                swap(&scores->score[j], &scores->score[j+1]);
            }
        }
    }
    return scores;

}

void freeArray(HighScores* score){
    free(score->score);
    free(score);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
