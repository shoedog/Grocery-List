/******************************************************************************
 ** Program Filename: items.cpp 
 ** Author: Wesley Jinks
 ** Date: 1/15/2015
 ** Description: This is the implementation file for the Item class. It contains
		 the variables and functions for Item.
 ** Input: None
 ** Output: None
 * ***************************************************************************/
#include "items.hpp"

		
/********************************************************************************
*	Function: Item()
*	Description: Constructor of a item. Sets variables to 0 or empty string.
*	Parameters: None
*	Pre-Conditions: None
*	Post-Conditions: Class variables are set to 0 or empty for strings
* ******************************************************************************/
Item::Item()
{
	itemName = "";
	unitType = "";
	numToBuy = 0;
	unitPrice = 0.0;
}

/********************************************************************************
*	Function: Item( string, string, int, float )
*	Description: Constructor of a item. Initializes class variables to passed
*		parameters.
*	Parameters: None
*	Pre-Conditions: None
*	Post-Conditions: Class variables are set based on arguments
* ******************************************************************************/
Item::Item( std::string name, std::string unit, int num, float price)
{
	itemName = name;
	unitType = unit;
	numToBuy = num;
	unitPrice = price;
}

/********************************************************************************
*	Function: Item( const Item &item )
*	Description: Copy Constructor
*	Parameters: None
*	Pre-Conditions: None
*	Post-Conditions: Copys class variables
********************************************************************************/
Item::Item( const Item &obj )
{
	itemName = obj.itemName;
	unitType = obj.unitType;
	numToBuy = obj.numToBuy;
	unitPrice = obj.unitPrice;
}

/********************************************************************************
*	Function: Item( const Item &item )
*	Description: Copy Constructor
*	Parameters: None
*	Pre-Conditions: None
*	Post-Conditions: Copys class variables
********************************************************************************/
void Item::operator=( const Item& obj )
{
	itemName = obj.itemName;
	unitType = obj.unitType;
	numToBuy = obj.numToBuy;
	unitPrice = obj.unitPrice;
}

/********************************************************************************
*	Function:
*	Description: 
*	Parameters: 
*	Pre-Conditions:
*	Post-Conditions: 
* ******************************************************************************/
std::ostream& operator<<( std::ostream &out, Item& o)
{
	 out << "Name: " << o.getItemName() << "% Buy " << o.getNumToBuy() << "% "
		 << o.getUnitType() << "% at $" << o.getUnitPrice() << "% per "
		 << o.getUnitType() << ". \n";

	return out;
}
