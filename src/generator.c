#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ROADS 4
const char* ROAD_FILES[] = {"lanea.txt", "laneb.txt", "lanec.txt", "laned.txt"};

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ROADS; i++) {
        FILE* file = fopen(ROAD_FILES[i], "a");
        if (file == NULL) {
            printf("Error opening file %s\n", ROAD_FILES[i]);
            return 1;
        }
        // Generate 10 vehicles per road for example
        for (int j = 0; j < 10; j++) {
            int turn = rand() % 3; // 0: NONE, 1: LEFT, 2: RIGHT
            const char* turn_str = (turn == 0) ? "NONE" : (turn == 1) ? "LEFT" : "RIGHT";
            int vehicle_id = rand() % 1000; // Simple ID
            fprintf(file, "%d,%s\n", vehicle_id, turn_str);
        }
        fclose(file);
    }
    return 0;
}