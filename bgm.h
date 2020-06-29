#pragma once
#include <windows.h>
#include <mmsystem.h>//多媒体接口库
using namespace std;
#pragma comment(lib,"winmm.lib")//多媒体静态库

class BGM
{
public:
    void play_music() {
        mciSendString("open 1.mp3 alias music1", 0, 0, 0);//打开音频文件,并重命名为music1
        mciSendString("play music1 repeat", 0, 0, 0); //开始循环播放music1
    };
    void pause_music() {
        mciSendString("pause music1", 0, 0, 0);//暂停播放music1
    };
    void setvolume(signed int u_volume) {
        char cmd[256];//指令字符串
        char ch_volume[256];//音量字符串
        mciSendString("status music1 volume", ch_volume, 255, 0);//获取音量大小：初始音量大小为1000
        long l_volume = strtol(ch_volume, NULL, 10);//把音量字符串类型转为整型以便修改音量大小
        wsprintf(cmd, "setaudio music1 volume to %i", l_volume + u_volume);//修改音量大小(正数提高音量，负数降低音量，建议每次调整大小为100的倍数)
        mciSendString(cmd, NULL, 0, NULL);//设置music1音量
    };
    void close_music() {
        mciSendString("close music1", 0, 0, 0);//关闭音频文件
    }
};