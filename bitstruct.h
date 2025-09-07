typedef struct bitstructAtom
{
    unsigned int atom_number :7; // unsigned для исключения отрицательных значений
    unsigned int group_atom :5;
    unsigned int line_atom :3;
    unsigned int is_metall :1;
}atom;

void atomset(char **args);
void atominform(char **args);