#ifndef MACHINE_H
#define MACHINE_H

typedef struct machine_node MachineNode;
typedef struct machines_list MachineList;

MachineList *create_machine_list();

MachineNode *create_machine_node(int id);

void add_machine(MachineList *list, int id);

int find_idle_machine(MachineList *list);

void mark_machine_as_busy(MachineList *list, int id);

void release_machine(MachineList *list, int id);

void print_machine_status(MachineList *list);

void free_machine_list(MachineList *list);

int get_machine_id(MachineNode *node);

MachineList *initialize_machines (MachineList *list, int number);



#endif
