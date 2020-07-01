#include <iostream>
#include "bgm.h"

int main()
{
    BGM music;//仅供展示用(负责命令的同学后期删去后，想使用什么功能直接用按键调用即可)
    music.play_music();//仅供展示用（开始播放音乐）
    music.setvolume(-500);//仅供展示用（降低音量500）
    system("pause");//冻结屏幕以展示音乐播放效果
    return 0;
}

