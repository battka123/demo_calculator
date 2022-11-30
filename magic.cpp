#include "header.hpp"
#include <cmath>

void Magic( std::stack<float>& numbers, std::stack<std::string>& action, int& buf_prioritet, std::string& buf_operacia){
    std::string k = action.top();
    if (k=="+" && numbers.size() >1){
        float a = numbers.top(); numbers.pop();
        float b = numbers.top(); numbers.pop();
        numbers.push(a+b);
        action.pop();
    }
    else if (k=="-" && numbers.size() >1){
        float a = numbers.top(); numbers.pop();
        float b = numbers.top(); numbers.pop();
        numbers.push(b-a);
        action.pop();
    }
    else if (k=="/" && numbers.size() >1){
        float a = numbers.top(); numbers.pop();
        float b = numbers.top(); numbers.pop();
        numbers.push(b/a);
        action.pop();
    }
    else if (k=="*" && numbers.size() >1){
        float a = numbers.top(); numbers.pop();
        float b = numbers.top(); numbers.pop();
        numbers.push(a*b);
        action.pop();
    }
    else if (k=="^" && numbers.size() >1){
        float a = numbers.top(); numbers.pop();
        float b = numbers.top(); numbers.pop();
        numbers.push(std::pow(b,a));
        action.pop();
    }
    else if (k=="sqrt"){
        if (buf_operacia != "("){
            float a = numbers.top();
            numbers.pop();
            numbers.push(std::sqrt(a));
            action.pop();
        }
        else{
            buf_prioritet =-1;
        }
    }
    else if (k=="exp"){
        if(buf_operacia != "("){
            float a = numbers.top();
            numbers.pop();
            numbers.push(std::exp(a));
            action.pop();
        }
        else{
            buf_prioritet =-1;
        }
    }
    else if (k=="sin"){
        if(buf_operacia != "("){
            float a = numbers.top();
            numbers.pop();
            numbers.push(std::sin(a));
            action.pop();
        }
        else{
            buf_prioritet =-1;
        }
    }
    else if (k=="cos"){
        if(buf_operacia != "("){
            float a = numbers.top();
            numbers.pop();
            numbers.push(std::cos(a));
            action.pop();
        }
        else{
            buf_prioritet =-1;
        }
    }
    else if (k=="tan"){
        if(buf_operacia != "("){
            float a = numbers.top();
            numbers.pop();
            numbers.push(std::tan(a));
            action.pop();
        }
        else{
            buf_prioritet =-1;
        }
    }
    else if (k=="ctg"){
        if(buf_operacia != "("){
            float a = numbers.top();
            numbers.pop();
            numbers.push(1 / (std::tan(a)));
            action.pop();
        }
        else{
            buf_prioritet = -1;
        }
    }
    else if (k=="(" ){
        buf_prioritet = 0;
        action.pop();
    }
    if ((numbers.size() == 1) && (action.empty())){
        buf_prioritet = -1;
    }
}