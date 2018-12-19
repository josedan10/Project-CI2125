// SO {1: Windows, 2: Linux}
#define SO 1

void clearScreen () {
  #if SO == 1
    system("cls");

  #else
    system("clear");

  #endif
}

unsigned short clearAndPrintMenu(unsigned short (*menu)()) {
  clearScreen();
  return (*menu)();
}