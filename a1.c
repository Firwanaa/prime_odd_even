/*
@Instructor: Prof. Alaa Mohammed Salih
@Autor: Alqassam Firwana
@id: 000000000
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Checks if one number is prime or not
char *isPrime(int num)
{
    for (int i = 2; i < num; i++) // loop over each number
    {
        if (num % i == 0 && i != num) // check reminder and not the num itself
            return "No";
    }
    return "yes";
}

//Checks if one number is Odd or Even
char *isOdd(int num)
{
    if (num % 2 == 0) // check if even
    {
        return "Even";
    }
    else
        return "Odd";
}

//Find min number
int min(int array[], int size)
{
    int minNum = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < minNum) //compare numbers
            minNum = array[i]; // store the minimum
    }

    return minNum;
}

//Find max number
int max(int array[], int size)
{
    int maxNum = array[0]; //start from first number
    for (int i = 0; i < size; i++)
    {
        if (array[i] > maxNum) //compare numbers
            maxNum = array[i]; //store maximum
    }
    return maxNum;
}

//Calculate sum
int sum(int array[], int size)
{
    int sumNum = 0;
    for (int i = 0; i < size; i++)
    {
        sumNum += array[i]; //add up all numbers
    }
    return sumNum;
}

//Calculate average
float avg(int array[], int size)
{
    float average = 0.0;
    return average = (float)sum(array, size) / (float)size; //calculate avg.int casted to float
}
//Print all results
void printResults(int array[], int size)
{

    int maxNum = max(array, size); //find and store max
    int minNum = min(array, size); //find and store min
    printf("\033[0;36m");          //color - Cyan
    printf("===================================================== \n");
    printf("\033[0m");                                 //reset color
    printf("No\tNumber\tPrime\tOdd/Even\tMin/Max \n"); //table headings
    printf("\033[0;36m");                              //color - Cyan
    printf("===================================================== \n");
    printf("\033[0m"); //reset color

    for (int i = 0; i < size; i++)
    {
        char minMax[10] = ""; //start with empty string
        if (array[i] == maxNum)
            strcpy(minMax, "max"); //change string to max
        if (array[i] == minNum)
            strcpy(minMax, "min");                                                                     //change string to min
        printf("\033[0;35m");                                                                          //color - purple/pinkish
        printf("%d\t%d\t%s\t%s\t\t%s\n", i + 1, array[i], isPrime(array[i]), isOdd(array[i]), minMax); //print rows
    }
    printf("\033[0m");
}

//78 29 11 74 27 96 47 43 64 50 //given test values
int main()
{

    int arrSize = 10; //size of 10

    int array[arrSize]; //declare array of size 10
    array[0] = '\0';

    //populate arrary by user input
    //reset color
start:
    printf("\033[0;32m");                      //color - Green
    printf("Please Enter your Array of 10 numbers: "); //ask user for array
    printf("\033[0m");

    for (int i = 0; i < arrSize; i++)
    {

        int x;
        char char_var;
        x = scanf("%d", &array[i]); //to check if scanf returns int or not
        //store user input to array
        if (x != 1)
        {
            printf("\033[1;31m");
            printf("\nPlease Enter numbers only!, Press Enter to continue...\n");
            printf("\033[0m");
            //to erase all chrachters after scanf, referance included in the PDF: 1
            while ((char_var = getchar()) != '\n' && char_var != EOF)
                ;
            scanf("%c", &char_var);
            i = arrSize;
            goto start;
        }
    }

    int total = sum(array, arrSize);     //store sum to variable
    float average = avg(array, arrSize); //store average to variable

    printResults(array, arrSize); //Print results
    printf("\033[1;33m");            //color yellow
    printf("\nsum\t %d\n", total);   //print sum
    printf("Avg\t %.1f\n", average); //print average

    return 0;
}
