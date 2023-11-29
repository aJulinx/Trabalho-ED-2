#ifndef PACIENT_H
#define PACIENT_H

typedef struct pacientes Pacients;
typedef struct paciente Pacient;

Pacient *create_meliant(int t_in);

Pacients *create_meliants();

void meliant_insert(Pacients *meliants, Pacient *pacient);

int list_size(Pacients *meliants);

int gen_randint(int initial_number, int final_number);

void print_pacient(Pacient *pacient);

void print_lista_pacientes(struct pacientes *list_pacients);

int get_pacient_id(Pacient *pacient);

//void print_pacient_using_id(Pacients *list_pacients, int *id_);


#endif