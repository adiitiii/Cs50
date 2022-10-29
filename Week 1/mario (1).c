#include <cs50.h>
#include <stdio.h>

int main ()
{
    int height;
    do{
         height = get_int("Height (between 1 to 8): ");
      }
    while (height < 1 || height > 8);

{for (int i = 1; i <= height ; i++)
{
    for (int k = 1; k <= height-i; k++)
    {
        printf(" ");
    }
        {
            for (int j = 0; j < i; j++)
                {
                    printf("#");
                }
    printf("\n");
    }
}
}

}

