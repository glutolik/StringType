#include "StringType.h"
using namespace std;

int main()
{
//    string s;
//    string p;
//    cin >> s >> p;
//    const char* sc = s.c_str();
//    const char* pc = p.c_str();
//    StringType str(sc);
//    StringType pattern(pc);
//    cout << like(str, pattern, '\\', true) << endl;
//    cout << Like(pattern).match(str) << endl;
//    cout << stack_like(str, pattern) << endl;
//    std::string m_str = str.get_str();
    ifstream in;
    ofstream out;

    in.open("tests.txt");
    std::string sc, pc;
    StringType str, pattern;
    bool res;
    clock_t work_time;
    while(!in.eof()){
        in >> sc >> pc >> res;
        str = StringType(sc);
        pattern = StringType(pc);
        work_time = clock();
        if(like(str, pattern) != res)
            cout << "Fail!" << " ";
        work_time = clock() - work_time;
        cout << "Rec time: " << (double)work_time/CLOCKS_PER_SEC << endl;
        if(stack_like(str, pattern) != res)
            cout << "Fail!" << " ";
        work_time = clock() - work_time;
        cout << "Stack time: " << (double)work_time/CLOCKS_PER_SEC << endl;
        cout << endl;


    }
    in.close();
    return 0;
}
