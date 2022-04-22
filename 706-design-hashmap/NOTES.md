```
class MyHashMap {
public:
//brute force
//map index of array with the value
vector<int>v;
MyHashMap() {
v = vector<int>(1e6+1,-1);
}
void put(int key, int value) {
v[key]=value;
}
int get(int key) {
return v[key];
}
void remove(int key) {
v[key]=-1;
}
};
```