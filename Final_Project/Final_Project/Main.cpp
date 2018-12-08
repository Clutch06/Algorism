#include <gl/freeglut.h>
#include "Jump.h"

GLvoid DrawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);

void Jump(int value);

void floor();
void cube();

GLfloat side_move = 0.0;
int jump_done = false;

void main(int argc, char** argv)
{
	// 윈도우 초기화 및 생성
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 0);
	glutInitWindowSize(1680, 1020);
	glutCreateWindow("openGL");

	// 필요한 콜백함수 설정
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, Jump, 1);

	// 이벤트 루프 실행
	glutMainLoop();
}

GLvoid DrawScene()
{
	// 윈도우, 깊이 버퍼 클리어
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	floor();	// 바닥 그리기

	glTranslatef(side_move, 0.0, 0.0);
	glTranslatef(0.0, jump, 0.0);

	cube();	// 직육면체 그리기

	// 결과 출력
	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	//--- 뷰포트 변환 설정
	glViewport(0, 0, w, h);

	// 투영 행렬 스택 재설정 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0f, w / h, 1.0, 2000.0);	// 원근 투영
	glTranslatef(0.0, 0.0, -1000.0);     // 투영 공간을 화면 안쪽으로 이동하여 시야를 확보한다.
	//glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);

	// 모델 뷰 행렬 스택 재설정 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 관측 변환: 카메라의 위치 설정 (필요한 경우, 다른 곳에 설정 가능) 
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		side_move -= 20.0;
		
		if (side_move <= -200.0)
			side_move += 20.0;
	}

	if (key == 'd')
	{
		side_move += 20.0;

		if (side_move >= 200.0)
			side_move -= 20.0;
	}

	if (key == ' ')
		jumping = true;

	// 화면 재출력을 위하여 디스플레이 콜백 함수 호출
	glutPostRedisplay();
}

void Jump(int value)
{
	if (jumping == true)
	{
		jump += jump_scale;

		if (jump <= 0)
			jump_scale = 30;

		else if (jump >= 150) {
			jump_scale = -30;
			jump_done = true;
		}

		if (jump_done && jump < 0)
			jumping = false;

	}

	glutPostRedisplay(); 
	glutTimerFunc(100, Jump, 1); // 타이머함수 재 설정
}

void floor()
{
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
		glVertex3f(-300.0, -200.0, -1000.0);
		glVertex3f(-300.0, -200.0, 700.0);
		glVertex3f(300.0, -200.0, 700.0);
		glVertex3f(300.0, -200.0, -1000.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(10.0);
	glBegin(GL_LINES);
		glVertex3f(-100.0, -200.0, -1000.0);
		glVertex3f(-100.0, -200.0, -900.0);
		glVertex3f(-100.0, -200.0, -800.0);
		glVertex3f(-100.0, -200.0, -700.0);
		glVertex3f(-100.0, -200.0, -600.0);
		glVertex3f(-100.0, -200.0, -500.0);
		glVertex3f(-100.0, -200.0, -400.0);
		glVertex3f(-100.0, -200.0, -300.0);
		glVertex3f(-100.0, -200.0, -200.0);
		glVertex3f(-100.0, -200.0, -100.0);
		glVertex3f(-100.0, -200.0, 0.0);
		glVertex3f(-100.0, -200.0, 100.0);
		glVertex3f(-100.0, -200.0, 200.0);
		glVertex3f(-100.0, -200.0, 300.0);
		glVertex3f(-100.0, -200.0, 400.0);
		glVertex3f(-100.0, -200.0, 500.0);
		glVertex3f(-100.0, -200.0, 600.0);
		glVertex3f(-100.0, -200.0, 700.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(10.0);
	glBegin(GL_LINES);
		glVertex3f(100.0, -200.0, -1000.0);
		glVertex3f(100.0, -200.0, -900.0);
		glVertex3f(100.0, -200.0, -800.0);
		glVertex3f(100.0, -200.0, -700.0);
		glVertex3f(100.0, -200.0, -600.0);
		glVertex3f(100.0, -200.0, -500.0);
		glVertex3f(100.0, -200.0, -400.0);
		glVertex3f(100.0, -200.0, -300.0);
		glVertex3f(100.0, -200.0, -200.0);
		glVertex3f(100.0, -200.0, -100.0);
		glVertex3f(100.0, -200.0, 0.0);
		glVertex3f(100.0, -200.0, 100.0);
		glVertex3f(100.0, -200.0, 200.0);
		glVertex3f(100.0, -200.0, 300.0);
		glVertex3f(100.0, -200.0, 400.0);
		glVertex3f(100.0, -200.0, 500.0);
		glVertex3f(100.0, -200.0, 600.0);
		glVertex3f(100.0, -200.0, 700.0);
	glEnd();
}

void cube()
{
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-50.0, -200.0, 450.0);
		glVertex3f(-50.0, -200.0, 550.0);
		glVertex3f(50.0, -200.0, 550.0);
		glVertex3f(50.0, -200.0, 450.0);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(-50.0, -100.0, 450.0);
		glVertex3f(-50.0, -100.0, 550.0);
		glVertex3f(50.0, -100.0, 550.0);
		glVertex3f(50.0, -100.0, 450.0);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(-50.0, -100.0, 550.0);
		glVertex3f(-50.0, -200.0, 550.0);
		glVertex3f(50.0, -200.0, 550.0);
		glVertex3f(50.0, -100.0, 550.0);
	glEnd();







	glDisable(GL_CULL_FACE);
}