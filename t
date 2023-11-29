/*
                VERIFICAR SE TEM MÁQUINA DISPONÍVEL E ALOCAR PARA O PACIENTE ATUAL
            */

           
            /*Realización de convocatoria de informe y cómputo de métricas
            
            ExamNode *next_laud = laud_dequeue(laud_queue);
            if(next_laud!=NULL){
                int id_radiologist = find_idle_radiologist(radiologist_list);
                if(id_radiologist!=-1){
                    Laud *laud_after_node = laud_make(id_radiologist, next_laud, time_unit);
                    laud_after = laud_enqueuE(laud_after_node);                   
                    laud_medium_time += laud_after_node->time_laud;
                    if(gravidade == 1;){
                        helth_time +=laud_after_node->time_laud;
                        helth_cont++;
                    }
                    else if(gravidade == 2;){
                        bronkaite_time +=laud_after_node->time_laud;
                        bronkaite_cont++;
                    }
                    else if(gravidade == 3;){
                        peneu_time +=laud_after_node->time_laud;
                        peneu_cont++;
                    }
                    else if(gravidade == 4;){
                        femur_broken_time +=laud_after_node->time_laud;
                        femur_broken_cont++;
                    }
                    else if(gravidade == 4;){
                        aprendeu_time +=laud_after_node->time_laud;
                        aprendeu_cont++;
                    }
                    }
                    }
            */

           /*Mostrar métricas en pantalla y pausar el bucle durante 10 segundos
            if(count_show==10){
                sleep(10);
                printf("Tempo médio para laudo %d \n\n", laud_medium_time);
                printf("Tempo médio por patologia \n Saude Normal: %d \n Bronquite: %d \n Pneumonia: %d \n Fratura de Femur: %d \n Apendicite: %d \n\n", 
                    (helth_time/helth_cont), (bronkaite_time/bronkaite_cont), (peneu_time/peneu_cont), (femur_broken_time/femur_broken_cont), (aprendeu_time/aprendeu_cont));
                printf("Exames realizados após o tempo: %d", after_time_exams);
                count_show=0;

            }*/