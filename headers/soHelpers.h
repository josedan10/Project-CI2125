#define SO 1

void clearAndPrintMenu(int (*menu)()) {
  #if SO == 1
    system("cls");
    (*menu)();
  #else
    system("clear");
    (*menu)();
  #endif
}