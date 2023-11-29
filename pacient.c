#include "pacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct paciente
{
    char name[50];
    char cpf[12];
    int age;
    int id;
    int t_in;
     // int t_exam;
    //int t_out;
    /*char condition [30];
    int gravidade;*/
};

struct pacientes
{   
    int n;                     // quantidade de meliantes 
    int n_max;                 // capacidade total de meliantes
    
    struct paciente **meliants_vector; // vetor de meliantes
};

int gen_randint(int initial_number, int final_number)
{
    return initial_number + rand()%(final_number - initial_number + 1);
};

int gen_age()
{    
    return gen_randint(0,100);
};

void gen_cpf(Pacient *pacient)
{
    for (int i = 0; i < 11 ; i++)
    {
        pacient->cpf[i] = gen_randint('0','9');
    }
    pacient->cpf[11] = '\0';
};

void gen_name(Pacient *pacient)
{
    pacient->name[0] = gen_randint('A','Z');
    for (int i = 1; i <= 49 ; i++)
    {
        pacient->name[i] = gen_randint('a','z');
    }
};

Pacient *create_meliant(int t_in)
{
    static int id = 1;
    struct paciente *pacient = (struct paciente *)malloc(sizeof(struct paciente));
    gen_name(pacient);
    pacient->age = gen_age();
    gen_cpf(pacient);
    pacient->id = id++;
    pacient->t_in = t_in;
    /*pacient->t_exam = gen_randint(5,10);
    pacient->t_out = 0;
    strcpy(pacient->condition,"desconhecido");
    pacient->gravidade = 0;*/
    return pacient;
};

Pacients *create_meliants()
{
    struct pacientes *meliants = (struct pacientes *)malloc(sizeof(struct pacientes));                  // Allocate memory for the Pacients structure
    meliants->n = 0;                                                                                    // Initialize the number of elements to 0
    meliants->n_max = 4;                                                                                // Allocate initially space for 4 elements
    meliants->meliants_vector = (struct paciente **)malloc(meliants->n_max * sizeof(struct paciente *)); // Allocate memory for the vector data

    return meliants; // Return a pointer to the created dynamic vector
};

// Helper function to reallocate memory for the dynamic vector
static void reallocate(Pacients *meliants)
{
   meliants->n_max *= 2;                                                                                           // Double the capacity
   meliants->meliants_vector = (struct paciente **)realloc(meliants->meliants_vector, meliants->n_max * sizeof(struct paciente*));// Reallocate memory for the vector data
};

void meliant_insert(Pacients *meliants, Pacient *pacient)
{
   // Check if the capacity is enough, and if not, reallocate memory
   if (meliants->n == meliants->n_max)
   {
        reallocate(meliants);
   }
   meliants->meliants_vector[meliants->n++] = pacient; // Insert the pacient and increment the size
};

// Function to get the current size (number of elements) of the dynamic vector
int list_size(Pacients *meliants)
{
   return (meliants->n);
};

void print_pacient(Pacient *pacient)
{
    printf("nome do paciente: %s \n" ,pacient->name);
    printf("cpf do paciente: %s \n" ,pacient->cpf);
    printf("idade do paciente: %d \n" ,pacient->age);
    printf("Identificação do paciente: %d \n" ,pacient->id);
    printf("Tempo de entrada do paciente: %d \n" ,pacient->t_in);
    //printf("Tempo de exame do paciente: %d \n" ,pacient->t_exam);    
    //printf("Tempo de saida do paciente: %d \n" ,pacient->t_out);
}

void print_lista_pacientes(struct pacientes *list_pacients)
{
    for (int i = 0; i < list_pacients->n; i++)
    {
        struct paciente *paciente_atual = list_pacients->meliants_vector[i];
        //int *id = paciente_atual->id;
        print_pacient(paciente_atual);
        //printf("id do vagabundo: %d \n", id);
    }
};

int get_pacient_id(Pacient *pacient)
{
    return (pacient->id);

};


