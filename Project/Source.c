#include <stdio.h>
#include <stdlib.h>

//Linear Search Function
int linSearch(int arr[], int size, int target, int* numComparisons) {
	int i;  //Declaring variable

			//For loop going through and comparing each element to target
	for (i = 0; i <= size; i++) {
		(*numComparisons)++; //Advancing to next index in array

		if (arr[i] == target) {
			return i; //Return target if found
		}
	}
	//if not found
	return -1;
}

int BinarySearch(int numbers[], int numbersSize, int key, int *comparisons) {
	//Declaring variables
	int mid = 0;
	int low = 0;
	int high = 0;

	high = numbersSize - 1;

	while (high >= low) {   //If high is >= then low advance index
		(*comparisons)++;
		mid = (high + low) / 2;  //mid val equals high+low /2
		if (numbers[mid] < key) { //If key is bigger than mid add 1
			low = mid + 1;
		}
		else if (numbers[mid] > key) {  //if key is less than mid subtract 1
			high = mid - 1;
		}
		else {
			return mid; //return value when found
		}

	}

	return -1; // not found
}

void sort(int arr[], int size) {
	//Declaring variables
	int i = 0;
	int j = 0;
	int k = 0;
	int indexSmallest = arr[0];
	int temp;

	//for loop going throught the whole thing
	for (i = 0; i < size; ++i) {

		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < size; ++j) {

			if (arr[j] < arr[indexSmallest]) {
				indexSmallest = j;		//update to smaller value if found
			}
		}

		// Swap numbers[i] and numbers[indexSmallest]
		temp = arr[i];
		arr[i] = arr[indexSmallest];
		arr[indexSmallest] = temp;
	}

	//Printing the sorted values
	for (k = 0; k < size; k++)
	{
		printf("The values are: %d\n", arr[k]);
	}
}

//Function to copy from arr1 to arr2
void arrayCopy(int fromArray[], int toArray[], int size) {
	int i = 0;


	for (i = 0; i < size; i++) {
		if (fromArray[i] != -999) {  //while the input is not -999
			toArray[i] = fromArray[i]; //copying elements
		}
	}
}

int *growArray(int *arr, int *size) {

	int *temp;		//Temp pointer
	temp = (int *)malloc(*size * 2 * sizeof(int));   //allocating memory(doubling iu)
	int i;
	for (i = 0; i < *size; i++)   //Copying over the elements
		temp[i] = arr[i];
	free(arr); //freeing old array
	arr = temp;	//Setting pointer to new BIGGER array
	*size = *size * 2; //multipling size

	return arr;
}

int main() {
	printf("Jakub Glebocki, jglebo2@uic.edu\n\n");
	//initializing variables
	int val = 0;
	int i = 0;
	int count = 0;
	int *arr;
	int size = 10;
	arr = (int *)malloc(size * sizeof(int));
	int *secondArray;
	int key = 0;
	int returnValueBinary = 0;
	int returnValueLin = 0;
	int comparisons = 0;

	printf("Enter in a list of numbers followed by the terminal value of -999:\n");    //print statement

																					   /* loop until the user enters -999 */
	while (val != -999)
	{
		scanf("%d", &val);
		arr[i] = val;

		if (count > size - 3 && val != -999) {    //When running low on space allocate more

			arr = growArray(arr, &size);
		}
		i++;   //advacing to next element
		count++; //keeping track of how many index's get used
				 //printf("Count is: %d", count);
	}
	//Allocate memory for second Array
	secondArray = (int *)malloc(size * sizeof(int));

	//Copy first array into second array
	arrayCopy(arr, secondArray, count);

	//Sort the second(copied) array
	sort(secondArray, count - 1);

	//printf("Enter the number you would like to search for:\n");
	while (key != -999) {
		printf("\n**Enter the number you would like to search for:");
		scanf("%d", &key);
		printf(" %d\n", key);

		comparisons = 0;  //setting back to 0
		returnValueBinary = BinarySearch(secondArray, count, key, &comparisons); //storing the value from return in MAIN
		if (returnValueBinary != -1 && key != -999) {
			printf("\nBinary search:Value found!\n");
			printf("Binary search:It took %d comparisons to find the desired value\n", comparisons); //Print statements
			printf("Binary search: value was found at index: %d\n", returnValueBinary);
		}
		else {
			printf("Binary search:Value not found\n"); //Not found
		}

		comparisons = 0;	//setting back to 0
		returnValueLin = linSearch(arr, count, key, &comparisons);  //storing the value from return in MAIN

		if (returnValueBinary != -1 && key != -999) {
			printf("\nLinear search:Value found!\n");
			printf("Linear search:It took %d comparisons to find the desired value\n", comparisons); //Print statements
			printf("Linear search:value was found at index: %d\n", returnValueLin);
		}
		else {
			printf("Linear search: Value not found\n");  //Not found
		}
	}
}