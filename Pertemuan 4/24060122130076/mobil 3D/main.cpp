 // Azzam Saefudin Rosyidi/ 24060122130076
  
#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
float angle=0.0, deltaAngle = 0.0, ratio; 
float x=0.0f,y=1.75f,z=15.0f; // posisi awal kamera 
float lx=0.0f,ly=0.0f,lz=-1.0f; 
int deltaMove = 0,h,w; 
int bitmapHeight=12; 
void Reshape(int w1, int h1) 
{ 
	 // Fungsi reshape 
	 if(h1 == 0) h1 = 1; 
	 w = w1; 
	 h = h1; 
	 ratio = 1.0f * w / h; 
	 glMatrixMode(GL_PROJECTION); 
	 glLoadIdentity(); 
	 glViewport(0, 0, w, h); 
	 gluPerspective(45,ratio,0.1,1000); 
	 glMatrixMode(GL_MODELVIEW); 
	 glLoadIdentity(); 
	 gluLookAt(
	 x, y, z, 
	 x + lx,y + ly,z + lz, 
	 0.0f,1.0f,0.0f); 
} 
void orientMe(float ang) 
{ 
	 // Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
	 lx = sin(ang); 
	 lz = -cos(ang); 
	 glLoadIdentity(); 
	 gluLookAt(x, y, z, 
	 x + lx,y + ly,z + lz, 
	 0.0f,1.0f,0.0f); 
} 
void moveMeFlat(int i) 
{ 
	 // Fungsi ini untuk maju mundur kamera 
	 x = x + i*(lx)*0.1; 
	 z = z + i*(lz)*0.1; 
	 glLoadIdentity(); 
	 gluLookAt(x, y, z, 
	 x + lx,y + ly,z + lz, 
	 0.0f,1.0f,0.0f); 
} 
void Grid() { 
	 // Fungsi untuk membuat grid di "lantai" 
	 double i; 
	 const float Z_MIN = -50, Z_MAX = 50; 
	 const float X_MIN = -50, X_MAX = 50; 
	 const float gap = 1.5; 
	 glColor3f(0.5, 0.5, 0.5); 
	 glBegin(GL_LINES); 
	 for(i=Z_MIN;i<Z_MAX;i+=gap) 
	 { 
		 glVertex3f(i, 0, Z_MIN); 
		 glVertex3f(i, 0, Z_MAX); 
	 } 
	 for(i=X_MIN;i<X_MAX;i+=gap) 
	 { 
		 glVertex3f(X_MIN, 0, i); 
		 glVertex3f(X_MAX, 0, i); 
	 } 
	 glEnd(); 
} 
void Mobil() 
{ 
// depan bawah

	glPushMatrix();
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(-7, -3, 0.0);
	glColor3f(0.5f, 0.0f, 0.0f); 
	glVertex3f(6, -3, 0.00);
	glColor3f(0.8f, 0.0f, 0.0f); 
	glVertex3f(5, -1, 0.00);
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex3f(-6, -1, 0.00);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(-7, -3, 0.00);
	glEnd();
	glPopMatrix();

// depan atas

	glPushMatrix();
	glTranslatef(0.00,3.00,0.00);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(3, -1, 0.00);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(2, 1, 0.00);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(-1, 1, 0.00);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3, -1, 0.00);
	glEnd();
	glPopMatrix();
	
//	belakang bawah

	glPushMatrix();
	glTranslatef(0, 3, -3.5);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(-7, -3, 0.0);
	glColor3f(0.5f, 0.0f, 0.0f); 
	glVertex3f(6, -3, 0.00);
	glColor3f(0.8f, 0.0f, 0.0f); 
	glVertex3f(5, -1, 0.00);
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex3f(-6, -1, 0.00);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(-7, -3, 0.00);
	glEnd();
	glPopMatrix();
	
//	belakang atas
	glPushMatrix();
	glTranslatef(0.00,3.00,-3.50);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(3, -1, 0.00);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(2, 1, 0.00);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(-1, 1, 0.00);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3, -1, 0.00);
	glEnd();
	glPopMatrix();
	
// samping kanan

	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.0f); 
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(6, -3, 0.0); 
	glVertex3f(5, -1, 0.00);
	glVertex3f(5, -1, -3.5);
	glVertex3f(6, -3, -3.5);
	glVertex3f(6, -3, 0.00);
	glEnd();
	glPopMatrix();
	
// samping kiri

	glPushMatrix(); 
	glTranslatef(0,3,0);
	glColor3f(0.5f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-7, -3, 0.0); 
	glVertex3f(-6, -1, 0.00);
	glVertex3f(-6, -1, -3.5);
	glVertex3f(-7, -3, -3.5);
	glVertex3f(-7, -3, 0.00);
	glEnd();
	glPopMatrix();
	
//	atas belakang

	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.0f); 
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(3, -1, 0.0); 
	glVertex3f(5, -1, 0.00);
	glVertex3f(5, -1, -3.5);
	glVertex3f(3, -1, -3.5);
	glVertex3f(3, -1, 0.00);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.0f); 
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2, 1, 0.0); 
	glVertex3f(3, -1, 0.00);
	glVertex3f(3, -1, -3.5);
	glVertex3f(2, 1, -3.5);
	glVertex3f(2, 1, 0.00);
	glEnd();
	glPopMatrix();	
	
//	atas

	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.0f); 
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2, 1, 0.0); 
	glVertex3f(-1, 1, 0.00);
	glVertex3f(-1, 1, -3.5);
	glVertex3f(2, 1, -3.5);
	glVertex3f(2, 1, 0.00);
	glEnd();
	glPopMatrix();
	
//	atas depan
	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.0f); 
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-1, 1, 0.0); 
	glVertex3f(-3, -1, 0.00);
	glVertex3f(-3, -1, -3.5);
	glVertex3f(-1, 1, -3.5);
	glVertex3f(-1 , 1, 0.00);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.0f); 
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-3, -1, 0.0); 
	glVertex3f(-6, -1, 0.00);
	glVertex3f(-6, -1, -3.5);
	glVertex3f(-3, -1, -3.5);
	glVertex3f(-3, -1, 0.00);
	glEnd();
	glPopMatrix();

//	bemper
	glPushMatrix();
	glColor3f(0.8f, 0.4f, 0.0f);
	glTranslatef(0,3,0.01);
	glBegin(GL_QUADS);
	glVertex3f(-7, -3, 0.0); 
	glVertex3f(6, -3, 0.00);
	glVertex3f(5.65, -2.3, 0);
	glVertex3f(-6.65, -2.3, 0);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.8f, 0.4f, 0.0f);
	glTranslatef(0,3,-0.01);
	glBegin(GL_QUADS);
	glVertex3f(-7, -3, -3.5); 
	glVertex3f(6, -3, -3.5);
	glVertex3f(5.65, -2.3, -3.5);
	glVertex3f(-6.65, -2.3, -3.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8f, 0.4f, 0.0f);
	glTranslatef(-0.01,3,0);
	glBegin(GL_QUADS);
	glVertex3f(-7, -3, 0.0); 
	glVertex3f(-6.65, -2.3, 0.0);
	glVertex3f(-6.65, -2.3, -3.5);
	glVertex3f(-7, -3, -3.5);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.8f, 0.4f, 0.0f);
	glTranslatef(0.01,3,0);
	glBegin(GL_QUADS);
	glVertex3f(6, -3, 0.0); 
	glVertex3f(5.65, -2.3, 0.0);
	glVertex3f(5.65, -2.3, -3.5);
	glVertex3f(6, -3, -3.5);
	glEnd();
	glPopMatrix();
	
//	angka
	glPushMatrix();
		glTranslatef(0.0,3,0.02);
		glColor3f(1.0f, 0.7f, 0.0f);
		glBegin(GL_QUADS);
    	glVertex2f(-1.4, -1.2);
    	glVertex2f(-0.5, -1.2);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-1.4, -2);
    	glEnd();
    	
		glBegin(GL_QUADS);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-0.8, -2);
    	glVertex2f(-0.8, -2.4);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
    	
		glBegin(GL_QUADS);
		glVertex2f(-1.4, -2.4);
    	glVertex2f(-1.4, -2.7);
    	glVertex2f(-0.5, -2.7);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1.2,3,0.02);
		glColor3f(1.0f, 0.7f, 0.0f);
		glBegin(GL_QUADS);
    	glVertex2f(-1.4, -1.2);
    	glVertex2f(-0.5, -1.2);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-1.4, -2);
    	glEnd();
    	
		glBegin(GL_QUADS);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-0.8, -2);
    	glVertex2f(-0.8, -2.4);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
    	
		glBegin(GL_QUADS);
		glVertex2f(-1.4, -2.4);
    	glVertex2f(-1.4, -2.7);
    	glVertex2f(-0.5, -2.7);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,3,-3.52);
		glColor3f(1.0f, 0.7f, 0.0f);
		glBegin(GL_QUADS);
    	glVertex2f(-1.4, -1.2);
    	glVertex2f(-0.5, -1.2);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-1.4, -2);
    	glEnd();
    	
		glBegin(GL_QUADS);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-0.8, -2);
    	glVertex2f(-0.8, -2.4);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
    	
		glBegin(GL_QUADS);
		glVertex2f(-1.4, -2.4);
    	glVertex2f(-1.4, -2.7);
    	glVertex2f(-0.5, -2.7);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1.2,3,-3.52);
		glColor3f(1.0f, 0.7f, 0.0f);
		glBegin(GL_QUADS);
    	glVertex2f(-1.4, -1.2);
    	glVertex2f(-0.5, -1.2);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-1.4, -2);
    	glEnd();
    	
		glBegin(GL_QUADS);
    	glVertex2f(-0.5, -2);
    	glVertex2f(-0.8, -2);
    	glVertex2f(-0.8, -2.4);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
    	
		glBegin(GL_QUADS);
		glVertex2f(-1.4, -2.4);
    	glVertex2f(-1.4, -2.7);
    	glVertex2f(-0.5, -2.7);
    	glVertex2f(-0.5, -2.4);
    	glEnd();
	glPopMatrix();
	
//	ban belakang
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); 
    glTranslatef(2.7, 0.25, -0.2); 
    glutSolidSphere(0.8, 100, 100); 
    glPopMatrix();
		
	glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); 
    glTranslatef(2.7, 0.25, -3.2); 
    glutSolidSphere(0.8, 100, 100); 
    glPopMatrix();
// ban depan
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); 
    glTranslatef(-3.2, 0.25, -0.2); 
    glutSolidSphere(0.8, 100, 100); 
    glPopMatrix();
    	
	glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); 
    glTranslatef(-3.2, 0.25, -3.2); 
    glutSolidSphere(0.8, 100, 100); 
    glPopMatrix();
	
//	kaca
	glPushMatrix();
		glTranslatef(0.00,3,0.01);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(-2.7,-1,0.00);
		glVertex3f(0.2,-1,0.00);
		glVertex3f(0.2,0.75,0.00);
		glVertex3f(-1,0.75,0.00);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.00,3.00,0.01);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(0.35,-1,0.00);
		glVertex3f(2.8,-1,0.00);
		glVertex3f(1.95,0.75,0.00);
		glVertex3f(0.35,0.75,0.00);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.00,3,-3.56);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(-2.7,-1,0.00);
		glVertex3f(0.2,-1,0.00);
		glVertex3f(0.2,0.75,0.00);
		glVertex3f(-1,0.75,0.00);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.00,3.00,-3.56);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(0.35,-1,0.00);
		glVertex3f(2.8,-1,0.00);
		glVertex3f(1.95,0.75,0.00);
		glVertex3f(0.35,0.75,0.00);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1.0f,1.0f,1.0f);
		glTranslatef(-0.1 ,3 , 0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-3, -1, -0.2);
		glVertex3f(-1, 0.892, -0.2);
		glVertex3f(-1, 0.892, -3.27);
		glVertex3f(-3, -1, -3.27);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1.0f,1.0f,1.0f);
		glTranslatef(0.1 ,3 , 0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(3, -1, -0.2);
		glVertex3f(2, 0.8, -0.2);
		glVertex3f(2, 0.8, -3.27);
		glVertex3f(3, -1, -3.27);
		glEnd();
	glPopMatrix();		
	
//	rear spoiler
	glPushMatrix();
		glTranslatef(0.0,3.0,0.0);
		glColor3f(0.75f, 0.75f, 0.75f);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(4, -1, 0.0);
		glVertex3f(4.5, 0.0, 0.0);
		glVertex3f(5, 0.0, 0.0);
		glVertex3f(4.5, -1, 0.0);
		glEnd();
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,3.0,-3.5);
		glColor3f(0.75f, 0.75f, 0.75f);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(4, -1, 0.0);
		glVertex3f(4.5, 0.0, 0.0);
		glVertex3f(5, 0.0, 0.0);
		glVertex3f(4.5, -1, 0.0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.75f,0.75f,0.75f);
		glTranslatef(0.0,3.0,0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(4.5, 0.0, 0.0);
		glVertex3f(5, 0.0, 0.0);
		glVertex3f(5, 0, -3.5);
		glVertex3f(4.5, 0, -3.5);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.75f,0.75f,0.75f);
		glTranslatef(0.0,3.0,0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(5, 0.0, 0.0);
		glVertex3f(4.5, -1, 0.0);
		glVertex3f(4.5, -1, -3.5);
		glVertex3f(5, 0, -3.5);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.75f,0.75f,0.75f);
		glTranslatef(0.0,3.0,0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(4.5, 0.0, 0.0);
		glVertex3f(4, -1, 0.0);
		glVertex3f(4, -1, -3.5);
		glVertex3f(4.5, 0, -3.5);
		glEnd();
	glPopMatrix();
	
//	lampu
	glPushMatrix();
		glTranslatef(-6.5,0.8,-0.8);
		glColor3f(1.0f, 0.8f, 0.0f); 
    	glutSolidSphere(0.45, 20, 20);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-6.5,0.8,-2.6);
		glColor3f(1.0f, 0.8f, 0.0f); 
    	glutSolidSphere(0.45, 20, 20);
	glPopMatrix();
	
    glPushMatrix();
    	glColor3f(1.0f, 1.0f, 0.0f); 
    	glTranslatef(5.3,0.8,-2.6);
    	glutSolidCube(0.7); 
    glPopMatrix();
	
	glPushMatrix();
    	glColor3f(1.0f, 1.0f, 0.0f); 
    	glTranslatef(5.3,0.8,-0.8);
    	glutSolidCube(0.7); 
    glPopMatrix();							
} 
void display() { 
	 // Kalau move dan angle tidak nol, gerakkan kamera... 
	 if (deltaMove) 
	 	moveMeFlat(deltaMove); 
	 if (deltaAngle) { 
		 angle += deltaAngle; 
		 orientMe(angle); 
	 } 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	 // Gambar grid 
	 Grid(); 
	 // Gambar objek di sini... 
	 Mobil(); 
	 glutSwapBuffers(); 
	 glFlush(); 
} 
void pressKey(int key, int x, int y) { 
	 // Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas 
	 // Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak 
	 switch (key) { 
	 case GLUT_KEY_LEFT : 
		 deltaAngle = -0.01;
		 break; 
	 case GLUT_KEY_RIGHT : 
		 deltaAngle = 0.01;
		 break; 
	 case GLUT_KEY_UP : 
		 deltaMove = 1;
		 break; 
	 case GLUT_KEY_DOWN : 
		 deltaMove = -1;
		 break; 
 	} 
} 
void releaseKey(int key, int x, int y) { 
	 // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
	 // Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti 
	 switch (key) { 
	 case GLUT_KEY_LEFT : 
	 if (deltaAngle < 0.0f) 
		 deltaAngle = 0.0f; 
		 break; 
	 case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f) 
		 deltaAngle = 0.0f; 
		 break; 
	 case GLUT_KEY_UP : if (deltaMove > 0) 
		 deltaMove = 0; 
		 break; 
	 case GLUT_KEY_DOWN : if (deltaMove < 0) 
		 deltaMove = 0; 
		 break; 
	 } 
} 
	// Variable untuk pencahayaan 
	const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f }; 
	const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
	const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f }; 
	const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
	const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
	const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
	const GLfloat high_shininess[] = { 100.0f }; 
void lighting(){ 
	 // Fungsi mengaktifkan pencahayaan 
	 glEnable(GL_DEPTH_TEST); 
	 glDepthFunc(GL_LESS); 
	 glEnable(GL_LIGHT0); 
	 glEnable(GL_NORMALIZE); 
	 glEnable(GL_COLOR_MATERIAL); 
	 glEnable(GL_LIGHTING); 
	 glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
	 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
	 glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
	 glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
	 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
	 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
	 glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
} 
void init(void) 
{ 
	 glEnable (GL_DEPTH_TEST); 
	 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
} 
int main(int argc, char **argv) 
{ 
	 glutInit(&argc, argv); 
	 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
	 glutInitWindowPosition(100,100); 
	 glutInitWindowSize(640,480); 
	 glutCreateWindow("3D Lighting"); 
	 glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol keyboard dipencet terus) 
	 glutSpecialFunc(pressKey);
	 glutSpecialUpFunc(releaseKey); 
	 glutDisplayFunc(display); 
	 glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus 
	 glutReshapeFunc(Reshape); 
	 lighting(); 
	 init(); 
	 glutMainLoop(); 
	 return(0); 
}

