/* Solve problme that finds the largest suqare size rectangular from the given 
array of rectangulars heights which have all width = 1 */


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> h = {3, 5, 7, 6, 5, 2, 1}; // Vector with rectangular heights which all width are 1

// we can solve this problem with sweeping algorithm and stack
int solveStack(){
    stack<int> remaining; // Put remaining rectangular in the stack
    
    h.push_back(0);
    int ret = 0;
    
    // find the largest size rectangular for every element in the vector h
    for(int i = 0; i < h.size(); i++){
        //if the rightmost remaining rectangular is taller than the current h[i],
        // the largest area will be ends with i
        
        // stack pop with every iteration -> n times O(n)
        while(!remaining.empty() && h[remaining.top()] >= h[i]){
            int j = remaining.top();
            remaining.pop();
            int width = -1;
            
            if(remaining.empty())
                width = i;
            else
                width = (i - remaining.top() - 1);
            ret = max(ret, h[j] * width);
        }
        remaining.push(i);
    }
    return ret;
}

int main(){
    cout << solveStack() << endl;
    return 0;
}