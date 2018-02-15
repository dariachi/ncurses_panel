#include "Panel.hpp"

Panel::Panel() {}

Panel::Panel(std::string *base, int n) : key(0), selected(0), i(0), base(base), count(n)
{
    // start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    //init_pair(3,COLOR_RED,COLOR_WHITE);
    // bkgd(COLOR_PAIR(1));
    curs_set(0);
    noecho();
    keypad(stdscr,TRUE);
}

Panel::Panel(Panel const &src)
{
    *this = src;
}

Panel &Panel::operator=(Panel const &src)
{
    this->key = src.key;
    this->selected = src.selected;
    this->i = src.i;
    this->base = src.base;
    this->count = src.count;
    return(*this);
}

Panel::~Panel(void) {
    return ;
}

void    Panel::renewal(int s, int col)
{
    wbkgd(items[s],COLOR_PAIR(col));
    wnoutrefresh(items[s]);
}

int Panel::enter_comand(void)
{
    copie_item = items[0];
    delete_menu();
    wclear(copie_item);
    mvwprintw(copie_item, 1, 1,  "%s", base[selected * 2 + 1].c_str());
    wnoutrefresh(copie_item);
    doupdate();
    wrefresh(copie_item);
    return 1;
}

void    Panel::move_p(void)
{
    renewal(selected+1, 2);
    if (key==KEY_DOWN)
        selected=(selected+1) % count;
    else
        selected=(selected+count-1) % count;
    renewal(selected+1, 1);
    doupdate();
}

int Panel::scroll_menu(void)
{
    int u = 0;
    while (1) {
        key=getch();
        if ((key==KEY_DOWN || key==KEY_UP) && u !=1)
            move_p();
        else if (key==ESCAPE)
            return -1;
        else if (key==ENTER && u!= 1)
            u = enter_comand();
    }
    return selected;
}

void Panel::delete_struct()
{
    delwin(items[0]);
    delete(items);
}
    
void Panel::delete_menu(void)
{
    for (int i = 1;i < count;i++)
        delwin(items[i]);
}

void  Panel::creat_sub_win(void)
{
    int start_col = 20;
    for(int k = 1; k < count+1; k++)
        items[k]=subwin(items[0],1,42,k+1,start_col+1);
}

void    Panel::print(void)
{
    for (i = 1; i < count+1;i++)
        wprintw(items[i],"%s", base[(i-1)*2].c_str()); 
}

void Panel::draw_menu(void)
{
    items = new WINDOW*[count + 1];
    items[0]=newwin(15,45,1,20);
    wbkgd(items[0],COLOR_PAIR(2));
    box(items[0],ACS_VLINE,ACS_HLINE);
    creat_sub_win();
    print();
    wbkgd(items[1],COLOR_PAIR(1));
    wrefresh(items[0]);
}

int     Panel::getkey(void) const{
    return(this->key);
}

int     Panel::getselected(void) const{
    return(this->selected);
}
int     Panel::getI(void) const{
    return(this->i);
}
std::string *Panel::getBase(void) const{
    return(this->base);
}
int     Panel::getCount(void) const{
    return(this->count);
}
