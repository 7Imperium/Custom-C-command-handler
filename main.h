#include <stdlib.h>
#include "logicVector3d.h"


#define MAX_INPUT_SIZE 256
#define MAX_ARG 10

typedef struct {
    char *name;
    void (*function)(char **args);
    int countargs;
    char *discription;
} Command;

void help(char **args);

Command commands[] = {
    {"help", help, 0, "Показывает все команды и их описание."},
    {"pcreate", creationpoit, 4, "Создает точку. [pcreate point-name X Y Z]"},
    {"plist", PrintPointList, 0, "Отображает все созданные точки."},
    {"pcompare", CompareTwoPoints, 2, "Сравнивает две точки. [pcompare ID-first-point ID-second-point]"},
    {"pdistance", DistanceTwoPoints, 2, "Вычисляет дистанцию между двумя точками. [pdistance ID-first-point ID-second-point]"},
    {"pset", SettlerPositionPoint, 4, "Форматированный ввод координат точки. [pset ID-point X Y Z]"},
    {"padd", AddlerPositionPoint, 4, "Изменяет координаты по средству добавления значения к координате. [padd ID-point X Y Z]"},
    {"pinform", PrintInformPoint, 1, "Выводит подробную информацию по точке. [pinform ID-point]"},
    {"pointdel", DelPoint, 1, "Удаление точки. [pointdel ID-point]"},
    {"atomset", atomset, 2, "Устанавливает номер атомной группы атома. [atomset ID-point atom-number]"},
    {"atominform", atominform, 1, "Выводит подробную информацию об атоме. [atominform ID-point]"},
    {"free", FreeMemory, 0, "Очищает память."},
    {"exit", NULL, 0,"Выход из программы."},
    {NULL, NULL}
};