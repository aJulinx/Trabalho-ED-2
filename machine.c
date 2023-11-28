#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

struct machine_node
{
    int is_occupied;
    int id_machine;
    int time_occupied;
    struct machine_node *next;
};

struct machines_list
{
    MachineNode *first;
};

MachineList *create_machine_list() {
    MachineList *list = (MachineList *)malloc(sizeof(MachineList));
    list->first = NULL;
    
    return list;
}

MachineNode *create_machine_node(int id) {
    MachineNode *new_node = (MachineNode *)malloc(sizeof(MachineNode));

    new_node->id_machine = id;
    new_node->is_occupied = 0;
    new_node->time_occupied = 0;
    new_node->next = NULL;

    return new_node;
}

int get_machine_id(MachineNode *node)
{
    return node->id_machine;
};



void add_machine(MachineList *list, int id) {
    MachineNode *new_node = create_machine_node(id);
    new_node->next = list->first;
    list->first = new_node;
}

int find_idle_machine(MachineList *list) {
    MachineNode *current = list->first;

    while (current != NULL) {
        if (current->is_occupied == 0) {
            return current->id_machine;
        }
        current = current->next;
    }

    return -1;
}

void mark_machine_as_busy(MachineList *list, int id) {
    MachineNode *current = list->first;

    while (current != NULL) {
        if (current->id_machine == id) {
            current->is_occupied = 1;
            return;
        }
        current = current->next;
    }
}

void release_machine(MachineList *list, int id) {
    MachineNode *current = list->first;

    while (current != NULL) {
        if (current->id_machine == id) {
            current->is_occupied = 0;
            return;
        }
        current = current->next;
    }
}

void print_machine_status(MachineList *list) {
    MachineNode *current = list->first;

    while (current != NULL) {
        printf("Máquina %d: %s\n", current->id_machine,
               current->is_occupied ? "Ocupada" : "Ociosa");
        current = current->next;
    }
}

void free_machine_list(MachineList *list) {
    MachineNode *current = list->first;
    MachineNode *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->first = NULL;
}

MachineList *initialize_machines (MachineList *list, int number){

    for(int i=0;i<number;i++)
    {
        add_machine(list,i);
    }
    return list;
}

void get_pacient_exam_time()
{
    
}