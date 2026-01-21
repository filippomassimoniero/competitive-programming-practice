#include <bits/stdc++.h>

using namespace std;

pair<int,int> getTokenValue(vector<string>& tokens, int currentIndex) {
    string currentToken = tokens[currentIndex];

    pair<int,int> firstToken;
    pair<int,int> secondToken;
    if(currentToken == "+") {
        firstToken = getTokenValue(tokens, currentIndex-1);
        secondToken = getTokenValue(tokens, currentIndex - 1 - firstToken.second);
        return {firstToken.first + secondToken.first,1 + firstToken.second + secondToken.second};
    } else if(currentToken == "*") {
        firstToken = getTokenValue(tokens, currentIndex-1);
        secondToken = getTokenValue(tokens, currentIndex - 1 - firstToken.second);

        return {firstToken.first * secondToken.first,1 + firstToken.second + secondToken.second};
    } else if(currentToken == "-") {
        firstToken = getTokenValue(tokens, currentIndex-1);
        secondToken = getTokenValue(tokens, currentIndex - 1 - firstToken.second);

        return {secondToken.first - firstToken.first,1 + firstToken.second + secondToken.second};
    } else if(currentToken == "/") {
        firstToken = getTokenValue(tokens, currentIndex-1);
        secondToken = getTokenValue(tokens, currentIndex - 1 - firstToken.second);

        return {secondToken.first / firstToken.first,1 + firstToken.second + secondToken.second};
    } else { 
        // Token is a number
        return {stoi(currentToken),1};
    }
    return {0,0};
}
int evalRPN(vector<string>& tokens) {
    return getTokenValue(tokens,  tokens.size()-1).first;
}


int main() {
    vector<string> in1 = {"2","1","+","3","*"};
    vector<string> in2 = {"4","13","5","/","+"};
    vector<string> in3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // cout << evalRPN(in1) << endl;
    cout << evalRPN(in2) << endl;
    cout << evalRPN(in3) << endl;
    return 0;
}