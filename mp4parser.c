#include "stdafx.h"
#include "stream.h"
#include "mp4.h"

int main(int argc, char* argv[])
{
   mp4_box_t *root,*SearchResult = NULL;
   stream_t* s = NULL;

   s = create_file_stream();
   if (stream_open(s, "Channel1_Audio1_MPU_0000.mp4", MODE_READ) == 0)
      return -1;

   root = MP4_BoxGetRoot(s);
   SearchResult=MP4_BoxSearchBox(root,ATOM_mmth);
   printf("search result box is %c%c%c%c\n",SearchResult->i_type&0x000000ff,(SearchResult->i_type&0x0000ff00)>>8,(SearchResult->i_type&0x00ff0000)>>16,(SearchResult->i_type&0xff000000)>>24);
   MP4_BoxFree(s, root);

   stream_close(s);
   destory_file_stream(s);

	return 0;
}

