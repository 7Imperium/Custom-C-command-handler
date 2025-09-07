#include "bitstruct.h"
typedef struct PositionVector3 // структура позции
{
    float X;
    float Y;
    float Z;
} PositionV; //Краткое обозначение
typedef struct point3D //Структура точки
{
    char *name;
    PositionV Position; //Вдоженная структура
    atom Atom;
} point;
extern point *listpoints;
extern int Pcount;
void creationpoit(char **args); // Создание точки
void PrintPointList(char **args); // Отображение всех доступных точек
void CompareTwoPoints(char **args); // Сравнение двух точек
void DistanceTwoPoints(char **args); // Дистанция между двумя точками
void SettlerPositionPoint(char **args); // Форматированный ввод
void AddlerPositionPoint(char **args); // Добавление ++ -- к осям (ADDLER и номер оси)
void PrintInformPoint(char **args);  // Подробная информация по точке
void FreeMemory(char **args); // очистка памяти
void DelPoint(char ** args);