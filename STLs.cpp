
//icpc Mansoura
//-------------------------------------------
//A-Queue ID
#include <iostream>
using namespace std;
#include <queue>
int main(){
    queue <int> q;
    int t;
    cin>>t;
    while(t--){
        int id,n;
        cin>>id>>n;
        if(id==1){
            q.push(n);
        }
        else if(id==2){
            if(q.empty()){
                cout<<"no\n";
            }
            else{
                if(q.front()==n){
                    cout<<"yes\n";
                }
                else{
                    cout<<"no\n";
                }
                q.pop();
            }
        }
    }
}
//-----------------------------------------------------
//B-Deque Easy Version
#include <iostream>
using namespace std;
#include <queue>
int main(){
    deque <long long>dq;
    int q;
    cin>>q;
    while(q--){
        string s;
        long long x;
        cin>>s;
        if(s=="push_back"){
            cin>>x;
            dq.push_back(x);
        }
        else if(s=="front"){
            cout<<dq.front()<<"\n";
        }
        else if(s=="back"){
            cout<<dq.back()<<"\n";
        }
        else if(s=="push_front"){
            cin>>x;
            dq.push_front(x);
        }
        else if(s=="print"){
            cin>>x;
            cout<<dq[x-1]<<"\n";
        }
        else if(s=="pop_back"){
            dq.pop_back();
        }
        else if(s=="pop_front"){
            dq.pop_front();
        }
    }
}
//--------------------------------------------
//C-Regular Bracket Sequence (Easy Version)
#include <iostream>
using namespace std;
#include <stack>
int main(){
    stack <int>st;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push('(');
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                cout<<"No";
                return 0;
            }
        }
    }
    if(st.empty()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
//----------------------------------------------------
//D-Case of the Zeros and Ones
#include <iostream>
using namespace std;
#include <stack>
int main(){
    stack <int> st;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(!st.empty()){
            if(st.top()!=s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        else{
            st.push(s[i]);
        }
    }
    cout<<st.size();     
}
//---------------------------------------
//E-Prepend and Append
#include <iostream>
using namespace std;
#include <queue>
int main(){
    deque <int> dq;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            dq.push_back(s[i]);
        }
        while(true){
            if(dq.empty()){
                break;
            }
            if(dq.front()!=dq.back()){
                dq.pop_front();
                dq.pop_back();
            }
            else{
                break;
            }
        }
        cout<<dq.size()<<"\n";
        dq.clear();
    }
}
//------------------------------------------
//H-Hotelier
#include <iostream>
using namespace std;
#include <vector>
int main(){
    int n;
    cin>>n;
    vector <int> v(10,0);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='L'){
            for(int j=0;j<v.size();j++){
                if(v[j]==0){
                    v[j]=1;
                    break;
                }
            }
        }
        else if(s[i]=='R'){
            for(int j=9;j>=0;j--){
                if(v[j]==0){
                    v[j]=1;
                    break;
                }
            }
        }
        else if(s[i]>='0' && s[i]<='9'){
            v[s[i]-'0']=0;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}
//------------------------------------------
//F-Regular Bracket Sequence
#include <iostream>
using namespace std;
#include <stack>
int main(){
    stack<char>st;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push('(');
        }
        else{
            if(!st.empty()){
                st.pop();
                count+=2;
            }
        }
    }
    cout<<count;
}
//-----------------------------------------------
//G-Regular Bracket Sequence(Hard Version)
#include <iostream>
using namespace std;
#include <stack>
int main(){
    stack<char>st;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='<' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                cout<<"No";
                return 0;
            }
            if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    cout<<"No";
                    return 0;
                }
            }
            else if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    cout<<"No";
                    return 0;
                }
            }
            else if(s[i]=='>'){
                if(st.top()=='<'){
                    st.pop();
                }
                else{
                    cout<<"No";
                    return 0;
                }
            }
            else if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else{
                    cout<<"No";
                    return 0;
                }
            }
        }
    }
    if(st.empty()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
//----------------------------------------------
//I-Permutation Minimization by Deque
#include <iostream>
using namespace std;
#include <queue>
int main(){
    deque<int>dq;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            if(dq.empty()){
                dq.push_back(p[i]);
            }
            else{
                if(p[i]<dq.front()){
                    dq.push_front(p[i]);
                }
                else{
                    dq.push_back(p[i]);
                }
            }
        }
        for(int i=0;i<dq.size();i++){
            cout<<dq[i]<<" ";
        }
        cout<<"\n";
        dq.clear();
    }
}
//-----------------------------------------
//J-Table Tennis
#include <iostream>
using namespace std;
#include <queue>
int main(){
    long long n,k,c=0;
    cin>>n>>k;
    deque<long long>dq(n);
    for(int i=0;i<n;i++){
        cin>>dq[i];
    }
    if(k>=n-1){
        long long max=dq[0];
        for(int i=0;i<dq.size();i++){
            if(max<dq[i]){
                max=dq[i];
            }
        }
        cout<<max;
    }
    else{
        while(c<k){
            if(dq[0]>dq[1]){
                dq.push_back(dq[1]);
                dq.erase(dq.begin()+1);
                c++;
            }
            else{
                c=1;
                dq.push_back(dq[0]);
                dq.erase(dq.begin());
            }
        }
        cout<<dq.front();
    }
}
//-----------------------------------------------
//L-Queue
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
int main(){
    long long n,count=0;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long sum=0;
    for(int i=0;i<n;i++){
        if(v[i]>=sum){
            count+=1;
            sum+=v[i]; 
        }
    }
    cout<<count;
}
//---------------------------------
//M-Kefa and Frist Step
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
int main(){
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long length=1,max_len=1;
    for(int i=1;i<v.size();i++){
        if(v[i]>=v[i-1]){
            length++;
        }
        else{
            length=1;
        }
        max_len=max({length,max_len});
    }
    cout<<max_len; 
}
//------------------------------------------
//O-Game with String
#include <iostream>
using namespace std;
#include <queue>
int main(){
    deque<char>dq;
    string s;
    int count=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(dq.empty() || s[i]!=dq.back()){
            dq.push_back(s[i]);
        }
        else{
            dq.pop_back();
            count+=1;
        }
    }
    if(count%2==0){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}
//-----------------------------------
//K-Meximization
#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <vector>
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
        sort(v.begin(),v.end());
        vector<int>v1;
        vector<int>v2;
        if(v1.empty()){
            v1.push_back(v[0]);
        }
        for(int i=1;i<v.size();i++){
            if(v[i]!=v[i-1]){
                v1.push_back(v[i]);
            }
            else{
                v2.push_back(v[i]);
            }
        }
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        for(int i=0;i<v2.size();i++){
            cout<<v2[i]<<" \n";
        }
    }
}
//---------------------------------------
//N-Bad Prices
#include <iostream>
using namespace std;
#include <vector>
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,bad=0;
        cin>>n;
        vector<long long>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        long long min=v.back();
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>min){
                bad+=1;
            }
            else{
                min=v[i];
            }
        }
        cout<<bad<<"\n";
        v.clear();
    }
}
//------------------------------------------
//S-Minimal String
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
int main(){
    vector <int>v(26,0);
    string s;
    cin>>s;
    for(char c:s){
        v[c-'a']++;
    }
    int min_char=0;
    stack<char>t;
    string u="";
    for(int i=0;i<s.length();i++){
        t.push(s[i]);
        v[s[i]-'a']--;
        while(min_char < 26 && v[min_char]==0){
            min_char++;
        }
        while(!t.empty()&&t.top()-'a'<=min_char){
            u.push_back(t.top());
            t.pop();
        } 
    }
    while(!t.empty()){
        u.push_back(t.top());
        t.pop();
    }
    cout<<u;
}
//-----------------------------------
//P-Great vova wall
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
int main(){
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<v.size();i++){
        if(v[i]%2==0){
            v[i]=0;
        }
        else{
            v[i]=1;
        }
    }
    stack<long long>st;
    for(int i=0;i<v.size();i++){
        if(st.empty()){
            st.push(v[i]);
        }
        else if(st.top()==v[i]){
            st.pop();
        }
        else{
            st.push(v[i]);
        }
    }
    if(st.size()<=1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
//continue....