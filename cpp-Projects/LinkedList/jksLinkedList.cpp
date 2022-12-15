#include <iostream>
#include <cwchar> 	//for font
#include <windows.h>//for font 

using namespace std;

class POLYNOMIAL
{
   private :
       struct polinomialNode
       {
           float coeff ;
           int exp ;
           polinomialNode *link ;
       } *p ;
   public :
       POLYNOMIAL( ) ;
       // I have taken integer exponents and float coeffs
       void AddTermToPolynomial ( float c, int e ) ;
       void AppendNewNode( float c, int e ) ;
       void DisplayPolinomial( ) ;
       void AddPolynomials( POLYNOMIAL &l1, POLYNOMIAL &l2 ) ;
       void MultiplyPolyNomial ( POLYNOMIAL &p1, POLYNOMIAL &p2 ) ;
       ~POLYNOMIAL( ) ;
} ;
POLYNOMIAL :: POLYNOMIAL( )
{
   p = NULL ;
}
//each term is stored as node in a linkedlist.appending each node to end of the list.
void POLYNOMIAL :: AddTermToPolynomial ( float c, int e )
{
   polinomialNode *temp = p ;
   if ( temp == NULL )
   {
       temp = new polinomialNode ;
       p = temp ;
   }
   else
   {
       while ( temp -> link != NULL )
           temp = temp -> link ;
       temp -> link = new polinomialNode ;
       temp = temp -> link ;
   }
   temp -> coeff = c ;
   temp -> exp = e ;
   temp -> link = NULL ;
}
void POLYNOMIAL :: DisplayPolinomial( )
{
   polinomialNode *temporary = p ;
   int f = 0 ;
   cout << endl ;
   while ( temporary != NULL )
   {
       if ( f != 0 )
       {
           if ( temporary -> coeff > 0 )
               cout << " + " ;
           else
               cout << " " ;
       }
       if ( temporary -> exp != 0 )
           cout << temporary -> coeff << "x^" << temporary -> exp ;
       else
           cout << temporary -> coeff ;
       temporary = temporary -> link ;
       f = 1 ;
   }
}

void POLYNOMIAL :: AddPolynomials ( POLYNOMIAL &check1, POLYNOMIAL &check2 )
{
   polinomialNode *z ;
   if ( check1.p == NULL && check2.p == NULL )
       return ;
   polinomialNode *temp1, *temp2 ;
   temp1 = check1.p ;
   temp2 = check2.p ;
   while ( temp1 != NULL && temp2 != NULL )
   {
       if ( p == NULL )
       {
           p = new polinomialNode ;
           z = p ;
       }
       else
       {
           z -> link = new polinomialNode ;
           z = z -> link ;
       }
       if ( temp1 -> exp < temp2 -> exp )
       {
           z -> coeff = temp2 -> coeff ;
           z -> exp = temp2 -> exp ;
           temp2 = temp2 -> link ;
       }
       else
       {
           if ( temp1 -> exp > temp2 -> exp )
           {
               z -> coeff = temp1 -> coeff ;
               z -> exp = temp1 -> exp ;
               temp1 = temp1 -> link ;
           }
           else
           {
               if ( temp1 -> exp == temp2 -> exp )
               {
                   z -> coeff = temp1 -> coeff + temp2 -> coeff ;
                   z -> exp = temp1 -> exp ;
                   temp1 = temp1 -> link ;
                   temp2 = temp2 -> link ;
               }
           }
       }
   }
   while ( temp1 != NULL )
   {
       if ( p == NULL )
       {
           p = new polinomialNode ;
           z = p ;
       }
       else
       {
           z -> link = new polinomialNode ;
           z = z -> link ;
       }
       z -> coeff = temp1 -> coeff ;
       z -> exp = temp1 -> exp ;
       temp1 = temp1 -> link ;
   }
   while ( temp2 != NULL )
   {
       if ( p == NULL )
       {
           p = new polinomialNode ;
           z = p ;
       }
       else
       {
           z -> link = new polinomialNode ;
           z = z -> link ;
       }
       z -> coeff = temp2 -> coeff ;
       z -> exp = temp2 -> exp ;
       temp2 = temp2 -> link ;
   }
   z -> link = NULL ;
}
void POLYNOMIAL :: MultiplyPolyNomial ( POLYNOMIAL &p1, POLYNOMIAL &p2 )
{
   polinomialNode *temp1, *temp2 ;
   float coeff1, exp1 ;
   temp1 = p1.p ;
   temp2 = p2.p ;
   if ( temp1 == NULL && temp2 == NULL )
       return ;
   if ( temp1 == NULL )
       p = p2.p ;
   else
   {
       if ( temp2 == NULL )
           p = temp1 ;
       else       {
           while ( temp1 != NULL )
           {
               while ( temp2 != NULL )
               {
                   coeff1 = temp1 -> coeff * temp2 -> coeff ;
                   exp1 = temp1 -> exp + temp2 -> exp ;
                   temp2 = temp2 -> link ;
                   AppendNewNode ( coeff1, exp1 ) ;
               }
               temp2 = p2.p ;
               temp1 = temp1 -> link ;
           }
       }
   }
}
void POLYNOMIAL :: AppendNewNode ( float c, int e )
{
   polinomialNode *r, *temp ;
   temp = p ;
   if ( temp == NULL || c > temp -> exp )
   {
       r = new polinomialNode ;
       r -> coeff = c ;
       r -> exp = e ;
       if ( p == NULL )
       {
           r -> link = NULL ;
           p = r ;
       }
       else
       {
           r -> link = temp ;
           p = r ;
       }
   }
   else
   {
       while ( temp != NULL )
       {
           if ( temp -> exp == e )
           {
               temp -> coeff += c ;
               return ;
           }
           if ( temp -> exp > c && ( temp -> link -> exp < c ||
                       temp -> link == NULL ) )
           {
               r = new polinomialNode ;
               r -> coeff = c;
               r -> exp = e ;
               r -> link = NULL ;
               temp -> link = r ;
               return ;
           }
           temp = temp -> link ;
       }
       r -> link = NULL ;
       temp -> link = r ;
   }
}
POLYNOMIAL :: ~POLYNOMIAL( )
{
   polinomialNode *q ;
   while ( p != NULL )
   {
       q = p -> link ;
       delete p ;
       p = q ;
   }
}
int main()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // width of character
	cfi.dwFontSize.Y = 20;                  // height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system ("color 70");
	
	
   POLYNOMIAL var1 ;
   POLYNOMIAL sumVar;
   //adding polynomialss in decreasing order of exponents
   var1.AddTermToPolynomial ( 3, 5 ) ;
   var1.AddTermToPolynomial ( 2, 4 ) ;
   var1.AddTermToPolynomial ( 1, 2 ) ;
  
   POLYNOMIAL var2 ;
   var2.AddTermToPolynomial ( 1, 6 ) ;
   var2.AddTermToPolynomial ( 2, 5 ) ;
   var2.AddTermToPolynomial ( 3, 4 ) ;
  
  
  
   int choice, num, i ;
unsigned long int fact;

  
   while (1)
{
cout<<"1. Add a term to polynomial 1\n";
cout<<"2. Add a term to polynomial 2\n";
cout<<"3. Display polynomial 1\n";
cout<<"4: Display polynomial 2\n";
cout<<"5: Display the sum of the two polynomials\n";
cout<<"6: Display polynomial 1 * mentioned polynomial \n";cout<<"7:Exit\n";

cout<<"\n Your choice ?";
cin>>choice ;
switch ( choice)
{
case 1 :
float co;
int expo;
cout << "enter the term to be added to the polynomial 1\n";
cin >> co >> expo;
var1.AddTermToPolynomial (co,expo);
break;
  
case 2 :
float co2;
int expo2;
cout << "enter the term to be added to the polynomial 2\n";
cin >> co2 >> expo2;
var2.AddTermToPolynomial (co2,expo2);
break;
  
case 3:
cout << "displaying polynomial 1\n";
var1.DisplayPolinomial();
break;
  
case 4:
cout << "displaying polynomial 2\n";
var2.DisplayPolinomial();
break;
  
case 5:
cout << "Displaying sum of two polynomails\n";
  
   sumVar.AddPolynomials ( var1, var2 ) ;
   cout << "\nSum polynomial: " << endl;
   sumVar.DisplayPolinomial() ;
   break;
     
   case 6:
cout << "Displaying multiplication of polynomails with term\n";
POLYNOMIAL MultiplyVar;
POLYNOMIAL var3 ;
float co3;
int expo3;
cout << "enter the term to be added to the polynomial 1\n";
cin >> co3 >> expo3;
   //adding polynomialss in decreasing order of exponents
   var3.AddTermToPolynomial ( co3, expo3 ) ;
   MultiplyVar.AddPolynomials ( var1, var3 ) ;
   cout << "\nmultiplied polynomial: " ;
   MultiplyVar.DisplayPolinomial( ) ;
   break;
     
}
}
return 0;
  
}

  
