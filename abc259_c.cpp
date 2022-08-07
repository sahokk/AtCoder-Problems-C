//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


void RLE(string s, vector<pair<char, int>> &vec){
    int cnt = 1;
    FOR(i, 1, (int)s.size()){
        if(s[i] != s[i-1]){
            vec.PB({s[i-1], cnt});
            cnt = 0;
        }
        cnt++;
    }
    vec.PB({s.back(),cnt});
}

int main(){
    string s, t;
    cin >> s >> t;
    vector<pair<char, int>> svec, tvec;
    RLE(s, svec); RLE(t, tvec);
    
    bool ans = true;
    REP(i, (int)svec.size()){
        if((int)svec.size() != (int)tvec.size()) ans = false;
        if(svec[i].first != tvec[i].first) ans = false;
        if(!(svec[i].second == tvec[i].second || (svec[i].second < tvec[i].second && svec[i].second >= 2))) ans = false;
    }
    cout << (ans ? "Yes":"No") << endl;
    return 0;
}