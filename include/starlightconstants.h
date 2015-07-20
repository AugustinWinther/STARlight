///////////////////////////////////////////////////////////////////////////
//
//    Copyright 2010
//
//    This file is part of starlight.
//
//    starlight is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    starlight is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with starlight. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////
//
// File and Version Information:
// $Rev::                             $: revision of last commit
// $Author::                          $: author of last commit
// $Date::                            $: date of last commit
//
// Description:
//
//
//
///////////////////////////////////////////////////////////////////////////


#ifndef STARLIGHTCONSTANTS_H_INCLUDE
#define STARLIGHTCONSTANTS_H_INCLUDE


/*
 * Constants are set here
 */
namespace starlightConstants
{


	// constants
	static const double hbarc    = 0.197327053;
	static const double hbarcmev = hbarc*1000.;
	static const double pi       = 3.141592654;
	static const double twoPi    = 2 * pi;
	static const double alpha    = 1/137.0359895;

	// deuteron slope parameter
	static const double deuteronSlopePar = 9.5; // [(GeV/c)^{-2}]
	// particle masses
	static const double protonMass      = 0.93827231;   // [GeV/c^2]
	static const double pionChargedMass = 0.13956995;   // [GeV/c^2]
        static const double pionNeutralMass = 0.1349766;    // [GeV/c^2]
	static const double kaonChargedMass = 0.493677;     // [GeV/c^2]
	static const double mel      = 0.00051099907;       // [GeV/c^2]
	static const double muonMass = 0.105658389;         // [GeV/c^2]
	static const double tauMass  = 1.777;               // [GeV/c^2]
	
	static const double f0Mass = 0.980;                 // [GeV/c^2]
        static const double etaMass = 0.54730;              // [GeV/c^2]
        static const double etaPrimeMass = 0.95766;         // [GeV/c^2]
        static const double etaCMass = 2.9803;              // [GeV/c^2]
        static const double f2Mass = 1.2751;                // [GeV/c^2]
        static const double a2Mass = 1.3183;                // [GeV/c^2]
        static const double f2PrimeMass = 1.525;            // [GeV/c^2]

        static const double rho0Mass  = 0.7685;             // [GeV/c^2]
	static const double rho0Width = 0.1507;             // [GeV/c^2]
        static const double rho0PrimeMass  = 1.350;         // [GeV/c^2]
	static const double rho0PrimeWidth = 0.360;         // [GeV/c^2]
        static const double OmegaMass  = 0.78194;           // [GeV/c^2]
	static const double OmegaWidth = 0.00843;           // [GeV/c^2]
        static const double PhiMass  = 1.019413;            // [GeV/c^2]
	static const double PhiWidth = 0.00443;             // [GeV/c^2]
        static const double JpsiMass = 3.09692;             // [GeV/c^2]
        static const double JpsiWidth = 0.000091;           // [GeV/c^2]
        static const double Psi2SMass = 3.686093;           // [GeV/c^2]
        static const double Psi2SWidth = 0.000337;          // [GeV/c^2]
        static const double Upsilon1SMass = 9.46030;        // [GeV/c^2]
        static const double Upsilon1SWidth = 0.00005402;    // [GeV/c^2]
        static const double Upsilon2SMass = 10.02326;       // [GeV/c^2]
        static const double Upsilon2SWidth = 0.00003198;    // [GeV/c^2]
        static const double Upsilon3SMass = 10.3552;        // [GeV/c^2]
        static const double Upsilon3SWidth = 0.00002032;    // [GeV/c^2]	
	
	enum particleTypeEnum {
		UNKNOWN        = 0,
		ELECTRON       = 11,
		MUON           = 13,
		TAUON          = 15,
		TAUONDECAY     = 10015,
		PROTON         = 212,
		PION           = 211,
		KAONCHARGE     = 321,
		KAONNEUTRAL    = 310,
		A2             = 115,
		ETA            = 221,
		F2             = 225,
		ETAPRIME       = 331,
		F2PRIME        = 335,
		ETAC           = 441,
		F0             = 9010221,
		ZOVERZ03       = 33,
		RHO            = 113,
		RHOZEUS        = 913,
		FOURPRONG      = 999,
		OMEGA          = 223,
		PHI            = 333,
		JPSI           = 443,
		JPSI_ee        = 443011,
		JPSI_mumu      = 443013,
		JPSI2S         = 444,
		JPSI2S_ee      = 444011,
		JPSI2S_mumu    = 444013,
		UPSILON        = 553,
		UPSILON_ee     = 553011,
		UPSILON_mumu   = 553013,
		UPSILON2S      = 554,
		UPSILON2S_ee   = 554011,
		UPSILON2S_mumu = 554013,
		UPSILON3S      = 555,
		UPSILON3S_ee   = 555011,
		UPSILON3S_mumu = 555013
	};

	enum decayTypeEnum {
		NOTKNOWN        = 0,
		NARROWVMDEFAULT = 1,
		WIDEVMDEFAULT   = 2,
		PSIFAMILY       = 3,
		LEPTONPAIR      = 4,
		SINGLEMESON     = 5
	};

	enum interactionTypeEnum {
		UNSPECIFIED         = 0,
		PHOTONPHOTON        = 1,
		PHOTONPOMERONNARROW = 2,
		PHOTONPOMERONWIDE   = 3,
                PHOTONPOMERONINCOHERENT = 4,
                PHOTONUCLEARSINGLE  = 5,
		PHOTONUCLEARDOUBLE  = 6,
		PHOTONUCLEARSINGLEPA = 7,
		PHOTONUCLEARSINGLEPAPY = 8
		
	};
	//Structure for each event's set of tracks.
	struct event{
 
	public:

		int _numberOfTracks;
		//Right now this is set up for a maximum of 4 tracks,if we want more, just increase the arrays
		//Moved it to 30, this way when pythia returns, it wont complain too much...hedging bets...not sure how many
		double px[30],py[30],pz[30];
		//starlightConstants::particleTypeEnum _fsParticle[30];
		int _fsParticle[30];
		int _charge[30];
		//To help track mothers and daughters produced through pythia.
		int _mother1[30];
		int _mother2[30];
		int _daughter1[30];
		int _daughter2[30];
		//Normally we just set vertices to 0
		//But for pythia, we decay additional states
		int _numberOfVertices;
		double _vertx[10],_verty[10],_vertz[10];	
	};


}  // starlightConstants


#endif  // STARLIGHTCONSTANTS_H_INCLUDE

