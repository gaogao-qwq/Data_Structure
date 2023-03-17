/* https://leetcode.cn/problems/subdomain-visit-count/ */
#include "LC.h"

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> umap;
        for(auto i : cpdomains) {
            string cnt, domain;
            auto l = i.begin(), r = i.end();
            while(*l != ' '){
                cnt.push_back(*l);
                ++l;
            }
            cout << cnt << " ";
            while(*r != ' ') {
                if(*r == '.') {
                    cout << domain << " ";
                    umap[domain] += stoi(cnt);
                }
                domain.insert(domain.begin(), *r);
                --r;
            }
            cout << domain << " ";
            umap[domain] += stoi(cnt);
        }
        for(auto i : umap) {
            ans.push_back(to_string(i.second) + " " + i.first);
        }
        return ans;
    }

int main() {
    vector<string> cpdomains{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    for(auto i : subdomainVisits(cpdomains)) {
        cout << endl << i << " ";
    }
    return 0;
}