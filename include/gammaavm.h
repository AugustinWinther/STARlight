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
// $Rev:: 313                         $: revision of last commit
// $Author:: aaronstanek              $: author of last commit
// $Date::                            $: date of last commit
//
// Description:
//
//
//
///////////////////////////////////////////////////////////////////////////


#ifndef GAMMAAVM_H
#define GAMMAAVM_H


#include <vector>

#include "starlightconstants.h"
#include "readinluminosity.h"
#include "beambeamsystem.h"
#include "randomgenerator.h"
#include "eventchannel.h"
#include "upcevent.h"
#include "upcXevent.h"
#include "nBodyPhaseSpaceGen.h"


class Gammaavectormeson : public eventChannel
{
  
 public:
  Gammaavectormeson(const inputParameters& input, randomGenerator* randy, beamBeamSystem& bbsystem);
  virtual ~Gammaavectormeson();
  starlightConstants::event produceEvent(int &ievent);
  
  //upcEvent produceEvent(vector3 beta);
  upcXEvent produceEvent(vector3 beta);

  void pickwy(double &W, double &Y);
  void momenta(double W,double Y,double &E,double &px,double &py,double &pz,int &tcheck,
                double &Eb1, double &pxb1, double &pyb1, double &pzb1,
								double &Eb2, double &pxb2, double &pyb2, double &pzb2, double &t2,
								double &Egam, double&pxgam, double &pygam, double &pzgam, double &Q2gam);
  double pTgamma(double E); 
  void vmpt(double W,double Y,double &E,double &px,double &py, double &pz,int &tcheck);
  void twoBodyDecay(starlightConstants::particleTypeEnum &ipid,double W,double px0,double py0,double pz0,double &E1,double &px1,double &py1,double&pz1, double &E2, double &px2,double &py2,double &pz2,int &iFbadevent);
  bool omega3piDecay(starlightConstants::particleTypeEnum& ipid, starlightConstants::particleTypeEnum& ipid2, const double E, const double W, const double* p, lorentzVector* decayMoms, int& iFbadevent);
  double breitWignerMass(const double M, const double gamma);
  bool simpleTwoParticleDecay(const double m0, const double px0, const double py0, const double pz0,const double m1, double& px1, double& py1, double& pz1,const double m2, double& px2, double& py2, double& pz2,int& iFbadevent);
  bool jpsi4piDecay(const double m0, const double px0, const double py0, const double pz0, lorentzVector* decayVecs, int& iFbadevent);
  bool jpsi2kaon2piDecay(const double m0, const double px0, const double py0, const double pz0, lorentzVector* decayVecs, int& iFbadevent);
  bool fourBodyDecay(starlightConstants::particleTypeEnum& ipid, const double E, const double W, const double* p, lorentzVector* decayMoms, int& iFbadevent);
  double getMass();
  double getWidth();
  virtual double getTheta(starlightConstants::particleTypeEnum ipid);
  double getSpin();
  double _VMbslope;
  virtual double getDaughterMass(starlightConstants::particleTypeEnum &ipid);
  virtual double get2ndDaughterMass(starlightConstants::particleTypeEnum &ipid);                

  
 private:
  starlightConstants::particleTypeEnum _VMpidtest;
  int _VMnumw;
  int _VMnumy;
  int _VMinterferencemode;
  int _ProductionMode;
  int _TargetBeam; 
  int N0;
  int N1;
  int N2; 
  int _VMNPT;
  double _VMgamma_em;
  double _VMWmax;
  double _VMWmin;
  double _VMYmax;
  double _VMYmin;
  double _mass;
  double _width;
  double _VMptmax;
  double _VMdpt;
  int    _bslopeDef;
  double _bslopeVal;
  double _pEnergy;
  nBodyPhaseSpaceGen* _phaseSpaceGen;
  
};

class Gammaanarrowvm : public Gammaavectormeson
{
 public:
  Gammaanarrowvm(const inputParameters& input, randomGenerator* randy, beamBeamSystem& bbsystem);
  virtual ~Gammaanarrowvm();
};

class Gammaawidevm : public Gammaavectormeson
{  
 public:
  Gammaawidevm(const inputParameters& input, randomGenerator* randy, beamBeamSystem& bbsystem);
  virtual ~Gammaawidevm();
};

class Gammaaincoherentvm : public Gammaavectormeson
{  
 public:
  Gammaaincoherentvm(const inputParameters& input, randomGenerator* randy, beamBeamSystem& bbsystem);
  virtual ~Gammaaincoherentvm();
};

#endif  // GAMMAAVM_H
