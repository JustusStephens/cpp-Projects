//Justus Stephens
//CPS 162
//September 22, 2019
//Linked List Polynomials


#include <iostream>
#include <cwchar> 		//for font
#include <windows.h>	//for font 

using namespace std;

class Polynomial				//polynomial class
{
	private:
		struct polyNode
		{
			int exp;			//integer exponent
			float coe;         //incase coefficient is a decimal
			polyNode *next;		//pointer to my polyNode
		} *point;
		
	public:
		Polynomial();													//constructor with functions
		void addTerm(int ex, float co);									//add a term
		void addNewNode(int ex, float co);								//add a new node
		void displayPoly();												//display poly
		void polySum(Polynomial &l1, Polynomial &l2);					//sum
		void polyDif(Polynomial &l1, Polynomial &l2);				    //dif
		void MultiplyPolyNomial ( Polynomial &p1, Polynomial &p2 ) ;    //multiply
		
       ~Polynomial() ;					//destructor
} ;
		
		Polynomial::Polynomial()        //setting first node to null
		{
			point = NULL;
		}
		
///////////////////// add term method ////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
void Polynomial :: addTerm ( int ex, float co )
{
   polyNode *temp = point ;          //temp pointer equals point
   if ( temp == NULL )					//if null make new node
   {
       temp = new polyNode ;
       point = temp ;
   }
   
   else									//if not null find null then make new node
   {
       while ( temp -> next != NULL )
       {
           temp = temp -> next ;
       }
       
       temp -> next = new polyNode ;
       temp = temp -> next ;
   }
   
   temp -> exp = ex ;			//exponent
   temp -> coe = co ;			//coefficeint
   temp -> next = NULL ;
}

// Display polynomial /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Polynomial :: displayPoly()
{
   polyNode *tempp = point ;
   int num = 0 ;
   cout << "\n" ;
   while ( tempp != NULL )
   {
       if ( num != 0 )
       {
           if ( tempp -> coe > 0 )						//positive coefficient
               cout << " + " ;
           else
               cout << " - " ;							//negative coefficient
       }
       if ( tempp -> exp != 0 )								//if there is and exponent
           cout << tempp -> coe << "x^" << tempp -> exp ;
       else
           cout << tempp -> coe ;							//no exponent, just print coefficeint
       tempp = tempp -> next ;
       num = 1 ;
   }
}

// adding polys/////////////////////////////////////////////////////////////////////////////////////////////////

void Polynomial :: polySum ( Polynomial &n1, Polynomial &n2 )
{
   polyNode * f;
   
   if ( n1.point == NULL && n2.point == NULL )				//if both are empty just go back
       return ;
       
   polyNode *temp1, *temp2 ;			//temp pointers			
   temp1 = n1.point ;					//pointer to poly 1
   temp2 = n2.point ;					//pointer to poly 2
   		
   while ( temp1 != NULL && temp2 != NULL )
   {
       if ( point == NULL )
       {
           point = new polyNode ;
           f = point ;
       }
       else
       {
           f -> next = new polyNode ;
           f = f -> next ;
       }
       
       if ( temp1 -> exp < temp2 -> exp )			//if poly 1 exponent is less than poly 2 exponent f will get value of greater
       {
       	   f -> exp = temp2 -> exp ;
           f -> coe = temp2 -> coe ;				
           temp2 = temp2 -> next ;
       }
       else											//else 1 is greater than 2 f gets greater
       {
           if ( temp1 -> exp > temp2 -> exp )
           {
           	   f -> exp = temp1 -> exp ;
               f -> coe = temp1 -> coe ;
               temp1 = temp1 -> next ;
           }
           
           else											//equal exponents can have added coeffics
           {
               if ( temp1 -> exp == temp2 -> exp )
               {
                   f -> coe = temp1 -> coe + temp2 -> coe ;          
                   f -> exp = temp1 -> exp ;
                   temp1 = temp1 -> next ;
                   temp2 = temp2 -> next ;
               }
           }
       }
   }
   
   while ( temp1 != NULL )					//while temp pointer 1 isnt null
   {
       if ( point == NULL )
       {
           point = new polyNode ;
           f = point ;
       }
       else
       {
           f -> next = new polyNode ;
           f = f -> next ;
       }
       f -> exp = temp1 -> exp ;
       f-> coe = temp1 -> coe ;
       temp1 = temp1 -> next ;
   }
   
   while ( temp2 != NULL )				//while temp pointer 2 isnt null
   {
       if ( point == NULL )
       {
           point = new polyNode ;
           f = point ;
       }
       else
       {
           f -> next = new polyNode ;
           f = f -> next ;
       }
       f -> exp = temp2 -> exp ;
       f -> coe = temp2 -> coe ;
       temp2 = temp2 -> next ;
   }
   f -> next = NULL ;
}

// difference of polynomials /////////////////////////////////////////////////////////////////////////////////////

void Polynomial :: polyDif ( Polynomial &n1, Polynomial &n2 )
{
   polyNode * f;
   
   if ( n1.point == NULL && n2.point == NULL )				//if both are empty just go back
       return ;
       
   polyNode *temp1, *temp2 ;			//temp pointers			
   temp1 = n1.point ;					//pointer to poly 1
   temp2 = n2.point ;					//pointer to poly 2
   		
   while ( temp1 != NULL && temp2 != NULL )
   {
       if ( point == NULL )
       {
           point = new polyNode ;
           f = point ;
       }
       else
       {
           f -> next = new polyNode ;
           f = f -> next ;
       }
       
       if ( temp1 -> exp < temp2 -> exp )			//if poly 1 exponent is less than poly 2 exponent f will get value of greater
       {
       	   f -> exp = temp2 -> exp ;
           f -> coe = temp2 -> coe ;				
           temp2 = temp2 -> next ;
       }
       else											//else 1 is greater than 2 f gets greater
       {
           if ( temp1 -> exp > temp2 -> exp )
           {
           	   f -> exp = temp1 -> exp ;
               f -> coe = temp1 -> coe ;
               temp1 = temp1 -> next ;
           }
           
           else											//equal exponents can have added coeffics
           {
               if ( temp1 -> exp == temp2 -> exp )
               {
                   f -> coe = temp1 -> coe - temp2 -> coe ;          
                   f -> exp = temp1 -> exp ;
                   temp1 = temp1 -> next ;
                   temp2 = temp2 -> next ;
               }
           }
       }
   }
   
   while ( temp1 != NULL )					//while temp pointer 1 isnt null
   {
       if ( point == NULL )
       {
           point = new polyNode ;
           f = point ;
       }
       else
       {
           f -> next = new polyNode ;
           f = f -> next ;
       }
       f -> exp = temp1 -> exp ;
       f-> coe = temp1 -> coe ;
       temp1 = temp1 -> next ;
   }
   
   while ( temp2 != NULL )				//while temp pointer 2 isnt null
   {
       if ( point == NULL )
       {
           point = new polyNode ;
           f = point ;
       }
       else
       {
           f -> next = new polyNode ;
           f = f -> next ;
       }
       f -> exp = temp2 -> exp ;
       f -> coe = temp2 -> coe ;
       temp2 = temp2 -> next ;
   }
   f -> next = NULL ;
}

// Multiplying poly/////////////////////////////////////////////////////////////////////////////////////////////////

void Polynomial :: MultiplyPolyNomial ( Polynomial &p1, Polynomial &p2 )
{
   polyNode *temp1, *temp2 ;
   float coe1, exp1;
   temp1 = p1.point ;
   temp2 = p2.point ;
   
   if ( temp1 == NULL && temp2 == NULL )			//if both empty return
       return ;
       
   if ( temp1 == NULL )								//if one is null point to 2					
       point = p2.point ;
       
   else
   {
       if ( temp2 == NULL )						//else point to 1
           point = temp1 ;
           
       else
	   {
           while ( temp1 != NULL )
           {
               while ( temp2 != NULL )
               {
                   coe1 = temp1 -> coe * temp2 -> coe ;		//multiply coeffs
                   exp1 = temp1 -> exp + temp2 -> exp ;		//add exponents
                   temp2 = temp2 -> next ;
                   addNewNode ( coe1, exp1 ) ;			//add node
               }
               temp2 = p2.point ;
               temp1 = temp1 -> next ;
           }
       }
   }
}

//Add new node ///////////////////////////////////////////////////////////////////////////////////

void Polynomial :: addNewNode ( int ex, float co)
{
   polyNode *add, *temp;					//pointers
   temp = point ;
   if ( temp == NULL || co > temp -> exp )  //coefficeint greater than exponent
   {
       add = new polyNode ;			//new node
       add -> coe = co ;			//coef
       add -> exp = ex ;			//expo
       
       if ( point == NULL )
       {
           add -> next = NULL ;
           point = add ;
       }
       else
       {
           add -> next = temp ;
           point = add ;
       }
   }
   
   else
   {
       while ( temp != NULL )
       {
           if ( temp -> exp == ex ) 	//same exp add coefs then return
           {
               temp -> coe += co ;
               return ;
           }
           
           if ( temp -> exp > co && (temp -> next == NULL || temp -> next -> exp < co ) )   //if exponent is greater than co, and next = null or temp pointer to next  to exp < co
           {
               add = new polyNode ;		//add new node
               add -> coe = co;		//add co
               add -> exp = ex;			//add ex
               add -> next = NULL ;		//point to null
               temp -> next = add ;		//link it to add
               return ;
           }
           
           temp = temp -> next ;			//point to next
       }
       add -> next = NULL ;   //null
       temp -> next= add ;	//link
   }
}

// destructor ////////////////////////////////////////////////////////////////////////////////////////

Polynomial :: ~Polynomial( )
{
   polyNode *de ;					//pointer
   while ( point != NULL )			//while not at the end
   {
       de = point -> next ;			//point to next
       delete point ;				//delete
       point = de ;					//original point to de
   }
}

// main /////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // width of character
	cfi.dwFontSize.Y = 20;                  // height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system ("color 90");
	
	
   Polynomial t1;
   Polynomial t2;
   Polynomial sumT;					//default polys
   Polynomial difT;
   
   t1.addTerm ( 1, 4 ) ;
   t1.addTerm ( 2, 5 ) ;
   t1.addTerm ( 3, 6 ) ;
  
   t2.addTerm ( 7, 3 ) ;
   t2.addTerm ( 8, 2 ) ;
   t2.addTerm ( 9, 1 ) ;
  
  
  
int choice, num, i;
unsigned long int fact;

  
   while (1)
{
	cout<<"\n				1. Add a term to polynomial 1\n";
	cout<<"				2. Add a term to polynomial 2\n";
	cout<<"				3. Display polynomial 1\n";
	cout<<"				4: Display polynomial 2\n";
	cout<<"				5: Display the sum of the two polynomials\n";
	cout <<"				6: Display the difference of the two polynomials\n";
	cout<<"				7: Display polynomial 1 times another term \n";
	cout<<"				8:Exit\n";
	cout<<"				\n 				Please Enter a Number From 1 to 8 \n";
	cin>>choice;
	
switch ( choice)
{
	case 1 :		//add to number 1
		float co;
		int ex;
		cout << "enter the term to be added to the polynomial #1 \n";
		cin >> co >> ex;
		t1.addTerm(ex,co);
	break;
  
	case 2 :		//add to number 2
		float co2;
		int ex2;
		cout << "enter the term to be added to the polynomial #2 \n";
		cin >> co2 >> ex2;
		t2.addTerm(ex2,co2);
	break;
  
	case 3:											//display number 1
		cout << "displaying polynomial #1 \n";
		t1.displayPoly();
	break;
  
	case 4:											//display number 2
		cout << "displaying polynomial #2 \n";
		t2.displayPoly();
	break;
  
	case 5:												//sum
	   cout << "\n Displaying sum of two polynomails \n";
	   sumT.polySum( t1,t2);
	   cout << "\n Sum of the polynomials: " << endl;
	   sumT.displayPoly() ;
	break;
	
	case 6:							//dif
		cout << "\n Displaying the difference of two polynomials \n";
		difT.polyDif(t1, t2);
		cout << "\n Difference: " << endl;
		difT.displayPoly() ;
	break;
     
   case 7:		//multi
		cout << "Displaying multiplication of polynomail \n";
		Polynomial MultiT;
		Polynomial t3;
		float co3;
		int ex3;
		cout << "\n Please enter the term to be multiplied to the polynomial #1 \n";
		cin >> co3 >> ex3;
	    t3.addTerm(ex3,co3);
	    MultiT.polySum( t1, t3 );
	    cout << "\n multiplied polynomial: " ;
	    MultiT.displayPoly();
   break;
     
}   //end switch

}  //end while

return 0;
  
}

