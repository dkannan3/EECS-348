#include <stdio.h>
#include <string.h>

void find_combinations(int score, int current_score, char* path, int current_play) {
    int plays[] = {8, 7, 6, 3, 2};  
    char play_names[][20] = {"TD + 2pt", "TD + FG", "TD", "3pt + FG", "Safety"};
    
    if (score == current_score) {
        printf("%s\n",path);
        return;
    }

    for (int i = current_play; i < 5; i++) {
        if (current_score + plays[i] <= score) {
            char new_path[100];
            if (current_score > 0) {
                snprintf(new_path, sizeof(new_path), "%s, %s", path, play_names[i]);
            } else {
                snprintf(new_path, sizeof(new_path), "%s", play_names[i]);
            }
            find_combinations(score, current_score + plays[i], new_path, i);
        }
    }
}

int main() {
    int score;
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    
    printf("Possible combinations of scoring plays:\n");
    char path[100] = "";
    find_combinations(score, 0, path, 0);

    return 0;
}

