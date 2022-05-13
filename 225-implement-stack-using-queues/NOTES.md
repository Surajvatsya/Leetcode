int ele = q2.front();
q2.pop();
q2.push(ele);
n--;
}
int ele = q2.front();
q2.pop();
return ele;
}
int top() {
if(!q1.empty()){
return q1.back();
}
return q2.back();
}
bool empty() {
if(q1.empty() and q2.empty())
return true;
return false;
}
};
```