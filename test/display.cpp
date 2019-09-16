#include "display.h"
#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>
#include <iostream>
#include <direct.h>
#include <mmsystem.h>
#include <conio.h>
 
#pragma comment(lib, "winmm.lib")
using namespace Gdiplus;

#define SOUND_FILE_MAIN ".\\main.wav"
#define SOUND_FILE_1STAGE ".\\1stage.wav"
#define SOUND_FILE_2STAGE ".\\2stage.wav"
#define SOUND_FILE_3STAGE ".\\3stage.wav"
#define SOUND_FILE_ENDING ".\\ending.wav"

Display::Display(Character *c)
{
	myC = c;
}
void Display::xyprint(int x,int y, char *ch)
{
	gotoxy(x,y);
	cout<<ch;
}

void Display::ShowC(int x,int y)
{
	textcolor(LIGHTRED);
	xyprint(x+6,y+3,myC->GetCharacter());
}
//+26+7
void Display:: Draw(int state)
{

	char keyInput[10] = "";
	Image *pImage = NULL;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken = NULL;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
 
	Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));

	if(state ==0){
		pImage = pGraphics ? new Image(L"C:\\1stage.bmp") : NULL;   
	}
	else if(state == 1){
		pImage = pGraphics ? new Image(L"C:\\2stage.bmp") : NULL; 
	}
	else if(state == 2){
		pImage = pGraphics ? new Image(L"C:\\3stage.bmp") : NULL;
	}
	else if(state == 3){
		pImage = pGraphics ? new Image(L"C:\\rush.bmp") : NULL;
	}
	else if(state == 4){
		pImage = pGraphics ? new Image(L"C:\\select.bmp") : NULL;
	}
	else if(state == 5){
		pImage = pGraphics ? new Image(L"C:\\help.bmp") : NULL;
	}
	else if(state == 6){
		pImage = pGraphics ? new Image(L"C:\\clear.bmp") : NULL;
	}
	else if(state == 7){
		pImage = pGraphics ? new Image(L"C:\\ca.bmp") : NULL;
	}
	else if(state == 8){
		pImage = pGraphics ? new Image(L"C:\\cab.bmp") : NULL;
	}
	else if(state == 9){
		pImage = pGraphics ? new Image(L"C:\\car.bmp") : NULL;
	}
	else if(state == 10){
		pImage = pGraphics ? new Image(L"C:\\cal.bmp") : NULL;
	}
	else if(state == 11){ //검은화면 리셋
		pImage = pGraphics ? new Image(L"C:\\reset.bmp") : NULL;
	}
	else if(state == 12){
		pImage = pGraphics ? new Image(L"C:\\riding.bmp") : NULL;
	}
	if (pImage)
	{
		if(state ==3)
			pGraphics->DrawImage(pImage, 60, 90);
		else if (state ==4)
			pGraphics->DrawImage(pImage, 280,250 );
		else if (state ==5)
			pGraphics->DrawImage(pImage, 0,0 );
		else if (state >=0&&state<=2)
			pGraphics->DrawImage(pImage, 0,0 );
		else if(state ==7)
			pGraphics->DrawImage(pImage, 400,0);
		else if(state ==8)
			pGraphics->DrawImage(pImage, 400,0);
		else if(state ==9)
			pGraphics->DrawImage(pImage, 400,0);
		else if(state ==10)
			pGraphics->DrawImage(pImage, 400,0);
		else if (state ==6)
			pGraphics->DrawImage(pImage, 150,90);
		else if (state ==11)
			pGraphics->DrawImage(pImage, 0,0 );
		else if(state==12)
			pGraphics->DrawImage(pImage, 400,0);
	}
	else
	{
		printf("Error\n");
	}
 
	delete pImage;
	delete pGraphics;
	GdiplusShutdown(gdiplusToken);

}


void Display::ReturnC(int x,int y)
{
	textcolor(LIGHTRED);
	xyprint(x+6,y+3,myC->GetCharacter());
}
void Display:: GetMap(int stage){
	_mymap.LoadM(stage);
}

void Display::ShowMap(int stage)
{
	int i,j;
	for(i=0;i<8;i++){
		gotoxy(6,3+i);
		for(j=0;j<12;j++){
			if(_mymap.MapShap[stage][i][j]==WALL)
			{
				textcolor(WHITE);
				printf("■");
	
			}
			else if(_mymap.MapShap[stage][i][j]==BLANK)
			{ 
				textcolor(WHITE);
				printf("□");
	
			}
			else if(_mymap.MapShap[stage][i][j]==GREEN_CAR)
			{
				textcolor(GREEN);
				printf("■");
		
			}
			else if(_mymap.MapShap[stage][i][j]==EXIT){
				textcolor(LIGHTRED);
				printf("♥");
			}
			else if(_mymap.MapShap[stage][i][j]==MY_CAR){
				textcolor(LIGHTRED);
				printf("■");
			}
			else if(_mymap.MapShap[stage][i][j]==BLUE_CAR){
				textcolor(BLUE);
				printf("■");
			}
			else if(_mymap.MapShap[stage][i][j]==SKY_CAR){
				textcolor(CYAN);
				printf("■");
			}
			else if(_mymap.MapShap[stage][i][j] == BROWN_CAR){
				textcolor(BROWN);
			printf("■");
			}
			else if(_mymap.MapShap[stage][i][j] == LIGHTBLUE_CAR){
				textcolor(LIGHTBLUE);
				printf("■");}
			else if(_mymap.MapShap[stage][i][j] == MAGENTA_CAR){
				textcolor(MAGENTA);
				printf("■");}
		}
		puts("");
		}

}

void Display :: ShowScore(int *score){
	textcolor(WHITE);
	
	gotoxy(36,4);printf("-Score-");
	
	textcolor(LIGHTMAGENTA);
	gotoxy(37,5);
	printf("%4d",*score);

}

void Display :: ShowStage(int stage){
	textcolor(WHITE);
	
	gotoxy(14,1);printf("-Stage-");
	
	textcolor(LIGHTGREEN);
	gotoxy(17,2);
	printf("%d",stage+1);
}

/*void Display :: ShowTime(int *time){
	textcolor(WHITE);
	
	gotoxy(34,8);printf("Limited Time");
	
	textcolor(LIGHTRED);
	gotoxy(38,9);
	printf("%d",*time);
}*/

void Display:: ShowReset(){

	textcolor(WHITE);
	gotoxy(6,11);printf("RESET = R");

}

void Display:: ShowExit(){
	textcolor(WHITE);
	gotoxy(22,11);printf("EXIT = Q");
}
void Display:: Interface(int *score,int stage,int *time){
	ShowStage(stage);
	ShowScore(score);
	//ShowTime(time);
	ShowReset();
	ShowExit();
}

void Display:: Startmain(){
	textbackground(BLACK);
	clrscr();
	main_sound();
	Draw(3);
	Draw(4);
}
void Display:: help(){
	Draw(5);
}

void Display:: reset(){ //검은화면으로 초기화
	Draw(11);
}

void Display::ShowCar(int x,int y)
{
	textcolor(YELLOW);
	xyprint(x*2+6,y+3,"■");
}


void Display::main_sound(){
	PlaySound(TEXT(SOUND_FILE_MAIN), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Display::stage_sound(int stage){
	if(stage ==0)
		PlaySound(TEXT(SOUND_FILE_1STAGE), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(stage==1)
		PlaySound(TEXT(SOUND_FILE_2STAGE), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(stage ==2)
		PlaySound(TEXT(SOUND_FILE_3STAGE), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void Display::clear_sound(){
	PlaySound(TEXT(SOUND_FILE_ENDING), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Display::stop_sound(){
	PlaySound(NULL, 0, 0);
}
/*int main(int argc, char* argv[]){
    printf("아무 키나 입력하시면 소리 재생이 멈춥니다.\n");
    PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    while (!_kbhit());
    PlaySound(NULL, 0, 0);
    return 0;
}
*/

void Display::PrintSquare(){
	textcolor(WHITE);
	gotoxy(10,14);printf("┏━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(10,15);printf("┃                                      ┃");
	gotoxy(10,16);printf("┃                                      ┃");
    gotoxy(10,17);printf("┃                                      ┃");
	gotoxy(10,18);printf("┗━━━━━━━━━━━━━━━━━━━┛");
}

void Display::PrintMessage(){
	srand((unsigned int)time(NULL));
	textcolor(WHITE);
	gotoxy(12,16);cout<<"                                     "; //글씨 초기화
	gotoxy(12,16);
	switch(rand()%13){
	case 0:
	cout<<"            궁시렁 궁시렁";
	break;
	case 1:
	cout<<"              덥다 더워~";
	break;
	case 2:
	cout<<"           빨간 마티즈라...";
	break;
	case 3:
	cout<<"   누가 주차를 이따구로 해놓은거야?";
	break;
	case 4:
	cout<<"         여긴 어디? 난 누구?";
	break;
	case 5:
	cout<<"           아 백수되고싶다.";
	break;
	case 6:
	cout<<"         공부 좀 열심히 할걸...";
	break;
	case 7:
	cout<<"         긁어먹으면 큰일난다...";
	break;
	case 8:
	cout<<"        조퇴하기 딱 좋은 날이군.";
	break;
	case 9:
	cout<<"               배고파...";
	break;
	case 10:
	cout<<"          집가서 치맥하고 싶다.";
	break;
	case 11:
	cout<<"        빌게이츠 아들로 태어날걸.";
	break;
	case 12:
	cout<<"        아아 보채지 좀 마세요ㅡㅡ";
	break;
	case 13:
	cout<<"       다른 주차장도 이용해주세요~";
	break;
	default:
	cout<<"             랜덤함수 오류";
	break;
	}
}

void Display::GameOver(){ //임시 게임오버 화면
	clrscr();
	gotoxy(36,10);
    textcolor(LIGHTRED);
	cout<<"GameOver";
	delay(1000);
	gotoxy(22,12);
	cout<<"당신은 차를 빼내지못하여 해고당했습니다.";
	delay(1000);
	gotoxy(28,14);
	cout<<"Restart하려면 Z를 눌러주세요.";
}

void Display::ClearStage(int score, int stage){ //임시 스테이지 클리어 화면
	clrscr();
	gotoxy(30,10);
    textcolor(WHITE);
	cout<<"클리어 스코어 : ";
	delay(500);
	cout<<score<<" X "<<stage+1;
	delay(1000);
	gotoxy(30,12);
	cout<<"차를 움직인 횟수 : ";
	delay(500);
	cout<<((1000-score)/50); //차움직일때마다 50씩 감점된다는 가정하에
	delay(1000);
	gotoxy(30,14);
	cout<<"클리어 등급 : ";
	delay(1000);
	switch(stage){
		case 0: //1스테이지
		if(score >= 700) //임시 등급표
			cout<<"A";
		else if(score < 700 && score >=600)
			cout<<"B";
		else
			cout<<"C";
		break;
	case 1: 
		if(score >= 750) //임시 등급표
			cout<<"A";
		else if(score < 750 && score >=650)
			cout<<"B";
		else
			cout<<"C";
		break;
	case 2:
		if(score >= 400) //임시 등급표
			cout<<"A";
		else if(score < 400 && score >=300)
			cout<<"B";
		else
			cout<<"C";
		break;
	}
	delay(1000);
	gotoxy(27,18);
	cout<<"계속 진행하려면 Z를 눌러주세요.";
}

void Display::Ending(int score){
	clear_sound();
	clrscr();
	gotoxy(22,10);
    textcolor(WHITE);
	cout<<"당신은";
	delay(500);
	cout<<" 절대로";
	delay(500);
	cout<<" 포기하지";
	delay(500);
	cout<<" 않았음을";
	delay(500);
	cout<<" 알기에... ";
	delay(1500);
	gotoxy(35,12);
	textcolor(LIGHTRED);
	cout<<"의지";
	textcolor(WHITE);
	cout<<"가 차오른다";
	delay(1500);
	clrscr();
	gotoxy(30,12);
	textcolor(WHITE);
	cout<<"최종 클리어 스코어 : ";
	delay(500);
	textcolor(YELLOW);
	cout<<score;
	delay(1000);
	gotoxy(30,14);
	textcolor(WHITE);
	cout<<"클리어 등급 : ";
	delay(1000);
	textcolor(YELLOW);
	if(score>=3700)
		cout<<"S";
	else if(score < 3700 && score >=3200)
		cout<<"A";
	else if(score < 3200 && score >=2800)
		cout<<"B";
	else if(score < 2800)
		cout<<"C";
	gotoxy(33,16);
	delay(1000);
	textcolor(WHITE);
	cout<<"수고하셨습니다.";
	delay(1000);
	clrscr();
	for(int j=0; j<=15 ;j++){
		gotoxy(26,10);
		textcolor(j);
		cout<<"Made in Team of LIFE IS MY WAY";
		delay(400);
		gotoxy(26,10);
	}
	clrscr();
	for(int i=25;i+24>=1;i--){
	if(i>=1){
		textcolor(LIGHTMAGENTA);
		gotoxy(30,i);
		cout<<"Team of LIFE IS MY WAY";
	}
	if(i+3>=1&&(i+4<=25)){
		textcolor(WHITE);
		gotoxy(38,i+3);
		cout<<"정 승 현";
	}
	if(i+5>=1&&(i+5<=25)){
		textcolor(WHITE);
		gotoxy(38,i+5);
		cout<<"권 용 환";
	}
	if(i+7>=1&&(i+7<=25)){
		textcolor(YELLOW);
		gotoxy(39,i+7);
		cout<<"- BGM -";
	}
	if(i+9>=1&&(i+9<=25)){
		textcolor(WHITE);
		gotoxy(37,i+9);
		cout<<"브금 저장소";
	}
	if(i+11>=1&&(i+11<=25)){
		textcolor(YELLOW);
		gotoxy(38,i+11);
		cout<<"- IMAGE -";
	}
	if(i+13>=1&&(i+13<=25)){
		textcolor(WHITE);
		gotoxy(39,i+13);
		cout<<"Google";
	}
	if(i+15>=1&&(i+15<=25)){
		textcolor(WHITE);
		gotoxy(38,i+15);
		cout<<"정 승 현";
	}
	if(i+24>=1&&(i+24<=25)){
		textcolor(LIGHTRED);
		gotoxy(38,i+24);
		cout<<"- END -";
	}
	delay(400);
	clrscr();
	}
	
}