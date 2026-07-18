#include "PermitTypes.h"

namespace FattyMenu {
	/* Definitions of CPermit objects
	   Usage/Format:
	   CPermit permit = {
			"Permit Name", int civic_point_requirement, int cost
			{
				{ "Package 1 name", int package_1_cost, int package_1_quantity = 5 },
				{ "Package 2 name", int package_2_cost, int package_2_quantity = 5 },
				...
				{ "Package n name", int package_n_cost, int package_n_quantity = 5 }
			},

			// Vector of strings for each authorized sellable item
			{
				"Authorized sellable example item 1",
				"Authorized sellable example item 2",
				...
				"Authorized sellable example item n"
			}
	
	   };
	   
	   NOTE: 
		- Any zeroes listed here are placeholder values until concrete data has been provided
		- As of writing, the quantity is 5 across each package, but this can be overwritten with a new value if needed
	*/

	namespace PermitTypes {
		CPermit hydration = {
			"Hydration", 50, 25,
			{
				{ "Packaged Blue >B Drinks", 10 },
				{ "Packaged Red >B Drinks", 35 },
				{ "Packaged Yellow >B Drinks", 75 },
				{ "Packaged Desiccated Sustenance Bars", 8 },
				{ "Packaged Solidified Nutrient Tablets", 13 },
				{ "Packaged Sweetened Hydration Bars", 18 },
				{ "Packaged Fermented Vitality Tablets", 23 }
			},
			{
				"Water",
				"Tea"
			}
		};
		CPermit nourishment = {
			"Nourishment", 100, 50,
			{
				{ "Packaged Gelatinated Calorie Pastes", 23 },
				{ "Packaged Refined Craniate Slices", 28 },
				{ "Packaged Concentrated Fowl Blends", 33 },
				{ "Packaged Enriched Taxon Extracts", 38 }
			},
			{
				"Foodstuffs",
				"Ingredients"
			}
		};
		CPermit garment = {
			"Garment", 200, 70,
			{
				{ "Packaged Blue Denim Jackets", 120 },
				{ "Packaged Beige Denim Jackets", 150 },
				{ "Packaged Blue Jeans", 100 },
				{ "Packaged Black Jeans", 200 },
				{ "Packaged Blue Shoes", 85 },
				{ "Packaged Black Shoes", 85 },
				{ "Packaged Blue Caps", 175 },
				{ "Packaged Black Gloves", 100 }
			},
			{
				"Clothing",
				"Textiles",
				"Thread"
			}
		};
		CPermit luxury = {
			"Luxury", 400, 90,
			{
				{ "Packaged Ground Sunrise Coffee", 45 },
				{ "Packaged Packaged Rye Flour", 5 },
				{ "Packaged Dried Herbs", 10 },
				{ "Packaged Dried Spices", 10 },
				{ "Packaged Variety Dried Vegetables", 15 },
				{ "Packaged Salt", 5 },
				{ "Packaged Cigarette Packs", 40 },
				{ "Packaged Televisions", 375 },
				{ "Packaged >B Radios", 250 }
			},
			{
				"Coffee",
				"Coffee Maker",
				"Cookware",
				"Soda",
				"Electronics",
				"Tobacco",
				"Ingredients",
				"Espresso",
				"Writing Materials"
			}
		};
	}
}