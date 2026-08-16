// A. Second Max Element
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        set<long long,greater<long long>>s;
        vector<long long>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            s.insert(v[i]);
        }
        if(s.size()<=1){
            cout<<-1<<"\n";
        }
        else{
            auto it=++s.begin();
            cout<<*it<<"\n";
        }
    }
}
//.......................................
// B. Tom Riddle's Diary
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin>>n;
    set <string>set;
    while(n--){
        cin>>s;
        if(set.find(s)!=set.end()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
            set.insert(s);
        }
    }
}
//........................................
// C. Registration system
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin>>n;
    map<string,int>mp;
    while(n--){
        cin>>s;
        if(mp[s]==0){
            cout<<"OK\n";
            mp[s]=1;
        }
        else{
            cout<<s<<mp[s]<<"\n";
            mp[s]++;
        }
    }
}
//.......................................
// D. Radio Station
#include <iostream>
#include <map>
using namespace std;
int main(){
    string name,ip;
    int n,m;
    cin>>n>>m;
    map<string,string>mp;
    while(n--){
        cin>>name>>ip;
        mp[ip+";"]=name;
    }
    while(m--){
        cin>>name>>ip;
        auto it=mp.begin();
        for(int i=0;i<mp.size();i++){
            if(ip==it->first){
                cout<<name<<" "<<ip<<" "<<"#"<<mp[ip]<<"\n";
            }
            it++;
        }
    }
}
//.......................................
// E. Chat Order
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string>v1;
    set<string>s;
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=v.size()-1;i>=0;i--){
        if(s.count(v[i])==0){
            v1.push_back(v[i]);
            s.insert(v[i]);
        }
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<"\n";
    }
}
//.........................................
//F. Odd Set
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int count_odd=0;
        int n;
        cin>>n;
        vector<int>v(2*n);
        for(int i=0;i<2*n;i++){
            cin>>v[i];
        }
        for(int i=0;i<v.size();i++){
            if(v[i]%2!=0){
                count_odd+=1;
            }
        }
        if(count_odd==n){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        } 
    }
}
//.......................................
// H. Bogosort
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
}
//.................................
// G. Snacktower
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    priority_queue<int>pq;
    deque<int>dq;
    for(int i=0;i<n;i++){
        cin>>v[i];
        dq.push_back(v[i]);
    }
    sort(dq.rbegin(),dq.rend());
    for(int i=0;i<v.size();i++){
        if(v[i]==dq.front()){
            cout<<v[i]<<" ";
            dq.pop_front();
            while (!pq.empty() && pq.top()==dq.front()){
                cout<<pq.top()<<" ";
                dq.pop_front();
                pq.pop();
            }
            cout<<"\n";
        }
        else{
            pq.push(v[i]);
            cout<<"\n";
        }
    }
}
//.......................................
// O. Potions (Easy Version)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    long long n,health=0,count=0;
    cin>>n;
    vector<long long>v(n);
    priority_queue<long long>pq;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<v.size();i++){
        health+=v[i];
        count++;
        if(v[i]<0){
            pq.push(-v[i]);
        }
        if(health<0){
            if(!pq.empty()){
                health+=pq.top();
                pq.pop();
                count--;
            }
        }
    }
    cout<<count;
}
//..........................................
// I. Train and Queries
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
    map<long long,int>frist_pos;
    map<long long,int>last_pos;
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            if(frist_pos[x]==0){
                frist_pos[x]=i+1;
            }
            last_pos[x]=i+1;
        }
        while(k--){
            long long a,b;
            cin>>a>>b;
            if(frist_pos.count(a) && last_pos.count(b)){
                if(frist_pos[a]<last_pos[b]){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
            }
            else{
                cout<<"NO\n";
            }
        }
        last_pos.clear();
        frist_pos.clear();
    } 
}
//............................................
// J. Powers of Two
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>v(n);
    map<long long,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long count=0;
    for(int i=0;i<v.size();i++){
        for(int k=0;k<31;k++){
            long long power=pow(2,k);
            long long target=power-v[i];
            if(mp.count(target)){
                count+=mp[target];
            }
        }
        mp[v[i]]++;
    }
    cout<<count;
}
//....................................
// K. 3SUM Closure
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
void solve(){
    int c_positive=0,c_negative=0,c_zero=0;
    int n;
    cin>>n;
    multiset<long long>ms;
    vector<long long>pos;
    vector<long long>neg;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        ms.insert(x);
        if(x>0){
            c_positive++;
            pos.push_back(x);
        }
        else if(x<0){
            c_negative++;
            neg.push_back(x);
        }
        else{
            c_zero++;
        }
    }
    if(c_positive>2){
        cout<<"NO\n";
        return;
    }
    if(c_negative>2){
        cout<<"NO\n";
        return;
    }
    vector<long long>v;
    for(long long y:pos){
        v.push_back(y);
    }
    for(long long y:neg){
        v.push_back(y);
    }
    for(int i=0;i<min(c_zero,2);i++){
        v.push_back(0);
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                long long sum=v[i]+v[j]+v[k];
                if(!ms.count(sum)){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
    ms.clear();
    pos.clear();
    neg.clear();
    v.clear();
}
//................................................
// L. Yet Another Problem About Pairs Satisfying an Inequality
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<long long>v1(n+1,0);
    for(int i=1;i<v.size();i++){
        if(v[i]<i){
            v1[i]=1;
        }
    }
    vector<long long>sum(n+1,0);
    long long count=0;
    for(int i=1;i<v1.size();i++){
        sum[i]=sum[i-1]+v1[i];
    }
    for(int j=1;j<v.size();j++){
        if(v[j]<j){
            long long target=v[j]-1;
            if(target>=1){
                count+=sum[target];
            }
        }
    }
    cout<<count<<"\n";
}
//....................................
// M. Lecture
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    map<string,string>mp;
    while(m--){
        string a,b;
        cin>>a>>b;
        if(a.size()==b.size() || a.size()<b.size()){
            mp[a]=a;
        }
        else if(a.size()>b.size()){
            mp[a]=b;
        }
    }
    while(n--){
        string s;
        cin>>s;
        cout<<mp[s]<<" ";
    }
}
//.......................................
// N. Longest Strike
#include <iostream>
#include <map>
#include <vector>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<long long>v(n);
    map<long long,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<v.size();i++){
        if(mp[v[i]]==0){
            mp[v[i]]=1;
        }
        else{
            mp[v[i]]++;
        }
    }
    vector<long long>v1;
    for(auto key:mp){
        v1.push_back(key.first);
    }
    long long current_start=-1,l=-1,r=-1,max_length=-1;
    for(int i=0;i<v1.size();i++){
        if(mp[v1[i]]>=k){
            if(current_start==-1 ||  v1[i]!=v1[i-1]+1 ){
                current_start=v1[i];
            }
            long long length=v1[i]-current_start;
            if(length>max_length){
                max_length=length;
                l=current_start;
                r=v1[i];
            }
        }
        else{
            current_start=-1;
        }
    }
    if(l==-1){
        cout<<-1<<"\n";
    }
    else{
        cout<<l<<" "<<r<<"\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
//..........................................
// P. Escape from Stones
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    deque<int>dq(s.size(),0);
    int left=0,right=s.size()-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='l'){
            dq[right]=i+1;
            right--;
        }
        else{
            dq[left]=i+1;
            left++;
        }
    }
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<"\n";
    }
}
//.......................................
// Q. Powering the Hero (easy version)
#include <iostream>
#include <queue>
using namespace std;
void solve(){
    int n;
    cin>>n;
    deque<long long>dq(n);
    for(int i=0;i<n;i++){
        cin>>dq[i];
    }
    priority_queue<long long>bouns_desk;
    long long army=0;
    for(int i=0;i<dq.size();i++){
        if(dq[i]>0){
            bouns_desk.push(dq[i]);
        }
        else if(dq[i]==0){
            if(!bouns_desk.empty()){
                army+=bouns_desk.top();
                bouns_desk.pop();
            }
        }
    }
    cout<<army<<"\n";
    while(!bouns_desk.empty()){
        bouns_desk.pop();
    }
    dq.clear();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}