#include <stdio.h>
#include <stdlib.h>
#include "pacient.h"
#include "machine.h"
#include "exam.h"

int main(void) {
    // Declaração e inicialização de elementos contadores.
    int time_unit = 0;
    int count_show = 0;
    int machine_quantity = 5;
    int laud_medium_time = 0;
    int helth_time = 0;
    int helth_cont = 0;
    int bronkaite_time = 0;
    int bronkaite_cont = 0;
    int peneu_time = 0;
    int peneu_cont = 0;
    int femur_broken_time = 0;
    int femur_broken_cont = 0;
    int aprendeu_time = 0;
    int aprendeu_cont = 0;

    // Declaração e inicialização de estruturas.
    Pacients *list_meliants = create_meliants();
    MachineList *machine_list_create = create_machine_list();
    ExameFila *exam_queue = exam_create();

    // Inicialização da lista de máquinas
    MachineList *machine_list = initialize_machines(machine_list_create, machine_quantity);

    // Loop que simula a oficina
    while (time_unit < 60) {
        // Possibilidade de que chegue um paciente.
        int gen_pacient_chance = gen_randint(1, 100);
        printf("%d \n", gen_pacient_chance);

        // Se chegar um paciente, ele é adicionado à lista de pacientes e à fila de exames.
        if (gen_pacient_chance <= 20) {
            Pacient *pacient = create_meliant(time_unit);
            int id_pacient = get_pacient_id(pacient);
            meliant_insert(list_meliants, pacient);
            exam_enqueue(exam_queue, id_pacient, time_unit);
            ExameNode *next_pacient = exam_dequeue(exam_queue);

            if (next_pacient != NULL) {
                int machine_id = find_idle_machine(machine_list);
                if (machine_id != -1) {
                    exam_enqueue(exam_queue, next_pacient->patient_id, time_unit);
                    ExameNode *laud_node = exam_make(next_pacient, machine_id, machine_list, time_unit);
                    exam_enqueue(exam_queue, laud_node->patient_id, time_unit);
                }

                // Convocação de laudo e cálculo de métricas
                ExameNode *next_laud = exam_dequeue(exam_queue);

                if (next_laud != NULL) {
                    int id_radiologist = find_idle_radiologist(radiologist_list);
                    if (id_radiologist != -1) {
                        laud_medium_time += next_laud->time_atend;

                        if (next_laud->gravidade == 1) {
                            helth_time += next_laud->time_atend;
                            helth_cont++;
                        } else if (next_laud->gravidade == 2) {
                            bronkaite_time += next_laud->time_atend;
                            bronkaite_cont++;
                        } else if (next_laud->gravidade == 3) {
                            peneu_time += next_laud->time_atend;
                            peneu_cont++;
                        } else if (next_laud->gravidade == 4) {
                            femur_broken_time += next_laud->time_atend;
                            femur_broken_cont++;
                        } else if (next_laud->gravidade == 4) {
                            aprendeu_time += next_laud->time_atend;
                            aprendeu_cont++;
                        }
                    }
                }
            }
        }

        time_unit++;
        count_show++;
    }

    print_lista_pacientes(list_meliants);
    exam_free(exam_queue);
    free(machine_list_create);
    free(list_meliants);

    return 0;
}
