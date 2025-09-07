#include <stdio.h>
#include <stdlib.h>
#include "logicVector3d.h"

char *atomname[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", 
"Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", 
"Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", 
"Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", 
"Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", 
"Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", 
"Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", 
"Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium",
"Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

void atomset(char **args){
    if(atoi(args[1]) < 119){
        listpoints[atoi(args[0])].Atom.atom_number = atoi(args[1])-1;
        listpoints[atoi(args[0])].Atom.is_metall = 1;
        if(atoi(args[1]) == 1){
            listpoints[atoi(args[0])].Atom.group_atom = 1;
            listpoints[atoi(args[0])].Atom.line_atom = 1;
            listpoints[atoi(args[0])].Atom.is_metall = 0;
        }
        else if (atoi(args[1]) == 2)
        {
            listpoints[atoi(args[0])].Atom.group_atom = 18;
            listpoints[atoi(args[0])].Atom.line_atom = 1;
            listpoints[atoi(args[0])].Atom.is_metall = 0;
        }
        else if (atoi(args[1]) > 2 && atoi(args[1]) < 5)
        {
            listpoints[atoi(args[0])].Atom.group_atom = atoi(args[1])-2;
            listpoints[atoi(args[0])].Atom.line_atom = 2;
        }
        else if (atoi(args[1]) > 4 && atoi(args[1]) < 13)
        {
            if(atoi(args[1]) + 8 < 19){
                listpoints[atoi(args[0])].Atom.group_atom = 8 + atoi(args[1]);
                listpoints[atoi(args[0])].Atom.line_atom = 2;
                listpoints[atoi(args[0])].Atom.is_metall = 0;
            }
            else{
                listpoints[atoi(args[0])].Atom.group_atom = atoi(args[1]) - 10;
                listpoints[atoi(args[0])].Atom.line_atom = 3;
            }
        }
        else if (atoi(args[1]) > 12 && atoi(args[1]) < 58)
        {
            int i = atoi(args[1]);
            int n = 3;
            do
            {
                if(i < 19){
                    listpoints[atoi(args[0])].Atom.group_atom = i;
                    listpoints[atoi(args[0])].Atom.line_atom = n;
                }
                else{
                    i -= 18;
                    n++;
                    if(i < 19){
                        listpoints[atoi(args[0])].Atom.group_atom = i;
                        listpoints[atoi(args[0])].Atom.line_atom = n;
                    }
                }
            } while (i > 19);
        }
        else if ((atoi(args[1]) > 57 && atoi(args[1]) < 72))
        {
            listpoints[atoi(args[0])].Atom.group_atom = 3;
            listpoints[atoi(args[0])].Atom.line_atom = 6;
        }
        else if ((atoi(args[1]) > 89 && atoi(args[1]) < 104))
        {
            listpoints[atoi(args[0])].Atom.group_atom = 3;
            listpoints[atoi(args[0])].Atom.line_atom = 7;
        }
        else if (atoi(args[1]) > 71 && atoi(args[1]) < 90)
        {
            int n = 3;
            int i = atoi(args[1])-14;
            do
            {
                if(i < 19){
                    listpoints[atoi(args[0])].Atom.group_atom = i;
                    listpoints[atoi(args[0])].Atom.line_atom = n;
                }
                else{
                    i -= 18;
                    n++;
                    if(i < 19){
                        listpoints[atoi(args[0])].Atom.group_atom = i;
                        listpoints[atoi(args[0])].Atom.line_atom = n;
                    }
                }
            } while (i > 19);
        }
        else if (atoi(args[1]) > 103)
        {
            listpoints[atoi(args[0])].Atom.group_atom = atoi(args[1])-100;
            listpoints[atoi(args[0])].Atom.line_atom = 7;
        }

        if((atoi(args[1]) > 13 && atoi(args[1]) < 19) || (atoi(args[1]) > 312&& atoi(args[1]) < 37) || (atoi(args[1]) > 51 && atoi(args[1]) < 55) || (atoi(args[1]) == 86)){
            listpoints[atoi(args[0])].Atom.is_metall = 0;
        }

        atominform(&args[0]);
    }
    else{
        printf("Максимальное значение 118.\n");
    }
}
void atominform(char **args){
    if(atoi(args[0]) < Pcount && atoi(args[1]) > 0){
        if(listpoints[atoi(args[0])].Atom.group_atom == 0){
            listpoints[atoi(args[0])].Atom.group_atom = 1;
        }
        if(listpoints[atoi(args[0])].Atom.line_atom == 0){
            listpoints[atoi(args[0])].Atom.line_atom = 1;
        }
        printf("%d : %s Atom(%s №%d Group: %d Line: %d IsMetal?: %s)\n", atoi(args[0]),
            listpoints[atoi(args[0])].name,
            atomname[listpoints[atoi(args[0])].Atom.atom_number],
            listpoints[atoi(args[0])].Atom.atom_number+1,
            listpoints[atoi(args[0])].Atom.group_atom,
            listpoints[atoi(args[0])].Atom.line_atom,
            listpoints[atoi(args[0])].Atom.is_metall ? "true" : "false");
    }
    else{
        printf("Точки не существует или введен нулевой элемент.\n");
    }
}