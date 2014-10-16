#ifndef PRODUCTS_H
#define PRODUCTS_H
#include "QString.h"
#include "QVariant.h"
#include "listelem.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

class Products
{
public:
    Products();
    Products(QString art,QString naim,QString cena );
    QString getTitle() const;
    void setTitle(const QString &value);

    int getId() const;
    void setId(int value);

    QString getId_1c() const;
    void setId_1c(const QString &value);

    QString getMesure_unit() const;
    void setMesure_unit(const QString &value);

    float getPrice() const;
    QString getPriceS() ;
    void setPrice(float value);
    void setPriceS(QString value);

    float getIn_price() const;
    void setIn_price(float value);

    float getPrev_price() const;
    void setPrev_price(float value);
    QString getPrevPriceS() ;

    QString getManufactur() const;
    void setManufactur(const QString &value);

    QString getCountry() const;
    void setCountry(const QString &value);

    QString getArtikul() const;
    void setArtikul(const QString &value);



private:
    QString title;
    QString artikul;
    int id;
    QString id_1c;
    QString mesure_unit;
    float price;
    float in_price;
    float prev_price;
    QString manufactur;
    QString country;

};

void load_goods_csv(int col_count, ListElem<Products> &elem, const char * filename);

#endif // PRODUCTS_H




