#include<stdio.h>
#include<time.h>

// 10原軒税 辞稽 陥献 疑弘 (唖 朝球 2舌梢)
// 紫遂切稽採斗 2鯵税 脊径葵聖 閤焼辞 -> 旭精 疑弘 達生檎 朝球 及増奄
// 乞窮 疑弘 瞬聖 達生檎 惟績 曽戟
// 恥 叔鳶 判呪 硝形爽奄 

int arrayAnimal[4][5]; // 朝球 走亀 (20舌税 朝球) 
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
	strAnimal[0] = "据周戚";
	strAnimal[1] = "馬原";
	strAnimal[2] = "悪焼走";
	strAnimal[3] = "壱丞戚";
	strAnimal[4] = "掬走";
	
	strAnimal[5] = "坪晦軒";
	strAnimal[6] = "奄鍵";
	strAnimal[7] = "開展";
	strAnimal[8] = "展繕";
	strAnimal[9] = "硲櫛戚";
}

void shuffleAnimal() {
	int i,j;
	int pos,x,y;
	
	// けけけけけ
	// けけけけけ
	// けけけけけ
	// けけけけけ
	
	for(i=0;i<10;i++) {
		for(j=0;j<2;j++) {
			pos = getEmptyPosition();
			x = conv_pos_x(pos);
			y = conv_pos_y(pos);
			
			arrayAnimal[x][y] = i;
		}
	}
}

// 疎妊拭辞 朔 因娃 達奄 
int getEmptyPosition() {
	int randPos;
	int x,y; 
	
	// けけけけけ   0  1  2  3  4  -> 0 0 0 0 0
	// けけけけけ   5  6  7  8  9  -> 1 1 1 1 1
	// けけけけけ  10 11 12 13 14  -> 2 2 2 2 2
	// けけけけけ  15 16 17 18 19  -> 3 3 3 3 3
	
	while(1) {
		randPos = rand()%20; // 0 ~ 19 紫戚税 収切 鋼発 
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
	// 19 -> 19 / 5 ? 交精 3, 蟹袴走 4 
	return y % 5; // y 研 5 稽 蟹勧 蟹袴走 葵 
}
