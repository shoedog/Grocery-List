/******************************************************************************
 ** Program Filename: items.hpp 
 ** Author: Wesley Jinks
 ** Date: 1/15/2015
 ** Description: This is the header file for the Item class. It contains the 
		variables and functions for Item.
 ** Input: None
 ** Output: None
 * ***************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

class Item
{
	private:
		std::string itemName;  //The items name
		std::string unitType;  //The unit type
		int numToBuy;     //The number to buy
		float unitPrice;  //Price of the item per unite
		
	public:
		
		/********************************************************************************
		*	Function: Item()
		*	Description: Constructor of a item. Sets variables to null or 0.
		*	Parameters: None
		*	Pre-Conditions: None
		*	Post-Conditions: Class variables are set to 0 or null
		* ******************************************************************************/
		Item();

		/********************************************************************************
		*	Function: Item( string, string, int, float )
		*	Description: Constructor of a item. Initializes class variables to passed
		*		parameters.
		*	Parameters: None
		*	Pre-Conditions: None
		*	Post-Conditions: Class variables are set based on arguments
		* ******************************************************************************/
		Item( std::string, std::string, int, float);

		/********************************************************************************
		*	Function: Item( const Item &item )
		*	Description: Copy Constructor
		*	Parameters: None
		*	Pre-Conditions: None
		*	Post-Conditions: Copys class variables
		********************************************************************************/
		Item( const Item & );

		/********************************************************************************
		*	Function: Item( const Item &item )
		*	Description: = Overloadr
		*	Parameters: None
		*	Pre-Conditions: None
		*	Post-Conditions: Copys class variables
		********************************************************************************/
		void operator=( const Item & );

		/********************************************************************************
		*	Function: ~Item()
		*	Description: Destructor of an Item. 
		*	Parameters: None
		*	Pre-Conditions: None
		*	Post-Conditions: Destructs object
		* ******************************************************************************/
//		~Item();

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		std::string getItemName()
		{	return itemName;  }

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		std::string getUnitType()
		{	return unitType;  }

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		int getNumToBuy()
		{	return numToBuy;  }

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		float getUnitPrice()
		{	return unitPrice;  }

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		void setItemName( std::string name )
		{	this->itemName = name;  }

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		void setUnitType( std::string unit )
		{	this->unitType = unit;  }

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		void setNumToBuy( int num )
		{	this->numToBuy = num;  }

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		void setPrice( float price )
		{	this->unitPrice = price;  }
	
		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
		friend std::ostream& operator<<( std::ostream&, Item& );

		/********************************************************************************
		*	Function:
		*	Description: 
		*	Parameters: 
		*	Pre-Conditions:
		*	Post-Conditions: 
		* ******************************************************************************/
	//	friend std::istream& operator>>( std::istream &ins, Item &i );

};

#endif


