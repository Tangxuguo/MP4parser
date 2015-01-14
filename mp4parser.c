#include "stdafx.h"
#include "mp4.h"
#include "malloc.h"
#include "string.h"

int main(int argc, char* argv[])
{
   int i;
   mp4_box_t *root,*SearchResult = NULL;
   stream_t* s = NULL;

   //////////////ÐÞ¸Äºó
   unsigned long filesize = 0;
   BUFFER_t *buffer = NULL;
   FILE *file = fopen("Channel1_Audio1_MPU_0000.mp4","rb");
   fseek(file,0L,SEEK_END);
   filesize = ftell(file);
   fseek(file,0L,SEEK_SET); 
   buffer = (BUFFER_t *)malloc(sizeof(BUFFER_t));
   buffer->begin_addr = (unsigned char *)malloc(filesize);
   buffer->buf = (unsigned char *)malloc(filesize);
   fread(buffer->begin_addr,filesize,1,file);
   memcpy(buffer->buf,buffer->begin_addr,filesize);
   (*buffer).offset = 0;
   (*buffer).filesize = filesize;
   s = create_buffer_stream();
   if (buffer_open(s, buffer) == 0)
      return -1;
   root = MP4_BoxGetRootFromBuffer(s,filesize);
   SearchResult = MP4_BoxSearchBox(root,ATOM_mmth);
   printf("search result box is %c%c%c%c\n",SearchResult->i_type&0x000000ff,(SearchResult->i_type&0x0000ff00)>>8,(SearchResult->i_type&0x00ff0000)>>16,(SearchResult->i_type&0xff000000)>>24);
   MP4_BoxFreeFromBuffer( root );

   buffer_close(s);
   destory_buffer_stream(s);
   ////////////////

 /*  s = create_file_stream();
   if (stream_open(s, "Channel1_Audio1_MPU_0000.mp4", MODE_READ) == 0)
      return -1;

   root = MP4_BoxGetRoot(s);
   SearchResult=MP4_BoxSearchBox(root,ATOM_mmth);
   printf("search result box is %c%c%c%c\n",SearchResult->i_type&0x000000ff,(SearchResult->i_type&0x0000ff00)>>8,(SearchResult->i_type&0x00ff0000)>>16,(SearchResult->i_type&0xff000000)>>24);
   MP4_BoxFree( root );

   stream_close(s);
   destory_file_stream(s);*/

	return 0;
}

