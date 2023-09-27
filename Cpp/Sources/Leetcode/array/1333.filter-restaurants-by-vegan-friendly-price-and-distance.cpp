#include "LC.h"

class Restarant {
public:
    int id;
    int rating;
    int veganFriendly;
    int price;
    int distance;

    Restarant(int id, int rating, int veganFriendly, int price, int distance) : id(id), rating(rating),
                                                                                veganFriendly(veganFriendly),
                                                                                price(price), distance(distance) {}
};

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<Restarant> filtered;
        for (auto restaurant: restaurants) {
            if (restaurant[3] <= maxPrice && restaurant[4] <= maxDistance) {
                if (!veganFriendly) {
                    filtered.emplace_back(restaurant[0],
                                          restaurant[1],
                                          restaurant[2],
                                          restaurant[3],
                                          restaurant[4]);
                    continue;
                }
                if (restaurant[2])
                    filtered.emplace_back(restaurant[0],
                                          restaurant[1],
                                          restaurant[2],
                                          restaurant[3],
                                          restaurant[4]);
            }
        }
        std::sort(filtered.begin(), filtered.end(), [](Restarant a, Restarant b) {
            if (a.rating == b.rating) return a.id > b.id;
            return a.rating > b.rating;
        });
        vector<int> ans;
        for (auto i: filtered) {
            ans.push_back(i.id);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> restaurants = {{1, 4,  1, 40, 10},
                                       {2, 8,  0, 50, 5},
                                       {3, 8,  1, 30, 4},
                                       {4, 10, 0, 10, 3},
                                       {5, 1,  1, 15, 1}};
    auto ans = s.filterRestaurants(restaurants, 1, 50, 10);
    for (auto i: ans) {
        cout << i << " ";
    }
}