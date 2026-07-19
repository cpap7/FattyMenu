#pragma once

#include "../Code.h" // For CCode class definition

namespace FattyMenu {
	/* For declarations each type of code used by Civil Protection over the radio */
	namespace CPCodes {

		namespace Abbreviation {
			extern CCode adw;
			extern CCode bol;
			extern CCode cpt;
			extern CCode db;
			extern CCode goa;
			extern CCode oc;
			extern CCode upi;
			extern CCode utl;
			extern CCode _34s;
			extern CCode _187;
			extern CCode _415b;
			extern CCode _505;
		}

		namespace Response {
			extern CCode code_1;
			extern CCode code_2;
			extern CCode code_3;
			extern CCode code_4;
			extern CCode code_7;
			extern CCode code_12;
			extern CCode code_100;
		}

		namespace Eleven {
			extern CCode _116;
			extern CCode _1142;
			extern CCode _1143;
			extern CCode _1144;
			extern CCode _1194;
			extern CCode _1199;
		}

		namespace Ten {
			extern CCode _100;
			extern CCode _101;
			extern CCode _102;
			extern CCode _103;
			extern CCode _104;
			extern CCode _106;
			extern CCode _107;
			extern CCode _108;
			extern CCode _109;
			extern CCode _1012;
			extern CCode _1014;
			extern CCode _1015;
			extern CCode _1019;
			extern CCode _1020;
			extern CCode _1022;
			extern CCode _1025;
			extern CCode _1026;
			extern CCode _1027;
			extern CCode _1030;
			extern CCode _1031;
			extern CCode _1032;
			extern CCode _1033;
			extern CCode _1038;
			extern CCode _1041;
			extern CCode _1042;
			extern CCode _1054d;
			extern CCode _1065;
			extern CCode _1078;
			extern CCode _1091d;
			extern CCode _1093;
			extern CCode _1096;
			extern CCode _1097;
			extern CCode _1099;
			extern CCode _10103;
			extern CCode _10103m;
			extern CCode _10107;
			extern CCode _10108;
			extern CCode _10109;
		}

		// CCode violation declarations
		namespace Violation {
			// Violation Category: Violation of civic trust
			// Category Description: Actions that undermine civic responsibility, authorized resource allocation, workforce obligations or public trust
			extern CCode _27;
			extern CCode _54;
			extern CCode _62;
			extern CCode _69;
			extern CCode _91;
			extern CCode _99;
			extern CCode _311;
			extern CCode _374b;
			extern CCode _488;
			extern CCode _647f;

			// Violation Category: Failure to comply with the civil will
			// Category Description: Failure to obey, respect, or cooperate w/ lawful directives issued by Civil Protection
			extern CCode _35;
			extern CCode _59;
			extern CCode _63;
			extern CCode _148;
			extern CCode _507;
			extern CCode _647e;

			// Violation Category: Promoting communal unrest
			// Category Description: Actions intented to disrupt civic harmony, encourage disorder or undermine public stability
			extern CCode _28;
			extern CCode _404;
			extern CCode _407;
			extern CCode _415;

			// Violation Category: Divisive sociocidal counter-obeyance
			// Category Description: Organized resistance to authority, interference with operations, or support of anti-civil elements
			extern CCode _17f;
			extern CCode _51;
			extern CCode _63s;
			extern CCode _94;
			extern CCode _95;
			extern CCode _603;

			// Violation Category: Destruction of corporal social protection units
			// Category Description: Acts resulting in damage to Civil Protection personnel, assets or operational capability 
			extern CCode _51b;
			extern CCode _243;
		}


		// CCode declarations for override codes
		namespace Override {
			extern CCode sociostable;
			extern CCode unrest_procedure;
			extern CCode containment_procedure;
			extern CCode lockdown_procedure;
		}

		// CCode declarations for verdict codes
		namespace Verdict {
			extern CCode verbal_warning;
			extern CCode citation;
			extern CCode prosecution;
			extern CCode terminal_prosecution;
			extern CCode disassociation;
			extern CCode amputation;
			extern CCode immediate_amputation;
		}
	}
}