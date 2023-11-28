#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exam.h"
#include "pacient.h"

struct ExameNode {
    int patient_id;
    int timestamp;
    char condition[20];
    struct ExameNode *next;
};

struct ExameFila {
    struct ExameNode *front;
    struct ExameNode *rear;
};

typedef struct ExameNode ExameNode;
typedef struct ExameFila ExameFila;

ExameFila *exam_create() {
    ExameFila *exam_q = (ExameFila *)malloc(sizeof(ExameFila));
    if (exam_q == NULL) {
        perror("Failed to create exam queue");
        exit(EXIT_FAILURE);
    }
    exam_q->front = exam_q->rear = NULL;
    return exam_q;
}

int exam_is_empty(ExameFila *exam_q) {
    if(exam_q->front == NULL){
        return 0;
    }

    return 1;
}

void exam_enqueue(ExameFila *exam_q, int patient_id, int timestamp) {
    ExameNode *node = (ExameNode *)malloc(sizeof(ExameNode));
    if (node == NULL) {
        perror("Failed to enqueue exam");
        exit(EXIT_FAILURE);
    }

    node->patient_id = patient_id;
    node->timestamp = timestamp;
    node->next = NULL;

    if (exam_is_empty(exam_q)) {
        exam_q->front = node;
    } else {
        exam_q->rear->next = node;
    }

    exam_q->rear = node;
}

ExameNode *exam_dequeue(ExameFila *exam_q) {
    assert(!exam_is_empty(exam_q));

    ExameNode *record = exam_q->front;
    exam_q->front = exam_q->front->next;

    if (exam_q->front == NULL) {
        exam_q->rear = NULL;
    }

    return record;
}

void exam_free(ExameFila *exam_q) {
    ExameNode *p = exam_q->front;
    while (p != NULL) {
        ExameNode *t = p->next;
        free(p);
        p = t;
    }
    free(exam_q);
}

void exam_print(ExameFila *exam_q) {
    if (exam_is_empty(exam_q)) {
        printf("Queue is empty\n");
        return;
    }

    for (ExameNode *p = exam_q->front; p != NULL; p = p->next) {
        printf("Patient ID: %d, Timestamp: %d\n", p->patient_id, p->timestamp);
    }

    printf("\n");
}

