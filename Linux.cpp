/*Linux
一、主界面
    [root@localhost ~]#
    用户名 主机名  用户主目录 #超级管理员 $普通用户
    命令格式：命令 参数 参数
二、常用命令
    ip addr 查看ip地址
    2.YUM 软件包升级器 - （Fedora, RedHat及类似系统）
        yum install package_name 下载并安装一个rpm包
            例如：yum -y install vim (-y自动确定)
    3.文件
        ls  查看当前目录的文件
        ls -l (ll)查看当前目录的文件详细信息
            例如：   .   1.c    .2.cpp.swp       .bash_logout   .cshrc
                    ..  2      anaconda-ks.cfg  .bash_profile  .tcshrc
                    1   2.cpp  .bash_history    .bashrc        .viminfo
            . 表示当前目录  ..表示上一级目录
        ls -al / ls -a -l 查看当前目录的所有文件(包括.开头的隐藏文件)详细信息
        ls -a 查看当前目录的所有文件(包括.开头的隐藏文件)
            例如：-rw-r--r--. 1     root    root   88          Apr 26 06:13 2.cpp
                    权限   文件名   拥有者   群组   文件大小(字节)   日期     文件名
        ls -l | grep *** 查看当前目录文件详细信息，然后查找相应字段
        | 管道“|”是管道命令操作符，简称管道符。
            利用Linux所提供的管道符“|”将两个命令隔开，
            管道符左边命令的输出就会作为管道符右边命令的输入。
            连续使用管道意味着第一个命令的输出会作为 第二个命令的输入，
            第二个命令的输出又会作为第三个命令的输入，依此类推。
        ls -l /etc  查看指定目录文件详细信息
        chgrp (新群组) *.*   将*.*放到新群组下
        chown 将指定文件的拥有者改为指定的用户或组
        chmod u/y/o+r/w/x *.*  对指定群组增加对应权限
        chmod u/y/o-r/w/x *.*  对指定群组减少对应权限
        chmod +r/w/x *.* 对所有群组增加对应权限
        chmod 777   对所有群组赋予所有权限
        chmod 更改权限
            - --- --- --- .
            第1个横杠(文件类型)
                - 普通文件
                d 目录/文件夹
            第2-4个横杠(拥有者)  u
                - 无权限
                r 读取权限  4
                w 写入权限  2
                x 执行权限  1
            第5-7个横杠(群组) y
                - 无权限
                r 读取权限
                w 写入权限
                x 执行权限
            第8-10个横杠(其他用户) o
                - 无权限
                r 读取权限
                w 写入权限
                x 执行权限
        cp *.* **.* 把*.*复制重命名为**.*
        cat *.* 查看文件(一般打开文本文件)
        touch *.* 创建文件          文件由 文件名.拓展名 组成
        touch XXXX-{1..9}.xx    可以创建名为XXXX-1.xx ~ XXXX-9.xx等多个文件
        mkdir *** 创建文件夹
        mv *.* **.* 将*.*文件重命名为**.*
        rename .x .xx *.x  将所有后缀名为.x的文件重命名为.xx
        rm *.* 删除文件
        rm -f XXXX-{1..9}.xx    可以直接(不需要确认)删除名为XXXX-1.xx ~ XXXX-9.xx等多个文件
        rm -r XXX   可以直接删除目录
        rm -rf *    删除所有数据
        mv *.* 目标文件夹/ 移动*.*到目标文件夹
        pwd 查看当前目录完整路径
        cd *** 到目标目录下
        cd .. 返回上一层目录
        cd /root 返回用户主目录
        cd ~ 返回用户主目录
        cd / 返回根目录
        cd - 返回上次操作的目录
        cd 返回用户主目录
        cd 绝对路径 进入目标目录
        ps -ef 用于查看全格式的全部进程
        top 命令查看zombie进程数量
        ps -A -ostat,ppid,pid,cmd | grep -e '^[zZ]' 查看僵尸进程
        kill -HUP ppid 结束僵尸进程
        kill -9 1234 立即结束僵尸进程  -9表示立即执行 1234为父进程号,即ppid
        直接查找僵死进程，然后将父进程杀死~
        ps -A -o stat,ppid,pid,cmd | grep -e '^[Zz]' | awk '{print $2}' | xargs kill -9
        head -X *.*  查看前X行
        tail -X *.*  查看后X行
        source FileName 作用：在当前bash环境下读取并执行FileName中的命令。
        source .bash_rc 与 . .bash_rc 是等效的。该命令通常用命令“.”来替代。
        cat $PATH   查看linux环境下的变量需要加$
        xargs  将参数列表转换成小块分段传递给其他命令
        tar -zcvf *.tar.gz *.* *.* 将两个*.*文件压缩为*.taz.gz
        tar -zcxf 路径/*.tar.gz 解压到当前目录下
        tar -zcxf 路径/*.tar.gz -d 路径/ 解压到指定路径下
        top 任务管理器 q退出
        find
        find ./ -name "*.*"  按名称查找
        find ./ -atime 1
        find ./ -size +1000k 查找大于1000k的文件
        cut -f 1 -d, 11.txt
        -f 指定列
        -d 指定分隔符
        cat 11.txt | tr , '#'
        tr , .  将,转换成.
        tr a-z A-Z  大小写转换
        echo "abc 123 def" | tr -d 0-9  删除字符
        echo "abc 123 def" | tr -d " "   删除字符
        echo "abc 123 def" | tr -d " ""0-9"   删除字符
        输出重定向符
            echo "Hello World" >a.txt
            >>  追加
            >  覆盖
            ./out.exe 1>1.txt 2>2.txt
            1 标准输出
            2 标准错误输出
        输入重定向
            echo 11 22 >1.txt   ./4 <1.txt
            #include<stdio.h>
            int main()
            {
                printf("正常的\n");
                perror("不正常的\n");
                return 0;
            }
            输出结果:
                正常的
                不正常的
                : Success

        $? 上一次调用的返回值(不管是函数还是命令)
    4.  网络
        ping 检测网络
        ping -c 3 www.baidu.com  与百度进行三次通信，然后退出
        scp 在两台Linux主机上传输文件
        scp root@192.168.3.179:/root/1.c /11.c      从xxx下载文件
        scp /11.c root@192.168.3.179:/root/1.c      向xxx上传文件
    5.  tree命令行参数：
        -a 显示所有文件和目录。
        -A 使用ASNI绘图字符显示树状图而非以ASCII字符组合。
        -C 在文件和目录清单加上色彩，便于区分各种类型。
        -d 显示目录名称而非内容。
        -D 列出文件或目录的更改时间。
        -f 在每个文件或目录之前，显示完整的相对路径名称。
        -F 在执行文件，目录，Socket，符号连接，管道名称名称，各自加上"*","/","=","@","|"号。
        -g 列出文件或目录的所属群组名称，没有对应的名称时，则显示群组识别码。
        -i 不以阶梯状列出文件或目录名称。
        -I 不显示符合范本样式的文件或目录名称。
        -l 如遇到性质为符号连接的目录，直接列出该连接所指向的原始目录。
        -n 不在文件和目录清单加上色彩。
        -N 直接列出文件和目录名称，包括控制字符。
        -p 列出权限标示。
        -P 只显示符合范本样式的文件或目录名称。
        -q 用"?"号取代控制字符，列出文件和目录名称。
        -s 列出文件或目录大小。
        -t 用文件和目录的更改时间排序。
        -u 列出文件或目录的拥有者名称，没有对应的名称时，则显示用户识别码。
        -x 将范围局限在现行的文件系统中，若指定目录下的某些子目录，其存放于另一个文件系统上，则将该子目录予以排除在寻找范围外。
    6.  用户
        useradd xxx 创建用户
        passwd xxx 更改用户密码
    7.  gcc/g++
        gcc/g++ *.c/.cpp -o *.exe  将文件编译为可执行文件
        gcc/g++ -g *.c/.cpp -o *.exe 将文件编译为可执行文件,在编译的时候，产生调试信息。
        gdb
        gdb filename 调试目标文件
        l/list
        r Run的简写，运行被调试的程序。如果此前没有下过断点，则执行完整个程序；如果有断点，则程序暂停在第一个可用断点处。
        b设置断点，clear清除断点
        b/clear <行号>	   b: Breakpoint的简写，设置断点。
        info breakpoints  查看断点信息
        b <函数名称>   两可以使用“行号”“函数名称”“执行地址”等方式指定断点位置。
        b *<函数名称>  其中在函数名称前面加“*”符号表示将断点设置在“由编译器
        b *<代码地址>   生成的prolog代码处”。如果不了解汇编，可以不予理会此用法。
        disable <断点序号> 禁用断点
        watch 设置观察点(watchpoint)。使用观察点可以使得当某表达式的值发生变化时,程序暂停执行。
        bt/backtrace  可使用frame 查看堆栈中某一帧的信息
        set var name=value 在程序运行中动态改变变量的值
        n/next 逐过程执行
        s/step 逐语句执行
        c Continue的简写，继续执行被调试程序，直至下一个断点或程序结束。
        p/print 打印当前变量
        q/quit 退出
    8.  grep 'xx' *.* 查看某文件中关键字信息
        -n  查看行号及文件名
        -v  查看某文件中除关键字以外的信息(反向查询)
        -l  定位到文件
            grep -l 1 *.txt
        'xx$'查看行尾
        ip addr | grep ens33$ | awk '{print $2}'
        awk [options] 'pattern{action}' file
        ip addr | grep ens33$ | awk '{print $2}' | awk -F/ '{print $1}'
        -F，用于指定输入分隔符
        -v，用于设置变量的值
    9.  计算    +-/*%
        expr 1 \* 21454646
        expr 1 + 1231
        A=`expr 1 \* 21454646`
        echo $((1*1231))
        echo $((1+1))
        echo $[1*11]
        let a=1+2
        echo $a

        >  -gt
        <  -lt
        >= -ge
        <= -le
        == -eq

        A=( 1 2 3 )
        ${A[0]}
        unset A[3]  删除数组
        ${#A[*]} 数组长度
        ${A[@]}  数组所有元素
    10. Windows：
            绝对路径：是从盘符开始的路径，形如C:\windows\system32\cmd.exe
            相对路径：是从当前路径开始的路径，如当前路径为C:\windows，要描述上述路径，只需输入 system32\cmd.exe 。
        Linux：
            绝对路径：  /root/test/A/1.txt
            相对路径：  test/A/1.txt
        etc 目录下存放系统和应用配置文件

        linux系统将设备与文件关联称为 “挂载”
        service mariadb start 启动某项服务
        service mariadb stop  停止某项服务
        service mariadb restart   重启某项服务
        service mariadb status   查看某项服务状态
        systemctl stop firewalld    关闭防火墙
        systemctl disable firewalld    禁用防火墙
        crontab -e
        * * * * * /root/test16.sh
        分时天月周
    11. shell脚本

        -f  文件
        -d  目录
        -e  路径
        -l  链接
        -x  执行
        -y
        -w

        #!/bin/bash     //# 注释
        ls
        cat 1.c
        echo "------------------------"
        cal


        #!/bin/bash
        for i in {1..20}
        do
            ./4 <<EOF           //EOF前后不允许有任何空格 除了#都可以用，只要保证前后一致
            $i 10
        EOF
        done

        #!/bin/bash     //统计/etc/passwd，中shell次数，shell是指后面的/bin/bash，/sbin/nologin等
        awk -F: '{
            A[$NF]++;
        }END{
            for( i in A )
                {
                    printf("%s %d\n",i,A[ i ]);
                }
        }' /etc/passwd

        #!/bin/bash
        read A
        C=()
        for(( i=0;i<$A;i++ ))
        do
            read B
            let C[$i]=B
        done
        echo ${#C[*]}
        echo ${C[*]} | tr -d " "

        #!/bin/bash
        echo $0 脚本自身的名称
        echo "第一个参数：$1"
        echo "第二个参数：$2"
        echo "参数个数：$#"
        echo "所有参数：$@"
        $*:  传入脚本的所有参数；
        $$:  脚本执行的进程id；
        function ABC()
        {
            A=323
            echo $1
            echo $2
            return 19
        }
        ABC 213 sdsbh
        echo $?

        ./test13.sh 123 456 2 2 22 2 2 2
        ./test13.sh
        第一个参数 123
        第二个参数 456
        参数个数 8
        123 456 2 2 22 2 2 2
        213
        sdsbh
        19

        #include<iostream>
        #include<mysql.h>
        #include<string.h>
        using namespace std;

        MYSQL *conn = nullptr;

        void search_menu(const char* parent_id, const char * space)
        {
            char buffer[128] = {0};
            sprintf(buffer, "SELECT * FROM t1_menu WHERE parent_id=%s", parent_id);

            mysql_query(conn, buffer);
            MYSQL_ROW row;

            MYSQL_RES *res = mysql_store_result(conn);
            while( res != nullptr && (row = mysql_fetch_row(res)) != nullptr)
            {
                cout << space << row[1] << endl;
                if ( strcmp("0", row[3] ) == 0 ) {
                    char mark[32] = {0};
                    strcpy(mark, space);
                    strcat(mark, "|----");
                    search_menu(row[0], mark);
                }
            }
            mysql_free_result(res);
        }

        int main()
        {
            int i = 0;
            conn = mysql_init(nullptr);
            mysql_real_connect(conn,"127.0.0.1","root","123456","2202",0,nullptr,0);

            mysql_query(conn,"set charset utf8");
            search_menu("0", "");

            mysql_close(conn);

            return 0;
        }


        //扫描当前目录下所有.txt结尾的文件，但每次列出10个文件，提示是否要删除这10个文件。
        //若选择不是则不删除，并继续显示下10个文件询问提示。
        //若选择是则删除，并继续显示下10个文件询问提示。
        #!/bin/bash
        A=0
        B=()
        for i in temp/*.txt
        do
            B[$A]="$i"
            A=$[A+1]
            if [ $A -gt 9 ]
            then
                echo "${B[*]}"
                echo -n "是否要删除以上10个文件(Y/N)?"
                read N
                if [ "$N" = "Y" ]
                then
                    rm -rf ${B[*]}
                fi
                A=0
                B=()
            fi
        done
        echo "${B[*]}"
        echo -n "是否要删除以上文件(Y/N)?"
        read N
        if [ "$N" = "Y" ]
        then
            rm -rf ${B[*]}
        fi

    12. 磁盘管理
        df -h   查看磁盘空间使用情况
        mount -t auto /dev/cdrom /mnt/2202  将光驱和2202文件夹关联2
        umount /mnt/2202
        cdrom 光驱
        sdb  U盘
        fdisk -l 查看当前链接到系统的磁盘和设备
    13. ftp
        ftp [-v] [-d] [-i] [-n] [-g] [-s:filename] [-a] [-w:windowsize] [computer]
        ls/dir 显示目录文件
        lcd 改变本地目录
        cd 改变ftp服务器目录
        get 下载
        put 上传
        mget 多个文件下载
        mput 多个文件上传
        delete 删除
        prompt on/off 是否关闭确认提示
        -v  禁止显示远程服务器相应信息
        -n  禁止自动登录
        C:\Users\Administrator>ftp -n 192.168.65.131
        连接到 192.168.65.131。
        220 **************Welcome to blah vsFTP service.**************
        C:\Users\Administrator>ftp -nv 192.168.65.131
        ftp> user dylan dylan
        ftp> dir
        drwxrwxr-x    2 502      504          4096 Dec 07 15:36 ftp
        -rw-rw-r--    1 502      504             0 Dec 07 15:35 hello.txt
        -i   多文件传输过程中关闭交互提示
            使用前
                ftp> mget *.txt
                mget hello.txt? n
            使用后
                ftp> mget *.txt
        注意：单文件传输不影响
        -d  启用调试，显示所有客户端与服务器端传递的命令
        -g  禁用文件名通配符，允许在本地文件和路径名中使用
        -s:filename 指定包含 FTP 命令的文本文件；命令在FTP启动后自动运行。此参数中没有空格。可替代重定向符（>）使用。
        -a  在绑字数据连接时使用所有本地接口
        -w:windowsize 覆盖默认的传输缓冲区大小 65535。
        computer  指定远程电脑计算机名或IP地址。此参数必须放到最后。
    14. sed
        sed -i 's/=enforcing/=disabled/g' /etc/selinux/config   关闭安全策略
        sed -i -n '1p' 222.txt  删除第一行以外的内容
        sed -n '1p;3p' 111.txt  分别显示第一行和第三行
        sed -n '1,3p' 111.txt   连续显示第一行到第三行
        sed -n '/1/p' 111.txt   查询包含1的行数，并输出
        sed '1,3d' 111.txt   删除第一行到第三行，输出剩下的
        sed 's/1/Hello/g' 111.txt   字符串替换,将1替换为Hello
        sed '1aHello' 111.txt   在第一行之后加上Hello
        sed '1iHello' 111.txt   在第一行之前加上Hello
        sed '/1/iHello' 111.txt    在匹配到的行之前加上Hello
        sed '/1/aHello' 111.txt    在匹配到的行之后加上Hello
    15. awk
        awk -F, '{print $1}' data.txt   以,分隔，输出第一列的数据
        awk -F, '{printf("%s,%s,%s\n",$3,$1,$2)}' data.txt
            20,aaa,男           以,分割字符串，以,为间隔按指定次序输出
            16,bbb,女
        awk -F, '{printf("%s|%s|%s\n",$3,$1,$2)}' data.txt
            20|aaa|男           以,分割字符串，以|为间隔按指定次序输出
            16|bbb|女
        awk -F, '{print $(NF-1)}' data.txt     NF是行数，NR是当前列数

三、常用软件
    vi/vim 文本编辑器
    gcc 编译器
    wget 下载器
    tree 树状显示目录
四、vim使用指南
    [O]pen Read-Only,     只读
    (E)dit anyway,        编辑
    (R)ecover,  恢复(异常情况退出，可以恢复)
    (D)elete it,        删除
    (Q)uit,         退出
    (A)bort:

*/find /root/ -name \*.sh | awk '{match(^\/(\w+\/)+$)}' '{print $1}'

g++ Linux_Socket.cpp MySocket.cpp MySocket.h -pthread -o socket.exe

