#include "includes.h"

void get_ (Data &data){
    string key;
    cin >> key;
    if(data.contains(key)) {
        cout << data[key];
    }else{
        cerr << "key doesn't exist" << endl;
    }
}

void show(Data &data){
    for(const auto &item : data){
        cout << item.first << "->" << item.second << endl;
    }
}


void help () {
    for (const auto &i: COMMANDS) {
        cout << i.first << endl;

    }
}
void add(Data &data, string key = "", string val = ""){
    ofstream bin;
    if(key.empty() && val.empty()) {
        cin >> key >> val;
        bin.open(bin_path, ofstream::app );
        bin << binCommand << key << " " << val << "\n";
        binCommand = "";
    }
    if(data.contains(key)){
        cerr << "key already exist";

    }

    else {

        data[key] = val;

        bin.close();
    }
}

void edit(Data &data, string key = "", string val = ""){
    ofstream bin;
    if(key.empty() && val.empty()) {
        cin >> key >> val;
            if(!data.contains(key)){
                cerr << "key doesn't exist";
            }
        bin.open(bin_path, ofstream::app);
        bin << binCommand << key << " " << val << "\n";
        binCommand = "";
        bin.close();
    }
    if(!data.contains(key)){
        cerr << "key doesn't exist";
    }
    else
    {

        data[key] = val;

    }
}


void del(Data &data, string key = ""){


    if(key.empty()) {
        ofstream bin;
        cin >> key;
        if(!data.contains(key)){
        cerr << "key doesn't exist" << "\n";
    }

        data.erase(key);
        bin.open(bin_path, ofstream::app);
        bin << binCommand << key << '\n';
        binCommand = "";
        bin.close();
    }

    else{

        data.erase(key);

    }
}

void parse(string &str, Data &data){
    string val1, val2;
    if(str[0] == '/' && str[1] == 'a'){
        int cnt = 5;
        while(str[cnt] != ' '){
            val1 += str[cnt];
            cnt++;
        }
        while(cnt < str.length()){
            cnt++;
            val2 += str[cnt];

        }
        add(data, val1, val2);
    }
    else if(str[0] == '/' && str[1] == 'e'){
        int cnt = 6;
        while(str[cnt] != ' '){
            val1 += str[cnt];
            cnt++;
        }
        while(cnt < str.length()){
            cnt++;
            val2 += str[cnt];


        }
        edit(data, val1, val2);
    }
    else if (str[0] == '/' && str[1] == 'd'){

        for(int i = 5; i < str.length(); i++){
            val1 += str[i];

        }

        del(data, val1);
    }
}



void init (Data &data){
    string str;
    ifstream file;
    file.open(bin_path, ifstream::app);
    if(!file.is_open()){
        cerr << "unable to open binlog";
    }
    file.seekg(0, ios::beg);
    while(getline(file, str)){
        parse(str, data);

    }

}




int main() {

    Data data;
    data.clear();
    init(data);


    cout << "enter command" << endl;
    while(command != "/stop"){

        cin >> command;
        switch(COMMANDS[command]) {
            case 1:
                get_(data);
                break;
            case 2:
                help();
                break;
            case 3:
                binCommand = "/add ";
                add(data);
                break;
            case 4:
                binCommand = "/edit ";
                edit(data);
                break;
            case 5:
                binCommand = "/del ";
                del(data);
                break;
            case 6:
                break;
            case 7:
                show(data);
                break;
            default:
                cerr << "unknown command" << endl;
                break;
        }


    }

}
