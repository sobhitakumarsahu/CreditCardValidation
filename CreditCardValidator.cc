#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/****************************************************************************
*Func Name: isValidCreditCard
*Functionality: 
* 1. Sums all odd positioned digits
* 2. Sums twice of all even positioned digits. If twice of a digit results to 
*    double digit number, again it sums the digits.
*    e.g even positioned digit is 8, twice of 8 is 16, 
*        since 16 is double digit number, it will sum 1 + 6 = 7;
* 
*****************************************************************************/
bool isValidCreditCard(long lCredNum)
{
	int iOddSum=0,iEvenSum=0,itempsum=0,temp=0,iModRes=0, iTotSum=0,iTwiceModRes=0;
	bool isEvenDigit = false;
	while(lCredNum!=0)
	{
		iModRes = lCredNum%10;
		if(isEvenDigit==true)
		{
		    iTwiceModRes = 2 * iModRes;
		    if(iTwiceModRes>=10)
		    {
		        while(iTwiceModRes!=0)
		        {
		            temp = iTwiceModRes%10;
		            itempsum += temp;
		            iTwiceModRes = iTwiceModRes/10;
		        }
		        iEvenSum += itempsum;
		        itempsum = 0;
		    }
		    else
		    {
    			iEvenSum += iTwiceModRes;
		    }
		    isEvenDigit = false;
		}
		else
		{
			iOddSum += iModRes;	
			isEvenDigit = true;
		}
		lCredNum = lCredNum/10;
	}
	iTotSum = iEvenSum + iOddSum;
	return(iTotSum%10==0);
}
int main() {
    string sCreditCardNumber;
    long lCreditCardNumber=0;
    cout <<"Enter your Credit Card Number:";
    cin >>sCreditCardNumber;
    if(sCreditCardNumber.size()==16)
    {
        stringstream convert(sCreditCardNumber);
        convert>>lCreditCardNumber;
        if(isValidCreditCard(lCreditCardNumber))
    	{
    	    cout<<"Valid Credit Card";
    	}
    	else
    	{
    	    cout<<"Invalid Credit Card";
    	}
    }
    else
	{
	    cout<<"Credit Card must be of 16 digits";
	}
	return 0;
}