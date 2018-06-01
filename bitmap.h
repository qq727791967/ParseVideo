/**
 * FreeRDP: A Remote Desktop Protocol Client
 * Bitmap File Format Utils
 *
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#pragma once
extern void freerdp_bitmap_write(char* filename, void* data, int width, int height, int bpp);
extern char * freerdp_bitmap_write_mem(void* data, int width, int height, int bpp,int *ncount);
extern void freerdp_bitmap_clean_mem();
typedef UINT8 uint8;
typedef UINT32 uint32;
typedef UINT16 uint16;
typedef int sint32;
#pragma pack(push)
#pragma pack(1)
typedef struct
{
	uint8 magic[2];
} bmpfile_magic;

typedef struct
{
	uint32 filesz;
	uint16 creator1;
	uint16 creator2;
	uint32 bmp_offset;
} bmpfile_header;

typedef struct
{
	uint32 header_sz;
	sint32 width;
	sint32 height;
	uint16 nplanes;
	uint16 bitspp;
	uint32 compress_type;
	uint32 bmp_bytesz;
	sint32 hres;
	sint32 vres;
	uint32 ncolors;
	uint32 nimpcolors;
} BITMAPINFOHEADER1;

typedef struct bitmap_data
{
	char *pdata;
	UINT data_count;
}BITMAP_DATA;

#pragma pack(pop)