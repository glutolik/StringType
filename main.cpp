#include "StringType.h"
using namespace std;

int main()
{
    string s;
    string p;
    cin >> s >> p;
    const char* sc = s.c_str();
    const char* pc = p.c_str();
    StringType str(sc);
    StringType pattern(pc);
    cout << like(str, pattern, '\\', true) << endl;
    cout << Like(pattern).match(str) << endl;
    std::string m_str = str.get_str();
    return 0;
}
