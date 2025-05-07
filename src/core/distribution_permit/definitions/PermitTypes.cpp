#include "PermitTypes.h"

/* Definitions of CPermit objects 
   Format:
   CPermit permit = {
		"Permit Name", int civic_point_requirement, int cost,
		{
			{ "Package 1 name", int package_1_cost },
			{ "Package 2 name", int package_2_cost },
			...
			{ "Package n name", int package_n_cost }
		},
		{
			"Authorized sellable example item 1",
			"Authorized sellable example item 2",
			...
			"Authorized sellable example item n"
		}

   };

   Note: Zeroes are placeholder values until concrete data has been provided
*/
namespace PermitTypes {
	CPermit hydration = {
		"Hydration", 50, 25,
		{
			{ "Packaged Blue >B Drinks (x5)", 0 },
			{ "Packaged Red >B Drinks (x5)", 0 },
			{ "Packaged Yellow >B Drinks (x5)", 75 },
			{ "Packaged Desiccated Sustenance Bars (x5)", 0 },
			{ "Packaged Solidified Nutrient Tablets (x5)", 0 },
			{ "Packaged Sweetened Hydration Bars (x5)", 0 },
			{ "Packaged Fermented Vitality Tablets (x5)", 0 } 
		},
		{ 
			"Drinks",
			"Tea",
			"Coffee",
			"Coffee mugs",
			"Coffee maker"
		}
	};
	CPermit nourishment = {
		"Nourishment", 100, 50,
		{
			{ "Packaged Gelatinated Calorie Pastes (x5)", 23 },
			{ "Packaged Refined Craniate Slices (x5)", 28 },
			{ "Packaged Concentrated Fowl Blends (x5)", 33 },
			{ "Packaged Enriched Taxon Extracts (x5)", 38 }
		},
		{
			"Foodstuffs",
			"Ingredients",
			"Cookware (food)"
		}
	};
	CPermit garment = {
		"Garment", 200, 70,
		{
			{ "Packaged Blue Denim Jackets (x5)", 120 },
			{ "Packaged Beige Denim Jackets (x5)", 150 },
			{ "Packaged Blue Jeans (x5)", 100 },
			{ "Packaged Black Jeans (x5)", 200 },
			{ "Packaged Blue Shoes (x5)", 85 },
			{ "Packaged Black Shoes (x5)", 85 },
			{ "Packaged Blue Caps (x5)", 175 },
			{ "Packaged Black Gloves (x5)", 100 }
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
			{ "Packaged Ground Sunrise Coffee (x5)", 45 },
			{ "Packaged Packaged Rye Flour (x5)", 5 },
			{ "Packaged Dried Herbs", 10 },
			{ "Packaged Dried Spices (x5)", 10 },
			{ "Packaged Variety Dried Vegetables (x5)", 15 },
			{ "Packaged Salt (x5)", 5 },
			{ "Packaged Cigarette Packs (x5)", 40 },
			{ "Packaged Televisions (x5)", 375 },
			{ "Packaged >B Radios (x5)", 250 }
		},
		{
			"Electronics",
			"Tobacco",
			"Ingredients",
			"Coffee",
			"Writing Materials"
		}
	};
}