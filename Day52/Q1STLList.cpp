#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n, p;
    cout << "Enter number of products: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter prices of products: ";
    for (int i = 0; i < n; ++i){
        cin >> prices[i];
	}
    cout << "Enter price to search for: ";
    cin >> p;

    if (find(prices.begin(), prices.end(), p) != prices.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
  
    sort(prices.begin(), prices.end());
    cout << "Sorted prices: ";
    for (int price : prices){
        cout << price << " ";
    }
    cout << endl;
    int totalCost = accumulate(prices.begin(), prices.end(), 0);
    cout << "Total cost: " << totalCost << endl;

    int maxPrice = *max_element(prices.begin(), prices.end());
    int minPrice = *min_element(prices.begin(), prices.end());
    cout << "Max price: " << maxPrice << endl;
    cout << "Min price: " << minPrice << endl;

    return 0;
}
