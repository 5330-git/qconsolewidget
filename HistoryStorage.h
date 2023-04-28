#ifndef HISTORYSTORAGE_H
#define HISTORYSTORAGE_H

/*
* Decoded by Utf-8
* Versions
*   v-1.0.0 2023/4/27
* Author:
*   Anton :blog address --> https://blog.csdn.net/yyy11280335?spm=1000.2115.3001.5343
*
* Introduction:
*   本文件用于实现用户历史输入的回滚容器，通过派生std::vector<>实现
*   This file provides a realization of storage of user history input and message roll back By deriving template std::vector<>
*/

#include <vector>
#include<QDebug>
// Forward Declaration：
namespace AntonaQConsoleWidget{
    template<typename type_Ele> class HistoryStorage;
}

// Details:
namespace AntonaQConsoleWidget{
    template<typename type_Ele>
    class HistoryStorage:protected std::vector<type_Ele>{
    protected:
        // 以下变量用于定位数据放置区域以及读取位点
        std::size_t bottom_index;       // 数据放置区起始点
        std::size_t top_index;          // 数据放置区终点
        std::size_t read_index;         // 读取位点
        std::size_t max_size;
    public:
        using iterator = typename std::vector<type_Ele>::iterator;

        // 数据放置部分
        void push(const type_Ele& ele);

        // 数据清除部分
        void clear();

        // 数据读取部分
        type_Ele& readForward();        // 以栈的方法读取数据，即返回上一条数据
        type_Ele& readBackward();       // 以队列的方式读取数据，即返回下一条数据

        // 迭代器部分(标准库迭代器的获取)
        iterator begin();
        iterator end();

        // 构造函数
        HistoryStorage(std::size_t max_s = 50);
        // 析构函数
        virtual ~HistoryStorage();
    };
}

// template class member functions defines:
namespace AntonaQConsoleWidget{
    template<typename type_Ele>
    void HistoryStorage<type_Ele>::push(const type_Ele& ele){
        this->operator[](this->top_index) = ele;
        this->read_index = this->top_index;
        top_index = (top_index+1)%this->size(); // 向后移动末尾指针
        if(top_index == bottom_index){
            // 存储空间已经存满，默认回到前面进行覆盖，同时移动起始指针
            this->bottom_index = (bottom_index+1)%this->size();
        }
    }
    template<typename type_Ele>
    void HistoryStorage<type_Ele>::clear(){
        this->bottom_index = 0;
        this->top_index = 0;
        this->read_index = 0;
    }
    template<typename type_Ele>
    type_Ele& HistoryStorage<type_Ele>::readForward(){
        std::size_t read_pos = this->read_index;
//        qDebug()<<"bottom"<<this->bottom_index;
//        qDebug()<<"read_pos"<<read_pos;
//        qDebug()<<"top"<<this->top_index;
        if(this->top_index == this->bottom_index){
            // 初始情况，直接返回bottom
            return this->operator[](0);
        }
        this->read_index = (read_index == 0)?top_index:read_index-1;
        if(this->read_index == top_index){
            // 阅读位点等于末尾位点，而top_index位点是不可用的，因此需要将阅读位点移动当起始位点
            if(this->top_index == 0){
                // 序列的末尾在vector之首，那么阅读位点应该在top_index之前一位，也就是vector之尾
                this->read_index = this->size()-1;
            }
            else{

                this->read_index = top_index - 1;
            }

        }
        return this->operator[](read_pos);
    }

    template<typename type_Ele>
    type_Ele& HistoryStorage<type_Ele>::readBackward(){
        std::size_t read_pos = this->read_index;
//        qDebug()<<"bottom"<<this->bottom_index;
//        qDebug()<<"read_pos"<<read_pos;
//        qDebug()<<"top"<<this->top_index;
        if(this->top_index == this->bottom_index){
            // 初始情况，直接返回bottom
            return this->operator[](0);
        }
        this->read_index = (read_index+1)%this->size();
        if(this->read_index == this->top_index){
            this->read_index = this->bottom_index;
        }
        return this->operator[](read_pos);
    }

    template<typename type_Ele>
    typename HistoryStorage<type_Ele>::iterator HistoryStorage<type_Ele>::begin(){
        return this->std::vector<type_Ele>::begin();
    }

    template<typename type_Ele>
    typename HistoryStorage<type_Ele>::iterator HistoryStorage<type_Ele>::end(){
        return this->std::vector<type_Ele>::end();
    }

    template<typename type_Ele>
    HistoryStorage<type_Ele>::HistoryStorage(std::size_t max_s){
        this->bottom_index = 0;
        this->top_index = 0;
        this->read_index = 0;
        this->max_size = max_s;
        this->resize(this->max_size);
    }

    template<typename type_Ele>
    HistoryStorage<type_Ele>::~HistoryStorage(){
        ;
    }
}

#endif
