#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
using namespace std;

class VIP
{
private:
    string Name;
    string Tele;
public:
    static bool IsVIP(const string& tele); // 检查是否是会员
    void Set();
    void VIP_Show();
    void VIP_delete();
};

class Customer//顾客
{
private:
    char table[20];//桌号
    int queues;//排队号
    char dishes[20][30];//所点菜品
    char BZ[30];//顾客备注
    float  Total_price=0;//总金额
    static int total;//顾客总数
    static float income;
    int Num_dishes;//点菜数量
public:
    Customer();
    void order();//点菜
    void Printf();//输出顾客信息
    void Bill();
    void correct_order();
    void getTotal_price();
    static float getincome();
    static int gettotal();
    ~Customer();
};
int Customer::total=0;
float Customer::income = 0;

class Menus//菜单
{
private:
    int number;//菜品编号
    char dish_name[30];//菜品名称
    float price;//菜品价格
    static int sums;//菜品总数
public:
    void Set();//增加菜品
    void show();//显示菜品信息
    void correct_menus();//修改菜品
    void delete_menus();//删除菜单
    friend void Customer::order();
    friend void Customer::correct_order();
};
int Menus::sums=5;

void Hello()
{
    cout << "*********************************************" << endl;
    cout<< "********************欢迎光临*****************" <<endl;
    cout<< "****************四道菜（创意谷店）***********" <<endl;
}
int menu()
{
    int n;
    cout << "*********************************************" << endl;
    cout << "*                    菜单                   *" << endl;
    cout << "*********************************************" << endl;
    cout << "* "<<setw(25)<< left <<"1.  新增菜品" << setw(17) <<  left <<"2.  删除菜品" <<"*"<< endl;
    cout << "* "<<setw(25)<< left <<"3.  修改菜品" << setw(17) << left << "4.  显示菜品信息" <<"*"<< endl;
    cout << "* "<<setw(25)<< left <<"5.  顾客点菜" << setw(17) << left << "6.  显示顾客信息" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"7.  修改顾客点菜信息" << setw(17) << left << "8.  结账" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"9.  显示在店人数" << setw(17) <<  left <<"10. 新增会员信息" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"11. 显示会员信息" << setw(17) <<  left <<"12. 删除会员信息" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"13. 打印总收入" << setw(17) <<  left <<"0.  退出" << "*"<<endl;
    cout << "*********************************************" << endl;
    cout<<endl;
    cout<<"请选择：";
    cin>>n;
    system("cls");
    if(n>=0&&n<=13)
        return n;
    else
        menu();
}


int main() {
    Menus m;
    Hello();
    Customer* customers[20]; // 最多处理20个顾客对象
    VIP v;
    int num_customers = 0;

    while (1) {
        switch (menu()) {
            case 1:
                m.Set();
                break;
            case 2:
                m.delete_menus();
                break;
            case 3:
                m.correct_menus();
                break;
            case 4:
                m.show();
                break;
            case 5:
                customers[num_customers] = new Customer(); // 创建新顾客对象
                customers[num_customers]->order(); // 点菜
                num_customers++;
                break;
            case 6:
            {
                int customerIndex;
                cout << "*********************************************" << endl;
                cout << "请输入要查看的顾客排队号：" ;
                cin >> customerIndex;
                cout << "*********************************************" << endl;
                system("cls");
                if (customerIndex >= 1 && customerIndex <= num_customers)
                {
                    customers[customerIndex - 1]->Printf(); // 打印指定顾客信息
                }
                else
                {
                    cout << "无效的排队号！" << endl;
                }
                break;
            }
            case 7:
            {
                int customerIndex;
                cout << "*********************************************" << endl;
                cout << "请输入要修改点菜信息的顾客排队号：" ;
                cin >> customerIndex;
                cout << "*********************************************" << endl;
                system("cls");
                if (customerIndex >= 1 && customerIndex <= num_customers)
                {
                    customers[customerIndex - 1]->correct_order(); // 修改指定顾客的点菜信息
                }
                else
                {
                    cout << "无效的排队号！" << endl;
                }
                break;
            }
            case 8:
            {
                int customerIndex;
                cout << "*********************************************" << endl;
                cout << "请输入要结账的顾客排队号：" ;
                cin >> customerIndex;
                cout << "*********************************************" << endl;
                system("cls");
                if (customerIndex >= 1 && customerIndex <= num_customers)
                {
                    customers[customerIndex - 1]->Bill(); // 结账指定顾客
//                    for (int i = customerIndex - 1; i < num_customers - 1; ++i)
//                    {
//                        customers[i] = customers[i + 1]; // 移动数组元素
//                    }
//                    num_customers--; // 减少顾客数量
                }
                else
                {
                    cout << "无效的排队号！" << endl;
                }
                break;
            }
            case 9:
            {
                cout << "*********************************************" << endl;
                cout << "*在店人数为：" <<setw(10)<< Customer::gettotal() <<"                     *"<<endl;
                cout << "*********************************************" << endl;
                getchar();
                getchar();
                system("cls");
                break;
            }
            case 10:
                v.Set();
                break;
            case 11:
                v.VIP_Show();
                break;
            case 12:
                v.VIP_delete();
                break;
            case 13:
            {
                cout << "*********************************************" << endl;
                for (int i = 0; i < num_customers; ++i)
                {
                    customers[i]->getTotal_price();
                }
                cout << "* 总收入为：" <<setw(10)<< Customer::getincome() <<"                      *"<<endl;
                cout << "*********************************************" << endl;
                getchar();
                getchar();
                system("cls");
                break;
            }
            case 0:
                cout << "*********************************************" << endl;
                cout<<"**感谢您使用四道菜(创意谷店)餐饮业管理系统***"<<endl;
                cout << "*********************************************" << endl;
                return 0;
        }
    }
    system("pause");
    return 0;
}

void Menus::Set()
{
    sums++;
    cout << "*********************************************" << endl;
    cout<<"请输入菜名：";
    cin>>dish_name;
    cout<<endl;
    cout<<"请输入价格：";
    cin>>price;
    cout << "*********************************************" << endl;
    number=sums;
    ofstream out("Menus.txt",ios::app);//存入文件
    //检查文件是否打开成功
    if(!out) //无法打开
    {
        cout<<"文件无法打开"<<endl;
        return;
    }
    out<<number<<" "<<dish_name<<" "<<price<<" "<<endl;
    cout<<"输入成功！"<<endl;
    getchar();
    getchar();
    out.close();
    system("cls");
}

void Menus::delete_menus()
{
    int i = 0, temp;
    char name[30];
    Menus menu[50];

    // 显示当前菜单项
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"菜品编号"<< setw(20) << left <<"菜名"<< setw(10) << left <<"价格"<<"  * "<<endl;

    ifstream in("Menus.txt");
    if (!in)
    {
        cout << "文件无法打开" << endl;
        return;
    }

    // 读取菜单信息到数组并显示
    while (in >> menu[i].number >> menu[i].dish_name >> menu[i].price)
    {
        cout<<"* "<< setw(10) << left <<menu[i].number<< setw(20) << left <<menu[i].dish_name<<setw(10)<< left <<menu[i].price<<"  * "<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    temp = i; // 记录读取的菜品数量
    in.close();

    // 获取要删除的菜品名称
    cout << "请输入需要删除的菜品名字(输入0为返回)： ";
    cin >> name;
    if (strcmp(name, "0") == 0)
    {
        system("cls");
        return;
    }
    // 在数组中查找要删除的菜品
    for (i = 0; i < temp; i++)
    {
        if (strcmp(name, menu[i].dish_name) == 0)
        {
            // 找到要删除的菜品，将其从数组中移除
            for (int j = i; j < temp - 1; j++)
            {
                menu[j] = menu[j + 1];
            }
            temp--; // 更新菜品数量
            break;
        }
    }

    // 将更新后的菜单信息写回文件
    ofstream outf("Menus.txt", ios::trunc);
    if (!outf)
    {
        cout << "无法打开文件" << endl;
        return;
    }

    for (i = 0; i < temp; i++)
    {
        outf << menu[i].number << " " << menu[i].dish_name << " " << menu[i].price << endl;
    }

    outf.close();
    cout << "删除成功！" << endl;

    getchar();
    getchar();
    system("cls");
}


void Menus::correct_menus()
{
    int i = 0, temp;
    char name[30];
    Menus menu[50];

    // 显示当前菜单项
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"菜品编号"<< setw(20) << left <<"菜名"<< setw(10) << left <<"价格"<<"  * "<<endl;

    ifstream in("Menus.txt");
    if (!in)
    {
        cout << "文件无法打开" << endl;
        return;
    }

    // 读取菜单信息到数组并显示
    while (in >> menu[i].number >> menu[i].dish_name >> menu[i].price)
    {
        cout<<"* "<< setw(10) << left <<menu[i].number<< setw(20) << left <<menu[i].dish_name<<setw(10)<< left <<menu[i].price<<"  * "<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    temp = i; // 记录读取的菜品数量
    in.close();

    // 获取要修改的菜品名称
    cout << endl << "请输入想要修改的菜品名（输入0为返回）：" << endl;
    cin >> name;
    if (strcmp(name, "0") == 0)
    {
        system("cls");
        return;
    }
    // 在数组中查找要修改的菜品
    for (i = 0; i < temp; i++)
    {
        if (strcmp(name, menu[i].dish_name) == 0)
        {
            // 找到要修改的菜品，允许用户输入新的菜品编号、菜名、价格
            cout << "请输入修改后的菜品编号、菜名、价格：" << endl;
            cin >> menu[i].number >> menu[i].dish_name >> menu[i].price;
            break;
        }
    }

    // 将更新后的菜单信息写回文件
    ofstream outf("Menus.txt", ios::trunc);
    if (!outf)
    {
        cout << "无法打开文件" << endl;
        return;
    }

    for (i = 0; i < temp; i++)
    {
        outf << menu[i].number << " " << menu[i].dish_name << " " << menu[i].price << endl;
    }

    outf.close();
    cout << "修改成功！" << endl;

    getchar();
    getchar();
    system("cls");
}


void Menus::show()
{
    int i=0;
    Menus menu[50];
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"菜品编号"<< setw(20) << left <<"菜名"<< setw(10) << left <<"价格"<<"  * "<<endl;
    ifstream in("Menus.txt");
    while(in>>menu[i].number>>menu[i].dish_name>>menu[i].price)
    {
        cout<<"* "<< setw(10) << left <<menu[i].number<< setw(20) << left <<menu[i].dish_name<<setw(10)<< left <<menu[i].price<<"  * "<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    getchar();
    getchar();
    system("cls");
}


Customer::Customer()
{
    total++;
    queues=total;
    cout<<"您当前的排队号为："<<queues<<endl;
}
Customer::~Customer()
{

}
void Customer::order()
{
    int flag = 0;
    Menus menu[50];
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"菜品编号"<< setw(20) << left <<"菜名"<< setw(10) << left <<"价格"<<"  * "<<endl;
    ifstream in("Menus.txt");
    if (!in) {
        cout << "文件无法打开" << endl;
        return;
    }
    int i = 0;
    while (in >> menu[i].number >> menu[i].dish_name >> menu[i].price) {
        cout<<"* "<< setw(10) << left <<menu[i].number<< setw(20) << left <<menu[i].dish_name<<setw(10)<< left <<menu[i].price<<"  * "<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    in.close();
    int temp = i - 1;
    int num_dishes = 0; // 初始化点菜数量为0
    cout << "请输入该顾客桌号:";
    cin >> table;
    cout<<endl;
    while (flag == 0)
    {
        i = temp;
        cout<<"请输入需要点菜的菜名："<<endl;
        cout<<"（输入0结束点菜，需要2份同样菜品请输2次菜名）"<<endl;
        while (true)
        {
            cin >> dishes[num_dishes];
            if (strcmp(dishes[num_dishes], "0") == 0) {
                break;
            }
            // 检查菜单中是否有该菜品
            flag = 0;
            for (int j = 0; j <= i; ++j) {
                if (strcmp(menu[j].dish_name, dishes[num_dishes]) == 0)
                {
                    Total_price+=menu[j].price;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "菜单中没有此菜，请重新输入：" << endl;
                continue;
            }
            num_dishes++;
        }
        Num_dishes=num_dishes;
        cout<<endl;
        cout<<"顾客备注:";
        cin >> BZ;
        cout << "*********************************************" << endl;
        if (flag == 1)
            cout << "点菜成功！" << endl;
        else
            cout << "菜单中没有此菜！" << endl;
    }
    getchar();
    getchar();
    system("cls");
}

void Customer::Printf()
{
    int i=0;
    cout << "*********************************************" << endl;
    cout<<"* "<<setw(10)<<left<<"桌号"<<setw(10)<<left<<"排队号"<<setw(22)<<left<<"顾客备注"<<"*"<<endl;
    cout<<"* "<<setw(10)<<left<<table<<setw(10)<<left<<queues<<setw(22)<<left<<BZ<<"*"<<endl;
    cout << "*********************************************" << endl;
    cout<<"* "<<"已点菜品:"<<"                                 *"<<endl;
    for(i;i<Num_dishes;i++)
    {
        cout<<"* "<<setw(20)<<dishes[i]<<"                      *"<<endl;
    }
    cout <<"* "<< "总金额：" <<setw(10)<<left<< Total_price <<"                        *"<<endl;
    cout << "*********************************************" << endl;
    getchar();
    getchar();
    system("cls");
}

void Customer::correct_order()
{
    cout << "*********************************************" << endl;
    cout <<"* "<< "当前顾客的点菜信息如下：" <<"                  *"<<endl;
    cout<<"* "<<setw(10)<<left<<"桌号"<<setw(10)<<left<<"排队号"<<setw(22)<<left<<"顾客备注"<<"*"<<endl;
    cout<<"* "<<setw(10)<<left<<table<<setw(10)<<left<<queues<<setw(22)<<left<<BZ<<"*"<<endl;
    cout <<"* "<< "已点菜品：" <<"                                *"<< endl;
    for (int i = 0; i < Num_dishes; ++i)
    {
        cout<<"* "<<setw(20)<<dishes[i]<<"                      *"<<endl;
    }
    cout <<"* "<< "总金额：" <<setw(10)<<left<< Total_price <<"                        *"<<endl;
    cout << "*********************************************" << endl;
    cout <<"* "<< "请选择您要修改的内容：" <<"                    *"<< endl;
    cout <<"* "<< "1. 修改桌号" <<"                               *"<< endl;
    cout <<"* "<< "2. 修改菜品" <<"                               *"<< endl;
    cout <<"* "<< "3. 修改备注" <<"                               *"<< endl;
    cout <<"* "<< "0. 返回主菜单" <<"                             *"<< endl;
    cout << "*********************************************" << endl;

    int choice;
    cin >> choice;
    system("cls");
    switch (choice)
    {
        case 1:
            cout << "请输入新的桌号：" << endl;
            cin >> table;
            break;
        case 2:
            cout << "请输入新的菜品信息（输入0结束）：" << endl;
            Num_dishes = 0;
            Total_price = 0;
            while (true)
            {
                cin >> dishes[Num_dishes];
                if (strcmp(dishes[Num_dishes], "0") == 0)
                {
                    break;
                }
                // 根据菜品名称查找对应的价格并计算总金额
                bool found = false;
                ifstream in("Menus.txt");
                Menus menu;
                while (in >> menu.number >> menu.dish_name >> menu.price)
                {
                    if (strcmp(menu.dish_name, dishes[Num_dishes]) == 0)
                    {
                        Total_price += menu.price;
                        found = true;
                        break;
                    }
                }
                in.close();

                if (!found)
                {
                    cout << "菜单中没有此菜品，请重新输入：" << endl;
                    continue;
                }

                Num_dishes++;
            }
            break;
        case 3:
            cout << "请输入新的备注：" << endl;
            cin >> BZ;
            break;
        case 0:
            return;
        default:
            cout << "无效的选项，请重新选择：" << endl;
            correct_order();
            return;
    }
    system("cls");
    cout << "修改完成！" << endl;
    cout << "修改后的顾客信息如下：" << endl;
    Printf();
}

void Customer::Bill()
{
    int mode=0;
    int i=0;
    cout << "********************小票*********************" << endl;
    cout<<"* "<<setw(10)<<left<<"桌号"<<setw(10)<<left<<"排队号"<<setw(22)<<left<<"顾客备注"<<"*"<<endl;
    cout<<"* "<<setw(10)<<left<<table<<setw(10)<<left<<queues<<setw(22)<<left<<BZ<<"*"<<endl;
    cout << "*********************************************" << endl;
    cout<<"* "<<"已点菜品:"<<"                                 *"<<endl;
    for(i;i<Num_dishes;i++)
    {
        cout<<"* "<<setw(20)<<dishes[i]<<"                      *"<<endl;
    }
    cout << "*********************************************" << endl;
    cout<<"* "<<"您的消费金额为："<<setw(10)<<left<<Total_price<<"                *"<<endl;
    cout << "*********************************************" << endl;
    cout<<"* "<<"1.打折"<<"                                    *"<<endl;
    cout<<"* "<<"2.抹零"<<"                                    *"<<endl;
    cout<<"* "<<"3.减免金额（优惠劵/赠送菜品）"<<"             *"<<endl;
    cout<<"* "<<"4.会员打折"<<"                                *"<<endl;
    cout<<"* "<<"0.确定最终金额"<<"                            *"<<endl;
    cout << "*********************************************" << endl;
    cin>>mode;
    system("cls");
    if(mode==1)
    {
        int x=10;
        cout << "*********************************************" << endl;
        cout<<"请输入折扣力度（输入1~9数字）"<<endl;
        cin>>x;
        cout<<endl;
        cout << "*********************************************" << endl;
        Total_price=Total_price*0.1*x;
    }
    if(mode==2)
    {
        int ml;
        ml=(int)Total_price/10;
        Total_price=ml*10;
    }
    if(mode==3)
    {
        float x=0;
        cout << "*********************************************" << endl;
        cout<<"输入减免金额"<<endl;
        cin>>x;
        cout<<endl;
        cout << "*********************************************" << endl;
        Total_price=Total_price-x;
    }
    if(mode==4)
    {
        string phoneNumber;
        cout << "*********************************************" << endl;
        cout << "请输入电话号码以验证会员身份：" << endl;
        cin >> phoneNumber;
        if (VIP::IsVIP(phoneNumber))
        {
            // 如果是会员，可以打折
            Total_price *= 0.9; // 例如打9折
            cout << "会员验证成功，享受9折优惠！" << endl;
            cout << "*********************************************" << endl;
        }
        else
        {
            cout << "非会员，无法享受会员折扣。" << endl;
            cout << "*********************************************" << endl;
        }
        getchar();
        getchar();
        system("cls");
    }
    system("cls");
    cout << "*********************************************" << endl;
    cout<<"* "<<"您的消费金额为："<<setw(10)<<left<<Total_price<<"                *"<<endl;
    cout<<"*"<<" 欢迎下次光临四道菜（创意谷店）"<<"            *"<<endl;
    cout << "*********************************************" << endl;
    income+=Total_price;
    total--;
    getchar();
    getchar();
    system("cls");
}

void VIP::Set()
{
    cout << "*********************************************" << endl;
    cout << "请输入VIP姓名：";
    cin >> Name;
    cout << "请输入VIP电话：";
    cin >> Tele;
    cout<<endl;
    cout << "*********************************************" << endl;

    // 将VIP信息写入文件
    ofstream fout("VIP.txt", ios::app); // 以追加模式打开文件
    if (!fout)
    {
        cerr << "无法打开文件！" << endl;
        return;
    }
    fout << Name << " " << Tele << endl;
    fout.close();

    cout << "VIP信息已成功添加到文件中。" << endl;
    getchar();
    getchar();
    system("cls");
}

void VIP::VIP_Show()
{
    int i=0;
    VIP v[50];
    cout << "*********************************************" << endl;
    cout<<"* "<<"当前的VIP名单："<<"                           *"<<endl;
    cout<<"* "<<setw(20)<<left<<"姓名"<<setw(20)<<left<<"电话"<<"  *"<<endl;
    ifstream in("VIP.txt");
    while(in>>v[i].Name>>v[i].Tele)
    {
        cout<<"* "<<setw(20)<<left<<v[i].Name<<setw(20)<<left<<v[i].Tele<<"  *"<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    getchar();
    getchar();
    system("cls");
}

void VIP::VIP_delete()
{
    int i = 0, temp;
    char tele[30];
    VIP v[50];

    // 显示当前VIP
    cout << "*********************************************" << endl;
    cout<<"* "<<"当前的VIP名单："<<"                           *"<<endl;
    cout<<"* "<<setw(20)<<left<<"姓名"<<setw(20)<<left<<"电话"<<"  *"<<endl;
    ifstream in("VIP.txt");
    if (!in)
    {
        cout << "文件无法打开" << endl;
        return;
    }

    // 读取VIP信息到数组并显示
    while (in >> v[i].Name >> v[i].Tele )
    {
        cout<<"* "<<setw(20)<<left<<v[i].Name<<setw(20)<<left<<v[i].Tele<<"  *"<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    temp = i;
    in.close();

    cout << "请输入需要删除的会员电话(输入0为返回)： ";
    cin >> tele;
    if (strcmp(tele, "0") == 0)
    {
        system("cls");
        return;
    }

    for (i = 0; i < temp; i++)
    {
        if (tele==v[i].Tele)
        {
            // 找到要删除的VIP，将其从数组中移除
            for (int j = i; j < temp - 1; j++)
            {
                v[j] = v[j + 1];
            }
            temp--; // 更新VIP名单
            break;
        }
    }

    // 将更新后的菜单信息写回文件
    ofstream outf("VIP.txt", ios::trunc);
    if (!outf)
    {
        cout << "无法打开文件" << endl;
        return;
    }

    for (i = 0; i < temp; i++)
    {
        outf << v[i].Name << " " << v[i].Tele <<  endl;
    }

    outf.close();
    cout << "删除成功！" << endl;

    getchar();
    getchar();
    system("cls");
}
float Customer::getincome()
{
    return income;
}
//会员验证
bool VIP::IsVIP(const string& tele) {
    ifstream in("VIP.txt");
    string storedTele;
    while (in >> storedTele) {
        if (tele == storedTele) {
            in.close();
            return true;
        }
    }
    in.close();
    return false;
}

int Customer::gettotal()
{
    return total;
}
void Customer::getTotal_price()
{
    cout<<"* "<<setw(2)<<left<<queues<<"号顾客的消费金额为："<<setw(10)<<left<<Total_price<<"          *"<<endl;
}
