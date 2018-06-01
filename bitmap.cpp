/**
 * FreeRDP: A Remote Desktop Protocol Client
 * Bitmap File Format Utils
 *
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at111
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "StdAfx.h"

#include "bitmap.h"


char * freerdp_bitmap_write_mem(void* data, int width, int height, int bpp,int *ncount)
{
	//FILE* fp;
	char *pbuffer;
	bmpfile_magic magic;
	bmpfile_header header;
	BITMAPINFOHEADER1 info_header;
	char *pIndex ;
	//fp = fopen(filename, "w+b");

	//if (fp == NULL)
	//{
	//	printf("failed to open file %s\n", filename);
	//	return;
	//}

	magic.magic[0] = 'B';
	magic.magic[1] = 'M';

	header.creator1 = 0;
	header.creator2 = 0;

	header.bmp_offset =
		sizeof(bmpfile_magic) +
		sizeof(bmpfile_header) +
		sizeof(BITMAPINFOHEADER1);

	info_header.bmp_bytesz = width * height * (bpp / 8);

	*ncount = header.bmp_offset+info_header.bmp_bytesz;

	//pbuffer = (char *)malloc(header.bmp_offset+info_header.bmp_bytesz);
	pbuffer = new char[header.bmp_offset+info_header.bmp_bytesz];
	header.filesz =
		header.bmp_offset +
		info_header.bmp_bytesz;

	info_header.width = width;
	info_header.height = (-1) * height;
	info_header.nplanes = 1;
	info_header.bitspp = bpp;
	info_header.compress_type = 0;
	info_header.hres = width;
	info_header.vres = height;
	info_header.ncolors = 0;
	info_header.nimpcolors = 0;
	info_header.header_sz = sizeof(BITMAPINFOHEADER1);
	pIndex = pbuffer;
	memcpy(pIndex,&magic,sizeof(bmpfile_magic));
	pIndex += sizeof(bmpfile_magic);
	memcpy(pIndex,&header,sizeof(bmpfile_header));
	pIndex += sizeof(bmpfile_header);
	memcpy(pIndex,&info_header,sizeof(BITMAPINFOHEADER1));
	pIndex += sizeof(BITMAPINFOHEADER1);
	memcpy(pIndex,data,info_header.bmp_bytesz);
	//fwrite((void*) &magic, sizeof(bmpfile_magic), 1, fp);
	//fwrite((void*) &header, sizeof(bmpfile_header), 1, fp);
	//fwrite((void*) &info_header, sizeof(BITMAPINFOHEADER), 1, fp);
	//fwrite((void*) data, info_header.bmp_bytesz, 1, fp);

	//fclose(fp);
	return pbuffer;
}
//void freerdp_bitmap_clean_mem()
//{
//	free(pbuffer);
//	pbuffer = 0;
//}
void freerdp_bitmap_write(char* filename, void* data, int width, int height, int bpp)
{
	FILE* fp;
	bmpfile_magic magic;
	bmpfile_header header;
	BITMAPINFOHEADER1 info_header;

	fp = fopen(filename, "w+b");

	if (fp == NULL)
	{
		printf("failed to open file %s\n", filename);
		return;
	}

	magic.magic[0] = 'B';
	magic.magic[1] = 'M';

	header.creator1 = 0;
	header.creator2 = 0;

	header.bmp_offset =
			sizeof(bmpfile_magic) +
			sizeof(bmpfile_header) +
			sizeof(BITMAPINFOHEADER1);

	info_header.bmp_bytesz = width * height * (bpp / 8);

	header.filesz =
		header.bmp_offset +
		info_header.bmp_bytesz;

	info_header.width = width;
	info_header.height = (-1) * height;
	info_header.nplanes = 1;
	info_header.bitspp = bpp;
	info_header.compress_type = 0;
	info_header.hres = width;
	info_header.vres = height;
	info_header.ncolors = 0;
	info_header.nimpcolors = 0;
	info_header.header_sz = sizeof(BITMAPINFOHEADER1);

	fwrite((void*) &magic, sizeof(bmpfile_magic), 1, fp);
	fwrite((void*) &header, sizeof(bmpfile_header), 1, fp);
	fwrite((void*) &info_header, sizeof(BITMAPINFOHEADER1), 1, fp);
	fwrite((void*) data, info_header.bmp_bytesz, 1, fp);

	fclose(fp);
}

