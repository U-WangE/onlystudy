#include<stdio.h>
#include<time.h>

// 10������ ���� �ٸ� ���� (�� ī�� 2�徿)
// ����ڷκ��� 2���� �Է°��� �޾Ƽ� -> ���� ���� ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ� 

int arrayAnimal[4][5]; // ī�� ���� (20���� ī��) 
char *strAnimal[10];	

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int);
int conv_pos_y(int);

void main() {
	
	
	srand(time(NULL));
	
	initAnimalArray();
	initAnimalName();
	
	shuffleAnimal(); 
	
}

void initAnimalArray() {
	int i,j;
	
	for(i=0;i<4;i++) {
		for(j=0;j<5;j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName() {
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";
	
	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
}

void shuffleAnimal() {
	int i,j;
	int pos,x,y;
	
	// ����������
	// ����������
	// ����������
	// ����������
	
	for(i=0;i<10;i++) {
		for(j=0;j<2;j++) {
			pos = getEmptyPosition();
			x = conv_pos_x(pos);
			y = conv_pos_y(pos);
			
			arrayAnimal[x][y] = i;
		}
	}
}

// ��ǥ���� �� ���� ã�� 
int getEmptyPosition() {
	int randPos;
	int x,y; 
	
	// ����������   0  1  2  3  4  -> 0 0 0 0 0
	// ����������   5  6  7  8  9  -> 1 1 1 1 1
	// ����������  10 11 12 13 14  -> 2 2 2 2 2
	// ����������  15 16 17 18 19  -> 3 3 3 3 3
	
	while(1) {
		randPos = rand()%20; // 0 ~ 19 ������ ���� ��ȯ 
		// 19 -> (3,4)
		x = conv_pos_x(randPos);
		y = conv_pos_y(randPos);
		
		if(arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x) {
	// 19 -> (3,4)
	return x / 5;
}

int conv_pos_y(int y) {
	// 19 -> 19 / 5 ? ���� 3, ������ 4 
	return y % 5; // y �� 5 �� ���� ������ �� 
}
