#include "FileSystem.h"

int main() {
 int ex = 0;
 while (ex == 0) {
  string adress;
  cout << "ex) d:\\\\examplefolder\\\\examtext.txt" << endl;
  cout << "파일경로 입력: ";
  getline(cin, adress);
  system("cls");
  FileSystem js(adress);
  js.FileManu();
  ex = js.start();
 }
 cout << "프로그램을 종료합니다" << endl;
}