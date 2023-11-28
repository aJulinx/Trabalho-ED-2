#include "pacient.h"
#include "machine.h"
#include "exam.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int time_unit = 0;
    int machine_quantity = 5;
    
    Pacients *list_meliants = create_meliants();
    
    MachineList *machine_list_create = create_machine_list();

    MachineList *machine_list = initialize_machines(machine_list_create,machine_quantity);

    ExameFila *exam_queue = exam_create();


    //print_machine_status(machine_list);

    //43200 unidades totais
    while (time_unit < 50)
    {   

        int gen_pacient_chance = gen_randint(0, 100);

        if (gen_pacient_chance <= 20)
        {
            Pacient *pacient = create_meliant(time_unit);
            
            int id_pacient = get_pacient_id(pacient);

            meliant_insert(list_meliants ,pacient);

            exam_enqueue(exam_queue,id_pacient,time_unit);
            printf("\n--------------fila de exames---------------\n");
            //exam_print(exam_queue);

            int size_meliants = list_size(list_meliants);
            printf("\n-----------------------------\n");
            printf("quantidade de pacientes atuais: %d\n", size_meliants);
            /*
                VERIFICAR SE TEM MÁQUINA DISPONÍVEL E ALOCAR PARA O PACIENTE ATUAL
            */
            int open_machines = (find_idle_machine(machine_list) + 1); 
            printf("Número de maquinas disponiveis: %d\n------------------\n ", open_machines);

            int id_machine = find_idle_machine(machine_list);

            while(find_idle_machine(machine_list)!=-1 && exam_is_empty(exam_queue)==0)
            {

                
                mark_machine_as_busy(machine_list,id_machine);         
                print_machine_status(machine_list);  
                printf("\n") ;

                print_pacient(pacient);

                
            }   


                           
        } 
        


        time_unit++;
    }
    //printa lista de pacientes
    //print_lista_pacientes(list_meliants);
}