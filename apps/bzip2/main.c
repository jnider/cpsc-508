#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bzlib.h>

int main(int argc, char *argv[])
{
	int ret;
	int bs = 1;// block size
	bz_stream stream;
	int verbosity = 4; // max debugging
	int wf = 30; // good default

	unsigned int uncompressedSize;
	unsigned int inSize = 1024;
	unsigned int compressedSize = inSize * 2;

	char *inbuf = malloc(inSize);
	char *compressed = malloc(compressedSize);
	char *uncompressed = malloc(compressedSize * 2); // leave a little space in case

	printf("Testing bzip2\n");
	memset(&stream, 0, sizeof(stream));
	ret = BZ2_bzCompressInit(&stream, bs, verbosity, wf);
	if (ret != BZ_OK)
	{
		printf("Compress init failed\n");
		return -1;
	}

	// fill the uncompressed buffer with very important information
	for (int i=0; i < inSize; i++)
		inbuf[i] = rand();

	// compress a buffer
	printf("compressing\n");
	ret = BZ2_bzBuffToBuffCompress(compressed, &compressedSize, inbuf, inSize,
		bs, verbosity, wf); 
	if (ret != BZ_OK)
	{
		printf("Compress failed: %i\n", ret);
		return -2;
	}

	BZ2_bzCompressEnd(&stream);

	memset(&stream, 0, sizeof(stream));
	ret = BZ2_bzDecompressInit(&stream, verbosity, 0);
	if (ret != BZ_OK)
	{
		printf("Decompress init failed\n");
		return -1;
	}

	// decompress the same buffer
	printf("decompressing\n");
	ret = BZ2_bzBuffToBuffDecompress(uncompressed, &uncompressedSize, compressed, compressedSize,
		0, verbosity); 
	if (ret != BZ_OK)
	{
		printf("Decompress failed\n");
		return -2;
	}

	// compare the outputs
	printf("comparing\n");
	for (int i=0; i < inSize; i++)
	{
		if (inbuf[i] != uncompressed[i])
		{
			printf("Error in byte %i\n", i); 
			return -3;
		}
	}

	printf("Comparison complete!\n");

	return 0;
}
