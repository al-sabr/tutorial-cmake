#include <iostream>
#include <module1.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    cout << endl;
    string filepath(argv[0]);
    cout << "filepath = " << filepath << endl;
    cout << "Main function" << endl;
    module1::test(155);
    cout << std::flush;
    return 0;
}