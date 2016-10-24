/* Author: R.K. Joshi, IIT Bombay */
// to compile: fltk-config --compile demo2.cpp 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include <iostream>
#include <cstdlib>
#include <cmath> 
using namespace std;

static const int tilesize = 30;
static const int xmaxtiles= 14;
static const int ymaxtiles= 20;
const int totallevel=20;
const float PI=3.14159;
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
		int radius=360;
		while(radius>0){
				fl_draw_box(FL_FLAT_BOX,250+radius*cos((float(radius)/360)*5*2*PI+(float(level)/totallevel)*2*PI),250+radius*sin((float(radius)/360)*5*2*PI+(float(level)/totallevel)*2*PI),
				float(radius)/20,float(radius)/20,c1);
				radius=radius-5;
			}
		level = level-1;
		myplot(level);

}

void Board::draw () { // this gets called automatically when redraw() is called 
  myplot(totallevel); // we call myplot once here, and write our recursive code inside myplot
}

int Board::handle(int e) {

       /* cout << e << "  " << Fl::event_key() << endl;  // try uncommenting it..
        if (e==8)  // means it's a keyboard event
        switch (Fl::event_key()) {  // different keys are sensed here
                case 65361 : c1++; break;
                case 65362 : c2++; break;
                case 65363 : c1++; break;
                case 65364 : c2++; break;
        }
        redraw();*/
}



int main(int argc, char *argv[]) {
    	Fl_Window *window = new Fl_Window (500,500,"DEMO"); // outer window
	window->color(56);   
	Board *b = new Board();
	window->end();  
   	window->show();
    	return(Fl::run());  // the process waits from here on for events
}


