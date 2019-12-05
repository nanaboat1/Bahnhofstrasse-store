#include <iostream>
using namespace std;
//Function Prototypes
char shelfname_stringtoChar_Row(string shelfIndex);
char shelfname_stringtoChar_Column(string shelfIndex);
int numerical_Value_ofRowindex(char shelfname_stringtoChar_Row);
int numerical_Value_ofColumnindex(char shelfname_stringtoChar_Column);

class  Customer{
public:
    bool authorization; // gives authorization to the customer to buy things from the store 
    double receipt_bill; // stores the total purchase of the customer
    int cash_rewards; //a promotional something, I have not figured it out so do not ask me what it does. 
    int customer_ratings;
    int key;//key used to perform a specific fxn to the shelf.

    //Constructor for this class. When the class is istantiated default values are given to the data fields during compile time. 
    Customer(){
        authorization = false;
        receipt_bill = 0.00;
        cash_rewards = 0.00;
        customer_ratings = 0; 
        key = 1235;//default value for the data. 
    }

    //Methods for this class
    bool authorizing(){//This method changes the value of authorization field to true.
        return authorization = true;
    }

    int ratings(){//this method asks the user to rate the experience in using the store. 

        if(authorization){// this method is enabled only when the user has been authorized.
        cout << " How was your experience today shopping with us. Please rate us from 1 to 5 :) "<<endl;
        cin >> customer_ratings;    
        return customer_ratings;
        }
        else{
            customer_ratings = 0;
            return customer_ratings;//returns the default constructors value for customers ratings
        }
    }
    int cashRewards(){
        //Depending on certain conditions then a number is given to cash rewards which is evaluated 
        //based on certain criterias. Which will be filled in later.
        return cash_rewards; 
    }
    double addToBill(int price){

        if(authorization){  
        receipt_bill += price;
        return receipt_bill;// adds the prize to the receipt bill then returns the new prize. 
        }
        else{
            return receipt_bill; // returns the original receipt bill without adding the prize.
        }
    }
};

class Stocker{
public:
    bool authorisation;//authorises the functions of this class to be used. 
    string shelf_select;//check your previous library on how to make small letters capital , check lm8 it might be there.
    bool assistance;//
    int key;//grants access to perform a specific access to the shelf.

    Stocker(){
        authorisation = false;
        shelf_select = "aA";//Default shell value
        assistance = false;
        key = 1234;//default value for the key.
    }

    bool authorising(){//authorises this class to be used in session.
        return authorisation = true;     
    }

    string selectShelf(){
        
        cout << "Enter the shelf code ";
        cin >> shelf_select;    
        return shelf_select; 
    }
};
class BusinessAnalytics{//more to add to the code will do that in the coming days 
public:
    bool autharise;//authorizes this function to be used. 
    double totalSales;// stores the total purchase made in a day. 
    int totalItemspurchased;//stores total items purchased
    /* 8 data fields to store the total items purchased. */ 
    double profits; 

    //creating a constructor for the class
    BusinessAnalytics(){
        autharise = false;
        totalSales = 0.00;
        totalItemspurchased = 0;
        profits = 0.00;
    }

    //Methods for this class

    bool authorazing(){
        
        return autharise = true;//authorises this class to be used in a session. 
    }

    double total_sales(int sale_per_Session){
        if(autharise){//if autharisation is set to true then the function runs. 
        totalSales +=sale_per_Session;
        return totalSales;// return the total sales after the prize per session
        }
        else{
            return totalSales;//return the original total sales after the prize per session. 
        }

    }
    /*For the Profits Method, I have to be really critical of this. I will do this after I have found how the code is going to work. */
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This lists of functions, consists of the shelfs of the store and function manipulators that helps access the shelf array based on the users input.
//This function helps the stocker to add quanity amount to the shelf.
int quantity_add(){
  int add_quant = 0;
  cout << "Enter the quanity amount you want to add--> ";
  cin >> add_quant;
  
  return add_quant;
}
char chartoNum(char ch){
  if( static_cast<int>(ch)>=48&&static_cast<int>(ch)<58){//returns the numbers if user input are numbers
    return ch;//returns the ch when the input is a number.
  }
  else if(static_cast<int>(ch)>96&&static_cast<int>(ch)<123){//when the input is lower case, we need to convert it to upper case.

    return toupper(ch);//converts it to its upper case character then tranlates it to a phone number. 
  }
  else if(static_cast<int>(ch)>=65&&static_cast<int>(ch)<=90){//when the letter is already in upper case.
    return ch; //When the number is already in upper case it calls dialchartonum to give its corresponding phone number.
  }
  return ch = '_';
}
string correctshelfName(string shelfindex){
  //The correctshelfName function corrects the users input of the shelf number to the standard format required by the program
  //to prevent runtime issues.  
  string standardShelfname = "aa";//stores tesf. //the value inside is an arbitrarily value to prevent error during compile time.   
  for(int i = 0; i <2; i++){  
   standardShelfname[i] = chartoNum(shelfindex[i]);
  }
  return standardShelfname;
  //The customer class will use the return value when the customer class  is objectisied.
}
int specific_ASCIIofChar_shelfIndex(int totalASCII_of_index){
  /* This function uses the total ASCII value of the shelf index and switch statement to return its
  corresponding value to the array. 
  */
  switch(totalASCII_of_index){
    case 114://when the Array shelf is A1.( Total ASCII value ==> 114)(A1, is the first column.)
      return 0;//it returns 0  
    break;
    case 115://when the Array shelf is A2. (Total ASCII value ==> 115)(A2, is the second column.)
      return 1;
    break;
    case 116://when the Array shelf is A3. (Total ASCII value ==> 116)(A3, is the third column.)
      return 2;
    case 117://when the Array shelf is A4. (Total ASCII value ==> 117)(A4, is the fourth column.)
      return 3;
    break;
    case 118://when the array shelf is A5. (Total ASCII value ==> 118)(A5, is the fifth column. )
      return 4;
    break;
  }
  //return 8;
}

string warehouseItems(string warehouseIndex){  
  const int item_type = 5;
  //correctshelfName(), evaluates the user input to the standard
  warehouseIndex = correctshelfName(warehouseIndex);
 /*For compile reasons, this array is hard coded with predefined stuffs and time convenience */
   string warehouse_items[item_type];
    warehouse_items[0] = "Cloths";
    warehouse_items[1] = "Watch";
    warehouse_items[2] = "Smartphones";
    warehouse_items[3] = "Books";
    warehouse_items[4] = "Fast food";
  /* The numerical values of the row and column index are gotten and then assiged to int varibles*/
  int numerical_val_row = numerical_Value_ofRowindex(shelfname_stringtoChar_Row(warehouseIndex)); //The numerical value of Row index is gotten is evaluated by calling the functions. 
  int numerical_val_column = numerical_Value_ofColumnindex(shelfname_stringtoChar_Column(warehouseIndex));//The numerical value of column index is evaluated by calling the functions.
  /* After I have gotten the numerical values, I send it to a function that uses switch statements to evaluate them and couts a unique
  value that can be used by the warehouse to give a specific index of the shelf
  */
  int total_numerical_valRow_Clmn = numerical_val_row + numerical_val_column;//this variables stores the total numerical value of row index and column index. 

  //cout << total_numerical_valRow_Clmn << endl; used for testing purposes
  int index_to_be_accessed = specific_ASCIIofChar_shelfIndex(total_numerical_valRow_Clmn);
  //cout << index_to_be_accessed << endl;used for testing purposes. 
  string item_to_disp;
  for(int i = 0; i <= index_to_be_accessed; i++){
    item_to_disp = warehouse_items[i];
  }
  return item_to_disp;
}
int warehouseStock(string warehouseIndex){//This contains the quantities of stock in the warehouse with the prize.
  const int item_type = 5;
  //correctshelfName(), evaluates the user input to the standard
  warehouseIndex = correctshelfName(warehouseIndex);
 /*For compile reasons, this array is hard coded with predefined stuffs and time convenience */
   int warehouse_items[item_type];
    warehouse_items[0] = 4;
    warehouse_items[1] = 3;
    warehouse_items[2] = 2;
    warehouse_items[3] = 2;
    warehouse_items[4] = 3;
  /* The numerical values of the row and column index are gotten and then assiged to int varibles*/
  int numerical_val_row = numerical_Value_ofRowindex(shelfname_stringtoChar_Row(warehouseIndex)); //The numerical value of Row index is gotten is evaluated by calling the functions. 
  int numerical_val_column = numerical_Value_ofColumnindex(shelfname_stringtoChar_Column(warehouseIndex));//The numerical value of column index is evaluated by calling the functions.
  /* After I have gotten the numerical values, I send it to a function that uses switch statements to evaluate them and couts a unique
  value that can be used by the warehouse to give a specific index of the shelf*/
  int total_numerical_valRow_Clmn = numerical_val_row + numerical_val_column;//this variables stores the total numerical value of row index and column index. 
  //cout << total_numerical_valRow_Clmn << endl; used for testing purposes
  int index_to_be_accessed = specific_ASCIIofChar_shelfIndex(total_numerical_valRow_Clmn);
  /*                                                                           */
  
  //cout << index_to_be_accessed << endl;used for testing purposes. 
  int quantity_to_disp;//this variables displays the quantity of the specific shelf to the user.
  //The loops displays the specific warehouse shelf Item quanity asked for.
  for(int i = 0; i <=index_to_be_accessed; i++){
    quantity_to_disp = warehouse_items[i];
  }
  cout << "Quanity is " << quantity_to_disp << endl;
  /* This block of code will ask the Stocker is she wants to add extra quantity of the item to the specific shelf 
   If the user opts not to add more quantities to the shelf the shel wont increase but if she opts to then it will increase*/
  int yes_or_no = 0;
  cout << "Do you want to add more quanties to the shelf Index--> (1)->Yes || (0)-->No >> " << endl;
  cin >> yes_or_no;
  if(yes_or_no == 1){
    warehouse_items[index_to_be_accessed] += quantity_add();
    //Then the new quanity is displayed rather than the old run. 
    for(int i = 0; i <= index_to_be_accessed; i++){
    quantity_to_disp = warehouse_items[i];
    }

    cout << "New Quanity is--> " << quantity_to_disp << endl;
  }
  else{
    ;//when nothing happens. 
  } 
  return quantity_to_disp;//either it returns the old quanity or the accumulated new quantity quanity. 
}
//This functions help convert the users input into int values to help access the shelf arrays.
int numerical_Value_ofRowindex(char convert_rowchar_toInt){
  /*This function converts the rowIndex char gotten from shelfname_stringtoChar_Row to its corresponding ASCII value (integer value)
  */
  
  return static_cast<int>(convert_rowchar_toInt);
}
int numerical_Value_ofColumnindex(char convert_columnchar_toInt){
  /*This function converts the column char gotten from shelfname_stringtoChar_Column to its corresponding ASCII value (integer value)
  */
  
  return convert_columnchar_toInt;
}
char shelfname_stringtoChar_Row(string shelfIndex){//The parameter is the shelf place the user wants to access.
    // This function breaks the user input(Shelfindex of row to be evaluated by the add new item category)
    

    char string_index_to_char_row; 
    //char column_index;
    for(int i = 0; i <1; i++){
     string_index_to_char_row = shelfIndex[i];
    }
    //For testing reasons, I included the cout.
    //cout << string_index_to_char_row << endl;
    return string_index_to_char_row;
}
char shelfname_stringtoChar_Column(string shelfIndex){//The parameter is the shelf place the user wants to access. 
  // This function breaks the userinput(Shelfindex of column to be evaluated by the add new item category)
 
  char string_index_to_char_column; 
  //char column_index;
  for(int i = 0; i <2; i++){

    string_index_to_char_column = shelfIndex[i];
  }
  //For testing reasons, I included the the cout below. 
  //cout << string_index_to_char_column << endl;
  return string_index_to_char_column;
}

void myStore(){
    Customer User;// Instantiated the customer class
    Stocker  Cashier;// Instantiated the Stocker class
    /* The selectshelf method of Class Stocker is instatiated here and the return value of the shelfselect method is passed to the datafield (shelf_select)  
    */  

    Cashier.shelf_select = Cashier.selectShelf();
    
    cout << warehouseItems(Cashier.shelf_select) << ":"/*<< " :Quanitiy is --> " */<< endl <</*"New Quanity is-->"<< */warehouseStock(Cashier.shelf_select);//" " << warehouseStock(Cashier.shelf_select) << endl;

    


    /*My store the program is the cashier right .
    And  in the store we have a customer and a stocker
    and a way to print the items in the store nicely and a shelf name so that when the user enters a specific value of the shelf 
    it can bring the items of the shelf then the user chooses the quantity he or she wants to buy. 
    */
   // create the customer and also the stocker. 
}

int main(){
    int program = 1;

    while(program != 0){

        myStore();

    }
    


    return 0;
}