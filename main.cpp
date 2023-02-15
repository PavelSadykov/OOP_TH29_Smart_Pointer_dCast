//
//  main.cpp
//  ООП ДЗ 29 Умные указатели
//
//  Created by Павел on 10.02.2023.
//

#include <iostream>

class Parent{
public:
   virtual  void bar(){
        std::cout<<"Parent::bar()"<< std::endl;
    }
    virtual void qux(){
        std::cout<<"Parent::qux()"<< std::endl;
    }
};

class Child : public Parent{
public:
    void bar() override{
        std::cout<<"Child::bar()"<< std::endl;
        
    }
    void qux()override{
        std::cout<<"Child::qux()"<< std::endl;
    }
};


int main(int argc, const char * argv[]) {
   std::shared_ptr <Parent> parent = std::make_shared<Child>();
    parent->bar();//на экране Child::bar()
    parent->qux();//на экране Child::qux()
   std::shared_ptr <Parent> parent1 = std::shared_ptr<Child>(new Child());
   if(parent == nullptr){//если каст не произойдет то указатель будет указывать на nullptr
        std::cout<<"parent is nullptr"<<std::endl;
    }else{
        std::cout<<"OK"<<std::endl;    }
    parent1->bar();//на экране Child::bar()
    parent1->qux();//на экране Child::qux()
    
    
    return 0;
}
