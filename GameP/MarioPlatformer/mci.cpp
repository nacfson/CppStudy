//#include <Windows.h>
//#include <mmsystem.h>
//#include <Digitalv.h>
//#pragma comment(lib, "winmm.lib")
////PlaySound();
//MCI_OPEN_PARMS openBgm; //파일 열기 위한 구조체
//MCI_PLAY_PARMS playBgm; //파일 재생 위한 구조체
//UINT dwID,dwID2;
//void PlayingBgm() {
//	openBgm.lpstrElementName = TEXT("Sound\\Bgm.wav");
//	openBgm.lpstrDeviceType = L"waveaudio";
//	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,(DWORD_PTR)&openBgm);
//	dwID = openBgm.wDeviceID;
//	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);
//}
//MCI_OPEN_PARMS openEffect; //파일 열기 위한 구조체
//MCI_PLAY_PARMS playEffect;
//void PlayingEffect() {
//	openEffect.lpstrElementName = TEXT("Sound\\Effect.wav");
//	openEffect.lpstrDeviceType = L"waveaudio";
//	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
//	dwID2 = openEffect.wDeviceID;
//
//
//	mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
//	Sleep(100);
//	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START,(DWORD_PTR)&playEffect);
//}
//int main(void) {
//	
//	//PlayingBgm();
//	while (1) {
//		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
//			PlayingEffect();
//		}
//	}
//	return 0;
//}