#include "control.h"

/*ver.1.0.5
말풍선, 스코어적용, 스코어별 등급적용, 임시 클리어화면 생성, 일부컴퓨터에서 그림겹쳐보이는 오류 수정
*아직 남은것 : 스테이지당 맵 수정 및 뭐 게임오버화면이나 이런것도 이미지로 만들면 좋고...
시간 함수 적용안할거면 지워야되고 그럼 Display::ShowScore 스코어 나오는 위치도 좀 아래로 내리면 되겠지??
게임 모두 클리어 시 종료화면도 만들어야댐!!!
*/
void main(){
	_setcursortype(_NOCURSOR);
	Character c;
	Display d(&c);
	Control t(&c,&d);
	t.Start_Main();
}