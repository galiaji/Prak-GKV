// Nama				 : Galih Aji Syafaat
// NIM				 : 24060121130072
// Nama File		 : LenganGerak.cpp --> Praktikum 4
// Deskripsi file	 : membuat lengan yang dapat digerakan dengan masukan dari keyboard.
// Tanggal Pembuatan : 8-03-2022

#include <GL/glut.h>  
static int shoulder = 0, elbow = 0, palm = 0, jempol = 0, telunjuk =0,tengah = 0, manis = 0, kelingking = 0 ; 

 void init(void) 
 {  
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);  
 }
   
		 void display(void) 
		 {  
		 glClear (GL_COLOR_BUFFER_BIT);
		 // shoulder
		 glPushMatrix();  
		 glTranslatef (-1.0, 0.0, 0.0);  
		 glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);    
		 glTranslatef (1.0, 0.0, 0.0);
		 glPushMatrix();  
		 glScalef (2.0, 0.4, 1.0);
		 glutWireCube (.50);
		 glPopMatrix();  
		// elbow		 
		 glTranslatef (0.50, 0.0, 0.0);  
		 glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
		 glTranslatef (0.50, 0.0, 0.0);
		 glPushMatrix();  
		 glScalef (2.0, 0.4, 1.0);
		 glutWireCube (0.50);
		 glPopMatrix();
		 // palm
		 glTranslatef (0.45, 0.0, 0.0);  
		 glRotatef ((GLfloat) palm, 0.0, 0.0, 1.0);    
		 glTranslatef (0.45, 0.0, 0.0);
		 glPushMatrix();  
		 glScalef (2.0, 0.4, 1.0);
		 glutWireCube (0.5);
		 glPopMatrix();
		 
//jari
		//kelingking
		glPushMatrix();
			glTranslatef(0.5,0.0,-0.5);
			glRotatef((GLfloat)kelingking,0.0,0.0,1.0);
			glTranslatef(0.25,0.0,0.0);
			glScalef(0.5,0.2,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		
	
		
		//manis
		glPushMatrix();
			glTranslatef(.5,0.0,-0.2);
			glRotatef((GLfloat)manis,0.0,0.0,1.0);
			glTranslatef(0.35,0.0,0.0);
			glScalef(0.7,0.2,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		
		//tengah
		glPushMatrix();
			glTranslatef(.5,0.0,0.1);
			glRotatef((GLfloat)tengah,0.0,0.0,1.0);
			glTranslatef(0.45,0.0,0.0);
			glScalef(0.9,0.2,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		
		//telunjuk
		glPushMatrix();
			glTranslatef(.5,0.0,0.4);
			glRotatef((GLfloat)telunjuk,0.0,0.0,1.0);
			glTranslatef(0.35,0.0,0.0);
			glScalef(0.7,0.2,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		
		//jempol
		glPushMatrix();
			glTranslatef(0.0,0.0,0.5);
		 	glRotatef(-45,0.0,1.0,0.0);
		 	glRotatef((GLfloat)jempol,0.0,1.0,0.0);
		 	glTranslatef(0.3,0.0,0.1);
			glScalef(0.5,0.2,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		glPopMatrix(); 
		
 glutSwapBuffers();
}
 void reshape (int w, int h) {  glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
glMatrixMode (GL_PROJECTION);
glLoadIdentity (); 
gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef (0.0, 0.0, -5.0);
} 
void keyboard(unsigned char key, int x, int y)
{        switch (key) 
{
case 'o': shoulder = (shoulder + 5) % 360;         glutPostRedisplay();
break;  case 'O': shoulder = (shoulder -5) % 360;  glutPostRedisplay();
break;  case 'i': elbow = (elbow + 5) % 360;       glutPostRedisplay();
break;  case 'I': elbow = (elbow -5) % 360;        glutPostRedisplay();
break;  case 'p': palm = (palm + 5) % 360;       glutPostRedisplay();
break;  case 'P': palm = (palm -5) % 360;        glutPostRedisplay();
break;  case 'q': jempol = (jempol + 5) % 360;       glutPostRedisplay();
break;  case 'Q': jempol = (jempol -5) % 360;        glutPostRedisplay();
break;  case 'w': telunjuk = (telunjuk + 5) % 360;       glutPostRedisplay();
break;  case 'W': telunjuk = (telunjuk -5) % 360;        glutPostRedisplay();
break;  case 'e': tengah = (tengah + 5) % 360;       glutPostRedisplay();
break;  case 'E': tengah = (tengah -5) % 360;        glutPostRedisplay();
break;  case 'a': manis = (manis + 5) % 360;       glutPostRedisplay();
break;  case 'A': manis = (manis -5) % 360;        glutPostRedisplay();
break;  case 'd': kelingking = (kelingking + 5) % 360;       glutPostRedisplay();
break;  case 'D': kelingking = (kelingking -5) % 360;        glutPostRedisplay();
break;  case 27: exit(0);
break;
default: break;  
} 
} 
 
 int main(int argc, char** argv) 
 {
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize (700, 600);
 glutInitWindowPosition (1000, 100);
 glutCreateWindow (argv[0]);
 init();  
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0; 
 }
