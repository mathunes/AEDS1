#include <stdio.h>
#include <math.h>

char toGrade(int mark);

int main() {
  int mark;
  
  do {

    printf("\nNota: ");
	  fflush(stdin);
    scanf("%d", &mark);

    if (mark >= 0) 
      printf("Conceito: %c\n", toGrade(mark));
    else 
      printf("Insira uma nota a partir de 0\n");

  } while (mark < 0);

  return 0; 
}

char toGrade (int mark) {
  switch (mark) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return 'F';
      break;
    case 5:
      return 'E';
      break;
    case 6:
      return 'D';
      break;
    case 7:
      return 'C';
      break;
    case 8:
      return 'B';
      break;
    case 9:
    default:
      return 'A';
      break;
  }
}
