#define TreeCutter_cxx
#include "TreeCutter.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TTree.h"
void TreeCutter::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L TreeCutter.C
//      Root > TreeCutter t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   TFile *outfile = new TFile("/lariat/data/users/gpulliam/MCdata/64GeV_pos100A/RoundXCut.root","recreate");
   
   if (fChain == 0) return;
   TTree *cuttree=fChain->CloneTree(0);
   
   Long64_t nentries = fChain->GetEntriesFast();
   int pass=0;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (TrackPresentDet1 && TrackPresentDet4 && (TrackPresentDet3 || TrackPresentDet2))
      { 
        ++pass;
        std::cout<<"Entry : "<<jentry<<" Total Passed: "<<pass<<" Percentage complete : "<<double(jentry)/double(nentries)*100<<std::endl;
        cuttree->Fill();
      }
   }
   cuttree->Write();
   outfile->Close();
}
