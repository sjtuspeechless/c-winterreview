//------------------------
//Description:HfmCode Coder and Decoder
//Author:Ruisi Zhang
//2018.12.01
//------------------------
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<cmath>

using namespace std;

//------------------------
//function:a node of hfTree
//data: character of input
//weight:weight of input
//------------------------
struct Node
{
    char data;
    double weight;
    int parent, left, right;//index of parent,left and right node
};
//------------------------
//function:the number of character
//num:the percentage of ch
//ch:input character
//------------------------
struct Wen{
    double num;
    char ch;
};

//------------------------
//hfTree class
//function:hfTree operation
//------------------------
class hfTree  {
private:
    //input char number
    int length;
public:
    struct hfCode {
        //input char
        char data;
        //correspoding code
        string code;
    };
    Node *elem;
    hfCode *result;
    //constructor
    hfTree(const char *x, const double *w, int size);
    //code->char
    void getCode(hfCode result[]);
    //deconstructor
    ~hfTree() { delete[]elem;  }
};
//------------------------
//function:constructor of hfTree
//input:v:input character array; w:input weight array; size:the size of input char
//output:\
//------------------------
hfTree::hfTree(const char *v, const double *w, int size){
    const int MAX_INT = 32767;
    double min1, min2;
    int x, y;

    length = 2 * size;
    elem = new Node[length];

    //initialize
    for (int i = size; i < length; ++i) {
        elem[i].weight = w[i - size];
        elem[i].data = v[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }

    //find min
    for (int i = size - 1; i > 0; --i) {
        min1 = min2 = MAX_INT;
        x = y = 0;
        for (int j = i + 1; j < length; ++j) {
            if(elem[j].parent==0)
                if (elem[j].weight < min1) {
                    min2 = min1;
                    min1 = elem[j].weight;
                    x = y;
                    y = j;
                }
                else if (elem[j].weight < min2) {
                    min2 = elem[j].weight;
                    x = j;
                }
        }

        //combine tree
        elem[i].weight = min1 + min2;
        elem[i].left = x;
        elem[i].right = y;
        elem[i].parent = 0;
        elem[x].parent = i;
        elem[y].parent = i;
    }
}
//------------------------
//function:tranfer char to code
//input: struct array of hfCode
//output:\
//------------------------
void hfTree::getCode(hfCode result[])
{
    int size = length / 2;
    int p, s;

    for (int i = size; i < length; ++i) {
        result[i - size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent;
        s = i;
        while (p)
        {
            //go from child to parent
            if (elem[p].left == s) {
                result[i - size].code = '0' + result[i - size].code;
            }
            else result[i - size].code = '1' + result[i - size].code;
            s = p;
            p = elem[p].parent;
        }
    }
}

void Ini();                //initialization
void Decode();             //decode
void Encode();             //encode
void codePrint();          //print code
void treePrint();          //print tree
void WenRead();             //read string
int main()
{
    char input = ' ';
    while(input != 'Q'){
        cout<<"Please enter your operation:\n";
        cout<<"I for Initialization\n";
        cout<<"E for Encoding\n";
        cout<<"D for Decoding\n";
        cout<<"P for code Printing\n";
        cout<<"T for Tree printing\n";
        cout<<"W for read article\n";
        cout<<"Q for Quit\n";
        cin>>input;
        if (input == 'I'){
            Ini();
        }
        if (input == 'E'){
            Encode();
        }
        if (input == 'D'){
            Decode();
        }
        if (input == 'P'){
            codePrint();
        }
        if (input == 'T'){
            treePrint();
        }
        if(input == 'W'){
            WenRead();
        }
    }
    return 0;
}
//------------------------
//function:initialize the input character
//input: \
//output:\
//------------------------
void Ini(){
    int n;
    cout<<"please input the size,characters and weight:\n";
    //input size
    cin>>n;
    char *ch = new char[n];      //character
    double *w = new double[n];   //weight
    //input weight and data
    for(int i = 0;i < n;++i){
        cin>>ch[i];
        cin>>w[i];
    }

    //construct a hfTree and tranfer char to code
    hfTree tree(ch, w, n);
    hfTree::hfCode *result=new hfTree::hfCode[n];
    for(int i = 0;i < n;i++)
        result[i].data = ch[i];
    tree.getCode(result);

    //read code and char into hfmTree.txt
    ofstream out("hfmTree.txt");
    if (!out) {
        cerr << "create file error\n"; return;
    }
    out << n << '\n';
    for (int i = 0; i < n; i++)
        out << result[i].data << '\t' << result[i].code << '\t' << w[i] << '\n';
    out.close();
}

//------------------------
//function:encode file
//input: \
//output:\
//------------------------
void Encode(){
    //read the file to get ch and code
    int n, i = 0;
    ifstream in_1;
    in_1.open("hfmTree.txt");
    if (!in_1) { cerr << "open file1 erroe\n"; return; }
    in_1 >> n;
    in_1.get();
    string *s = new string[n];
    char *ch1 = new char[n];
    double *w = new double[n];

    for (i = 0; i < n; i++){
        in_1.get(ch1[i]);
        in_1 >> s[i];
        in_1 >> w[i];
        in_1.get();
    }
    in_1.close();

    //tranfer ch in file into code
    char ch;
    ofstream out("codeFile.txt");
    if (!out) { cerr << "create file error\n"; return; }
    ifstream in_2("plainFile.txt");
    if (!in_2) { cerr << "open file2 erroe\n"; return; }
    while (in_2.get(ch)) {
        for (i = 0; i < n; i++) {
            if (ch == ch1[i]) {
                out << s[i];
                break;
            }
        }
    }
    in_2.close();
    out.close();
}

//------------------------
//function:decode file
//input: \
//output:\
//------------------------
void Decode(){
    int n, i = 0;
    ifstream in_1;
    in_1.open("hfmTree.txt");           //open file
    if (!in_1) { cerr << "open file1 erroe\n"; return; }
    in_1 >> n;                           //char
    in_1.get();                          //'\n'
    string *s = new string[n];           //code
    char *ch = new char[n];            //char
    double *w = new double[n];

    for (i = 0; i < n; i++) {
        in_1.get(ch[i]);
        in_1 >> s[i];
        in_1 >> w[i];
        in_1.get();                     //'\n'
    }
    in_1.close();

    //compare the string with specific code
    int m = 0;

    char *str=new char[n];
    for (int i = 0; i < n; i++) {
        str[i] = '\0';
    }
    ofstream out("textFile.txt");             //open file
    if (!out) { cerr << "create file error\n"; return; }
    ifstream in_2;
    in_2.open("codeFile.txt");
    if (!in_2) { cerr << "open file2 erroe\n"; return; }
    bool flag = false;
    while (in_2 >> str[m]) {
        flag = false;
        for (i = 0; i < n; i++) {
            if (str == s[i]) {
                out << ch[i];
                for (int o = 0; o <= m; o++) {
                    str[o] = '\0';
                }
                m = 0;
                flag = true;
                break;
            }
        }
        if (!flag) m++;
    }
    in_2.close();
    out.close();
}

//------------------------
//function:print code in line and save
//input: \
//output:\
//------------------------
void codePrint() {
    char ch;
    int t = 0;
    ofstream out("codePrint.txt");      //open file
    if (!out) { cerr << "create file error\n"; return; }
    ifstream in("codeFile.txt");
    if (!in) { cerr << "open file erroe\n"; return; }
    while (in >> ch) {
        out << ch;                      //output ch
        cout << ch;
        t++;
        if (t == 50) {                  //get 50 char and go next line
            out << '\n';
            cout << '\n';
            t = 0;
        }
    }

}

//------------------------
//function:print hfTree
//input: \
//output:\
//------------------------
void treePrint(){
    //read and construct new tree
    int n, i = 0;
    ifstream in_1;
    in_1.open("hfmTree.txt");
    if (!in_1) { cerr << "open file erroe\n"; return; }
    in_1 >> n;
    in_1.get();
    string *s = new string[n];
    char *ch = new char[n];
    double *w = new double[n];

    for (i = 0; i < n; i++) {
        in_1.get(ch[i]);
        in_1 >> s[i];
        in_1 >> w[i];
        in_1.get();
    }
    in_1.close();

    hfTree tree(ch, w, n);
    hfTree::hfCode *result = new hfTree::hfCode[n];
    tree.getCode(result);

    int *num = new int [n];
    for(int i = 0;i < n;i++)
        num[i] = result[i].code.length();
    int p, q;
    //string from small to big
    for (p = 0; p < n - 1; p++)
        for (q = 0; q < n - 1 - p; q++)
            if (num[q] > num[q + 1]){
                hfTree::hfCode tmp1;
                int tmp;
                tmp = num[q];
                num[q] = num[q+1];
                num[q+1] = tmp;
                tmp1 = result[q];
                result[q] = result[q+1];
                result[q+1] = tmp1;
                //small -> big
            }
    for(int i = 0;i < n;i++){
        if(num[i] == num[i+1]){
            if(result[i].code > result[i+1].code){
                hfTree::hfCode tmp1;
                tmp1 = result[i];
                result[i] = result[i+1];
                result[i+1] = tmp1;
            }
        }
    }
    ofstream out("treePrint.txt");               //打开编码保存文件
    if (!out) { cerr << "create file error\n"; return; }

    //print and save tree
    for(int i = 0;i < n;i++){
        if(result[i].code.length() == result[i+1].code.length()){
            cout<<result[i].data;
            out<<result[i].data;
        }
        else{
            cout<<result[i].data<<endl;
            out<<result[i].data<<endl;
        }
    }
}

//------------------------
//function:read article and construct tree
//input: \
//output:\
//------------------------
void WenRead(){
    //read and save a string
    cout<<"Please input your article\n";
    string str;
    cin>>str;
    bool flag = false;
    int len = str.length();
    int sum = 0;
    Wen *W = new Wen[len];
    int m = -1;
    for(int i = 0;str[i] != '\0';i++){
        for(int j = m;j >= 0;j--){
            if(W[j].ch == str[i] ){
                W[j].num++;
                flag = true;
            }
        }
        if(!flag){
            m++;
            W[m].ch = str[i];
            W[m].num =1;
        }
        flag = false;
    }

    //construct a tree and save it to file
    for(int i = 0;i < m;i++)
        sum += W[i].num;
    hfTree tree(&W->ch, &W->num, m);
    for(int i = 0;i < m;i++)
        W[i].num = W[i].num/sum;


    hfTree::hfCode *result=new hfTree::hfCode[m];
    for(int i = 0;i < m;i++)
        result[i].data = W[i].ch;

    tree.getCode(result);

    ofstream out;
    out.open("hfmTree.txt");
    if (!out) {
        cerr << "create file error\n"; return;
    }
    out << m << '\n';
    for (int i = 0; i < m; i++)
        out << W[i].ch  << '\t' << result[i].code << '\t' << W[i].num << '\n';

    out.close();
}
