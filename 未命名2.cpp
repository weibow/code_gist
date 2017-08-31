#include <iostream>
class Test1  
{  
public :  
    Test1(int num):n(num){}  
private:  
    int n;  
};  
class Test2  
{  
public :  
 //   explicit Test2(int num):n(num){}  
      Test2(int num):n(num){}  
      int show() const
      {
      	return n;
      }
private:  
    int n;  
};  

class String {
	public :
		String(const char*p);
};
  
int main()   
{  
    Test1 t1 = 12;  
    Test2 t2(13); 
 //  Test2 t3 = 14;
   using namespace std; 
   String s1 = "hello";
   std::cout << t2.show() << std::endl; 
   std::cout  << s1.String() << std::endl;
    return 0;  
}  

    