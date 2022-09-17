#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream ifs("1.dump",std::ios::binary);
    if(!ifs.open())
    {
        cout<<"open failed"<<endl;
        return 1;
    }
    int k=1;
    int len = 0;
    char head[4]={0};
    do{
        
        ifs.read(head,4);
        if(ifs.gcount()==4)
        {
            int *p=(int*)&head;
            len=*p;
            cout<<"len = "<<len<<endl;
            char *buf=new char[len];

            ifs.read(head,len);
            if(ifs.gcount()!=4)
            {
                
                cout<<"格式错误"<<endl;
                break;
            }

            ofstream ofs(to_string(k++)+".jpg");
            ofs.write(buf,ifs.gcount());
            ofs.close();

        }else{
            cout<<"格式错误"<<endl;
            break;
        }

    }while(!ifs.eof());
    


    return 0;
}