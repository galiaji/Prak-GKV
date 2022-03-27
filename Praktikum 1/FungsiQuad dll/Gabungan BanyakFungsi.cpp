// Nama : Galih Aji Syafaat
// NIM  : 24060121130072

/*
 * File : Gabungan BanyakFungsi.cpp -> Fungsi Quad dll.dev
 * Deskripsi : Membentuk program dengan gabungan fungsi GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, GL_QUADS_STRIP.
 */

 #include <GL/glut.h>
 #include <stdlib.h>
 
 void Garis(void)
 {
 	glClear(GL_COLOR_BUFFER_BIT);
 	glLineWidth(0.5f);




glBegin(GL_TRIANGLE_STRIP);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2f(0.997, 0.35);
glVertex2f(0.5, 0.35);
glVertex2f(0.5, -0.3499);
glVertex2f(0.997, -0.3499);
glEnd();

glBegin(GL_TRIANGLE_STRIP);
glColor3f(.0f, 1.0f, 1.0f);
glVertex2f(-0.997, 0.349);
glVertex2f(-0.5, 0.349);
glVertex2f(-0.5, -0.3499);
glVertex2f(-0.997, -0.3499);

glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(0.0,0.0);
glColor3f(.0f, 1.0f, 1.0f);
glVertex2f(-0.2, 0.7);
glVertex2f(0.2, 0.7);
glVertex2f(0.5, 0.35);
glVertex2f(0.5, -0.39);
glVertex2f(0.2, -0.6999);
glVertex2f(-0.2, -0.6999);
glVertex2f(-0.5, -0.39);
glVertex2f(-0.5, 0.35);
glVertex2f(-0.2, 0.6999);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, .0f, 1.0f);
glVertex2f(0.2, 0.999);
glColor3f(.0f, 1.0f, 1.0f);
glVertex2f(0.2, 0.7);
glVertex2f(0.5, 0.35);
glVertex2f(0.999, 0.35);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f);
glVertex2f(-0.2, 0.999);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2f(-0.2, 0.7);
glVertex2f(-0.5, 0.35);
glVertex2f(-0.999, 0.35);
glEnd();
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f);
glVertex2f(-0.2, -0.999);
glColor3f(.0f, 1.0f, 1.0f);
glVertex2f(-0.2, -0.7);
glVertex2f(-0.5, -0.35);
glVertex2f(-0.999, -0.35);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f);
glVertex2f(0.2, -0.999);
glColor3f(.0f, 1.0f, 1.0f);
glVertex2f(0.2, -0.7);
glVertex2f(0.5, -0.35);
glVertex2f(0.999, -0.35);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2f(-0.2, -0.7);
glColor3f(1.0f, 0.0f, 1.0f);
glVertex2f(-0.2, -0.999);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2f(0.2, -0.7);
glColor3f(1.0f, 0.0f, 1.0f);
glVertex2f(0.2, -0.999);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2f(-0.2, 0.7);
glColor3f(1.0f, .0f, 1.0f);
glVertex2f(-0.2, 0.999);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2f(0.2, 0.7);
glColor3f(1.0f, 0.0f, 1.0f);
glVertex2f(0.2, 0.999);
glEnd();


glBegin(GL_LINE_STRIP);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.5, 0.35);
glVertex2f(-0.999, 0.35);
glVertex2f(-0.999, -0.35);
glVertex2f(-0.5, -0.35);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.5, 0.35);
glVertex2f(1, 0.35);
glVertex2f(1, -0.35);
glVertex2f(0.5, -0.35);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.2, 0.7);
glVertex2f(-0.2, 0.996);
glVertex2f(0.2, 0.996);
glVertex2f(0.2, 0.7);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.2, -0.7);
glVertex2f(-0.2, -0.996);
glVertex2f(0.2, -0.996);
glVertex2f(0.2, -0.7);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.2, 0.7);
glVertex2f(0.2, 0.7);
glVertex2f(0.5, 0.35);
glVertex2f(0.5, -0.35);
glVertex2f(0.2, -0.7);
glVertex2f(-0.2, -0.7);
glVertex2f(-0.5, -0.35);
glVertex2f(-0.5, 0.35);
glEnd();
 	glFlush();
 }
 
  int main(int argc, char *argv[])
 {
 	glutInit(&argc, argv);
 	glutInitWindowSize(1000,1000);
 	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
 	
 	glutCreateWindow("Membuat Garis");
 	
 	glutDisplayFunc(Garis);
 	
 	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
 	
 	glutMainLoop();
 	
 	return 0;
 }
