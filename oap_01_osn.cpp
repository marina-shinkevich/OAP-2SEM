#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

void compr(string& str)
{
 int i = 0;
 while (i < str.length())
 {
  if (str[i] == ' ')
  {
   str = str.erase(i, 1);
  }
  else
  {
   i++;
  }
 }
}

void f(string* str, ...)
{
 string** cp = &str;
 while (*cp != NULL)
 {
  compr(**cp);

  cout << **cp << endl;
  cp++;
  
 }
}


int main(int argc, char* argv[])
{


 string s1 = "df gd fg ";
 string s2 = "df gd dfgdfg gdfg5434fg ";
 string s3 = "df g ds gdf gg d d fg ";
 


 f(&s1, &s2,&s3, NULL);

 string s4 = "df gd fg ";
 string s5 = "df gd dfgdfg gdfg5434fg ";
 f(&s4, &s5, NULL);

 string s6 = "df gd fg";
 string s7 = "df gd dfgdfg gdfg5434fg";
 string s8 = "df g ds gdf gg d d fg";
 string s9 = "df gd fg ";
 string s10 = "df gd dfgdfg gdfg5434fg";
 f(&s6, &s7, &s8, &s9, &s10, NULL);




 return 0;
}
