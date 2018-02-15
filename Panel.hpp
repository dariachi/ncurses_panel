#ifndef PANEL_HPP
#define PANEL_HPP

#define ENTER 10
#define ESCAPE 27
#include <iostream>
#include <ncurses.h>

class Panel
{
private:
	int key;
	int selected;
	int i;
	WINDOW **items;
	WINDOW *copie_item;
	std::string *base;
	int count;
public:
	Panel();
	Panel(std::string *base, int n);
	Panel(Panel const &src);
	Panel &operator=(Panel const &src);
	~Panel();
	int scroll_menu(void);
	void delete_menu(void);
	void draw_menu(void);
	void delete_struct(void);
	void renewal(int s, int col);
	int enter_comand(void);
	void    move_p(void);
	void  creat_sub_win(void);
	void    print(void);
	int		getkey(void) const;
	int 	getselected(void) const;
	int 	getI(void) const;
	std::string *getBase(void) const;
	int		getCount(void) const;
};

#endif