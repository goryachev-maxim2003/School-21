#include <math.h>
#include <stdio.h>

void encode();
void decode();
int asci_to_int(char a, char b);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("n/a");
    return 0;
  }
  if (argv[1][0] == '0' && argv[1][1] == '\0') {
    encode();
  } else if (argv[1][0] == '1' && argv[1][1] == '\0') {
    decode();
  } else {
    printf("n/a");
  }

  return 0;
}

void encode() {
  while (1) {
    char c1, c2;
    scanf("%c%c", &c1, &c2);
    //Пробел не на своем месте
    if (c1==' ' || c1=='\n'){
      printf("n/a");
      break;
    }
    if (c2 == ' ') {
      printf("%X ", c1);
    } else if (c2 == '\n') {
      printf("%X", c1);
      break;
    } else {
      printf("n/a");
      break;
    }
  }
}

void decode() {
  while (1) {
    char c1, c2, c3;
    int err = 0;
    scanf("%c%c%c", &c1, &c2, &c3);
    if (c3 == ' ') {
      printf("%c ", asci_to_int(c1, c2));
    } else if (c3 == '\n') {
      printf("%c", asci_to_int(c1, c2));
      break;
    } else {
      printf("n/a");
      break;
    }
  }
}

int asci_to_int(char a, char b) {
  int num1, num2;
  num1 = 0;
  num2 = -1;
  //Первый символ
  if (a >= '0' && a <= '9') {
    num1 = (a - 48) * 16;
  } else if (a >= 'A' && a <= 'F') {
    num1 = (a - 55) * 16;
  }
  //Второй символ
  if (b >= '0' && b <= '9') {
    num2 = b - 48;
  } else if (b >= 'A' && b <= 'F') {
    num2 = b - 55;
  }
  return num1 + num2;
}
