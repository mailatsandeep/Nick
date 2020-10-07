// Solution1_updated.c File
#include <stdio.h>
int ReadWriteText()
{
	FILE *filePtr;	// a file pointer to the requested file
	char chInput;
	// Open a file ArbitraryText.txt in append mode and crete if doesn't already exists.
	if ((filePtr = fopen("ArbitraryText.txt", "a+")) == NULL)
	{
		fputs("Memory Allocation Error", stderr);
		return 1;
	}
	// Following while loop will run and takes the input from keyboard and write it to opened file till EOF(End Of File) 
	// Encounters. Once EOF input occurs, loop will break and further file will be closed to save entered text.

	while ((chInput = getchar()) != EOF) {
		putc(chInput, filePtr);
	}

	// Close the file
	if (filePtr)
		fclose(filePtr);

	return 0;
}
int ReadWriteImage()
{
	FILE * pFileSource;	// source file pointer
	long lSize;		// size of file in byte
	char * bufferFileData;	// buffer to hold the file data
	size_t result;

	// A SampleImage.png keep it in project directory OR give fully qualified path
	// Open file in read binary mode
	if((pFileSource = fopen("SampleInputImage.png", "rb")) == NULL)
	{
		fputs("File Open Error", stderr);
		return 1;
	}
	// get the file size in bytes:
	fseek(pFileSource, 0, SEEK_END);
	lSize = ftell(pFileSource);
	rewind(pFileSource);

	// Allocate buffer
	bufferFileData = (char*)malloc(sizeof(char)*lSize);
	if (bufferFileData == NULL)
	{
		fputs("Memory Allocation Error", stderr);
		fclose(pFileSource);
		return 1;
	}
	// Read all the data from file and fill the buffer
	result = fread(bufferFileData, 1, lSize, pFileSource);
	if (result != lSize)
	{
		fputs("File Read Error", stderr);
		fclose(pFileSource);
		free(bufferFileData);
		return 1;
	}
	fclose(pFileSource);

	FILE * pFileDestination;
	if ((pFileDestination = fopen("SampleOutputImage.png", "wb+")) == NULL)
	{
		fputs("File Open Error", stderr);
		return 1;
	}
	result = fwrite(bufferFileData, 1, lSize, pFileDestination);
	if (result != lSize)
	{
		fputs("File Write Error", stderr);
		fclose(pFileDestination);
		free(bufferFileData);
		return 1;
	}
	fclose(pFileDestination);
	free(bufferFileData);
	return 0;
}
int ReadWriteVideo()
{
	FILE * pFileSource;	// source file pointer
	long lSize;		// size of file in byte
	char * bufferFileData;	// buffer to hold the file data
	size_t result;

	// A SampleImage.png keep it in project directory OR give fully qualified path
	// Open file in read binary mode
	if ((pFileSource = fopen("SampleInputVideo.mp4", "rb")) == NULL)
	{
		fputs("File Open Error", stderr);
		return 1;
	}
	// get the file size in bytes:
	fseek(pFileSource, 0, SEEK_END);
	lSize = ftell(pFileSource);
	rewind(pFileSource);

	// Allocate buffer
	bufferFileData = (char*)malloc(sizeof(char)*lSize);
	if (bufferFileData == NULL)
	{
		fputs("Memory Allocation Error", stderr);
		fclose(pFileSource);
		return 1;
	}
	// Read all the data from file and fill the buffer
	result = fread(bufferFileData, 1, lSize, pFileSource);
	if (result != lSize)
	{
		fputs("File Read Error", stderr);
		fclose(pFileSource);
		free(bufferFileData);
		return 1;
	}
	fclose(pFileSource);

	FILE * pFileDestination;
	if ((pFileDestination = fopen("SampleOutputVideo.mp4", "wb+")) == NULL)
	{
		fputs("File Open Error", stderr);
		return 1;
	}
	result = fwrite(bufferFileData, 1, lSize, pFileDestination);
	if (result != lSize)
	{
		fputs("File Write Error", stderr);
		fclose(pFileDestination);
		free(bufferFileData);
		return 1;
	}
	fclose(pFileDestination);
	free(bufferFileData);
	return 0;
}
int ReadWriteBinary()
{
	FILE * pFileSource;	// source file pointer
	long lSize;		// size of file in byte
	char * bufferFileData;	// buffer to hold the file data
	size_t result;

	// A SampleImage.png keep it in project directory OR give fully qualified path
	// Open file in read binary mode
	if((pFileSource = fopen("SampleInputBinary.exe", "rb")) == NULL)
	{
		fputs("File Open Error", stderr);
		return 1;
	}
	// get the file size in bytes:
	fseek(pFileSource, 0, SEEK_END);
	lSize = ftell(pFileSource);
	rewind(pFileSource);

	// Allocate buffer
	bufferFileData = (char*)malloc(sizeof(char)*lSize);
	if (bufferFileData == NULL)
	{
		fputs("Memory Allocation Error", stderr);
		fclose(pFileSource);
		return 1;
	}
	// Read all the data from file and fill the buffer
	result = fread(bufferFileData, 1, lSize, pFileSource);
	if (result != lSize)
	{
		fputs("File Read Error", stderr);
		fclose(pFileSource);
		free(bufferFileData);
		return 1;
	}
	fclose(pFileSource);

	FILE * pFileDestination;
	if((pFileDestination = fopen("SampleOutputBinary.exe", "wb+")) == NULL)
	{
		fputs("File Open Error", stderr);
		return 1;
	}
	result = fwrite(bufferFileData, 1, lSize, pFileDestination);
	if (result != lSize)
	{
		fputs("File Write Error", stderr);
		fclose(pFileDestination);
		free(bufferFileData);
		return 1;
	}
	fclose(pFileDestination);
	free(bufferFileData);
	return 0;
}
int main(void)
{	
	int choice = 0;
	int retval = 0;
	// Decision Block
	printf("Please enter your choice : \n 1 for Text \n 2 for Image\n 3 for Video\n 4 for Binary\n 0 to Exit\n\n");
	scanf("%d", &choice);
	if(choice)
		switch (choice)
		{
		case 1:
			retval = ReadWriteText();
			break;
		case 2:
			retval = ReadWriteImage();
			break;
		case 3:
			retval = ReadWriteVideo();
			break;
		case 4:
			retval = ReadWriteBinary();
			break;
		default:
			break;
		}
	else
		exit(1);

	if (retval)
	{
		printf("Operation failed");
		exit(1);
	}	
}