/*给我设中文！*****************************************************************
07-31 1.0 
Basic options

08-01 1.1 
Supported QQ,PowerToys,Wallpaper,Spacedesk,Aurora,Edge or so...
Delete some app that might no used so ofen....
Add "getch"so that its no so complex to continue.

08-02 1.2 
(Actually not)Add NAS to support.
Add Key-Shortcut to support!!!
//An unforgettabled day about TW

08-03 2.0 14:00~18:47
优化了main函数的结构，将相关内容按功能包装为了函数
在【打开原神】的任务中，将自动开启浏览器的功能改为了自动登录

08-04 2.1
Fix the problem that when open bo3 the tools couldnt open but the cmd windows.
Fix the problem that when recover the Apps, those shall be closed were not closed by then.
Improve the struction of the code:Delete unnessasary definations.
Adjust the text of fail killing NAS.
Add color to the text.
*******To Do:Fix problem that when opening bo3 tool couldnt be launch by shortcut.********

08-05 2.2
Rename:Game Assister.
Prevent Recover by mistake.

08-06 2.3
Add support to act without killing QQ
Auto assist now requires to be after 19:40.
Auto enter fixed,it will be more accurate to avoid failing enter.(20:00:10)
To Do:add prerecovery code to support.

08-07 3.0
Fix the problem that cannot auto start assist on Sunday.
Add PreRecovery Code to support now!Mistaking-Struct Prevention within.//So many f*king BUGS!!!
Add start struction to support!There's no need to kill those apps opened as windows open now.
Add reminder when it's 19:50.
Add auto open game when it's 19:55.
Auto enter is more accurate now(20:00:03)

08-08 3.1
Fix the problem that some apps still recover though didnt exist before assist.
Change the mode when acting start-boot,it's now support game opening as well...

08-09 3.2
在star-boot时若按下Esc不再需要按Alt+A来重启了……牵扯一大堆……设变量时时刻注意其用途!!...
在非未成年辅助时也可自动打开游戏了

08-10 3.3
Fix wrong path of QQ after resetting Windows11.
Add WindowTop and Rainmeter to suppurt.

08-11 3.4
Fix wrong text and PreRecovery Code...
Fix mistaken kill QQ in code Q...
Improve the reading experience via defind
Improve the logic of Shortcut...
Prevent over type of the PreRecovery Code that open wrong game...
FPS show app now supported via Xbox Game Bar...
Add Snap GenShin Launcher to support.

08-12 3.5
Fix wrong first numb of PreRecovery Code...
Fix cannot recover after assist...
Fix mistaken opening QQ in code Default...[not]
Add auto account switch to assist...

08-13 3.6
Fix wrong value of keyboard shortcut...
Add fuction to open another game.
ToDo:Fix error of open another game...可能是第一个明明知道问题所在但是没办法解决的bug………………
*****************Fix mistaken opening QQ in code default......

08-15 3.6.1
Fix error of open another game,its now not achive via shortcut...
Fix mistakenly open in code S...
事实上！！！getch和getkeystate的区别不也是局部和全局快捷键的区别吗？！！
*****************Fact theres no need to add so much shortcut...
*****************Lose control of rec...

08-19 3.6.2
Fix lose of rec control and imorove the code strtc of whitch...
Fix unablility of open QQ in code Q...
**********************Strange pause when enter rec menu...
[not]Shall be the Final Vervion...(It was for serverl times...)

08-20 3.6.3
Add respond to recovery...

08-25 3.6.4
Improve the struction of start-boot code...
*******************************************************************/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define MOUSEX 65535/1920
#define MOUSEY 65535/1080
short int wp=0,wt=0,rm=0,pt=0,qq=0,eg=0,cm=0,sd=0,nas=0,g=0,t=0;//直接可以在这里加开机自启预设哈哈:)……牵连到一大堆改动……:(//Deleted...
short int k[3];
void kill();
void open();
void click(int x,int y);
void rec();
int main(void)
{
    system("mode con cols=40 lines=20");
    system("color 0e");
    system("echo off");//?
    printf("|||Start improving?|||\n\napps now suppurted:\
    \nWallpaper,Windowtop,rainmeter,PowerToys,\nQQ,Edge,Cloudmusic,Spacedesk,Aurora,\nBilibili\n\n");
    printf("\
Press any key to continue.\n\
Press S to start-boot.\n\
Press Q to play without QQ.\n\
Support PreRecovery Code now,\n\
type numb in order to continue...\n\
First numb control the first 4 apps...\n\n");

    B:
    t=getch();
    printf("%c",t);//So getch() willnot show what you type...
    switch (t)
    {
    case '0':case '1':
        wp=wt=rm=pt=t-48;//Also attention to the diffrence of char and int!!!
        for (short int n=0;n<4;n++)//???n<4时确实错了，但为什么会Endless呢？……???没错啊是n<4啊………………现在又没问题了…………
        {
            if((k[n]=getch()-48)!=0 && k[n]!=1){printf("Error,pls retype the code\n");goto B;}
            printf("%d",k[n]);//Endless there...n=0,1,2,1,2,1,2...
        }
        qq=k[0];eg=k[1];cm=k[2];sd=k[3];Sleep(200);break;
    case 's':break;
    case 'q':if(system("taskkill /t /f /im QQ.exe")==0){qq=1;};kill();break;
    case 27:return 0;
    case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':printf("No such code,pls try again...\n");goto B;
    default:kill();break;//???What it is mean that t=0???//F**k it lead to the bug that lose control of rec...
    }
    
    Open:system("cls");
    // if(t=='0'||t=='1')
    {printf("Your Recovery Code:%d%d%d%d%d\n\n",wp,qq,eg,cm,sd);}
    if(nas=1 && !(t=='0' || t=='1' || t=='s')){printf("NAS may be running but unabled to kill,\nplease kill it your own.\n\n");}//Review order of calculate!!!
    open();
    // Sleep(1000);

    if(t=='s' && g==27){}
    system("cls");
    printf("Ready to reboot\n\nPress G to open another game...\nR to reboot...\n");
    t=getch();
    Switch1: switch (t)
    {
        case 'g':goto Open;
        case 'r':break;
        default: goto Switch1;
    }

    if(t=='s')
    {
        system("start /d D:\\WoisolG\\Steam\\steamapps\\common\\wallpaper_engine wallpaper32.exe");
        system("start /d G:\\WindowTop WindowTop.exe");
        system("start /d D:\\WoisolG\\rainmeter Rainmeter.exe");
        system("start /d \"C:\\Program Files\\PowerToys\" PowerToys.exe");
        system("start /d \"G:\\QQ\\Bin\" QQ.exe");
    }
    else
    {
        rec();
    }
    // if(t!='s' || g!=27)//!(t=='s && g==27)
    // {
    //     system("cls");
    //     printf("Ready to reboot\n\nPress G to open another game...\nR to reboot...\n");
    //     t=getch();
    //     Switch1: switch (t)
    //     {
    //         case 'g':goto Open;
    //         case 'r':break;
    //         default: goto Switch1;            
    //     }
    // }
    // if(t=='s')
    // {
    //     system("start /d D:\\WoisolG\\Steam\\steamapps\\common\\wallpaper_engine wallpaper32.exe");
    //     system("start /d G:\\WindowTop WindowTop.exe");
    //     system("start /d D:\\WoisolG\\rainmeter Rainmeter.exe");
    //     system("start /d \"C:\\Program Files\\PowerToys\" PowerToys.exe");
    //     system("start /d \"G:\\QQ\\Bin\" QQ.exe");
    // }
    // else
    // {
    //     system("cls");
    //     printf("Ready to reboot\n\nPress G to open another game...\nR to reboot...\n");
    //     t=getch();
    //     Switch2: switch (t)
    //     {
    //         case 'g':goto Open;
    //         case 'r':break;
    //         default: goto Switch2;            
    //     }
    //     rec();
    // }
    
    // if(t=='s')//Can still be better...优先判断字幕段或许可以实现
    // {
    //     if(g!=27)
    //     {
    //         system("cls");
    //         printf("Ready to reboot\n\nPress G to open another game...\nR to reboot...\n");
    //         t=getch();
    //         Switch1: switch (t)
    //         {
    //             case 'g':goto Open;
    //             case 'r':break;
    //             default: goto Switch1;            
    //         }
    //     }
    //     system("start /d D:\\WoisolG\\Steam\\steamapps\\common\\wallpaper_engine wallpaper32.exe");
    //     system("start /d G:\\WindowTop WindowTop.exe");
    //     system("start /d D:\\WoisolG\\rainmeter Rainmeter.exe");
    //     system("start /d \"C:\\Program Files\\PowerToys\" PowerToys.exe");
    //     system("start /d \"G:\\QQ\\Bin\" QQ.exe");
    //     return 0;
    // }
    // else
    // {
    //     system("cls");
    //     printf("Ready to reboot\n\nPress G to open another game...\nR to reboot...\n");
    //     t=getch();
    //     Switch2: switch (t)
    //     {
    //         case 'g':goto Open;
    //         case 'r':break;
    //         default: goto Switch2;            
    //     }
    //     rec();
    // }
    return 0;
}
void kill()
{
    // extern int qq,pt,wp,sd,cm,nas;//全局变量是不必用extern在函数内再定义的...在函数内定义的变量是作为局部的另一变量，加了extern便代表是用外部的变量...
    if(system("taskkill /t /f /im wallpaper32.exe")==0){wp=1;}//所以失败的时候是什么？……
    if(system("taskkill /t /f /im WindowTop.exe")==0){wt=1;}//If fail its -1,DONOT confuse!//说是按Q但实际上检测的要是q哈！！
    if(system("taskkill /t /f /im Rainmeter.exe")==0){rm=1;}
    if(system("taskkill /t /f /im PowerToys.exe")==0){pt=1;}//所以如果删除失败也算没执行成功……
    if(system("taskkill /t /f /im msedge.exe")==0){eg=1;}//Unabled to kill it...Shown killed but still running...Why???
    if(system("taskkill /t /f /im cloudmusic.exe")==0){cm=1;}
    if(system("taskkill /t /f /im spacedeskService.exe")==0){sd=1;}
    if(system("taskkill /t /f /im wsserver.exe")==0){nas=1;}//Unabled to kill it...Shown killed but still running...Why???
    system("taskkill /t /f /im aurora.exe");
    system("taskkill /t /f /im 哔哩哔哩.exe");
    system("taskkill /t /f /im fraps.exe");
    // printf("%d%d%d%d%d",wp,qq,pt,eg,cm);system("pause");
}
void open()
{
    printf("||Which game to play?||\n\n1.GenShin Impact\n2.Call of Duty Bo3\nEsc.Do not act.\nOthers.\n");
    // extern int t;
    A:g=getch();
                                                                        //GenShin
    if(g=='1')
    {
        int a=0,s5=0;//Assist or not.
        system("cls");
        printf("Opening Genshin...\n");
        system("start /d \"G:\\SnapGenshin\" DGP.Genshin.exe");
        // system("start /d \"C:\\Program Files\\WindowsApps\\microsoft.xboxgamingoverlay_5.822.6271.0_x64__8wekyb3d8bbwe\" GameBar.exe");

        time_t ct=0;
        struct tm *t;//这个t居然没冲突...所以{}内的定义都是局部对吗？~
        ct=time(NULL);
        t=localtime(&ct);
        if((t->tm_wday>4 ||t->tm_wday==0) && t->tm_hour==19 && t->tm_min>=30){a=1;printf("It's weekday %d %d:%d so\nAssist ON...\nPress Alt+A again to stop.\n",t->tm_wday,t->tm_hour,t->tm_min);}
        else
        {
            printf("Press Alt+A in 5s for assist\n\n");
            for(s5=0;s5<=50;s5++)
            {
                if(s5%10==0){printf("%d\n",5-s5/10);}
                Sleep(100);
                if(GetKeyState(65)<0 && GetKeyState(18)<0){a=1;system("cls");printf("Assist ON...\nPress Alt+A again to stop.\n");Sleep(1000);break;}
                if (s5==50 && a==0){system("cls");printf("Assist OFF.\n");Sleep(2000);break;}//Used to think to deside after 2sec here...
            }   //!!!!!!!!!ATTENTIONS TO OREDER OF THE SIMBOL!!!!!!!!!!!![划去]实际上是等于号的问题！！！！=和==！！！
        }

        // system("start /d \"C:\\Users\\Woisol\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\" time.lnk");
        if(a==1)
        {
            short int t1=0,t2=0;//每次循环这里都会再设为0…………怪不得循环………………
        while(1)
        {
            Sleep(100);
            if(GetKeyState(65)<0 && GetKeyState(18)<0){system("cls");printf("You close the assist...\n");Sleep(2000); break;}
            ct=time(NULL);//Remember to update the time!!!
            t=localtime(&ct);
            switch (t->tm_min)
            {
            case 50:
                if(t1==1){break;}
                printf("\n\n\n              WARNING!\n\nIt's 19:50 now!Get yourself ready!\n\n");
                t1=1;break;//忘记标记以致刷屏……这里的}也要注意位置！
            case 55:
                if(t2==1){break;}//欸嘿~
                printf("Opening GenShin...");
                click(490,322);
                Sleep(1000);
                click(1050,510);
                click(1030,250);
                t2=1;break;
            case 0:
                if(t->tm_sec==3)
                {
                mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE,65535/2,65535/2,0,0);
                mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
                mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                system("cls");
                printf("Mission completed.\n");
                goto O;//One break merely break the switch...
                }
            }
            // if(t->tm_min==55)//Former one
            // {
            // }
            // if(t->tm_min==0 && t->tm_sec==3)
            // {
            // }
            // if(GetKeyState(65)<0){if(GetKeyState(18)<0){system("taskkill /t /f /im msedge.exe");break;}}}//Forgot to break that couldnt recover those app...
        }
        // system("pause");//Former act without surpurt to Shortcut
        }
        else
        {
            Sleep(3000);
            printf("Opening GenShin...");
            click(490,322);
            Sleep(1000);
            click(1030,250);

        }
        O:Sleep(5000);
    }
                                                                //Call of Duty BO3
    else if(g=='2')
    {
        system("cls");
        printf("Opening Call of Duty BO3...\n");//Press Alt+A to open Swithcher,\nAlt+S to stop openning Switcher.
        system("start /d \"G:\\Call of Duty Black Ops III\" BlackOps3.exe");
        system("\"G:\\Call of Duty Black Ops III\\BO3 ZM Trainer 1.3.3.exe\"");
        // Sleep(0);
        // system("\"G:\\Call of Duty Black Ops III\\BO3OfflineSwitcherUpdate9.EXE\"");
        Sleep(100);
        printf("\n");
        // while(1)
        // {
        //     Sleep(100);
        //     if(GetKeyState(83)<0){if(GetKeyState(18)<0){break;}}//Miss "}" that fail.Which wont be found.
        //     if(GetKeyState(65)<0){if(GetKeyState(18)<0){system("\"G:\\Call of Duty Black Ops III\\BO3OfflineSwitcherUpdate9.EXE\"");break;}}
        // }
    }
    else if(g==18||g==71){g=getch();goto A;}//防止按Alt+G返回时误触发……Waiting for better mode...
    else if(g!=27)
    {
        keybd_event(VK_LWIN,0,0,0);
        keybd_event(VK_LWIN,0,KEYEVENTF_KEYUP,0);
    }
    //The former act that cant react at once||
    /*t=getchar();
    scanf("%d",&t);
    switch(t)
    {
    case '1':
    system("start /d \"G:\\Genshin Impact\" launcher.exe");
    system("start /d D:\\WoisolG\\FPS fraps.exe");
    system("start /d \"C:\\Users\\Woisol\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\time.lnk\"");
    system("pause");
    system("taskkill /t /f /im msedge.exe");
    break;
    case '2':system("explorer \"G:\\Call of Duty Black Ops III\"");system("taskkill /t /f /im fraps.exe");break;
    }*/
}
void click(int x,int y)
{
    mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE,x*MOUSEX,y*MOUSEY,0,0);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}
void rec()
{
    // extern int qq,pt,wp,sd,cm,nas;//,t;
    // system("pause");//Attention to 1 and '1'!!!!!!!
    printf("Recovering...\n");
    if (g=='1'){system("taskkill /t /f /im fraps.exe");system("taskkill /t /f /im launcher.exe");}//这里原来要判断两次分别关掉…………
    if (g=='2'){system("taskkill /t /f /im \"BO3 ZM Trainer 1.3.3\"");system("taskkill /t /f /im BO3OfflineSwitcherUpdate9.EXE");}
    if (wp==1){system("start /d D:\\WoisolG\\Steam\\steamapps\\common\\wallpaper_engine wallpaper32.exe");}//so when using start it can start at a time right?...
    if (wt==1){system("start /d G:\\WindowTop WindowTop.exe");}
    if (rm==1){system("start /d D:\\WoisolG\\rainmeter Rainmeter.exe");}
    if (pt==1){system("start /d \"C:\\Program Files\\PowerToys\" PowerToys.exe");}
    if (qq==1){system("start /d \"G:\\QQ\\Bin\" QQ.exe");}
    if (eg==1){system("start /d \"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\" msedge.exe");}
    if (cm==1){system("start /d D:\\WoisolG\\CloudMusic cloudmusic.exe");}
    if (sd==1){system("start /d C:\\Windows\\System32 spacedeskConsole.exe");}
    // if (nas==1){system("start /d \"D:\\HikBox Client\" HikStorage.exe");}
}