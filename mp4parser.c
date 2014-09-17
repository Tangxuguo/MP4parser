#include "stdafx.h"
#include "stream.h"
#include "mp4.h"

int main(int argc, char* argv[])
{
   mp4_box_t *root = NULL;
   stream_t* s = NULL;

   s = create_file_stream();
   if (stream_open(s, "D:\\media\\title.mp4", MODE_READ) == 0)
      return -1;

   root = MP4_BoxGetRoot(s);
   MP4_BoxFree(s, root);

   stream_close(s);
   destory_file_stream(s);

	return 0;
}

