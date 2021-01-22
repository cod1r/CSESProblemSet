#include <bits/stdc++.h>
using namespace std;


struct _next {
    int disk = NULL;
    int target = NULL;
    int cannot = NULL;
    _next(int _disk, int _target, int _cannot){
        disk = _disk;
        target = _target;
        cannot = _cannot;
    }
};

int main(){
    int disks; cin >> disks; 
    // maybe later
    // vector<int> a, b, c;
    unordered_map<int, int> loc;
    unordered_map<int, vector<int>> stacks;
    vector<pair<int, int>> path;
    stacks[1] = vector<int>{};
    int moves = 0;

    const int loop_limit = 30000;

    for (int d = disks; d >= 1; d--){
        loc[d] = 1;
        stacks[loc[d]].push_back(d);
    }
    for (int d = disks; d >= 1; d--){
        stack<_next> s;

        s.push(_next(d, 3, NULL));
        int counter = 0;
        
        while(
                s.size() > 0 && 
                // if "home stack" doesn't have the disk you want to pop off on top
                (
                    (stacks[loc[s.top().disk]].back() != d) || 
                // if the "target stack" has a smaller disk on top or multiple smaller disks on top
                    (stacks[s.top().target].size() > 0 && stacks[s.top().target].back() < s.top().disk)
                )
            )
            {
            if (++counter > loop_limit){
                // printf("s size: %d, stack of current disk's size: %d\n", s.size(), stacks[loc[d]].size());
                throw runtime_error("inf loop");
            }
            // if "home stack" doesn't have the disk you want to pop off on top then those other disks
            // need to go the their placeholder stacks
            int ndx = 0;
            for (; ndx < stacks[loc[s.top().disk]].size(); ndx++){
                if (stacks[loc[s.top().disk]][ndx] < s.top().disk) break;
            }
            for (; ndx < stacks[loc[s.top().disk]].size(); ndx++){
                int n = stacks[loc[s.top().disk]][ndx];
                int go;
                if (loc[n] != 1 && s.top().target != 1 && loc[s.top().disk] != 1)
                    go = 1;
                else if (loc[n] != 2 && s.top().target != 2 && loc[s.top().disk] != 2)
                    go = 2;
                else if (loc[n] != 3 && s.top().target != 3 && loc[s.top().disk] != 3)
                    go = 3;
                // printf("%d going to %d and cannot go to %d\n", n, go, s.top().target);
                s.push(_next(n, go, s.top().target)); 
            }
			//printf("s size: %d, s.top: %d", s.size(), s.top().disk);
			//return 0;
            // if the "target stack" has a smaller disk on top or multiple smaller disks on top
            if (stacks[s.top().target].size() > 0 && stacks[s.top().target].back() < s.top().disk){
                // printf("current disk: %d, target stack: %d, disk in the way: %d\n", s.top().disk, s.top().target, stacks[s.top().target].back());
                // if the target stack is the last stack and
                // some disks are already on the last stack and don't need to be touched again
                int index = 0;
                for (int ii = 0; ii < stacks[s.top().target].size(); ii++){
                    if (stacks[s.top().target][ii] > s.top().disk){
                        index++;
                    }
                }
                // stores the current disk we want to pop off of and keeps the target stack the same
                _next working_top = s.top();
                for (; index < stacks[working_top.target].size(); index++){
                    int t = stacks[working_top.target][index];
                    int go;
                    if (loc[t] != 1 && s.top().target != 1 && loc[s.top().disk] != 1)
                        go = 1;
                    else if (loc[t] != 2 && s.top().target != 2 && loc[s.top().disk] != 2)
                        go = 2;
                    else if (loc[t] != 3 && s.top().target != 3 && loc[s.top().disk] != 3)
                        go = 3;
                    
                    if (go > 3) {
                        printf("top: %d %d %d, t: %d\n", s.top().disk, s.top().target, s.top().cannot, t); 
                        throw runtime_error("conditions not working");
                    }
                    s.push(_next(t, go, s.top().target));
                }
            }
            
            // after the "home stack" has the right disk on top and the "target stack" either has a disk on top that is bigger than the disk you are trying to put on top or the stack is empty
            int counter2 = 0;
            while(s.size() > 0){
                if (++counter2 > loop_limit) throw runtime_error("inf loop2");
                // printf("s top: %d %d %d %d\n", s.top().disk, s.top().target, s.top().cannot, loc[s.top().target]);
                if (
                        // checks if the current stack has size greater than zero and that the current disk is on top
                        stacks[loc[s.top().disk]].size() > 0 && stacks[loc[s.top().disk]].back() == s.top().disk && 
                        // checks if the target stack is either zero or has bigger disks on it
                        (stacks[s.top().target].size() == 0 || stacks[s.top().target].back() > s.top().disk)
                    ){
                    int top_disk = s.top().disk;
                    int past_stack = loc[top_disk];
                    int target_stack = s.top().target;
                    // pops off current stack
                    stacks[loc[top_disk]].pop_back();
                    // redefines the location or stack of top_disk
                    loc[top_disk] = target_stack;
                    // pushes onto target stack
                    stacks[target_stack].push_back(top_disk);
                    // pops the instruction off the stack
                    s.pop();
                    // increments the total amount of moves
                    moves ++;
                    // printf("Stack size: %d, Disk: %d, Going to: %d\n", s.size(), top_disk, target_stack);
                    // printf("%d %d\n", past_stack, target_stack);
                    path.push_back(pair<int, int>{past_stack, target_stack});
                }
                else if (stacks[loc[s.top().disk]].back() != s.top().disk){
                    // printf("Top of stack: %d, Disk that is supposed to be on top: %d\n", stacks[loc[s.top().disk]].back(), s.top().disk);
                    break;
                }
                else if (stacks[s.top().target].back() < s.top().disk){
                    // printf("current disk: %d, greater than disk on target stack: %d\n", s.top().disk, s.top().target);
                    break;
                }
            }
        }
            // after the "home stack" has the right disk on top and the "target stack" either has a disk on top that is bigger than the disk you are trying to put on top or the stack is empty
            int counter2 = 0;
            // printf("2info stack size: %d\n", s.size());
            while(s.size() > 0){
                if (++counter2 > loop_limit) throw runtime_error("inf loop2");
                if (stacks[loc[s.top().disk]].size() > 0 && stacks[loc[s.top().disk]].back() == s.top().disk){
                    int top_disk = s.top().disk;
                    int past_stack = loc[top_disk];
                    int target_stack = s.top().target;
                    // pops off current stack
                    stacks[loc[top_disk]].pop_back();
                    // redefines the location or stack of top_disk
                    loc[top_disk] = target_stack;
                    // pushes onto target stack
                    stacks[target_stack].push_back(top_disk);
                    // printf("Stack size: %d, Disk: %d, Going to: %d\n", s.size(), s.top().disk, s.top().target);
                    // pops the instruction off the stack
                    s.pop();
                    // increments the total amount of moves
                    moves ++;
                    // printf("%d %d\n", past_stack, target_stack);
                    path.push_back(pair<int, int>{past_stack, target_stack});
                }
                else if (stacks[loc[s.top().disk]].back() != s.top().disk){
                    // printf("Top of stack: %d, Disk that is supposed to be on top: %d\n", stacks[loc[s.top().disk]].back(), s.top().disk);
                    break;
                }
            }
    }
    // printf("Final last stack size: %d\n", stacks[3].size());
    printf("%d\n", moves);
    for (pair<int, int> p : path)
        printf("%d %d\n", p.first, p.second);
    // printf("Contents\n");
    // for (int i : stacks[3])
    //     printf("%d\n", i);
    return 0;
}
