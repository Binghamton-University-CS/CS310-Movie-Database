#ifndef Array_H
#define Array_H
#include<iostream>
using namespace std;
template <typename type>
class Array{
    public:
    type *arr;
    int limit = 1;
    Array();
    void push_back(type val);
    //void deep_push_back(type& val);
    void sort_push(type val);
    type& at(int i);
    //int at(type& x);
    void erase(int begin); //bool should be*********
    int len = 0;
    int size();
    int begin();
    void resize();
    void sort();
};

template <typename type>
Array<type>::Array(){
    arr = new type[limit];
    len = 0;
}
template <typename type>
void Array<type>::push_back(type val){
    if(len == limit){
        this->resize();
    }
    arr[len] = val;
    len++;
    return;
}
// template <typename type>
// void Array<type>::deep_push_back(type& val){
//     if(len == limit){
//         this->resize();
//     }
//     arr[len] = *val;
//     len++;
//     return;
// }
template <typename type>
void Array<type>::sort_push(type val){
    if(len == limit){
        this->resize();
    }
    arr[len] = val;
    len++;
    for (int i = len-1;i > 0; i--){
        if(arr[i]<arr[i-1]){
            type temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
    return;
}

template <typename type>
type& Array<type>::at(int i){
    return arr[i];
}
template <typename type>
void Array<type>::erase(int loc){
    if (loc >-1 && loc < len){
        arr[loc] = arr[len-1];
        len--;
    }
    type* temparr = new type[limit];
    for (int i=0; i < len; i++){
        temparr[i] = arr [i];
    }
    delete[] arr;
    arr = temparr;  
}

template <typename type>
int Array<type>::begin(){
    return 0;
}
template <typename type>
int Array<type>::size(){
    return len;
}
template <typename type>
void Array<type>::resize(){
    type* resize_arr = new type[limit*2];
    for(int i = 0; i < limit; i++){
        resize_arr[i] = arr[i];
    }
    limit*=2;
    delete[] arr;
    arr = resize_arr;    
}
#endif
