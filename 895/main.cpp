#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <queue>
#include <stack>

using namespace std;

/********************** TO SLOW **************************/
/***** The comp for priority_queue comp(a, b) if a < b, then a go before b, when use top(), get the **last item** **************/
//struct Comp {
    //bool operator () (int a, int b) {
        //return a < b;
    //}
//};

//struct Item {
    //int freq;
    //int val;
    //priority_queue<int, vector<int>, Comp> indices;

    //int top() {
        //return indices.top();
    //}

    //void push(int index) {
        //++freq;
        //indices.push(index);
    //}

    //int pop() {
        //int idx = indices.top();
        //indices.pop();
        //--freq;

        //return idx;
    //}

    //bool empty() {
        //return freq <= 0;
    //}

    //Item(int val, int index) {
        //this->val = val;
        //indices.push(index);
        //freq = 1;
    //}
//};

//class mQueue {
//public:
    //vector<Item> q;

    //bool empty() {
        //return q.empty();
    //}
    //void _push(Item elm) {
        //if (empty()) {
            //q.push_back(elm);
            //return;
        //}

        //auto insert_iter = q.end();
        //for (auto iter=q.begin(); iter != q.end(); ++iter) {
            //if (elm.freq == iter->freq) {
                //if (elm.top() > iter->top()) {
                    //insert_iter = iter;
                    //break;
                //}
            //}
            //else if (elm.freq > iter->freq) {
                //insert_iter = iter;
                //break;
            //}
        //}

        //q.insert(insert_iter, elm);
    //}

    //void push(int val, int index) {
        //Item elm(val, index);

        //for (auto iter=q.begin(); iter != q.end(); ++iter) {
            //if (iter->val == elm.val) {
                //iter->push(elm.top());
                //elm = *iter;
                //q.erase(iter);
                //break;
            //}
        //}
        //_push(elm);
    //}

    //int pop() {
        //Item top_elm = q[0];
        //q.erase(q.begin());
        //int top_val = top_elm.val;

        //top_elm.pop();
        //if (!top_elm.empty()) {
            //_push(top_elm);
        //}

        //return top_val;
    //}
//};

//class FreqStack {
    //long long cur_index;
    //mQueue q;

//public:
    //FreqStack() {
        //cur_index = 0;
    //}
    
    //void push(int x) {
        //q.push(x, cur_index++);
    //}
    
    //int pop() {
        //return q.pop();
    //}
//};
//


/**** search O(1) ******/
/***** Stack of stacks *****/

class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> s;
    int max_freq;

    FreqStack() {
        max_freq = 0;
    }

    void push(int x) {
        freq[x] += 1;
        max_freq = max(max_freq, freq[x]);

        s[freq[x]].push(x);
    }

    int pop() {
        int x = s[max_freq].top();
        s[max_freq].pop();
        if (!s[freq[x]--].size()) {
            max_freq--;
        }

        return x;
    }

};

int main () {
    FreqStack s;
    s.push(5);
    s.push(7);
    s.push(5);
    s.push(7);
    s.push(4);
    s.push(5);
    
    for (int i = 0; i < 4; ++i) {
        std::cout << s.pop() << std::endl;
    }

    return 0;
}
