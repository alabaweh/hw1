#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  // Define a ULListStr object.
    ULListStr list ;




    string random_array []= {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                        "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
                        "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
                        "41", "42", "43", "44", "45"};



//    ULListStr dat;
//    dat.push_back("7");
//    dat.push_front("8");
//    dat.push_back("9");
//





    for(int k=0; k<21; k++)
        list.push_back(random_array[k]);


    for(int k=0; k<; k++)
        list.pop_back();


   for(int count = 0; count < 4; ++count)
   {
       list.push_back("test");

//        EXPECT_EQ("test", list.get(0));

       cout<<list.get(0)<<endl;

       list.popback();

//        EXPECT_EQ(0, list.size());

       cout<<list.size() <<endl;
//        EXPECT_EQ(true, list.empty());

       cout<<list.empty() <<endl;
   }





   list.push_front("fred");
   list.push_back("bob");


   list.displayList();



}
