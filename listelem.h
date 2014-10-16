#ifndef LISTELEM_H
#define LISTELEM_H
#include <vector>
#include <iostream>
#include <iterator>
#include <string.h>

using namespace std;


template <typename elemtype>

class ListElem{
public:
    ListElem()
    {
        list_of_elem =new vector<elemtype>;
        beg_pos=0;
        length=0;
    }

    void add(elemtype &elem){

        list_of_elem->push_back(elem);
        length++;


    }
    elemtype it_elem(int i)
    {
        return list_of_elem->operator [](i);
    }
    //friend class ListElem_iterator;
    /*typedef ListElem_iterator<elemtype> iterator;
     ListElem_iterator<elemtype> begin() const
    {
        return (list_of_elem->begin());
    }
    ListElem_iterator<elemtype> end() const
    {
        return list_of_elem->end();
    }
    typedef iteratorlist iterator;
    iteratorlist begin()
    {
                return list_of_elem->begin();
            }
            iteratorlist end()
            {
                        return list_of_elem->end();
                    }

*/
    void delete_elem(elemtype &elem);
    void load_from_file(string file_name);
    void load_in_file(string file_name);
    int count_elem(){
        return length;
    }

    ~ListElem(){
        delete list_of_elem;
    }

private:
    vector<elemtype> *list_of_elem;
    int beg_pos;
    int length;

};

#endif // LISTELEM_H
