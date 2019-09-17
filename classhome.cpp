#include "FileSystem.h"

void FileSystem::FileManu() {
 cout << "location: " << address << endl;
 cout << "1. File Write(new)" << endl;
 cout << "2. File Write(Amend)(open textfile)" << endl;
 cout << "3. File Read" << endl;
 cout << "r. Reset location" << endl;
 cout << "x. Exit" << endl;
 cout << "Press Key" << endl;
}

void FileSystem :: FileAccess(int k) {
 os.exceptions(os.failbit | os.badbit);
 is.exceptions(is.failbit | is.badbit);
 try {
  if (k == 1) {
   os.open(address);
   in();
  }
  else if (k == 2) {
   is.open(address);
   ou();
  }
  else {}
 }
 catch (ofstream::failure& k) {
  cout << k.what() << endl;
 }
}

void FileSystem :: in() {
 int ex = 0;
 string k;
 system("cls");
 while (ex == 0) {
  getline(cin, k);
  if (k == "x") {
   ex = 1;
  }
  else {
   os << k << endl;
  }
 }
 cout << "저장이 완료되었습니다." << endl;
 system("pause");
 system("cls");
 os << "eof" << endl;
 os.close();
 FileManu();
}

void FileSystem :: ou() {
 system("cls");
 try {
  string k;
  while (getline(is, k)) {
   if (k == "eof") {
    system("pause");
    system("cls");
    is.close();
    FileManu();
    break;
   }
   else
   cout << k << endl;
  }
 }
 catch (ifstream::failure& k) {
  if (is.eof()) {
   system("pause");
   system("cls");
   is.close();
  }
  else
   cout << k.what() << endl;
   is.close();
 }
}

int FileSystem::start() {
 char ch;
 char c;
 int ex = 0;
 int ex1 = 0;
 while (ex == 0) {
  if (kbhit()) {
   ch = getch();
   switch (ch) {
   case '1':
    ex1 = 0;
    cout << "Warning : 전에 남아있는 데이터가 모두 지워집니다." << endl;
    cout << "1. Access" << endl;
    cout << "2. Denial of Access" << endl;
    while (ex1 == 0) {
     if (kbhit()) {
      c = getch();
      switch (c) {
      case '1':
       system("cls");
       FileAccess(1);
       ex1 = 4;
       FileManu();
       break;

      case '2':
       system("cls");
       ex1 = 4;
       FileManu();
       break;
      default:;
      }
     }
    }
    break;
   case '2': system(address.c_str());
    break;
   case '3': FileAccess(2);
    break;
   case 'r':
   case 'R':
    
    system("cls");
    return 0;
    break;
   case 'X':
   case 'x':
    ex = 1;
    return 1;
   default:
    system("cls");
    cout << endl;
    cout << "press again" << endl;
    cout << endl;
   }
  }
 }
}
