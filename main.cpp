#include "Panel.hpp"

std::string    *creat_mass(int n)
{
    std::string *mass = new std::string[n * 2];
    mass[0] = "Picadilly Gradius (1989)";
    mass[1] = "Only released in Japan, rather than a video  game this spin off game is a token gambling game with a Gradius theme.";
    mass[2] = "Nemesis (1990)";
    mass[3] = "The first Gradius for a portable system, in this case Nintendo's Game Boy";
    mass[4] = "Gradius: The Interstellar Assault (1991)";
    mass[5] = "Another Gradius game exclusively for the Game Boy. ";
    mass[6] = "Salamander 2 (1996)";
    mass[7] = "The follow-up to Salamander.";
    mass[8] = "Gradius Gaiden (1997)";
    mass[9] = "The first Gradius produced exclusively for a home console.";
    mass[10] = "Solar Assault (1997)";
    mass[11] = "Solar Assault is an arcade 3D rail shooter in the lines of Star Fox or Panzer Dragoon, with Gradius's settings.";
    mass[12] = "Gradius IV (1999)";
    mass[13] = "Released in Japanese arcades as Gradius IV Fukkatsu";
    mass[14] = "Gradius Advance (2001)";
    mass[15] = "The first Gradius to be created by a development team other than Konami's own internal teams";    
    return(mass);
}

int main(void)
{
	int key;
    int n = 8;
    initscr();
    start_color();
    std::string *base = creat_mass(n);
    do {
        key=getch();
        if (key == ENTER) 
        {
            Panel panel(base, n);
            panel.draw_menu();
            panel.scroll_menu();
            panel.delete_struct();
        }
        bkgd(COLOR_PAIR(0));
    } while (key!=ESCAPE);
    endwin();
	return 0;
}
