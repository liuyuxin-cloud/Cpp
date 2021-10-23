#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

class Rational{
    private:
        int numerator;
        int denominator;
    public:
        Rational(){}           
        
        Rational(int numerator, int denominator){
        	if(denominator == 0){
        		cout << "error!";
        		exit(1);
			}
 			int x = numerator > 0 ? numerator : -numerator;
 			int y = denominator > 0 ? denominator : -denominator;
			while(x * y){
 				if(x > y){
 					x %= y;	
				}else{
					y %= x;
				}	
			}
			if(x > y){
				this->numerator = numerator / x;
				this->denominator = denominator / x;
			}else{
				this->numerator = numerator / y;
				this->denominator = denominator / y;
			}
        }
        
        int getNumerator(){
            return numerator;
        }
        
        int getDoinator(){
            return denominator;
        }

        Rational add(Rational secondRational){
            int tempDenominator = denominator * secondRational.denominator;
            int tempNumerator1 = numerator * secondRational.denominator;
            int tempNumerator2 = denominator * secondRational.numerator;
            int tempNumerator = tempNumerator1 + tempNumerator2;
            return Rational(tempNumerator, tempDenominator);
        }

        Rational subtract(Rational secondRational){
            int tempDenominator = denominator * secondRational.denominator;
            int tempNumerator1 = numerator * secondRational.denominator;
            int tempNumerator2 = denominator * secondRational.numerator;
            int tempNumerator = tempNumerator1 - tempNumerator2;
            return Rational(tempNumerator, tempDenominator);
        }

        Rational mutiply(Rational secondRational){
            int tempDenomiantor = denominator * secondRational.denominator;
            int tempNumerator = numerator * secondRational.numerator;
            return Rational(tempNumerator, tempDenomiantor);
        }

        Rational devide(Rational secondRational){
            Rational temp = Rational(secondRational.denominator, secondRational.numerator);
            return mutiply(temp);
        }

        bool equals(Rational secondRational){
            if(numerator == secondRational.numerator && denominator == secondRational.denominator){
                return true;
            }
            return false;
        }

        int compareTo(Rational secondRational){
            int tempDenominator = denominator * secondRational.denominator;
            int tempNumerator1 = numerator * secondRational.denominator;
            int tempNumerator2 = denominator * secondRational.numerator;
            return numerator < denominator ? -1 : numerator == denominator ? 0 : 1;
        }

        int intValue(){
            return numerator / denominator;
        }

        double doubleValue(){
            return 1.0 * numerator / denominator;
        }

        string toString() {
			
			stringstream ss1, ss2;
			string nume, deno, total;
			
			ss1 << this->numerator;
			ss1 >> nume;
			ss2 << this->denominator;
		    ss2 >> deno;
			
			
			if (this->denominator == 1) {
				return nume;
			} else {
				total = nume + " / " + deno;
				return total;
			}
		} 

        Rational operator+(Rational secondRational){
            return add(secondRational);
        }

        Rational operator-(Rational secondRational){
            return subtract(secondRational);
        }

        Rational operator*(Rational secondRational){
            return mutiply(secondRational);
        }

        Rational operator/(Rational secondRational){
            return devide(secondRational);
        }

        int operator[](int type){
            if(type == 0)   return numerator;
            return denominator;
        }

        Rational operator+=(Rational secondRational){
            return add(secondRational);
        }

        Rational operator-=(Rational secondRational){
            return subtract(secondRational);
        }

        Rational operator*=(Rational secondRational){
            return mutiply(secondRational);
        }

        Rational operator/=(Rational secondRational){
            return devide(secondRational);
        }

        Rational operator++(int){
            numerator += denominator;
            return Rational(numerator, denominator);
        }

        Rational operator--(int){
            numerator -= denominator;
            return Rational(numerator, denominator);
        }

        bool operator<(Rational secondRational){
            if(compareTo(secondRational) == -1) return true;
            return false;
        }

        bool operator<=(Rational secondRational){
            if(compareTo(secondRational) == 1)  return false;
            return true;
        }

        bool operator>(Rational secondRational){
            if(compareTo(secondRational) == 1)  return true;
            return false;
        }

        bool operator>=(Rational secondRational){
            if(compareTo(secondRational) == -1) return false;
            return true;
        }

        bool operator==(Rational secondRational){
            if(equals(secondRational) == true)  return true;
            return false;
        }

        bool operator!=(Rational secondRational){
            if(equals(secondRational) == false) return true;
            return false;
        }
};


int main(){
	Rational r1 = Rational(1, 5);
	Rational r2 = Rational(4, 5);
	Rational r3;
	r3 = r1++;
	cout << r3.getNumerator() <<"  "<< r3.getDoinator() << endl; 
	cout << r1.toString() ;
} 