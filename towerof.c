#include <stdio.h>

void toh(int num, char fpeg, char tpeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", fpeg, tpeg);
        return;
    }
    toh(num - 1, fpeg, auxpeg, tpeg);
    printf("\n Move disk %d from peg %c to peg %c", num, fpeg, tpeg);
    toh(num - 1, auxpeg, tpeg, fpeg);
}
int main()

{
    int num;

    printf("Number of disks : ");
    scanf("%d", &num);
    printf("sequence of moves are :\n");
    toh(num, 'A', 'C', 'B');
    return 0;
}
