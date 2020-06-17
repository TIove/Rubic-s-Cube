#pragma once

#include "Small_Cube.h"


class Cube_3D {
	Small_Cube a[3][3][3];
	
	int rotate[6];
	
	double size;
	
	unsigned int color[6];

public:
	
	int current;

	Cube_3D() {}

	Cube_3D(double size, unsigned int *color) {
		clear(size, color);
	}
    
    void set_current() {
        this->current = -1;
    }
    
    void change_point_of_view_right() {
        
        
        
    }
    
    void set_from_file(double size, Cube& cube, unsigned int *color) {
        this->size = size;
        int i, j, k;
        memset(rotate, 0, sizeof(rotate));
        current = -1;
        
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++) {
                switch (cube.get_forward_matrix()[2-j][i]) {
                    case 'G':
                        a[i][j][2].setColor(0, color[3]);
                        break;
                    case 'B':
                        a[i][j][2].setColor(0, color[2]);
                        break;
                    case 'W':
                        a[i][j][2].setColor(0, color[0]);
                        break;
                    case 'Y':
                        a[i][j][2].setColor(0, color[1]);
                        break;
                    case 'R':
                        a[i][j][2].setColor(0, color[4]);
                        break;
                    case 'O':
                        a[i][j][2].setColor(0, color[5]);
                        break;
                }
            }
                
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++) {
                switch (cube.get_back_matrix()[2-j][2-i]) {
                    case 'G':
                        a[i][j][0].setColor(1, color[3]);
                        break;
                    case 'B':
                        a[i][j][0].setColor(1, color[2]);
                        break;
                    case 'W':
                        a[i][j][0].setColor(1, color[0]);
                        break;
                    case 'Y':
                        a[i][j][0].setColor(1, color[1]);
                        break;
                    case 'R':
                        a[i][j][0].setColor(1, color[4]);
                        break;
                    case 'O':
                        a[i][j][0].setColor(1, color[5]);
                        break;
            }
        }
        
        for(k = 0; k < 3; k++)
            for(j = 0; j < 3; j++) {
                switch (cube.get_down_matrix()[2-k][j]) {
                    case 'G':
                        a[j][0][k].setColor(2, color[3]);
                        break;
                    case 'B':
                        a[j][0][k].setColor(2, color[2]);
                        break;
                    case 'W':
                        a[j][0][k].setColor(2, color[0]);
                        break;
                    case 'Y':
                        a[j][0][k].setColor(2, color[1]);
                        break;
                    case 'R':
                        a[j][0][k].setColor(2, color[4]);
                        break;
                    case 'O':
                        a[j][0][k].setColor(2, color[5]);
                        break;
            }
        }
        
        for(k = 0; k < 3; k++)
            for(j = 0; j < 3; j++) {
                switch (cube.get_up_matrix()[k][j]) {
                    case 'G':
                        a[j][2][k].setColor(3, color[3]);
                        break;
                    case 'B':
                        a[j][2][k].setColor(3, color[2]);
                        break;
                    case 'W':
                        a[j][2][k].setColor(3, color[0]);
                        break;
                    case 'Y':
                        a[j][2][k].setColor(3, color[1]);
                        break;
                    case 'R':
                        a[j][2][k].setColor(3, color[4]);
                        break;
                    case 'O':
                        a[j][2][k].setColor(3, color[5]);
                        break;
            }
        }
        
        for(i = 0; i < 3; i++)
            for(k = 0; k < 3; k++) {
                switch (cube.get_left_matrix()[2-k][i]) {
                    case 'G':
                        a[0][k][i].setColor(4, color[3]);
                        break;
                    case 'B':
                        a[0][k][i].setColor(4, color[2]);
                        break;
                    case 'W':
                        a[0][k][i].setColor(4, color[0]);
                        break;
                    case 'Y':
                        a[0][k][i].setColor(4, color[1]);
                        break;
                    case 'R':
                        a[0][k][i].setColor(4, color[4]);
                        break;
                    case 'O':
                        a[0][k][i].setColor(4, color[5]);
                        break;
            }
        }
        
        for(i = 0; i < 3; i++)
            for(k = 0; k < 3; k++) {
                switch (cube.get_right_matrix()[2-k][2-i]) {
                    case 'G':
                        a[2][k][i].setColor(5, color[3]);
                        break;
                    case 'B':
                        a[2][k][i].setColor(5, color[2]);
                        break;
                    case 'W':
                        a[2][k][i].setColor(5, color[0]);
                        break;
                    case 'Y':
                        a[2][k][i].setColor(5, color[1]);
                        break;
                    case 'R':
                        a[2][k][i].setColor(5, color[4]);
                        break;
                    case 'O':
                        a[2][k][i].setColor(5, color[5]);
                        break;
            }
        }
                
    }
    
	void clear(double size, unsigned int *color) {
		memset(rotate, 0, sizeof(rotate));
		this->size = size;
		current = -1;

		int i, j, k;
        
		for(i = 0; i < 6; i++)
			this->color[i] = color[i];

		// forward
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				a[i][j][2].setColor(0, color[0]);

		// back
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				a[i][j][0].setColor(1, color[1]);

		// down
		for(k = 0; k < 3; k++)
			for(j = 0; j < 3; j++)
				a[j][0][k].setColor(2, color[2]);

		// up
		for(k = 0; k < 3; k++)
			for(j = 0; j < 3; j++)
				a[j][2][k].setColor(3, color[3]);

		// left
		for(i = 0; i < 3; i++)
			for(k = 0; k < 3; k++)
				a[0][k][i].setColor(4, color[4]);

		// right
		for(i = 0; i < 3; i++)
			for(k = 0; k < 3; k++)
				a[2][k][i].setColor(5, color[5]);

		
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				for(k = 0; k < 3; k++)
					a[i][j][k].size = (size / 3.0) * 0.95;
	}

	void draw() {
		const double K = 0.65;
		
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(((1.0 - K)/2)*size + K*size/2, ((1.0 - K)/2)*size + K*size/2, ((1.0 - K)/2)*size + K*size/2);
		glutSolidCube(size * K);
		glPopMatrix();

		
		memset(ok, true, sizeof(ok));
		if (current != -1)
		{
			glPushMatrix();
			int i, j, k;

			if (current == 0 || current == 1) {
				k = (current & 1) * 2;
				
				for(i = 0; i < 3; i++)
					for(j = 0; j < 3; j++)
						ok[i][j][k] = false;
				
				glTranslated(size / 2, size / 2, 0);
				glRotatef(rotate[current], 0, 0, 1);
				glTranslated(-size / 2, -size / 2, 0);
				
				for(i = 0; i < 3; i++)
					for(j = 0; j < 3; j++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			
			else if (current == 2 || current == 3)
			{
				j = (current & 1) * 2;
				for(i = 0; i < 3; i++)
					for(k = 0; k < 3; k++)
						ok[i][j][k] = false;
				
				glTranslated(size / 2, 0, size / 2);
				glRotatef(rotate[current], 0, 1, 0);
				glTranslated(-size / 2, 0, -size / 2);
				for(i = 0; i < 3; i++)
					for(k = 0; k < 3; k++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			else if (current == 4 || current == 5)
			{
				i = (current & 1) * 2;
				for(j = 0; j < 3; j++)
					for(k = 0; k < 3; k++)
						ok[i][j][k] = false;
				
				glTranslated(0, size / 2, size / 2);
				glRotatef(rotate[current], 1, 0, 0);
				glTranslated(0, -size / 2, -size / 2);
				for(j = 0; j < 3; j++)
					for(k = 0; k < 3; k++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			glPopMatrix();
		}

		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				for(int k = 0; k < 3; k++)
					if (ok[i][j][k])
						
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
	}

public:
	void rot90(int idx, int sign)
	{
		int i, j, k;
    
		if (sign == -1)
			sign = 3;
		while(sign--)
		{
			if (idx == 0 || idx == 1) {
				
				k = (idx & 1) * 2;
				
				for(i = 0; i < 3; i++)
					for(j = 0; j < 3; j++)
						tmp[j][2 - i] = a[i][j][k];
				for(i = 0; i < 3; i++)
					for(j = 0; j < 3; j++)
						tmp[i][j].rotateZ(), a[i][j][k] = tmp[i][j];
			}
			
			else if (idx == 2 || idx == 3 || idx == 6)
			{
                if (idx == 6) {
                    j = 1;
                    for(i = 0; i < 3; i++)
                        for(k = 0; k < 3; k++)
                            tmp[k][2 - i] = a[i][j][k];
                    for(i = 0; i < 3; i++)
                        for(k = 0; k < 3; k++)
                            tmp[i][k].rotateX(), a[i][j][k] = tmp[i][k];
                }
                else{
                
                    j = (idx & 1) * 2;
                    for(i = 0; i < 3; i++)
                        for(k = 0; k < 3; k++)
                            tmp[k][2 - i] = a[i][j][k];
                    for(i = 0; i < 3; i++)
                        for(k = 0; k < 3; k++)
                            tmp[i][k].rotateX(), a[i][j][k] = tmp[i][k];
                }
			}
			else if (idx == 4 || idx == 5 || idx == 7)
			{
                if (idx == 7) {
                    i = 0;
                    for(j = 0; j < 3; j++)
                        for(k = 0; k < 3; k++)
                            tmp[k][2 - j] = a[i][j][k];
                    for(j = 0; j < 3; j++)
                        for(k = 0; k < 3; k++)
                            tmp[j][k].rotateY(), a[i][j][k] = tmp[j][k];
                } else {
                    i = (idx & 1) * 2;
				
				for(j = 0; j < 3; j++)
					for(k = 0; k < 3; k++)
						tmp[k][2 - j] = a[i][j][k];
				for(j = 0; j < 3; j++)
					for(k = 0; k < 3; k++)
						tmp[j][k].rotateY(), a[i][j][k] = tmp[j][k];
                }
			}
		}
	}

	void Rotate(int idx, int angle) {
		
		if (current == -1 || current == idx || idx == 7)
		{
			
			rotate[idx] += angle;

			if (rotate[idx] % 90 != 0)
			{
				current = idx;
			}
			else
			{
            
				if ((rotate[idx] < 0) ^ (current == 2 || current == 3 ))
					rot90(idx, 1);
				else
					rot90(idx, -1);
				rotate[idx] = 0;
				current = -1;
			}
		}
	}
private:
	int _angle[4];
	bool ok[4][4][4];
	Small_Cube tmp[4][4];
};

