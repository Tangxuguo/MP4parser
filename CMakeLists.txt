#file(GLOB SRCS *.c *.h)

set(SRCS
	stream.h
	stream.c
	mp4.h
	mp4.c
	mp4parser.c
)

ADD_EXECUTABLE(mp4parser ${SRCS})

TARGET_LINK_LIBRARIES(mp4parser m)
