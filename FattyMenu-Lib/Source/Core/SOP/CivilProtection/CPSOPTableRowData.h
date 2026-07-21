#pragma once
#include "TableRowTypes.h"
#include <vector>

namespace FattyMenu {
	namespace CPSOPTableData {
		inline const std::vector<SPolitiScheduleRow> politi_schedule_table_data = {
			// Columns:
			// Start time		End time		Event					Time length (start time - end time)
			{ "00:00",			"03:00",		"Curfew Procedure",		"3 hours"							},
			{ "04:15",			"05:45",		"Workforce Intake",		"1 hour, 30 minutes"				},
			{ "06:00",			"07:00",		"Ration Intake",		"1 hour"							},
			{ "07:15",			"11:45",		"Workforce Intake",		"4 hours, 30 minutes"				},
			{ "12:00",			"13:00",		"N/A",					"1 hour"							},
			{ "13:15",			"17:45",		"Workforce Intake",		"4 hours, 30 minutes"				},
			{ "18:00",			"19:00",		"Ration Intake",		"1 hour"							},
			{ "19:15",			"23:00",		"Workforce Intake",		"3 hours, 45 minutes"				},
		};

		inline const std::vector<SOverrideCodeRow> override_code_table_data = {
			// Columns:
			// Status					Sociostable			Unrest				Containment			Lockdown
			{ "Ration intake",			"Active",			"Discretionary",	"Suspended",		"Suspended"		},
			{ "Workforce status",		"Active",			"Discretionary",	"Suspended",		"Suspended"		},
			{ "Shield access",			"Civic Populace",	"Workforce",		"Ground Units",		"Ground Units"	},
			{ "Weapon protocol",		"Holstered",		"Unholstered",		"Raised",			"Raised"		}
		};

		inline const std::vector<SViolationLevelRow> violation_level_table_data = {
			// Columns:
			{
				// Recommended verdict(s)
				{ "Verbal Warning", "Citation", "Prosecution" },

				// Description
				"Minor, isolated, accidental or first-time violation with negligable impact on sociostability. Little or no harm, disruption, interference or resistance is present",

				// Level
				1,
			},
			{
				{ "Citation", "Prosecution" },
				"Deliberated, repeated or disruptive violation with limited impact on sociostability. The violation demonstrates disregard for civic expectations but results in only minor harm, interference, disruption or disorder",
				2
			},
			{
				{ "Prosecution" },
				"Serious violation resulting in measurable loss, interference, public disruption or operational burden. The violation produces measurable consequences affecting individuals, property, civic functions, or protection team operations",
				3
			},
			{
				{ "Terminal prosecution", "Amputation\n(if necessary to display authority amongst populace)" },
				"Severe violation involving substantial harm, dangerous conduct, significant resistance, organized misconduct or serious interference with Combine operations. The violation presents a clear threat to sociostability, civic order or operations",
				4
			},
			{
				{ "Terminal prosecution", "Immediate amputation\n(if unable to apprehend)", "Disassociation\n(if labor required)" },
				"Critical violation involving extreme harm, armed conduct, violent intent, organized resistance, direct attacks upon Combine authority or actions causing widespread instability. The violation presents an immediate and significant threat to sociostability",
				5
			}
		};

		inline const std::vector<SLocationAuthorizationRow> patrol_region_table_data = {
			// Columns:
			// Location 							Civic Populace					Engineer Core								Infestation Control					Civil Protection
			{ { "Workforce Intake Hub" },			{ "Permitted" },				{ "Permitted" },							{ "Permitted" },					{ "Permitted" } },
			{ { "Residental Block (priority)" },    { "Access Protocol" },			{ "Access Protocol" },						{ "Access Protocol" },				{ "Permitted" } },
			{ { "Residental Block" },				{ "Permitted" },				{ "Permitted" },							{ "Permitted" },					{ "Permitted" } },
			{ { "Distribution Block" },		        { "Access Protocol" },			{ "Access Protocol" },						{ "Access Protocol" },				{ "Permitted" } },
			{ { "Production Block" },				{ "Access Protocol" },			{ "Permitted" },							{ "Permitted" },					{ "Permitted" } },
			{ { "Station Block" },					{ "Not Permitted", true },		{ "Not Permitted", true },					{ "Not Permitted", true },			{ "Permitted" } }
		};

		inline const std::vector<SLocationAuthorizationRow> non_patrol_region_table_data = {
			// Columns:
			// Location 							Civic Populace					Engineer Core						Infestation Control					Civil Protection
			{ { "Restricted Block" },				{ "Not Permitted" },			{ "Not Permitted", true },			{ "Not Permitted", true },			{ "Not Permitted", false, true } },
			{ { "Storm System" },					{ "Not Permitted" },			{ "Not Permitted", true },			{ "Not Permitted", true },			{ "Not Permitted", false, true } },
			{ { "Outland Zone" },					{ "Not Permitted" },			{ "Not Permitted", true },			{ "Not Permitted" },				{ "Not Permitted", false, true } },
			{ { "Terminal Restriction Zone" },		{ "Not Permitted" },			{ "Not Permitted" },				{ "Not Permitted" },				{ "Not Permitted", false, true } },

		};

		inline const std::vector<SResidentialBlockRow> residential_block_table_data = {
			// Columns:
			// Residential Block		Capacity
			{ "Residental Block 1",		"4 residents per room"          },
			{ "Residental Block 3",		"10 residents per room"         },
			{ "Residental Block 4",		"6 residents per room"          },
			{ "Residental Block 5",		"4 residents per room"          },
			{ "Residental Block 8",		"Unlimited capacity (overflow)" },
		};
	}
}