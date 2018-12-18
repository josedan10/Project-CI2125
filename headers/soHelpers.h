// SO {1: Windows, 2: Linux}
#define SO 1

unsigned short clearAndPrintMenu(unsigned short (*menu)()) {
  #if SO == 1
    system("cls");
    return (*menu)();
  #else
    system("clear");
    return (*menu)();
  #endif
}

void clearScreen () {
  #if SO == 1
    system("cls");

  #else
    system("clear");

  #endif
}