#include "sound.h"
#include "Consola.h"
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>

#pragma comment(lib, "winmm.lib")
 
#define SOUND_FILE_MAIN ".\\main.wav"
#define SOUND_FILE_1STAGE ".\\1stage.wav"
#define SOUND_FILE_2STAGE ".\\2stage.wav"
#define SOUND_FILE_3STAGE ".\\3stage.wav"
#define SOUND_FILE_CLEAR ".\\clear.wav"

void Sound::main(){
	PlaySound(TEXT(SOUND_FILE_MAIN), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Sound::stage(int stage){
	if(stage ==0)
		PlaySound(TEXT(SOUND_FILE_1STAGE), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(stage==1)
		PlaySound(TEXT(SOUND_FILE_2STAGE), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(stage ==2)
		PlaySound(TEXT(SOUND_FILE_3STAGE), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void Sound::clear(){
	PlaySound(TEXT(SOUND_FILE_CLEAR), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
/*int main(int argc, char* argv[]){
    printf("아무 키나 입력하시면 소리 재생이 멈춥니다.\n");
    PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    while (!_kbhit());
    PlaySound(NULL, 0, 0);
    return 0;
}
*/