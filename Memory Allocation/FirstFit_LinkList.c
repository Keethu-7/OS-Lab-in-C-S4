#include <stdio.h>
#include <stdlib.h>

struct Block {
    int size;
    int id;
    struct Block* next;
};

struct Process {
    int size;
    int block_id;
};


struct Block* createBlock(int size, int id) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->size = size;
    newBlock->id = id;
    newBlock->next = NULL;
    return newBlock;
}


void addBlock(struct Block** head, int size, int id) {
    struct Block* newBlock = createBlock(size, id);
    if (*head == NULL) {
        *head = newBlock;
    } else {
        struct Block* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBlock;
    }
}

int main() {
    struct Block* head = NULL;
    int bno, pno, i;
    
    printf("Enter number of blocks: ");
    scanf("%d", &bno);
    printf("Enter size of each block:\n");
    for (i = 0; i < bno; i++) {
        int size;
        printf("Block %d size: ", i + 1);
        scanf("%d", &size);
        addBlock(&head, size, i + 1);
    }

    printf("Enter number of processes: ");
    scanf("%d", &pno);
    struct Process processes[pno];
    
    printf("Enter size of each process:\n");
    for (i = 0; i < pno; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processes[i].size);
        processes[i].block_id = -1;
    }

    for (i = 0; i < pno; i++) {
        struct Block* temp = head;
        while (temp != NULL) {
            if (temp->size >= processes[i].size) {
                processes[i].block_id = temp->id;
                temp->size -= processes[i].size;
                break;
            }
            temp = temp->next;
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i].size);
        if (processes[i].block_id != -1) {
            printf("%d\n", processes[i].block_id);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}
