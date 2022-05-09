//1.需要头文件<mysql.h>
#include <iostream>
#include<mysql.h>

using namespace std;
//2.设置项目路径
//具体可参考文件 第三卷 数据库开发_B站版.wps
/*
①点击项目属性，
②选择VC++目录，给包含目录加入mysql路径:C:\Program Files\MySQL\MySQL Server 8.0\include
给库目录加入路径：C:\Program Files\MySQL\MySQL Server 8.0\lib
③选择链接器的输入，给附加依赖项加入：libmysql.lib
*/
void test();
int main()
{
    test();
    getchar();

    return 0;
}
void test() {
    cout << "test!" << endl;
    
    /***********************
    *通用部分
    * 
    ************************/
    MYSQL m;//mysql连接
    MYSQL_RES* res;//查询结果集
    MYSQL_ROW row;//二维数组，存放数据

    //初始化数据库
    mysql_init(&m);

    //设置编码方式
    mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");
    
    //连接数据库  
    if (mysql_real_connect(&m, "localhost", "root", "Malzahar001", "addr_list", 3306, NULL, 0)) {
        //主机，用户名，密码，数据库名，端口
        cout << "数据库连接成功" << endl;
    }
    else {
        cout << "数据库连接失败：" << mysql_error(&m) << endl;//输出错误信息
    }
    /***********************
    *具体部分
    *
    ************************/
    //1.向数据库插入数据
    /*    const char* sql01 = "insert into admini_list values(3,'chen1','1')";
    if (mysql_query(&m, sql)) {  //插入失败，则返回1，成功返回0
        cout << "插入数据失败"<<mysql_error(&m) << endl;
    }
    else {
        cout << "插入数据成功" << endl;
    }
    */

    //2.删除数据
    /*    const char* sql02 = "delete from admini_list where id=3";
    if (mysql_query(&m, sql02)) {
        cout << "删除失败" << mysql_error << endl;
    }
    else {
        cout << "删除成功" << endl;
    }

    */

    //3.更新数据
    /*    const char* sql03 = "update admini_list set AdminiName=1000 where id=1000";
    if (mysql_query(&m, sql03)) {
        cout << "更新失败" << mysql_error << endl;
    }
    else {
        cout << "更新成功" << endl;
    }
    */

    //4.查询数据
    const char* sql04 = "select * from admini_list";
    if (mysql_query(&m, sql04)) {
        cout << "未查到记录" << mysql_error << endl;
    }
    else {
        cout << "查到记录" << endl;
    }

    //5.根据用户名和密码获取用户信息(id,level_id)
    //snprintf给sql赋值字符串语句，内含账号与密码
    //user.username需要用c_str()由字符串string转换为char*型
    /*    
    char sql[256];
    snprintf(sql, 256, "select * from Admini_list where AdminiName='%s' and password='%s';", 
        Admini.AdminiName.c_str(), Admini.password.c_str());
    if (mysql_query(&m, sql)) {
        cout << "未查到记录" << mysql_error << endl;
    }
    else {
        cout << "查到记录" << endl;
    }
    */
    /***********************
    *通用部分
    *
    ************************/
    //获取查询结果集
    res = mysql_store_result(&m);
    cout<<"id\tAdminiName\tpassword" << endl; //输出记录的模式
    while (row = mysql_fetch_row(res)) { //row循环获取整个记录的每一个行（从上到下）
        cout << row[0] <<"\t" << row[1] << "\t\t" << row[2] << endl; //输出改行的每一项
    }

    //释放资源
    mysql_free_result(res);//释放结果集
    mysql_close(&m);//关闭数据库
}