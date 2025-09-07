#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG];
    printf("Введите help для просмотра всех команд.\n");

    while (1) {
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL) { //CTRL + D
            FreeMemory(NULL);
            printf("Ошибка чтения ввода или конец файла.\n");
            break;
        }

        input[strcspn(input, "\n")] = 0;

        char *token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }

        char *command_name = token;
        int i = 0;
        while ((token = strtok(NULL, " ")) != NULL && i < MAX_ARG-1) {
            args[i++] = token;
        }

        args[i] = NULL;


        int found = 0;
        for (int j = 0; commands[j].name != NULL; j++) {
            if (strcmp(command_name, commands[j].name) == 0 && strcmp(command_name, "exit") != 0) {
                if(commands[j].countargs <= i){
                    commands[j].function(args);
                }else{
                    for(; i < commands[j].countargs; i++){
                        args[i] = "0";
                    }
                    args[i] = NULL;
                    commands[j].function(args);
                }
                found = 1;
                break;
            }
        }

        if (! found && strcmp(command_name, "exit") == 0) {
            FreeMemory(NULL);
            printf("Выход из программы.\n");
            break;
        } else if (!found) {
            printf("Неизвестная команда: %s\n", command_name);
        }
    }

    return 0;
}

void help(char **args) {
    for (int j = 0; commands[j].name != NULL; j++) {
        printf("%s - %s\n", commands[j].name, commands[j].discription);
    }
}
