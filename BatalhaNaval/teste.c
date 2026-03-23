#include <stdio.h>

int main() {
    int index;
    char *nomesAlunos[3][3] = {
        {"Aluno 1", "Pt: 30", "Mat: 90"},
        {"Aluno 2", "Pt: 60", "Mat: 70"},
        {"Aluno 3", "Pt: 95", "Mat: 85"}
    };

    printf("\nDigite o número do aluno que queira ver as notas:");
    scanf("\n%d", &index);

    printf("\nNotas de %s: \n  %s\n  %s\n", nomesAlunos[index][0], nomesAlunos[index][1], nomesAlunos[index][2]);
}