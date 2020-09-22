// Solution.c File
#include <stdio.h>
int  main()
{
	FILE *filePtr;	// a file pointer to the requested file
	char chInput;
	// Open a file ArbitraryText.txt in append mode and crete if doesn't already exists.
	if((filePtr = fopen("ArbitraryText.txt", "a+")) == NULL)
	{
		printf("Requested file could not be opened.\n");
		return 1;
	}
	else
		printf("Requested file opened with read/write permission in append mode.\n");

	// Following while loop will run and takes the input from keyboard and write it to opened file till EOF(End Of File) 
	// Encounters. Once EOF input occurs, loop will break and further file will be closed to save entered text.
	
	while ((chInput = getchar()) != EOF) {
		putc(chInput, filePtr);
	}
	
	// Close the file
	if(filePtr)
		fclose(filePtr);

	return 0;
}