#include<stdio.h>
#include<time.h>

// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기 

int arrayAnimal[4][5]; // 카드 지도 (20장의 카드) 
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
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	
	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal() {
	int i,j;
	int pos,x,y;
	
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	
	for(i=0;i<10;i++) {
		for(j=0;j<2;j++) {
			pos = getEmptyPosition();
			x = conv_pos_x(pos);
			y = conv_pos_y(pos);
			
			arrayAnimal[x][y] = i;
		}
	}
}

// 좌표에서 빈 공간 찾기 
int getEmptyPosition() {
	int randPos;
	int x,y; 
	
	// ㅁㅁㅁㅁㅁ   0  1  2  3  4  -> 0 0 0 0 0
	// ㅁㅁㅁㅁㅁ   5  6  7  8  9  -> 1 1 1 1 1
	// ㅁㅁㅁㅁㅁ  10 11 12 13 14  -> 2 2 2 2 2
	// ㅁㅁㅁㅁㅁ  15 16 17 18 19  -> 3 3 3 3 3
	
	while(1) {
		randPos = rand()%20; // 0 ~ 19 사이의 숫자 반환 
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
	// 19 -> 19 / 5 ? 몫은 3, 나머지 4 
	return y % 5; // y 를 5 로 나눈 나머지 값 
}
