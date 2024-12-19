#include <iostream>
using namespace std;
#include<list>;
#include<string>;
#include<algorithm>;
#include<vector>;



list<double>numbers = {};
list<char>operations={};


class Calculate{
    public:
        double add(double a, double b){
            return a+b;
        }
        
        double sub(double a, double b){
            return a-b;
        }
        double multiple(double a, double b){
            return a*b;
        }
        
        double divide(double a, double b){
            return a/b;
        }
        

};


int main()
{

    Calculate calc;
    string input;
    string y="";
    string answer;
    
    cout<< "Welcome to MS calculator"<<endl;    
    cout << "Type any numbers and operations!! Hit enter when you want to see the result!!" << endl;
    getline(cin,input);
        for(size_t i=0; i<input.length(); ++i){
            if(i%2==0){
                numbers.push_back(input[i] -'0');
            }
            else
            {
                operations.push_back(input[i]);
            }
        }
        auto opeGo = operations.begin();
        auto numGo = numbers.begin();
        vector<char>interOperations;
        vector<double>interNumbers;

        interNumbers.push_back(*numGo);
        ++numGo;

        while(opeGo != operations.end()){
            char op = *opeGo;
            double num = *numGo;
            if(op == '*'||op =='/'){
                if(op =='*'){
                    interNumbers.back()=calc.multiple(interNumbers.back(),num);
                }else if(op =='/'){
                    interNumbers.back()=calc.divide(interNumbers.back(),num);
                }
            }else{
                interNumbers.push_back(num);
                interOperations.push_back(op);
            }
            ++opeGo;
            ++numGo;
        }

            double result = interNumbers.front();
            for(size_t i=0; i<interNumbers.size(); ++i){
                char num = interNumbers[i+1];
                char op = interOperations[i];
                if(op =='+'){
                    result += num;
                }
                else if(op =='-'){
                    result -= num;
                }
                
            }

            cout<<"Result is: "<<result<<endl;

    
    
    
    

    return 0;





}
