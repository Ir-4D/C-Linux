//类的概念：类是具有共同属性(成员变量)和方法(成员函数)的集合
//QT笔记
//D:\QT\参考资料\QT_核心原理及设计.txt
/*一、C++结构体
	1.	C++结构体可以加入成员函数
	2.	C++结构体可以继承
		(1)继承之后成员变量属于并列关系
		(2)继承是单向的
		(3)继承可以有多个父结构体，称为多继承
	3.	C++结构体可以加权限(三大权限)，结构体默认公有权限
		(1)公有：public	(谁都可以用)
		(2)私有：private (自用)
		(3)受保护的：protected (自己，子类/结构体可用)
*/

/*二、类
	1.	类默认私有权限
	2.	类的继承通过已有类产生新类的过程
		(1)一旦继承，派生类拥有基类的完整对象
		(2)一个父类，单继承；两个或更多父类，多继承
		(3)实例化是如何执行的
			先进后出(栈的顺序)，多父类：从左到右深度优先，
			先实例化父类，再到子类，
			析构时先析构子类，再析构父类
		(4)一个派生类继承了所有的基类方法，但下列情况除外：
			基类的构造函数、析构函数和拷贝构造函数。
			基类的重载运算符。
			基类的友元函数
		(5)委托构造
		(6)友元，拷贝构造，析构，重载没有被继承
		具体参考：F:\CPP\day10\3.cpp
	3.	new与malloc
		new是动态分配内存，产生类类型指针，内部使用malloc来分配内存，
			还会调用类的构造函数来初始化成员变量，释放使用delete
		malloc只分配，不初始化，返回void*类型指针，释放使用free
		真正的区别：
			1.new初始化，malloc不初始化
			2.new返回类类型指针，malloc返回类型不确定
			3.new,delete都是运算符，malloc,free都是函数
	具体参考：F:\CPP\day1\test_struct_0422\test_struct_0422\test_struct_0422.cpp
	4.	构造函数：给属性赋初值(初始化属性)
		写法：函数名和类名一致，无返回值类型
		类自带：无参构造，若以自定义，则会覆盖掉默认的
	5.	类的添加以及析构函数
	具体参考：F:\CPP\day4\test_class_0425\test_class_0425\my_class.h
	6.	实例化：由抽象到具体的过程
		结果：产生一个实例，即对象
	7.	(1)什么情况下一定要重新实现拷贝构造
		类带有指针变量，并有动态内存分配时，需要重新构造
		系统默认的构造函数使用值传递，导致多个构造函数共用一块内存，
		(2)拷贝构造函数时，不加引用(&)传参时，会导致多次构造
	具体参考：F:\CPP\day5\1.cpp
	8.	对象赋值：
		重载运算符：改变符号(=)的原功能
		无法重载的符号：
			.   成员访问运算符
			.*, ->*  成员指针访问运算符
			::  域运算符
			sizeof  长度运算符
			?:  条件运算符
			#   预处理符号

		关键字：operator 符号
			A& / void operator = (const A &a)
			{
				a = x.a; //对属性的转移赋值
			}
		重载：目的：实现静态多态，不能继承
		概念：在同一个作用域，函数名一样，参数不一样
			在编译时，根据实参确定调用，所以才叫静态多态
			(1)参数类型不一样
			(2)参数个数不一样
			执行时才确定，叫做动态多态
			使同一函数执行不同功能
		this：代表当前对象地址
	具体参考：F:\CPP\day5\2.cpp
	8.	多态性
		重写：virtual
		重载：(同一作用域)
		重定义：子类重新实现父类中的非虚函数
		(1)静态多态
			通过重载来实现
			编译时根据实参的不同来确定，叫做静态多态
		(2)动态多态
			通过重写来确定
			执行时才确定，叫做动态多态
		F:\CPP\day13\2.cpp
		virtual 修饰成员函数，使其变成虚函数，在继承时才有效
		如果父类不用指针，能产生动态多态效果么？(一个接口，多个实现)
			如果要产生多态效果，先是虚函数，再用父类指针指向子类对象，
			接着再用指针调用被重写的方法
		虚函数
			是在基类中使用关键字 virtual 声明的函数。
			在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
				我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，
				这种操作被称为动态链接，或后期绑定。
			继承时，子类必须重写该纯虚函数
		虚函数表
			表：有虚函数的类里面才会存在，属于类的
			作为第一个属性存的： --vfptr 4字节
			
		抽象类
			接口描述了类的行为和功能，而不需要完成类的特定实现。
			C++ 接口是使用抽象类来实现的，抽象类与数据抽象互不混淆，
				数据抽象是一个把实现细节与相关的数据分离开的概念。
			如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。
				纯虚函数是通过在声明中使用 "= 0" 来指定的，
		
		C++中基类的析构函数为什么要用virtual虚析构函数？
			直接的讲，C++中基类采用virtual虚析构函数是为了防止内存泄漏。
			具体地说，如果派生类中申请了内存空间，并在其析构函数中对这些内存空间进行释放。
			假设基类中采用的是非虚析构函数，当删除基类指针指向的派生类对象时就不会触发动态绑定，
			因而只会调用基类的析构函数，而不会调用派生类的析构函数。那么在这种情况下，
			派生类中申请的空间就得不到释放从而产生内存泄漏。
			所以，为了防止这种情况的发生，C++中基类的析构函数应采用virtual虚析构函数。

	9.	类默认函数
		(1)空构造函数
		(2)析构函数
		(3)拷贝构造函数				//动态指针属性
		(4)重载等号(=)赋值函数		//需要重新构造
		(5)重载取地址(&)
		(6)const重载取地址(&)
	10.	函数指针
			函数指针，其本质是一个指针变量，该指针指向这个函数。总结来说，函数指针就是指向函数的指针。
			声明格式：类型说明符 (*函数名) (参数)
			去掉标识符之后剩下的就是类型
		具体参考：F:\CPP\day12\3.cpp
				 F:\CPP\day13\1.cpp
		指针函数
			指针函数，简单的来说，就是一个返回指针的函数，其本质是一个函数，而该函数的返回值是一个指针。
			声明格式为：类型标识符 *函数名(参数表)

			如：
				int f(int x,int y); //返回一个int类型的结果，是一个值

				int* f(int x,int y); //返回一个 int* 的指针，也就是地址

				当然，指针函数有好几种写法：
				int *f(int x,int y);
				int * f(int x,int y);
				int* f(int x,int y);
				以上三种方式都表示函数返回一个 int* 的指针，第三种更直观一些。
*/

/*三、C++中基本内置类型(算术类型和空类型)
	1.	算术类型：
		类型		含义			最小尺寸	所占字节
		bool		布尔型			-				1
		char		字符型			8 bit			1
		wchar_t		宽字符型		16 bit			2
		short		短整型			16 bit			2
		int			整形			32bit			4
		long		长整型			32 bit			4
		long long	长整型			64 bit			8
		float		单精度浮点型	7位有效数字		4
		double		双精度浮点型	16位有效数字	8
		long double	扩展精度浮点型	19位有效数字 	8
		除去布尔型和扩展的字符型之外，其他整型可以划分为带符号的和无符号的两种。
		带符号类型可以表示正数、负数和0，无符号类型则仅能表示大于等于0的值。
		类型int、short、long和long long都是带符号的，
		通过在这些类型名前添加unsigned就可以得到无符号类型，
		例如unsigned long。类型unsigned int可以编写为unsigned。
	具体参考：F:\CPP\day2\test_sizeof_0423\test_sizeof_0423\test_sizeof_0423.cpp
	2.	空类型，即void类型
		void类型：常用在程序编写中对定义函数的参数类型、返回值、函数中指针类型进行声明。
		可以表示一种未知类型，不能代表一个真实的变量。
		void a; //错误
		void function(void a); //错误
		void function(void); //正确
		void* ：则为“无类型指针”，可以指向任何类型的数据，可以将任意类型的指针直接赋值给void指针
	3.	其他类型：数组、引用、指针等
		(1)数组
			数组允许定义可存储相同类型数据项的变量，
			但是结构是 C++ 中另一种用户自定义的可用的数据类型，
			它允许您存储不同类型的数据项。
			如结构体struct、联合体union、枚举enum 、类class及STL容器。
			数据结构可以当类型(自定义类型)
		(2)引用：引用式别名，不开辟新内存，有指针效果，就是对象本身
				int a = 5;			int a = 5;
				int &b = a;			int *b = &a;
				//左边是引用		//右边是取地址符号
				b = 6;	//a = 6		*b = 6;	//a = 6
				cout << a;			cout << a;
			引用和指针的区别
				I.引用省内存(引用不开辟新内存)
				II.引用比指针安全(野指针，踩内存)
				III.引用比指针高效
			左值引用(&)与右值引用(&&)的区别
				在C++11中可以取地址的、有名字的就是左值，反之，不能取地址的、没有名字的就是右值（将亡值或纯右值）。

	具体参考：F:\CPP\day2\1.cpp
*/

/*四、C++函数
	1.	友元函数：
		(1)类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
			尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
		(2)友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，
			在这种情况下，整个类及其所有成员都是友元。
		(3)如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend，
			友元函数会破坏封装性。
	2.	友元类：
		一旦一个类变成另一个类的友元类之后，该类的所有成员函数都是另一个类的友元函数
	3.	友元函数和友元类都是单向不可继承的，在类的任何位置声明都可以
	4.	内联函数：提高执行速度，减少栈内存，提高运行速度
		(1)C++ 内联函数是通常与类一起使用。如果一个函数是内联的，
			那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。
		(2)对内联函数进行任何修改，都需要重新编译函数的所有客户端，
			因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。
		(3)如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 inline，
			在调用函数之前需要对函数进行定义。如果已定义的函数多于10行，
			编译器会忽略 inline 限定符。
		(4)在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。
			尽量在类内声明，类外定义，有需要时根据算法复杂度手动加inline
			特别是项目代码，尽量都非内联
		(5)代码膨胀：太多内联函数，且算法复杂，有很多调用
			解决方法：去掉没必要的内联函数
			inline只是建议内联函数，但是不一定会内联
	5.	this指针
		(1)this表示当前对象首地址
		(2)非静态成员函数内部都可以用
		(3)好处：
			区分变量作用域<特别是有同名局部变量>
			能快速提示
	6.	static静态
		产生内存：一次
		存放位置：静态存储区
		生命周期：程序开始时产生，程序结束时释放
		在类内：静态成员
				(1)变量：静态属性(类)：
					在全局作用域进行初始化
					所有对象共用静态属性
				(2)函数：
					只能使用静态成员

*/

/*C++语法习惯
	1.	C 用 0 表示 假，!0 表示 真
		C++ 用 false 表示 假，ture 表示 真
	2.	cin输入,cout输出
		int a,b,c;
		cin >> a;		cout << a;
		cin >> b;		cout << b;
		cin >> c;		cout << a << b << c << endl;
	3.	文件命名规则
		3.1.MyClass 大驼峰：所有单词首字母都大写
			myClass 小驼峰：首单词首字母小写
			my_class 凹驼峰：所有单词小写，多个单词用下划线连接
		3.2.文件名全部小写，可以含下划线或连字符，按项目约定命名,且尽量保证文件名明确。比如：
			cmd_save_player_info_class.cc my_use_full_class.cc
			定义类的文件名一般是成对出现，如：foo_bar.h foo_bar.cc
			若是类中含大量内联函数，我们还可使用-ini.h文件，使之文件内容更加清晰，于是又如：
			url_table.h url_table.cc url-table-ini.h
		3.3.类命名规则
			类型命名每个单词首字母大写，不含下划线，以名词形式。比如： MyPlayerManager，这对于所有类型命名一样，类结构体，枚举，类定义都是如此，比如：MyExcitingEnum
		3.4.变量命名规则
			变量名一律小写，单词用下划线相连，例如：
			int player_id; string table_name;
			特殊的是类成员变量，后跟下划线区别普通变量，比如： player_name_ player_id_   m_player_name_play_id
			全局变量则以 g_ 开头，比如 ： g_system_time
			当然结构体成员变量还是和普通变量一样,比如：string name; int num_entries;
			前缀	说明
			无	局部变量
			m_	类的成员变量(member)
			sm_	类的静态成员变量(static member)
			s_	静态变量(static)
			g_	外部全局变量(global)
			sg_	静态全局变量(static global)
			gg_	进程间共享的共享数据段全局变量(global global)
		3.5.常量命名规则
			由全大写字母组成，单词间通过下划线来界定，比如：
			const int DAYS_IN_A_Week=7;
			const string COMPANY_NAME=”Tecent”;
		3.6.函数命名规则
			常规函数每个单词首字母大写，使用命令式语气，比如：OpenFile() CheckFileName()，
			而存取函数或短小的内联函数使用小写加下划线，且与访问变量相吻合，比如 set_num_errors();
			class Player
			{
				public:
					void set_player_id(const int player_id){return player_id_=player_id;}
					int get_player_id() const{return player-id_;}
					private:
					int player_id_;
			};
		3.7.名字空间命名
			命名空间全小写，并基于项目名称和目录结构，比如
			google_awesome_project
		3.8.枚举命名规则
			枚举类名属于类型名，按类命名，枚举值全大写加下划线，比如：ENUM_NAME
		3.9.宏变量命名规则
			如果你一定要用到宏，全大写加下划线，比如：
			define PI_ROUND 3.0
	4.	函数出参，入参
		规则：已有的遵守惯例(出参，入参)
			自定义的遵守I/O顺序(入参，出参)
	5.	C++介绍
		泛型编程：用到模板，模板类型不确定，可以随便指定类型，一旦指定，特化为特定类型
		封装：使用权限修饰符来对类成员进行访问权限的限制，一般成员变量设为私有，成员
			函数设为公有，而受保护是为了继承引入的目的是让子类可以访问父类中别人看不见的东西
		继承：通过已有类(父类/基类)产生新类(子类/派生类)的过程
		多态性：多种形态：同一个接口，多个功能
			API：Application Programming Interface,应用程序编程接口：函数
				纯虚函数：只声明，不定义
				virtual void test() = 0;(父类)
			写函数体 子类把接口实现
			(1)动态多态：(重写)
				子类重新实现父类中的虚函数
				重写：在执行时，用父类指针指向子类对象时
					父类指针——>被重写函数调用()
					其实执行的是子类中函数中的函数体
			(2)静态多态：(重载)
				在同一作用域中，函数名一样，参数不一样（个数不一样，类型不一样）
				重载：在编译时，根据实参来确定调用

	7. 	调试	F5
		逐语句(F11)：遇见函数会进入
		逐过程(F10)：遇见函数会跳过
		跳出(shift+F11)：返回到上级函数调用的后面<执行到返回>
		重启(ctrl+shift+F5)
		停止(shift+F5)
		this：指针(代表当前对象的首地址)
*/

/*STL模板库
	F:\CPPSTL.txt
	1.	string
		string:npos是个特殊值，说明查找没有匹配
	2.	vertor
	3.	list
	4.	map
	5.	deque 双端队列
	F:\CPP\day23\deque.cpp
	6.	queue 普通队列
		在尾部添加，在头部删除
		不能使用迭代器遍历
	F:\CPP\day23\queue.cpp
	7.	lambda表达式   c++11标准
		[=](int a,int b)->bool
		{
			return a>b;
		}
		[=]表示对作用域内的值进行传值，类似值传递
		[&]表示对作用域内的值进行引用，类似址传递
	F:\CPP\day23\deque.cpp
	8.	智能指针
		#include <memory>
		自动管理动态内存申请的存储
		F:\CPP\day25\memory.cpp
		(1)unique_ptr
			F:\CPP\day25\unique_ptr.cpp
		(2)share_ptr
			多个指针可以指向共享，内部有引用计数
		(3)weak_ptr	
		(4)auto_ptr
			待删除
		F:\CPP\智能指针.txt
	9.	仿函数
		(1)#include <functional>
		(2)仿函数(functor)，就是使一个类的使用看上去像一个函数。
			其实现就是类中实现一个operator()，
			这个类就有了类似函数的行为，就是一个仿函数类了。
		(3)	plus			加
			minus			减
			multiplies		乘
			divides			除
			modulus			取模
			negte			取反
			equal_to		==
			not_equal_to	!=
			greater			>
			less			<
			greater_equal	>=
			less_equal		<=
		F:\CPP\day26\fang.cpp
	10.	时间函数
 */
/*五、C++流
	istream / ostream
	1.	文件
		#include <fstream>
		(1)ifstream
		(2)ofstream
		F:\CPP\day23\fstream.cpp
	2.	字符
		#include <sstream>
		(1)istringstream
		(2)ostringstream
		F:\CPP\day23\istringstream.cpp
	3.	IO
		#include <iostream>
		(1)cin
		(2)cout
 */

/*六、正则表达式
	#include <regex>
	?  		表示出现1次或者0次
    \d 		表示数字
    \w 		表示字母(不区分大小写)，数字，下划线
    +		匹配一次或者多次
    ()		感兴趣的内容，不加括号不保存
    $		末尾
    [,;|]|$	结束符号
    []		表示取值范围
    {m}		表示必须是m个
	{m,}	表示至少m个
	{m,n}	表示取值为大于m,小于n
    .  表示任意字符  .+表示任意长度任意字符
	F:\CPP\day24\regex.cpp
 */

/*七、高级编程
	1.	线程
	F:\CPP多线程.txt
	2.	异常处理
	#include <exception>
	try
	{
		//
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	3.	静态链接库
		静态库（Static Library）通常包含某些变量和函数，在编译期间由编译器和链接器将它编译到目标文件中，目标文件可以是exe或都dll。
		静态库的表现形式在Windows中常以.lib结尾，在Linux系统中以.a结尾。
		优点：发布时只需发布.exe文件，因为库已经集成到可执行文件中，运行时不再依赖库。
		缺点：静态库编译到目标文件中，导致目录文件较大，同时，如果后续升级静态库后必须重新编译目标文件
		(1)	如果没放到项目下，需要在   "项目->属性->C/C++->常规->附加包含目录"   中添加.h文件路径
			在   "项目->属性->链接器->常规->附加库目录"   中添加.lib文件路径
			在   "项目->属性->链接器->输入->附加依赖项"   中添加.lib文件
		(2)	如果.h与.lib文件放置在项目路径下，只需要在主程序中添加#include"头文件.h"
			在   "项目->属性->链接器->输入->附加依赖项"   中添加.lib文件
 */
/*文件
	1.	文件操作
		(1)向文件写数据
		头文件#include <ofstream>
		　　①Create an instance of ofstream(创建ofstream实例)
		　　②Open the file with open() or ofstreamconstructor (用open()或者构造函数打开文件)
		　　③Writedata to the file with "<<" (用流插入运算符写数据)
		　　④Close the file (explicitly close()) (显式地使用close()函数关闭文件)
			若文件已存在，内容被直接清除。
		(2)从文件读数据
		头文件#include <ifstream>
		　　①Create an instance of ifstream(创建ifstream对象)
		　　②Open the file (use open() or ifstreamconstructor) (用open()函数或构造函数打开文件)
		　　③Read data from the file with ">>" (用流提取运算符从文件读数据)
		　　④Close the file (explicitly using close() ) (显式调用close()函数关闭文件)
		(3)格式控制
		头文件#include <iomanip>
			①setw(width) 设置域宽
			　　setw()控制符只对其后输出的第一个数据有效，其他控制符则对其后的所有输入输出产生影响。
			　　默认为setw(0)，按实际输出。
			　　如果输出的数值占用的宽度超过setw(int n)设置的宽度，则按实际宽度输出。
			②setfill(c) 
			　　设置填充字符，即“<<"符号后面的数据长度小于域宽时，使用什么字符进行填充。
			③setprecision(int n)
			　　可以控制显示浮点数的有效位
			　　n代表数字总位数
			　　setprecision(0)的效果取决于编译器。不同编译器的实现是不同的。
			④showpoint
		　　	将浮点数以带小数点、带结尾0 的形式输出，即便它没有小数部分
			⑤left　　输出内容左对齐
				right    输出内容右对齐  
			⑥getline
		　　	getline(chararray[], intsize, chardelimitChar) //要写入的数组，大小，分隔符
		　　	因为 >>运算符要求数据用空格分隔
		(4)文件打开模式

			fstream= ofstream+ ifstream
			　　ofstream: write data
			　　ifstream: read data
			Mode　　 　　Description
			ios::in 　　Opens a file for input. 读模式
			ios::out 　 Opens a file for output. 写模式
			ios::app 　Appends all output to the end of the file. 追加模式
			ios::ate 　 Opens a file for output. If the file already exists, move to the end of the file. Data can be written anywhere in the file.
			　　　　　　打开文件用于输出。若文件存在则光标移至文件尾部。数据可以在任意位置写入
			ios::truct   Discards the file’s contents if the file already exists. (This is the default action for ios:out).
			　　　　　　 若文件存在则丢弃其内容，这是ios:out的默认方式
			ios::binary Opens a file for binary input and output.打开文件以二进制模式读写
			模式组合： |
			　　Eg：stream.open("state.txt", ios::out | ios::app);
		(5)测试流状态
			流状态位 (Stream State Bit):These bit values (0or 1) indicate the state of a stream. (比特值指示流的当前状态)
			Bit 　　　　　　When to set
			ios::eofbit 　　Set when the end of an input stream is reached. 到达文件末尾时
			ios::failbit 　　Set when an operation failed. 操作失败时
			ios::hardfail 　Set when an unrecoverable error occurred. 遇到不可恢复的错误时
			ios::badbit 　  Set when an invalid operation has been attempted. 试图进行非法操作时
			ios::goodbit 　Set when an operation is successful. 操作成功时
			流状态函数(Stream State Functions)
			Function　　 Description
			eof() 　　　　Returns true if the eofbit flag is set.
			fail() 　　　　Returns true if the failbit or hardfail flags is set.
			bad() 　　　  Returns true if the badbit is set.
			good() 　　　Returns true if the goodbit is set.
			clear() 　　　Clears all flags.
		(6)二进制读写
			文本文件与二进制文件，都按二进制格式存储比特序列
				text file : interpretedas a sequence of characters (解释为一系列字符)
				binary file : interpretedas a sequence of bits. (解释为一系列比特)
			ios::binary以二进制模式打开文件
			文本模式读写函数
			　　write: <<operator; put()
			　　read : >>operator; get(); getline()
			二进制模式读写函数
			　　write: write();　　streamObject.write(char* address, intsize)　　
			　　read : read();　　streamObject.read(char * address, intsize)
			将任意类型数据写入文件：转换为字节流，write进去。
			reinterpret_cast<dataType>(address)　　//将数据的地址转换为为字符类型指针用于二进制读写
		(7)seekp, seekg, tellp, tellg
			seek: 移动文件指针
			tell:获取文件指针位置
			p: put，表示操作输出文件中的指针
			g: get，表示操作输入文件中的指针
			Seek Base 　　Description
			ios::beg 　　Calculates the offset from the beginning of the file.
			ios::end 　　Calculates the offset from the end of the file.
			ios::cur 　　 Calculates the offset from the current file pointer.
	2.	文件流
		ofstream 	该数据类型表示输出文件流，用于创建文件并向文件写入信息。
		ifstream 	该数据类型表示输入文件流，用于从文件读取信息。
		fstream 	该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，
					这意味着它可以创建文件，向文件写入信息，从文件读取信息。
		open()
			open函数的参数定义了文件的打开模式。总共有如下模式
			属性列表
			ios::in 读
			ios::out	写
			ios::app	从文件末尾开始写
			ios::binary 二进制模式
			ios::nocreate	打开一个文件时，如果文件不存在，不创建文件。
			ios::noreplace	打开一个文件时，如果文件不存在，创建该文件
			ios::trunc	打开一个文件，然后清空内容
			ios::ate	打开一个文件时，将位置移动到文件尾
		istream 和 ostream 都提供了用于重新定位文件位置指针的成员函数。
			这些成员函数包括关于 istream 的 seekg（"seek get"）
			和关于 ostream 的 seekp（"seek put"）。
		seekg 和 seekp 的参数通常是一个长整型。第二个参数可以用于指定查找方向。
			查找方向可以是 ios::beg（默认的，从流的开头开始定位），
			也可以是 ios::cur（从流的当前位置开始定位），
			也可以是 ios::end（从流的末尾开始定位）。
*/

/*Git
	git init
	git add *.* 将内容从工作目录添加到暂存区（或称为索引（index）区），以备下次提交。
	git commit 提交到本地库
	git reset
	git push 给服务器提交
	git clone ssh://admin@192.168.31.192:29418/LZQ.git 将服务器的库拷贝一份到本地空文件夹
	git分支：每个分支都可以管理一个版本库
	git branch 分支名  创建分支
	git branch -a  查看分支
	git checkout 分支名  切换分支
	git merge 分支名  将指定分支合并到当前目录
TCP/UDP
	TCP与UDP的区别：
		1.基于连接与无连接；
		2.对系统资源的要求（TCP较多，UDP少）；
		3.UDP程序结构较简单；
		4.流模式与数据报模式 ；
		5.TCP保证数据正确性，UDP可能丢包，TCP保证数据顺序，UDP不保证。

*/
/*QT
一、QT三大核心机制
	1.	信号——槽
	2.	元对象
	3.	事件模型
二、槽函数与成员函数的区别
	1.	声明上的区别：槽函数的声明上面加slots(关键字)
	2.	只有槽函数才可以和信号连接且生效
	bool QObject::connect ( const QObject * sender, const QMetaMethod & signal, const QObject * receiver, const QMetaMethod & method, Qt::ConnectionType type = Qt::AutoConnection )
		4种写法						信号发出者				信号						信号接收者					槽函数						(5种)连接方式

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(myslots()));
		(1)宏： SIGNAL()   SLOT()
			connect(this,SIGNAL(my_signals()),this,SLOT(my_slot()));
		(2)函数指针： &类名::函数名(只适合无重载时用)
		    connect(this,&MainWindow::my_signals,this,&MainWindow::my_slot);
		(3)重载的函数指针： QOverload<参数类型...>::of(&类名::函数名)
		    connect(this,QOverload<>::of(&MainWindow::my_signals),this,QOverload<>::of(&MainWindow::my_slot));
		(4)用匿名函数取代槽： [](参数) 类型{...} 匿名函数相当于函数指针
		    connect(this,QOverload<>::of(&MainWindow::my_signals),this,[=]{qDebug() << "4445456" << endl;});
	信号：只有声明，没有实现，声明时要加signals
		拥有信号的类的对象才可以作为发出者
	槽：有声明，需加slots
	发射信号：emit my_signal();
	3.	5种连接方式
		0，Qt::AutoConnection，自动<自动匹配模式>
		1，Qt::DirectConnection，直接
		2，Qt::QueuedConnection，队列<单线程，多线程都行>
		3，Qt::AutoCompatConnection，阻塞队列<只能多线程>
		0x80，Qt::UniqueConnection，唯一连接<防止重复连接>
	4个参数，第5个连接方式不写默认0，自动连接
	4.	Qt对象模型(对象树)
	父子对象关系
		只需在实例化时，指定好所属父对象，当释放父对象时，其所有子对象也会
		一起释放，自定义对象指针如何自动释放?
			(1)实例化时直接指定父指针
			(2)用成员函数setParent(父指针)

*/

//#pragma once    //只编译一次

#include "pch.h"
#include <iostream>
#include <stdio.h>
struct M
{
	int a;
	int b;
	void get()
	{
		printf("%d\n,%d\n", a, b);
	}
};
int main()
{
	M m1;
	m1.a = 5;
	m1.b = 6;
	m1.get();

}
