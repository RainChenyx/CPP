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
    static bool IsVIP(const string& tele); // ����Ƿ��ǻ�Ա
    void Set();
    void VIP_Show();
    void VIP_delete();
};

class Customer//�˿�
{
private:
    char table[20];//����
    int queues;//�ŶӺ�
    char dishes[20][30];//�����Ʒ
    char BZ[30];//�˿ͱ�ע
    float  Total_price=0;//�ܽ��
    static int total;//�˿�����
    static float income;
    int Num_dishes;//�������
public:
    Customer();
    void order();//���
    void Printf();//����˿���Ϣ
    void Bill();
    void correct_order();
    void getTotal_price();
    static float getincome();
    static int gettotal();
    ~Customer();
};
int Customer::total=0;
float Customer::income = 0;

class Menus//�˵�
{
private:
    int number;//��Ʒ���
    char dish_name[30];//��Ʒ����
    float price;//��Ʒ�۸�
    static int sums;//��Ʒ����
public:
    void Set();//���Ӳ�Ʒ
    void show();//��ʾ��Ʒ��Ϣ
    void correct_menus();//�޸Ĳ�Ʒ
    void delete_menus();//ɾ���˵�
    friend void Customer::order();
    friend void Customer::correct_order();
};
int Menus::sums=5;

void Hello()
{
    cout << "*********************************************" << endl;
    cout<< "********************��ӭ����*****************" <<endl;
    cout<< "****************�ĵ��ˣ�����ȵ꣩***********" <<endl;
}
int menu()
{
    int n;
    cout << "*********************************************" << endl;
    cout << "*                    �˵�                   *" << endl;
    cout << "*********************************************" << endl;
    cout << "* "<<setw(25)<< left <<"1.  ������Ʒ" << setw(17) <<  left <<"2.  ɾ����Ʒ" <<"*"<< endl;
    cout << "* "<<setw(25)<< left <<"3.  �޸Ĳ�Ʒ" << setw(17) << left << "4.  ��ʾ��Ʒ��Ϣ" <<"*"<< endl;
    cout << "* "<<setw(25)<< left <<"5.  �˿͵��" << setw(17) << left << "6.  ��ʾ�˿���Ϣ" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"7.  �޸Ĺ˿͵����Ϣ" << setw(17) << left << "8.  ����" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"9.  ��ʾ�ڵ�����" << setw(17) <<  left <<"10. ������Ա��Ϣ" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"11. ��ʾ��Ա��Ϣ" << setw(17) <<  left <<"12. ɾ����Ա��Ϣ" << "*"<<endl;
    cout << "* "<<setw(25)<< left <<"13. ��ӡ������" << setw(17) <<  left <<"0.  �˳�" << "*"<<endl;
    cout << "*********************************************" << endl;
    cout<<endl;
    cout<<"��ѡ��";
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
    Customer* customers[20]; // ��ദ��20���˿Ͷ���
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
                customers[num_customers] = new Customer(); // �����¹˿Ͷ���
                customers[num_customers]->order(); // ���
                num_customers++;
                break;
            case 6:
            {
                int customerIndex;
                cout << "*********************************************" << endl;
                cout << "������Ҫ�鿴�Ĺ˿��ŶӺţ�" ;
                cin >> customerIndex;
                cout << "*********************************************" << endl;
                system("cls");
                if (customerIndex >= 1 && customerIndex <= num_customers)
                {
                    customers[customerIndex - 1]->Printf(); // ��ӡָ���˿���Ϣ
                }
                else
                {
                    cout << "��Ч���ŶӺţ�" << endl;
                }
                break;
            }
            case 7:
            {
                int customerIndex;
                cout << "*********************************************" << endl;
                cout << "������Ҫ�޸ĵ����Ϣ�Ĺ˿��ŶӺţ�" ;
                cin >> customerIndex;
                cout << "*********************************************" << endl;
                system("cls");
                if (customerIndex >= 1 && customerIndex <= num_customers)
                {
                    customers[customerIndex - 1]->correct_order(); // �޸�ָ���˿͵ĵ����Ϣ
                }
                else
                {
                    cout << "��Ч���ŶӺţ�" << endl;
                }
                break;
            }
            case 8:
            {
                int customerIndex;
                cout << "*********************************************" << endl;
                cout << "������Ҫ���˵Ĺ˿��ŶӺţ�" ;
                cin >> customerIndex;
                cout << "*********************************************" << endl;
                system("cls");
                if (customerIndex >= 1 && customerIndex <= num_customers)
                {
                    customers[customerIndex - 1]->Bill(); // ����ָ���˿�
//                    for (int i = customerIndex - 1; i < num_customers - 1; ++i)
//                    {
//                        customers[i] = customers[i + 1]; // �ƶ�����Ԫ��
//                    }
//                    num_customers--; // ���ٹ˿�����
                }
                else
                {
                    cout << "��Ч���ŶӺţ�" << endl;
                }
                break;
            }
            case 9:
            {
                cout << "*********************************************" << endl;
                cout << "*�ڵ�����Ϊ��" <<setw(10)<< Customer::gettotal() <<"                     *"<<endl;
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
                cout << "* ������Ϊ��" <<setw(10)<< Customer::getincome() <<"                      *"<<endl;
                cout << "*********************************************" << endl;
                getchar();
                getchar();
                system("cls");
                break;
            }
            case 0:
                cout << "*********************************************" << endl;
                cout<<"**��л��ʹ���ĵ���(����ȵ�)����ҵ����ϵͳ***"<<endl;
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
    cout<<"�����������";
    cin>>dish_name;
    cout<<endl;
    cout<<"������۸�";
    cin>>price;
    cout << "*********************************************" << endl;
    number=sums;
    ofstream out("Menus.txt",ios::app);//�����ļ�
    //����ļ��Ƿ�򿪳ɹ�
    if(!out) //�޷���
    {
        cout<<"�ļ��޷���"<<endl;
        return;
    }
    out<<number<<" "<<dish_name<<" "<<price<<" "<<endl;
    cout<<"����ɹ���"<<endl;
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

    // ��ʾ��ǰ�˵���
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"��Ʒ���"<< setw(20) << left <<"����"<< setw(10) << left <<"�۸�"<<"  * "<<endl;

    ifstream in("Menus.txt");
    if (!in)
    {
        cout << "�ļ��޷���" << endl;
        return;
    }

    // ��ȡ�˵���Ϣ�����鲢��ʾ
    while (in >> menu[i].number >> menu[i].dish_name >> menu[i].price)
    {
        cout<<"* "<< setw(10) << left <<menu[i].number<< setw(20) << left <<menu[i].dish_name<<setw(10)<< left <<menu[i].price<<"  * "<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    temp = i; // ��¼��ȡ�Ĳ�Ʒ����
    in.close();

    // ��ȡҪɾ���Ĳ�Ʒ����
    cout << "��������Ҫɾ���Ĳ�Ʒ����(����0Ϊ����)�� ";
    cin >> name;
    if (strcmp(name, "0") == 0)
    {
        system("cls");
        return;
    }
    // �������в���Ҫɾ���Ĳ�Ʒ
    for (i = 0; i < temp; i++)
    {
        if (strcmp(name, menu[i].dish_name) == 0)
        {
            // �ҵ�Ҫɾ���Ĳ�Ʒ��������������Ƴ�
            for (int j = i; j < temp - 1; j++)
            {
                menu[j] = menu[j + 1];
            }
            temp--; // ���²�Ʒ����
            break;
        }
    }

    // �����º�Ĳ˵���Ϣд���ļ�
    ofstream outf("Menus.txt", ios::trunc);
    if (!outf)
    {
        cout << "�޷����ļ�" << endl;
        return;
    }

    for (i = 0; i < temp; i++)
    {
        outf << menu[i].number << " " << menu[i].dish_name << " " << menu[i].price << endl;
    }

    outf.close();
    cout << "ɾ���ɹ���" << endl;

    getchar();
    getchar();
    system("cls");
}


void Menus::correct_menus()
{
    int i = 0, temp;
    char name[30];
    Menus menu[50];

    // ��ʾ��ǰ�˵���
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"��Ʒ���"<< setw(20) << left <<"����"<< setw(10) << left <<"�۸�"<<"  * "<<endl;

    ifstream in("Menus.txt");
    if (!in)
    {
        cout << "�ļ��޷���" << endl;
        return;
    }

    // ��ȡ�˵���Ϣ�����鲢��ʾ
    while (in >> menu[i].number >> menu[i].dish_name >> menu[i].price)
    {
        cout<<"* "<< setw(10) << left <<menu[i].number<< setw(20) << left <<menu[i].dish_name<<setw(10)<< left <<menu[i].price<<"  * "<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    temp = i; // ��¼��ȡ�Ĳ�Ʒ����
    in.close();

    // ��ȡҪ�޸ĵĲ�Ʒ����
    cout << endl << "��������Ҫ�޸ĵĲ�Ʒ��������0Ϊ���أ���" << endl;
    cin >> name;
    if (strcmp(name, "0") == 0)
    {
        system("cls");
        return;
    }
    // �������в���Ҫ�޸ĵĲ�Ʒ
    for (i = 0; i < temp; i++)
    {
        if (strcmp(name, menu[i].dish_name) == 0)
        {
            // �ҵ�Ҫ�޸ĵĲ�Ʒ�������û������µĲ�Ʒ��š��������۸�
            cout << "�������޸ĺ�Ĳ�Ʒ��š��������۸�" << endl;
            cin >> menu[i].number >> menu[i].dish_name >> menu[i].price;
            break;
        }
    }

    // �����º�Ĳ˵���Ϣд���ļ�
    ofstream outf("Menus.txt", ios::trunc);
    if (!outf)
    {
        cout << "�޷����ļ�" << endl;
        return;
    }

    for (i = 0; i < temp; i++)
    {
        outf << menu[i].number << " " << menu[i].dish_name << " " << menu[i].price << endl;
    }

    outf.close();
    cout << "�޸ĳɹ���" << endl;

    getchar();
    getchar();
    system("cls");
}


void Menus::show()
{
    int i=0;
    Menus menu[50];
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"��Ʒ���"<< setw(20) << left <<"����"<< setw(10) << left <<"�۸�"<<"  * "<<endl;
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
    cout<<"����ǰ���ŶӺ�Ϊ��"<<queues<<endl;
}
Customer::~Customer()
{

}
void Customer::order()
{
    int flag = 0;
    Menus menu[50];
    cout << "*********************************************" << endl;
    cout<<"* "<< setw(10) << left <<"��Ʒ���"<< setw(20) << left <<"����"<< setw(10) << left <<"�۸�"<<"  * "<<endl;
    ifstream in("Menus.txt");
    if (!in) {
        cout << "�ļ��޷���" << endl;
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
    int num_dishes = 0; // ��ʼ���������Ϊ0
    cout << "������ù˿�����:";
    cin >> table;
    cout<<endl;
    while (flag == 0)
    {
        i = temp;
        cout<<"��������Ҫ��˵Ĳ�����"<<endl;
        cout<<"������0������ˣ���Ҫ2��ͬ����Ʒ����2�β�����"<<endl;
        while (true)
        {
            cin >> dishes[num_dishes];
            if (strcmp(dishes[num_dishes], "0") == 0) {
                break;
            }
            // ���˵����Ƿ��иò�Ʒ
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
                cout << "�˵���û�д˲ˣ����������룺" << endl;
                continue;
            }
            num_dishes++;
        }
        Num_dishes=num_dishes;
        cout<<endl;
        cout<<"�˿ͱ�ע:";
        cin >> BZ;
        cout << "*********************************************" << endl;
        if (flag == 1)
            cout << "��˳ɹ���" << endl;
        else
            cout << "�˵���û�д˲ˣ�" << endl;
    }
    getchar();
    getchar();
    system("cls");
}

void Customer::Printf()
{
    int i=0;
    cout << "*********************************************" << endl;
    cout<<"* "<<setw(10)<<left<<"����"<<setw(10)<<left<<"�ŶӺ�"<<setw(22)<<left<<"�˿ͱ�ע"<<"*"<<endl;
    cout<<"* "<<setw(10)<<left<<table<<setw(10)<<left<<queues<<setw(22)<<left<<BZ<<"*"<<endl;
    cout << "*********************************************" << endl;
    cout<<"* "<<"�ѵ��Ʒ:"<<"                                 *"<<endl;
    for(i;i<Num_dishes;i++)
    {
        cout<<"* "<<setw(20)<<dishes[i]<<"                      *"<<endl;
    }
    cout <<"* "<< "�ܽ�" <<setw(10)<<left<< Total_price <<"                        *"<<endl;
    cout << "*********************************************" << endl;
    getchar();
    getchar();
    system("cls");
}

void Customer::correct_order()
{
    cout << "*********************************************" << endl;
    cout <<"* "<< "��ǰ�˿͵ĵ����Ϣ���£�" <<"                  *"<<endl;
    cout<<"* "<<setw(10)<<left<<"����"<<setw(10)<<left<<"�ŶӺ�"<<setw(22)<<left<<"�˿ͱ�ע"<<"*"<<endl;
    cout<<"* "<<setw(10)<<left<<table<<setw(10)<<left<<queues<<setw(22)<<left<<BZ<<"*"<<endl;
    cout <<"* "<< "�ѵ��Ʒ��" <<"                                *"<< endl;
    for (int i = 0; i < Num_dishes; ++i)
    {
        cout<<"* "<<setw(20)<<dishes[i]<<"                      *"<<endl;
    }
    cout <<"* "<< "�ܽ�" <<setw(10)<<left<< Total_price <<"                        *"<<endl;
    cout << "*********************************************" << endl;
    cout <<"* "<< "��ѡ����Ҫ�޸ĵ����ݣ�" <<"                    *"<< endl;
    cout <<"* "<< "1. �޸�����" <<"                               *"<< endl;
    cout <<"* "<< "2. �޸Ĳ�Ʒ" <<"                               *"<< endl;
    cout <<"* "<< "3. �޸ı�ע" <<"                               *"<< endl;
    cout <<"* "<< "0. �������˵�" <<"                             *"<< endl;
    cout << "*********************************************" << endl;

    int choice;
    cin >> choice;
    system("cls");
    switch (choice)
    {
        case 1:
            cout << "�������µ����ţ�" << endl;
            cin >> table;
            break;
        case 2:
            cout << "�������µĲ�Ʒ��Ϣ������0��������" << endl;
            Num_dishes = 0;
            Total_price = 0;
            while (true)
            {
                cin >> dishes[Num_dishes];
                if (strcmp(dishes[Num_dishes], "0") == 0)
                {
                    break;
                }
                // ���ݲ�Ʒ���Ʋ��Ҷ�Ӧ�ļ۸񲢼����ܽ��
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
                    cout << "�˵���û�д˲�Ʒ�����������룺" << endl;
                    continue;
                }

                Num_dishes++;
            }
            break;
        case 3:
            cout << "�������µı�ע��" << endl;
            cin >> BZ;
            break;
        case 0:
            return;
        default:
            cout << "��Ч��ѡ�������ѡ��" << endl;
            correct_order();
            return;
    }
    system("cls");
    cout << "�޸���ɣ�" << endl;
    cout << "�޸ĺ�Ĺ˿���Ϣ���£�" << endl;
    Printf();
}

void Customer::Bill()
{
    int mode=0;
    int i=0;
    cout << "********************СƱ*********************" << endl;
    cout<<"* "<<setw(10)<<left<<"����"<<setw(10)<<left<<"�ŶӺ�"<<setw(22)<<left<<"�˿ͱ�ע"<<"*"<<endl;
    cout<<"* "<<setw(10)<<left<<table<<setw(10)<<left<<queues<<setw(22)<<left<<BZ<<"*"<<endl;
    cout << "*********************************************" << endl;
    cout<<"* "<<"�ѵ��Ʒ:"<<"                                 *"<<endl;
    for(i;i<Num_dishes;i++)
    {
        cout<<"* "<<setw(20)<<dishes[i]<<"                      *"<<endl;
    }
    cout << "*********************************************" << endl;
    cout<<"* "<<"�������ѽ��Ϊ��"<<setw(10)<<left<<Total_price<<"                *"<<endl;
    cout << "*********************************************" << endl;
    cout<<"* "<<"1.����"<<"                                    *"<<endl;
    cout<<"* "<<"2.Ĩ��"<<"                                    *"<<endl;
    cout<<"* "<<"3.������Ż݄�/���Ͳ�Ʒ��"<<"             *"<<endl;
    cout<<"* "<<"4.��Ա����"<<"                                *"<<endl;
    cout<<"* "<<"0.ȷ�����ս��"<<"                            *"<<endl;
    cout << "*********************************************" << endl;
    cin>>mode;
    system("cls");
    if(mode==1)
    {
        int x=10;
        cout << "*********************************************" << endl;
        cout<<"�������ۿ����ȣ�����1~9���֣�"<<endl;
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
        cout<<"���������"<<endl;
        cin>>x;
        cout<<endl;
        cout << "*********************************************" << endl;
        Total_price=Total_price-x;
    }
    if(mode==4)
    {
        string phoneNumber;
        cout << "*********************************************" << endl;
        cout << "������绰��������֤��Ա��ݣ�" << endl;
        cin >> phoneNumber;
        if (VIP::IsVIP(phoneNumber))
        {
            // ����ǻ�Ա�����Դ���
            Total_price *= 0.9; // �����9��
            cout << "��Ա��֤�ɹ�������9���Żݣ�" << endl;
            cout << "*********************************************" << endl;
        }
        else
        {
            cout << "�ǻ�Ա���޷����ܻ�Ա�ۿۡ�" << endl;
            cout << "*********************************************" << endl;
        }
        getchar();
        getchar();
        system("cls");
    }
    system("cls");
    cout << "*********************************************" << endl;
    cout<<"* "<<"�������ѽ��Ϊ��"<<setw(10)<<left<<Total_price<<"                *"<<endl;
    cout<<"*"<<" ��ӭ�´ι����ĵ��ˣ�����ȵ꣩"<<"            *"<<endl;
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
    cout << "������VIP������";
    cin >> Name;
    cout << "������VIP�绰��";
    cin >> Tele;
    cout<<endl;
    cout << "*********************************************" << endl;

    // ��VIP��Ϣд���ļ�
    ofstream fout("VIP.txt", ios::app); // ��׷��ģʽ���ļ�
    if (!fout)
    {
        cerr << "�޷����ļ���" << endl;
        return;
    }
    fout << Name << " " << Tele << endl;
    fout.close();

    cout << "VIP��Ϣ�ѳɹ���ӵ��ļ��С�" << endl;
    getchar();
    getchar();
    system("cls");
}

void VIP::VIP_Show()
{
    int i=0;
    VIP v[50];
    cout << "*********************************************" << endl;
    cout<<"* "<<"��ǰ��VIP������"<<"                           *"<<endl;
    cout<<"* "<<setw(20)<<left<<"����"<<setw(20)<<left<<"�绰"<<"  *"<<endl;
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

    // ��ʾ��ǰVIP
    cout << "*********************************************" << endl;
    cout<<"* "<<"��ǰ��VIP������"<<"                           *"<<endl;
    cout<<"* "<<setw(20)<<left<<"����"<<setw(20)<<left<<"�绰"<<"  *"<<endl;
    ifstream in("VIP.txt");
    if (!in)
    {
        cout << "�ļ��޷���" << endl;
        return;
    }

    // ��ȡVIP��Ϣ�����鲢��ʾ
    while (in >> v[i].Name >> v[i].Tele )
    {
        cout<<"* "<<setw(20)<<left<<v[i].Name<<setw(20)<<left<<v[i].Tele<<"  *"<<endl;
        i++;
    }
    cout << "*********************************************" << endl;
    temp = i;
    in.close();

    cout << "��������Ҫɾ���Ļ�Ա�绰(����0Ϊ����)�� ";
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
            // �ҵ�Ҫɾ����VIP��������������Ƴ�
            for (int j = i; j < temp - 1; j++)
            {
                v[j] = v[j + 1];
            }
            temp--; // ����VIP����
            break;
        }
    }

    // �����º�Ĳ˵���Ϣд���ļ�
    ofstream outf("VIP.txt", ios::trunc);
    if (!outf)
    {
        cout << "�޷����ļ�" << endl;
        return;
    }

    for (i = 0; i < temp; i++)
    {
        outf << v[i].Name << " " << v[i].Tele <<  endl;
    }

    outf.close();
    cout << "ɾ���ɹ���" << endl;

    getchar();
    getchar();
    system("cls");
}
float Customer::getincome()
{
    return income;
}
//��Ա��֤
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
    cout<<"* "<<setw(2)<<left<<queues<<"�Ź˿͵����ѽ��Ϊ��"<<setw(10)<<left<<Total_price<<"          *"<<endl;
}
