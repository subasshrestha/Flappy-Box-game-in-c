// inclusioin of header file
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
//declaration of function
void layout();

void main(){
	int gd=0,gm;//declaring graphics driver variable and graphic mode variable
	int score=0,boxCoordinateX=319,boxCoordinateY=239,obstacleCoordinateX=639,obstacleCoordinateY=60,randomNumber,temporaryData; //no of variables used in this code
	char ch,sdisplay[5];
	initgraph(&gd,&gm,"C://TURBOC3//BGI");   //initialize graphics and locating the Bordland graphics interface
        setbkcolor(BLUE);	//set background color
        layout();
	randomNumber=random(250);	//generate random number between 0 and 250

        //Display initial score
	setcolor(RED);
        settextstyle(8,0,4);
        sprintf(sdisplay,"%d",score);
        outtextxy(getmaxx()-100,3,sdisplay);

        //loop for moving obstacle and box
	while(1){
		//kbhit() check if any key is pressed
		while(!kbhit()){
                        //Increase score when box is at half of obstacle
                	if(boxCoordinateX+20==obstacleCoordinateX+10){
                                setcolor(YELLOW);
                                settextstyle(8,0,4);
                                outtextxy(getmaxx()-100,3,sdisplay);
        		        score++;
	        	        sprintf(sdisplay,"%d",score);
                                setcolor(RED);
				outtextxy(getmaxx()-100,3,sdisplay);
	                }
				
			//move obstacle
                        setcolor(WHITE);
		       	line(obstacleCoordinateX,obstacleCoordinateY,obstacleCoordinateX,obstacleCoordinateY+randomNumber);
                       	line(obstacleCoordinateX,obstacleCoordinateY+randomNumber+140,obstacleCoordinateX,getmaxy()-30);
		       	setcolor(BLUE);
		       	line(obstacleCoordinateX+30,obstacleCoordinateY,obstacleCoordinateX+30,obstacleCoordinateY+randomNumber);
		       	line(obstacleCoordinateX+30,obstacleCoordinateY+randomNumber+140,obstacleCoordinateX+30,getmaxy()-30);
                        obstacleCoordinateX--;
				
			//change obstacle position
	               	if(obstacleCoordinateX<=-32){
	              		obstacleCoordinateX=getmaxx();
	                     	randomNumber=random(250);
			}

			//game over condition
		        if( (boxCoordinateY+20==getmaxy()-30) || ((boxCoordinateX+20>=obstacleCoordinateX&&boxCoordinateX+20<=obstacleCoordinateX+30)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY+20<=obstacleCoordinateY+randomNumber+140)) || ((obstacleCoordinateX+30>=boxCoordinateX&&obstacleCoordinateX+30<=boxCoordinateX+20)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY+20<=obstacleCoordinateY+randomNumber+140)))
	     	        {
        			break;
        		}
				
			//move box downward
        		setcolor(GREEN);
        		line(boxCoordinateX,boxCoordinateY+20,boxCoordinateX+20,boxCoordinateY+20);
        		setcolor(BLUE);
        		line(boxCoordinateX,boxCoordinateY-1,boxCoordinateX+20,boxCoordinateY-1);
                        boxCoordinateY++;
        		delay(5);
 		}

             //game over condition   
		if( (boxCoordinateY+20==getmaxy()-30) || ((boxCoordinateX+20>=obstacleCoordinateX&&boxCoordinateX+20<=obstacleCoordinateX+30)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY+20<=obstacleCoordinateY+randomNumber+140)) || ((obstacleCoordinateX+30>=boxCoordinateX&&obstacleCoordinateX+30<=boxCoordinateX+20)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY+20<=obstacleCoordinateY+randomNumber+140))){
 			break;
	        }
			
	        ch=getch(); //input for one character 
	        //condition for esc key
		if(ch==27){
	       	        exit(1);
	        }
			//condition for space bar
	        if(ch==32){
                        temporaryData=boxCoordinateY;
					//move box 80 distane from current position using loop
			for(boxCoordinateY;boxCoordinateY>=temporaryData-80;boxCoordinateY--){
			        //condition for game over
				if((boxCoordinateY==59) || ((boxCoordinateX+20>=obstacleCoordinateX&&boxCoordinateX+20<=obstacleCoordinateX+30)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY+20<=obstacleCoordinateY+randomNumber+140)) || ((obstacleCoordinateX+30>=boxCoordinateX&&obstacleCoordinateX+30<=boxCoordinateX+20)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY+20<=obstacleCoordinateY+randomNumber+140))){
			       	        break;
			        }
		        	setcolor(GREEN);
			        line(boxCoordinateX,boxCoordinateY,boxCoordinateX+20,boxCoordinateY);
			        setcolor(BLUE);
			        line(boxCoordinateX,boxCoordinateY+21,boxCoordinateX+20,boxCoordinateY+21);
		        	delay(1);
			}
	        	//condition for game over
			if((boxCoordinateY==59) || ((boxCoordinateX+20>=obstacleCoordinateX&&boxCoordinateX+20<=obstacleCoordinateX+30)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY<=obstacleCoordinateY+randomNumber+140)) || ((obstacleCoordinateX+30>=boxCoordinateX&&obstacleCoordinateX+30<=boxCoordinateX+20)&&!(boxCoordinateY>=obstacleCoordinateY+randomNumber&&boxCoordinateY+20<=obstacleCoordinateY+randomNumber+140))){
		        	break;
		        }

       		 }
	}

//display game over 
setcolor(YELLOW);
settextstyle(1,0,5);
outtextxy(getmaxx()/2-100,getmaxy()/2-50,"GAME OVER");
//loop for taking input  
while(1){
	ch=getch();
	if(ch==27){
		exit(1);
	}
	if(ch=='p'){
		main();
	}
}
}

void layout(){
	setcolor(YELLOW);
	rectangle(0,0,getmaxx(),60);
	rectangle(0,getmaxy()-30,getmaxx(),getmaxy());
	setfillstyle(SOLID_FILL,YELLOW);	//set yellow color to fill  
	floodfill(1,1,YELLOW);	//fill above color inside yellow boundry
	floodfill(getmaxx()-1,getmaxy()-1,YELLOW);
        setcolor(RED);
        settextstyle(8,0,4);
        outtextxy(getmaxx()-200,3,"Score: ");
        setcolor(YELLOW);
	settextstyle(1,0,2);
	outtextxy(getmaxx()/2-150,getmaxy()/2-50,"Press any key to start game");
        getch();
        setcolor(BLUE);
        outtextxy(getmaxx()/2-150,getmaxy()/2-50,"Press any key to start game");
}