#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
  string s = "HelloWorld";
  cout << s.capacity() << endl;
  cout << s.size() << endl;
  //string s2;
  //while(getline(cin,s2)){
  //  if(!s2.empty()){
  //    cout << s2 << endl;
  //  }
  //}
 
  for(auto &c : s)
    c = toupper(c);
  cout << s << endl;
  
  
  return 0;
}
