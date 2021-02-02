#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    vector<int> stk;
    int curr = 0;
    int prev = 0;
    int dist = 0;
    int omax = 0;

    if(a.size() == 1) return 1;
    if (all_of(a.begin(), a.end(), [&] (int i) {return i == a[0];}))
        return a.size();

    for(int i=0; i<a.size(); i++ ){
        curr = prev = a[i];
        stk.push_back(a[i]);
        for(int j = i+1; j<a.size(); j++){
            if(abs(a[j]-curr) <= 1){
                dist++;
                if(dist>1){ prev = curr; dist = 0; }
                curr = a[j];
                stk.push_back(curr);
            }
            else if (abs(a[j]-prev) <= 1){
                dist++;
                stk.pop_back();
                stk.push_back(a[j]);
                curr = a[j];
            }
            if(abs(stk[stk.size()-1]-stk[stk.size()-2]) > 1 && stk.size() > 1){
                int tmp=stk[stk.size()-1];
                stk.pop_back();
                stk.pop_back();
                stk.push_back(tmp);
            }
            else continue;
        }
        int cmax = (i+1)-a.size(); 
        if(stk.size()>abs(cmax)){ if(stk.size() > omax ) omax = stk.size(); break; }
        else{ 
            if(omax<stk.size())
                omax = stk.size();
            stk.clear();
            dist = 0;
        }
    }
    return omax;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
