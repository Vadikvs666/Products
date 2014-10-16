#include "products.h"

Products::Products()
{
}

Products::Products(QString art, QString naim, QString cena)
{
    setArtikul(art);
    setId_1c(art);
    setTitle(naim);
    setPriceS(cena);
    setPrev_price(0);


}
QString Products::getTitle() const
{
    return title;
}

void Products::setTitle(const QString &value)
{
    title = value;
}
int Products::getId() const
{
    return id;
}

void Products::setId(int value)
{
    id = value;
}
QString Products::getId_1c() const
{
    return id_1c;
}

void Products::setId_1c(const QString &value)
{
    id_1c = value;
}
QString Products::getMesure_unit() const
{
    return mesure_unit;
}

void Products::setMesure_unit(const QString &value)
{
    mesure_unit = value;
}
float Products::getPrice() const
{
    return price;
}

QString Products::getPriceS()
{
    QVariant tmp=price;
    return tmp.toString();
}

void Products::setPrice(float value)
{
    price = value;
}

void Products::setPriceS(QString value)
{
    QVariant tmp=value;
    price=tmp.toFloat();
}
float Products::getIn_price() const
{
    return in_price;
}

void Products::setIn_price(float value)
{
    in_price = value;
}
float Products::getPrev_price() const
{
    return prev_price;
}

void Products::setPrev_price(float value)
{
    prev_price = value;
}

QString Products::getPrevPriceS()
{
    QVariant tmp=prev_price;
    return tmp.toString();
}
QString Products::getManufactur() const
{
    return manufactur;
}

void Products::setManufactur(const QString &value)
{
    manufactur = value;
}
QString Products::getCountry() const
{
    return country;
}

void Products::setCountry(const QString &value)
{
    country = value;
}
QString Products::getArtikul() const
{
    return artikul;
}

void Products::setArtikul(const QString &value)
{
    artikul = value;
}


Products* pick_row(string s)
{
    Products * product;
    int k=0,z=1;
    string arg1="",arg2="",arg3="",temp="";
    for(int i=0;i<=s.size();i++)
    {

       if (s[i]==';'||i==s.size())
       {

           if(k==0)
           {
                arg1 = temp;
                k++;
                z=0;
                 temp="";
               //  break;
             //  cout << arg1.c_str()<<" " ;
           }
           else if(k==1)
           {
               arg2=temp;
               k++;
               z=0;
             // cout << arg2.c_str()<<" ";
                temp="";
               // break;
           }
           else if(k==2)
           {
               arg3=temp;
               k=0;
               z=0;
             //  cout << arg3.c_str()<<endl;
                temp="";
                break;

           }

       }
       else if(z!=0)
       {
            temp+=s[i];}
            z++;
               }
    float cena=0.0;
    sscanf( arg3.c_str(),"%f",&cena);
   //  cout << cena<<endl;

    QString str1 = QString::fromUtf8(arg1.c_str());
    QString str2 = QString::fromUtf8(arg2.c_str());
    QString str3 = QString::fromUtf8(arg3.c_str());
    product =new Products(str1,str2,str3);

    return product;
}




void load_goods_csv(int col_count, ListElem<Products> &elem, const char *filename){

    Products *product;
    string buf="";
    ifstream file;
    file.open(filename,ios_base::in);

    if(file)
    {
        int k=0;
        string arg1="",arg2="",arg3="";
        while(!file.eof())
        {

               product =new Products();
               getline(file,buf);

                  product=pick_row(buf);
                  elem.add(*product);
                  k=0;
                  buf="";
        }
    }
}







