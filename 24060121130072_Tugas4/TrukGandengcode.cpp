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
	float PHI = 3.1415;

	void cylinder(float alas,float atas,float tinggi);
	GLfloat  source_light[]={0.30,0.30,0.30,0.50};
	double Loop,LoopAll=0;
	bool on=false;
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
	 glColor3f(0.0, 1.0, 0.0); 
	 glBegin(GL_LINES); 
	 for(i=Z_MIN;i<Z_MAX;i+=gap) 
	 { 
	glVertex3f(i, -0.9, Z_MIN); 
	 glVertex3f(i, -0.9, Z_MAX); 
	 } 
	 for(i=X_MIN;i<X_MAX;i+=gap) 
	 { 
	 glVertex3f(X_MIN, -0.3, i); 
	 glVertex3f(X_MAX, -0.3, i); 
	 } 
	 glEnd(); 
	} 
			void BakTruk2() 
			{glColor3f (1.0,0.0,0.0);
			glPushMatrix(); 
			glTranslatef(0,0,3);
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,1.0f,0.0f); 
			glVertex3f(3.0f,1.0f,0.0f); 
			glVertex3f(3.0f,5.0f,0.0f); 
			glVertex3f(-6.0f,5.0f,0.0f);
			glEnd(); 
			glPopMatrix();
	
			//Atas
		
			glPushMatrix(); 
			glRotated(-90, 1, 0, 0); 
			glTranslatef(0,-4,5); 
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,1.0f,0.0f); 
			glVertex3f(3.0f,1.0f,0.0f); 
			glVertex3f(3.0f,5.0f,0.0f); 
			glVertex3f(-6.0f,5.0f,0.0f);
			 glEnd(); 
			 glPopMatrix(); 
			//Kiri
			glPushMatrix(); 
			glRotated(-180, 1, 0, 0); 
			glTranslatef(0,-6,1); 
			glBegin(GL_QUADS); 
	 		glTexCoord2f(0.0f,0.0f); // kiri bawah 
	 		glVertex3f(-6.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,0.0f); // kanan bawah 
	 		glVertex3f(3.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,1.0f); // kanan atas 
			glVertex3f(3.0f,5.0f,0.0f); 
	 		glTexCoord2f(0.0f,1.0f); // kanan bawah 
	 		glVertex3f(-6.0f,5.0f,0.0f);
			 glEnd(); 
			 glPopMatrix(); 
			//Bawah 
			glPushMatrix(); 
			glRotated(-90, 1, 0, 0); 
			glTranslatef(0,-4,1); 
			glBegin(GL_QUADS); 
	 		glTexCoord2f(0.0f,0.0f); // kiri bawah 
	 		glVertex3f(-6.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,0.0f); // kanan bawah 
	 		glVertex3f(3.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,1.0f); // kanan atas 
			glVertex3f(3.0f,5.0f,0.0f); 
	 		glTexCoord2f(0.0f,1.0f); // kanan bawah 
	 		glVertex3f(-6.0f,5.0f,0.0f);
			glEnd(); 
			glPopMatrix(); 
			
			//Depan
			glPushMatrix(); 
			glRotated(90, 0, 1, 0); 
			glTranslatef(0,0,3); 
			glBegin(GL_QUADS); 
			glVertex3f(-3.0f,1.0f,0.0f); 
			glVertex3f(1.0f,1.0f,0.0f); 
			glVertex3f(1.0f,5.0f,0.0f); 
			glVertex3f(-3.0f,5.0f,0.0f);
			glEnd();
			glPopMatrix();
			
					//Belakang
			glPushMatrix(); 
			glRotated(90, 0, 1, 0); 
			glTranslatef(0,0,-6); 
			glBegin(GL_QUADS); 
			glVertex3f(-3.0f,1.0f,0.0f); 
			glVertex3f(1.0f,1.0f,0.0f); 
			glVertex3f(1.0f,5.0f,0.0f); 
			glVertex3f(-3.0f,5.0f,0.0f);
			glEnd();
			glPopMatrix();
	}
	
				void BakTruk1() 
			{glColor3f (1.0,0.0,0.0);
			
			//Kanan
			glPushMatrix(); 
			glTranslatef(10,0,3);
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,1.0f,0.0f); 
			glVertex3f(3.0f,1.0f,0.0f); 
			glVertex3f(3.0f,5.0f,0.0f); 
			glVertex3f(-6.0f,5.0f,0.0f);
			glEnd(); 
			glPopMatrix();
	
			//Atas
		
			glPushMatrix(); 
			glRotated(-90, 1, 0, 0); 
			glTranslatef(10,-4,5); 
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,1.0f,0.0f); 
			glVertex3f(3.0f,1.0f,0.0f); 
			glVertex3f(3.0f,5.0f,0.0f); 
			glVertex3f(-6.0f,5.0f,0.0f);
			 glEnd(); 
			 glPopMatrix(); 
			//Kiri
			glPushMatrix(); 
			glRotated(-180, 1, 0, 0); 
			glTranslatef(10,-6,1); 
			glBegin(GL_QUADS); 
	 		glTexCoord2f(0.0f,0.0f); // kiri bawah 
	 		glVertex3f(-6.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,0.0f); // kanan bawah 
	 		glVertex3f(3.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,1.0f); // kanan atas 
			glVertex3f(3.0f,5.0f,0.0f); 
	 		glTexCoord2f(0.0f,1.0f); // kanan bawah 
	 		glVertex3f(-6.0f,5.0f,0.0f);
			 glEnd(); 
			 glPopMatrix(); 
			//Bawah 
			glPushMatrix(); 
			glRotated(-90, 1, 0, 0); 
			glTranslatef(10,-4,1); 
			glBegin(GL_QUADS); 
	 		glTexCoord2f(0.0f,0.0f); // kiri bawah 
	 		glVertex3f(-6.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,0.0f); // kanan bawah 
	 		glVertex3f(3.0f,1.0f,0.0f); 
	 		glTexCoord2f(1.0f,1.0f); // kanan atas 
			glVertex3f(3.0f,5.0f,0.0f); 
	 		glTexCoord2f(0.0f,1.0f); // kanan bawah 
	 		glVertex3f(-6.0f,5.0f,0.0f);
			glEnd(); 
			glPopMatrix(); 
			
			//Depan
			glPushMatrix(); 
			glRotated(90, 0, 1, 0); 
			glTranslatef(0,0,13); 
			glBegin(GL_QUADS); 
			glVertex3f(-3.0f,1.0f,0.0f); 
			glVertex3f(1.0f,1.0f,0.0f); 
			glVertex3f(1.0f,5.0f,0.0f); 
			glVertex3f(-3.0f,5.0f,0.0f);
			glEnd();
			glPopMatrix();
			
					//Belakang
			glPushMatrix(); 
			glRotated(90, 0, 1, 0); 
			glTranslatef(0,0,4); 
			glBegin(GL_QUADS); 
			glVertex3f(-3.0f,1.0f,0.0f); 
			glVertex3f(1.0f,1.0f,0.0f); 
			glVertex3f(1.0f,5.0f,0.0f); 
			glVertex3f(-3.0f,5.0f,0.0f);
			glEnd();
			glPopMatrix();
		}
		
		void sasis2(){ 
			//Kanan 
			glColor3f (1.0,1.0,1.0);
			glPushMatrix(); 
			glTranslatef(0,0,2.5);
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,0.50f,0.0f); 
			glVertex3f(3.0f,0.50f,0.0f); 
			glVertex3f(3.0f,1.0f,0.0f); 
			glVertex3f(-6.0f,1.0f,0.0f);
			
			glEnd(); 
			glPopMatrix();
	
			//Kiri
	
			glColor3f (1.0,1.0,1.0);
			glPushMatrix(); 
			glTranslatef(0,0,-0.5);
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,0.50f,0.0f); 
			glVertex3f(3.0f,0.50f,0.0f); 
			glVertex3f(3.0f,1.0f,0.0f); 
			glVertex3f(-6.0f,1.0f,0.0f);
			
			glEnd(); 
			glPopMatrix();
	
			//sasis bawah 
			glPushMatrix(); 
			glRotated(90, 1.5, 0,0 ); 
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,2.50f,-0.50f); 
			glVertex3f(3.0f,2.50f,-0.50f); 
			glVertex3f(3.0f,-0.50f,-0.50f); 
			glVertex3f(-6.0f,-0.50f,-0.50f);
			
			glEnd(); 
			glPopMatrix();
	//		//bemper bak2 belakang
			glPushMatrix(); 
			glRotated(-90, 0, 1,0 ); 
			glBegin(GL_QUADS); 
			glVertex3f(-0.50f,1.0f,6.0f); 
			glVertex3f(2.50f,1.0f,6.0f); 
			glVertex3f(2.50f,0.250f,6.0f); 
			glVertex3f(-0.50f,0.250f,6.0f);
			glEnd(); 
			glPopMatrix();
	//		bumper bak 2 depan
			glPushMatrix(); 
			glRotated(-90, 0, 1,0 ); 
			glBegin(GL_QUADS); 
			glVertex3f(-0.50f,1.0f,-3.0f); 
			glVertex3f(2.50f,1.0f,-3.0f); 
			glVertex3f(2.50f,0.50f,-3.0f); 
			glVertex3f(-0.50f,0.50f,-3.0f);
			glEnd(); 
			glPopMatrix();
	// Gandengan
				glPushMatrix(); 
			glColor3f(0,0,0);
			glBegin(GL_QUADS); 
			glVertex3f(3.0f,1.0f,1.20f); 
			glVertex3f(4.50f,1.0f,1.20f); 
			glVertex3f(4.50f,0.50f,1.20f); 
			glVertex3f(3.0f,0.50f,1.20f);
			glEnd(); 
			glPopMatrix();
	
					glPushMatrix(); 
			
			glBegin(GL_QUADS); 
			glVertex3f(3.0f,1.0f,0.80f); 
			glVertex3f(4.50f,1.0f,0.80f); 
			glVertex3f(4.50f,0.50f,0.80f); 
			glVertex3f(3.0f,0.50f,0.80f);
			glEnd(); 
			glPopMatrix();
			
							glPushMatrix(); 
			
			glBegin(GL_QUADS); 
			glVertex3f(3.0f,1.0f,1.20f); 
			glVertex3f(4.50f,1.0f,1.20f); 
			glVertex3f(4.50f,1.0f,0.80f); 
			glVertex3f(3.0f,1.0f,0.80f);
			glEnd(); 
			glPopMatrix();
	
					glPushMatrix(); 
			
			glBegin(GL_QUADS); 
			glVertex3f(3.0f,0.50f,1.20f); 
			glVertex3f(4.50f,0.50f,1.20f); 
			glVertex3f(4.50f,0.50f,0.80f); 
			glVertex3f(3.0f,0.50f,0.80f);
			glEnd(); 
			glPopMatrix();
	}
	
	void sasis1(){
			//Kanan 
			glColor3f (1.0,1.0,1.0);
			glPushMatrix(); 
			glTranslatef(10,0,2.5);
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,0.50f,0.0f); 
			glVertex3f(6.0f,0.50f,0.0f); 
			glVertex3f(6.0f,1.0f,0.0f); 
			glVertex3f(-6.0f,1.0f,0.0f);
			
			glEnd(); 
			glPopMatrix();
	
			//Kiri
	
			glColor3f (1.0,1.0,1.0);
			glPushMatrix(); 
			glTranslatef(10,0,-0.5);
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,0.50f,0.0f); 
			glVertex3f(6.0f,0.50f,0.0f); 
			glVertex3f(6.0f,1.0f,0.0f); 
			glVertex3f(-6.0f,1.0f,0.0f);
			
			glEnd(); 
			glPopMatrix();
	
			//sasis bawah 
			glPushMatrix();
			glTranslatef(10,0,0); 
			glRotated(90, 1.5, 0,0 ); 
			glBegin(GL_QUADS); 
			glVertex3f(-6.0f,2.50f,-0.50f); 
			glVertex3f(6.0f,2.50f,-0.50f); 
			glVertex3f(6.0f,-0.50f,-0.50f); 
			glVertex3f(-6.0f,-0.50f,-0.50f);
			
			glEnd(); 
			glPopMatrix();
	//		//bemper bak1 belakang
			glPushMatrix(); 
			glRotated(-90, 0, 1,0 ); 
			glBegin(GL_QUADS); 
			glVertex3f(-0.50f,1.0f,-4.0f); 
			glVertex3f(2.50f,1.0f,-4.0f); 
			glVertex3f(2.50f,0.250f,-4.0f); 
			glVertex3f(-0.50f,0.250f,-4.0f);
			glEnd(); 
			glPopMatrix();
	//		bumper bak 2 depan
			glPushMatrix(); 
			glRotated(-90, 0, 1,0 ); 
			glBegin(GL_QUADS); 
			glVertex3f(-0.50f,1.0f,-16.0f); 
			glVertex3f(2.50f,1.0f,-16.0f); 
			glVertex3f(2.50f,0.50f,-16.0f); 
			glVertex3f(-0.50f,0.50f,-16.0f);
			glEnd(); 
			glPopMatrix();
	
	}
	
	void Kepala(){
	
	
		//bagian 1
			glPushMatrix();
			glColor3f (1.0,.50,0.0);
			glBegin(GL_QUADS);
			glVertex3f(13.0f,1.0f,-1.0f);
			glVertex3f(16.0f,1.0f,-1.0f);
			glVertex3f(16.0f,4.50f,-1.0f);
			glVertex3f(13.0f,4.50f,-1.0f);
			 glEnd();
			 glPopMatrix();

		//bagian 1
			glPushMatrix();
			glTranslatef(0,0,4);
			glBegin(GL_QUADS);
			glVertex3f(13.0f,1.0f,-1.0f);
			glVertex3f(16.0f,1.0f,-1.0f);
			glVertex3f(16.0f,4.50f,-1.0f);
			glVertex3f(13.0f,4.50f,-1.0f);
			 glEnd();
			 glPopMatrix();
		// Atas
			glPushMatrix();
			glRotatef(90,0,0,1);
			glBegin(GL_QUADS);
			glVertex3f(4.5f,-13.0f,-1.0f);
			glVertex3f(4.50f,-16.0f,-1.0f);
			glVertex3f(4.50f,-16.0f,3.0f);
			glVertex3f(4.50f,-13.0f,3.0f);
			 glEnd();
			 glPopMatrix();
		//Bawah	 
			glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3f(13.0f,1.0f,-1.0f);
			glVertex3f(16.0f,1.0f,-1.0f);
			glVertex3f(13.0f,1.0f,3.0f);
			glVertex3f(16.0f,1.0f,3.0f);
			 glEnd();
			 glPopMatrix();
		//kaca depan
			glPushMatrix();
			glColor3f (0.0,1.0,1.0);
			glBegin(GL_QUADS);
			glVertex3f(16.0f, 4.4f, -1.0f);
			glVertex3f(16.50f, 2.8f, -1.0f);
			glVertex3f(16.50f, 2.8f, 3.0f);
			glVertex3f(16.0f, 4.4f, 3.0f);
			glEnd();
			glPopMatrix();
		//grill
					glPushMatrix();
			glColor3f (1.0,0.50,.0);
			glBegin(GL_QUADS);
			glVertex3f(16.50f, 1.0f, -1.0f);
			glVertex3f(16.50f, 2.8f, -1.0f);
			glVertex3f(16.50f, 2.8f, 3.0f);
			glVertex3f(16.50f, 1.0f, 3.0f);
			glEnd();
			glPopMatrix();
	//	//bagian 2
		 glPushMatrix();
		glColor3f (1.0,.50,0.0);
		glBegin(GL_QUADS);
		glVertex3f(16.0f, 2.8f, -1.0f);
		glVertex3f(16.50f, 2.8f, -1.0f);
		glVertex3f(16.50f, 1.0f, -1.0f);
		glVertex3f(16.0f, 1.0f, -1.0f);
		glEnd();
			glPopMatrix();
		//bagian 2
		glPushMatrix();
		glColor3f (.0,1.0,1.0);
			glBegin(GL_TRIANGLES);
			glVertex3f(16.0f,4.4f,-1.0f);
			glVertex3f(16.0f,2.8f,-1.0f);
			glVertex3f(16.5f,2.8f,-1.0f);
			glEnd();
			 glPopMatrix();
			 
		//bagian 2
		 glPushMatrix();
		 glTranslatef(0,0,4);
		glColor3f (1.0,.50,0.0);
		glBegin(GL_QUADS);
		glVertex3f(16.0f, 2.8f, -1.0f);
		glVertex3f(16.50f, 2.8f, -1.0f);
		glVertex3f(16.50f, 1.0f, -1.0f);
		glVertex3f(16.0f, 1.0f, -1.0f);
		glEnd();
			glPopMatrix();
		//bagian 2
		glPushMatrix();
		glTranslatef(0,0,4);
		glColor3f (.0,1.0,1.0);
			glBegin(GL_TRIANGLES);
			glVertex3f(16.0f,4.4f,-1.0f);
			glVertex3f(16.0f,2.8f,-1.0f);
			glVertex3f(16.5f,2.8f,-1.0f);
			glEnd();
			 glPopMatrix();
			 
		// Bumper
		glPushMatrix();
		glTranslatef(0,0,4);
		glColor3f (.0,.0,.0);
		glBegin(GL_QUADS);
		glVertex3f(16.0f, 0.5f, -1.0f);
		glVertex3f(16.75f, 0.5f, -1.0f);
		glVertex3f(16.75f, 1.0f, -1.0f);
		glVertex3f(16.0f, 1.0f, -1.0f);
		glEnd();
			glPopMatrix();
			
			glPushMatrix();
		glColor3f (.0,.0,.0);
		glBegin(GL_QUADS);
		glVertex3f(16.0f, 0.5f, -1.0f);
		glVertex3f(16.75f, 0.5f, -1.0f);
		glVertex3f(16.75f, 1.0f, -1.0f);
		glVertex3f(16.0f, 1.0f, -1.0f);
		glEnd();
			glPopMatrix();
			
		glPushMatrix();
		
		glColor3f (.0,.0,.0);
		glBegin(GL_QUADS);
		glVertex3f(16.75f, 0.5f, -1.0f);
		glVertex3f(16.75f, 0.5f, 3.0f);
		glVertex3f(16.75f, 1.0f, 3.0f);
		glVertex3f(16.75f, 1.0f, -1.0f);
		glEnd();
			glPopMatrix();
			
			glPushMatrix();
		
		glColor3f (1.0,1.0,1.0);
		glBegin(GL_QUADS);
		glVertex3f(16.0f, 0.5f, -1.0f);
		glVertex3f(16.0f, 0.5f, 3.0f);
		glVertex3f(16.0f, 1.0f, 3.0f);
		glVertex3f(16.0f, 1.0f, -1.0f);
		glEnd();
			glPopMatrix();
			
		glPushMatrix();
			glColor3f (.0,0.0,.0);
			glBegin(GL_QUADS);
			glVertex3f(16.750f, 1.0f, -1.0f);
			glVertex3f(16.50f, 1.0f, -1.0f);
			glVertex3f(16.50f, 1.0f, 3.0f);
			glVertex3f(16.750f, 1.0f, 3.0f);
			glEnd();
			glPopMatrix();

glPushMatrix();
			glColor3f (.0,0.0,.0);
			glBegin(GL_QUADS);
			glVertex3f(16.75f, .50f, -1.0f);
			glVertex3f(16.25f, .50f, -1.0f);
			glVertex3f(16.25f, .50f, 3.0f);
			glVertex3f(16.75f, .50f, 3.0f);
			glEnd();
			glPopMatrix();
			
		glPushMatrix();
		glTranslatef(0,0,4);
		glColor3f (1.0,1.0,1.0);
		glBegin(GL_TRIANGLES);
		glVertex3f(16.0f,1.0f,-1.0f);
		glVertex3f(16.0f,1.0f,-1.0f);
		glVertex3f(15.5f,0.6f,-1.0f);
		glEnd();
		glPopMatrix();
		
				// pintu
		glPushMatrix();
		glColor3f (0.0,0.50,1.0);
		glBegin(GL_QUADS);
		glVertex3f(14.0f,1.0f,-1.0009f);
		glVertex3f(15.90f,1.0f,-1.0009f);
		glVertex3f(15.90f,4.40f,-1.0009f);
		glVertex3f(14.0f,4.40f,-1.0009f);
		glEnd();
		glPopMatrix();	
			
		glPushMatrix();
		glBegin(GL_QUADS);
		glVertex3f(14.0f,1.0f,3.0009f);
		glVertex3f(15.90f,1.0f,3.0009f);
		glVertex3f(15.90f,4.40f,3.0009f);
		glVertex3f(14.0f,4.40f,3.0009f);
		glEnd();
		glPopMatrix();
		
		//kaca pintu		
		glPushMatrix();
		glColor3f (.0,1.0,1.0);
		glBegin(GL_QUADS);
		glVertex3f(14.10f,3.30f,-1.00091f);
		glVertex3f(15.80f,2.80f,-1.00091f);
		glVertex3f(15.80f,4.30f,-1.00091f);
		glVertex3f(14.10f,4.30f,-1.00091f);
		glEnd();
		glPopMatrix();	
			
		glPushMatrix();
		glBegin(GL_QUADS);
		glVertex3f(14.10f,3.30f,3.0091f);
		glVertex3f(15.80f,2.80f,3.0091f);
		glVertex3f(15.80f,4.30f,3.0091f);
		glVertex3f(14.10f,4.30f,3.0091f);
		glEnd();
		glPopMatrix();
	// lampu	
			glPushMatrix();
			glColor3f (1.0,1.0,1.0);
			glBegin(GL_QUADS);
			glVertex3f(16.509f, 1.30f, 1.90f);
			glVertex3f(16.509f, 1.7f, 1.90f);
			glVertex3f(16.509f, 1.8f, 2.70f);
			glVertex3f(16.509f, 1.30f, 2.70f);
			glEnd();
			glPopMatrix();
			
			glPushMatrix();
			glColor3f (1.0,1.0,1.0);
			glBegin(GL_QUADS);
			glVertex3f(16.509f, 1.30f, 0.10f);
			glVertex3f(16.509f, 1.7f, 0.10f);
			glVertex3f(16.509f, 1.8f, -0.70f);
			glVertex3f(16.509f, 1.30f, -0.70f);
			glEnd();
			glPopMatrix();
			
	// lampu bemper depan 
				glPushMatrix();
			glColor3f (1.0,1.0,0.0);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.650f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.9f);
			glVertex3f(16.76f, 0.650f, 2.9f);
			glEnd();
			glPopMatrix();

				glPushMatrix();
			glColor3f (1.0,1.0,0.0);
			glTranslatef(0,0,-2.9);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.650f, 1.99f);
			glVertex3f(16.76f, 0.85f, 1.99f);
			glVertex3f(16.76f, 0.85f, 2.8f);
			glVertex3f(16.76f, 0.650f, 2.8f);
			glEnd();
			glPopMatrix();
	// lampu bemper belakang
				glPushMatrix();
			glColor3f (1.0,0.0,0.0);
			glTranslatef(-22.77,0,-0.5);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
				glPushMatrix();
			glColor3f (1.0,0.0,0.0);
			glTranslatef(-22.77,0,-2.3);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
				glPushMatrix();
			glColor3f (1.0,1.0,0.0);
			glTranslatef(-22.77,0,-0.5);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
				glPushMatrix();
			glColor3f (1.0,1.0,0.0);
			glTranslatef(-22.77,0,-2.3);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
			// bemper belakang truk
							glPushMatrix();
			glColor3f (1.0,0.0,0.0);
			glTranslatef(-12.77,0,-0.5);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
				glPushMatrix();
			glColor3f (1.0,0.0,0.0);
			glTranslatef(-12.77,0,-2.3);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.0f);
			glVertex3f(16.76f, 0.85f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
				glPushMatrix();
			glColor3f (1.0,1.0,0.0);
			glTranslatef(-12.77,0,-0.5);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
				glPushMatrix();
			glColor3f (1.0,1.0,0.0);
			glTranslatef(-12.77,0,-2.3);
			glBegin(GL_QUADS);
			glVertex3f(16.76f, 0.50f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.0f);
			glVertex3f(16.76f, 0.3f, 2.8f);
			glVertex3f(16.76f, 0.50f, 2.8f);
			glEnd();
			glPopMatrix();
	// GRIL ABU
		glPushMatrix();
			glColor3f (1.0,1.0,1.0);
			glBegin(GL_QUADS);
			glVertex3f(16.509f, 2.f, 1.80f);
			glVertex3f(16.509f, 1.30f, 1.80f);
			glVertex3f(16.509f, 2.f, 0.20f);
			glVertex3f(16.509f, 1.30f, 0.20f);
			glEnd();
			glPopMatrix();
			
		
	//sein 
	glPushMatrix();
			glColor3f (1.0,1.0,0.0);
			glBegin(GL_QUADS);
			glVertex3f(16.509f, 1.350f, 2.80f);
			glVertex3f(16.509f, 1.9f, 2.80f);
			glVertex3f(16.509f, 1.8f, 2.70f);
			glVertex3f(16.509f, 1.30f, 2.70f);
			glEnd();
			glPopMatrix();
			
			glPushMatrix();
			glColor3f (1.0,1.0,.0);
			glBegin(GL_QUADS);
			glVertex3f(16.509f, 1.350f, -0.80f);
			glVertex3f(16.509f, 1.9f, -0.80f);
			glVertex3f(16.509f, 1.8f, -0.70f);
			glVertex3f(16.509f, 1.30f, -0.70f);
			glEnd();
			glPopMatrix();
	}
	
	void cylinder(float alas, float atas, float tinggi)
{
	float i;
	// roda paling belakamg kiri
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(-4.50, 0.28, -1.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	
	// roda bak belakang bagian depan kiri
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(1.8, 0.28, -alas / 8);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	// roda paling belakang kanan
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
		glRotatef(180,-4.50, 0.28, 0);
	glTranslatef(-4.50, 0.28, -3.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();

	// roda bak belakang kanan depan
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
		glRotatef(180,1.8, 0.28, 0);
	glTranslatef(1.8, 0.28, -3.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	// roda belakang truk kiri 1
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(5.50, 0.28, -1.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	
	// roda belakang truk kiri 2
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(7, 0.28, -1.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	// roda truk depan kiri
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(14.6, 0.28, -1.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	
	// roda belakang truk kanan 1
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(180,5, 0.28,0);
	glTranslatef(5.50, 0.28, -3.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	
	// roda belakang truk kanan 2
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(180,6.5, 0.28,0);
	glTranslatef(7, 0.28, -3.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
	glPopMatrix();
	// roda depan truk
		glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(180,14.6, 0.28,0);	
	glTranslatef(14.6, 0.28, -3.01);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{	glColor3f(0.0,0.0,0.0);
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	
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
	 
	 BakTruk1();
	 BakTruk2();
	 sasis1();
	 sasis2(); 
	 Kepala();
	 cylinder(0.620,0.620,0.5);
	 glutSwapBuffers(); 
	 glFlush(); 
	} 
	void pressKey(int key, int x, int y) { 
	 // Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas 
	 // Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak 
	 switch (key) { 
	 case GLUT_KEY_LEFT : deltaAngle = -0.01f;break; 
	 case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break; 
	 case GLUT_KEY_UP : deltaMove = 1;break; 
	 case GLUT_KEY_DOWN : deltaMove = -1;break; 
	 } 
	} 
	void releaseKey(int key, int x, int y) { 
	 // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
	 // Saat tombol dilepas, variabel angle dan move diset nol =>kamera berhenti 
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
	 glutCreateWindow("Truk Gandeng"); 
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
