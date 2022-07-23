#include <ncurses.h>
#include <stdlib.h>
#include "accprec.h"

int main(){
	initscr();
	cbreak();
	noecho();
	start_color();
	
	int selectionx[10];
	int selectiony[10];
	double x[10];
	double y[10];
	int size = 10;

	init_pair(1,COLOR_CYAN,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_BLACK,COLOR_WHITE);
	init_pair(4,COLOR_WHITE,COLOR_GREEN);
	
	WINDOW * infowin = newwin(3,56,0,0);
	WINDOW * ctrlwin = newwin(4,50,14,0);
	WINDOW * tarbck = newwin(9,16,4,4);
	WINDOW * target = newwin(7,14,5,5);
	WINDOW * seltbl = newwin(14,18,0,56);
	WINDOW * stttbl = newwin(4,24,14,50);
	WINDOW * xtrtbl = newwin(6,74,18,0);

	box(infowin,0,0);	box(tarbck,0,0);
	box(ctrlwin,0,0);	box(seltbl,0,0);
	box(stttbl,0,0);	box(xtrtbl,0,0);

	wattron(stdscr,COLOR_PAIR(1));	wbkgd(stdscr,COLOR_PAIR(1));
	wattron(tarbck,COLOR_PAIR(2));	wbkgd(tarbck,COLOR_PAIR(2));
	wattron(target,COLOR_PAIR(3));	wbkgd(target,COLOR_PAIR(3));
	wattron(infowin,COLOR_PAIR(3));	wbkgd(infowin,COLOR_PAIR(3));
	wattron(ctrlwin,COLOR_PAIR(3));	wbkgd(ctrlwin,COLOR_PAIR(3));
	wattron(seltbl,COLOR_PAIR(3));	wbkgd(seltbl,COLOR_PAIR(3));
	wattron(stttbl,COLOR_PAIR(3));	wbkgd(stttbl,COLOR_PAIR(3));
	wattron(xtrtbl,COLOR_PAIR(3));	wbkgd(xtrtbl,COLOR_PAIR(3));

	mvwprintw(ctrlwin,1,1,"Use arrow keys to move cursor.");
	mvwprintw(ctrlwin,2,1,"Press RETURN to select space.");
	mvwprintw(seltbl,1,1,"Selections:");
	mvwprintw(seltbl,2,1,"X:	Y:");
	mvwprintw(stttbl,1,1,"Accuracy:");
	mvwprintw(stttbl,2,1,"Precision:");
	mvwprintw(xtrtbl,1,1,"ACT's Accuracy/Precision Example");
	mvwprintw(xtrtbl,2,1,"Version 1.0	|	23/07/22");
	mvwprintw(xtrtbl,3,1,"https://github.com/act17/accprec");
	mvwprintw(xtrtbl,4,1,"Released under the LGPL 2.1");
	
	noecho();
	refresh();
	wrefresh(target); 	wrefresh(tarbck);
	wrefresh(infowin);	wrefresh(ctrlwin);
	wrefresh(seltbl);	wrefresh(stttbl);
	wrefresh(xtrtbl);

	keypad(infowin,true);
	
	int choice;
	int highlighta = 1;
	int highlightb = 1;
	int value = 0;
	int tablevalue = 3;

	do{
		mvwprintw(infowin,1,1,"X: %d Y: %d",highlighta,highlightb);
		if(highlightb < 10)			//Display error prevention
			mvwprintw(infowin,1,10,"           ");
		if(highlighta == 4 && highlightb == 7){
			wattron(infowin,COLOR_PAIR(4));
			mvwprintw(infowin,1,12,"Centered!");
			wattron(infowin,COLOR_PAIR(3));
		}
		for(int i = 1; i < 8; i++){
		for(int j = 1; j < 15; j++){
			if(i == highlighta && j == highlightb)
				wattron(target,A_REVERSE);
			mvwprintw(target,i-1,j-1," ");
			wattroff(target,A_REVERSE);
		}
		wrefresh(target);
		wrefresh(infowin);	
		}
		choice = wgetch(infowin);
		switch(choice){
			case KEY_UP:
				if(highlighta == 1)
					break;
				highlighta--;
			break;
			case KEY_DOWN:
				if(highlighta == 7)
					break;
				highlighta++;
				break;
			case KEY_LEFT:
				if(highlightb == 1)
					break;
				highlightb--;
				break;
			case KEY_RIGHT:
				if(highlightb == 14)
					break;
				highlightb++;
				break;
			case 10:
				selectionx[value] = highlighta;
				selectiony[value] = highlightb;
				mvwprintw(seltbl,tablevalue,1,"%d	%d",selectionx[value],selectiony[value]);
				value++;
				tablevalue++;
				wrefresh(seltbl);
			default:
				break;
		}
	}while(value < size);
	for(int i = 0; i < size; i++){
		x[i] = selectionx[i];
		y[i] = selectiony[i];
	}
	double acc = accuracy(x,y,4,7,size);
	double prc = precision(x,y,14.652,size);
	mvwprintw(stttbl,1,11,"%lf %",acc*100);
	mvwprintw(stttbl,2,12,"%lf %",prc*100);
	wrefresh(stttbl);
	getch();	
	clear();
	endwin();
	return 0;
}
