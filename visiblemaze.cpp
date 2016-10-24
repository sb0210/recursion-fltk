/* Author: R.K. Joshi, IIT Bombay */
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

class MyBox {
	public:
	int x[5];
	int y[5];
	int maze[14][20];
	MyBox(int a[5], int b[5]){
		for(int i=0;i<5;i++)
			{x[i]=a[i];y[i]=b[i];
			}
			for(int i=0;i<14;i=i+2){
				for(int j=1;j<20;j=j+2){
						if(i%2==1&&j%2==1)maze[i][j]=1;
						else maze[i][j]=0;
						}
						} 
			}
	MyBox (){
		x[0]=0;y[0]=-1;
		x[1]=0;y[1]=0;	
		x[2]=0;y[2]=1;	
		x[3]=-1;y[3]=0;	
		x[4]=1;y[4]=0;	
		for(int i=0;i<14;i++)
		{
			for(int j=1;j<=20;j++)
			{
						if(i%2==1&&j>=1&&j<=18)maze[i][j]=1;
						else maze[i][j]=0;
			}
		} 
		}
	bool u(){ // to check that the move is possible or not.
		if(x[0]>=0&&y[0]>=0&&x[0]<=13&&y[0]<=19){
			 if (maze[x[1]][y[1]-1]){ return false;}
			  else return true ;}  return false;}	
			  
	bool r(){ 
		if(x[4]>=0&&y[4]>=0&&x[4]<=13&&y[4]<=19){
			 if (maze[x[1]+1][y[1]]){ return false;}
			  else return true ;}	 return false;}		  
	bool l(){ 
		if(x[3]>=0&&y[3]>=0&&x[3]<=13&&y[3]<=19){
			 if (maze[x[1]-1][y[1]]){ return false;}
			  else return true ;} return false;}		  
	bool d(){ 
		if(x[2]>=0&&y[2]>=0&&x[2]<=13&&y[2]<=19){
			 if (maze[x[1]][y[1]+1]){ return false;}
			  else return true ;}	 return false;}	
			  
	bool u1(){ //for checking that sides of players are in contact with walls or not
		if(x[0]>=0&&y[0]>=0){
			 if (maze[x[0]][y[0]]){ return false;}
			  else return true ;}  return false;}	
			  
	bool r1(){ 
		if(x[4]>=0&&y[4]>=0){
			 if (maze[x[4]][y[4]]){ return false;}
			  else return true ;}	 return false;}		  
	bool l1(){ 
		if(x[3]>=0&&y[3]>=0){
			 if (maze[x[3]][y[3]]){ return false;}
			  else return true ;} return false;}		  
	bool d1(){ 
		if(x[2]>=0&&y[2]>=0){
			 if (maze[x[1]][y[2]]){ return false;}
			  else return true ;}	 return false;}			  
	
		
};

MyBox player;
class Board : public Fl_Widget {
int lb, rb, ub, db;
public:
	Board();
	void draw();
	int handle (int e);
	
};

int Board::handle(int e) {
		
//	cout << e << "  " << Fl::event_key() << endl;  // try uncommenting it..
	if (e==8)  // means it's a keyboard event
	switch (Fl::event_key()) {  // different keys are sensed here
		case 65361 : if(player.x[1]==13&&player.y[1]==19) exit(0); if(player.l()) {for (int i=0;i<5;i++){player.x[i]--;}} break; 
		case 65362 : if(player.x[1]==13&&player.y[1]==19) exit(0); if(player.u()) {for (int i=0;i<5;i++){player.y[i]--;}} break;
		case 65363 : if(player.x[1]==13&&player.y[1]==19) exit(0);if(player.r()) {for (int i=0;i<5;i++){player.x[i]++;}} break;
		case 65364 : if(player.x[1]==13&&player.y[1]==19) exit(0);if(player.d()) {for (int i=0;i<5;i++){player.y[i]++;}} break;
		default: break;
	}
	redraw();
}

Board::Board() : Fl_Widget (0,0,xmaxtiles*tilesize,
			ymaxtiles*tilesize,"MAZE GAME, DEMO CSE IITB CS152 2014") {
	// passing window position, size. and label into superclass's constructor
	
	
}

void Board::draw () { // this gets called automatically when redraw() is called 
		int i=0;
		for(int m=0;m<20;m++)
		{
			for( i=0;i<14;i++){
					if(player.maze[i][m]==0)fl_draw_box(FL_BORDER_BOX,i*tilesize,m*tilesize,tilesize,tilesize,9);
					else  fl_draw_box(FL_BORDER_BOX,i*tilesize,m*tilesize,tilesize,tilesize,8);
				}
			
		}
		fl_draw_box(FL_BORDER_BOX,(player.x[0])*tilesize,(player.y[0])*tilesize,tilesize,tilesize,3);if(!player.u1()) fl_draw_box(FL_BORDER_BOX,(player.x[0])*tilesize,(player.y[0])*tilesize,tilesize,tilesize,6);
		fl_draw_box(FL_BORDER_BOX,(player.x[1])*tilesize,(player.y[1])*tilesize,tilesize,tilesize,4);
 		fl_draw_box(FL_BORDER_BOX,(player.x[2])*tilesize,(player.y[2])*tilesize,tilesize,tilesize,3);if(!player.d1()) fl_draw_box(FL_BORDER_BOX,(player.x[2])*tilesize,(player.y[2])*tilesize,tilesize,tilesize,6);
 		fl_draw_box(FL_BORDER_BOX,(player.x[3])*tilesize,(player.y[3])*tilesize,tilesize,tilesize,3);if(!player.l1()) fl_draw_box(FL_BORDER_BOX,(player.x[3])*tilesize,(player.y[3])*tilesize,tilesize,tilesize,6);
 		fl_draw_box(FL_BORDER_BOX,(player.x[4])*tilesize,(player.y[4])*tilesize,tilesize,tilesize,3);if(!player.r1()) fl_draw_box(FL_BORDER_BOX,(player.x[4])*tilesize,(player.y[4])*tilesize,tilesize,tilesize,6);
 		
 		// first argument: type of box, you can have FL_BORDER_BOX also
 		// second, third argument: x,y position of the left corner
		// fourth, fifth arg: x,y dimensions
		// last arg: the color of the box

		//fl_draw_box(FL_FLAT_BOX,6*tilesize,14*tilesize,
	//			tilesize,tilesize,db);
	//	fl_draw_box(FL_FLAT_BOX,2*tilesize,8*tilesize,
	//			tilesize,tilesize,lb);
	//	fl_draw_box(FL_FLAT_BOX,10*tilesize,8*tilesize,
	//			tilesize,tilesize,rb);
}


int main(int argc, char *argv[]) {
    	Fl_Window *window = new Fl_Window (800,700,"DEMO"); // outer window
	window->color(56);   
	Board *b = new Board();
        Fl_Box *scorebox = new Fl_Box(tilesize*xmaxtiles+10,50,180,200,"MAZE");
	scorebox->box(FL_UP_BOX);
        scorebox->labelfont(FL_BOLD+FL_ITALIC);
        scorebox->labelsize(36);
        scorebox->labeltype(FL_SHADOW_LABEL);

        scorebox->box(FL_UP_BOX);
        scorebox->labelfont(FL_BOLD+FL_ITALIC);
        scorebox->labelsize(36);
        scorebox->labeltype(FL_SHADOW_LABEL);
	window->end();  
   	window->show();
    	return(Fl::run());  // the process waits from here on for events
}


