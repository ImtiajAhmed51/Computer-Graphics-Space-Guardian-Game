#include <iostream>
#include <GLUT/glut.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <GLUT/glut.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>
#define XMAX 1200
#define YMAX 700
#define JET_SPEED 20
using namespace std;
GLint m_viewport[4];
bool mButtonPressed = false;
float mouseX, mouseY;
enum view {INTRO, MENU, INSTRUCTIONS, GAME, GAMEOVER};
view viewPage = INTRO; // initial value
bool keyStates[256] = {false};
bool direction[4] = {false};
bool laser1Dir[2] = {false};
bool laser2Dir[2] = {false};
int x=-180,y=-299;
int  rotateJet=0;

int health1 = 100;
int health2 = 100;
bool gameOver = false;
float xOne = 500, yOne = 0;
float xTwo = 500, yTwo = 0;
bool laser1 = false, laser2 = false;
float x2,y2;

void jet();
void displayRasterText(float x ,float y ,float z ,char *stringToDisplay) {
    glRasterPos3f(x, y, z);
    for(char* c = stringToDisplay; *c != '\0'; c++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *c);
    }
}
void init()
{
    glClearColor(0.0,0.0,0.0,0);
    //glColor3f(1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1200,1200,-700,700);                   //<-----CHANGE THIS TO GET EXTRA
    glMatrixMode(GL_MODELVIEW);
}
void dot(){
    glPushMatrix();
    glTranslatef(-12000,6200,0);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    //START GAME PLOYGON
        glVertex2f(40,40);
        glVertex2f(40,20);
        glVertex2f(52,32);
        glVertex2f(52,40);
    glEnd();

    
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    //START GAME PLOYGON
        glVertex2f(52,32);
        glVertex2f(40,20);
        glVertex2f(90,20);
        glVertex2f(80,32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    //START GAME PLOYGON
        glVertex2f(90,20);
        glVertex2f(80,32);
        glVertex2f(80,40);
        glVertex2f(90,40);
    glEnd();
    
    
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    //START GAME PLOYGON
        glVertex2f(40,20);
        glVertex2f(40,11);
        glVertex2f(90,11);
        glVertex2f(90,20);
    glEnd();

    glPopMatrix();
    
}
void introScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.3,0.7,0.8 );
    displayRasterText(-150, 300, 0.0,"Space Guardian");
    glColor3f(0.6,0.9,1);
//    displayRasterText(-125, 225, 0.0,"");
//           glColor3f(1.0, 0.7, 0.8);
//    displayRasterText(-100, 150, 0.0,"");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-130, 80, 0.0,"");
//    glColor3f(1.0, 0.0, 0.0);
//    displayRasterText(-800, -100, 0.0,"Md. Imtiaj Ahmed");
//    glColor3f(1.0, 1.0, 1.0);
//    displayRasterText(-800, -200, 0.0,"21-44828-1");
//
 
  
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.3,0.5 ); //Continue POLYGON
        glVertex2f(-170,-480);
        glVertex2f(-200,-580);
        glVertex2f(200,-580);
        glVertex2f(230,-480);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    
    
    if(mouseX>=-100 && mouseX<=100 && mouseY>=-285 && mouseY<=-240){
        glColor3f(1 ,1 ,0);
        if(mButtonPressed){
            mButtonPressed = false;
            cout<<"button pressed CONTINUE\n";
            viewPage = MENU;
 
        }
    }
    else
        glColor3f(0 , 0, 0);
    displayRasterText(-120, -550, 0.0,"CONTINUE...");
    
    
    
    
    
    glPushMatrix();
    glTranslated(0,500,0);
   //glScalef(0.5,0.5,1);
    glColor3f(1, 1, 0);
    rotateJet+=2;

    glRotatef(rotateJet, 0.0f, 0.0f, 1.0f);
    jet();
    glPopMatrix();
    

    glFlush();
    glutSwapBuffers();
}

void startScreenDisplay()
{

   
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    //START GAME PLOYGON
        glVertex2f(200 ,300);
        glVertex2f(100 ,400);
        glVertex2f(1100 ,400);
        glVertex2f(1200 ,300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2,0.3,1); //INSTRUCTIONS POLYGON
        glVertex2f(200, 50);
        glVertex2f(100 ,150);
        glVertex2f(1100 ,150);
        glVertex2f(1200 ,50);
    glEnd();

    glBegin(GL_POLYGON);
    
    glColor3f(0.2,0.3,0.5 ); //QUIT POLYGON
        glVertex2f(200 ,-200);
        glVertex2f(100 ,-100);
        glVertex2f(1100, -100);
        glVertex2f(1200, -200);
    glEnd();

    glPushMatrix();                  //Jet Mouse Position
    glColor3f(1, 1, 0);
    //glScalef(2,2,1);
    //glScalef(1,1,1);
    glTranslatef(x2,y2,0);
    glRotatef(180, 0.0f, 0.0f, 1.0f);
    jet();
    glPopMatrix();
    
    if(mouseX>=100 && mouseX<=600 && mouseY>=150 && mouseY<=200){
        glColor3f(1,0 ,0) ;
        if(mButtonPressed){
            health1 = health2 = 100;
            viewPage = GAME;
            cout<<"button pressed Start\n";
            mButtonPressed = false;
        }
    } else
        glColor3f(0 , 0, 0);

    displayRasterText(400 ,340 ,0.4 ,"Start Game");

    if(mouseX>=100 && mouseX<=600 && mouseY>=30 && mouseY<=80) {
        glColor3f(1 ,0 ,0);
        if(mButtonPressed){
            viewPage = INSTRUCTIONS;
            cout<<"button pressed Instructions\n";
            mButtonPressed = false;
        }
    } else
        glColor3f(0 , 0, 0);
    displayRasterText(400 ,80 ,0.4 ,"Instructions");

    if(mouseX>=100 && mouseX<=600 && mouseY>=-90 && mouseY<=-40){
        glColor3f(1 ,0 ,0);
        if(mButtonPressed){
            mButtonPressed = false;
            cout<<"button pressed Quit\n";
            exit(0);
        }
    }
    else
        glColor3f(0 , 0, 0);
    displayRasterText(350 ,-170 ,0.4 ,"    Quit");
    
    
    
    
    
    
    glutPostRedisplay();
}

void backButton() {
    if(mouseX <= -450 && mouseX >= -500 && mouseY >= -275 && mouseY <= -250){
            glColor3f(1, 1, 0);
            if(mButtonPressed) {
                viewPage = MENU;
                mButtonPressed = false;
                //instructionsGame = false;
                glutPostRedisplay();
            }
    }
    else
        glColor3f(1, 0, 0);
    displayRasterText(-1000 ,-550 ,0, "Back");
}

void instructionsScreenDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //SetDisplayMode(MENU_SCREEN);
    //colorBackground();
    glColor3f(1, 1, 0);
    displayRasterText(-900 ,550 ,0.4 ,"INSTRUCTIONS");
    glColor3f(1, 1, 0);
    displayRasterText(-1000 ,400 ,0.4 ,"PLAYER 1");
    displayRasterText(200 ,400 ,0.4 ,"PLAYER 2");
    glColor3f(1, 1, 1);
    displayRasterText(-1100 ,300 ,0.4 ,"Key 'w' to move up.");
    displayRasterText(-1100 ,200 ,0.4 ,"Key 's' to move down.");
    displayRasterText(-1100 ,100 ,0.4 ,"Key 'd' to move right.");
    displayRasterText(-1100 ,0 ,0.4 ,"Key 'a' to move left.");
    displayRasterText(100 ,300 ,0.4 ,"Key 'i' to move up.");
    displayRasterText(100 ,200 ,0.4 ,"Key 'k' to move down.");
    displayRasterText(100 ,100 ,0.4 ,"Key 'j' to move right.");
    displayRasterText(100 ,0 ,0.4 ,"Key 'l' to move left.");
    displayRasterText(-1100 ,-100 ,0.4 ,"Key 'c' to shoot, Use 'w' and 's' to change direction.");
    displayRasterText(100 ,-100 ,0.4 ,"Key 'm' to shoot, Use 'i' and 'k' to change direction.");
    //displayRasterText(-1100 ,-100 ,0.4 ,"The packet can be placed only when 's' is pressed before.");
    displayRasterText(-1100, -300,0.4,"The Objective is to kill your opponent.");
    displayRasterText(-1100 ,-370 ,0.4 ,"Each time a player gets shot, LIFE decreases by 5 points.");
    backButton();
    //if(previousScreen)
    //    nextScreen = false ,previousScreen = false; //as set by backButton()
}

//jet resize
void Draw(bool isPlayer2)
{
    if(isPlayer2){
        glColor3f(1, 1, 0);
    }
    else{
        glColor3f(1, 0, 0);
    }
       

    glPushMatrix();
    glScalef(0.8,0.8,1);
    
    jet();
    glPopMatrix();

}
//Jet Draw
void jet(){
    glBegin(GL_QUADS);
    glVertex2f(250+x,233+y);
    glVertex2f(198+x,233+y);
    glVertex2f(198+x,242+y);
    glVertex2f(250+x,242+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(242+x,242+y);
    glVertex2f(215+x,242+y);
    glVertex2f(215+x,250+y);
    glVertex2f(242+x,250+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(233+x,250+y);
    glVertex2f(206+x,250+y);
    glVertex2f(206+x,259+y);
    glVertex2f(233+x,259+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(224+x,259+y);
    glVertex2f(198+x,259+y);
    glVertex2f(198+x,268+y);
    glVertex2f(224+x,268+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(224+x,268+y);
    glVertex2f(189+x,268+y);
    glVertex2f(189+x,278+y);
    glVertex2f(224+x,278+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(215+x,278+y);
    glVertex2f(171+x,278+y);
    glVertex2f(171+x,286+y);
    glVertex2f(215+x,286+y);
    glEnd();
    
//    glBegin(GL_QUADS);
//    glVertex2f(233+x,286+y);
//    glVertex2f(135+x,286+y);
//    glVertex2f(135+x,313+y);
//    glVertex2f(233+x,313+y);
//    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(233+x,286+y);
    glVertex2f(140+x,286+y);
    glVertex2f(140+x,313+y);
    glVertex2f(233+x,313+y);
    glEnd();
//
    glBegin(GL_QUADS);
    glVertex2f(120+x,295+y);
    glVertex2f(120+x,304+y);
    glVertex2f(251+x,304+y);
    glVertex2f(251+x,295+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(215+x,313+y);
    glVertex2f(171+x,313+y);
    glVertex2f(171+x,322+y);
    glVertex2f(215+x,322+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(189+x,322+y);
    glVertex2f(189+x,330+y);
    glVertex2f(224+x,330+y);
    glVertex2f(224+x,322+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(224+x,330+y);
    glVertex2f(198+x,330+y);
    glVertex2f(198+x,340+y);
    glVertex2f(224+x,340+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(233+x,339+y);
    glVertex2f(206+x,339+y);
    glVertex2f(206+x,349+y);
    glVertex2f(233+x,349+y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(242+x,349+y);
    glVertex2f(215+x,349+y);
    glVertex2f(215+x,358+y);
    glVertex2f(242+x,358+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(250+x,358+y);
    glVertex2f(198+x,358+y);
    glVertex2f(198+x,366+y);
    glVertex2f(250+x,366+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(189+x,330+y);
    glVertex2f(171+x,330+y);
    glVertex2f(171+x,340+y);
    glVertex2f(189+x,340+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(189+x,260+y);
    glVertex2f(171+x,260+y);
    glVertex2f(171+x,269+y);
    glVertex2f(189+x,269+y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(198+x,330+y);
    glVertex2f(189+x,330+y);
    glVertex2f(189+x,340+y);
    glVertex2f(198+x,340+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(198+x,260+y);
    glVertex2f(189+x,260+y);
    glVertex2f(189+x,269+y);
    glVertex2f(198+x,269+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(189+x,322+y);
    glVertex2f(179+x,322+y);
    glVertex2f(179+x,330+y);
    glVertex2f(189+x,330+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(190+x,269+y);
    glVertex2f(180+x,269+y);
    glVertex2f(180+x,278+y);
    glVertex2f(190+x,278+y);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0,0.7,1);
    glVertex2f(241+x,313+y);
    glVertex2f(215+x,313+y);
    glVertex2f(215+x,322+y);
    glVertex2f(224+x,322+y);
    glVertex2f(224+x,330+y);
    glVertex2f(241+x,330+y);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0,0.7,1);
    glVertex2f(241+x,287+y);
    glVertex2f(215+x,287+y);
    glVertex2f(215+x,277+y);
    glVertex2f(224+x,277+y);
    glVertex2f(224+x,268+y);
    glVertex2f(241+x,268+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(206+x,304+y);
    glVertex2f(188+x,304+y);
    glVertex2f(188+x,313+y);
    glVertex2f(206+x,313+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(197+x,295+y);
    glVertex2f(180+x,295+y);
    glVertex2f(180+x,304+y);
    glVertex2f(197+x,304+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(206+x,286+y);
    glVertex2f(188+x,286+y);
    glVertex2f(188+x,295+y);
    glVertex2f(206+x,295+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(198+x,358+y);
    glVertex2f(180+x,358+y);
    glVertex2f(180+x,366+y);
    glVertex2f(198+x,366+y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(198+x,233+y);
    glVertex2f(180+x,233+y);
    glVertex2f(180+x,242+y);
    glVertex2f(198+x,242+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(171+x,330+y);
    glVertex2f(153+x,330+y);
    glVertex2f(153+x,340+y);
    glVertex2f(171+x,340+y);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0.7,1);
    glVertex2f(171+x,260+y);
    glVertex2f(153+x,260+y);
    glVertex2f(153+x,269+y);
    glVertex2f(171+x,269+y);
    glEnd();
}
// jet fire laser draw
void drawLaser(int x, int y, bool dir[]) {
    //glPushMatrix();
    int xend = -XMAX, yend = y;
    if(dir[0])
        yend = YMAX;
    else if(dir[1])
        yend = -YMAX;
    glLineWidth(3);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(xend, yend);
    glEnd();
    //glPopMatrix();
}
// jet create 2 position player 1 & player 2
void jetCreate(int x, int y, bool isPlayer2){
    glPushMatrix();
    glTranslated(x,y,0);
    glPushMatrix();
    glTranslated(4,19,0);
    glPopMatrix();
    Draw(isPlayer2);
    glEnd();
    glPopMatrix();
}
//health player 1
void DisplayHealthBar1() {
    char temp1[40];
    if(20>=health1){
        glColor3f(1 ,0 ,0);
    }else{
        glColor3f(1 ,1 ,1);
    }
    sprintf(temp1,"  HEALTH : %d",health1);
    displayRasterText(-1100 ,600 ,0.4 ,temp1);
    glColor3f(1 ,0 ,0);
}
//health player 2
void DisplayHealthBar2() {
    char temp2[40];
    if(20>=health2){
        glColor3f(1 ,0 ,0);
    }else{
        glColor3f(1 ,1 ,1);
    }
    sprintf(temp2,"  HEALTH : %d",health2);
    displayRasterText(700 ,600 ,0.4 ,temp2);
    glColor3f(1 ,0 ,0);
}
void checkLaserContact(int x, int y, bool dir[], int xp, int yp, bool player1) {
    int xend = -XMAX, yend = y;
    //xp += 8; yp += 8; // moving circle slightly up to fix laser issue
    if(dir[0])
        yend = YMAX;
    else if(dir[1])
        yend = -YMAX;

    // Here we find out if the laser(line) intersects with spaceship(circle)
    // by solving the equations for the same and finding the discriminant of the
    // quadratic equation obtained
    float m = (float)(yend - y) / (float)(xend - x);
    float k = y - m * x ;
    int r = 40; // approx radius of the spaceship

    //calculating value of b, a, and c needed to find discriminant
    float b = 2 * xp - 2 * m * (k - yp);
    float a = 1 + m * m;
    float c = xp * xp + (k - yp) * (k - yp) - r * r;

    float d = (b * b - 4 * a * c); // discriminant for the equation
    //cout<<("\nx: "<<x<<", y: "<<y<<", xp: "<<, yp: %d", d, x, y, xp, yp);
    if(d >= 0) {
        if(player1)
            health1 -= 5;
        else
            health2 -= 5;

        cout<<"1: "<<health1<<", 2: "<<health2<<"\n";
    }
}

void gameScreenDisplay()
{
    DisplayHealthBar1();
    DisplayHealthBar2();
    for(int i=0;i<1400;i+=110){
        
        for(int j=0;j<3000;j+=120){
            glPushMatrix();
            if(i%3==0){
                glTranslatef(j+50, -i+30+rand()%50+1, 0);
            }else{
                glTranslatef(j+rand()%10+1, -i+rand()%50+1, 0);
            }
            //glTranslatef(j, -i, 0);
            glScalef(0.1,0.1, 1);
            dot();
            glPopMatrix();
        }
    }
    glScalef(1.8, 1.8 ,0);

    if(health1 > 0){
        jetCreate(xOne, yOne, true);
        if(laser1) {
            drawLaser(xOne, yOne, laser1Dir);
            checkLaserContact(xOne, yOne, laser1Dir, -xTwo, yTwo, true);
        }
    }
    else {
        viewPage = GAMEOVER;
    }

    if(health2 > 0) {
        glPushMatrix();
        glScalef(-1, 1, 1);
        jetCreate(xTwo, yTwo, false);
        if(laser2) {
            drawLaser(xTwo, yTwo, laser2Dir);
            checkLaserContact(xTwo, yTwo, laser2Dir, -xOne, yOne, false);
        }
        glPopMatrix();
    }
    else {
        viewPage = GAMEOVER;
    }

    if(viewPage == GAMEOVER) {
        xOne = xTwo = 500;
        yOne = yTwo = 0;
    }
}

void displayGameOverMessage() {
    glColor3f(1, 1, 0);
    char* message;
    if(health1 > 0)
        message = "Game Over! Player 1 won the game";
    else
        message = "Game Over! Player 2 won the game";
    
    displayRasterText(-350 ,600 ,0.4 , message);
}

void keyOperations() {
    if(keyStates[13] == true && viewPage == INTRO) {
        viewPage = MENU;
        cout<<"view value changed to "<<viewPage<<" enter key pressed\n";
    }
    if(viewPage == GAME) {
        laser1Dir[0] = laser1Dir[1] = false;
        laser2Dir[0] = laser2Dir[1] = false;
        if(keyStates['c'] == true) {
            laser2 = true;
            if(keyStates['w'] == true)     laser2Dir[0] = true;
            if(keyStates['s'] == true)     laser2Dir[1] = true;
        }
        else {
            laser2 = false;
            if(keyStates['d'] == true) xTwo-=JET_SPEED;
            if(keyStates['a'] == true) xTwo+=JET_SPEED;
            if(keyStates['w'] == true) yTwo+=JET_SPEED;
            if(keyStates['s'] == true) yTwo-=JET_SPEED;
        }

        if(keyStates['m'] == true) {
            laser1 = true;
            if(keyStates['i'] == true) laser1Dir[0] = true;
            if(keyStates['k'] == true) laser1Dir[1] = true;
        }
        else {
            laser1 = false;
            if(keyStates['l'] == true) xOne+=JET_SPEED;
            if(keyStates['j'] == true) xOne-=JET_SPEED;
            if(keyStates['i'] == true) yOne+=JET_SPEED;
            if(keyStates['k'] == true) yOne-=JET_SPEED;
        }
    }
}

void display()
{
    //glClearColor(, 0 , 0, 1);
    keyOperations();
    glClear(GL_COLOR_BUFFER_BIT);

    switch (viewPage)
    {
        case INTRO:
            introScreen();
            break;
        case MENU:
            startScreenDisplay();
            break;
        case INSTRUCTIONS:
            instructionsScreenDisplay();
            break;
        case GAME:
            gameScreenDisplay();
            //reset scaling values
            glScalef(1/2 ,1/2 ,0);
            break;
        case GAMEOVER:
            displayGameOverMessage();
            startScreenDisplay();
            break;
    }

    glFlush();
    glLoadIdentity();
    glutSwapBuffers();
}
void passiveMotionFunc(int x,int y) {

    //when mouse not clicked
    mouseX = float(x)/(m_viewport[2]/1200.0)-600.0;  //converting screen resolution to ortho 2d spec
    mouseY = -(float(y)/(m_viewport[3]/700.0)-350.0);

    if(x-600<0){
        x2=(x-600)*2;
        
    }
    y2=(-y+300)*2.3;
    glutPostRedisplay();
}

void mouseClick(int buttonPressed ,int state ,int x, int y) {

    if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y)
{
    keyStates[key] = true;
    cout<<key<<"\n";
    glutPostRedisplay();
}

void refresh() {
    glutPostRedisplay();
}

void keyReleased(unsigned char key, int x, int y) {
    keyStates[key] = false;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Space Guardian");
    init();
    glutIdleFunc(refresh);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMotionFunc);
    glGetIntegerv(GL_VIEWPORT ,m_viewport);
    glutDisplayFunc(display);
    glutMainLoop();
}
