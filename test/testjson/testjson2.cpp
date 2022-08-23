#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// json序列化示例1
string func1() {
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing?";

    string sendBuf = js.dump();
    //cout << sendBuf.c_str() << endl;
    return sendBuf;
}

// json序列化示例2
string func2() {
    json js;
    js["id"] = {1, 2, 3, 4, 5};
    js["name"] = "zhang san";
    js["msg"]["zhangsan"] = "hello world";
    js["msg"]["li si"] = "hello china";
    js["msg"] = {{"zhang san", "hello world"}, {"li si", "hello china~"}};

    //cout << js << endl;
    return js.dump();
} 

// json序列化示例3
string func3() {
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
    //cout << sendBuf << endl;
    return sendBuf;
}

int main() {
    string recvBuf = func3();
    // 数据的反序列化  json字符串 =》反序列化 数据对象（看作容器，方便访问）
    json jsbuf = json::parse(recvBuf);
    // cout << jsbuf["msg_type"] << endl;
    // cout << jsbuf["from"] << endl;
    // cout << jsbuf["to"] << endl;
    // cout << jsbuf["msg"] << endl;

    // cout << jsbuf["id"] << endl;
    // auto arr = jsbuf["id"];
    // cout << arr[2] << endl;

    // auto msgjs = jsbuf["msg"];
    // cout << msgjs["zhang san"] << endl;
    // cout << msgjs["li si"] << endl;

    vector<int> vec = jsbuf["list"];
    for (int& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    map<int, string> mymap = jsbuf["path"];
    for (auto& p : mymap) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    return 0;
}