###项目介绍

这个项目fork自[Jackarain]([https://github.com/Jackarain/mpfour),感谢。主要功能是解析MP4文件，获取各个box内容，在其上做了一些修改，兼容标准的MP4文件格式

 1. 使能够运行在linux平台下，修改了输出日志代码
 2. 增加mmpu,hint，mmth，muli box解析
 3. 增加box搜索功能（这个地方运行会有内存错误，待完善）


###使用说明

#####编译：

我测试的环境是在ubuntu下用eclipse开发，语音是c，编译的时候可能需要添加math库，即加上 -lm
#####添加box：
如果里面没有添加你需要的box，你可以自行添加，，添加的方法，修改mp4.c和mp4.h文件，找一个类比参考（如ftyp，mmpu）修改相应的部分，stream.c里面有你需要的获取流数据的函数
##### 获取box：
使用函数root = MP4_BoxGetRoot(s)，会获取整个MP4结构，通过first和next指针找到你所需要的box或container，root是一个二叉树，正在准备完善搜索
