#include <iostream>

int data =1;
int bss;
const static int rodata=1;

int main(){
int * heap=new int(3);
int stack=1;

std::cout << "code\t"<< (void*) main<<std::endl;
std::cout <<"Rodata\t"<< &rodata <<std::endl;
std::cout <<"data\t"<<&data<<std::endl;
std::cout<<"BSS\t"<<&bss<<std::endl;
std::cout<<"HEAP\t"<<heap<<std::endl;
std::cout<<"Stack\t"<<&stack<<std::endl;
}



