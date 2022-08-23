#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// json序列化示例1
void func1() {
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing?";

    string sendBuf = js.dump();
    cout << sendBuf.c_str() << endl;
}

// json序列化示例2
void func2() {
    json js;
    js["id"] = {1, 2, 3, 4, 5};
    js["name"] = "zhang san";
    js["msg"]["zhangsan"] = "hello world";
    js["msg"]["li si"] = "hello china";
    js["msg"] = {{"zhang san", "hello world"}, {"li si", "hello china~"}};

    cout << js << endl;
} 

// json序列化示例3
void func3() {
    json js;
    
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    js["list"] = vec;

    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});

    js["path"] = m;

    //cout << js << endl;
    string sendBuf = js.dump(); // json数据对象 =》json字符串 （数据序列化）
    cout << sendBuf << endl;
}

int main() {
    func3();

    return 0;
}