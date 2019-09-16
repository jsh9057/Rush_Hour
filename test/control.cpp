#include "Control.h"

#define CHACTER_MEET_LEFT _D->_mymap.MapShap[_Stage][_C->GetCY()][_C->GetCX()-1]
#define CHACTER_MEET_RIGHT _D->_mymap.MapShap[_Stage][_C->GetCY()][_C->GetCX()+1]
#define CHACTER_MEET_UP _D->_mymap.MapShap[_Stage][_C->GetCY()-1][_C->GetCX()]
#define CHACTER_MEET_DOWN _D->_mymap.MapShap[_Stage][_C->GetCY()+1][_C->GetCX()]

#define CAR_MEET_DOWN _D->_mymap.MapShap[_Stage][_mycar.c_Y+1][_mycar.c_X]
#define CAR_MEET_UP _D->_mymap.MapShap[_Stage][_mycar.c_Y-_mycar.c_length][_mycar.c_X]
#define CAR_MEET_LEFT _D->_mymap.MapShap[_Stage][_mycar.c_Y][_mycar.c_X-_mycar.c_length]
#define CAR_MEET_RIGHT _D->_mymap.MapShap[_Stage][_mycar.c_Y][_mycar.c_X+1]

#define TIME 180 //임시


int getkey()
{
	int key=_getch();
	return (key==0xe0) ? (0xe000 | _getch()): key;
}
Control::Control(Character *C, Display *D){
	_C=C;
	_D=D;
	M_X=0;
	M_Y=0;
	M_C=10;
	_Stage=0;
	_Score = 1000;
	_FScore = 0;
}
void Control::SetMC(int x){
	M_C = x-1;
}
void Control::ClearMXY(){
	M_X = 0;
	M_Y = 0;
	M_C = 10;
}
void Control::AddMXY(int x, int y){
	M_X += x;
	M_Y += y;
}
void Control::SetCarXY(){
	if(M_C==10)
		;
	else{
		_mycar[M_C].c_X += M_X;
		_mycar[M_C].c_Y += M_Y;
	}
	ClearMXY();
}
void Control:: SetMCXY()                 //실제 xy값이랑 출력상의xy값이 다르기때문
{
	int x=0,y=0;

	while(_D->_mymap.MapShap[_Stage][y][x]!=EXIT){
		x++;
		if(x>=12){
			y++;x=0;}
	}
	_C->SetCXY(x,y);
	MCX=x*2;
	MCY=y;

}
void Control:: MoveMCXY(int x, int y)  //실제 x*2씩 증가해야 출력상에 문제가없음
{
	MCX=MCX+x*2;
	MCY=MCY+y;
}
void Control:: delectC(int x, int y){
	textcolor(WHITE);
	_D->xyprint(x+6,y+3,"□");
}
void Control:: delectCar(int x, int y){ //가로
	textcolor(WHITE);
	_D->xyprint(x*2+6,y+3,"□");
}
void Control:: Map(){
	_D->GetMap(_Stage);
	CreateCar();
	_D->ShowMap(_Stage);
}

void Control:: Interface(int *time){

	_D->Interface(&_Score, _Stage, time);
	_D->PrintSquare();
	Map();
}

void Control:: Start_Main(){
	clrscr();
	int key;
	int x=32,y=16;
	int select=3;
	_D->Startmain();
	textcolor(LIGHTRED);
	gotoxy(x,y);
	_D->xyprint(x,y=y+2,_C->GetCharacter());
	while(1){
		key=getkey();

	if(key==DOWN&&select>1)
	{
		select--;
		_D->xyprint(x,y," ");
		y=y+3;
		_D->xyprint(x,y,_C->GetCharacter());

	}
	else if(key==UP&&select<3)
	{
		select++;
		_D->xyprint(x,y," ");
		y=y-3;
		_D->xyprint(x,y,_C->GetCharacter());
	}
	else if(key=='z')
	{
		key=0;
			if(select==3)
				StartGame();
			else if(select==2)
			{
				clrscr();
				gotoxy(40,13);
				textcolor(LIGHTMAGENTA);
				printf("HELP\n");
				delay(1000);
				clrscr();
				_D->help();
				while(key!='z'){
				key=_getch();
				}
					key=0;
					_D->reset();
					Start_Main();
				
			}
			else if(select==1)
				gotoxy(1,1);
			textcolor(WHITE);
				exit(0);
		}
}
}


void Control::MoveFunc(){
	int key;
	SetCarXY();
	//seemap();
	_D->Draw(7);
	_D->PrintMessage();
	GameOver();
	while(1){
		key=getkey();
		if(key==LEFT) 
		{
			_D->Draw(10);
			_C->SetState(3);
			if(CHACTER_MEET_LEFT == BLANK)
			{
				_C->MoveC(-1,0);
				delectC(MCX,MCY);
				MoveMCXY(-1,0);
				_D->ShowC(MCX,MCY);
			}
		}
		else if(key==RIGHT) 
		{             
			_C->SetState(1);
			_D->Draw(9);
			if(CHACTER_MEET_RIGHT == BLANK)
			{
			textcolor(WHITE);
				_C->MoveC(+1,0);
				delectC(MCX,MCY);
				MoveMCXY(+1,0);
				_D->ShowC(MCX,MCY);
			}
		
		}
		else if(key==DOWN)
		{
			_C->SetState(2);
			_D->Draw(7);
			if(CHACTER_MEET_DOWN == BLANK)
			{
				_C->MoveC(0,1);
				delectC(MCX,MCY);
				MoveMCXY(0,+1);
				_D->ShowC(MCX,MCY);
			}
		}
		else if(key==UP)
		{
			_D->Draw(8);
			_C->SetState(0);
			if(CHACTER_MEET_UP == BLANK)
			{
				_C->MoveC(0,-1);
			    delectC(MCX,MCY);
				MoveMCXY(0,-1);
				_D->ShowC(MCX,MCY);
			}
		}
		else if(key == 'z'){
			if(BoardCar() == BLANK || BoardCar() == WALL);
			else{
				SetMC(BoardCar());
				MoveCar(_mycar[BoardCar()-1]);}
		}
		else if(key=='r')
		{
			StartStage();
		}
		else if(key=='q')
		{
			gotoxy(10,20);
			textcolor(WHITE);
			exit(0);
		}
}
}

void Control::CreateCar(){ //스테이지 차의 숫자를 정해줌

	switch(_Stage){
		case 0:  //1스테이지 차량 생성
			{
			_mycar[0].SetOption(1,2,0);
			_mycar[1].SetOption(2,3,0);
			_mycar[2].SetOption(3,3,1);
			_mycar[3].SetOption(4,3,1);
			_mycar[4].SetOption(5,3,0);
			_mycar[5].SetOption(6,3,1);
			_mycar[6].SetOption(7,3,1);
			for(int i=0; i<7; i++)
			  FindCar(&_mycar[i]);
			break;
			}
		case 1: 
			{
			_mycar[0].SetOption(1,2,0);
			_mycar[1].SetOption(2,3,1);
			_mycar[2].SetOption(3,3,0);
			_mycar[3].SetOption(4,4,1);
			_mycar[4].SetOption(5,3,1);
			_mycar[5].SetOption(6,4,0);
			_mycar[6].SetOption(7,5,0);
			for(int i=0; i<7; i++)
			  FindCar(&_mycar[i]);
			break;
			}
		case 2:
			{
			_mycar[0].SetOption(1,2,0);
			_mycar[1].SetOption(2,4,0);
			_mycar[2].SetOption(3,3,1);
			_mycar[3].SetOption(4,4,1);
			_mycar[4].SetOption(5,4,0);
			_mycar[5].SetOption(6,4,1);
			_mycar[6].SetOption(7,3,0);
			for(int i=0; i<7; i++)
			  FindCar(&_mycar[i]);
			break;
			}
		
		default:
			break;

		}	
}

void Control::FindCar(Car *_mycar){ //맵의 차 숫자의 배열을 완성시켜줌
	for(int i=0;i<8;i++)
		for(int j=0;j<12;j++){
			if(_D->_mymap.MapShap[_Stage][i][j] == _mycar->c_number){
				_mycar->SetXY(j,i); //차의 xy좌표를 set함
				ChangeMap(*_mycar);
			}
		}
}
void Control::StartGame(){ //스테이지 시작
	PrintStart();
	StartStage();
}
void Control::PrintCar(Car *_mycar){ //차 색깔 변경!!!
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<12;j++){
			gotoxy(6+(j*2),3+i);
			if(_D->_mymap.MapShap[_Stage][i][j]==_mycar->c_number){
				CarColor(*_mycar);
				printf("■");
			}
		}
	}
}

int Control::BoardCar(){ //어떤차에 탑승할것인지 판별해줌(차 번호 반환)
	switch(_C->_State){
		case 0: //캐릭터가 위를 가리킬때
				return CHACTER_MEET_UP;
		case 1: //캐릭터가 오른쪽을 가리킬때
			return CHACTER_MEET_RIGHT;
		case 2: //캐릭터가 아래를 가리킬때
			return CHACTER_MEET_DOWN;
		case 3: //캐릭터가 왼쪽을 가리킬때
			return CHACTER_MEET_LEFT;
		default:
			return 9;
	}
}
void Control::PrintStart(){ //게임시작시 스테이지 출력화면
	_D->stop_sound();
	clrscr();
	_D->Draw(_Stage);
	delay(1000);
	_D->reset();
}
void Control::StartStage(){ //스테이지 시작 화면
	clrscr();
				int time=TIME;
				ResetScore();
				Interface(&time);
				SetMCXY();
				ClearMXY();
				_D->stage_sound(_Stage);
				MoveFunc();
}

void Control::MoveCar(Car _mycar){ //차의 움직임
	int key;
	_D->PrintMessage();
	_D->Draw(12);
	//seemap();
	_mycar.SetBoard();  //탑승상태변경
	delectC(MCX,MCY); //캐릭터이미지 삭제
	PrintCar(&_mycar); //해당 차색깔 변경
	while(1){
		key=getkey();
		if(_mycar.c_option == 0){ //가로일떄
		if(key==LEFT) 
		{
			if(CAR_MEET_LEFT == BLANK)
			{
				delectCar(_mycar.c_X,_mycar.c_Y);
				DelectMap(_mycar.c_X,_mycar.c_Y);
				_mycar.MoveXY(-1,0);
				AddMXY(-1,0);
				AddMap(_mycar);
				ChangeMap(_mycar);
				_D->ShowCar(_mycar.c_X-_mycar.c_length+1,_mycar.c_Y);
				//seemap();
			}
		}
		else if(key==RIGHT) 
		{                                     
			if(CAR_MEET_RIGHT == BLANK)
			{
				delectCar(_mycar.c_X-_mycar.c_length+1,_mycar.c_Y);
				DelectMap(_mycar.c_X-_mycar.c_length+1,_mycar.c_Y);
				_mycar.MoveXY(+1,0);
				AddMXY(+1,0);
				AddMap(_mycar);
				ChangeMap(_mycar);
				_D->ShowCar(_mycar.c_X,_mycar.c_Y);
				//seemap();
			}
				else if(CAR_MEET_RIGHT == EXIT){
				delectCar(_mycar.c_X-_mycar.c_length+1,_mycar.c_Y);
				DelectMap(_mycar.c_X-_mycar.c_length+1,_mycar.c_Y);
				_mycar.MoveXY(+1,0);
				AddMXY(+1,0);
				AddMap(_mycar);
				ChangeMap(_mycar);
				_D->ShowCar(_mycar.c_X,_mycar.c_Y);
				//임시 클리어 화면
				ClearStage();
				}
		}
		else if(key == 'z'){
			OutCar(&_mycar);
		}
		else if(key=='r')
		{
			StartStage();
		}
		else if(key=='q')
		{
			gotoxy(10,20);
			textcolor(WHITE);
			exit(0);
		}
		}
		else if(_mycar.c_option == 1){ //세로일떄
		if(key==DOWN)
		{
			if(CAR_MEET_DOWN == BLANK)
			{
				delectCar(_mycar.c_X,_mycar.c_Y-_mycar.c_length+1); //이미지상 잔상제거
				DelectMap(_mycar.c_X,_mycar.c_Y-_mycar.c_length+1); //해당배열 0으로 초기화
				_mycar.MoveXY(0,+1);//배열 무브
				AddMap(_mycar); //그 차의 기준점 다시 지정해줌
				AddMXY(0,+1); //컨트롤 함수 자체에 mycar에 add할 XY더해줌
				ChangeMap(_mycar); //바뀐배열상 차 다시 생성
				_D->ShowCar(_mycar.c_X,_mycar.c_Y); //블럭하나 이미지상 생성
				//seemap();
			}
		}
		else if(key==UP)
		{
			if(CAR_MEET_UP == BLANK)
			{
				delectCar(_mycar.c_X,_mycar.c_Y);
				DelectMap(_mycar.c_X,_mycar.c_Y);
				_mycar.MoveXY(0,-1);
				AddMap(_mycar);
				AddMXY(0,-1);
				ChangeMap(_mycar);
				_D->ShowCar(_mycar.c_X,_mycar.c_Y-_mycar.c_length+1);
				//seemap();
			}
		}
		else if(key == 'z'){
			OutCar(&_mycar);
		}
		else if(key=='r')
		{
			StartStage();
		}
		else if(key=='q')
		{
			gotoxy(10,12);
			textcolor(WHITE);
			exit(0);
		}
		}	
}
}
void Control::CarColor(Car _mycar){ //차 색깔 지정
	if(_mycar.c_board == 1)
		textcolor(YELLOW);
	else{
	if(_mycar.c_number == MY_CAR)
		textcolor(LIGHTRED);
	else if(_mycar.c_number == GREEN_CAR)
		textcolor(GREEN);
	else if(_mycar.c_number == BLUE_CAR)
		textcolor(BLUE);
	else if(_mycar.c_number == SKY_CAR)
		textcolor(CYAN);
	else if(_mycar.c_number == BROWN_CAR)
		textcolor(BROWN);
	else if(_mycar.c_number == LIGHTBLUE_CAR)
		textcolor(LIGHTBLUE);
	else if(_mycar.c_number == MAGENTA_CAR)
		textcolor(MAGENTA);
	else
		textcolor(WHITE);
	}
}
void Control::ChangeMap(Car _mycar){
	if(_mycar.c_option == 0)
		for(int z=0;z <_mycar.c_length; z++){
			_D->_mymap.MapShap[_Stage][_mycar.c_Y][_mycar.c_X-z] = _mycar.c_number;} //가로일때 왼쪽으로 올라가면서 생성
	else if(_mycar.c_option == 1)
		for(int z=0;z <_mycar.c_length; z++){
			_D->_mymap.MapShap[_Stage][_mycar.c_Y-z][_mycar.c_X] = _mycar.c_number;} //세로일때 위로 올라.가면서 생성
}
void Control::DelectMap(int x, int y){ //블럭 하나의 배열을 0으로 만듬
	_D->_mymap.MapShap[_Stage][y][x] = 0;
}
void Control::AddMap(Car _mycar){ //블럭의 기준점을 다시 입력해줌
	_D->_mymap.MapShap[_Stage][_mycar.c_Y][_mycar.c_X] = _mycar.c_number;
}

void Control::OutCar(Car *_mycar){
	int key;
	//seemap();
	_C->SetCXY(_mycar->c_X,_mycar->c_Y);
	PrintOut(*_mycar);
			if(_mycar->c_option == 0){ //가로
				key = getkey();
				DelectOutMark(*_mycar);
				if(key == UP){
					if(CHACTER_MEET_UP == BLANK){
					_C->SetCXY(_mycar->c_X,_mycar->c_Y-1);
					MCX = _C->_Cx*2;
					MCY = _C->_Cy;
					_D->ReturnC(MCX,MCY);
					_mycar->SetBoard();
					PrintCar(_mycar);
					MinusScore(); //점수 변경
				_D->ShowScore(&_Score);
					MoveFunc();}
				}
				else if(key == DOWN){
					if(CHACTER_MEET_DOWN == BLANK){
					_C->SetCXY(_mycar->c_X,_mycar->c_Y+1);
					MCX = _C->_Cx*2;
					MCY = _C->_Cy;
					_D->ReturnC(MCX,MCY);
					_mycar->SetBoard();
					PrintCar(_mycar);
					MinusScore();
				_D->ShowScore(&_Score);
					MoveFunc();}
				}
			}
				else if(_mycar->c_option == 1){
				key = getkey();
				DelectOutMark(*_mycar);
				if(key == LEFT){
					if(CHACTER_MEET_LEFT == BLANK){
					_C->SetCXY(_mycar->c_X-1,_mycar->c_Y);
					MCX = _C->_Cx*2;
					MCY = _C->_Cy;
					_D->ReturnC(MCX,MCY);
					_mycar->SetBoard();
					PrintCar(_mycar);
					MinusScore();
				_D->ShowScore(&_Score);
					MoveFunc();}
				}
				else if(key == RIGHT){
					if(CHACTER_MEET_RIGHT == BLANK){
					_C->SetCXY(_mycar->c_X+1,_mycar->c_Y);
					MCX = _C->_Cx*2;
					MCY = _C->_Cy;
					_D->ReturnC(MCX,MCY);
					_mycar->SetBoard();
					PrintCar(_mycar);
					MinusScore();
				_D->ShowScore(&_Score);
					MoveFunc();}
				}
				}
}
void Control::seemap(){
	gotoxy(6,17);
	cout << _mycar[0].c_X << _mycar[0].c_Y << _mycar[1].c_X <<_mycar[1].c_Y << _mycar[2].c_X <<_mycar[2].c_Y << _mycar[3].c_X <<_mycar[3].c_Y;
	int i,j;
	for(i=0;i<8;i++){
		gotoxy(6,18+i);
		for(j=0;j<12;j++)
			printf("%d",_D->_mymap.MapShap[_Stage][i][j]);
		}	
}
void Control::PrintOut(Car _mycar){
	if(_mycar.c_option == 0){
		if(CHACTER_MEET_UP == BLANK){
			textcolor(LIGHTRED);
			_D->xyprint(_C->_Cx*2+6,_C->_Cy+2,"▲");
		}
		if(CHACTER_MEET_DOWN == BLANK){
			textcolor(LIGHTRED);
			_D->xyprint(_C->_Cx*2+6,_C->_Cy+4,"▼");
		}
	}
	else if(_mycar.c_option == 1){
		if(CHACTER_MEET_LEFT == BLANK){
			textcolor(LIGHTRED);
			_D->xyprint(_C->_Cx*2+4,_C->_Cy+3,"◀");
		}
		if(CHACTER_MEET_RIGHT == BLANK){
			textcolor(LIGHTRED);
			_D->xyprint(_C->_Cx*2+8,_C->_Cy+3,"▶");
		}
	}
}
void Control::DelectOutMark(Car _mycar){
	if(_mycar.c_option == 0){
		if(CHACTER_MEET_UP == BLANK){
			textcolor(WHITE);
			_D->xyprint(_C->_Cx*2+6,_C->_Cy+2,"□");
		}
		if(CHACTER_MEET_DOWN == BLANK){
			textcolor(WHITE);
			_D->xyprint(_C->_Cx*2+6,_C->_Cy+4,"□");
		}
	}
	else if(_mycar.c_option == 1){
		if(CHACTER_MEET_LEFT == BLANK){
			textcolor(WHITE);
			_D->xyprint(_C->_Cx*2+4,_C->_Cy+3,"□");
		}
		if(CHACTER_MEET_RIGHT == BLANK){
			textcolor(WHITE);
			_D->xyprint(_C->_Cx*2+8,_C->_Cy+3,"□");
		}
	}
}
void Control::ResetScore(){
	_Score = 1000;//임시값
}
void Control::MinusScore(){
	_Score -= 50;//임시값
}

void Control::GameOver(){
	int key=0;
	if(_Score == 0){
		delay(1000);
		_D->GameOver();
		while(key != 'z'){
			key=_getch();
				}
		StartGame();
}
}

void Control::ClearStage(){ //스테이지 클리어 시
	int key=0;
	ClearMXY();
	delay(500);
	clrscr();
	_D->stop_sound();
	_D->Draw(6);
	delay(2000);
		_D->Draw(11); //검은화면으로 초기화 함수
		_D->ClearStage(_Score, _Stage);
		_Stage++;
		_FScore += _Score*(_Stage+1);
		while(key != 'z'){
			key=_getch();
				}
		if(_Stage<=2) //세개의 스테이지
			StartGame();
		else {//종료화면 조건(이거 만들어야대!!)
			_D->Ending(_FScore);
			_FScore=0;
			_Stage=0;
			Start_Main();
		}
}
/*
void detcharloc(){

	int horinum = 0;
	int vernum = 0;

	MCX = _C->(_Cx*2 + horinum*2);
	MCY = _C->_Cy;
	_D->ReturnC(MCX,MCY);
	_mycar->SetBoard();


}*/