#define SO 1

void clearAndPrintMenu(void (*menu)()) {
  #if SO == 1
    system("cls");
    (*menu)();
  #else
    system("clear");
    (*menu)();
  #endif
}