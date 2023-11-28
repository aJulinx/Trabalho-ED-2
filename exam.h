#ifndef EXAM_H
#define EXAM_H

typedef struct ExameFila ExameFila;
typedef struct ExameNode ExameNode;

ExameFila *exam_create();

int exam_is_empty(ExameFila *exam_q);

void exam_enqueue(ExameFila *exam_q, int patient_id, int timestamp);

ExameNode *exam_dequeue(ExameFila *exam_q);

void exam_free(ExameFila *exam_q);

void exam_print(ExameFila *exam_q);

#endif
