//Distribute Money to Maximum Children
You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children that you must distribute the money to.
You have to distribute the money according to the following rules:
All money must be distributed.
Everyone must receive at least 1 dollar.
Nobody receives 4 dollars.
Return the maximum number of children who may receive exactly 8 dollars

 solution:
 class Solution {
public:
    int distMoney(int money, int child) {
        money=money-child;
        if(money<0)
            return -1;
        else if(money/7==child-1 && money%7==3){
            return child-2;
        }else if(money/7==child && money%7==0){
            return child;
        }
        else{
           return min(child-1,money/7);
        }    
    }
};