/* Author: R.K. Joshi, IIT Bombay */
// to compile: fltk-config --compile demo2.cpp 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

static const int tilesize = 30;
static const int xmaxtiles= 14;
static const int ymaxtiles= 20;
const int totallevel = 10;
const int sidelength =100;
const float PI = 3.14159;
class Board;
class Board : public Fl_Widget {
int c1, c2;
public:
	Board();
	void draw();
	void myplot(int level,float x,float y);
	int handle(int e);
};

Board::Board() : Fl_Widget (0,0,xmaxtiles*tilesize,
			ymaxtiles*tilesize,"A seed program") {
	
	c1 = 10; c2 = 40;  // initial colors 
}

void Board::myplot(int level,float x0,float y0) {
		if (level==0) return;
		
		float side = float(level)/totallevel*sidelength;
		float xdiff =side*sin((totallevel-level)*10*2*PI/360);
		float ydiff= side*cos((totallevel-level)*10*2*PI/360);
		float xoldcorner= x0+1.1*ydiff;
		float yoldcorner=y0-1.1*xdiff;
		fl_color(20);
		fl_polygon(x0, y0,x0+xdiff,y0+ydiff,x0+xdiff+ydiff,y0+ydiff-xdiff,x0+ydiff,y0-xdiff);
		fl_color(30);
		fl_pie(xoldcorner+0.4*xdiff+0.4*ydiff-0.4*side,yoldcorner-0.4*xdiff+0.4*ydiff-0.4*side,0.8*side,0.8*side,0,360);
		level = level-1;
		myplot(level,x0+xdiff+ydiff/2,y0+ydiff-xdiff/2);

}

void Board::draw () { // this gets called automatically when redraw() is called 
  myplot(totallevel,100,100); // we call myplot once here, and write our recursive code inside myplot
}

int Board::handle(int e) {

        cout << e << "  " << Fl::event_key() << endl;  // try uncommenting it..
        if (e==8)  // means it's a keyboard event
        switch (Fl::event_key()) {  // different keys are sensed here
                case 65361 : c1++; break;
                case 65362 : c2++; break;
                case 65363 : c1++; break;
                case 65364 : c2++; break;
        }
        redraw();
}



int main(int argc, char *argv[]) {
    	Fl_Window *window = new Fl_Window (800,700,"DEMO"); // outer window
	window->color(56);   
	Board *b = new Board();
	window->end();  
   	window->show();
    	return(Fl::run());  // the process waits from here on for events
}

