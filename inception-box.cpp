/* Author: R.K. Joshi, IIT Bombay */
// to compile: fltk-config --compile demo2.cpp 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include <iostream>
#include <cstdlib>
using namespace std;

static const int tilesize = 30;
static const int xmaxtiles= 14;
static const int ymaxtiles= 20;

class Board;
class Board : public Fl_Widget {
int c1, c2;
public:
	Board();
	void draw();
	void myplot(int level);
	int handle(int e);
};

Board::Board() : Fl_Widget (0,0,500,
			500,"A seed program") {
	
	c1 = 10; c2 = 40;  // initial colors 
}

void Board::myplot(int level) {
		if (level==0) return;
		fl_rect((100-level)*2.5 ,(100-level)*2.5,5*(level),5*(level),rand()%256);
		level = level-1;
		myplot(level);

}

void Board::draw () { // this gets called automatically when redraw() is called 
  myplot(100); // we call myplot once here, and write our recursive code inside myplot
}

int Board::handle(int e) {

}



int main(int argc, char *argv[]) {
    	Fl_Window *window = new Fl_Window (500,500,"DEMO"); // outer window
	window->color(56);   
	Board *b = new Board();
	window->end();  
   	window->show();
    	return(Fl::run());  // the process waits from here on for events
}


