void clearAndPrintMenu(void (*menu)()) {
  #if SO == 1
    system("cls");
  #else
    system("clear");
  #endif
}