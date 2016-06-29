#include "TFile.h"
#include "TDatime.h"
#include "TNamed.h"
#include "TMath.h"
#include "TLorentzVector.h"

#include "TopEMuTree.h"
#include <string>
#include <vector>

const Float_t eleM = .000510998910;
const Float_t muM = .1056583715;

void plots(TString strIn = "emuskim_0.root", const std::string outFileName = "topEmuSkim_0.root") {

  const int iDebug = 0;

  TFile *f = TFile::Open(strIn.Data());
  TTree *tr = dynamic_cast<TTree*>(f->Get("skimTree"));

//  TFile* outFile_p = new TFile(outFileName.c_str(), "RECREATE");
 int njets = 0;
 float csv = discr_csvV1_[nMaxJets];	  
 bool isBTagged(csv>0.800);

 std::map<TString, TH1 *> allPlots;

 for(Int_t ij=0; ij<=4; ij++)
    {
      for(Int_t itag=-1; itag<=2; itag++)
{
  if(itag>ij) continue;
TString tag(itag<0 ? Form("%dj",ij) : Form("%dj%dt",ij,itag));
allPlots["jpt_"+tag] = new TH1F("jpt_"+tag,";Transverse momentum [GeV];Events" ,20,0.,300.);
if(itag==-1)
	    {
	      allPlots["nbtags_"+tag]     = new TH1F("nbtags_"+tag,";Category;Events" ,3,0.,3.);
	      allPlots["nbtags_"+tag]->GetXaxis()->SetBinLabel(1, "=0b");
	      allPlots["nbtags_"+tag]->GetXaxis()->SetBinLabel(2, "=1b");
	      allPlots["nbtags_"+tag]->GetXaxis()->SetBinLabel(3, "#geq2b");
}
}
    }

    int nEntries = (int)tr->GetEntries();
  for(int entry = 0; entry < nEntries; entry++){
tr->GetEntry(entry);
std::cout<<"I am here: "<<endl;
//allPlots["jpt_"]->Fill(jtPt[indexJets[ij]]);
//++njets;
}
}
