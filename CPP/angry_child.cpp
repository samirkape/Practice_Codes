#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {

    int size  = arr.size();
    sort(arr.begin(), arr.end());
    int result = INT32_MAX;
    for(auto i = 0; i+k-1 < size; i++){
        int tmpres = abs(arr[i] - arr[i+(k-1)]);
        if ( tmpres < result ) result = tmpres;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
