#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char nombres[5][30];
    char materias[3][15];
    float notas[5][3]; 
    float promedio_estudiante = 0, promedio_asignatura = 0;
    int opc1, cont = 0, len, cont1 = 0;
    float min, max;
    int aprobados = 0, reprobados = 0;

    do
    {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar estudiantes (max 5)\n");
        printf("2. Registrar materias (3)\n");
        printf("3. Registrar sus notas respectivas\n");
        printf("4. Promedio por estudiante\n");
        printf("5. Promedio general por asignatura\n");
        printf("6. Calificacion mas alta y mas baja por estudiante\n");
        printf("7. Numero de estudiantes aprobados y reprobados\n");
        printf("8. Salir\n");
        printf(">> ");
        scanf("%d", &opc1);
        getchar(); 

        switch (opc1)
        {
        case 1:
            if (cont < 5)
            {
                printf("Ingrese el nombre del estudiante: ");
                fgets(nombres[cont], 30, stdin);
                len = strlen(nombres[cont]);
                if (nombres[cont][len - 1] == '\n')
                    nombres[cont][len - 1] = '\0';
                cont++;
            }
            else
            {
                printf("La cantidad maxima de estudiantes es 5.\n");
            }
            break;

        case 2:
            for (int i = 0; i < 3; i++)
            {
                printf("Ingrese el nombre de la materia %d: ", i + 1);
                fgets(materias[i], 15, stdin);
                len = strlen(materias[i]);
                if (materias[i][len - 1] == '\n')
                    materias[i][len - 1] = '\0';
            }
            break;

        case 3:
            for (int i = 0; i < cont; i++)
            {
                printf("Ingrese las 3 notas del estudiante %d (%s):\n", i + 1, nombres[i]);
                for (int j = 0; j < 3; j++)
                {
                    printf("%s: ", materias[j]);
                    scanf("%f", &notas[i][j]);
                }
            }
            break;

        case 4:
            for (int i = 0; i < cont; i++)
            {
                promedio_estudiante = 0;
                for (int j = 0; j < 3; j++)
                {
                    promedio_estudiante += notas[i][j];
                }
                promedio_estudiante /= 3;
                printf("Promedio del estudiante %s: %.2f\n", nombres[i], promedio_estudiante);
            }
            break;

        case 5:
            for (int j = 0; j < 3; j++)
            {
                promedio_asignatura = 0;
                for (int i = 0; i < cont; i++)
                {
                    promedio_asignatura += notas[i][j];
                }
                promedio_asignatura /= cont;
                printf("Promedio de la asignatura %s: %.2f\n", materias[j], promedio_asignatura);
            }
            break;

        case 6:
            for (int i = 0; i < cont; i++)
            {
                min = max = notas[i][0];
                for (int j = 1; j < 3; j++)
                {
                    if (notas[i][j] < min)
                        min = notas[i][j];
                    if (notas[i][j] > max)
                        max = notas[i][j];
                }
                printf("Estudiante %s -> Nota mas baja: %.2f, Nota mas alta: %.2f\n", nombres[i], min, max);
            }
            break;

        case 7:
            aprobados = 0;
            reprobados = 0;
            for (int i = 0; i < cont; i++)
            {
                promedio_estudiante = 0;
                for (int j = 0; j < 3; j++)
                {
                    promedio_estudiante += notas[i][j];
                }
                promedio_estudiante /= 3;
                if (promedio_estudiante >= 7.0)
                    aprobados++;
                else
                    reprobados++;
            }
            printf("Estudiantes aprobados: %d\n", aprobados);
            printf("Estudiantes reprobados: %d\n", reprobados);
            break;

        case 8:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida.\n");
            break;
        }

    } while (opc1 != 8);

    return 0;
}
