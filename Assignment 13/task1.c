#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the Player structure */
typedef struct {
    int id;
    char name[50];
    int age;
    float battingAverage;
    float bowlingAverage;
    // Add more statistic fields if needed
} Player;

/* Function prototypes */
Player *createPlayer();
void displayPlayer(const Player *p);
void freePlayer(Player *p);

int main() {
    // Database for storing players
    Player *players[100]; // Can store up to 100 players
    int playerCount = 0;
    int choice, id, i, found;

    while (1) {
        printf("1. Add a new player\n");
        printf("2. Display player by ID\n");
        printf("3. Display all players\n");
        printf("4. Delete a player by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (playerCount >= 100) {
                    printf("Database is full!\n");
                    break;
                }
                players[playerCount++] = createPlayer();
                break;
            case 2:
                printf("Enter Player ID to display: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < playerCount; i++) {
                    if (players[i]->id == id) {
                        displayPlayer(players[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Player not found!\n");
                }
                break;
            case 3:
                for (i = 0; i < playerCount; i++) {
                    displayPlayer(players[i]);
                }
                break;
            case 4:
                printf("Enter Player ID to delete: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < playerCount; i++) {
                    if (players[i]->id == id) {
                        freePlayer(players[i]);
                        
                        // Shift remaining players
                        for (int j = i; j < playerCount - 1; j++) {
                            players[j] = players[j + 1];
                        }
                        playerCount--;
                        printf("Player deleted successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Player not found!\n");
                }
                break;
            case 5:
                // Free memory and exit
                for (i = 0; i < playerCount; i++) {
                    freePlayer(players[i]);
                }
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0; // Safeguard return
}

/* Functions implementation */
Player *createPlayer() {
    Player *newPlayer = (Player *)malloc(sizeof(Player));
    if (newPlayer == NULL) {
        printf("Failed to allocate memory for new player.\n");
        return NULL;
    }

    printf("Enter Player ID: ");
    scanf("%d", &newPlayer->id);
    printf("Enter Player Name: ");
    scanf("%s", newPlayer->name); // Consider using fgets for multi-word names (not implemented here)
    printf("Enter Player Age: ");
    scanf("%d", &newPlayer->age);
    printf("Enter Batting Average: ");
    scanf("%f", &newPlayer->battingAverage);
    printf("Enter Bowling Average: ");
    scanf("%f", &newPlayer->bowlingAverage);

    return newPlayer;
}

void displayPlayer(const Player *p) {
    if (p != NULL) {
        printf("ID: %d\n", p->id);
        printf("Name: %s\n", p->name);
        printf("Age: %d\n", p->age);
        printf("Batting Average: %.2f\n", p->battingAverage);
        printf("Bowling Average: %.2f\n", p->bowlingAverage);
        // Display more statistics if needed
    }
}

void freePlayer(Player *p) {
    if (p != NULL) {
        free(p);
    }
}