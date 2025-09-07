#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "logicVector3d.h"

point *listpoints;// создание массива типа структуры Point
int Pcount = 0;

void creationpoit(char **args){ // Создание точки
    Pcount++;
    if(listpoints == NULL){ // Если память не была выделена
        listpoints = (point*)malloc(Pcount * sizeof(point)); // Выделение памяти
    }
    else{
        listpoints = (point*)realloc(listpoints, Pcount * sizeof(point)); // иначе выделить память на новое колличество ячеек массива
    }
    if(listpoints == NULL){ //Если после выделение массив все равно пуст, значит выделить память не удалось
        printf("Ошибка выделения памяти.\n");
    }
    else{
        listpoints[Pcount-1].name = strdup(args[0]); // установка имени
        listpoints[Pcount-1].Position.X = atof(args[1]); // начальных координат
        listpoints[Pcount-1].Position.Y = atof(args[2]);
        listpoints[Pcount-1].Position.Z = atof(args[3]);
        printf("Точка %s создана в (%.2f,%.2f,%.2f).\n", listpoints[Pcount-1].name, atof(args[1]), atof(args[2]), atof(args[3]));
    }
}

void PrintPointList(char **args){
    if(listpoints != NULL){
        for(int i = 0; i < Pcount; i++){ // повторить столько раз сколько у нас колличество точек
            printf("%d: %s\n", i, listpoints[i].name); // отображение имени и ID точки
        }
    }
    else{
        printf("Нет доступных точек.\n");
    }
}

void CompareTwoPoints(char **args){ // Сравнение точек
    if(atoi(args[0]) < Pcount && atoi(args[1]) < Pcount){
        if(fabs(listpoints[atoi(args[0])].Position.X) > fabs(listpoints[atoi(args[1])].Position.X)){ // Использованеи модуля для подсчета отрицательных чисел
            printf("Точка %s по X дальше от нуля чем %s на: %.1f\n", listpoints[atoi(args[0])].name, listpoints[atoi(args[1])].name, fabs(listpoints[atoi(args[0])].Position.X) - fabs(listpoints[atoi(args[1])].Position.X));
        }
        else if(fabs(listpoints[atoi(args[0])].Position.X) < fabs(listpoints[atoi(args[1])].Position.X)){ // исключение ==
            printf("Точка %s по X ближе к нулю чем %s на: %.1f\n", listpoints[atoi(args[0])].name, listpoints[atoi(args[1])].name, fabs(listpoints[atoi(args[0])].Position.X) - fabs(listpoints[atoi(args[1])].Position.X));
        }
        else{
            printf("Позиции по X равны\n");
        }
        if(fabs(listpoints[atoi(args[0])].Position.Y) > fabs(listpoints[atoi(args[1])].Position.Y)){ // тоже самое для все остальных осей
            printf("Точка %s по Y дальше от нуля чем %s на: %.1f\n", listpoints[atoi(args[0])].name, listpoints[atoi(args[1])].name, fabs(listpoints[atoi(args[0])].Position.Y) - fabs(listpoints[atoi(args[1])].Position.Y));
        }
        else if(fabs(listpoints[atoi(args[0])].Position.Y) < fabs(listpoints[atoi(args[1])].Position.Y)){
            printf("Точка %s по Y ближе к нулю чем %s на: %.1f\n", listpoints[atoi(args[0])].name, listpoints[atoi(args[1])].name, fabs(listpoints[atoi(args[0])].Position.Y) - fabs(listpoints[atoi(args[1])].Position.Y));
        }
        else{
            printf("Позиции по Y равны\n");
        }
        if(fabs(listpoints[atoi(args[0])].Position.Z) > fabs(listpoints[atoi(args[1])].Position.Z)){
            printf("Точка %s по Z дальше от нуля чем %s на: %.1f\n", listpoints[atoi(args[0])].name, listpoints[atoi(args[1])].name, fabs(listpoints[atoi(args[0])].Position.Z) - fabs(listpoints[atoi(args[1])].Position.Z));
        }
        else if(fabs(listpoints[atoi(args[0])].Position.Z) < fabs(listpoints[atoi(args[1])].Position.Z)){
            printf("Точка %s по Z ближе к нулю чем %s на: %.1f\n", listpoints[atoi(args[0])].name, listpoints[atoi(args[1])].name, fabs(listpoints[atoi(args[0])].Position.Z) - fabs(listpoints[atoi(args[1])].Position.Z));
        }
        else{
            printf("Позиции по Z равны\n");
        }
    }
    else{
        printf("Неверный ID точки.\n");
    }
}

void DistanceTwoPoints(char **args){ // формула для дистанции
    if(atoi(args[0]) < Pcount && atoi(args[1]) < Pcount){
        printf("Расстояние от точки %s до точки %s: %.2f\n", listpoints[atoi(args[0])].name, listpoints[atoi(args[1])].name, sqrtf(powf((listpoints[atoi(args[0])].Position.X - listpoints[atoi(args[1])].Position.X), 2) + powf((listpoints[atoi(args[0])].Position.Y - listpoints[atoi(args[1])].Position.Y), 2) + powf((listpoints[atoi(args[0])].Position.Z - listpoints[atoi(args[1])].Position.Z), 2)));
    }
    else{
        printf("Неверный ID точки.\n");
    }
}

void SettlerPositionPoint(char **args){ // установка форматированного ввода координат
    listpoints[atoi(args[0])].Position.X = atof(args[1]);
    listpoints[atoi(args[0])].Position.Y = atof(args[2]);
    listpoints[atoi(args[0])].Position.Z = atof(args[3]);
    printf("Координаты точки изменены.\n");
    PrintInformPoint(&args[0]);
}

void AddlerPositionPoint(char **args){
    if(atoi(args[0]) < Pcount){
        listpoints[atoi(args[0])].Position.X += atof(args[1]);
        listpoints[atoi(args[0])].Position.Y += atof(args[2]);
        listpoints[atoi(args[0])].Position.Z += atof(args[3]);
        PrintInformPoint(&args[0]);
    }
    else{
        printf("Такой точки не существует.\n");
    }
}

void PrintInformPoint(char **args){ //подробная информация о точке
    if(atoi(args[0]) < Pcount){
        printf("%d: %s Position:(X:%.2f, Y:%.2f, Z:%.2f)\n", atoi(args[0]), listpoints[atoi(args[0])].name, 
        listpoints[atoi(args[0])].Position.X,
        listpoints[atoi(args[0])].Position.Y,
        listpoints[atoi(args[0])].Position.Z);
    }
    else{
        printf("Такой точки не существует.\n");
    }
}
void DelPoint(char ** args){
    if(listpoints[atoi(args[0])+1].name != NULL){
        for(int i = atoi(args[0]); listpoints[i+1].name != NULL; i++){
            listpoints[i] = listpoints[i+1];
        }
        Pcount--;
        listpoints = (point*)realloc(listpoints, Pcount * sizeof(point));
    }
}

void FreeMemory(char **args){
    if(listpoints != NULL){
        Pcount = 0;
        free(listpoints); // просто очистка памяти :)
        listpoints = NULL;
        printf("Память очищена.\n");
    }
    else{
        printf("Память не была выделена.\n");
    }
}